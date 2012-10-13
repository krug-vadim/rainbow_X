#ifndef PIXELSWIDGET_H
#define PIXELSWIDGET_H

#include <QtGui/QWidget>

class PixelsWidget : public QWidget
{
	Q_OBJECT

	public:
		explicit PixelsWidget(QWidget *parent = 0);

		QImage *image() const;
		void setImage(QImage *image);

	protected:
		void paintEvent(QPaintEvent *event);

	private:
		QImage *_image;

};

#endif // PIXELSWIDGET_H
