#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QStringList>
#include "Enums.h"

namespace Todo {
struct sTodoInfo{
    eTodoPriority   priority    {eTodoPriority::none};
    bool            completed   {false};
    QString         description {};
    QString         backgroundColor{"transparent"};
    bool fromString(const QString &input)
    {
        QStringList list = input.split(',');
        if(list.size() != 4) return false;

        this->priority = static_cast<eTodoPriority>(list[0].toInt());
        this->completed = list[1] == "1";
        this->description = list[2];
        this->backgroundColor = list[3];
        return true;
    }
    QString toString()
    {
        return QString("%1,%2,%3,%4").
                arg(static_cast<int>(priority)).
                arg(completed).
                arg(description).
                arg(backgroundColor);
    }
};
}

#endif // STRUCTS_H
