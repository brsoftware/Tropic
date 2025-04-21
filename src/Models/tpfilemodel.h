#ifndef TPFILEMODEL_H
#define TPFILEMODEL_H

#include <QFileSystemModel>

#include <TpGlobals>

TP_NAMESPACE

class TpFileModel : public QFileSystemModel
{
    Q_OBJECT

public:
    TpFileModel(QObject *parent = nullptr);
};

TP_END_NAMESPACE

#endif // TPFILEMODEL_H
