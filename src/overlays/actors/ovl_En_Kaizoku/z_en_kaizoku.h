#ifndef Z_EN_KAIZOKU_H
#define Z_EN_KAIZOKU_H

#include "global.h"

struct EnKaizoku;

typedef void (*EnKaizokuActionFunc)(struct EnKaizoku*, PlayState*);

typedef struct EnKaizoku {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char pad144[4];
    /* 0x148 */ SkelAnime unk148;                   /* inferred */
    /* 0x18C */ char pad18C[0x120];                 /* maybe part of unk148[5]? */
    /* 0x2AC */ EnKaizokuActionFunc actionFunc;
    /* 0x2B0 */ s16 unk2B0;                         /* inferred */
    /* 0x2B2 */ s16 unk2B2;                         /* inferred */
    /* 0x2B4 */ s16 unk2B4;                         /* inferred */
    /* 0x2B6 */ s16 unk2B6;                         /* inferred */
    /* 0x2B8 */ s16 unk2B8;                         /* inferred */
    /* 0x2BA */ char pad2BA[0x12];                  /* maybe part of unk2B8[0xA]? */
    /* 0x2CC */ s16 unk2CC;                         /* inferred */
    /* 0x2CE */ s16 unk2CE;                         /* inferred */
    /* 0x2D0 */ s16 unk2D0;                         /* inferred */
    /* 0x2D2 */ s16 unk2D2;                         /* inferred */
    /* 0x2D4 */ char pad2D4[4];                     /* maybe part of unk2D2[3]? */
    /* 0x2D8 */ u8 unk2D8;                          /* inferred */
    /* 0x2D9 */ char pad2D9[0x17];                  /* maybe part of unk2D8[0x18]? */
    /* 0x2F0 */ f32 unk_2F0;
    /* 0x2F4 */ s16 unk_2F4;
    /* 0x2F6 */ char pad2F6[0xCE];                  /* maybe part of unk_2F4[0x68]? */
    /* 0x3C4 */ f32 unk3C4;                         /* inferred */
    /* 0x3C8 */ char pad3C8[4];
    /* 0x3CC */ f32 unk3CC;                         /* inferred */
    /* 0x3D0 */ char pad3D0[4];
    /* 0x3D4 */ ColliderCylinder unk3D4;            /* inferred */
    ///* 0x420 */ ColliderQuad unk420;                /* inferred */
    /* 0x420 */ Collider unk420;                    /* inferred */
    /* 0x438 */ char pad438[0x160];                 /* maybe part of unk420[0xF]? */
    /* 0x598 */ s32 unk598;                         /* inferred */
    /* 0x59C */ char pad59C[0x54];                  /* maybe part of unk598[0x16]? */
} EnKaizoku;                                        /* size = 0x5F0 */

#endif // Z_EN_KAIZOKU_H
