#include "tablemodule.h"
#include "QtCore/qitemselectionmodel.h"
#include <QFile>
#include <QItemSelectionModel>
#include <Qmap>

TableModule::TableModule(QObject *parent)
    : QAbstractTableModel(parent)
{
}

bool TableModule::reloadDataFromFile(const QString& path)
{

    QList<QList<QString>> newData;
    pathToFile = path;
    QFile inputFile(path);
    if (!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return false;
    }
    QTextStream inputStream(&inputFile);
    QString firstline = inputStream.readLine();
    head = firstline.split(',');

    while (!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QString> dataRow;
        for (QString& item: line.split(","))
            dataRow.append(item);
        newData.append(dataRow);
        ages.insert(dataRow.at(3));
        teams.insert(dataRow.at(2));
        gamesplayed.insert(dataRow.at(11));
        points.insert(dataRow.at(12));
        rebounds.insert(dataRow.at(13));
        assists.insert(dataRow.at(14));
        seasons.insert(dataRow.at(16));
        names.insert(dataRow.at(1));
    }
    inputFile.close();

    beginResetModel();
    dataTable = newData;
    endResetModel();
    return true;
}
int TableModule::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataTable.count();
}

int TableModule::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataTable[0].count();
}

QVariant TableModule::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        try
        {
            if (index.column() == 0 || index.column() == 17)
                return dataTable[index.row()][index.column()].toInt();
            return QVariant(dataTable[index.row()][index.column()]);
        }
        catch (...)
        {
            return QVariant();
        }
    }
    return QVariant();
}

bool TableModule::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value)
    {
        if (index.column() != 0)
        {
            dataTable[index.row()][index.column()] = value.toString();
            emit dataChanged(index, index, {role});
            return true;
        }
    }
    return false;
}

Qt::ItemFlags TableModule::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

TableModule::~TableModule()
{
    qDebug()<< "destructor";
    QFile inputFile("/Users/polinagalisnikova/Downloads/dataset_finalnew.csv");
    inputFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&inputFile);
    for (size_t i = 0; i < head.size(); ++i)
    {
        if (i != head.size() - 1)
        {
            out << head[i] << ',';
        }
        else
        {
            out << head[i];
        }
    }
    out << '\n';
    for (const QList<QString>& x: dataTable)
    {
        for (size_t i = 0; i < x.size(); ++i)
        {
            if (i != x.size() - 1)
                out << x[i] << ',';
            else
                out << x[i];
        }
        out << '\n';
    }
    inputFile.close();

}

QVariant TableModule::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
            return head[section];
        else if (orientation == Qt::Vertical)
            return dataTable[section][0];
    }
    return QVariant();
}

bool TableModule::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role))
    {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}



void TableModule::appendRow(const QList<QString>& data)
{
    beginInsertRows(QModelIndex(), dataTable.size(), dataTable.size());
    dataTable.append(data);
    endInsertRows();
}

bool TableModule::removeRow(int rowIndex)
{
    if (rowIndex >= dataTable.size())
    {
        return false;
    }
    beginRemoveRows(QModelIndex(), rowIndex, rowIndex);
    dataTable.removeAt(rowIndex);
    endRemoveRows();
    return true;
}


QList<QString> TableModule::operator[](int index)
{
    return dataTable[index];
}

QList<QString> TableModule::getAgesList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{ages.begin(),ages.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getTeamList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{teams.begin(),teams.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getGamesPlayedList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{gamesplayed.begin(),gamesplayed.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getPointsList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{points.begin(),points.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getReboundsList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{rebounds.begin(), rebounds.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getAssistsList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{assists.begin(), assists.end()})
        list << v;
    return list;
}

QList<QString> TableModule::getSeasonsList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{seasons.begin(), seasons.end()})
        list << v;
    return list;
}


//bool TableModule::reloadDataFromFile(const QString& path)
//{

//    QList<QList<QString>> newData;

//    QFile inputFile(path);
//    if (!inputFile.open(QFile::ReadOnly | QFile::Text))
//    {
//        return false;
//    }
//    QTextStream inputStream(&inputFile);

//    // header
//    QString firstline = inputStream.readLine();
//    // _header = firstline.split(",");

//    while (!inputStream.atEnd())
//    {
//        QString line = inputStream.readLine();

//        QList<QString> dataRow;
//        QList<QString> items = line.split(",");
//        for (int i = 0; i < items.size(); ++i)
//        {
//            QString value;
//            if (i == 0)
//            {
//                value = items[i];
//            }
//            else
//            {
//                value = items[i];
//            }

//            dataRow.append(value);
//        }
//        newData.append(dataRow);
//    }
//    inputFile.close();

////    beginResetModel();
////    dataTable = newData;
////    endResetModel();
//    return true;
//}

QString TableModule::findBestTeam()
{
    return dataTable[1][2];
}

QString TableModule::findBestHight()
{
    return dataTable[1][4];
}

QString TableModule::findBestWeight()
{
    return dataTable[1][5];
}

QString TableModule::findBestCountry()
{
    return dataTable[1][7];
}

QList<QString> TableModule::getNamesList()
{
    QList<QString> list;
    list << "All";
    for (const QString& v: QList<QString>{names.begin(), names.end()})
        list << v;
    return list;
}
