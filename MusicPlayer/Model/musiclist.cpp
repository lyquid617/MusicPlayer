#include "musiclist.h"

MusicList::MusicList()
{
    ptr2lst = &musics;
}


void MusicList::addMusic(QUrl &url){

    musics.push_back(Music(url));
    QString q = url.toString();
    QString *p = &q;
    update_view_notification->add_parameter(p);
    notify();
}

//void MusicList::addToPlayList(){

//    for(int i = 0;i<musics.size();i++){
//        Playlist->addMedia(musics[i].getUrl());
//    }

//}

QVector<Music>* MusicList::getList(){
    return ptr2lst;
}



void MusicList::set_update_view_notification(shared_ptr<Notification> noti){
    update_view_notification = noti;
}

void MusicList::notify(){
    update_view_notification->exec();
}
