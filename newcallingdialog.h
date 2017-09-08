#ifndef NEWCALLINGDIALOG_H
#define NEWCALLINGDIALOG_H

#include <QDialog>

namespace Ui {
class NewCallingDialog;
}

class NewCallingDialog : public QDialog
{
    Q_OBJECT

public:
  //  explicit NewCallingDialog(QWidget *parent = 0);
    NewCallingDialog();
    ~NewCallingDialog();

private:
    Ui::NewCallingDialog *ui;
};

#endif // NEWCALLINGDIALOG_H
