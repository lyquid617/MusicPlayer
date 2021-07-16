#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "View/updateviewnotification.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_player();
    update_view_notification = std::static_pointer_cast<Notification, UpdateViewNotification>(std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<MainWindow>(this))));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_player(){

    //init the player
    player = new QMediaPlayer();

    playlist = new QMediaPlaylist();

    player->setPlaylist(playlist);

    player->setVolume(80);
    //connections
    //connect(ui->Pause,&QPushButton::clicked,this,&MainWindow::on_Pause_clicked);

}



void MainWindow::set_addMusic_command(std::shared_ptr<Command> cmd){
    addmusiccommand = cmd;
}

std::shared_ptr<Notification> MainWindow::get_update_notification(){
    return update_view_notification;
}

void MainWindow::update(QStringList lst){

    for(int i = 0;i<lst.size();i++){
        //qDebug() << musiclist[i].get_title()<<endl;
        ui->musictable->setRowCount(i+1);
        QTableWidgetItem *itemName = new QTableWidgetItem(lst[i]);
        ui->musictable->setItem(i, 0, itemName);
    }
}


void MainWindow::on_skipforward_clicked()
{
    playlist->next();
    playlist->nextIndex();
    updateInfo();
}
void MainWindow::on_skipbackward_clicked()
{
    playlist->previous();
    playlist->previousIndex();
    updateInfo();
}
void MainWindow::on_Pause_clicked()
{
    if(!isplay)
            {
                isplay = true;
                ui->Pause->setStyleSheet(PlayStyle());
                player->play();
            }
        else
            {
                isplay = false;
                ui->Pause->setStyleSheet(PauseStyle());
                player->pause();
            }
    updateInfo();
}

void MainWindow::setPosition(int position)
{
    // avoid seeking when the slider value change is triggered from updatePosition()
    if (qAbs(player->position() - position) > 99)
        player->setPosition(position);
}

void MainWindow::updateInfo(){
    QString info="";
    QString author = player->metaData(QStringLiteral("Author")).toStringList().join(",");
    info.append(author);
    QString title = player->metaData(QStringLiteral("Title")).toString();
    QString albumTitle = player->metaData(QStringLiteral("AlbumTitle")).toString();
    info.append(" - "+title);
    //info.append(" ["+formatTime(player->duration())+"]");
    ui->label->setText(info);
}


void MainWindow::on_playlist_clicked()
{
    //show a child table or window displaying the music list
}

void MainWindow::on_addMusic_clicked()
{
    QFileDialog fileDialog;
    qDebug() <<"1"<<endl;
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setWindowTitle("add local music");
    QStringList list;list<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(list);

    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));

    if (fileDialog.exec() == QDialog::Accepted){
       QList<QUrl> urls=fileDialog.selectedUrls();
       QStringList mscnames = fileDialog.selectedFiles();


       for(int i = 0;i<urls.size();i++){
           //addMusic(urls[i]);
           qDebug() << urls[i]<<endl;
           playlist->addMedia(QUrl(urls[i]));
           addmusiccommand->exec(urls[i]);
       }
    }


}






