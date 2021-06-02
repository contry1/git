#ifndef VIEWWEB_H
#define VIEWWEB_H

#include <QtWidgets>
#include <QWebEngineView>


//namespace view {

class viewweb : public QWebEngineView
{
    Q_OBJECT
public:
    viewweb();
    viewweb( QWebEngineView *par);
    void view_http_web(const QUrl &url);
   ~viewweb()=default;
   QWebEngineView * qev;
 signals:

  public  slots:
    void loadnextpage(const QUrl &url);

   private:

    QUrl * url;

};
//}


#endif // VIEW_H
