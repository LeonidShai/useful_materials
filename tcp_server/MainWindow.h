#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include <TcpServer.h>
#include <TaskExecutor.h>

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
    void connectionChanged();
    void showMessage(QByteArray buffer);

    void on_pushButton_run_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_quit_clicked();

    void on_pushButton_send_clicked();
    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow* _ui;
    TcpServer*      _tcpServer;
    TcpConfig       _tcpConfig;
    TaskExecutor*   _taskExecutor;
    QThread*        _thread;
};

#endif // MAINWINDOW_H
