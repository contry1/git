#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <qkeysequenceedit.h>
#include <QPushButton>
#include "swebengineview.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();


   virtual void closeEvent(QCloseEvent *event);//关闭窗口事件，可以询问是否退出
   virtual void show();

protected:
    void resizeEvent(QResizeEvent *);
private slots:
  //  void onexitBtnClicked();
  signals:
//   virtual void clicked();
public  slots:
  void update();

private:
    QWebEngineView *view;
    SWebEngineView* m_view = Q_NULLPTR;
    QPushButton* m_exitBtn = Q_NULLPTR;
};

#endif // MAINWINDOW_H
