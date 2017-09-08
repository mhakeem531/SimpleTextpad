#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui -> textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    Newdia = new NewDialog;
    Newdia -> exec();
    if(Newdia -> InformationCompleted ==  true)
    {
       this -> FileName = Newdia -> NewFileName;
        QFile CreationFile(FileName);
        if (!CreationFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::warning(this ,"Warning","Not enough space in selcted path!!!");
        }
        else
        {

            bool x = CreationFile.open(QIODevice::ReadWrite | QIODevice::Text);
           if(x)
           {

               QTextStream stream(&CreationFile);
               stream << "" << endl;
           }
           ui -> textEdit -> setPlainText("");
        }

    }

}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this , "Choose a file!" , QDir::currentPath());
    if(!file.isEmpty())
    {
        /*
         * if the choosen file is not empty : a stream will be created to move data from the
         * file to the ram to be displayed on the app
         */
        QFile sfile(file);
                                         /*Text here to prevent the app tp make any chande to the text*/
        if(sfile.open(QFile::ReadOnly | QFile::Text))
        {
            FileName = file;
            QTextStream in(&sfile);
            QString text = in.readAll();
            sfile.close();

            ui -> textEdit -> setPlainText(text);
        }
    }

}

/*
 * this function to open a file and make an edit on it then want to save it
 *
*/
void MainWindow::on_actionSave_triggered()
{
    QFile sfile(FileName);
    if(sfile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sfile);
        out << ui -> textEdit -> toPlainText();

        sfile.flush();
        sfile.close();
    }


}

void MainWindow::on_actionsave_as_triggered()
{

    QString file = QFileDialog::getSaveFileName(this , "Save AS!!");
    if(!file.isEmpty())
    {
       FileName = file;
       on_actionSave_triggered();
    }
}

void MainWindow::on_actionCopy_triggered()
{
   ui -> textEdit -> copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui -> textEdit -> cut();
}

void MainWindow::on_actionpaste_triggered()
{
    ui -> textEdit -> paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui -> textEdit -> undo();
}

void MainWindow::on_actionRedo_triggered()
{
   ui -> textEdit -> redo();
}
