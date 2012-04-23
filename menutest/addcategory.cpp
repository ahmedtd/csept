#include "addcategory.h"
#include "ui_addcategory.h"
#include "globals.h"

AddCategory::AddCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategory)
{
    ui->setupUi(this);
}

AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::on_catButtonBox_accepted()
{
    std::string category = "";

    if (ui->classBox->currentText() == "General")
    {
        category = ui->CategoryEdit->text().toStdString();
    }else
    {
        //The category is of the form "Class:" + text
        category = "Class:" + ui->CategoryEdit->text().toStdString();
    }

    //Append the new category to categories.txt
    std::fstream cat_file;
    if (cat_file.is_open())
    {
        QMessageBox errorMessBox;
        errorMessBox.setText("Categories file is already open");
        errorMessBox.exec();
        return;
    }

    cat_file.open("categories.txt", std::ios::out | std::ios::app);

    if (!cat_file.is_open())
    {
        //Error, so don't use
        QMessageBox errorMessBox;
        errorMessBox.setText("Log file cannot be opened");
        errorMessBox.exec();
        return;
    }

    cat_file << category << std::endl;

    if (cat_file.is_open())
    {
        cat_file.close();
    }

    this->close();
}

void AddCategory::on_catButtonBox_rejected()
{
    this->close();
}
