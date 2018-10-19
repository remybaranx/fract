#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <QJsonObject>
#include <QSharedPointer>

#include "step.h"

/**
 * @brief The Session class
 */
class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString          name        READ name        WRITE setName        NOTIFY nameChanged)
    Q_PROPERTY(QString          description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool             hasWarmUp   READ hasWarmUp   WRITE enableWarmUp)
    Q_PROPERTY(Step*            warmUp      READ warmUp)
    Q_PROPERTY(bool             hasCoolDown READ hasCoolDown WRITE enableCoolDown)
    Q_PROPERTY(Step*            coolDown    READ coolDown)
    Q_PROPERTY(QList<QObject*>  steps       READ steps)

public:
    Session(QObject* _parent = nullptr);
    Session(const Session& _session);
    Session& operator= (const Session& _session);
    virtual ~Session();

    static bool    Parse   (const QJsonObject& _json, Session& _session);

    void jsonify (QJsonObject& _jsonObject) const;

    void setName(const QString& _name);
    void setDescription(const QString& _description);

    bool hasCoolDown() {return m_hasCoolDown;}
    void enableCoolDown(bool _enabled) {m_hasCoolDown = _enabled;}
    Step* coolDown() const {return m_coolDown.data();}

    bool hasWarmUp() {return m_hasWarmUp;}
    void enableWarmUp(bool _enabled) {m_hasWarmUp = _enabled;}
    Step* warmUp() const {return m_warmUp.data();}

    QList<QObject*> steps() const {return m_steps;}

    QString name();
    QString description();

signals:
    void nameChanged();
    void descriptionChanged();

private:
    void _copy(const Session& _session);

private:
    QString                 m_name;
    QString                 m_description;
    bool                    m_hasWarmUp;
    StepPointer             m_warmUp;
    bool                    m_hasCoolDown;
    StepPointer             m_coolDown;
    QList<QObject*>         m_steps;
};

#endif // SESSION_H
