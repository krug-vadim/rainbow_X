#include "rainbowwidget.h"
#include "ui_rainbowwidget.h"

RainbowWidget::RainbowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RainbowWidget)
{
	ui->setupUi(this);
}

RainbowWidget::~RainbowWidget()
{
	delete ui;
}
