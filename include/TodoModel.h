#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "Structs.h"

class TodoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum eFieldRoles : uint16_t{
        PriorityRole = Qt::UserRole + 1,
        completedRole,
        DescriptionRole,
        BackgroundRole
        };

    explicit TodoModel(QObject *parent = nullptr);
    QHash<int, QByteArray> roleNames() const ;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

public slots:
    void removeItem(int rowIndex);
    void addItem(QString description);
    void updateBackground(int rowIndex ,QString color);
private :
    QVector<sTodoInfo> m_dataContainer;
};

#endif // TODOMODEL_H
