/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *playcontrol;
    QPushButton *skipbackward;
    QSpacerItem *horizontalSpacer;
    QPushButton *Pause;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *skipforward;
    QPushButton *volume;
    QSlider *positionSlider;
    QPushButton *playmode;
    QLabel *label;
    QTableWidget *musictable;
    QPushButton *playlist;
    QPushButton *addMusic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"background-image: url(:/image/image/background.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(480, 690, 291, 61));
        playcontrol = new QHBoxLayout(horizontalLayoutWidget);
        playcontrol->setSpacing(0);
        playcontrol->setContentsMargins(11, 11, 11, 11);
        playcontrol->setObjectName(QStringLiteral("playcontrol"));
        playcontrol->setContentsMargins(0, 0, 0, 0);
        skipbackward = new QPushButton(horizontalLayoutWidget);
        skipbackward->setObjectName(QStringLiteral("skipbackward"));
        skipbackward->setEnabled(true);
        skipbackward->setCursor(QCursor(Qt::PointingHandCursor));
        skipbackward->setAutoFillBackground(false);
        skipbackward->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/skipbackward.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
""));

        playcontrol->addWidget(skipbackward);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        playcontrol->addItem(horizontalSpacer);

        Pause = new QPushButton(horizontalLayoutWidget);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setCursor(QCursor(Qt::PointingHandCursor));
        Pause->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/play.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/pause.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"}\n"
""));

        playcontrol->addWidget(Pause);

        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        playcontrol->addItem(horizontalSpacer_2);

        skipforward = new QPushButton(horizontalLayoutWidget);
        skipforward->setObjectName(QStringLiteral("skipforward"));
        skipforward->setEnabled(true);
        skipforward->setCursor(QCursor(Qt::PointingHandCursor));
        skipforward->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/skipforward.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
""));

        playcontrol->addWidget(skipforward);

        playcontrol->setStretch(0, 1);
        playcontrol->setStretch(1, 1);
        playcontrol->setStretch(2, 1);
        playcontrol->setStretch(3, 1);
        playcontrol->setStretch(4, 1);
        volume = new QPushButton(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(1120, 700, 32, 32));
        volume->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/volume.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"}\n"
""));
        positionSlider = new QSlider(centralWidget);
        positionSlider->setObjectName(QStringLiteral("positionSlider"));
        positionSlider->setGeometry(QRect(0, 610, 1200, 22));
        positionSlider->setOrientation(Qt::Horizontal);
        playmode = new QPushButton(centralWidget);
        playmode->setObjectName(QStringLiteral("playmode"));
        playmode->setGeometry(QRect(880, 700, 113, 32));
        playmode->setStyleSheet(QLatin1String("QPushButton{\n"
"background-image:url(:/image/image/repeat.png);\n"
"background-repeat:norepeat;\n"
"background-position:center;\n"
"border:none;\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 690, 401, 20));
        musictable = new QTableWidget(centralWidget);
        if (musictable->columnCount() < 1)
            musictable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        musictable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        musictable->setObjectName(QStringLiteral("musictable"));
        musictable->setGeometry(QRect(170, 230, 361, 291));
        musictable->verticalHeader()->setStretchLastSection(true);
        playlist = new QPushButton(centralWidget);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setGeometry(QRect(980, 700, 113, 32));
        playlist->setStyleSheet(QLatin1String("QPushButton{\n"
"background-image:url(:/image/image/playlist.png);\n"
"background-repeat:norepeat;\n"
"background-position:center;\n"
"border:none\n"
"\n"
"\n"
"}"));
        addMusic = new QPushButton(centralWidget);
        addMusic->setObjectName(QStringLiteral("addMusic"));
        addMusic->setGeometry(QRect(430, 180, 113, 32));
        addMusic->setStyleSheet(QLatin1String("QPushButton{\n"
"background-image:url(:/image/image/addmusic.png);\n"
"background-repeat:norepeat;\n"
"background-position:center;\n"
"border:none\n"
"\n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        skipbackward->setText(QString());
        Pause->setText(QString());
        skipforward->setText(QString());
        volume->setText(QString());
        playmode->setText(QString());
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = musictable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\346\255\214\346\233\262", Q_NULLPTR));
        playlist->setText(QString());
        addMusic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
