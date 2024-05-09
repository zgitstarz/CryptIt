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

void buttonDraw(const QStyleOption* opt, QPainter* painter, const QWidget* w)
{

    if(!(opt->state & QStyle::State_Enabled))
    {
        painter->setBrush(QColor(0xbe, 0xc0, 0xc1));
        painter->setPen(QColor(0x54, 0x54, 0x54));
        painter->setOpacity(0.5);
    }
    else if(opt->state & QStyle::State_MouseOver || opt->state & QStyle::State_Sunken)
    {
        painter->setBrush(QColor(0xbe, 0xc0, 0xc1));
        painter->setPen(QPen(QColor(0xff, 0xd7, 0x00), 2));
    }

    else
    {
        painter->setBrush(QColor(0xbe, 0xc0, 0xc1));
        painter->setPen(QColor(0x54, 0x54, 0x54));
    }

    painter->drawRoundedRect(opt->rect, 6, 6);

}


void GlobalCustomStyle::drawControl(ControlElement element, const QStyleOption *option,
                 QPainter *painter, const QWidget *widget) const
{
    painter->setRenderHint(QPainter::Antialiasing);

    switch(element)
    {

    case ControlElement::CE_PushButtonBevel:
        buttonDraw(option, painter, widget);
        break;

    default:
        super::drawControl(element, option, painter, widget);
        break;
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













