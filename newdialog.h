#ifndef NEWDIALOG_H
#define NEWDIALOG_H
#include <QDialog>
#include <QMessageBox>
namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    QString NewFileName;
    bool InformationCompleted = false;

    ~NewDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewDialog *ui;

};

#endif // NEWDIALOG_H
