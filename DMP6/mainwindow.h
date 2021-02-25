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

    void on_pb_trapezoidal_clicked();

    void on_pb_wavy_clicked();

    void on_pb_Circular_clicked();

    void on_pb_applykmeans_clicked();

    void on_pb_Wavelet_clicked();
    void process();
private:
    Ui::MainWindow *ui;
    cv::Mat *origin_image;
    QImage *Q_origin_image;
};
#endif // MAINWINDOW_H
