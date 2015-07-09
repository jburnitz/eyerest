#include <QMainWindow>
#include <QApplication>

#include <QDesktopWidget>
#include <QList>
#include <QDebug>

#include "popuphandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QMainWindow*> windowList;

    QPalette p;
    /** \note Some extraneous pointer referencing, but how many screen are there really? */
    for (int screenItr=0; screenItr < QApplication::desktop()->numScreens(); screenItr++ ){

        QMainWindow* winPtr = new QMainWindow();

        winPtr->setGeometry(QApplication::desktop()->availableGeometry( screenItr ));
        winPtr->setStyleSheet("QMainWindow {background: 'black';}");
        windowList.append( winPtr );

        qDebug() << Q_FUNC_INFO << ": added screen " << winPtr->size();
    }

    PopupHandler pop( windowList );
    pop.BeginTimers();

    return a.exec();
}
