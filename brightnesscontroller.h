#ifndef BRIGHTNESSCONTROLLER_H
#define BRIGHTNESSCONTROLLER_H

#include <MContentItem>
#include <MSlider>
#include <QGraphicsLinearLayout>
#include "brightnessplugin.h"
#include <gq/GConfItem>

class MStatusIndicatorMenuInterface;
class ProfilePlugin;

class BrightnessController : public MWidget
{
    Q_OBJECT
public:
    explicit BrightnessController(BrightnessPlugin *brightnessPlugin, QGraphicsItem *parent = NULL);
    virtual ~BrightnessController();

signals:

public slots:

private:
    MSlider *m_brightnessSlider;
    BrightnessPlugin *m_brightnessPlugin;

    GConfItem *m_brightnessGConfItem;

private slots:
    void onSliderValueChanged(int);
    void onValueChanged();
};

#endif // BRIGHTNESSCONTROLLER_H
