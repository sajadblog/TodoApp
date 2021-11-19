#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>
#include <QSortFilterProxyModel>
#include <QVector>
#include "Structs.h"

namespace Todo {
class TodoModel : public QAbstractListModel
{
    Q_OBJECT
    friend class FilterTodoModel;
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

class FilterTodoModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(TodoModel* model READ getModel)
public:
    FilterTodoModel(QObject *parent = nullptr);
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

public slots:
    void setFilters(QString filters);
    TodoModel *getModel() ;
    void saveToFile();
    void loadFromFile();

private :
    TodoModel m_todoModel;
    QStringList m_filterList{};
};
}
#endif // TODOMODEL_H
