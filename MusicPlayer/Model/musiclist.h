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
public:
    MusicList();
    void addMusic(QUrl &url);
    void addToPlayList(shared_ptr<QMediaPlaylist> playlist);

    void clear();
    void set_update_view_notification(shared_ptr<Notification> noti);
    void notify();
};



#endif // MUSICLIST_H
