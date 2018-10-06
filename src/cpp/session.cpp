#include "session.h"
#include <QJsonArray>

//--------------------------------------------------------------------------------
Session::Session(QObject* _parent)
    : QObject(_parent)
{
    m_hasWarmUp   = false;
    m_hasCoolDown = false;
}

//--------------------------------------------------------------------------------
Session::Session(const Session& _session) : QObject()
{
    m_name = _session.m_name;
    m_description = _session.m_description;
    m_steps = _session.m_steps;

    m_hasWarmUp = _session.m_hasWarmUp;
    if (m_hasWarmUp) {
        m_warmUp = _session.m_warmUp;
    }

    m_hasCoolDown = _session.m_hasCoolDown;
    if (m_hasCoolDown) {
        m_coolDown = _session.m_coolDown;
    }
}

//--------------------------------------------------------------------------------
const Session& Session::operator= (const Session& _session)
{
    m_name = _session.m_name;
    m_description = _session.m_description;
    m_steps = _session.m_steps;

    m_hasWarmUp = _session.m_hasWarmUp;
    if (m_hasWarmUp) {
        m_warmUp = _session.m_warmUp;
    }

    m_hasCoolDown = _session.m_hasCoolDown;
    if (m_hasCoolDown) {
        m_coolDown = _session.m_coolDown;
    }

    return (*this);
}

//--------------------------------------------------------------------------------
bool Session::Parse (const QJsonObject& _json, Session& _session)
{
    Session l_session;

    // ---- parse session info ----

    if (_json.contains("name") && _json["name"].isString())
    {
        l_session.setName(_json["name"].toString());
    }
    else
    {
        qWarning("Unable to find 'name' attribute in 'session' element");
        return false;
    }

    if (_json.contains("description") && _json["description"].isString())
    {
        l_session.setDescription(_json["description"].toString());
    }
    else
    {
        qWarning("Unable to find 'description' attribute in 'session' element");
        return false;
    }

    // ---- parse session steps----
    if (_json.contains("steps") && _json["steps"].isArray())
    {
        QJsonArray       l_jsonStepsArray = _json["steps"].toArray();
        StepVector       l_stepVector;
        Step             l_step;

        l_stepVector.clear();
        l_stepVector.reserve(l_jsonStepsArray.size());

        for (int i = 0; i < l_jsonStepsArray.size(); ++i) {
            QJsonObject l_jsonStep = l_jsonStepsArray[i].toObject();

            if (Step::Parse(l_jsonStep, l_step)) {
                l_stepVector.append(l_step);
            }
            else {
                return false;
            }
         }

        l_session.setSteps(l_stepVector);
    }
    else
    {
        qWarning("Unable to find 'steps' array in 'session' element");
        return false;
    }

    qDebug("Session successfully loaded!");
    _session = l_session;
    return true;
}

//--------------------------------------------------------------------------------
void Session::setName(const QString& _name)
{
    if (m_name != _name)
    {
        m_name = _name;
        emit nameChanged();
    }
}

//--------------------------------------------------------------------------------
void Session::setDescription(const QString& _description)
{
    if (m_description != _description)
    {
        m_description = _description;
        emit descriptionChanged();
    }
}

//--------------------------------------------------------------------------------
void Session::setSteps (const StepVector& _steps)
{
    m_steps = _steps;
}

//--------------------------------------------------------------------------------
QString Session::name()
{
    return m_name;
}

//--------------------------------------------------------------------------------
QString Session::description()
{
    return m_description;
}
