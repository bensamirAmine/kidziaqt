#ifndef NOTIF_H
#define NOTIF_H

#include <QString>
class Notif
{
private:
    int num;
public:
    Notif();
    void notification_ajout(int,QString,QString,QString,QString);
    void notification_df(QString name);
};

#endif // NOTIF_H
