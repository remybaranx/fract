#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <QJsonObject>
#include "step.h"

/**
 * @brief The Session class
 */
class Session : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name        READ name        WRITE setName        NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool    hasWarmUp   READ hasWarmUp   WRITE enableWarmUp)
    Q_PROPERTY(Step    warmUp      READ warmUp      WRITE setWarmUp)
    Q_PROPERTY(bool    hasCoolDown READ hasCoolDown WRITE enableCoolDown)
    Q_PROPERTY(Step    coolDown    READ coolDown    WRITE setCoolDown)

public:
    Session(QObject* _parent = nullptr);
    Session(const Session& _session);
    const Session& operator= (const Session& _session);
    virtual ~Session() {}

    static bool Parse (const QJsonObject& _json, Session& _session);

    void setName(const QString& _name);
    void setDescription(const QString& _description);

    bool hasCoolDown() {return m_hasCoolDown;}
    void enableCoolDown(bool _enabled) {m_hasCoolDown = _enabled;}
    const Step& coolDown() const {return m_coolDown;}
    void setCoolDown(const Step& _coolDown) {m_coolDown = _coolDown;}

    bool hasWarmUp() {return m_hasWarmUp;}
    void enableWarmUp(bool _enabled) {m_hasWarmUp = _enabled;}
    const Step& warmUp() const {return m_warmUp;}
    void setWarmUp(const Step& _warmUp) {m_warmUp = _warmUp;}

    void setSteps(const StepVector& _steps);

    QString name();
    QString description();

signals:
    void nameChanged();
    void descriptionChanged();

private:
    QString         m_name;
    QString         m_description;
    bool            m_hasWarmUp;
    Step            m_warmUp;
    bool            m_hasCoolDown;
    Step            m_coolDown;
    StepVector      m_steps;
};

typedef QVector<Session> SessionVector;
typedef QMap<QString, Session> SessionsMap;

Q_DECLARE_METATYPE(SessionsMap)

#endif // SESSION_H
