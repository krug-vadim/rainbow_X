#ifndef IBNIZ_H
#define IBNIZ_H

#include <QtCore/QStack>
#include <QtCore/QString>
#include <QtGui/QImage>

extern "C" {
	#include "fixmath.h"
}

class Ibniz
{
	public:
		Ibniz();

		void run(QImage *src, QImage *dst, const QString &program, int cx, int cy);

	private:
		void parse(QImage *src, const QString &program, int cx, int cy);

		QStack<fix_t> stack;
};

#endif // IBNIZ_H
