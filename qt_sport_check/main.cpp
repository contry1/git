#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>
#include "viewweb.h"
#include <QDebug>

#include <QWebEnginePage>

#define cout qDebug()
int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
