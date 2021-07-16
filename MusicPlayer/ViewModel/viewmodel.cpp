#include "viewmodel.h"
#include "Commands/addmusiccommand.h"
#include "Commands/command.h"

ViewModel::ViewModel()
{
    addMusic_command = std::static_pointer_cast<Command, AddMusicCommand>(std::shared_ptr<AddMusicCommand>(new AddMusicCommand(std::shared_ptr<ViewModel>(this))));
}

void ViewModel::bind(std::shared_ptr<MusicList> msc){
    musiclist = msc;

}

std::shared_ptr<Command> ViewModel::get_addMusic_command(){
    return addMusic_command;
}



//QVector<Music>* ViewModel::get(){
//    return musiclist->getList();
//}

//TODO::
void ViewModel::exec_addMusic_command(QUrl &urli){
    musiclist->addMusic(urli);
}

void ViewModel::set_update_view_notification(std::shared_ptr<Notification>  notification){
    update_view_notification = notification;
}
