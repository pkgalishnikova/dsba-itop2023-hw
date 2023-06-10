#ifndef TABLEMODULE_H
#define TABLEMODULE_H

#include <QAbstractTableModel>

class TableModule : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableModule(QObject *parent = nullptr);
    ~TableModule();
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool reloadDataFromFile(const QString& path);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    void appendRow(const QList<QString>& data);
    bool removeRow(int rowIndex);
    QList<QString> operator[](int index);
    QList<QString> getAgesList();
    QList<QString> getTeamList();
    QList<QString> getGamesPlayedList();
    QList<QString> getPointsList();
    QList<QString> getReboundsList();
    QList<QString> getAssistsList();
    QList<QString> getSeasonsList();
    QList<QString> getNamesList();
//    void setSelectionModel(Qt::ItemSelectionMode *selectionModel);
    QString findBestTeam();
    QString findBestHight();
    QString findBestWeight();
    QString findBestCountry();

private:
    QList<QList<QString>> dataTable;
//    QString header, buffer;
    QList<QString> head;
    QString pathToFile, headAdd;
    QSet<QString> ages, names, teams, gamesplayed, points, rebounds, assists, seasons;
};
#endif // TABLEMODULE_H
