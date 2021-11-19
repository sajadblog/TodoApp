#include "TodoModel.h"

#include <QColor>
#include <QDebug>

TodoModel::TodoModel(QObject *parent) : QAbstractListModel(parent)
{
    m_dataContainer.append({eTodoPriority::medium,false,"test to od item", "white"});
    m_dataContainer.append({eTodoPriority::none,true,"item2", "#d3d3d3"});
    m_dataContainer.append({eTodoPriority::low,false,"lorem ipsum", "#90ee90"});
}

QHash<int, QByteArray> TodoModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[eFieldRoles::PriorityRole] = "priority";
    roles[eFieldRoles::completedRole] = "completed";
    roles[eFieldRoles::DescriptionRole] = "description";
    roles[eFieldRoles::BackgroundRole] = "background";
    return roles;
}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    return m_dataContainer.size();
}

void TodoModel::removeItem(int rowIndex)
{
    beginRemoveRows(QModelIndex(),rowIndex,rowIndex);
    m_dataContainer.removeAt(rowIndex);
    endRemoveRows();
}

void TodoModel::addItem(QString description)
{
    beginInsertRows(QModelIndex(), m_dataContainer.size(),m_dataContainer.size());
    m_dataContainer.push_back({.description = description});
    endInsertRows();
}

void TodoModel::updateBackground(int rowIndex, QString color)
{
    m_dataContainer[rowIndex].backgroundColor = color;
    beginResetModel();
    endResetModel();
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    if(index.row() >= m_dataContainer.size()) return QVariant();
    if(!index.isValid()) return QVariant();

    switch (eFieldRoles(role)) {
    case eFieldRoles::PriorityRole      :  return static_cast<int>(m_dataContainer[index.row()].priority);
    case eFieldRoles::completedRole     :  return m_dataContainer[index.row()].completed ;
    case eFieldRoles::DescriptionRole   :  return m_dataContainer[index.row()].description;
    case eFieldRoles::BackgroundRole    :  return m_dataContainer[index.row()].backgroundColor;
    }
    return QVariant();
}

bool TodoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() >= m_dataContainer.size()) return false;
    if(!index.isValid()) return false;

    switch (eFieldRoles(role)) {
    case eFieldRoles::PriorityRole      :  m_dataContainer[index.row()].priority = eTodoPriority(value.toInt()); break;
    case eFieldRoles::completedRole     :  m_dataContainer[index.row()].completed = value.toBool();break;
    case eFieldRoles::DescriptionRole   :  m_dataContainer[index.row()].description = value.toString();break;
    case eFieldRoles::BackgroundRole    :  m_dataContainer[index.row()].backgroundColor = value.toString();break;
    }
    return true;
}

FilterTodoModel::FilterTodoModel(QObject *parent):
    QSortFilterProxyModel(parent)
{
    setSourceModel(&m_todoModel);
}

bool FilterTodoModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if(m_filterList.isEmpty()) return true;
    foreach(const QString &filter , m_filterList)
    {
        if(m_todoModel.m_dataContainer[sourceRow].description.contains(filter, Qt::CaseInsensitive)) {
            return true;
        }
    }
    return false;
}

void FilterTodoModel::setFilters(QString filters)
{
    m_filterList.clear();
    foreach(const QString &filter , filters.split(' '))
    {
        if(!filter.isEmpty())
            m_filterList.append(filter);
    }

    m_todoModel.beginResetModel();
    m_todoModel.endResetModel();
}

TodoModel *FilterTodoModel::getModel()
{
    return &m_todoModel;
}
