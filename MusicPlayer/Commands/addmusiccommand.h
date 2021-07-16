#ifndef ADDMUSICCOMMAND_H
#define ADDMUSICCOMMAND_H

#include "command.h"

class AddMusicCommand:public Command
{
private:
    //QUrl url;
    std::shared_ptr<ViewModel> vm;

public:
    AddMusicCommand(std::shared_ptr<ViewModel> vm):vm(vm){}
    void exec(QUrl &urli);
};

#endif // ADDMUSICCOMMAND_H
