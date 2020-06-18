#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QSqlDatabase>
bool dateValidate(QString date){
   QString currentDate= QDate::currentDate().toString("dd/MM/yyyy");

   QDate date1 = QDate::fromString(date,"dd/MM/yyyy");
   QDate date2 = QDate::fromString(currentDate,"dd/MM/yyyy");
   qDebug() << "Decrypted 22/11/2011 to" << currentDate;
   qDebug() << "Decrypted 22/11/2011 to" << date;
    return date1 >= date2;
}

