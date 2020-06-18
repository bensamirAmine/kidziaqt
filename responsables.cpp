#include "responsables.h"
#include <QDate>
#include <QMessageBox>
#include "connexion.h"
#include <QSystemTrayIcon>
#include <regex>
#include <QDebug>
#include "simplecrypt.h"
//CONSTRUCTEUR
Responsables::Responsables()
{
    nom = "";
    prenom = "";
    Tel =0;
    mail="";
    dateD="";
    cin="";
    role="";
}

Responsables::Responsables(QString nom,QString prenom,QString mail,QString dateD, QString cin,QString role,int Tel,QString password )
{

    this->nom = nom;
    this->prenom = prenom;
    this->Tel =Tel;
    this->mail=mail;
    this->dateD=dateD;
    this->cin=cin;
    this->role=role;
    this->password=password;
}


//GETTER
QString Responsables::getNom(){
    return  nom;
}
QString Responsables::getPrenom(){
    return  prenom;
}
int Responsables::getTel(){
    return  Tel;
}
QString Responsables::getMail(){
    return  mail;
}
QString Responsables::getDateD(){
    return  dateD;
}
QString Responsables::getCin(){
    return cin;
}

//SETTER
void Responsables::setNom(QString nom){
    this->nom = nom;
}
void Responsables::setPrenom(QString prenom){
    this->prenom = prenom;
}
void Responsables::setTel(int Tel){
    this->Tel = Tel;
}
void Responsables::setMail(QString mail){
    this->mail = mail;
}
void Responsables::setDateD(QString dateD){
    this->dateD = dateD;
}
void Responsables::setCin(QString cin){
    this->cin = cin;
}


//METHODES

bool Responsables::ajouterResponsables(){
    QSqlQuery query;

    query.prepare("INSERT INTO responsables (nom, prenom, tel, mail, datedebut, cin, role,password) "
                        "VALUES ( :nom, :prenom, :tel, :mail, :dated, :cin, :role,:password)");


    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", Tel);
    query.bindValue(":mail", mail);
    query.bindValue(":dated", dateD);
    query.bindValue(":role", role);
    query.bindValue(":password", password);

    query.bindValue(":cin", cin);

    return    query.exec();

}

QSqlQueryModel * Responsables::afficherResponsables()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from responsables");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Role"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));


    return model;
}


QSqlQuery Responsables::rechercher(QString cin)
{
    QSqlQuery query;
    query.prepare("SELECT * from responsables where cin=:cin");
    query.bindValue(":cin", cin);
    query.exec();

    return query;
}
int Responsables::loginResponsable(QString cin,QString pwd)
{
    //Set The Encryption And Decryption Key
    SimpleCrypt processSimpleCrypt(89473829);

    QString FreeTrialStartsOn(pwd);

    //Encrypt
    QString passwordCrypted = processSimpleCrypt.encryptToString(FreeTrialStartsOn);

   QString pwdC= passwordCrypted;
    QSqlQuery query;
    query.prepare("SELECT * from responsables where cin=:cin AND password=:password");
    query.bindValue(":cin", cin);
    query.bindValue(":password", pwdC);

    query.exec();
    qDebug() << "size from function" << query.size();
    return query.size();
}
bool Responsables::modifierResponsables()
{
    QSqlQuery query;
    query.prepare("UPDATE responsables set nom=:nom,prenom=:prenom,tel=:tel,mail=:mail,datedebut=:dateD,role=:role,password=:password where (cin=:cin)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", Tel);
    query.bindValue(":mail", mail);
    query.bindValue(":dateD", dateD);
    query.bindValue(":role", role);
    query.bindValue(":cin", cin);
    query.bindValue(":password", password);

return query.exec();

}


bool Responsables::supprimerResponsables(QString cin)
{
QSqlQuery query;
query.prepare("Delete from responsables where cin=:cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * Responsables::chercherResponsable(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from responsables where upper(nom) like upper('%"+rech+"%') or upper(prenom) like upper('%"+rech+"%') or upper(cin) like upper('%"+rech+"%')  or upper(mail) like upper('%"+rech+"%')  or upper(datedebut) like upper('%"+rech+"%') or upper(datedebut) like upper('%"+rech+"%')  or upper(role) like upper('%"+rech+"%')   ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


        return model;
}
QSqlQueryModel * Responsables::triNomAsc()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from responsables order by upper(nom) asc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


    return model;
}
QSqlQueryModel * Responsables::triNomDsc()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from responsables order by upper(nom) desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


    return model;
}
