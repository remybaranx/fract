#ifndef SESSIONMODEL_H
#define SESSIONMODEL_H

#include <QAbstractListModel>
#include <QJsonObject>

#include "session.h"

class SessionModel : public QAbstractListModel
{
    Q_OBJECT

public:
    bool load(const QString& _filename);
    bool save();

    int      rowCount (const QModelIndex&) const override;
    QVariant data     (const QModelIndex& _index, int _role) const override;

protected:
  QHash<int, QByteArray> roleNames() const override;

private:
    bool _parse(const QJsonObject& _json);

private:
    QList<QObject*> m_sessions;
    QString         m_filename;
};

#endif // SESSIONMODEL_H
