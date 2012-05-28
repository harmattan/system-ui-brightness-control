#include "brightnessplugin.h"
#include "brightnesscontroller.h"

Q_EXPORT_PLUGIN2(profile, BrightnessPlugin)

BrightnessPlugin::BrightnessPlugin(QObject *parent) :
    statusIndicatorMenu(0),
    m_brightnessController(0)
{
    Q_UNUSED(parent)
}

void BrightnessPlugin::setStatusIndicatorMenuInterface(MStatusIndicatorMenuInterface &menuInterface)
{
    statusIndicatorMenu = &menuInterface;
}

MStatusIndicatorMenuInterface *BrightnessPlugin::statusIndicatorMenuInterface() const
{
    return statusIndicatorMenu;
}

// Methods derived from MApplicationExtensionInterface
bool BrightnessPlugin::initialize(const QString &)
{
    m_brightnessController = new BrightnessController(this);

    return true;
}

QGraphicsWidget *BrightnessPlugin::widget()
{
    return m_brightnessController;
}

M_LIBRARY
