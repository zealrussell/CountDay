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

public slots:
    void mysetText();

private:
    Ui::Widget *ui;

    void initView();
};

#endif // WIDGET_H
