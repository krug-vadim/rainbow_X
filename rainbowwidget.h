#ifndef RAINBOWWIDGET_H
#define RAINBOWWIDGET_H

#include <QWidget>

namespace Ui {
	class RainbowWidget;
}

class RainbowWidget : public QWidget
{
		Q_OBJECT
		
	public:
		explicit RainbowWidget(QWidget *parent = 0);
		~RainbowWidget();
		
	private:
		Ui::RainbowWidget *ui;
};

#endif // RAINBOWWIDGET_H
