#include "delegate.h"
#include <QObject>
#include <QItemDelegate>
#include <QModelIndex>
#include <QSize>
#include <QSpinBox>

Delegate::Delegate(QObject *parent) :QItemDelegate(parent){

}
QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(10);
    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox *box = static_cast<QSpinBox *>(editor);
    box->setValue(value);

}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *box = static_cast<QSpinBox *>(editor);
    box->interpretText();
    model->setData(index,box->value(), Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
