#ifndef Z_OBJ_MINE_H
#define Z_OBJ_MINE_H

#include "global.h"

struct ObjMine;

typedef void (*ObjMineActionFunc)(struct ObjMine*, PlayState*);

typedef struct ObjMine {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ ColliderJntSph collider;
    /* 0x0164 */ ColliderJntSphElement elements;
    /* 0x01A4 */ void (*func_1A4)(Actor *thisx, s32 arg1);
    /* 0x01A8 */ s32 unk1A8;                        /* inferred */
    /* 0x01AC */ s32 unk1AC;                        /* inferred */
    /* 0x01B0 */ s32 unk1B0;                        /* inferred */
    /* 0x01B4 */ Vec3s *pathPoint;
    /* 0x01B8 */ char pad1B8[0x11A0];               /* maybe part of unk1B4[0x469]? */
} ObjMine;                                          /* size = 0x1358 */

#endif // Z_OBJ_MINE_H
