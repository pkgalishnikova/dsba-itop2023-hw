#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject *parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    void setAgeTargetField(const QString& field);
    void setTeamTargetField(const QString& field);
    void setGamesPlayedTargetField(const QString& field);
    void setPointsTargetField(const QString& field);
    void setReboundsTargetField(const QString& field);
    void setAssistsTargetField(const QString& field);
    void setSeasonTargetField(const QString& field);
    void setSearchTargetField(const QString& field);
private:
    QString targetAgeField, targetTeamField, targetGamesPlayedField, targetPointsField, targetReboundField, targetAssistField, targetSeasonField, targetSearchField;
};

#endif // PROXYMODEL_H
