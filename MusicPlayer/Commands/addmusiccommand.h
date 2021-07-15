#ifndef ADDMUSICCOMMAND_H
#define ADDMUSICCOMMAND_H

#include "command.h"

class AddMusicCommand:public Command
{
private:
    QUrl url;
public:
    AddMusicCommand(std::shared_ptr<ViewModel> vm):Command(vm){}
    void exec(QUrl& url);
};

#endif // ADDMUSICCOMMAND_H
