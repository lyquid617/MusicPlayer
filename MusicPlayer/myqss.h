#ifndef MYQSS_H
#define MYQSS_H
#include<QString>

/*此文件统一存放一些QSS样式代码*/

//播放按钮样式
inline QString PlayStyle()
{
    return "QPushButton"
   " {"
   "background-image:url(:/image/image/pause.png);"
 "   background-repeat:no-repeat;"
  "  background-position:center center;"
 "   border:none;"

"    }"

   " }"
   " QPushButton:pressed{"
    "background-repeat:no-repeat;"
   " background-position:center center;"
   " background-image:url(:/image/image/pause.png);"

     "}";
}
//暂停按钮样式
inline QString PauseStyle()
{
    return "QPushButton"
   " {"
   "background-image:url(:/image/image/play.png);"
 "   background-repeat:no-repeat;"
  "  background-position:center center;"
 "   border:none;"

"    }"

   " }"
   " QPushButton:pressed{"
    "background-repeat:no-repeat;"
   " background-position:center center;"
   " background-image:url(:/image/image/play.png);"

     "}";
}


#endif // MYQSS_H
