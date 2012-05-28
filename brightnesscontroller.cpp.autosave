#include "brightnesscontroller.h"
#include <MSlider>
#include <MImageWidget>

BrightnessController::BrightnessController(BrightnessPlugin *brightnessPlugin, QGraphicsItem *parent) :
    MWidget(parent),
    m_brightnessSlider(new MSlider(this)),
    m_brightnessPlugin(brightnessPlugin)
{
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Horizontal, this);
    //setTitle(tr("Brightness"));
    setObjectName("StatusIndicatorMenuExtensionContentItem");

    MImageWidget *lowBrightnessImage = new MImageWidget("icon-s-camera-low-brightness", this);
    layout->addItem(lowBrightnessImage);

    m_brightnessSlider->setRange(1, GConfItem("/system/osso/dsm/display/max_display_brightness_levels", this).value().toInt());
    layout->addItem(m_brightnessSlider);

    MImageWidget *highBrightnessImage = new MImageWidget("icon-s-camera-high-brightness", this);
    layout->addItem(highBrightnessImage);

    layout->setContentsMargins(30, 15, 15, 15);

    m_brightnessGConfItem = new GConfItem("/system/osso/dsm/display/display_brightness");
    m_brightnessSlider->setValue(m_brightnessGConfItem->value().toInt());
    connect(m_brightnessGConfItem, SIGNAL(valueChanged()), this, SLOT(onValueChanged()));
    connect(m_brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));
}

BrightnessController::~BrightnessController()
{

}

void BrightnessController::onValueChanged()
{
    // Avoid infinite loops :)
    disconnect(m_brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));

    m_brightnessSlider->setValue(m_brightnessGConfItem->value().toInt());

    connect(m_brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));
}

void BrightnessController::onSliderValueChanged(int newValue)
{
    m_brightnessGConfItem->blockSignals(true);
    m_brightnessGConfItem->set(newValue);
    m_brightnessGConfItem->blockSignals(false);
}
