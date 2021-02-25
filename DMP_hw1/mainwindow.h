#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void drawchart(int[]);
    void drawchart2(int[]);

    void on_pb_add_clicked();

    void on_pb_sub_clicked();

    void on_pb_avg_clicked();

    void on_pb_func_clicked();

    void on_pb_multi_clicked();

private:
    Ui::MainWindow *ui;
    int image_int_value[64][64];
};
#endif // MAINWINDOW_H
