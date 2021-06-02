#include "swebengineview.h"
#include <QDebug>

SWebEngineView::SWebEngineView(QWidget *parent) : QWebEngineView(parent)
{
}



QWebEngineView *SWebEngineView::createWindow(QWebEnginePage::WebWindowType type)
{
    Q_UNUSED(type);
    return this;
}
