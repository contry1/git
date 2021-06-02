#include <QGridLayout>
#include <QtWidgets>
#include "addressbar.h"
#include "viewweb.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>
#include <QWebEngineSettings>
#include<QRegion>
#define GEO_PHY_80    "http://192.168.2.201/login"
#define GEO_PHY_443   "https://192.168.2.201/login"


#include "logindlg.h"
#include "dragpushbutton.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :view(new QWebEngineView)
{


      view->window()->setWindowTitle("一视科技-体育测评系统");

      m_view = new SWebEngineView(this);

      QString path = QCoreApplication::applicationDirPath();
       qDebug()<<"=="<<path<<endl;
      QString file = path + "/config.ini";
      QSettings qs(file,QSettings::IniFormat);

      QString service = qs.value("net/url").toString();
      qDebug()<<"service== "<<service<<endl;
      QUrl url = QUrl(service);
      qDebug()<<"=="<<url<<endl;
      m_view->load(url);

      m_view->showFullScreen();

      QPushButton* m_exitBtn = new QPushButton(this);

      m_exitBtn->resize(30,30);
      m_exitBtn->move(1888,0);
      m_exitBtn->setText(tr("X"));


       QString str = "border-radius:30px";
       m_exitBtn->setStyleSheet(str);
       QString str1 = "color:red";
       m_exitBtn->setStyleSheet(str1);
       QString str2 = "background-color:yellow";
       m_exitBtn->setStyleSheet(str2);
       connect(m_exitBtn, SIGNAL(clicked()), this, SLOT(close()));//close override closeevent
}


void MainWindow::resizeEvent(QResizeEvent *)
{
    m_view->resize(this->size());
}


void MainWindow::show()
{
    this->showFullScreen();

}







void MainWindow::closeEvent(QCloseEvent *event)
{
   qDebug()<<"closeEvent "<<endl;
    //窗口关闭时询问是否退出
//   QMessageBox::StandardButton result=QMessageBox::question(this, "确认", "确定要退出本系统吗？",
//                      QMessageBox::QStringLiteral("确认")|QMessageBox::No |QMessageBox::Cancel,
//                      QMessageBox::No);
    int result=QMessageBox::question(this, tr("退出系统"),
                     QString(tr("确定要退出本系统吗")),tr("确认"),tr("取消"));


    if (result==0)//yes
    {
        // event->ignore();
        qDebug()<<"yes== "<<endl;
        loginDlg login;
        if(login.exec()==QDialog::Accepted)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }

    else
    {
        event->ignore();
    }

}


void MainWindow::update()
{


}

MainWindow::~MainWindow()
{
    if(view)
       delete view;
    if(m_view)
       delete m_view;
}
