#ifndef Z_EN_KAIZOKU_H
#define Z_EN_KAIZOKU_H

#include "global.h"

struct EnKaizoku;

typedef void (*EnKaizokuActionFunc)(struct EnKaizoku*, PlayState*);

typedef struct EnKaizoku {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char pad144[0x168];                 /* maybe part of actor[2]? */
    /* 0x2AC */ EnKaizokuActionFunc actionFunc;
    /* 0x2B0 */ char pad2B0[0x40];                  /* maybe part of actionFunc[0x11]? */
    /* 0x2F0 */ f32 unk_2F0;
    /* 0x2F4 */ s16 unk_2F4;
    /* 0x2F6 */ char pad2F6[0xDA];                  /* maybe part of unk_2F4[0x6E]? */
    /* 0x3D0 */ s32 unk3D0;                         /* inferred */
    /* 0x3D4 */ ColliderCylinder unk3D4;            /* inferred */
    /* 0x420 */ ColliderQuad unk420;                /* inferred */
    /* 0x4A0 */ char pad4A0[0x150];                 /* maybe part of unk420[3]? */
} EnKaizoku;                                        /* size = 0x5F0 */

#endif // Z_EN_KAIZOKU_H
