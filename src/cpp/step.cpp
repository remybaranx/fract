#include "step.h"

//-------------------------------------------------------------------------
Step::Step(QObject* _parent) : QObject(_parent)
{
    m_value = 0;
    m_unit  = "m";
}

//-------------------------------------------------------------------------
Step::Step(const Step& _step) : QObject()
{
    m_value = _step.m_value;
    m_unit  = _step.m_unit;
}

//-------------------------------------------------------------------------
Step& Step::operator= (const Step& _step)
{
    m_value = _step.m_value;
    m_unit  = _step.m_unit;

    return (*this);
}

//-------------------------------------------------------------------------
bool Step::Parse (const QJsonObject& _json, Step& _step)
{
    // ---- parse unit ----
    if (_json.contains("unit") && _json["unit"].isString())
    {
        _step.m_unit = _json["unit"].toString();
    }
    else
    {
        qWarning("Unable to find 'kind' attribute in 'Step' element");
        return false;
    }

    // ---- parse value ----
    if (_json.contains("value") && _json["value"].isDouble())
    {
        _step.setValue(static_cast<quint16>(_json["value"].toInt(0)));
    }
    else
    {
        qWarning("Unable to find 'value' attribute in 'Step' element");
        return false;
    }

    // ---- parse info ----
    if (_json.contains("info") && _json["info"].isString())
    {
        _step.setInfo(_json["info"].toString());
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
    return true;
}

//-------------------------------------------------------------------------
void Step::jsonify (QJsonObject& _jsonObject) const
{
    _jsonObject["unit"]=m_unit;
    _jsonObject["value"]=m_value;
    _jsonObject["info"]=m_info;
    _jsonObject["rest"]=false;
}

//-------------------------------------------------------------------------
void Step::setUnit(const QString& _unit)
{
    if (m_unit != _unit)
    {
        m_unit = _unit;
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
QString Step::unit() const
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
