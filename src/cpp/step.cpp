#include "step.h"

//-------------------------------------------------------------------------
Step::Step(QObject* _parent) : QObject(_parent)
{
    m_value = 0;
    m_unit  = DISTANCE_IN_M;
}


//-------------------------------------------------------------------------
Step::Step(const Step& _step) : QObject()
{
    m_value = _step.m_value;
    m_unit  = _step.m_unit;
}

//-------------------------------------------------------------------------
const Step& Step::operator= (const Step& _step)
{
    m_value = _step.m_value;
    m_unit  = _step.m_unit;

    return (*this);
}

//-------------------------------------------------------------------------
bool Step::Parse (const QJsonObject& _json, Step& _step)
{
    Step  l_step;

    // ---- parse unit ----
    if (_json.contains("unit") && _json["unit"].isString())
    {
        QString l_unitStr = _json["unit"].toString();

        if (l_unitStr == "m")
        {
            l_step.setUnit(DISTANCE_IN_M);
        }
        else if (l_unitStr == "km")
        {
            l_step.setUnit(DISTANCE_IN_KM);
        }
        else if (l_unitStr == "sec")
        {
            l_step.setUnit(DURATION_IN_SEC);
        }
        else if (l_unitStr == "min")
        {
            l_step.setUnit(DURATION_IN_MIN);
        }
        else
        {
            qWarning("Invalid 'unit' value in 'Step' element");
            return false;
        }
    }
    else
    {
        qWarning("Unable to find 'kind' attribute in 'Step' element");
        return false;
    }

    // ---- parse value ----
    if (_json.contains("value") && _json["value"].isDouble())
    {
        l_step.setValue(static_cast<quint16>(_json["value"].toInt(0)));
    }
    else
    {
        qWarning("Unable to find 'value' attribute in 'Step' element");
        return false;
    }

    // ---- parse value ----
    if (_json.contains("info") && _json["info"].isString())
    {
        l_step.setInfo(_json["value"].toString());
    }
    else
    {
        qWarning("Unable to find 'info' attribute in 'Step' element");
        return false;
    }

    // ---- parse rest ----
    if (_json.contains("rest") && _json["rest"].isBool())
    {
        //l_Step.setValue((quint16)_json["value"].toBool());
    }
    else
    {
        qWarning("Unable to find 'rest' attribute in 'Step' element");
        return false;
    }

    qDebug("Step successfully loaded!");
    _step = l_step;
    return true;
}

//-------------------------------------------------------------------------
void Step::setUnit(const Unit& _kind)
{
    if (m_unit != _kind)
    {
        m_unit = _kind;
        emit unitChanged();
    }
}

//-------------------------------------------------------------------------
void Step::setValue(const quint16& _value)
{
    if (m_value != _value)
    {
        m_value = _value;
        emit valueChanged();
    }
}

//-------------------------------------------------------------------------
void Step::setInfo(const QString& _info)
{
    if (m_info != _info)
    {
        m_info = _info;
        emit infoChanged();
    }
}

//-------------------------------------------------------------------------
Step::Unit Step::unit() const
{
    return m_unit;
}

//-------------------------------------------------------------------------
quint16 Step::value() const
{
    return m_value;
}

//-------------------------------------------------------------------------
QString Step::info() const
{
    return m_info;
}
