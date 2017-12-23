#include "processing.h"

QString whatType(QString str)
{
    QRegExp reg("^\\-?\\d+\\.\\d+$");

    if (str.contains(reg))
        return "REAL";

    reg = QRegExp("^\\-?\\d+$");
    if(str.contains(reg))
        return "INTEGER";
    return "TEXT";
}

QStringList parseStr(QString str)
{
        QStringList ret;
        int in;

        while ( (in = str.indexOf(";")) != -1)
        {
            QString subStr = str;
            subStr.remove(in,str.size());
            int countQ = subStr.count("\"");

            while (countQ % 2 != 0)
            {
                int in2 = str.indexOf(";",in+1);
                if (in2 == -1)
                {
                    ret.append(withoutQuotes(str));
                    return ret;
                }
                subStr = str;
                subStr.remove(in2,str.size());
                countQ = subStr.count("\"");
                in = in2;
            }

            ret.append(withoutQuotes(subStr));
            str.remove(0,subStr.size()+1);
        }

        ret.append(withoutQuotes(str));
        return ret;
}

QString withoutQuotes(QString str)
{
    if (str[0] == "\"")
    {
        str.remove(0,1);
        str.remove(str.size()-1,1);
    }

    str.replace("\"\"","\"");

    return str;
}

QString processingForCsvStr(QString str)
{
    if (str.contains("\""))
    {
        str.replace("\"","\"\"");
    }

    if (str.contains(";") || str.contains(",") || str.contains("\"") || str.contains("\n"))
        return "\"" + str + "\"";

    return str;
}
