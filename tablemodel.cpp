#include "tablemodel.h"

TableModel::TableModel(QObject *parent): QAbstractTableModel(parent)
{
}


void TableModel::setTableName(const QString &tableName)
{
    name = tableName;
}

void TableModel::setData(const QVector<QVector<QVariant>> &tableData)
{
    if (tableData.empty())
    {
        clear();
    }
    else
    {
        tData = tableData;
        emit dataChanged(createIndex(0, 0), createIndex(tData.count(), header.count()));
    }
}

void TableModel::setHeaderData(const QStringList& tableHeader)
{
    if (tableHeader.empty())
    {
    }
    {
        header = tableHeader;
        emit headerDataChanged(Qt::Horizontal,0,header.count());
    }
}

void TableModel::clear()
{
    beginResetModel();
    tData.clear();
    endResetModel();
}

void TableModel::setTypes(const QVector<QString>& tableTypes)
{
    types = tableTypes;
}

QString TableModel::getTableName()
{
    return name;
}

QVector<QVector<QVariant>> TableModel::getData()
{
    return tData;
}

QStringList TableModel::getHeader()
{
    return header;
}

QVector<QString> TableModel::getTypes()
{
    return types;
}

int TableModel::rowCount(const QModelIndex&) const
{
    return tData.count();
}

int TableModel::columnCount(const QModelIndex&) const
{
    return tData.at(0).count();
}


QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (tData.empty())
        {
            return QVariant();
        }
        return tData.at(index.row()).at(index.column());
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal && section < header.count())
    {
        return QVariant(header.at(section));
    }
    return QVariant();
}