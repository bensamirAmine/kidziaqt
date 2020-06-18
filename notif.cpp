#include "notif.h"
#include<QSystemTrayIcon>
#include<QString>
Notif::Notif()
{
num=0;
}

void Notif::notification_ajout(int id,QString titre,QString ams,QString succ,QString record ){
int number=id;
QSystemTrayIcon * notifyicon=new QSystemTrayIcon;
notifyicon->show();
notifyicon->setIcon(QIcon("C:/Users/mohamed ben samir/Documents/restaurant/photos/bg/not.png"));
QString  s=QString::number(number);
notifyicon->showMessage(titre,"le "+record+" avec l'ID "+s+" a ete "+ams+" avec "+succ,QSystemTrayIcon::Information,15000);
num++;

}

