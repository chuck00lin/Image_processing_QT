#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "qfiledialog.h"
#include "QDebug"
#include <QByteArray>
#include <QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>

QT_CHARTS_USE_NAMESPACE

#include <opencv2/imgproc.hpp>
QImage cvMat_to_QImage(const cv::Mat &mat );

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   //tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
    ui->setupUi(this);
    QString imagePath = QFileDialog::getOpenFileName( this, tr("Open File"),"",tr("Image Files (*.png *.jpg *.bmp)"));
    if(imagePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));

        //disable push_button to avoid crash
        ui->pb_show_origin->setEnabled(false);
        ui->pb_equalization->setEnabled(false);
        ui->pb_diff_AB->setEnabled(false);
        ui->pb_grayscaleAB->setEnabled(false);
        ui->pb_binary->setEnabled(false);

    }
    else {

        origin_image=new cv::Mat();//allocate memory to pointer "origin_image"
        *origin_image=cv::imread(imagePath.toStdString());

        Q_origin_image = new QImage();
        *Q_origin_image=cvMat_to_QImage(*origin_image);
        QPixmap image_pixmap=QPixmap::fromImage(*Q_origin_image);
        ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));

        //for difference
        ui->pb_diff_AB->setEnabled(false);
        ui->pb_binary->setEnabled(false);
            G_B=new cv::Mat();//
            G_A=new cv::Mat();//
    }
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

void MainWindow::on_pb_show_origin_clicked()
{
    QPixmap image_pixmap=QPixmap::fromImage(*Q_origin_image);
    ui->lb_oringimg->resize(ui->scrollAreaWidgetContents_3->width(),ui->scrollAreaWidgetContents_3->height());
    ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_pb_equalization_clicked()
{
    //
    cv::Mat HE;
    origin_image->copyTo(HE);
       int srcR[256];
       int srcG[256];
       int srcB[256];
       int scR[256];
       int scG[256];
       int scB[256];
       float R_p[256];
       float G_p[256];
       float B_p[256];
       for(int i = 0 ; i < 256 ; i++){
           srcR[i] = 0;
           srcG[i] = 0;
           srcB[i] = 0;
       }
       for(int i = 0 ; i < HE.rows ; i++){
           for(int j = 0 ; j < HE.cols ; j++){
               srcB[HE.at<cv::Vec3b>(i,j)[0]]++;
               srcG[HE.at<cv::Vec3b>(i,j)[1]]++;
               srcR[HE.at<cv::Vec3b>(i,j)[2]]++;
           }
       }
       for(int i = 0 ; i < 256 ; i++){
           B_p[i] = float(srcB[i]) / (HE.rows * HE.cols);
           G_p[i] = float(srcG[i]) / (HE.rows * HE.cols);
           R_p[i] = float(srcR[i]) / (HE.rows * HE.cols);
           //qDebug() << B_p[i];
       }
       float sumB = 0.0;
       float sumG = 0.0;
       float sumR = 0.0;
       for(int i = 0 ; i < 256 ; i++){
           sumB += B_p[i];
           B_p[i] = float(255*sumB);
           scB[i] = round(B_p[i]);

           sumG += G_p[i];
           G_p[i] = float(255*sumG);
           scG[i] = round(G_p[i]);

           sumR += R_p[i];
           R_p[i] = float(255*sumR);
           scR[i] = round(R_p[i]);
       }

       for(int i = 0 ; i < HE.rows ; i++){
           for(int j = 0 ; j < HE.cols ; j++){
               HE.at<cv::Vec3b>(i, j)[0] = scB[HE.at<cv::Vec3b>(i, j)[0]];
               HE.at<cv::Vec3b>(i, j)[1] = scG[HE.at<cv::Vec3b>(i, j)[1]];
               HE.at<cv::Vec3b>(i, j)[2] = scR[HE.at<cv::Vec3b>(i, j)[2]];
           }
       }

       QPixmap image_pixmap=QPixmap::fromImage(cvMat_to_QImage(HE));
       ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));
    //image_show.setPixel(j, i, qRgb(image_int_value[i][j]*8,image_int_value[i][j]*8,image_int_value[i][j]*8));
}


void MainWindow::on_pb_grayscaleAB_clicked()
{
    cv::Mat ref;
    origin_image->copyTo(ref);
    cv::Mat grayA;
        grayA.create(ref.rows, ref.cols, CV_8U);
        for(int i = 0 ; i < ref.rows ; i++){
            for(int j = 0 ; j < ref.cols ; j++){
                grayA.at<uchar>(i,j) = (ref.at<cv::Vec3b>(i, j)[0] + ref.at<cv::Vec3b>(i, j)[1] + ref.at<cv::Vec3b>(i, j)[2])/3.0;
            }
        }
    cv::Mat grayB;
        grayB.create(ref.rows, ref.cols, CV_8U);
        for(int i = 0 ; i < ref.rows ; i++){
            for(int j = 0 ; j < ref.cols ; j++){
                grayB.at<uchar>(i,j) = 0.114*ref.at<cv::Vec3b>(i, j)[0] + 0.587*ref.at<cv::Vec3b>(i, j)[1] + 0.299*ref.at<cv::Vec3b>(i, j)[2];
            }
        }

    QPixmap image_pixmap_A=QPixmap::fromImage(cvMat_to_QImage(grayA));
    ui->lb_img_a->setPixmap(image_pixmap_A.scaled(ui->lb_img_a->width(),ui->lb_img_a->height(),Qt::KeepAspectRatio));
    drawchart(grayA);

    QPixmap image_pixmap_B=QPixmap::fromImage(cvMat_to_QImage(grayB));
    ui->lb_img_b->setPixmap(image_pixmap_B.scaled(ui->lb_img_b->width(),ui->lb_img_b->height(),Qt::KeepAspectRatio));
    drawchart2(grayB);

    //for diff
    *G_A=grayA;
    *G_B=grayB;
    ui->pb_diff_AB->setEnabled(true);
    ui->pb_binary->setEnabled(true);
}
void MainWindow::drawchart(cv::Mat input)
{
    ui->horizontalLayoutWidget->layout()->takeAt(0);
    qDebug("aaa");
    int chart_value[256]={0};
    //cows 行 rows 列
    for(int i=0;i<input.rows;i++){
        for(int j=0;j<input.cols;j++){
               chart_value[input.at<uchar>(i, j)]++;
        }
    }
    qDebug("BBB");
    //chart
    QBarSet *set0=new QBarSet("Histogram");
    for(int i=0;i<256;i++){
        *set0<<chart_value[i];
    }
    //change color
    set0->setColor(Qt::blue);

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("grayscale distribution");
    //Noanimation
    chart->setAnimationOptions(QChart::AllAnimations);

    //坐標軸
//    QStringList categories;//0 to 32 level
//    for(int i=0;i<32;i++){
//        QString cat=QString::number(i);
//        categories<<cat;
//    }

   QBarCategoryAxis *axis = new QBarCategoryAxis();
//    axis->append(categories);

    //change font
    QFont serifFont("Times", 4, QFont::Thin);
    axis->setLabelsFont(serifFont);
    QFont SansSerifFont("SansSerif", 12, QFont::Bold);//change font
    chart->setTitleFont(SansSerifFont);

    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);//繼承來的抗鋸齒方法
    //chartView->show(); //show isolate
    ui->histo_1->addWidget(chartView);

}

void MainWindow::drawchart2(cv::Mat input)
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);
    qDebug("aaa");
    int chart_value[256]={0};
    //cows 行 rows 列
    for(int i=0;i<input.rows;i++){
        for(int j=0;j<input.cols;j++){
               chart_value[input.at<uchar>(i, j)]++;
        }
    }
    qDebug("BBB");
    //chart
    QBarSet *set0=new QBarSet("Histogram");
    for(int i=0;i<256;i++){
        *set0<<chart_value[i];
    }
    //change color
    set0->setColor(Qt::red);

    QBarSeries *series = new QBarSeries();
    series->append(set0);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("grayscale distribution");
    //Noanimation
    chart->setAnimationOptions(QChart::AllAnimations);

    //坐標軸
//    QStringList categories;//0 to 32 level
//    for(int i=0;i<32;i++){
//        QString cat=QString::number(i);
//        categories<<cat;
//    }

   QBarCategoryAxis *axis = new QBarCategoryAxis();
//    axis->append(categories);

    //change font
    QFont serifFont("Times", 4, QFont::Thin);
    axis->setLabelsFont(serifFont);
    QFont SansSerifFont("SansSerif", 12, QFont::Bold);//change font
    chart->setTitleFont(SansSerifFont);

    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);//繼承來的抗鋸齒方法
    //chartView->show(); //show isolate
    ui->histo_2->addWidget(chartView);

}

void MainWindow::on_pb_diff_AB_clicked()
{

    cv::Mat diffA_B;
    diffA_B.create(G_A->rows,G_A->cols, CV_8U);
        for(int i = 0 ; i < diffA_B.rows ; i++){
            for(int j = 0 ; j < diffA_B.cols ; j++){
                int diff = G_A->at<uchar>(i, j) - G_B->at<uchar>(i, j);
                if(diff < 0) diff = 0;
                diffA_B.at<uchar>(i,j) = diff;
            }
        }
    QPixmap image_pixmap_B=QPixmap::fromImage(cvMat_to_QImage(diffA_B));
    ui->lb_oringimg->setPixmap(image_pixmap_B.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));

}

void MainWindow::on_pb_binary_clicked()
{
    QString input_text;
    input_text=ui->lineEdit->text();
    if(input_text.isEmpty()){
        QMessageBox::information(0, "a little remind :) ","PLEASE ENTER NUMBER");
    }
    else{
        int threshhold= input_text.toInt();
        cv::Mat threshold_A;
        G_A->copyTo(threshold_A);
        cv::Mat threshold_B;
        G_B->copyTo(threshold_B);
        for(int i = 0 ; i < G_A->rows ; i++){
                for(int j = 0 ; j < G_A->cols ; j++){
                    if(threshold_A.at<uchar>(i, j) >= threshhold)    threshold_A.at<uchar>(i, j) = 255;
                    else    threshold_A.at<uchar>(i, j) = 0;
                    if(threshold_B.at<uchar>(i, j) >= threshhold)    threshold_B.at<uchar>(i, j) = 255;
                    else    threshold_B.at<uchar>(i, j) = 0;
                }
            }
        QPixmap image_pixmap_A=QPixmap::fromImage(cvMat_to_QImage(threshold_A));
        ui->lb_img_a->setPixmap(image_pixmap_A.scaled(ui->lb_img_a->width(),ui->lb_img_a->height(),Qt::KeepAspectRatio));
        drawchart(threshold_A);

        QPixmap image_pixmap_B=QPixmap::fromImage(cvMat_to_QImage(threshold_B));
        ui->lb_img_b->setPixmap(image_pixmap_B.scaled(ui->lb_img_b->width(),ui->lb_img_b->height(),Qt::KeepAspectRatio));
        drawchart2(threshold_B);

    }

}



void MainWindow::on_slider_brightness_sliderMoved(int  position)
{

    cv::Mat BC_src;
    origin_image->copyTo(BC_src);
    int br=ui->slider_brightness->value()/10;
        for(int i = 0 ; i < origin_image->rows ; i++){
            for(int j = 0 ; j < origin_image->cols ; j++){
                int AA0 =  br*(origin_image->at<cv::Vec3b>(i, j))[0] + ui->slider_contrast->value();
                int AA1 =  br*(origin_image->at<cv::Vec3b>(i, j))[1] + ui->slider_contrast->value();
                int AA2 =  br*(origin_image->at<cv::Vec3b>(i, j))[2] + ui->slider_contrast->value();

                if(AA0 > 255)    BC_src.at<cv::Vec3b>(i, j)[0] = 255;
                else if(AA0 < 0)    BC_src.at<cv::Vec3b>(i, j)[0] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[0] = AA0;

                if(AA1 > 255)    BC_src.at<cv::Vec3b>(i, j)[1] = 255;
                else if(AA1 < 0)    BC_src.at<cv::Vec3b>(i, j)[1] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[1] = AA1;

                if(AA2 > 255)    BC_src.at<cv::Vec3b>(i, j)[2] = 255;
                else if(AA2 < 0)    BC_src.at<cv::Vec3b>(i, j)[2] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[2] = AA2;
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(cvMat_to_QImage(BC_src));
        ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_slider_contrast_sliderMoved(int position)
{
    cv::Mat BC_src;
    origin_image->copyTo(BC_src);
    int cont=ui->slider_contrast->value()-50;
        for(int i = 0 ; i < origin_image->rows ; i++){
            for(int j = 0 ; j < origin_image->cols ; j++){
                int AA0 = (origin_image->at<cv::Vec3b>(i, j))[0] + cont;
                int AA1 = (origin_image->at<cv::Vec3b>(i, j))[1] + cont;
                int AA2 = (origin_image->at<cv::Vec3b>(i, j))[2] + cont;

                if(AA0 > 255)    BC_src.at<cv::Vec3b>(i, j)[0] = 255;
                else if(AA0 < 0)    BC_src.at<cv::Vec3b>(i, j)[0] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[0] = AA0;

                if(AA1 > 255)    BC_src.at<cv::Vec3b>(i, j)[1] = 255;
                else if(AA1 < 0)    BC_src.at<cv::Vec3b>(i, j)[1] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[1] = AA1;

                if(AA2 > 255)    BC_src.at<cv::Vec3b>(i, j)[2] = 255;
                else if(AA2 < 0)    BC_src.at<cv::Vec3b>(i, j)[2] = 0;
                else BC_src.at<cv::Vec3b>(i, j)[2] = AA2;
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(cvMat_to_QImage(BC_src));
        ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    cv::Mat resize;
    origin_image->copyTo(resize);
    resize.create(origin_image->rows*arg1,origin_image->cols*arg1, CV_8UC3);

        for(int i = 0 ; i < resize.rows ; i++){
            for(int j = 0 ; j < resize.cols ; j++){
                resize.at<cv::Vec3b>(i, j)[0] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[0];
                resize.at<cv::Vec3b>(i, j)[1] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[1];
                resize.at<cv::Vec3b>(i, j)[2] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[2];
            }
        }

        cv::imshow("Resize and modify grayscale level", resize);

}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)// shrink
{
    cv::Mat resize;
    origin_image->copyTo(resize);
    resize.create(origin_image->rows*arg1,origin_image->cols*arg1, CV_8UC3);

        for(int i = 0 ; i < resize.rows ; i++){
            for(int j = 0 ; j < resize.cols ; j++){
                resize.at<cv::Vec3b>(i, j)[0] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[0];
                resize.at<cv::Vec3b>(i, j)[1] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[1];
                resize.at<cv::Vec3b>(i, j)[2] = origin_image->at<cv::Vec3b>(i/arg1, j/arg1)[2];
            }
        }

        cv::imshow("Resize and modify grayscale level", resize);
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1) //grayscale
{
    int level=arg1;
    cv::Mat output;
    origin_image->copyTo(output);
       for(int i = 0 ; i <  origin_image->rows ; i++){
           for(int j = 0 ; j < origin_image->cols ; j++){
               output.at<cv::Vec3b>(i, j)[0] = origin_image->at<cv::Vec3b>(i, j)[0] / (256/level);
               output.at<cv::Vec3b>(i, j)[0] = output.at<cv::Vec3b>(i, j)[0] * (256/level);
               output.at<cv::Vec3b>(i, j)[1] = origin_image->at<cv::Vec3b>(i, j)[1] / (256/level);
               output.at<cv::Vec3b>(i, j)[1] = output.at<cv::Vec3b>(i, j)[1] * (256/level);
               output.at<cv::Vec3b>(i, j)[2] = origin_image->at<cv::Vec3b>(i, j)[2] / (256/level);
               output.at<cv::Vec3b>(i, j)[2] = output.at<cv::Vec3b>(i, j)[2] * (256/level);
           }
       }
       QPixmap image_pixmap=QPixmap::fromImage(cvMat_to_QImage( output));
       ui->lb_oringimg->setPixmap(image_pixmap.scaled(ui->lb_oringimg->width(),ui->lb_oringimg->height(),Qt::KeepAspectRatio));
}
