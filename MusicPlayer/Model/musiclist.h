#ifndef MUSICLIST_H
#define MUSICLIST_H
#include "music.h"
#include "QVector"
#include <QMediaPlaylist>

#include "Notification/notification.h"


using namespace std;
class MusicList
{
private:
    QVector<Music> musics;
    std::shared_ptr<Notification> update_view_notification;
    QVector<Music>* ptr2lst;
    //QMediaPlaylist* Playlist;
public:
    MusicList();
    //add
    void addMusic(QUrl &url);
    void addMusic();
    void addToPlayList();
    //get
    QVector<Music>* getList();


    void clear();
    void set_update_view_notification(shared_ptr<Notification> noti);
    void notify();
};



#endif // MUSICLIST_H
