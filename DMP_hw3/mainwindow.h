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
    void on_pushButton_clicked();

    void on_pb_apply_clicked();

    void on_spinBox_valueChanged(int arg1);

    //function
    void meanfilter();
    void maxfilter();
    void minfilter();
    void mediamfilter();
    void gaussianfilter();
    //
    void LoG();
    void zero_crossing();
    void Sobel_x();
    void Sobel_y();
    void Sobel_xy();
    void on_cbox_edge_activated(int index);

private:
    int masksize;
    int **matrix;
    Ui::MainWindow *ui;
    cv::Mat* origin_image; //for manipulate
    QImage *Q_origin_image; //for display
};
#endif // MAINWINDOW_H
