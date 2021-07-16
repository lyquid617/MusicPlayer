#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <any>

class Notification
{
public:
    Notification();
    virtual void add_parameter(void *) = 0;
    virtual void exec() = 0;
};



#endif // NOTIFICATION_H
