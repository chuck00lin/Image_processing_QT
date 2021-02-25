#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qfiledialog.h"
#include "QDebug"


//#include <QFrame>
QImage cvMat_to_QImage(const cv::Mat &mat );
double cal_f(double t);
void rainbow(cv::Mat colorbar);
void Hot(cv::Mat colorbar);
void Winter(cv::Mat colorbar);
void Fall(cv::Mat colorbar);
cv::Mat kmeans(cv::Mat input, int K);

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

void MainWindow::on_pb_RGB_clicked()
{
    cv::Mat rgb = origin_image->clone();
    QImage show=cvMat_to_QImage(rgb);
    ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
    ui->label_A->setText("RGB");
}

void MainWindow::on_pb_CMY_clicked()
{
    cv::Mat cmy = origin_image->clone();

       for(int i = 0 ; i < cmy.rows ; i++){
           for(int j = 0 ; j < cmy.cols ; j++){
               cmy.at<cv::Vec3b>(i, j)[0] = 255 - origin_image->at<cv::Vec3b>(i, j)[0];
               cmy.at<cv::Vec3b>(i, j)[1] = 255 - origin_image->at<cv::Vec3b>(i, j)[1];
               cmy.at<cv::Vec3b>(i, j)[2] = 255 - origin_image->at<cv::Vec3b>(i, j)[2];
           }
       }
       QImage show=cvMat_to_QImage(cmy);
       ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
       ui->label_A->setText("CMY");
}

void MainWindow::on_pb_HSI_clicked()
{


    cv::Mat hsi = origin_image->clone();
    //cv::Mat test = zero
    for(int i = 0 ; i < hsi.rows ; i++){
        for(int j = 0 ; j < hsi.cols ; j++){
            float B = (float)hsi.at<cv::Vec3b>(i, j)[0] / 255.0;
            float G = (float)hsi.at<cv::Vec3b>(i, j)[1] / 255.0;
            float R = (float)hsi.at<cv::Vec3b>(i, j)[2] / 255.0;
            float max = std::max(std::max(B, G), R);
            float min = std::min(std::min(B, G), R);
            //qDebug() << B << G;
            float L = (max + min) / 2;
            hsi.at<cv::Vec3b>(i, j)[1] = L * 255;
            //qDebug() << L;
            float S;
            if(L < 0.5) S = (max - min) / (max + min);
            else S = (max - min) / (2 - (max + min));
            hsi.at<cv::Vec3b>(i, j)[2] = S * 255;
            //qDebug() << S;
            float H;
            if(max == R)  H = (60*(G-B)) / S;
            else if(max == G)  H = (120 + 60*(B-R)) / S;
            else  H = (240 + 60*(R-G)) / S;
            if(H < 0)   H += 360;
            hsi.at<cv::Vec3b>(i, j)[0] = H / 2;
            //qDebug() << H;
        }
    }
    QImage show=cvMat_to_QImage(hsi);
    ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
    ui->label_A->setText("HSI");
}

void MainWindow::on_pb_XYZ_clicked()
{

       cv::Mat xyz = origin_image->clone();
       for(int i = 0 ; i < xyz.rows ; i++){
           for(int j = 0 ; j < xyz.cols ; j++){
               xyz.at<cv::Vec3b>(i, j)[0] = (0.412453*origin_image->at<cv::Vec3b>(i, j)[2] +
                       0.357580*origin_image->at<cv::Vec3b>(i, j)[1] +
                       0.180423*origin_image->at<cv::Vec3b>(i, j)[0]);
               xyz.at<cv::Vec3b>(i, j)[1] = (0.212671*origin_image->at<cv::Vec3b>(i, j)[2] +
                       0.715160*origin_image->at<cv::Vec3b>(i, j)[1] +
                       0.072169*origin_image->at<cv::Vec3b>(i, j)[0]);
               xyz.at<cv::Vec3b>(i, j)[2] = (0.019334*origin_image->at<cv::Vec3b>(i, j)[2] +
                       0.119193*origin_image->at<cv::Vec3b>(i, j)[1] +
                       0.950227*origin_image->at<cv::Vec3b>(i, j)[0]);
           }
       }
       QImage show=cvMat_to_QImage(xyz);
       ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
       ui->label_A->setText("XYZ");
}

void MainWindow::on_pb_Lab_clicked()
{
      cv::Mat lab = origin_image->clone();
      for(int i = 0 ; i < lab.rows ; i++){
          for(int j = 0 ; j < lab.cols ; j++){
              float B = (float)lab.at<cv::Vec3b>(i, j)[0] / 255.0;
              float G = (float)lab.at<cv::Vec3b>(i, j)[1] / 255.0;
              float R = (float)lab.at<cv::Vec3b>(i, j)[2] / 255.0;
              float X = (0.412453*R +
                         0.357580*G +
                         0.180423*B);
              float Y = (0.212671*R +
                         0.715160*G +
                         0.072169*B);
              float Z = (0.019334*R +
                         0.119193*G +
                         0.950227*B);
              X /= 0.950453;
              Z /= 1.088754;
              //qDebug() << X << Y << Z;
              float L;
              if(Y > 0.008856)    L = 116.0*pow(Y, 1.0/3) - 16.0;
              else    L = 903.3*Y;

              //qDebug() << L ;
              float a, b;
              a = 500.0*(cal_f(X) - cal_f(Y)) + 128.0;
              b = 200.0*(cal_f(Y) - cal_f(Z)) + 128.0;
              lab.at<cv::Vec3b>(i, j)[0] = L*255.0/100.0;
              lab.at<cv::Vec3b>(i, j)[1] = a;
              lab.at<cv::Vec3b>(i, j)[2] = b;
          }
      }
      QImage show=cvMat_to_QImage(lab);
      ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
      ui->label_A->setText("Lab");
}

double cal_f(double t){
    if(t > 0.008856)    return pow(t, 1.0/3);
    else    return 7.787*t + 16.0/116.0;
}

void MainWindow::on_pb_YUV_clicked()
{
        cv::Mat yuv = origin_image->clone();
        for(int i = 0 ; i < yuv.rows ; i++){
            for(int j = 0 ; j < yuv.cols ; j++){
                float B = (float)yuv.at<cv::Vec3b>(i, j)[0] / 255.0;
                float G = (float)yuv.at<cv::Vec3b>(i, j)[1] / 255.0;
                float R = (float)yuv.at<cv::Vec3b>(i, j)[2] / 255.0;

                float Y = 0.299*R + 0.587*G + 0.114*B;
                float U = (R-Y)*0.713 + 128.0;
                float V = (B-Y)*0.564 + 128.0;
                yuv.at<cv::Vec3b>(i, j)[0] = Y*255.0;
                yuv.at<cv::Vec3b>(i, j)[2] = U;
                yuv.at<cv::Vec3b>(i, j)[1] = V;
                //qDebug() << Y << U << V;
            }
        }
        QImage show=cvMat_to_QImage(yuv);
        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
        ui->label_A->setText("YUV");
}

void MainWindow::on_pb_Rainbow_clicked()
{
       cv::Mat colorbar(256*4, 50, CV_8UC3);
       rainbow(colorbar);
       cv::resize(colorbar, colorbar, cv::Size(colorbar.cols, 256), CV_INTER_LINEAR);
       cv::Mat clone;
       if(origin_image->channels() == 3) cv::cvtColor(*origin_image, clone, CV_BGR2GRAY);
       else    clone = origin_image->clone();

       cv::Mat pseudo(origin_image->rows, origin_image->cols, CV_8UC3);
       for(int i = 0 ; i < pseudo.rows ; i++){
           for(int j = 0 ; j < pseudo.cols ; j++){
               pseudo.at<cv::Vec3b>(i, j)[0] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[0];
               pseudo.at<cv::Vec3b>(i, j)[1] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[1];
               pseudo.at<cv::Vec3b>(i, j)[2] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[2];
           }
       }
       QImage show=cvMat_to_QImage(pseudo);
       ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
       ui->label_A->setText("Pseudo Color (Rainbow)");
       double angle=90;
       // get rotation matrix for rotating the image around its center in pixel coordinates
       cv::Point2f center((colorbar.cols-1)/2.0, (colorbar.rows-1)/2.0);
       cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
       // determine bounding rectangle, center not relevant
       cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), colorbar.size(), angle).boundingRect2f();
       // adjust transformation matrix
       rot.at<double>(0,2) += bbox.width/2.0 - colorbar.cols/2.0;
       rot.at<double>(1,2) += bbox.height/2.0 - colorbar.rows/2.0;
       cv::Mat dst;
       cv::warpAffine(colorbar, dst, rot, bbox.size());

       QImage color=cvMat_to_QImage(dst);
       ui->label_show_B1->setPixmap(QPixmap::fromImage(color).scaled(ui->label_show_B1->width(),ui->label_show_B1->height()));
}
void rainbow(cv::Mat colorbar){
    int R = 0, G = 0, B = 0;
    for(int i = 0 ; i < 256 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        R++;
    }
    R--;
    for(int i = 256 ; i < 256*2 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        G++;
    }
    G--;
    for(int i = 256*2 ; i < 256*3 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        R--;
    }
    R++;
    for(int i = 256*3 ; i < 256*4 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        B++;
    }
    B--;
}

void Hot(cv::Mat colorbar){
    int R = 0, G = 0, B = 0;
    for(int i = 0 ; i < 256 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        R++;
    }
    R--;
    for(int i = 256 ; i < 256*2 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        G++;
    }
}

void Winter(cv::Mat colorbar){
    int R = 0, G = 0, B = 255;
    for(int i = 0 ; i < 256 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        G++;
    }
    G--;
    for(int i = 256 ; i < 256*2 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        B--;
    }
}

void Fall(cv::Mat colorbar){
    int R = 255, G = 0, B = 0;
    for(int i = 0 ; i < 256 ; i++){
        for(int value = 0 ; value < 50 ; value++){
            colorbar.at<cv::Vec3b>(i, value)[0] = B;
            colorbar.at<cv::Vec3b>(i, value)[1] = G;
            colorbar.at<cv::Vec3b>(i, value)[2] = R;
        }
        G++;
    }
}

cv::Mat kmeans(cv::Mat input, int K){
    cv::Mat kmeans = input.clone();
    cv::Mat raw(input.rows * input.cols, 3, CV_32F);
    cv::Mat label, centers;
    for(int i = 0 ; i < kmeans.rows ; i++){
        for(int j = 0 ; j < kmeans.cols ; j++){
            raw.at<float>(kmeans.cols*i+j, 0) = (float)kmeans.at<cv::Vec3b>(i, j)[0];
            raw.at<float>(kmeans.cols*i+j, 1) = (float)kmeans.at<cv::Vec3b>(i, j)[1];
            raw.at<float>(kmeans.cols*i+j, 2) = (float)kmeans.at<cv::Vec3b>(i, j)[2];
        }
    }
    cv::kmeans(raw, K, label, cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);
    for(int i = 0 ; i < kmeans.rows ; i++){
        for(int j = 0 ; j < kmeans.cols ; j++){
            int labelID = label.at<int>(kmeans.cols*i+j, 0);
            kmeans.at<cv::Vec3b>(i, j)[0] = centers.at<float>(labelID, 0);
            kmeans.at<cv::Vec3b>(i, j)[1] = centers.at<float>(labelID, 1);
            kmeans.at<cv::Vec3b>(i, j)[2] = centers.at<float>(labelID, 2);
        }
    }
    return kmeans;
}
void MainWindow::on_pb_Hot_clicked()
{
       cv::Mat colorbar(256*2, 50, CV_8UC3);
       Hot(colorbar);
       cv::resize(colorbar, colorbar, cv::Size(colorbar.cols, 256), CV_INTER_LINEAR);
       cv::Mat clone;
       if(origin_image->channels() == 3) cv::cvtColor(*origin_image, clone, CV_BGR2GRAY);
       else    clone =origin_image->clone();

       cv::Mat pseudo(origin_image->rows, origin_image->cols, CV_8UC3);
       for(int i = 0 ; i < pseudo.rows ; i++){
           for(int j = 0 ; j < pseudo.cols ; j++){
               pseudo.at<cv::Vec3b>(i, j)[0] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[0];
               pseudo.at<cv::Vec3b>(i, j)[1] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[1];
               pseudo.at<cv::Vec3b>(i, j)[2] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[2];
           }
       }
       QImage show=cvMat_to_QImage(pseudo);
       ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
       ui->label_A->setText("Pseudo Color (HOT)");
       double angle=90;
       // get rotation matrix for rotating the image around its center in pixel coordinates
       cv::Point2f center((colorbar.cols-1)/2.0, (colorbar.rows-1)/2.0);
       cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
       // determine bounding rectangle, center not relevant
       cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), colorbar.size(), angle).boundingRect2f();
       // adjust transformation matrix
       rot.at<double>(0,2) += bbox.width/2.0 - colorbar.cols/2.0;
       rot.at<double>(1,2) += bbox.height/2.0 - colorbar.rows/2.0;
       cv::Mat dst;
       cv::warpAffine(colorbar, dst, rot, bbox.size());

       QImage color=cvMat_to_QImage(dst);
       ui->label_show_B1->setPixmap(QPixmap::fromImage(color).scaled(ui->label_show_B1->width(),ui->label_show_B1->height()));
}

void MainWindow::on_pb_Winter_clicked()
{
        cv::Mat colorbar(256*2, 50, CV_8UC3);
        Winter(colorbar);
        cv::resize(colorbar, colorbar, cv::Size(colorbar.cols, 256), CV_INTER_LINEAR);
        cv::Mat clone;
        if(origin_image->channels() == 3) cv::cvtColor(*origin_image, clone, CV_BGR2GRAY);
        else    clone =origin_image->clone();

        cv::Mat pseudo(origin_image->rows, origin_image->cols, CV_8UC3);
        for(int i = 0 ; i < pseudo.rows ; i++){
            for(int j = 0 ; j < pseudo.cols ; j++){
                pseudo.at<cv::Vec3b>(i, j)[0] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[0];
                pseudo.at<cv::Vec3b>(i, j)[1] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[1];
                pseudo.at<cv::Vec3b>(i, j)[2] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[2];
            }
        }
        //cv::imshow("color bar", colorbar);
        QImage show=cvMat_to_QImage(pseudo);
        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
        ui->label_A->setText("Pseudo Color (WINTER)");
        double angle=90;
        // get rotation matrix for rotating the image around its center in pixel coordinates
        cv::Point2f center((colorbar.cols-1)/2.0, (colorbar.rows-1)/2.0);
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
        // determine bounding rectangle, center not relevant
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), colorbar.size(), angle).boundingRect2f();
        // adjust transformation matrix
        rot.at<double>(0,2) += bbox.width/2.0 - colorbar.cols/2.0;
        rot.at<double>(1,2) += bbox.height/2.0 - colorbar.rows/2.0;
        cv::Mat dst;
        cv::warpAffine(colorbar, dst, rot, bbox.size());

        QImage color=cvMat_to_QImage(dst);
        ui->label_show_B1->setPixmap(QPixmap::fromImage(color).scaled(ui->label_show_B1->width(),ui->label_show_B1->height()));
}

void MainWindow::on_pb_Autumn_clicked()
{
        cv::Mat colorbar(256, 50, CV_8UC3);
        Fall(colorbar);
        cv::resize(colorbar, colorbar, cv::Size(colorbar.cols, 256), CV_INTER_LINEAR);
        cv::Mat clone;
        if(origin_image->channels() == 3) cv::cvtColor(*origin_image, clone, CV_BGR2GRAY);
        else    clone = origin_image->clone();

        cv::Mat pseudo(origin_image->rows, origin_image->cols, CV_8UC3);
        for(int i = 0 ; i < pseudo.rows ; i++){
            for(int j = 0 ; j < pseudo.cols ; j++){
                pseudo.at<cv::Vec3b>(i, j)[0] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[0];
                pseudo.at<cv::Vec3b>(i, j)[1] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[1];
                pseudo.at<cv::Vec3b>(i, j)[2] = colorbar.at<cv::Vec3b>(clone.at<uchar>(i, j), 0)[2];
            }
        }
        QImage show=cvMat_to_QImage(pseudo);
        ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
        ui->label_A->setText("Pseudo Color (AUTUMN)");
        double angle=90;
        // get rotation matrix for rotating the image around its center in pixel coordinates
        cv::Point2f center((colorbar.cols-1)/2.0, (colorbar.rows-1)/2.0);
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
        // determine bounding rectangle, center not relevant
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), colorbar.size(), angle).boundingRect2f();
        // adjust transformation matrix
        rot.at<double>(0,2) += bbox.width/2.0 - colorbar.cols/2.0;
        rot.at<double>(1,2) += bbox.height/2.0 - colorbar.rows/2.0;
        cv::Mat dst;
        cv::warpAffine(colorbar, dst, rot, bbox.size());

        QImage color=cvMat_to_QImage(dst);
        ui->label_show_B1->setPixmap(QPixmap::fromImage(color).scaled(ui->label_show_B1->width(),ui->label_show_B1->height()));
}

void MainWindow::on_pb_applykmeans_clicked()
{
    int K=ui->horizontalSlider_Kmean->value();
    cv::Mat k_mat = origin_image->clone();
    k_mat = kmeans(k_mat, K);
    QImage show=cvMat_to_QImage(k_mat);
    ui->label_show_A1->setPixmap(QPixmap::fromImage(show).scaled(ui->label_show_A1->width(),ui->label_show_A1->height(),Qt::KeepAspectRatio));
    ui->label_A->setText("KMEAN");
}
