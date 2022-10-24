/*
 * File: z_en_kaizoku.c
 * Overlay: ovl_En_Kaizoku
 * Description: Fighter pirate
 */

#include "z_en_kaizoku.h"

#define FLAGS (ACTOR_FLAG_1 | ACTOR_FLAG_4 | ACTOR_FLAG_10 | ACTOR_FLAG_100000)

#define THIS ((EnKaizoku*)thisx)

void EnKaizoku_Init(Actor* thisx, PlayState* play);
void EnKaizoku_Destroy(Actor* thisx, PlayState* play);
void EnKaizoku_Update(Actor* thisx, PlayState* play);

#if 0
// static DamageTable sDamageTable = {
static DamageTable D_80B8AB3C = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x1),
    /* Deku Stick     */ DMG_ENTRY(1, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xF),
    /* Zora boomerang */ DMG_ENTRY(0, 0x1),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x1),
    /* Goron punch    */ DMG_ENTRY(1, 0xE),
    /* Sword          */ DMG_ENTRY(1, 0xE),
    /* Goron pound    */ DMG_ENTRY(0, 0xD),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xE),
    /* Deku spin      */ DMG_ENTRY(0, 0x1),
    /* Deku bubble    */ DMG_ENTRY(1, 0xE),
    /* Deku launch    */ DMG_ENTRY(2, 0xE),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x1),
    /* Zora barrier   */ DMG_ENTRY(0, 0x5),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xE),
    /* Zora punch     */ DMG_ENTRY(1, 0xE),
    /* Spin attack    */ DMG_ENTRY(1, 0xD),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0xE),
};

ActorInit En_Kaizoku_InitVars = {
    ACTOR_EN_KAIZOKU,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_KZ,
    sizeof(EnKaizoku),
    (ActorFunc)EnKaizoku_Init,
    (ActorFunc)EnKaizoku_Destroy,
    (ActorFunc)EnKaizoku_Update,
    (ActorFunc)NULL,
};

// static ColliderCylinderInit sCylinderInit = {
static ColliderCylinderInit D_80B8AB7C = {
    { COLTYPE_NONE, AT_NONE, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_ALL, OC2_TYPE_1, COLSHAPE_CYLINDER, },
    { ELEMTYPE_UNK4, { 0x00000000, 0x00, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON | BUMP_HOOKABLE, OCELEM_ON, },
    { 20, 50, 0, { 0, 0, 0 } },
};

// static ColliderQuadInit sQuadInit = {
static ColliderQuadInit D_80B8ABA8 = {
    { COLTYPE_NONE, AT_ON | AT_TYPE_PLAYER | AT_TYPE_ENEMY, AC_NONE, OC1_NONE, OC2_NONE, COLSHAPE_QUAD, },
    { ELEMTYPE_UNK4, { 0xF7CFFFFF, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, TOUCH_ON | TOUCH_SFX_NORMAL | TOUCH_UNK7, BUMP_NONE, OCELEM_NONE, },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } } },
};

#endif

extern DamageTable D_80B8AB3C;
extern ColliderCylinderInit D_80B8AB7C;
extern ColliderQuadInit D_80B8ABA8;

extern UNK_TYPE D_060058B8;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/EnKaizoku_Init.s")

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/EnKaizoku_Destroy.s")
void EnKaizoku_Destroy(Actor *thisx, PlayState *play) {
    EnKaizoku *this = THIS;
    Effect_Destroy(play, this->unk3D0);
    Collider_DestroyCylinder(play, &this->unk3D4);
    Collider_DestroyQuad(play, &this->unk420);
    Audio_RestorePrevBgm();
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85858.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85900.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85A00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85E18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85EA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85F48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B85FA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B86804.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B868B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B86B58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B86B74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B872A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B872F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B874D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8760C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87900.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8798C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87C7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87CF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87D3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87E28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87E9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87F70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B87FDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88214.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88278.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8833C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88378.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88770.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B887AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88910.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88964.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88CD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B88D6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B891B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B89280.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B893CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B894C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8960C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8971C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B89A08.s")

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/EnKaizoku_Update.s")
? func_80B85900(EnKaizoku *);                       /* extern */
? func_80B89A08(EnKaizoku *, PlayState *);          /* extern */

void EnKaizoku_Update(Actor *thisx, PlayState *play) {
    Vec3f sp34;
    CollisionCheckContext *sp2C;
    ColliderCylinder *sp28;
    ColliderCylinder *temp_a1;
    CollisionCheckContext *temp_a1_2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_6;
    s32 temp_v0_5;
    EnKaizoku *this = THIS;

    if (this->unk2D8 == 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (this->unk2B0 != 0) {
        func_80B85900(this);
    }
    temp_v0 = this->unk2CE;
    if (temp_v0 != 0) {
        this->unk2CE = temp_v0 - 1;
    }
    temp_v0_2 = this->unk2B2;
    if (temp_v0_2 != 0) {
        this->unk2B2 = temp_v0_2 - 1;
    }
    temp_v0_3 = this->unk2B4;
    if (temp_v0_3 != 0) {
        this->unk2B4 = temp_v0_3 - 1;
    }
    temp_v0_4 = this->unk2B6;
    if (temp_v0_4 != 0) {
        this->unk2B6 = temp_v0_4 - 1;
    }
    temp_v0_5 = this->unk598;
    if (temp_v0_5 != 0) {
        this->unk598 = temp_v0_5 - 1;
    }
    temp_v0_6 = this->unk2B8;
    if (temp_v0_6 != 0) {
        this->unk2B8 = temp_v0_6 - 1;
    }
    this->actionFunc(this, play);
    Actor_MoveWithGravity(&this->actor);
    if (this->unk2B0 != 0) {
        func_80B89A08(this, play);
    }
    if (this->unk2B0 != 0) {
        Actor_SetFocus(&this->actor, 60.0f);
    }
    Actor_SetScale(&this->actor, 0.0125f);
    if (this->unk2CE == 0) {
        this->unk2CC += 1;
        if (this->unk2CC >= 4) {
            this->unk2CC = 0;
            this->unk2CE = Rand_S16Offset(0x14, 0x3C);
        }
    }
    if (this->actor.bgCheckFlags & 1) {
        Matrix_RotateYS((s16) (this->actor.shape.rot.y + this->unk_2F4), MTXMODE_NEW);
        Matrix_MultVecZ(this->unk_2F0, &sp34);
        this->actor.world.pos.x += this->unk3C4 + (bitwise f32) sp34;
        this->actor.world.pos.z += this->unk3CC + sp34.z;
        Math_ApproachZeroF(&this->unk3C4, 1.0f, 2.0f);
        Math_ApproachZeroF(&this->unk3CC, 1.0f, 2.0f);
        Math_ApproachZeroF(&this->unk_2F0, 1.0f, 5.0f);
    }
    Actor_UpdateBgCheckInfo(play, &this->actor, 35.0f, 40.0f, 35.0f, 0x1FU);
    temp_a1 = &this->unk3D4;
    sp28 = temp_a1;
    Collider_UpdateCylinder(&this->actor, temp_a1);
    temp_a1_2 = &play->colChkCtx;
    sp2C = temp_a1_2;
    CollisionCheck_SetOC(play, temp_a1_2, &sp28->base);
    if ((this->unk2D0 < 2) && (this->unk2B0 != 0)) {
        CollisionCheck_SetAC(play, sp2C, &sp28->base);
    }
    if (this->unk2D2 > 0) {
        CollisionCheck_SetAT(play, sp2C, &this->unk420);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8A318.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8A468.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8A6B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_En_Kaizoku/func_80B8A718.s")
