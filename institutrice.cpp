#include "institutrice.h"
#include <QDate>
#include <QMessageBox>
#include "connexion.h"
#include <QSystemTrayIcon>
#include <regex>
#include "simplecrypt.h"
//CONSTRUCTEUR
Institutrice::Institutrice()
{
    nom = "";
    prenom = "";
    Tel =0;
    mail="";
    dateD="";
    cin="";
}

Institutrice::Institutrice(QString nom,QString prenom,QString mail,QString dateD, QString cin,int Tel,QString password )
{

    this->nom = nom;
    this->prenom = prenom;
    this->Tel =Tel;
    this->mail=mail;
    this->dateD=dateD;
    this->cin=cin;
    this->password=password;
}


//GETTER
QString Institutrice::getNom(){
    return  nom;
}
QString Institutrice::getPrenom(){
    return  prenom;
}
int Institutrice::getTel(){
    return  Tel;
}
QString Institutrice::getMail(){
    return  mail;
}
QString Institutrice::getDateD(){
    return  dateD;
}
QString Institutrice::getCin(){
    return cin;
}

//SETTER
void Institutrice::setNom(QString nom){
    this->nom = nom;
}
void Institutrice::setPrenom(QString prenom){
    this->prenom = prenom;
}
void Institutrice::setTel(int Tel){
    this->Tel = Tel;
}
void Institutrice::setMail(QString mail){
    this->mail = mail;
}
void Institutrice::setDateD(QString dateD){
    this->dateD = dateD;
}
void Institutrice::setCin(QString cin){
    this->cin = cin;
}


//METHODES

bool Institutrice::ajouterInstitutrice(){
    QSqlQuery query;

    query.prepare("INSERT INTO institutrices (nom, prenom, tel, mail, datedebut, cin, password) "
                        "VALUES ( :nom, :prenom, :tel, :mail, :dated, :cin, :password)");


    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", Tel);
    query.bindValue(":mail", mail);
    query.bindValue(":dated", dateD);
    query.bindValue(":cin", cin);
    query.bindValue(":password", password);

    return    query.exec();

}

QSqlQueryModel * Institutrice::afficherInstitutrices()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from institutrices");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));


    return model;
}


QSqlQuery Institutrice::rechercher(QString cin)
{
    QSqlQuery query;

    query.prepare("SELECT * from institutrices where cin=:cin");
    query.bindValue(":cin", cin);
    query.exec();

    return query;
}
QSqlQuery Institutrice::loginInstitutrice(QString cin,QString pwd)
{

    QSqlQuery query;
    query.prepare("SELECT * from institutrices where cin=:cin AND password=:password");
    query.bindValue(":cin", cin);
    query.bindValue(":password", pwd);

    query.exec();

    return query;
}
bool Institutrice::modifierInstitutrice()
{
    QSqlQuery query;
    query.prepare("UPDATE institutrices set nom=:nom,prenom=:prenom,tel=:tel,mail=:mail,datedebut=:dateD, password=:password where (cin=:cin)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", Tel);
    query.bindValue(":mail", mail);
    query.bindValue(":dateD", dateD);
    query.bindValue(":cin", cin);
    query.bindValue(":password", password);

return query.exec();

}


bool Institutrice::supprimerInstitutrice(QString cin)
{
QSqlQuery query;
query.prepare("Delete from institutrices where cin=:cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * Institutrice::chercherInstitutrice(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from institutrices where upper(nom) like upper('%"+rech+"%') or upper(prenom) like upper('%"+rech+"%') or upper(cin) like upper('%"+rech+"%')  or upper(mail) like upper('%"+rech+"%')  or upper(datedebut) like upper('%"+rech+"%')  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


        return model;
}
QSqlQueryModel * Institutrice::triNomAsc()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from institutrices order by upper(nom) asc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


    return model;
}
QSqlQueryModel * Institutrice::triNomDsc()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from institutrices order by upper(nom) desc");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Début"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Password"));


    return model;
}
