#include <QApplication>
#include <QProcess>
#include <QStringList>
#include <QFile>
#include <QDomDocument>
#include <QDomNodeList>

QStringList Query_World_Records(QString Benchmark, int Limit){
    QProcess wget;
    QStringList args;
    QStringList result;
    QFile wgetOut("queryresult.xml");if(wgetOut.exists()){wgetOut.remove();}

    args << "--header=Accept: application/xml" << "-O"
            << "queryresult.xml"
            << "http://hwbot.org/api/ranking?application=" + Benchmark + "&limit=" + QString::number(Limit);
    wget.start("plugins/wget/wget.dll",args);
    wget.waitForFinished();
    wget.close();

    if (wgetOut.size() > 0){//to prevent crashing
        QDomDocument doc("mydocument");
        if (!wgetOut.open(QIODevice::ReadOnly)){result << "Error Opening XML";}
        if (!doc.setContent(&wgetOut)) {result << "Error Reading XML";}
        wgetOut.close();

        QDomNodeList list_score = doc.elementsByTagName("score");
        QDomNodeList list_user = doc.elementsByTagName("user");
        QDomNodeList list_gpu = doc.elementsByTagName("description");
        for (int i=0;i<list_score.length();i++){
            result << list_score.at(i).toElement().text() + ";" +
                      list_user.at(i).toElement().text() + ";" +
                      list_gpu.at(i).toElement().text();
        }
    } else {
        result << "Error: Not connected to Internet";
    }

    return result;
}
