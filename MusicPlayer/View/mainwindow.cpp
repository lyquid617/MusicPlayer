#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Notification/notification.h"

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
    QString runPath = QCoreApplication::applicationDirPath();//获取当前exe所在路径

    playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);



//    for(int i=0;i<fileList.size();i++)   //输出所有音频文件到界面
//        {


//            QString fileName = fileList.at(i);
//            qDebug() <<fileName<<endl;
//            addItem(fileName);

//            playlist->addMedia(QUrl("qrc"+MusicPath+"/"+fileName));

//        }
    playlist->setCurrentIndex(0);

    player->setPlaylist(playlist);
    player->setVolume(80);
    //connections
    //connect(ui->Pause,&QPushButton::clicked,this,&MainWindow::on_Pause_clicked);
    connect(ui->skipforward,&QPushButton::clicked,this,&MainWindow::on_skipforward_clicked);
    connect(ui->skipbackward,&QPushButton::clicked,this,&MainWindow::on_skipbackward_clicked);
    connect(ui->positionSlider, &QAbstractSlider::valueChanged, this, &MainWindow::setPosition);
    connect(ui->addMusic, &QPushButton::clicked,this,&MainWindow::on_addMusic_clicked);
    connect(player, &QMediaPlayer::metaDataAvailableChanged, this, &MainWindow::updateInfo);
}


void MainWindow::on_skipforward_clicked()
{
    playlist->next();
    playlist->nextIndex();
}
void MainWindow::on_skipbackward_clicked()
{
    playlist->previous();
    playlist->previousIndex();
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

QStringList MainWindow::getFileNames(const QString &path)
{

    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.mp3";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}
void MainWindow::addItem(QString name)
{
    int count = ui->musiclist->rowCount();
    ui->musiclist->setRowCount(count+1);

    QTableWidgetItem *itemName = new QTableWidgetItem(name);

    ui->musiclist->setItem(count, 0 , itemName);

}

void MainWindow::on_playlist_clicked()
{
    //show a child table or window displaying the music list
}

void MainWindow::on_addMusic_clicked()
{
    //add music to music list
    //add music commmand
    addmusiccommand->exec();
}
void MainWindow::set_addMusic_command(std::shared_ptr<Command> cmd){
    addmusiccommand = cmd;
}

std::shared_ptr<Notification> MainWindow::get_update_notification(){
    return update_view_notification;
}

void MainWindow::update(){

}
