#ifndef GLOBALCUSTOMSTYLE_H
#define GLOBALCUSTOMSTYLE_H

#include <QProxyStyle>
#include <QPainter>
#include <QStyleOption>

using super = QProxyStyle;

class GlobalCustomStyle : public super
{
public:
    GlobalCustomStyle();

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget = nullptr) const override;
    void drawControl(ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget = nullptr) const override;
    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                            QPainter *painter, const QWidget *widget = nullptr) const override;


};

#endif // GLOBALCUSTOMSTYLE_H
