#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddIns_clicked();

    void on_btnEditConfirm_clicked();

    void on_btnEditIns_clicked();

    void on_btnDeleteIns_clicked();

    void on_btnInst_clicked();

    void on_btnInst_2_clicked();

    void on_btnInst_3_clicked();

    void on_btnInst_4_clicked();

    void on_btnInst_5_clicked();

    void on_btnInst_6_clicked();

    void on_btnInst_7_clicked();

    void on_btnInst_8_clicked();

    void on_btnResp_5_clicked();

    void on_btnResp_6_clicked();

    void on_btnResp_7_clicked();

    void on_btnResp_8_clicked();

    void on_btnResp_clicked();

    void on_btnResp_2_clicked();

    void on_btnResp_3_clicked();

    void on_btnResp_4_clicked();

    void on_btnAddIns_2_clicked();

    void on_pushButton_edit_2_clicked();

    void on_pB_delete_clicked();

    void on_btnAddResp_3_clicked();

    void on_btnEditConfirm_2_clicked();

    void on_pushButton_edit_3_clicked();

    void on_pB_delete_2_clicked();

    void on_btnAddResp_clicked();

    void on_btnEditResp_clicked();

    void on_btnDeleteResp_clicked();

    void on_btnPdfMenu_clicked();

    void on_btnPdfMenu_6_clicked();

    void on_lineEditEditRespMail_2_textChanged(const QString &arg1);

    void on_lineEditAddInsMail_textChanged(const QString &arg1);

    void on_lineEditAddInsMail_selectionChanged();

    void on_lineEditAddInsMail_editingFinished();

    void on_lineEditAddIRespMail_2_cursorPositionChanged(int arg1, int arg2);

    void on_pB_login_clicked();


    void on_lineEditRechIns_textChanged(const QString &arg1);

    void on_lineEditRechResp_textChanged(const QString &arg1);

    void on_triResp_clicked();

    void on_triInst_clicked();

    void on_triInst_2_clicked();

    void on_triResp_2_clicked();

    void on_pushButtonAdminHomeIns_clicked();

    void on_home_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
