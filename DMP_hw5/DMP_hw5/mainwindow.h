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
    void on_action_import_triggered();

    void on_pb_RGB_clicked();

    void on_pb_CMY_clicked();

    void on_pb_HSI_clicked();

    void on_pb_XYZ_clicked();

    void on_pb_Lab_clicked();

    void on_pb_YUV_clicked();

    void on_pb_Rainbow_clicked();

    void on_pb_Hot_clicked();

    void on_pb_Winter_clicked();

    void on_pb_Autumn_clicked();

    void on_pb_applykmeans_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat *origin_image;
    QImage *Q_origin_image;
};
#endif // MAINWINDOW_H
