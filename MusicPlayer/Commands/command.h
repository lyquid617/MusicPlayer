#ifndef COMMAND_H
#define COMMAND_H

#include "ViewModel/viewmodel.h"
class ViewModel;

class Command
{
protected:
    //std::shared_ptr<Parameters> params;
    std::shared_ptr<ViewModel> vm;
public:
    Command(std::shared_ptr<ViewModel> vm):vm(vm){}
//    void set_parameters(std::shared_ptr<Parameters> parameters){
//        params = parameters;
//    }

//    Parameters& get_params_handle();
//    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
    virtual void exec() = 0;
};

#endif // COMMAND_H
