#ifndef LOGINDLG_H
#define LOGINDLG_H


#include <QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QLabel>
#include<QDebug>

//namespace Ui {
//class loginDlg;
//}

class loginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit loginDlg(QWidget *parent = 0);
    QPushButton * bt = Q_NULLPTR;
    QLineEdit *ed = Q_NULLPTR;
    QLabel* label = Q_NULLPTR;

    //virtual void closeEvent(QCloseEvent *event);
    ~loginDlg();

private slots:
    void on_loginbtn_clicked();

};

#endif // LOGINDLG_H
