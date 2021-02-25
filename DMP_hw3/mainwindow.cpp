#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qfiledialog.h"
#include "QDebug"
#include <opencv2/imgproc.hpp>

//#include <QFrame>
QImage cvMat_to_QImage(const cv::Mat &mat );

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
   // QFrame *frame = new QFrame;
   // frame->setObjectName("myframe");
    //frame->resize(400,700);
    //frame->setStyleSheet("QFrame#myframe{border-image:url(back_(1).png)}" );
   // frame->show();


    //this->centralWidget()->setStyleSheet("border-image:url(back_(1).png);" );


      //QTableWidget *tableWidget = new QTableWidget(5,5); // 构造了一个QTableWidget的对象，并且设置为10行，5列
      //    也可用下面的方法构造QTableWidget对象
      //    QTableWidget *tableWidget = new QTableWidget;
      //    tableWidget->setRowCount(10);     //设置行数为10
      //    tableWidget->setColumnCount(5);   //设置列数为5

      ui->tableWidget->setFont(QFont("Taipei Sans TC Beta"));
      ui->tableWidget->setRowCount(3);     //设置行数为3
      ui->tableWidget->setColumnCount(3);   //设置列数为3
      ui->tableWidget->setWindowTitle("QTableWidget & Item");
      //ui->tableWidget->resize(350, 200);  //設置大小
      //QStringList header;                 //設置標題
      //header<<"Month"<<"Description";
      //ui->tableWidget->setHorizontalHeaderLabels(header);

      masksize = ui->spinBox->value();
         for(int i = 0 ; i < masksize ; i++){
             for(int j = 0 ; j < masksize ; j++){
                 ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(1)));
             }
         }
      //ui->tableWidget->setItem(0,1,new QTableWidgetItem(QIcon("images/IED.png"), "Jan's month"));//可以設定icon
      ui->tableWidget->show();

      //combobox filter
      QStringList QfilterList;//停止位
      QfilterList.clear();
      QfilterList <<tr("mean filter")<<tr("median filter")<<tr("max filter")<<tr("min filter")<<tr("Gaussian filter");
      ui->cbox_filer->clear();
      ui->cbox_filer->addItems(QfilterList);
      //注意index從0開始計數，此時實際上是選中第四個
      //ui->comboBox->setCurrentIndex(3);

      //combobox edge
      QStringList QedgeList;//停止位
      QedgeList.clear();
      QedgeList <<tr("LoG(Marr_H...)")<<tr("Sobel_x")<<tr("Sobel_y")<<tr("Sobel_xy")<<tr("zero_crossing");
      ui->cbox_edge->clear();
      ui->cbox_edge->addItems(QedgeList);

      //initial matrix
       matrix = new int*[masksize];
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


void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pb_apply_clicked()//filter choice
{
    int choose=ui->cbox_filer->currentIndex();

    if(choose==0){
        meanfilter();
    }
    if(choose==1)
        mediamfilter();
    if(choose==2)
        maxfilter();
    if(choose==3)
        minfilter();
    if(choose==4)
        gaussianfilter();
}

void MainWindow::meanfilter()//平均濾波器
{
    delete matrix;
    matrix = new int*[masksize];
    for(int i = 0; i < masksize; i++)
        matrix[i] = new int[masksize];
    for(int i = 0 ; i < masksize ; i++){
        for(int j = 0 ; j < masksize ; j++){
            matrix[i][j] = ui->tableWidget->itemAt(i, j)->text().toInt();
        }
    }
    cv::Mat output;
    output =origin_image->clone();
    //qDebug() << "output clone";

    for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
        for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
            int sumB = 0, sumG = 0, sumR = 0;
            int m = 0;
            for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                    sumB += origin_image->at<cv::Vec3b>(a, b)[0]*matrix[m/masksize][m%masksize];
                    sumG +=origin_image->at<cv::Vec3b>(a, b)[1]*matrix[m/masksize][m%masksize];
                    sumR += origin_image->at<cv::Vec3b>(a, b)[2]*matrix[m/masksize][m%masksize];
                    m++;
                }
            }
            output.at<cv::Vec3b>(i, j)[0] = (1.0/(masksize*masksize))*sumB;
            output.at<cv::Vec3b>(i, j)[1] = (1.0/(masksize*masksize))*sumG;
            output.at<cv::Vec3b>(i, j)[2] = (1.0/(masksize*masksize))*sumR;
        }
    }

    QImage out=cvMat_to_QImage(output);
    QPixmap image_pixmap=QPixmap::fromImage(out);
    ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));

}
void MainWindow::mediamfilter()//中間值濾波器
{

    delete matrix;
    matrix = new int*[masksize];
    for(int i = 0; i < masksize; i++)
        matrix[i] = new int[masksize];
    for(int i = 0 ; i < masksize ; i++){
        for(int j = 0 ; j < masksize ; j++){
            matrix[i][j] = ui->tableWidget->itemAt(i, j)->text().toInt();
        }
    }
    cv::Mat output;
    output =origin_image->clone();
    //qDebug() << "output clone";

    int *meanvalueB;
    meanvalueB = new int[masksize*masksize];
    int *meanvalueG;
    meanvalueG = new int[masksize*masksize];
    int *meanvalueR;
    meanvalueR = new int[masksize*masksize];

    for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
        for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
            int sumB = 0, sumG = 0, sumR = 0;
            int m = 0;
            for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                    meanvalueB[m] = origin_image->at<cv::Vec3b>(a, b)[0]*matrix[m/masksize][m%masksize];
                    meanvalueG[m] = origin_image->at<cv::Vec3b>(a, b)[1]*matrix[m/masksize][m%masksize];
                    meanvalueR[m] = origin_image->at<cv::Vec3b>(a, b)[2]*matrix[m/masksize][m%masksize];
                    m++;
                }
            }
                    std::sort(meanvalueB, meanvalueB + masksize * masksize);
                    std::sort(meanvalueG, meanvalueG + masksize * masksize);
                    std::sort(meanvalueR, meanvalueR + masksize * masksize);
                    output.at<cv::Vec3b>(i, j)[0] = meanvalueB[(masksize*masksize)/2];
                    output.at<cv::Vec3b>(i, j)[1] = meanvalueG[(masksize*masksize)/2];
                    output.at<cv::Vec3b>(i, j)[2] = meanvalueR[(masksize*masksize)/2];
        }
    }
    QImage out=cvMat_to_QImage(output);
    QPixmap image_pixmap=QPixmap::fromImage(out);
    ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));

}
void MainWindow::maxfilter()//最大值濾波器
{

    delete matrix;
    matrix = new int*[masksize];
    for(int i = 0; i < masksize; i++)
        matrix[i] = new int[masksize];
    for(int i = 0 ; i < masksize ; i++){
        for(int j = 0 ; j < masksize ; j++){
            matrix[i][j] = ui->tableWidget->itemAt(i, j)->text().toInt();
        }
    }
    cv::Mat output;
    output =origin_image->clone();
    //qDebug() << "output clone";

    int *meanvalueB;
    meanvalueB = new int[masksize*masksize];
    int *meanvalueG;
    meanvalueG = new int[masksize*masksize];
    int *meanvalueR;
    meanvalueR = new int[masksize*masksize];

    for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
        for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
            int sumB = 0, sumG = 0, sumR = 0;
            int m = 0;
            for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                    meanvalueB[m] = origin_image->at<cv::Vec3b>(a, b)[0]*matrix[m/masksize][m%masksize];
                    meanvalueG[m] = origin_image->at<cv::Vec3b>(a, b)[1]*matrix[m/masksize][m%masksize];
                    meanvalueR[m] = origin_image->at<cv::Vec3b>(a, b)[2]*matrix[m/masksize][m%masksize];
                    m++;
                }
            }
                    std::sort(meanvalueB, meanvalueB + masksize * masksize);
                    std::sort(meanvalueG, meanvalueG + masksize * masksize);
                    std::sort(meanvalueR, meanvalueR + masksize * masksize);
                    output.at<cv::Vec3b>(i, j)[0] = meanvalueB[(masksize*masksize)-1];
                    output.at<cv::Vec3b>(i, j)[1] = meanvalueG[(masksize*masksize)-1];
                    output.at<cv::Vec3b>(i, j)[2] = meanvalueR[(masksize*masksize)-1];
        }
    }
    QImage out=cvMat_to_QImage(output);
    QPixmap image_pixmap=QPixmap::fromImage(out);
    ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));

}
void MainWindow::minfilter()//最小值濾波器
{
    delete matrix;
    matrix = new int*[masksize];
    for(int i = 0; i < masksize; i++)
        matrix[i] = new int[masksize];
    for(int i = 0 ; i < masksize ; i++){
        for(int j = 0 ; j < masksize ; j++){
            matrix[i][j] = ui->tableWidget->itemAt(i, j)->text().toInt();
        }
    }
    cv::Mat output;
    output =origin_image->clone();
    //qDebug() << "output clone";

    int *meanvalueB;
    meanvalueB = new int[masksize*masksize];
    int *meanvalueG;
    meanvalueG = new int[masksize*masksize];
    int *meanvalueR;
    meanvalueR = new int[masksize*masksize];

    for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
        for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
            int sumB = 0, sumG = 0, sumR = 0;
            int m = 0;
            for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                    meanvalueB[m] = origin_image->at<cv::Vec3b>(a, b)[0]*matrix[m/masksize][m%masksize];
                    meanvalueG[m] = origin_image->at<cv::Vec3b>(a, b)[1]*matrix[m/masksize][m%masksize];
                    meanvalueR[m] = origin_image->at<cv::Vec3b>(a, b)[2]*matrix[m/masksize][m%masksize];
                    m++;
                }
            }
                    std::sort(meanvalueB, meanvalueB + masksize * masksize);
                    std::sort(meanvalueG, meanvalueG + masksize * masksize);
                    std::sort(meanvalueR, meanvalueR + masksize * masksize);
                    output.at<cv::Vec3b>(i, j)[0] = meanvalueB[0];
                    output.at<cv::Vec3b>(i, j)[1] = meanvalueG[0];
                    output.at<cv::Vec3b>(i, j)[2] = meanvalueR[0];
        }
    }
    QImage out=cvMat_to_QImage(output);
    QPixmap image_pixmap=QPixmap::fromImage(out);
    ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));

}

void MainWindow::on_cbox_edge_activated(int index)
{
    if(index==0){
        LoG();
    }
    if(index==1)
        Sobel_x();
    if(index==2)
        Sobel_y();
    if(index==3)
        Sobel_xy();
    if(index==4)
        zero_crossing();

}
void MainWindow::zero_crossing()
{
    int **lapacian;
       lapacian = new int*[3];
       for(int i = 0; i < 3; i++)
           lapacian[i] = new int[3];
       lapacian[0][0] = 0;lapacian[0][1] = 1;lapacian[0][2] = 0;
       lapacian[1][0] = 1;lapacian[1][1] = -4;lapacian[1][2] = 1;
       lapacian[2][0] = 0;lapacian[2][1] = 1;lapacian[2][2] = 0;
       cv::Mat zero;

// = filtering(src, lapacian, 3, false, false, true)
       cv::Mat laplacian;
       laplacian =origin_image->clone();
       //qDebug() << "output clone";

       for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
           for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
               int sumB = 0, sumG = 0, sumR = 0;
               int m = 0;
               for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                   for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                       sumB += origin_image->at<cv::Vec3b>(a, b)[0]*lapacian[m/masksize][m%masksize];
                       sumG += origin_image->at<cv::Vec3b>(a, b)[1]*lapacian[m/masksize][m%masksize];
                       sumR += origin_image->at<cv::Vec3b>(a, b)[2]*lapacian[m/masksize][m%masksize];
                       m++;
                   }
               }
               if(sumB > 255) sumB = 255;
               if(sumG > 255) sumG = 255;
               if(sumR > 255) sumR = 255;
               if(sumB < 0) sumB = 0;
               if(sumG < 0) sumG = 0;
               if(sumR < 0) sumR = 0;
                laplacian.at<cv::Vec3b>(i, j)[0] = sumB;
                laplacian.at<cv::Vec3b>(i, j)[1] = sumG;
                laplacian.at<cv::Vec3b>(i, j)[2] = sumR;
           }
       }
       zero=laplacian;

       cv::cvtColor(zero, zero, CV_BGR2GRAY);
       int thresh = ui->threshold->value();
       for(int i = 0 ; i < zero.rows ; i++){
           for(int j  = 0 ; j < zero.cols ; j++){
               if(zero.at<uchar>(i,j) > thresh){
                   zero.at<uchar>(i,j) = 255;
               }
               if(zero.at<uchar>(i,j) < thresh){
                   zero.at<uchar>(i,j) = 0;
               }
           }
       }

       for(int i = 1 ; i < zero.rows-1 ; i++){
           for(int j  = 1 ; j < zero.cols-1 ; j++){
               int count = 0;
               if(zero.at<uchar>(i,j) == zero.at<uchar>(i+1,j)){
                   count++;
               }
               if(zero.at<uchar>(i,j) == zero.at<uchar>(i,j+1)){
                   count++;
               }
               if(zero.at<uchar>(i,j) == zero.at<uchar>(i-1,j)){
                   count++;
               }
               if(zero.at<uchar>(i,j) == zero.at<uchar>(i,j-1)){
                   count++;
               }
               if(count >= 2)  zero.at<uchar>(i, j) = 0;
               else zero.at<uchar>(i, j) = 255;
           }
       }

       QImage out=cvMat_to_QImage(zero);
       QPixmap image_pixmap=QPixmap::fromImage(out);
       ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
}
void MainWindow::LoG()
{
    int **gmatrix;
        gmatrix = new int*[5];
        for(int i = 0; i < 5; i++)
            gmatrix[i] = new int[5];
        gmatrix[0][0] = 0;gmatrix[0][1] = 0;gmatrix[0][2] = -1;gmatrix[0][3] = 0;gmatrix[0][4] = 0;
        gmatrix[1][0] = 0;gmatrix[1][1] = -1;gmatrix[1][2] = -2;gmatrix[1][3] = -1;gmatrix[1][4] = 0;
        gmatrix[2][0] = -1;gmatrix[2][1] = -2;gmatrix[2][2] = 16;gmatrix[2][3] = -2;gmatrix[2][4] = -1;
        gmatrix[3][0] = 0;gmatrix[3][1] = -1;gmatrix[3][2] = -2;gmatrix[3][3] = -1;gmatrix[3][4] = 0;
        gmatrix[4][0] = 0;gmatrix[4][1] = 0;gmatrix[4][2] = -1;gmatrix[4][3] = 0;gmatrix[4][4] = 0;
        masksize=5;
        //smooth the image with a Gaussian filter
        cv::Mat gaussian;
        gaussian =origin_image->clone();
        //qDebug() << "output clone";

        for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
            for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
                int sumB = 0, sumG = 0, sumR = 0;
                int m = 0;
                for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                    for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                        sumB += origin_image->at<cv::Vec3b>(a, b)[0]*gmatrix[m/masksize][m%masksize];
                        sumG += origin_image->at<cv::Vec3b>(a, b)[1]*gmatrix[m/masksize][m%masksize];
                        sumR += origin_image->at<cv::Vec3b>(a, b)[2]*gmatrix[m/masksize][m%masksize];
                        m++;
                    }
                }
//                if(sumB > 255) sumB = 255;
//                if(sumG > 255) sumG = 255;
//                if(sumR > 255) sumR = 255;
//                if(sumB < 0) sumB = 0;
//                if(sumG < 0) sumG = 0;
//                if(sumR < 0) sumR = 0;
                gaussian.at<cv::Vec3b>(i, j)[0] = sumB;
                gaussian.at<cv::Vec3b>(i, j)[1] = sumG;
                gaussian.at<cv::Vec3b>(i, j)[2] = sumR;
            }
        }
        //cv::imshow("Marr and Hildreth filter", gaussian);
        QImage out=cvMat_to_QImage(gaussian);
        QPixmap image_pixmap=QPixmap::fromImage(out);
        ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));

}

void MainWindow::Sobel_x()
{
    int **sobelx;
        sobelx = new int*[3];
        for(int i = 0; i < 3; i++)
            sobelx[i] = new int[3];
        sobelx[0][0] = -1;sobelx[0][1] = 0;sobelx[0][2] = 1;
        sobelx[1][0] = -2;sobelx[1][1] = 0;sobelx[1][2] = 2;
        sobelx[2][0] = -1;sobelx[2][1] = 0;sobelx[2][2] = 1;
        cv::Mat matsobelx;
        matsobelx =origin_image->clone();
        //qDebug() << "output clone";
        masksize=3;
        for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
            for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
                int sumB = 0, sumG = 0, sumR = 0;
                int m = 0;
                for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                    for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                        sumB += origin_image->at<cv::Vec3b>(a, b)[0]*sobelx[m/masksize][m%masksize];
                        sumG += origin_image->at<cv::Vec3b>(a, b)[1]*sobelx[m/masksize][m%masksize];
                        sumR += origin_image->at<cv::Vec3b>(a, b)[2]*sobelx[m/masksize][m%masksize];
                        m++;
                    }
                }
                if(sumB > 255) sumB = 255;
                if(sumG > 255) sumG = 255;
                if(sumR > 255) sumR = 255;
                if(sumB < 0) sumB = 0;
                if(sumG < 0) sumG = 0;
                if(sumR < 0) sumR = 0;
                matsobelx.at<cv::Vec3b>(i, j)[0] = sumB;
                matsobelx.at<cv::Vec3b>(i, j)[1] = sumG;
                matsobelx.at<cv::Vec3b>(i, j)[2] = sumR;
            }
        }
        //cv::imshow("Marr and Hildreth filter", gaussian);
        QImage out=cvMat_to_QImage(matsobelx);
        QPixmap image_pixmap=QPixmap::fromImage(out);
        ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
}
void MainWindow::Sobel_y()
{
    int **sobely;
        sobely = new int*[3];
        for(int i = 0; i < 3; i++)
               sobely[i] = new int[3];
           sobely[0][0] = -1;sobely[0][1] = -2;sobely[0][2] = -1;
           sobely[1][0] = 0;sobely[1][1] = 0;sobely[1][2] = 0;
           sobely[2][0] = 1;sobely[2][1] = 2;sobely[2][2] = 1;
        cv::Mat matsobelx;
        matsobelx =origin_image->clone();
        //qDebug() << "output clone";
        masksize=3;
        for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
            for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
                int sumB = 0, sumG = 0, sumR = 0;
                int m = 0;
                for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                    for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                        sumB += origin_image->at<cv::Vec3b>(a, b)[0]*sobely[m/masksize][m%masksize];
                        sumG += origin_image->at<cv::Vec3b>(a, b)[1]*sobely[m/masksize][m%masksize];
                        sumR += origin_image->at<cv::Vec3b>(a, b)[2]*sobely[m/masksize][m%masksize];
                        m++;
                    }
                }
                if(sumB > 255) sumB = 255;
                if(sumG > 255) sumG = 255;
                if(sumR > 255) sumR = 255;
                if(sumB < 0) sumB = 0;
                if(sumG < 0) sumG = 0;
                if(sumR < 0) sumR = 0;
                matsobelx.at<cv::Vec3b>(i, j)[0] = sumB;
                matsobelx.at<cv::Vec3b>(i, j)[1] = sumG;
                matsobelx.at<cv::Vec3b>(i, j)[2] = sumR;
            }
        }
        //cv::imshow("Marr and Hildreth filter", gaussian);
        QImage out=cvMat_to_QImage(matsobelx);
        QPixmap image_pixmap=QPixmap::fromImage(out);
        ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
}
void MainWindow::Sobel_xy()
{
    int **sobelx;
        sobelx = new int*[3];
        for(int i = 0; i < 3; i++)
               sobelx[i] = new int[3];
           sobelx[0][0] = -1;sobelx[0][1] = 0;sobelx[0][2] = 1;
           sobelx[1][0] = -2;sobelx[1][1] = 0;sobelx[1][2] = 2;
           sobelx[2][0] = -1;sobelx[2][1] = 0;sobelx[2][2] = 1;
        cv::Mat matsobelx;
        matsobelx =origin_image->clone();
        //qDebug() << "output clone";
        masksize=3;
        for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
            for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
                int sumB = 0, sumG = 0, sumR = 0;
                int m = 0;
                for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                    for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                        sumB += origin_image->at<cv::Vec3b>(a, b)[0]*sobelx[m/masksize][m%masksize];
                        sumG += origin_image->at<cv::Vec3b>(a, b)[1]*sobelx[m/masksize][m%masksize];
                        sumR += origin_image->at<cv::Vec3b>(a, b)[2]*sobelx[m/masksize][m%masksize];
                        m++;
                    }
                }
                if(sumB > 255) sumB = 255;
                if(sumG > 255) sumG = 255;
                if(sumR > 255) sumR = 255;
                if(sumB < 0) sumB = 0;
                if(sumG < 0) sumG = 0;
                if(sumR < 0) sumR = 0;
                matsobelx.at<cv::Vec3b>(i, j)[0] = sumB;
                matsobelx.at<cv::Vec3b>(i, j)[1] = sumG;
                matsobelx.at<cv::Vec3b>(i, j)[2] = sumR;
            }
        }
        int **sobely;
            sobely = new int*[3];
            for(int i = 0; i < 3; i++)
                   sobely[i] = new int[3];
               sobely[0][0] = -1;sobely[0][1] = -2;sobely[0][2] = -1;
               sobely[1][0] = 0;sobely[1][1] = 0;sobely[1][2] = 0;
               sobely[2][0] = 1;sobely[2][1] = 2;sobely[2][2] = 1;
            cv::Mat matsobely;
            matsobely =origin_image->clone();
            //qDebug() << "output clone";
            masksize=3;
            for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
                for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
                    int sumB = 0, sumG = 0, sumR = 0;
                    int m = 0;
                    for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
                        for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
                            sumB += origin_image->at<cv::Vec3b>(a, b)[0]*sobely[m/masksize][m%masksize];
                            sumG += origin_image->at<cv::Vec3b>(a, b)[1]*sobely[m/masksize][m%masksize];
                            sumR += origin_image->at<cv::Vec3b>(a, b)[2]*sobely[m/masksize][m%masksize];
                            m++;
                        }
                    }
                    if(sumB > 255) sumB = 255;
                    if(sumG > 255) sumG = 255;
                    if(sumR > 255) sumR = 255;
                    if(sumB < 0) sumB = 0;
                    if(sumG < 0) sumG = 0;
                    if(sumR < 0) sumR = 0;
                    matsobely.at<cv::Vec3b>(i, j)[0] = sumB;
                    matsobely.at<cv::Vec3b>(i, j)[1] = sumG;
                    matsobely.at<cv::Vec3b>(i, j)[2] = sumR;
                }
            }

        cv::Mat sobel(origin_image->rows,origin_image->cols, CV_8UC3);
            for(int i = 0 ; i < sobel.rows ; i++){
                for(int j = 0 ; j < sobel.cols ; j++){
                    sobel.at<cv::Vec3b>(i,j)[0] = matsobelx.at<cv::Vec3b>(i, j)[0] + matsobely.at<cv::Vec3b>(i, j)[0];
                    sobel.at<cv::Vec3b>(i,j)[1] = matsobelx.at<cv::Vec3b>(i, j)[1] + matsobely.at<cv::Vec3b>(i, j)[1];
                    sobel.at<cv::Vec3b>(i,j)[2] = matsobelx.at<cv::Vec3b>(i, j)[2] + matsobely.at<cv::Vec3b>(i, j)[2];
                }
            }
        //cv::imshow("Marr and Hildreth filter", gaussian);
        QImage out=cvMat_to_QImage(sobel);
        QPixmap image_pixmap=QPixmap::fromImage(out);
        ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
}
void MainWindow::gaussianfilter()
{
    delete matrix;
    matrix = new int*[masksize];
    for(int i = 0; i < masksize; i++)
        matrix[i] = new int[masksize];
    for(int i = 0 ; i < masksize ; i++){
        for(int j = 0 ; j < masksize ; j++){
            matrix[i][j] = ui->tableWidget->itemAt(i, j)->text().toInt();
        }
    }
    cv::Mat output;
    output =origin_image->clone();
    //qDebug() << "output clone";
    GaussianBlur(*origin_image, output,cv:: Size(masksize,masksize), 0);
//    for(int i = 0 + masksize/2 ; i < origin_image->rows - masksize/2 ; i++){
//        for(int j = 0 + masksize/2 ; j < origin_image->cols - masksize/2 ; j++){
//            int sumB = 0, sumG = 0, sumR = 0;
//            int m = 0;
//            for(int a = i-masksize/2 ; a <= i+masksize/2 ; a++){
//                for(int b = j-masksize/2 ; b <= j+masksize/2 ; b++){
//                    sumB += origin_image->at<cv::Vec3b>(a, b)[0]*matrix[m/masksize][m%masksize];
//                    sumG += origin_image->at<cv::Vec3b>(a, b)[1]*matrix[m/masksize][m%masksize];
//                    sumR += origin_image->at<cv::Vec3b>(a, b)[2]*matrix[m/masksize][m%masksize];
//                    m++;
//                }
//            }
//           output.at<cv::Vec3b>(i, j)[0] = sumB;
//           output.at<cv::Vec3b>(i, j)[1] = sumG;
//           output.at<cv::Vec3b>(i, j)[2] = sumR;
//        }
//    }

    QImage out=cvMat_to_QImage(output);
    QPixmap image_pixmap=QPixmap::fromImage(out);
    ui->label_after->setPixmap(image_pixmap.scaled(ui->label_origin->width(),ui->label_origin->height(),Qt::KeepAspectRatio));
}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    masksize = arg1;
    ui->tableWidget->setColumnCount(masksize);
    ui->tableWidget->setRowCount(masksize);

    for(int i = 0 ; i < masksize ; i++){
           for(int j = 0 ; j < masksize ; j++){
               ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(1)));
           }
       }
    //ui->tableWidget->setItem(0,1,new QTableWidgetItem(QIcon("images/IED.png"), "Jan's month"));//可以設定icon
    ui->tableWidget->show();

}

