#ifndef STEP_H
#define STEP_H

#include <QtGlobal>
#include <QObject>
#include <QJsonObject>
#include <QVector>
#include "types.h"

/**
 * @brief A step in a session, that can be a distance (in meters) or a duration (in seconds)
 */
class Step : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Kind kind READ kind WRITE setKind NOTIFY kindChanged)
    Q_PROPERTY(quint16 value READ value WRITE setValue NOTIFY valueChanged)

public:
    enum Kind {DISTANCE_STEP, DURATION_STEP};
    Q_ENUM(Kind)

public:
    Step(QObject* _parent = nullptr);
    Step(const Step& _step);
    const Step& operator= (const Step& _step);
    virtual ~Step() {}

    static bool Parse (const QJsonObject& _json, Step& _step);

    void setKind(const Kind& _kind);
    void setValue(const quint16& _value);

    Kind kind();
    quint16 value();

signals:
    void kindChanged();
    void valueChanged();

private:
    Kind       	 m_kind;	/**< the kind of the step */
    quint16      m_value;   /**< the value associated to the step */
};

typedef QVector<Step> StepVector;

#endif // STEP_H
