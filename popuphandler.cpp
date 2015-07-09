#include "popuphandler.h"
#include <QTimer>
#include <QList>
#include <QMainWindow>
#include <QObject>
#include <QDebug>
#define WAIT_MINUTES ( 20 )

PopupHandler::PopupHandler(QList<QMainWindow *> windowList) : QObject()
{
    windows = windowList;
    breakTime = new QTimer();

    QObject::connect( breakTime, SIGNAL(timeout()), this, SLOT(ShowAllWindows()) );
}

void PopupHandler::BeginTimers(){
    breakTime->start(  WAIT_MINUTES * 60 * 1000 );

    ShowAllWindows();
}

void PopupHandler::ShowAllWindows(){

    QTimer::singleShot(2000, this, SLOT(HideAllWindows()) );

    foreach( QMainWindow* winPtr, windows){
        winPtr->showFullScreen();
    }

}

void PopupHandler::HideAllWindows(){

    foreach( QMainWindow* winPtr, windows){
        winPtr->hide();
    }
}
