#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include <QDialog>
#include "globals.h"

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
    void on_catButtonBox_accepted();

    void on_catButtonBox_rejected();


private:
    Ui::AddCategory *ui;
};

#endif // ADDCATEGORY_H
