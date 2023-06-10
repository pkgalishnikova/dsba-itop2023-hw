#include "proxymodel.h"

ProxyModel::ProxyModel(QObject *parent): QSortFilterProxyModel(parent)
{

}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel() -> headerData(section, orientation, role);
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex age = sourceModel()->index(source_row, 3, source_parent);
    if (targetAgeField != sourceModel()->data(age).toString() && targetAgeField != "All")
        return false;

    QModelIndex team = sourceModel()->index(source_row, 2, source_parent);
    if (targetTeamField != sourceModel()->data(team).toString() && targetTeamField != "All")
        return false;

    QModelIndex games = sourceModel()->index(source_row, 11, source_parent);
    if (targetGamesPlayedField != sourceModel()->data(games).toString() && targetGamesPlayedField != "All")
        return false;

    QModelIndex point = sourceModel()->index(source_row, 12, source_parent);
    if (targetPointsField != sourceModel()->data(point).toString() && targetPointsField != "All")
        return false;

    QModelIndex rebound = sourceModel()->index(source_row, 13, source_parent);
    if (targetReboundField != sourceModel()->data(rebound).toString() && targetReboundField != "All")
        return false;

    QModelIndex assist = sourceModel()->index(source_row, 14, source_parent);
    if (targetAssistField != sourceModel()->data(assist).toString() && targetAssistField != "All")
        return false;

    QModelIndex season = sourceModel()->index(source_row, 16, source_parent);
    if (targetSeasonField != sourceModel()->data(season).toString() && targetSeasonField != "All")
        return false;
    return true;
}

void ProxyModel::setAgeTargetField(const QString& field)
{
    targetAgeField = field;
    invalidateFilter();
}

void ProxyModel::setTeamTargetField(const QString& field)
{
    targetTeamField = field;
    invalidateFilter();
}

void ProxyModel::setGamesPlayedTargetField(const QString& field)
{
    targetGamesPlayedField = field;
    invalidateFilter();
}

void ProxyModel::setPointsTargetField(const QString& field)
{
    targetPointsField = field;
    invalidateFilter();
}

void ProxyModel::setReboundsTargetField(const QString& field)
{
    targetReboundField = field;
    invalidateFilter();
}

void ProxyModel::setAssistsTargetField(const QString& field)
{
    targetAssistField = field;
    invalidateFilter();
}

void ProxyModel::setSeasonTargetField(const QString& field)
{
    targetSeasonField = field;
    invalidateFilter();
}

void ProxyModel::setSearchTargetField(const QString& field)
{
    targetSearchField = field;
    invalidateFilter();
}
