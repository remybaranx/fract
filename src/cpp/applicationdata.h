#ifndef SESSIONMODEL_H
#define SESSIONMODEL_H

#include <QAbstractItemModel>
#include <QJsonObject>

#include "session.h"

class ApplicationData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> sessions READ sessions NOTIFY sessionsChanged)
    Q_DISABLE_COPY(ApplicationData)

public:
    explicit ApplicationData(QObject* _parent = Q_NULLPTR);

    bool loadSessions(const QString& _filename);

    Q_INVOKABLE bool saveSessions();

    Q_INVOKABLE Session* createSession() {return new Session;}
    Q_INVOKABLE void addSession(Session* _session);
    Q_INVOKABLE void removeSession(int _index);

    QList<QObject*> sessions() const {return m_sessions;}

signals:
    void sessionsChanged();

private:
    bool _parse(const QJsonObject& _json);
    void _cleanSessions();

    QString             m_filename;
    QList<QObject*>     m_sessions;
};

#endif // SESSIONMODEL_H
