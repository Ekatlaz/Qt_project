#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include "registration.h"
#include "aboutdialog.h"
#include <QMessageBox>

#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new TableModel), proxyModel(new ProxyModel)
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    _aboutDialog = new AboutDialog(this);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode());
    ui->tableView->setSortingEnabled(true);

    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
    ui->tableView->hideColumn(11);
    ui->tableView->hideColumn(12);
    ui->tableView->hideColumn(13);
    ui->tableView->hideColumn(14);
    ui->tableView->hideColumn(15);
    ui->tableView->hideColumn(16);
    ui->tableView->hideColumn(17);
    ui->tableView->hideColumn(18);
    ui->tableView->hideColumn(19);
    ui->tableView->hideColumn(20);
    ui->tableView->hideColumn(21);
    ui->tableView->hideColumn(22);
    ui->tableView->hideColumn(23);

    QObject::connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);

//    for (int i = 0; i < 12; i++)
//    {
//        if (i != 3 && i != 0 && i != 2 && i != 8 && i != 10)
//            ui->tableView->setColumnHidden(i, true);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[index.row()];
    ui->nameLine->setText(targetLine[0]);
    ui->dateLine->setText(targetLine[1]);
    ui->locationLine->setText(targetLine[2]);
    ui->mintempLine->setText(targetLine[3]);
    ui->maxtempLine->setText(targetLine[4]);
    ui->rainfallLine->setText(targetLine[5]);
    ui->windgustdirLine->setText(targetLine[6]);
    ui->windgustspeedLine->setText(targetLine[7]);
    ui->winddir9amLine->setText(targetLine[8]);
    ui->winddir3pmLine->setText(targetLine[9]);
    ui->windspeed9amLine->setText(targetLine[10]);
    ui->windspeed3pmLine->setText(targetLine[11]);
    ui->humidity9amLine->setText(targetLine[12]);
    ui->humidity3pmLine->setText(targetLine[13]);
    ui->pressure9amLine->setText(targetLine[14]);
    ui->pressure3pmLine->setText(targetLine[15]);
    ui->cloud9amLine->setText(targetLine[16]);
    ui->cloud3pmLine->setText(targetLine[17]);
    ui->temp9amLine->setText(targetLine[18]);
    ui->temp3pmLine->setText(targetLine[19]);
    ui->raintodayLine->setText(targetLine[20]);
    ui->RISK_MMLine->setText(targetLine[21]);
    ui->raintomorrowLine->setText(targetLine[22]);
}


void MainWindow::on_addRow_clicked()
{
//    model->addRow(QList<QString>());
    AddRowDialog dialog;
    if (dialog.exec())
    {
        model->addRow(dialog.getRowData());
    }
//    if (dialog.close()){}
}


void MainWindow::on_deletRow_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    qDebug()<<select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
    on_goButton_clicked();
}

void MainWindow::on_goButton_clicked()
{
    QString needToSearch = ui->searchLine->text();
    proxyModel->setName(needToSearch);
}


void MainWindow::on_pushButton_clicked()
{
    registration window;
    window.setModal(true);
    window.exec();
}

void MainWindow::showAboutDialog()
{
    _aboutDialog->show();
}

void MainWindow::on_singnin_clicked()
{
    QString login = ui->loginLine->text();
    QString password = ui->passwordLine->text();

    if(login == "admin" && password == "1234") {
        QMessageBox::information(this, "Well done", "Authorization was successful");

    } else
        QMessageBox::warning(this, "Authorization", "Authorization was failed");
}

