#ifndef COMPTABLEMODEL_H
#define COMPTABLEMODEL_H

#include <QAbstractTableModel>

class CompTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CompTableModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QList<QVariant>> compDataTable;
};

#endif // COMPTABLEMODEL_H
