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

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    unsigned char image64[64][64];
    //int image_int_value[64][64];
    QString image64file = QFileDialog::getOpenFileName(this,tr("Open64File"),"D:/course/DMP/C1HW01-2019");
    QFile file(image64file);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error_reading", file.errorString());
    }
    //QDataStream in(&file);
    QString image_line;

    while(!file.atEnd()){
        image_line.append(file.readLine());
        image_line=image_line.simplified();
    }
    file.close();
    if(image_line.at(image_line.size()-1)=='\x1a')
        image_line.remove(image_line.size()-1,1);//remove \u001A

    qDebug()<<image_line.at(image_line.size()-1);
    //qDebug()<<image_line;

    string s_mage_line = image_line.toStdString();

    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
           image_int_value[i][j]=s_mage_line.at(i*64+j);
           if(image_int_value[i][j]>=65 && image_int_value[i][j]<91){
                image_int_value[i][j]=image_int_value[i][j]-55;
           }
           else{
                image_int_value[i][j]=image_int_value[i][j]-48;
           }
           //qDebug()<< image_int_value[i][j];
           //qDebug()<<"shit"<<i<<","<<j;
        }
    }

    int chart_value[32]={0};
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            for(int k=0;k<32;k++){
                if(image_int_value[i][j]==k)
                    chart_value[k]++;
            }
        }
    }
    MainWindow::drawchart(chart_value);
    //MainWindow::drawchart2(chart_value);

    //ui->layout()->addWidget(chart);
    for(int i=0;i<32;i++){
        qDebug()<<"this is"<<i<<":"<<chart_value[i];
    }
    //create image
    QImage image_show(64,64,QImage::Format_RGB32);
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
           image_show.setPixel(j, i, qRgb(image_int_value[i][j]*8,image_int_value[i][j]*8,image_int_value[i][j]*8));
           //image_show.setPixel(i, j, qRgb(255,255,255));
        }
    }
    QPixmap image_pixmap=QPixmap::fromImage(image_show);
    ui->label_showimage->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
    //ui->label->setPixmap(pixmap.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
qDebug("test");
int c=image64[0][0];
char b=image64[0][0];
qDebug()<< b;
qDebug()<<c;
char t='0';
int z=t;
qDebug()<< z;
//    QByteArray b64 = QByteArray::fromBase64("BFIJLMLJMSVTSROLKKJNVVVUVVVVVVVVVVUVUTVVUTRRLRTSRRRQRRRRQSTRQQQQ");
//    qDebug()<<image_line;
//    qDebug(">>>>\n");
//    qDebug()<<b64;
//    QByteArray c;
//    c= "\x04R\t,\xC2\xC9""1%SI\x13\x8B(\xA2MUUTUUUUUUUU\x15Q5UQ4Q-\x14\xD2""E\x14PE\x14QA$\xD1""A\x04\x10";
//    QByteArray c64 = c.toBase64();
//    qDebug(">>>>\n");
//    qDebug()<<c64;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawchart(int chart_value[])
{
    //chart
    QBarSet *set0=new QBarSet("amount of pixel");
    for(int i=0;i<32;i++){
        *set0<<chart_value[i];
    }
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("base32 distribution");
    //Noanimation
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;//0 to 32 level
    for(int i=0;i<32;i++){
        QString cat=QString::number(i);
        categories<<cat;
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

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
    ui->histo->addWidget(chartView);

}

void MainWindow::drawchart2(int chart_value[])
{
    //chart
    QBarSet *set0=new QBarSet("amount of pixel");
    for(int i=0;i<32;i++){
        *set0<<chart_value[i];
    }
    //change color
    set0->setColor(Qt::green);

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("base32 distribution");

    //Noanimation
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;//0 to 32 level
    for(int i=0;i<32;i++){
        QString cat=QString::number(i);
        categories<<cat;
    }
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

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

void MainWindow::on_pb_add_clicked()
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);//not so sure what am i doing  seems like clean the lay out,but still some small bug
    QString input_text;
    input_text=ui->lineEdit->text();
    if(input_text.isEmpty()){
        QMessageBox::information(0, "a little remind :) ","PLEASE ENTER NUMBER(dont too big");
    }
    else{
        int image_int_value_out[64][64];
        float add_num= input_text.toFloat();
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                if((image_int_value[i][j]+add_num)>255/8){
                    image_int_value_out[i][j]=255/8;
                }
                else if((image_int_value[i][j]+add_num)<0){
                    image_int_value_out[i][j]=0;
                }
                else{
                    image_int_value_out[i][j]=image_int_value[i][j]+add_num;
                }
            }
        }
        //create image
        QImage image_show(64,64,QImage::Format_RGB32);
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image_show.setPixel(j, i, qRgb(image_int_value_out[i][j]*8,image_int_value_out[i][j]*8,image_int_value_out[i][j]*8));
               //image_show.setPixel(i, j, qRgb(255,255,255));
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(image_show);
        ui->label_showsecond->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
        //draw chart
        int chart_value[32]={0};
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<32;k++){
                    if(image_int_value_out[i][j]>=k && image_int_value_out[i][j]<k+1)
                        chart_value[k]++;
                }
            }
        }
        MainWindow::drawchart2(chart_value);
    }

}

void MainWindow::on_pb_sub_clicked()
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);//not so sure what am i doing  seems like clean the lay out,but still some small bug
    QString input_text;
    input_text=ui->lineEdit->text();
    if(input_text.isEmpty()){
        QMessageBox::information(0, "a little remind :) ","PLEASE ENTER NUMBER(dont too big)");
    }
    else{
        int image_int_value_out[64][64];
        float sub_num= input_text.toFloat();
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                if((image_int_value[i][j]-sub_num)>255/8){
                    image_int_value_out[i][j]=255/8;
                }
                else if((image_int_value[i][j]-sub_num)<0){
                    image_int_value_out[i][j]=0;
                }
                else{
                    image_int_value_out[i][j]=image_int_value[i][j]-sub_num;
                }
            }
        }
        //create image
        QImage image_show(64,64,QImage::Format_RGB32);
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image_show.setPixel(j, i, qRgb(image_int_value_out[i][j]*8,image_int_value_out[i][j]*8,image_int_value_out[i][j]*8));
               //image_show.setPixel(i, j, qRgb(255,255,255));
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(image_show);
        ui->label_showsecond->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
        //draw chart
        int chart_value[32]={0};
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<32;k++){
                    if(image_int_value_out[i][j]>=k && image_int_value_out[i][j]<k+1)
                        chart_value[k]++;
                }
            }
        }
        MainWindow::drawchart2(chart_value);
    }
}

void MainWindow::on_pb_multi_clicked()
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);//not so sure what am i doing  seems like clean the lay out,but still some small bug
    QString input_text;
    input_text=ui->lineEdit->text();
    if(input_text.isEmpty()){
        QMessageBox::information(0, "a little remind :) ","PLEASE ENTER NUMBER(maybe<3?)");
    }
    else{
        int image_int_value_out[64][64];
        float mult_num= input_text.toFloat();
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                if((image_int_value[i][j]*mult_num)>255/8){
                    image_int_value_out[i][j]=255/8;
                }
                else if((image_int_value[i][j]*mult_num)<0){
                    image_int_value_out[i][j]=0;
                }
                else{
                    image_int_value_out[i][j]=image_int_value[i][j]*mult_num;
                }
            }
        }
        //create image
        QImage image_show(64,64,QImage::Format_RGB32);
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image_show.setPixel(j, i, qRgb(image_int_value_out[i][j]*8,image_int_value_out[i][j]*8,image_int_value_out[i][j]*8));
               //image_show.setPixel(i, j, qRgb(255,255,255));
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(image_show);
        ui->label_showsecond->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
        //draw chart
        int chart_value[32]={0};
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<32;k++){
                    if(image_int_value_out[i][j]>=k && image_int_value_out[i][j]<k+1)
                        chart_value[k]++;
                }
            }
        }
        MainWindow::drawchart2(chart_value);
    }
}

void MainWindow::on_pb_avg_clicked()
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);//not so sure what am i doing  seems like clean the lay out,but still some small bug
    int image2_int_value[64][64];
    QString image64file = QFileDialog::getOpenFileName(this,tr("Open64File"),"D:/course/DMP/C1HW01-2019");
    QFile file(image64file);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error_reading", file.errorString());
    }
    else{
        //QDataStream in(&file);
        QString image_line;

        while(!file.atEnd()){
            image_line.append(file.readLine());
            image_line=image_line.simplified();
        }
        file.close();
        if(image_line.at(image_line.size()-1)=='\x1a')
            image_line.remove(image_line.size()-1,1);//remove \u001A

        qDebug()<<image_line.at(image_line.size()-1);
        //qDebug()<<image_line;

        string s_mage_line = image_line.toStdString();

        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image2_int_value[i][j]=s_mage_line.at(i*64+j);
               if(image2_int_value[i][j]>=65 && image2_int_value[i][j]<91){
                    image2_int_value[i][j]=image2_int_value[i][j]-55;
               }
               else{
                    image2_int_value[i][j]=image2_int_value[i][j]-48;
               }
               //qDebug()<< image_int_value[i][j];
               //qDebug()<<"shit"<<i<<","<<j;
               image2_int_value[i][j]=(image2_int_value[i][j]+image_int_value[i][j])/2;
            }
        }
        //create image
        QImage image_show(64,64,QImage::Format_RGB32);
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image_show.setPixel(j, i, qRgb(image2_int_value[i][j]*8,image2_int_value[i][j]*8,image2_int_value[i][j]*8));
               //image_show.setPixel(i, j, qRgb(255,255,255));
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(image_show);
        ui->label_showsecond->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
        //draw chart
        int chart_value[32]={0};
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<32;k++){
                    if(image2_int_value[i][j]>=k && image2_int_value[i][j]<k+1)
                        chart_value[k]++;
                }
            }
        }
        MainWindow::drawchart2(chart_value);
    }

}

void MainWindow::on_pb_func_clicked()
{
    ui->horizontalLayoutWidget_2->layout()->takeAt(0);//not so sure what am i doing  seems like clean the lay out,but still some small bug

        int image_int_value_out[64][64];
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                    if(j==0){
                        image_int_value_out[i][j]=0;
                    }
                    else{
                        float gofx = image_int_value[i][j]-image_int_value[i][j-1];
                        if(gofx>255/8){
                            image_int_value_out[i][j]=255/8;
                        }
                        else if(gofx<0){
                            image_int_value_out[i][j]=0;
                        }
                        else{
                           image_int_value_out[i][j]=image_int_value[i][j]-image_int_value[i][j-1];
                        }
                    }
             }

        }
        //create image
        QImage image_show(64,64,QImage::Format_RGB32);
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
               image_show.setPixel(j, i, qRgb(image_int_value_out[i][j]*8,image_int_value_out[i][j]*8,image_int_value_out[i][j]*8));
               //image_show.setPixel(i, j, qRgb(255,255,255));
            }
        }
        QPixmap image_pixmap=QPixmap::fromImage(image_show);
        ui->label_showsecond->setPixmap(image_pixmap.scaled(ui->label_showimage->width(),ui->label_showimage->height(),Qt::KeepAspectRatio));
        //draw chart
        int chart_value[32]={0};
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<32;k++){
                    if(image_int_value_out[i][j]>=k && image_int_value_out[i][j]<k+1)
                        chart_value[k]++;
                }
            }
        }
        MainWindow::drawchart2(chart_value);
}


