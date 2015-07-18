#include "popuphandler.h"
#include <QTimer>
#include <QList>
#include <QMainWindow>
#include <QLabel>
#include <QObject>
#include <QDebug>

#include "config.h"

PopupHandler::PopupHandler( const QList<QMainWindow *> &windowList) : QObject()
{   
    windows = QList<QMainWindow*>(windowList);
    init();
}

void PopupHandler::init(){

    breakTime = new QTimer();
    QObject::connect( breakTime, SIGNAL(timeout()), this, SLOT(ShowAllWindows()) );

    countDownTime = new QTimer();
    QObject::connect( countDownTime, SIGNAL(timeout()), this, SLOT( UpdateTimerLabel())  );

    foreach( QMainWindow* winPtr, windows){

        QPalette p = ((QLabel*)winPtr->centralWidget())->palette();
        p.setColor(QPalette::Background, QColor(Qt::black) );
        p.setColor(QPalette::WindowText, QColor(Qt::white) );
        ((QLabel*)winPtr->centralWidget())->setPalette(p);
        ((QLabel*)winPtr->centralWidget())->setAlignment(Qt::AlignCenter);
    }
}

void PopupHandler::BeginTimers(){
    breakTime->start(  WAIT_MINUTES * 60 * 1000 );

    ShowAllWindows();
}

/* Remember this is the context this program, not the pre-existing desktop */
void PopupHandler::ShowAllWindows(){

    QTimer::singleShot( 1000 * REST_SECONDS, this, SLOT(HideAllWindows()) );

    countDownTime->start( 1000 );
    secondsRemaining = REST_SECONDS;
	
	qDebug() << "rest";

    foreach( QMainWindow* winPtr, windows){
        winPtr->showFullScreen();
        ((QLabel*)winPtr->centralWidget())->setNum( secondsRemaining );
    }

}

void PopupHandler::HideAllWindows(){

    foreach( QMainWindow* winPtr, windows){
        winPtr->hide();
    }
    countDownTime->stop();
}

void PopupHandler::UpdateTimerLabel(){
    foreach( QMainWindow* winPtr, windows){
        ((QLabel*) winPtr->centralWidget() )->setNum( --secondsRemaining );
    }
    qDebug() << secondsRemaining;
}
