#ifndef SESSIONMODEL_H
#define SESSIONMODEL_H

#include <QAbstractItemModel>
#include <QJsonObject>

#include "session.h"

class ApplicationData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> sessions READ sessions)
    Q_DISABLE_COPY(ApplicationData)

public:
    explicit ApplicationData(QObject* _parent = Q_NULLPTR);

    bool loadSessions(const QString& _filename);
    bool saveSessions();

    QList<QObject*> sessions() const {return m_sessions;}

private:
    bool _parse(const QJsonObject& _json);

    QString             m_filename;
    QList<QObject*>     m_sessions;
};

#endif // SESSIONMODEL_H
