#ifndef SWEBENGINEVIEW_H
#define SWEBENGINEVIEW_H


#include <QWidget>
#include <QWebEngineView>
#include <QMouseEvent>

class SWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    explicit SWebEngineView(QWidget *parent = 0);


protected:
    /**
     * @brief createWindow
     * @param type
     * @return
     */
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);
//private:
//    QList<QUrl> m_listUrl;
};

#endif // SWEBENGINEVIEW_H
