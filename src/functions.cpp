#include <QApplication>
#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <QList>
#include <QSettings>
#include "math.h"
#include <iostream>
#include <windows.h>


QStringList applog;

double round(double d){
    return floor(d + 0.5);
}

void WriteLog(QString text){
    //Create value to write
    QSettings SI("GENiEBEN","SystemInfo");

    applog << QString("[%1] %2 \n").arg(SI.value("OS_TimeStamp").toString()).arg(text);
    //Delete existing log files
    QFile outfile(QString("log.txt"));
    if( outfile.exists() ){ outfile.remove(); }
    //Create new log file and output value
    if( outfile.open(QFile::WriteOnly | QFile::Text) ){
      QTextStream stream(&outfile);
      for (int i = 0; i < applog.size(); ++i){
          stream << applog.at(i);
      }
    }
    outfile.close();
}

