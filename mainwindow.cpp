#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <string>
#include <QDir>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    countRemove = 0;
    this->setWindowTitle("RemoveTHATFile");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::remover(const QDir & in)
{
    QDir loc = in;
    QDirIterator it(loc, QDirIterator::Subdirectories);
    QVector<QDir> vec;
    while (it.hasNext())
        vec.append(it.next());

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].remove(ui->lineEdit_2->text().toStdString().c_str()))
            countRemove++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    countRemove = 0;
    QDir loc(ui->lineEdit->text().toStdString().c_str());
    if (loc.exists())
        remover(loc);

    ui->label_5->setText(std::to_string(countRemove).c_str());
}

void MainWindow::slotAboutQt()
{
    QApplication::aboutQt();
}


