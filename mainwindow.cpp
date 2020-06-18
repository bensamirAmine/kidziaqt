#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "institutrice.h"
#include "responsables.h"
#include <QRegularExpression>
#include <QMessageBox>
#include "QDebug"
#include <QVector>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPainter>
#include <QCryptographicHash>
#include <QTextCodec>
#include "simplecrypt.h"
#include "functions.h"
#include "notif.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditAddInsTel->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditAddInsCin->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditAddIRespCin_3->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditAddIRespTel_2->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditEditInsCin->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditEditInsTel->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditEditRespCin_2->setValidator( new QIntValidator(0, 100000000, this) );
    ui->lineEditEditRespTel_2->setValidator( new QIntValidator(0, 100000000, this) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddIns_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_btnEditIns_clicked()
{
    QString val=ui->tableIns->model()->data(ui->tableIns->model()->index(ui->tableIns->selectionModel()->currentIndex().row(),0)).toString();
    Institutrice i;


    QSqlQuery query=i.rechercher(val);
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);

     ui->lineEditEditInsCin->setText(val);

    QString nom,prenom,mail,Tel,dateD ;
    if (query.next())
    {
    nom= query.value(1).toString();
    ui->lineEditEditInsNom->setText(nom);
    prenom= query.value(2).toString();
    ui->lineEditEditInsPrenom->setText(prenom);
    mail= query.value(3).toString();
    ui->lineEditEditInsMail->setText(mail);
    Tel= query.value(4).toString();
    ui->lineEditEditInsTel->setText(Tel);
    dateD= query.value(5).toString();
    QDate DateD = QDate::fromString(dateD,"dd/MM/yyyy");
    ui->lineEditEditInsDd->setDate(DateD);
    QString password = query.value(6).toString();
    //Decrypt
               QString decrypt = processSimpleCrypt.decryptToString(password);


    ui->lineEditEditInsPassword->setText(decrypt);

    }
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_btnDeleteIns_clicked()
{
    QString val=ui->tableIns->model()->data(ui->tableIns->model()->index(ui->tableIns->selectionModel()->currentIndex().row(),0)).toString();
ui->lineEditDeleteCin->setText(val);
   // ui->lineEditDeleteCin->setText(val);

    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_btnInst_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnInst_2_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_3_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_4_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_5_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());

    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_6_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_7_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnInst_8_clicked()
{
    Institutrice i;
    ui->tableIns->setModel(i.afficherInstitutrices());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnResp_5_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_6_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_7_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_8_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_2_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_3_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnResp_4_clicked()
{
    Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btnAddIns_2_clicked()
{
  //  QRegularExpression rx("^[\w|\.]+@[\w]+\.[\w]{2,4}$");
    //QValidator *validator = new QRegularExpressionValidator(rx, this);
//    ui->lineEditAddInsMail->setValidator(validator);
    Notif n;
    QString ams,succ,titre,record;

    QString nom = ui->lineEditAddInsNom->text();
    QString prenom = ui->lineEditAddInsPrenom->text();
    QString mail= ui->lineEditAddInsMail->text();
    QString dateD= ui->lineEditAddInsDd->text();
    QString cin = ui->lineEditAddInsCin->text();
    int Tel = ui->lineEditAddInsTel->text().toInt();
    QString password = ui->lineEditAddInsPassword->text();

    //-----------
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                          QRegularExpression::CaseInsensitiveOption);
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEditAddInsMail->setValidator(validator);
    if(!ui->lineEditAddInsMail->hasAcceptableInput())
        ui->lineEditAddInsMail->setStyleSheet("QLineEdit { color: red;}");
    else
        ui->lineEditAddInsMail->setStyleSheet("QLineEdit { color: black;}");
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);

       QString FreeTrialStartsOn(password);

       //Encrypt
       pwdsc = processSimpleCrypt.encryptToString(FreeTrialStartsOn);

       QString pwdC= pwdsc;

       //Decrypt
       //QString decrypt = processSimpleCrypt.decryptToString(FreeTrialStartDate);

       //qDebug() << "Decrypted 22/11/2011 to" << decrypt;
    //---------------
    Institutrice i(nom,prenom,mail,dateD,cin,Tel,pwdC);

    bool test1 = dateValidate(dateD);
    if(test1 and ui->lineEditAddInsMail->hasAcceptableInput()){
        bool test = i.ajouterInstitutrice();
        if(test) {
            ui->tableIns->setModel(i.afficherInstitutrices());

            ui->stackedWidget->setCurrentIndex(4);
            titre ="succée";
            ams="ajouté";
            record="institutrice";
            n.notification_ajout(cin.toInt(),titre,ams,titre,record);
        }

    }else{

QMessageBox::critical(nullptr, QObject::tr("Ajouter Institutrice "),
            QObject::tr("Erreur date ou mail invalide!.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_edit_2_clicked()
{
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);
    Institutrice i;
    QString cin = ui->lineEditEditInsCin->text();

    QSqlQuery query=i.rechercher(cin);
    QString nom,prenom,mail,Tel,dateD ;
    if (query.next())
    {    
    nom= query.value(1).toString();
    ui->lineEditEditInsNom->setText(nom);
    prenom= query.value(2).toString();
    ui->lineEditEditInsPrenom->setText(prenom);
    mail= query.value(3).toString();
    ui->lineEditEditInsMail->setText(mail);
    Tel= query.value(4).toString();
    ui->lineEditEditInsTel->setText(Tel);
    dateD= query.value(5).toString();
    QDate DateD = QDate::fromString(dateD,"dd/MM/yyyy");
    ui->lineEditEditInsDd->setDate(DateD);
    QString password = query.value(6).toString();
    //Decrypt
               QString decrypt = processSimpleCrypt.decryptToString(password);


    ui->lineEditEditInsPassword->setText(decrypt);

    }
}
void MainWindow::on_btnEditConfirm_clicked()
{
    Notif n;
    QString ams,succ,titre,record;

    QString nom = ui->lineEditEditInsNom->text();
    QString prenom = ui->lineEditEditInsPrenom->text();
    QString mail= ui->lineEditEditInsMail->text();
    QString dateD= ui->lineEditEditInsDd->text();
    QString cin = ui->lineEditEditInsCin->text();
    int Tel = ui->lineEditEditInsTel->text().toInt();
    QString password = ui->lineEditEditInsPassword->text();
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);

       QString FreeTrialStartsOn(password);

       //Encrypt
       pwdsc = processSimpleCrypt.encryptToString(FreeTrialStartsOn);

       QString pwdC= pwdsc;
    Institutrice i(nom,prenom,mail,dateD,cin,Tel,pwdC);
    bool test1 = dateValidate(dateD);
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                          QRegularExpression::CaseInsensitiveOption);
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEditAddInsMail->setValidator(validator);
    if(!ui->lineEditAddInsMail->hasAcceptableInput())
        ui->lineEditAddInsMail->setStyleSheet("QLineEdit { color: red;}");
    else
        ui->lineEditAddInsMail->setStyleSheet("QLineEdit { color: black;}");
    if (test1 and ui->lineEditEditInsMail->hasAcceptableInput())
    {
        bool test=i.modifierInstitutrice();
        if(test){
            titre ="succée";
            ams="modifié";
            record="institutrice";
               n.notification_ajout(cin.toInt(),titre,ams,titre,record);
            ui->tableIns->setModel(i.afficherInstitutrices());

             ui->stackedWidget->setCurrentIndex(4);
        }


    }
    else
QMessageBox::critical(nullptr, QObject::tr("Modifier "),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pB_delete_clicked()
{
    Notif n;
    QString ams,succ,titre,record;

    Institutrice i;
    QString cin = ui->lineEditDeleteCin->text();
    bool test= i.supprimerInstitutrice(cin);

    if(test)
    {
        titre ="succée";
        ams="supprimé";
        record="institutrice";
           n.notification_ajout(cin.toInt(),titre,ams,titre,record);
        ui->tableIns->setModel(i.afficherInstitutrices());

         ui->stackedWidget->setCurrentIndex(4);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une institurice"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btnAddResp_3_clicked()
{
    Notif n;
    QString ams,succ,titre,record;

    QString nom = ui->lineEditAddIRespNom_4->text();
    QString prenom = ui->lineEditAddInslineEditAddInsPrenom_2->text();
    QString mail= ui->lineEditAddIRespMail_2->text();
    QString dateD= ui->lineEditAddIRespDd_2->text();
    QString cin = ui->lineEditAddIRespCin_3->text();
    QString role = ui->comboBoxRole->currentText();
    int Tel = ui->lineEditAddIRespTel_2->text().toInt();
    QString password = ui->lineEditAddRespPassword->text();
//
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);

       QString FreeTrialStartsOn(password);

       //Encrypt
       pwdsc = processSimpleCrypt.encryptToString(FreeTrialStartsOn);

       QString pwdC= pwdsc;

       //Decrypt
       //QString decrypt = processSimpleCrypt.decryptToString(FreeTrialStartDate);

       //qDebug() << "Decrypted 22/11/2011 to" << decrypt;
//
       QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                             QRegularExpression::CaseInsensitiveOption);
       QValidator *validator = new QRegularExpressionValidator(rx, this);
       ui->lineEditAddIRespMail_2->setValidator(validator);
       if(!ui->lineEditAddIRespMail_2->hasAcceptableInput())
           ui->lineEditAddIRespMail_2->setStyleSheet("QLineEdit { color: red;}");
       else
           ui->lineEditAddIRespMail_2->setStyleSheet("QLineEdit { color: black;}");

    Responsables r(nom,prenom,mail,dateD,cin,role,Tel,pwdC);

    bool test1 = dateValidate(dateD);

    if(test1  and ui->lineEditAddIRespMail_2->hasAcceptableInput()){
         bool test = r.ajouterResponsables();
         if(test){
              ui->tableResp->setModel(r.afficherResponsables());
             ui->stackedWidget->setCurrentIndex(0);
             titre ="succée";
             ams="ajouté";
             record="responsable";
             n.notification_ajout(cin.toInt(),titre,ams,titre,record);
         }

    }else{

QMessageBox::critical(nullptr, QObject::tr("Ajouter Responsables "),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_btnEditConfirm_2_clicked()
{
    Notif n;
    QString ams,succ,titre,record;


    QString nom = ui->lineEditEditRespNom_2->text();
    QString prenom = ui->lineEditEditRespPrenom_2->text();
    QString mail= ui->lineEditEditRespMail_2->text();
    QString dateD= ui->lineEditEditRespDd_2->text();
    QString cin = ui->lineEditEditRespCin_2->text();
    QString role = ui->comboBoxRole_2->currentText();
    int Tel = ui->lineEditEditRespTel_2->text().toInt();
    QString password = ui->lineEditEditRespPassword->text();
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                          QRegularExpression::CaseInsensitiveOption);
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEditEditRespMail_2->setValidator(validator);
    if(!ui->lineEditEditRespMail_2->hasAcceptableInput())
        ui->lineEditEditRespMail_2->setStyleSheet("QLineEdit { color: red;}");
    else
        ui->lineEditEditRespMail_2->setStyleSheet("QLineEdit { color: black;}");

        Responsables r(nom,prenom,mail,dateD,cin,role,Tel,password);
        bool test1 = dateValidate(dateD);

        if (test1 and ui->lineEditEditRespMail_2->hasAcceptableInput())
        {
            bool test=r.modifierResponsables();
           if (test){

               titre ="succée";
               ams="modifié";
               record="responsable";
                  n.notification_ajout(cin.toInt(),titre,ams,titre,record);
               ui->tableResp->setModel(r.afficherResponsables());

                ui->stackedWidget->setCurrentIndex(0);

           }

        }
        else
    QMessageBox::critical(nullptr, QObject::tr("Modifier Responsable"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_edit_3_clicked()
{
    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);
    Responsables r;
        QString cin = ui->lineEditEditRespCin_2->text();

        QSqlQuery query=r.rechercher(cin);
        QString nom,prenom,mail,Tel,dateD,role ;
        if (query.next())
        {
        nom= query.value(1).toString();
        ui->lineEditEditRespNom_2->setText(nom);
        prenom= query.value(2).toString();
        ui->lineEditEditRespPrenom_2->setText(prenom);
        mail= query.value(3).toString();
        ui->lineEditEditRespMail_2->setText(mail);
        role= query.value(6).toString();
        ui->comboBoxRole_2->setCurrentText(role);
        Tel= query.value(4).toString();
        ui->lineEditEditRespTel_2->setText(Tel);
        dateD= query.value(5).toString();
        QDate DateD = QDate::fromString(dateD,"dd/MM/yyyy");
        ui->lineEditEditRespDd_2->setDate(DateD);
        QString password = query.value(7).toString();
        //Decrypt
                   QString decrypt = processSimpleCrypt.decryptToString(password);


        ui->lineEditEditRespPassword->setText(decrypt);
        }
}

void MainWindow::on_pB_delete_2_clicked()
{
    Notif n;
    QString ams,succ,titre,record;

    Responsables r;
    QString cin = ui->lineEditDeleteResp->text();
    bool test= r.supprimerResponsables(cin);

    if(test)
    {
        ui->stackedWidget->setCurrentIndex(0);
        titre ="succée";
        ams="supprimé";
        record="responsable";
           n.notification_ajout(cin.toInt(),titre,ams,titre,record);
        ui->tableResp->setModel(r.afficherResponsables());

         ui->stackedWidget->setCurrentIndex(0);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Responsable"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btnAddResp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_btnEditResp_clicked()
{
    QString val=ui->tableResp->model()->data(ui->tableResp->model()->index(ui->tableResp->selectionModel()->currentIndex().row(),0)).toString();

    QString pwdsc ;

       //Set The Encryption And Decryption Key
       SimpleCrypt processSimpleCrypt(89473829);
    Responsables r;
        ui->lineEditEditRespCin_2->setText(val);

        QSqlQuery query=r.rechercher(val);
        QString nom,prenom,mail,Tel,dateD,role ;
        if (query.next())
        {
        nom= query.value(1).toString();
        ui->lineEditEditRespNom_2->setText(nom);
        prenom= query.value(2).toString();
        ui->lineEditEditRespPrenom_2->setText(prenom);
        mail= query.value(3).toString();
        ui->lineEditEditRespMail_2->setText(mail);
        role= query.value(6).toString();
        ui->comboBoxRole_2->setCurrentText(role);
        Tel= query.value(4).toString();
        ui->lineEditEditRespTel_2->setText(Tel);
        dateD= query.value(5).toString();
        QDate DateD = QDate::fromString(dateD,"dd/MM/yyyy");
        ui->lineEditEditRespDd_2->setDate(DateD);
        QString password = query.value(7).toString();
        //Decrypt
                   QString decrypt = processSimpleCrypt.decryptToString(password);


        ui->lineEditEditRespPassword->setText(decrypt);
        }
        ui->stackedWidget->setCurrentIndex(2);


}

void MainWindow::on_btnDeleteResp_clicked()
{
    QString val=ui->tableIns->model()->data(ui->tableIns->model()->index(ui->tableIns->selectionModel()->currentIndex().row(),0)).toString();
    ui->lineEditDeleteResp->setText(val);
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_btnPdfMenu_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableResp->model()->rowCount();
                const int columnCount =ui->tableResp->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<img src=':/new/prefix1/icon/logo.webp' width='100' height='100'>\n"
                            "<h1>Liste des abonnes</h1>"



                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableResp->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableResp->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableResp->isColumnHidden(column)) {
                                   QString data = ui->tableResp->model()->data(ui->tableResp->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                           document->print(&printer);}
}

void MainWindow::on_btnPdfMenu_6_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableIns->model()->rowCount();
                const int columnCount =ui->tableIns->model()->columnCount();

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<img src=':/new/prefix1/icon/logo.webp' width='100' height='100'>\n"
                            "<h1>Liste des abonnes</h1>"



                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableIns->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableIns->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableIns->isColumnHidden(column)) {
                                   QString data = ui->tableIns->model()->data(ui->tableIns->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                           document->print(&printer);}
}

void MainWindow::on_lineEditEditRespMail_2_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEditAddInsMail_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEditAddInsMail_selectionChanged()
{

}

void MainWindow::on_lineEditAddInsMail_editingFinished()
{

}

void MainWindow::on_lineEditAddIRespMail_2_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_pB_login_clicked()
{
    QString login = ui->lineEdit_user->text();
    QString pwd = ui->lineEdit_pswd->text();
    QString role = ui->comboBoxRole_3->currentText();
    QString pwdsc ;

       //Set The Encryption And Decryption Key

    Institutrice i;
    Responsables r;
    SimpleCrypt processSimpleCrypt(89473829);


    QSqlQuery queryIns=i.rechercher(login);
    QSqlQuery queryResp=r.rechercher(login);
    if(role =="Institutrice"){
        if (queryIns.next())
        {
            QString password = queryIns.value(6).toString();
            //Decrypt
                       QString decrypt = processSimpleCrypt.decryptToString(password);
                       if(pwd==decrypt){
                           ui->tableIns->setModel(i.afficherInstitutrices());
                           ui->stackedWidget->setCurrentIndex(4);

                       }else{
                           QMessageBox::critical(nullptr, QObject::tr("Login"),
                                       QObject::tr("mdp incorrect !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                       }






        }else{
            QMessageBox::critical(nullptr, QObject::tr("Login"),
                        QObject::tr("Cin n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }else{
        if (queryResp.next())
        {
            QString password = queryResp.value(7).toString();
            //Decrypt
                       QString decrypt = processSimpleCrypt.decryptToString(password);
                       if(pwd==decrypt){
                           QString respRole = queryResp.value(6).toString();
                           if (respRole == "Administrateur"){
                              ui->stackedWidget->setCurrentIndex(9);
                           }


                       }else{
                           QMessageBox::critical(nullptr, QObject::tr("Login"),
                                       QObject::tr("mdp incorrect !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                       }






        }else{
            QMessageBox::critical(nullptr, QObject::tr("Login"),
                        QObject::tr("Cin n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}


void MainWindow::on_lineEditRechIns_textChanged(const QString &arg1)
{
    Institutrice i;
    ui->tableIns->setModel(i.chercherInstitutrice(ui->lineEditRechIns->text()));
}

void MainWindow::on_lineEditRechResp_textChanged(const QString &arg1)
{
    Responsables r;
    ui->tableResp->setModel(r.chercherResponsable(ui->lineEditRechResp->text()));
}

void MainWindow::on_triResp_clicked()
{
    Responsables r;
ui->tableResp->setModel(r.triNomAsc());
}

void MainWindow::on_triInst_clicked()
{
    Institutrice i;
ui->tableIns->setModel(i.triNomAsc());
}

void MainWindow::on_triInst_2_clicked()
{
    Institutrice i;
ui->tableIns->setModel(i.triNomDsc());
}

void MainWindow::on_triResp_2_clicked()
{
    Responsables r;
ui->tableResp->setModel(r.triNomDsc());
}

void MainWindow::on_pushButtonAdminHomeIns_clicked()
{
      Responsables r;
    ui->tableResp->setModel(r.afficherResponsables());
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}
