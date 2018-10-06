#include "sessionmodel.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>

//-------------------------------------------------------------------------
bool SessionModel::_parse(const QJsonObject& _json)
{
    //@TODO: delete items
    m_sessions.clear();

    if (_json.contains("sessions") && _json["sessions"].isArray())
    {
        QJsonArray l_jsonSessionArray = _json["sessions"].toArray();

        for (int i = 0; i < l_jsonSessionArray.size(); ++i) {
            QJsonObject l_jsonSession = l_jsonSessionArray[i].toObject();
            Session*    l_session = new Session;

            if (Session::Parse(l_jsonSession, *l_session)) {
                m_sessions.append(l_session);
            }
            else {
                delete l_session;

                //@TODO: delete items
                m_sessions.clear();
                return false;
            }
         }
    }
    else
    {
        qWarning("Unable to find 'sessions' array in the JSON document");
        return false;
    }

    return true;
}

//-------------------------------------------------------------------------
bool SessionModel::load(const QString& _filename)
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
bool SessionModel::save()
{
    qDebug("sessions successfully saved!");
    return true;
}

//-------------------------------------------------------------------------
int SessionModel::rowCount (const QModelIndex&) const
{
    return m_sessions.size();
}

//-------------------------------------------------------------------------
QVariant SessionModel::data (const QModelIndex& _index, int) const
{
    QObject* item = m_sessions.at(_index.row());
    return QVariant::fromValue(item);
}

//-------------------------------------------------------------------------
QHash<int, QByteArray> SessionModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[Qt::UserRole + 1] = "item";
  return roles;
}
