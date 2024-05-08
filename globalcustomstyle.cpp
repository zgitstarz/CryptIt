#include "globalcustomstyle.h"

GlobalCustomStyle::GlobalCustomStyle() {}


void GlobalCustomStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                   QPainter *painter, const QWidget *widget) const
{
    painter->setRenderHint(QPainter::Antialiasing);
    switch(element)
    {
    case PrimitiveElement::PE_FrameFocusRect:
        return;

    case PrimitiveElement::PE_PanelLineEdit:
        painter->setBrush(QColor(0xff, 0xff, 0xff));
        painter->setPen(QColor(0x54, 0x54, 0x54));
        painter->drawRoundedRect(option->rect, 5, 5);
        return;
    default:
        super::drawPrimitive(element, option, painter, widget);
    }



}


void GlobalCustomStyle::drawControl(ControlElement element, const QStyleOption *option,
                 QPainter *painter, const QWidget *widget) const
{
    switch(element)
    {
    default:
        super::drawControl(element, option, painter, widget);
    }
}


void GlobalCustomStyle::drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                        QPainter *painter, const QWidget *widget) const
{
    switch(control)
    {
    default:
        super::drawComplexControl(control, option, painter, widget);
    }
}













