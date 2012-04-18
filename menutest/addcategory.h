#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include <QDialog>

namespace Ui {
    class AddCategory;
}

class AddCategory : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategory(QWidget *parent = 0);
    ~AddCategory();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddCategory *ui;
};

#endif // ADDCATEGORY_H
