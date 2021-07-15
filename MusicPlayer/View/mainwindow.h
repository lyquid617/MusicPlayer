#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>
#include "myqss.h"
#include <QDir>
#include "Commands/command.h"
class Notification;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init_player();
    void set_addMusic_command(std::shared_ptr<Command> cmd);
    std::shared_ptr<Notification> get_update_notification();
    void update();

private slots:

    void on_skipforward_clicked();

    void on_Pause_clicked();

    void on_skipbackward_clicked();


    void on_playlist_clicked();

    void on_addMusic_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    std::shared_ptr<Command> addmusiccommand;
    bool isplay = false;
    QString current_file;

    //for test use
    QString MusicPath = ":/music/music";

    QStringList fileList;  //文件名称

    QStringList getFileNames(const QString &path);	//获取路径下所有需要的文件类型文件
    void addItem(QString name);
    void updateInfo();
    void setPosition(int position);
    std::shared_ptr<Notification> update_view_notification;

};

class UpdateViewNotification : public Notification{
private:
    std::shared_ptr<MainWindow> window;
public:
    UpdateViewNotification(std::shared_ptr<MainWindow> m):window(m){}
    void exec(){
        window->update();

    }

};

#endif // MAINWINDOW_H
