#ifndef POPUPHANDLER_H
#define POPUPHANDLER_H


#include <QObject>

class QMainWindow;
class QTimer;

class PopupHandler : public QObject
{
    Q_OBJECT

public:
    PopupHandler( const QList<QMainWindow*> &windowList );

    void BeginTimers();

private:
    void init();
    QList<QMainWindow*> windows;
    QTimer* breakTime;
    QTimer* countDownTime;

    double secondsRemaining;

private slots:
    void ShowAllWindows();
    void HideAllWindows();

    void UpdateTimerLabel();
};

#endif // POPUPHANDLER_H
