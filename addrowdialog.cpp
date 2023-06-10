#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

QList<QString> AddRowDialog::getRowData()
{
    QList<QString> newList(23, "No data");
    if (ui->nameLine->text() != "")
        newList[0] = ui->nameLine->text();
    if (ui->locationLine->text() != "")
        newList[1] = ui->dateLine->text();
    newList[2] = ui->locationLine->text();
    newList[3] = ui->mintempSpinBox->text();
    newList[4] = ui->maxtmpSpinBox->text();
    newList[5] = ui->rainfallSpinBox->text();
    newList[6] = ui->windgustdirCB->currentText();
    newList[7] = ui->windgustspeedSpinB->text();
    newList[8] = ui->winddir9amcomboBox->currentText();
    newList[9] = ui->winddir3pmcomboBox->currentText();
    newList[10] = ui->windspeed9amdoubleSpinBox->text();
    newList[11] = ui->windspeed3pmdoubleSpinBox->text();
    newList[12] = ui->humidity9amdoubleSpinBox->text();
    newList[13] = ui->humidity3pmdoubleSpinBox->text();
    newList[14] = ui->pressure9amdoubleSpinBox->text();
    newList[15] = ui->pressure3pmdoubleSpinBox->text();
    newList[16] = ui->cloud9amdoubleSpinBox->text();
    newList[17] = ui->temp9amdoubleSpinBox->text();
    newList[18] = ui->temp3pmdoubleSpinBox->text();
    newList[19] = ui->raintodaycomboBox->currentText();
    newList[20] = ui->RISK_MMdoubleSpinBox->text();
    newList[21] = ui->raintomorrowcomboBox->currentText();
    return newList;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
