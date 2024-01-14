#include <studentmodel.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StudentModel::StudentModel(QObject *parent) : QAbstractTableModel(parent)
{
    QSqlQuery query("SELECT name, fatherName, motherName FROM student");
    while (query.next()) {
        Student student;
        student.name = query.value(0).toString();
        student.fatherName = query.value(1).toString();
        student.motherName = query.value(2).toString();
        students.append(student);
    }
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return students.size();
}

int StudentModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3; // Three columns: name, fatherName, motherName
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();
    const Student &student = students.at(row);

    switch (role) {
    case Qt::DisplayRole:
        if (col == 0) return student.name;
        if (col == 1) return student.fatherName;
        if (col == 2) return student.motherName;
        break;
    }

    return QVariant();
}

QVariant StudentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        if (section == 0) return "Name";
        if (section == 1) return "Father's Name";
        if (section == 2) return "Mother's Name";
    }

    return QVariant();
}
