#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
}

NewDialog::~NewDialog()
{
    delete ui;
}

void NewDialog::on_pushButton_clicked()
{
   this -> NewFileName =  ui -> lineEdit -> text();
    if(ui -> lineEdit -> text().isEmpty())
    {
        QMessageBox::warning(this ,"bad input","unavalible file name");
    }
    else
    {
        this -> NewFileName =  ui -> lineEdit -> text();
        this -> InformationCompleted = true;
        this -> reject();

    }

}
