#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Model/musiclist.h"
#include "Notification/notification.h"

class Command;
class ViewModel
{
private:
    std::shared_ptr<MusicList> musiclist;

    //QMediaPlaylist* playlist;
    std::shared_ptr<Notification> update_view_notification;
    std::shared_ptr<Command> addMusic_command;
public:
    ViewModel();
    void exec_addMusic_command(QUrl &urli);
    void bind(std::shared_ptr<MusicList>);



    std::shared_ptr<Command> get_addMusic_command();
    //QMediaPlaylist* get_playlist();
    void set_update_view_notification(std::shared_ptr<Notification>);
};


#endif // VIEWMODEL_H
