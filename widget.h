#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_coffee_clicked();

    void on_c50_clicked();

    void on_c100_clicked();

    void on_c500_clicked();

    void on_tea_clicked();

    void on_Aronia_clicked();

    void enablebutton();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
