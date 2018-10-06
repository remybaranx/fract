#include "applicationdata.h"

//--------------------------------------------------------------------------------
ApplicationData::ApplicationData(QObject* _parent) : QObject(_parent)
{
}

//--------------------------------------------------------------------------------
bool ApplicationData::load(const QString& _sessionFilename)
{
    return true;
}
