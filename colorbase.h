#ifndef COLORBASE_H
#define COLORBASE_H

#include "globalcustomstyle.h"



namespace ColorBase{

// AbstractButton Coloring
void buttonDraw(const QStyleOption* opt, QPainter* painter, const QWidget* w = nullptr);
QColor buttonBevelColor(const QStyleOption* opt, QPainter* painter, const QWidget* w = nullptr);
QColor buttonOutlineColor(const QStyleOption* opt, QPainter* painter, const QWidget* w = nullptr);
QColor buttonHoverColor(const QStyleOption* opt, QPainter* painter, const QWidget* w = nullptr);
void buttonSetPalette(QStyleOption* opt, QPainter* painter, const QWidget* w = nullptr);


// Text Input Coloring


}




#endif // COLORBASE_H
