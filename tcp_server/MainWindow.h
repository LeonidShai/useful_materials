#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <TcpServer.h>

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
    void on_pushButton_run_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_quit_clicked();

private:
    Ui::MainWindow* _ui;
    TcpServer*      _tcpServer;
    TcpConfig       _tcpConfig;
};

#endif // MAINWINDOW_H
