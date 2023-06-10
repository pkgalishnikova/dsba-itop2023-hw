#include "comptablemodel.h"

CompTableModel::CompTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int CompTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return compDataTable.count();
}

int CompTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return compDataTable[0].count();
}

QVariant CompTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return compDataTable.at(index.row()).at(index.column());
    return QVariant();
}
