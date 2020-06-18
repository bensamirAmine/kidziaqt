#ifndef RESPONSABLES_H
#define RESPONSABLES_H
#include <QDialog>
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>

class Responsables
{
public:
    Responsables();
    Responsables(QString,QString,QString,QString,QString,QString,int,QString);

    QString getNom();
    QString getPrenom();
    QString getMail();
    QString getDateD();
    QString getCin();
    int getTel();

    void setNom(QString);
    void setPrenom(QString);
    void setMail(QString);
    void setDateD(QString);
    void setCin(QString);
    void setTel(int);

    bool ajouterResponsables();
    bool modifierResponsables();
    bool supprimerResponsables(QString id);
    QSqlQueryModel * afficherResponsables();
    QSqlQuery rechercher(QString id);
    QSqlQueryModel * chercherResponsable(QString);
    QSqlQueryModel * triNomAsc();
    QSqlQueryModel * triNomDsc();
    int loginResponsable(QString cin,QString pwd);

private:
    QString nom,prenom,mail,dateD,cin,role,password;
    int Tel;
};

#endif // RESPONSABLES_H
