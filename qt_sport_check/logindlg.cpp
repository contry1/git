#include "logindlg.h"
#include<QMessageBox>
#include <QSettings>
#include <QCoreApplication>

#define PWD "123456"

loginDlg::loginDlg(QWidget *parent) : QDialog(parent)
{

    this->setWindowTitle("退出系统验证");

    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->resize(500,300);

    ed = new QLineEdit(this);
    ed->move(200,120);
    ed->setEchoMode(QLineEdit::Password);

    label = new QLabel("密码",this);
    label->move(140,120);

    bt = new QPushButton("验证",this);
    bt->move(200,160);

    connect(bt,SIGNAL(clicked()),this,SLOT(on_loginbtn_clicked()));
}

loginDlg::~loginDlg()
{
    if(bt)
      delete bt;
    if(ed)
      delete ed;
    if(label)
      delete label;
}

void loginDlg::on_loginbtn_clicked()
{
  //  QSettings qs("/home/yskj/qt_sport_check/config.ini",QSettings::IniFormat);


    QString path = QCoreApplication::applicationDirPath();
  //  qDebug()<<"=="<<path<<endl;
    QString file = path + "/config.ini";
    QSettings qs(file,QSettings::IniFormat);
    QString pwd = qs.value("net/passwd").toString();
    qDebug()<<"pwd=="<<pwd<<endl;
    if(this->ed->text()==QString(pwd))
    {
       //  qDebug()<<"on_loginbtn_clicked accept "<<endl;
         accept();
    }
    else
    {
         // qDebug()<<"on_loginbtn_clicked IGNORE "<<endl;
          QMessageBox::warning(this,"警告","密码错误!");
        //  reject();

    }
}



