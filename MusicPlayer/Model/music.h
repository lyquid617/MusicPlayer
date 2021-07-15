#ifndef MUSIC_H
#define MUSIC_H
#include <QUrl>

class Music
{
public:
    Music(){}
    Music(QUrl &urli):url(urli){}
    QUrl getUrl(){
        return url;
    }

private:
    QUrl url;

};

#endif // MUSIC_H
