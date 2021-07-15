#include "app.h"

App::App():mainwindow(new MainWindow()),musiclist(new MusicList()),viewmodel(new ViewModel())
{
    viewmodel->bind(musiclist);
    mainwindow->set_addMusic_command(viewmodel->get_addMusic_command());
    viewmodel->set_update_view_notification(mainwindow->get_update_notification());
}
