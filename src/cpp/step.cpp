#include "Step.h"

//-------------------------------------------------------------------------
Step::Step(QObject* _parent) : QObject(_parent)
{
    m_value = 0;
    m_kind  = DISTANCE_STEP;
}


//-------------------------------------------------------------------------
Step::Step(const Step& _step)
{
    m_value = _step.m_value;
    m_kind  = _step.m_kind;
}

//-------------------------------------------------------------------------
const Step& Step::operator= (const Step& _step)
{
    m_value = _step.m_value;
    m_kind  = _step.m_kind;

    return (*this);
}

//-------------------------------------------------------------------------
bool Step::Parse (const QJsonObject& _json, Step& _step)
{
    Step  l_step;

    // ---- parse kind ----

    if (_json.contains("kind") && _json["kind"].isString())
    {
        QString l_kindStr = _json["kind"].toString();

        if (l_kindStr == "duration")
        {
            l_step.setKind(DURATION_STEP);
        }
        else if (l_kindStr == "distance")
        {
            l_step.setKind(DISTANCE_STEP);
        }
        else
        {
            qWarning("Invalid 'kind' value in 'Step' element");
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
void Step::setKind(const Kind& _kind)
{
    if (m_kind != _kind)
    {
        m_kind = _kind;
        emit kindChanged();
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
Step::Kind Step::kind()
{
    return m_kind;
}

//-------------------------------------------------------------------------
quint16 Step::value()
{
    return m_value;
}
