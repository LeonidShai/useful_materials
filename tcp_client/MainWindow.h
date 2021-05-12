#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <TcpClient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* _ui;
    TcpClient* _tcpClient;
    TcpConfig _tcpConfig;

    int        _countConnect;

private slots:
    void connectionState();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();
    void on_pushButton_quit_clicked();
};

#endif // MAINWINDOW_H
