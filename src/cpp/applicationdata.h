#ifndef APP_DATA_H
#define APP_DATA_H

#include "sessionmodel.h"

class ApplicationData : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QStringList sessionNames READ sessionNames)

public:
    ApplicationData (QObject* _parent = nullptr);
    ~ApplicationData() {}

    bool load(const QString& _sessionFilename);

    const QStringList& sessionNames() {return m_sessionNames;}

private:
    SessionModel m_sessionModel;
    QStringList  m_sessionNames;
};

#endif //APP_DATA_H

