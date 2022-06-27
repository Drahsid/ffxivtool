#include <math.h>
#include "xivtypes.h"

const f32 Compute_GCD(u32 level, f32 base, f32 speed) {
    u32 lv = level;
    f32 gcd = base * 1000.0f;
    LevelModifiers* mods = &gLevelModifiers[level - 1];

    return ((gcd * (1000.0f + ceilf(130.0f * ((f32)mods->sub - speed) / (f32)mods->div)) / 10000.0f) / 100.0f);
}

