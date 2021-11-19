#ifndef ENUMS_H
#define ENUMS_H

#include <stdint.h>
namespace Todo {

enum class eTodoPriority : uint8_t{
    none = 0,
    high,
    medium,
    low
};
}

#endif // ENUMS_H
