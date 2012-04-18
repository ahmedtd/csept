#include "addcategory.h"
#include "ui_addcategory.h"

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

void AddCategory::on_buttonBox_accepted()
{
    if (ui->classBox->currentText() == "General")
    {
        //FIXME simply append the new category to categories.txt
        //FIXME update all_categories too
    }else
    {
        //FIXME append "Class"+ui->categoryEdit->text().toStdString() to categories.txt
        //FIXME update all_categories too
    }


}

void AddCategory::on_buttonBox_rejected()
{
    this->close();
}
