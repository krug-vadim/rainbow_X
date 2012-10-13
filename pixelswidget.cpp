#include "pixelswidget.h"

#include <QtGui/QPainter>

PixelsWidget::PixelsWidget(QWidget *parent) :
    QWidget(parent)
{
	_image = 0;
}

QImage *PixelsWidget::image() const
{
	return _image;
}

void PixelsWidget::setImage(QImage *image)
{
	_image = image;

	if ( !_image )
		return;

	setMinimumWidth(_image->width());
	setMaximumWidth(_image->width());

	setMinimumHeight(_image->height());
	setMaximumWidth(_image->height());
}

void PixelsWidget::paintEvent(QPaintEvent *event)
{
	if ( !image() )
	{
		QWidget::paintEvent(event);
		return;
	}

	QPainter painter(this);

	painter.drawImage(0, 0, *image());
}
