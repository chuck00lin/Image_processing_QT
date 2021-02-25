#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qfiledialog.h"
#include "QDebug"

QImage cvMat_to_QImage(const cv::Mat &mat );
using namespace cv;
using namespace std;

// Filter type
#define NONE 0  // no filter
#define HARD 1  // hard shrinkage
#define SOFT 2  // soft shrinkage
#define GARROT 3  // garrot filter
//--------------------------------
// signum
//--------------------------------
float sgn(float x)
{
    float res=0;
    if(x==0)
    {
        res=0;
    }
    if(x>0)
    {
        res=1;
    }
    if(x<0)
    {
        res=-1;
    }
    return res;
}
//--------------------------------
// Soft shrinkage
//--------------------------------
float soft_shrink(float d,float T)
{
    float res;
    if(fabs(d)>T)
    {
        res=sgn(d)*(fabs(d)-T);
    }
    else
    {
        res=0;
    }

    return res;
}
//--------------------------------
// Hard shrinkage
//--------------------------------
float hard_shrink(float d,float T)
{
    float res;
    if(fabs(d)>T)
    {
        res=d;
    }
    else
    {
        res=0;
    }

    return res;
}
//--------------------------------
// Garrot shrinkage
//--------------------------------
float Garrot_shrink(float d,float T)
{
    float res;
    if(fabs(d)>T)
    {
        res=d-((T*T)/d);
    }
    else
    {
        res=0;
    }

    return res;
}
//--------------------------------
// Wavelet transform
//--------------------------------
static void cvHaarWavelet(Mat &src,Mat &dst,int NIter)
{
    float c,dh,dv,dd;
    assert( src.type() == CV_32FC1 );
    assert( dst.type() == CV_32FC1 );
    int width = src.cols;
    int height = src.rows;
    for (int k=0;k<NIter;k++)
    {
        for (int y=0;y<(height>>(k+1));y++)
        {
            for (int x=0; x<(width>>(k+1));x++)
            {
                c=(src.at<float>(2*y,2*x)+src.at<float>(2*y,2*x+1)+src.at<float>(2*y+1,2*x)+src.at<float>(2*y+1,2*x+1))*0.5;
                dst.at<float>(y,x)=c;

                dh=(src.at<float>(2*y,2*x)+src.at<float>(2*y+1,2*x)-src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x+1))*0.5;
                dst.at<float>(y,x+(width>>(k+1)))=dh;

                dv=(src.at<float>(2*y,2*x)+src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x)-src.at<float>(2*y+1,2*x+1))*0.5;
                dst.at<float>(y+(height>>(k+1)),x)=dv;

                dd=(src.at<float>(2*y,2*x)-src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x)+src.at<float>(2*y+1,2*x+1))*0.5;
                dst.at<float>(y+(height>>(k+1)),x+(width>>(k+1)))=dd;
            }
        }
        dst.copyTo(src);
    }
}
//--------------------------------
//Inverse wavelet transform
//--------------------------------
static void cvInvHaarWavelet(Mat &src,Mat &dst,int NIter, int SHRINKAGE_TYPE=0, float SHRINKAGE_T=50)
{
    float c,dh,dv,dd;
    assert( src.type() == CV_32FC1 );
    assert( dst.type() == CV_32FC1 );
    int width = src.cols;
    int height = src.rows;
    //--------------------------------
    // NIter - number of iterations
    //--------------------------------
    for (int k=NIter;k>0;k--)
    {
        for (int y=0;y<(height>>k);y++)
        {
            for (int x=0; x<(width>>k);x++)
            {
                c=src.at<float>(y,x);
                dh=src.at<float>(y,x+(width>>k));
                dv=src.at<float>(y+(height>>k),x);
                dd=src.at<float>(y+(height>>k),x+(width>>k));

               // (shrinkage)
                switch(SHRINKAGE_TYPE)
                {
                case HARD:
                    dh=hard_shrink(dh,SHRINKAGE_T);
                    dv=hard_shrink(dv,SHRINKAGE_T);
                    dd=hard_shrink(dd,SHRINKAGE_T);
                    break;
                case SOFT:
                    dh=soft_shrink(dh,SHRINKAGE_T);
                    dv=soft_shrink(dv,SHRINKAGE_T);
                    dd=soft_shrink(dd,SHRINKAGE_T);
                    break;
                case GARROT:
                    dh=Garrot_shrink(dh,SHRINKAGE_T);
                    dv=Garrot_shrink(dv,SHRINKAGE_T);
                    dd=Garrot_shrink(dd,SHRINKAGE_T);
                    break;
                }

                //-------------------
                dst.at<float>(y*2,x*2)=0.5*(c+dh+dv+dd);
                dst.at<float>(y*2,x*2+1)=0.5*(c-dh+dv-dd);
                dst.at<float>(y*2+1,x*2)=0.5*(c+dh-dv-dd);
                dst.at<float>(y*2+1,x*2+1)=0.5*(c-dh-dv+dd);
            }
        }
        Mat C=src(Rect(0,0,width>>(k-1),height>>(k-1)));
        Mat D=dst(Rect(0,0,width>>(k-1),height>>(k-1)));
        D.copyTo(C);
    }
}
//--------------------------------
//
//--------------------------------
//int process(VideoCapture& capture)
void MainWindow::process()
{
    int n = 0;
    const int NIter=4;
    char filename[200];
    string window_name = "video | q or esc to quit";
    cout << "press space to save a picture. q or esc to quit" << endl;
    namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable window;
    Mat frame;
    frame= origin_image->clone();

    Mat GrayFrame=Mat(frame.rows, frame.cols, CV_8UC1);
    Mat Src=Mat(frame.rows, frame.cols, CV_32FC1);
    Mat Dst=Mat(frame.rows, frame.cols, CV_32FC1);
    Mat Temp=Mat(frame.rows, frame.cols, CV_32FC1);
    Mat Filtered=Mat(frame.rows, frame.cols, CV_32FC1);

        Dst=0;
        //capture >> frame;
        //if (frame.empty()) continue;
        cvtColor(frame, GrayFrame, CV_BGR2GRAY);
        GrayFrame.convertTo(Src,CV_32FC1);
        cvHaarWavelet(Src,Dst,NIter);

        Dst.copyTo(Temp);

        cvInvHaarWavelet(Temp,Filtered,NIter,GARROT,30);

        imshow(window_name, frame);

        double M=0,m=0;
        //----------------------------------------------------
        // Normalization to 0-1 range (for visualization)
        //----------------------------------------------------
        minMaxLoc(Dst,&m,&M);
        if((M-m)>0) {Dst=Dst*(1.0/(M-m))-m/(M-m);}
        imshow("Coeff", Dst);

        minMaxLoc(Filtered,&m,&M);
        if((M-m)>0) {Filtered=Filtered*(1.0/(M-m))-m/(M-m);}
        imshow("Filtered", Filtered);

//        char key = (char)waitKey(5);
//        switch (key)
//        {
//        case 'q':
//        case 'Q':
//        case 27: //escape key
//            return 0;
//        case ' ': //Save an image
//            sprintf(filename,"filename%.3d.jpg",n++);
//            imwrite(filename,frame);
//            cout << "Saved " << filename << endl;
//            break;
//        default:
//            break;
//        }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QImage cvMat_to_QImage(const cv::Mat &mat ) {
  switch ( mat.type() )
  {
     // 8-bit, 4 channel
     case CV_8UC4:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32 );
        return image;
     }

     // 8-bit, 3 channel
     case CV_8UC3:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
        return image.rgbSwapped();
     }

     // 8-bit, 1 channel
     case CV_8UC1:
     {
        static QVector<QRgb>  sColorTable;
        // only create our color table once
        if ( sColorTable.isEmpty() )
        {
           for ( int i = 0; i < 256; ++i )
              sColorTable.push_back( qRgb( i, i, i ) );
        }
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8 );
        image.setColorTable( sColorTable );
        return image;
     }

     default:
        qDebug("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
        break;
  }
  return QImage();
}

void MainWindow::on_action_import_triggered()
{
    QString imagePath = QFileDialog::getOpenFileName( this, tr("Open File"),"",tr("Image Files (*.png *.jpg *.bmp)"));
       if(imagePath.length() == 0) {
           QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));

       }
       else {
           origin_image=new cv::Mat();//allocate memory to pointer "origin_image"
           *origin_image=cv::imread(imagePath.toStdString());

           Q_origin_image = new QImage();
           *Q_origin_image=cvMat_to_QImage(*origin_image);
           QPixmap image_pixmap=QPixmap::fromImage(*Q_origin_image);
           ui->label_origin->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
       }
}

void MainWindow::on_pb_trapezoidal_clicked()
{
    cv::Mat trap = cv::Mat(origin_image->size(), CV_8U);
        cv::Mat src2 = origin_image->clone();
        cv::cvtColor(*origin_image, src2, CV_BGR2GRAY);

        for(int i = 0 ; i < trap.rows ; i++){
            for(int j = 0 ; j < trap.cols ; j++){
                double ii = i + j/4 - i*j/(2*trap.rows);
                double jj = 3*j/4 + i*j/(trap.cols*trap.rows);
                trap.at<uchar>(jj, ii) = src2.at<uchar>(j, i);
            }
        }
        ui->label_A->setText("Transform Image : Trapezoidal Transform");
        QImage show=cvMat_to_QImage(trap);
        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_pb_wavy_clicked()
{
    cv::Mat wavy = origin_image->clone();
    cv::Mat wavy2 = cv::Mat(wavy.size(), CV_8U);
       cv::Mat src2 = origin_image->clone();
       cv::cvtColor(src2, src2, CV_BGR2GRAY);
       cv::cvtColor(wavy, wavy, CV_BGR2GRAY);
       int amplitude = ui->horizontalSlider_A->value();
       double frequency =  ui->horizontalSlider_F->value();
       for(int i = 0 ; i < src2.rows ; i++){
           for(int j = 0 ; j < src2.cols ; j++){
               int  offset_x = amplitude * sin(2*CV_PI* i/frequency );
               int  offset_y = amplitude * cos(2*CV_PI* j/frequency);
               if(j+offset_x>0 && i+offset_y>0){
                   if( j+offset_x < src2.rows && i+offset_y <src2.cols  )  wavy2.at<uchar>(i, j) = src2.at<uchar>((i+offset_y)%src2.rows,(offset_x+j)%src2.cols);
                   //else  wavy.at<uchar>(i, j) = 0;
               }
               //else  wavy.at<uchar>(i, j) = 0;
           }
       }
//       for(int i = 0 ; i < src2.rows ; i++){
//           for(int j = 0 ; j < src2.cols ; j++){
//               int  offset_x = amplitude * sin(frequency * i);
//               int  offset_y = 0;
//               if( j-offset_x >0 && i/200%2==1)  wavy2.at<uchar>(i, j) = src2.at<uchar>(i, (j-offset_x)%wavy.cols);
//               else if( j-offset_x >0 && i/200%2==0)  wavy2.at<uchar>(i, j) = wavy.at<uchar>(i, j);
//               else  wavy2.at<uchar>(i, j) = 0;
//           }
//       }

       ui->label_A->setText("Transform Image : Wavy Transformation");
       QImage show=cvMat_to_QImage(wavy2);
       ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));

}

void MainWindow::on_pb_Circular_clicked()
{
    cv::Mat circular(origin_image->size(), CV_8U);
    cv::Mat src2;
    cv::cvtColor(*origin_image, src2, CV_BGR2GRAY);
    for(int i = 0 ; i < circular.rows ; i++){
        for(int j = 0 ; j < circular.cols ; j++){
            double ii = (i - circular.rows / 2.0) / (circular.rows/2.0);
            double jj = (j - circular.cols / 2.0) / (circular.cols/2.0);
            double iii = ii*sqrt(1 - jj*jj/2);
            double jjj = jj*sqrt(1 - ii*ii/2);
            int iiii = iii*(circular.rows)/2 + (circular.rows)/2;
            int jjjj = jjj*(circular.cols)/2 + (circular.cols)/2;
            circular.at<uchar>(iiii, jjjj) = src2.at<uchar>(i, j);
        }
    }
    ui->label_A->setText("Transform Image : Circular Transform");
    QImage show=cvMat_to_QImage(circular);
    ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));

}

void MainWindow::on_pb_applykmeans_clicked()
{
    cv::Mat hough = origin_image->clone();
        cv::Mat result = origin_image->clone();
        cv::cvtColor(hough, hough, CV_BGR2GRAY);
        cv::Mat canny;
        cv::Canny(hough, canny, 50, 200, 3);
        //cv::imshow("Canny", canny);

        std::vector<cv::Vec4i> linesP;
        cv::HoughLinesP(canny, linesP, 1, CV_PI/360, 50, 50, 10 );
        //qDebug() << linesP.size();
        std::vector<cv::Point> contour;
        for( size_t i = 0; i < linesP.size(); i++ )
        {
            cv::Vec4i l = linesP[i];
            cv::line(result, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,255,0), 3, cv::LINE_AA);

            cv::circle(result,cv::Point(l[0], l[1]),20,cv::Scalar(0,0,255),1);
            cv::circle(result,cv::Point(l[2], l[3]),20,cv::Scalar(255,0,0),1);
               contour.push_back(cv::Point(l[0], l[1]));
               contour.push_back(cv::Point(l[2], l[3]));
            double distance = sqrt(pow(l[0]-l[2], 2) + pow(l[1]-l[3], 2));
            cv::putText(result,std::to_string(distance),cv::Point((l[0]+l[2])/2, (l[1]+l[3])/2),cv::FONT_HERSHEY_SIMPLEX,0.4,cv::Scalar(255, 255, 255),1, cv::LINE_AA);
        }

        double area = contourArea(contour,false);
        qDebug() << area;
        ui->label_show_B1->setText("AREA:"+QString::number(area));
        ui->label_A->setText("Transform Image : Hough Transform");
        QImage show=cvMat_to_QImage(result);
        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));

}

void MainWindow::on_pb_Wavelet_clicked()
{
//    cv::Mat src = origin_image->clone();
//    cv::cvtColor(src, src, CV_BGR2GRAY);
//    src.convertTo(src,CV_32FC1);
//    cv::Mat dst = cv::Mat(src.size(), CV_32FC1);
//    int NIter=3;
//    float c,dh,dv,dd;
//        //assert( src.type() == CV_32FC1 );
//       // assert( dst.type() == CV_32FC1 );
//        int width = src.cols;
//        int height = src.rows;
//        for (int k=0;k<NIter;k++)
//        {
//            for (int y=0;y<(height>>(k+1));y++)
//            {
//                for (int x=0; x<(width>>(k+1));x++)
//                {
//                    c=(src.at<float>(2*y,2*x)+src.at<float>(2*y,2*x+1)+src.at<float>(2*y+1,2*x)+src.at<float>(2*y+1,2*x+1))*0.5;
//                    dst.at<float>(y,x)=c;

//                    dh=(src.at<float>(2*y,2*x)+src.at<float>(2*y+1,2*x)-src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x+1))*0.5;
//                    dst.at<float>(y,x+(width>>(k+1)))=dh;

//                    dv=(src.at<float>(2*y,2*x)+src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x)-src.at<float>(2*y+1,2*x+1))*0.5;
//                    dst.at<float>(y+(height>>(k+1)),x)=dv;

//                    dd=(src.at<float>(2*y,2*x)-src.at<float>(2*y,2*x+1)-src.at<float>(2*y+1,2*x)+src.at<float>(2*y+1,2*x+1))*0.5;
//                    dst.at<float>(y+(height>>(k+1)),x+(width>>(k+1)))=dd;
//                }
//            }
//            dst.copyTo(src);
//        }
//        //CV_32f to CV_8U
//        double minVal,maxVal;
//        cv::minMaxIdx(dst,&minVal,&maxVal);
//        dst.convertTo(dst,CV_8UC1,255.0/(maxVal-minVal),-minVal);

//        ui->label_A->setText("Transform Image : Wavelet transform");
//        QImage show=cvMat_to_QImage(dst);
//        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
    //VideoCapture capture(0);
    process();
}
