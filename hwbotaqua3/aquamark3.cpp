#include <QApplication>
#include <QTextStream>
#include <QDir>
#include <QFile>
#include "gui.h"
#include "functions.h"

bool _clearmydocs(){
    //Delete and recreate MyDocuments\Aquamark3 folder
    QDir mydocs; mydocs.setPath(qApp->property("Benchmark_My_Docs_Folder").toString());
    QDir benchpath; benchpath.setPath(qApp->property("Benchmark_Install_Path").toString());
    mydocs.removeRecursively(); WriteLog("mydocs removed:" + mydocs.absolutePath() );
    if (!mydocs.exists()) {
        mydocs.mkpath(".");
        WriteLog("mydocs created: " + mydocs.absolutePath() );
        return true;
    } else {
        return false;
    }
}

bool Aquamark3_WriteLicenseFile(){
    QDir mydocs; mydocs.setPath(qApp->property("Benchmark_My_Docs_Folder").toString());
    QFile outfile( mydocs.absolutePath() + "/License.txt" );
    if ( outfile.open(QIODevice::ReadWrite) ){
        QTextStream stream( &outfile );
        stream << "[AquaMark3License]\n\t{\n\t\tLicenseType = \"Commercial Plus\"\n\t\tUserID = \"John Urbanic (dhiltonmd@aol.com)\"\n\t\tKey = \"JU7R-T7GY-UYM3-JH4K-X4E6-S8F9-N7C5-XWUE-H3TU\"\n\t}" << endl;
    }
    outfile.close();
    return outfile.exists();
}

bool Aquamark3_WriteConfigFile(){
    QDir mydocs; mydocs.setPath(qApp->property("Benchmark_My_Docs_Folder").toString());
    QFile outfile( mydocs.absolutePath() + "/Run.txt" );
    if ( outfile.open(QIODevice::ReadWrite) ){
        QTextStream stream( &outfile );
        stream << "EnableSound=0\nDepth=32\nResolution=1024x768\nAntialiasingMode=0\nAntialiasingQuality=0\nAnisotropy=4\nDetail=4" << endl;
    }
    outfile.close();
    return outfile.exists();
}

QStringList Aquamark3_ReadScore(QString File){
    QString foo; int fooloop = 0;QStringList foolist; QStringList result;
    QFile inputFile(File);
    if (inputFile.exists()){
        if (inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while ( !in.atEnd() ){
                if (fooloop > 31 ){ foo = in.readLine(); }
                fooloop += 1;
            }
            inputFile.close();
        }
        foolist = foo.split( 0x09 );//split by TAB delimiter.
        result << QString::number(round(foolist.at(1).toDouble() * 1000));
        result << QString::number(round(foolist.at(4).toDouble() * 100));
        result << QString::number(round(foolist.at(5).toDouble() * 50));
    } else {
        result << 0;
    }
    return result;
}

QStringList Aquamark3_ReadChapters(QString File){
    QString foo; int fooloop = 0;QStringList foolist; QStringList result;
    QFile inputFile(File);
    if (inputFile.exists()){
        if (inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            while ( !in.atEnd() ){
                foo = in.readLine();
                if (fooloop==27){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==28){
                    foolist=foo.split(0x09);
                    result <<  QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==29){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==30){
                    foolist=foo.split(0x09);
                    result <<  QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==31){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==32){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==33){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==34){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                if (fooloop==35){
                    foolist=foo.split(0x09);
                    result << QString::number(foolist.at(3).toDouble());
                }
                fooloop +=1 ;
            }
            inputFile.close();
        }
    } else {
        result << 0;
    }
    return result;
}

bool Aquamark3_RanAtDefaultSettings(QString File){
    int result=0; QString foo;

    QFile benchconfig(File);
    if (benchconfig.exists()){
        if (benchconfig.open(QIODevice::ReadOnly)){
            QTextStream in(&benchconfig);
            while ( !in.atEnd() ){
                foo = in.readLine();
                if ( foo.contains("DisplayWidth\t1024") ){ result += 1;}
                if ( foo.contains("DisplayHeight\t768") ){ result += 1;}
                if ( foo.contains("DisplayDepth\t32") ){ result += 1;}
                if ( foo.contains("AntialiasingMode\t0") ){ result += 1;}
                if ( foo.contains("AntialiasingQuality\t1") ){ result += 1;}
                if ( foo.contains("AnisotropicFiltering\t4") ){ result += 1;}
                if ( foo.contains("DetailLevel\t5") ){ result += 1;}
                if ( foo.contains("EnableSound\t0") ){ result += 1;}
            }
            benchconfig.close();
        } else { WriteLog("eror reading details file"); }
    } else {
        WriteLog("could not find details file");
    }
    if (result==8){ return true; } else { return false; }
}
