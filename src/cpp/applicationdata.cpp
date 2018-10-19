#include "applicationdata.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>

//-------------------------------------------------------------------------
ApplicationData::ApplicationData(QObject* _parent) : QObject (_parent)
{
}

//-------------------------------------------------------------------------
bool ApplicationData::_parse(const QJsonObject& _json)
{
    //clean the current session model
    _cleanSessions();

    if (_json.contains("sessions") && _json["sessions"].isArray())
    {
        QJsonArray l_jsonSessionArray = _json["sessions"].toArray();

        for (int i = 0; i < l_jsonSessionArray.size(); ++i) {
            QJsonObject l_jsonSession = l_jsonSessionArray[i].toObject();
            Session*    l_session = new Session;

            if (Session::Parse(l_jsonSession, *l_session)) {

                m_sessions.append(static_cast<QObject*>(l_session));
            }
            else {
                //clean the current session model in case of parsing error
                _cleanSessions();
                return false;
            }
         }
    }
    else
    {
        qWarning("Unable to find 'sessions' array in the JSON document");
        return false;
    }

    emit sessionsChanged();
    return true;
}

//-------------------------------------------------------------------------
bool ApplicationData::loadSessions(const QString& _filename)
{
    QFile l_loadFile(_filename);

    // open the JSON file
    if (!l_loadFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Unable to load the file");
        return false;
    }

    m_filename = _filename;

    // read it as a byte array and build a JSON document
    QByteArray l_loadData = l_loadFile.readAll();
    QJsonDocument l_loadDoc(QJsonDocument::fromJson(l_loadData));

    // parse the JSON document
    return _parse(l_loadDoc.object());
}

//-------------------------------------------------------------------------
bool ApplicationData::saveSessions()
{
    QFile   l_file(m_filename);

    // open the JSON file
    if (!l_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning() << "Unable to open the file '" << m_filename << "'";
        return false;
    }

    // generate the JSON tree
    QJsonObject l_rootObject;
    QJsonArray  l_jsonSessions;

    foreach (const QObject* l_object, m_sessions)
    {
        QJsonObject     l_jsonSession;
        const Session*  l_session = qobject_cast<const Session*>(l_object);

        l_session->jsonify(l_jsonSession);
        l_jsonSessions.append(l_jsonSession);
    }

    l_rootObject["sessions"]=l_jsonSessions;

    // create the document and save it
    QJsonDocument l_document(l_rootObject);
    l_file.write(l_document.toJson());

    qDebug("sessions successfully saved!");

    emit sessionsChanged();
    return true;
}

//-------------------------------------------------------------------------
void ApplicationData::_cleanSessions()
{
    while(!m_sessions.isEmpty())
    {
        if (m_sessions.last()) {
            delete m_sessions.last();
        }
        m_sessions.removeLast();
    }
}

//-------------------------------------------------------------------------
void ApplicationData::addSession(Session* _session)
{
    m_sessions.append(qobject_cast<QObject*>(_session));
}

//-------------------------------------------------------------------------
void ApplicationData::removeSession(int _index)
{
    m_sessions.removeAt(_index);
}
