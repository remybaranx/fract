#include "session.h"

#include <QJsonArray>
#include <QDebug>
#include <QTextStream>

//--------------------------------------------------------------------------------
Session::Session(QObject* _parent)
    : QObject(_parent)
{
    m_hasWarmUp   = false;
    m_warmUp      = StepPointer(new Step(this));
    m_hasCoolDown = false;
    m_coolDown    = StepPointer(new Step(this));
}

//--------------------------------------------------------------------------------
Session::Session(const Session& _session) : QObject()
{
    _copy(_session);
}

//--------------------------------------------------------------------------------
Session& Session::operator= (const Session& _session)
{
   _copy(_session);
    return (*this);
}

//--------------------------------------------------------------------------------
Session::~Session()
{
}

//--------------------------------------------------------------------------------
bool Session::Parse (const QJsonObject& _json, Session& _session)
{
    // ---- parse session info ----

    if (_json.contains("name") && _json["name"].isString())
    {
        _session.setName(_json["name"].toString());
        qDebug() << "name: " << _session.m_name;
    }
    else
    {
        qWarning("Unable to find 'name' attribute in 'session' element");
        return false;
    }

    if (_json.contains("description") && _json["description"].isString())
    {
        _session.setDescription(_json["description"].toString());
        qDebug() << "description: " << _session.m_description;
    }
    else
    {
        qWarning("Unable to find 'description' attribute in 'session' element");
        return false;
    }

    // parse warm up
    if (_json.contains("warmup") && _json["warmup"].isObject())
    {
        QJsonObject l_jsonWarmUp = _json["warmup"].toObject();

        if (l_jsonWarmUp.contains("enabled") && l_jsonWarmUp["enabled"].isBool()) {
            _session.enableWarmUp(l_jsonWarmUp["enabled"].toBool());

            // then, parse the internal step
            if (_session.hasWarmUp())
            {
                if (l_jsonWarmUp.contains("step") && l_jsonWarmUp["step"].isObject()) {
                    QJsonObject l_jsonStep = l_jsonWarmUp["step"].toObject();

                    if (!Step::Parse(l_jsonStep, *_session.m_warmUp)) {
                        _session.enableWarmUp(false);
                        qWarning("Unable to parse 'step' attribute in 'warmup' element");
                        return false;
                    }
                }
                else {
                    _session.enableWarmUp(false);
                    qWarning("Unable to find 'step' attribute in 'warmup' element");
                    return false;
                }
            }
        }
        else {
            qWarning("Unable to find 'enabled' attribute in 'warmup' element");
            return false;
        }
    }
    else
    {
        qWarning("Unable to find 'warmup' attribute in 'session' element");
        return false;
    }

    // parse cool down
    if (_json.contains("cooldown") && _json["cooldown"].isObject())
    {
        QJsonObject l_jsonCoolDown = _json["cooldown"].toObject();

        if (l_jsonCoolDown.contains("enabled") && l_jsonCoolDown["enabled"].isBool())
        {
            _session.enableCoolDown(l_jsonCoolDown["enabled"].toBool());

            // then, parse the internal step
            if (_session.hasCoolDown())
            {
                if (l_jsonCoolDown.contains("step") && l_jsonCoolDown["step"].isObject())
                {
                    QJsonObject l_jsonStep = l_jsonCoolDown["step"].toObject();

                    if (!Step::Parse(l_jsonStep, *_session.m_coolDown)) {
                        _session.enableCoolDown(false);
                        qWarning("Unable to parse 'step' attribute in 'cooldown' element");
                        return false;
                    }
                }
                else {
                    _session.enableCoolDown(false);
                    qWarning("Unable to find 'step' attribute in 'cooldown' element");
                    return false;
                }
            }
        }
        else {
            qWarning("Unable to find 'enabled' attribute in 'cooldown' element");
            return false;
        }
    }
    else
    {
        qWarning("Unable to find 'cooldown' attribute in 'session' element");
        return false;
    }

    // ---- parse session steps----
    if (_json.contains("steps") && _json["steps"].isArray())
    {
        QJsonArray       l_jsonStepsArray = _json["steps"].toArray();
        StepVector       l_stepVector;
        Step*            l_step;

        //_session.m_steps.clear();

        for (int i = 0; i < l_jsonStepsArray.size(); ++i) {
            QJsonObject l_jsonStep = l_jsonStepsArray[i].toObject();
            l_step = new Step;

            if (Step::Parse(l_jsonStep, *l_step)) {
                _session.m_steps.append(l_step);
            }
            else {
                delete l_step;
                return false;
            }
         }
    }
    else
    {
        qWarning("Unable to find 'steps' array in 'session' element");
        return false;
    }


    qDebug("Session successfully loaded!");
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
QString Session::name()
{
    return m_name;
}

//--------------------------------------------------------------------------------
QString Session::description()
{
    return m_description;
}

//--------------------------------------------------------------------------------
void Session::_copy(const Session& _session)
{
    m_name        = _session.m_name;
    m_description = _session.m_description;

    //TODO: copy elements not only the list
    m_steps       = _session.m_steps;

    m_hasWarmUp = _session.m_hasWarmUp;
    m_warmUp    = _session.m_warmUp;

    m_hasCoolDown = _session.m_hasCoolDown;
    m_coolDown    = _session.m_coolDown;
}

//--------------------------------------------------------------------------------
void Session::jsonify (QJsonObject& _jsonObject) const
{
    QJsonObject l_jsonStep;

    // session information
    _jsonObject["name"]=m_name;
    _jsonObject["description"]=m_description;

    // warm up information
    QJsonObject l_warmUpStep;

    m_warmUp->jsonify(l_jsonStep);

    l_warmUpStep["enabled"]=m_hasWarmUp;
    l_warmUpStep["step"]=l_jsonStep;

    _jsonObject["warmup"]=l_warmUpStep;

    // cool down information
    QJsonObject l_coolDownStep;

    m_coolDown->jsonify(l_jsonStep);

    l_coolDownStep["enabled"]=m_hasCoolDown;
    l_coolDownStep["step"]=l_jsonStep;

    _jsonObject["cooldown"]=l_coolDownStep;

    // steps information
    QJsonArray l_jsonSteps;

    foreach (const QObject* l_object, m_steps)
    {
        const Step* l_step = qobject_cast<const Step*>(l_object);
        l_step->jsonify(l_jsonStep);

        l_jsonSteps.append(l_jsonStep);
    }
    _jsonObject["steps"]=l_jsonSteps;
}


