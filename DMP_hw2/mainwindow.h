#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void drawchart(cv::Mat);
    void drawchart2(cv::Mat);
    void on_pb_show_origin_clicked();

    void on_pb_equalization_clicked();

    void on_pb_grayscaleAB_clicked();

    void on_pb_diff_AB_clicked();

    void on_pb_binary_clicked();

    void on_slider_brightness_sliderMoved(int position);

    void on_slider_contrast_sliderMoved(int position);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);


    void on_doubleSpinBox_3_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    cv::Mat* origin_image; //for manipulate
    QImage *Q_origin_image; //for display

    cv::Mat* G_A;
    cv::Mat* G_B;
};
#endif // MAINWINDOW_H
