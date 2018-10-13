#ifndef STEP_H
#define STEP_H

#include <QtGlobal>
#include <QObject>
#include <QJsonObject>
#include <QVector>

/**
 * @brief A step in a session, that can be a distance (in meters) or a duration (in seconds)
 */
class Step : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Unit    unit  READ unit  WRITE setUnit  NOTIFY unitChanged)
    Q_PROPERTY(quint16 value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString info  READ info  WRITE setInfo  NOTIFY infoChanged)

public:
    enum Unit {DISTANCE_IN_M, DISTANCE_IN_KM, DURATION_IN_SEC, DURATION_IN_MIN};
    Q_ENUM(Unit)

public:
    Step(QObject* _parent = nullptr);
    Step(const Step& _step);
    const Step& operator= (const Step& _step);
    virtual ~Step() {}

    static bool Parse (const QJsonObject& _json, Step& _step);

    void setUnit(const Unit& _unit);
    void setValue(const quint16& _value);
    void setInfo(const QString& _info);

    Unit unit() const;
    quint16 value() const;
    QString info() const;

signals:
    void unitChanged();
    void valueChanged();
    void infoChanged();

private:
    Unit         m_unit;	/**< the unit of the step */
    quint16      m_value;   /**< the value associated to the step */
    QString      m_info;    /**< */
};

typedef QVector<Step> StepVector;

#endif // STEP_H
