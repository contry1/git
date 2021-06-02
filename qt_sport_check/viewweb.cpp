#include "viewweb.h"
#include <QWebEngineView>
//using namespace view;



viewweb::viewweb(QWebEngineView *par)
{
    this->qev = par;
}

void viewweb::view_http_web(const QUrl &url)
{

   if(this->qev && url.isValid())
   {
       this->qev->setUrl(url);
      //this->qev->showNormal();
      this->qev->showMaximized();
     // qev->setMaximumHeight(100);

     //this->qev->showFullScreen();
     qDebug()<<"hello "<<url<<endl;

   }

}






void viewweb::loadnextpage(const QUrl &url)
{

      this->load(url);

}


