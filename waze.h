#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_waze.h"

class waze : public QMainWindow
{
    Q_OBJECT

public:
    waze(QWidget *parent = Q_NULLPTR);

private:
    Ui::wazeClass ui;
};
