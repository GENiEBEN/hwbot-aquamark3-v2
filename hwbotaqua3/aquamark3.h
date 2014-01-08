#ifndef AQUAMARK3_H
#define AQUAMARK3_H

#include <QApplication>

extern bool _clearmydocs();
extern bool Aquamark3_WriteLicenseFile();
extern bool Aquamark3_WriteConfigFile();
extern QStringList Aquamark3_ReadScore(QString File);
extern QStringList Aquamark3_ReadChapters(QString File);
bool Aquamark3_RanAtDefaultSettings(QString File);



#endif // AQUAMARK3_H
