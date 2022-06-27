#include <stdio.h>
#include <stdlib.h>
#include "xivtypes.h"
#include "xivfuncs.h"

s32 main(s32 argc, char* argv[]) {
    s32 index;
    s32 level = 90;
    f32 base = 2.5f;
    f32 speed = 500.0f;
    f32 gcd;
    char* endp;

    printf("Build date %s %s\n", __DATE__, __TIME__);

    for (index = 0; index < argc; index++) {
        char* arg = argv[index];
        char* ch;

        if (arg != NULLPTR) {
            ch = arg;
            if (*ch++ == '-') {
                switch (*ch) {
                    case ('l'): {
                        ch += 2;
                        level = strtoll(ch, NULLPTR, 10);
                        break;
                    }
                    case ('g'): {
                        ch += 2;
                        base = strtold(ch, NULLPTR);
                        break;
                    }
                    case ('s'): {
                        ch += 2;
                        speed = strtold(ch, NULLPTR);
                        break;
                    }
                    case ('?'): {
                        printf("Arguments are:\n-l= [level; default: 90]\n-g= [base gcd; default: 2.5]\n-s= [skill speed; default: 500]\n-? [display help info]\n");
                        break;
                    }
                }
            }
        }
    }

    gcd = Compute_GCD(level, base, speed);
    printf("GCD is %f\n", gcd);

    return 0;
}

