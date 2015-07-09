#ifndef POPUPHANDLER_H
#define POPUPHANDLER_H

#include <QMainWindow>
#include <QObject>

class QTimer;

class PopupHandler : public QObject
{
    Q_OBJECT

public:
    PopupHandler( QList<QMainWindow*> windowList );
    void BeginTimers();

private:
    QList<QMainWindow*> windows;
    QTimer* breakTime;

private slots:
    void ShowAllWindows();
    void HideAllWindows();
};

#endif // POPUPHANDLER_H
