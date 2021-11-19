#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include "Enums.h"

struct sTodoInfo{
    eTodoPriority   priority    {eTodoPriority::none};
    bool            completed   {false};
    QString         description {};
    QString         backgroundColor{"transparent"};
};

#endif // STRUCTS_H
