#ifndef XIVTYPES_H
#define XIVTYPES_H

#include "primtypes.h"

#define LEVELMAX (90)

typedef struct {
    s64 mp;
    s64 main;
    s64 sub;
    s64 div;
    s64 hp;
    s64 elmt;
    s64 threat;
} LevelModifiers;

extern LevelModifiers gLevelModifiers[LEVELMAX];

#ifndef GAMEPATCH
#define GAMEPATCH 6010 // 6_1X
#endif

#endif

