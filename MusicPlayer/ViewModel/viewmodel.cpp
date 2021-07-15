#include "viewmodel.h"
#include "Commands/addmusiccommand.h"
#include "Commands/command.h"

ViewModel::ViewModel()
{

}

void ViewModel::bind(std::shared_ptr<MusicList> msc){
    musiclist = msc;
}

std::shared_ptr<Command> ViewModel::get_addMusic_command(){
    return addMusic_command;
}


//TODO::
void ViewModel::exec_addMusic_command(QUrl &url){
    musiclist->addMusic(url);
}

void ViewModel::set_update_view_notification(std::shared_ptr<Notification>  notification){
    update_view_notification = notification;
}
