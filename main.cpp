#include <QMainWindow>
#include <QApplication>

#include <QDesktopWidget>
#include <QList>
#include <QLabel>
#include <QDebug>

#include "popuphandler.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QMainWindow*> windowList;

    QPalette p;
    /** \note Some extraneous pointer referencing, but how many screen are there really? */
    for (int screenItr=0; screenItr < QApplication::desktop()->numScreens(); screenItr++ ){

        QMainWindow* winPtr = new QMainWindow();

        QLabel* labelPtr = new QLabel();
        labelPtr->setAutoFillBackground(true);
        winPtr->setCentralWidget( labelPtr );

        winPtr->setGeometry(QApplication::desktop()->availableGeometry( screenItr ));
        winPtr->setStyleSheet("QMainWindow {background: 'black';}");
        windowList.append( winPtr );

        qDebug() << Q_FUNC_INFO << ": added screen " << winPtr->size();
    }

    PopupHandler popper( windowList );
    popper.BeginTimers();

    return a.exec();
}
