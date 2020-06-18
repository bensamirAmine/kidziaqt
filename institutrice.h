#ifndef INSTITUTRICE_H
#define INSTITUTRICE_H


#include <QDialog>
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>


class Institutrice
{
public:
    Institutrice();
    Institutrice(QString,QString,QString,QString,QString,int,QString);

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

    bool ajouterInstitutrice();
    bool modifierInstitutrice();
    bool supprimerInstitutrice(QString id);
    QSqlQueryModel * afficherInstitutrices();
    QSqlQuery rechercher(QString id);
    QSqlQueryModel * chercherInstitutrice(QString);

    QSqlQuery loginInstitutrice(QString cin,QString pwd);
    QSqlQueryModel * triNomAsc();
    QSqlQueryModel * triNomDsc();

private:
    QString nom,prenom,mail,dateD,cin,password;
    int Tel;
};

#endif // INSTITUTRICE_H
