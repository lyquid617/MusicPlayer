#include "musiclist.h"

MusicList::MusicList()
{

}
void MusicList::addMusic(QUrl &url){
    musics.push_back(Music(url));
}

void MusicList::addToPlayList(shared_ptr<QMediaPlaylist> playlist){

    for(int i = 0;i<musics.size();i++){
        playlist->addMedia(musics[i].getUrl());
    }

}
void MusicList::set_update_view_notification(shared_ptr<Notification> noti){
    update_view_notification = noti;
}

void MusicList::notify(){
    update_view_notification->exec();
}
