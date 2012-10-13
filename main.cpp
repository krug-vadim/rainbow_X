#include <QApplication>
#include "rainbowwidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RainbowWidget w;
	w.show();
	
	return a.exec();
}
