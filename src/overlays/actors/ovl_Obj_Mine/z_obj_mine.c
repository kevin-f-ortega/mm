/*
 * File: z_obj_mine.c
 * Overlay: ovl_Obj_Mine
 * Description: Spike metal Mine
 */

#include "z_obj_mine.h"

#define FLAGS 0x00000000

#define THIS ((ObjMine*)thisx)

void ObjMine_Init(Actor* thisx, PlayState* play);
void ObjMine_Destroy(Actor* thisx, PlayState* play);
void ObjMine_Update(Actor* thisx, PlayState* play);
void ObjMine_Draw(Actor* thisx, PlayState* play);
extern void func_80A82FC8(ObjMine *thisx, PlayState *play);

s32 Collider_DestroyJntSph(PlayState* play, ColliderJntSph* collider);
void func_80A82F98(ObjMine *thisx, PlayState *play);
void func_80A811D0(ObjMine *arg0, s32 arg1);
s32 func_80A8120C(Vec3f *arg0, Vec3f *arg1);

#if 0
static s32 D_80A845A4[8] = {
    0x3F800000,
    0x40000000,
    0x40400000,
    0x40800000,
    0x40A00000,
    0x40C00000,
    0x40E00000,
    0x41000000,
};
#endif

#if 0
ActorInit Obj_Mine_InitVars = {
    ACTOR_OBJ_MINE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_NY,
    sizeof(ObjMine),
    (ActorFunc)ObjMine_Init,
    (ActorFunc)ObjMine_Destroy,
    (ActorFunc)ObjMine_Update,
    (ActorFunc)ObjMine_Draw,
};

// static ColliderJntSphElementInit sJntSphElementsInit[1] = {
static ColliderJntSphElementInit D_80A84570[1] = {
    {
        { ELEMTYPE_UNK2, { 0x00000000, 0x00, 0x00 }, { 0x01CBFFBE, 0x00, 0x00 }, TOUCH_NONE | TOUCH_SFX_NORMAL, BUMP_ON, OCELEM_ON, },
        { 0, { { 0, 0, 0 }, 30 }, 100 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
static ColliderJntSphInit D_80A84594 = {
    { COLTYPE_METAL, AT_NONE, AC_ON | AC_TYPE_PLAYER, OC1_ON | OC1_TYPE_PLAYER | OC1_TYPE_1, OC2_TYPE_1, COLSHAPE_JNTSPH, },
    ARRAY_COUNT(sJntSphElementsInit), D_80A84570, // sJntSphElementsInit,
};

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_80A845E8[] = {
    ICHAIN_F32(uncullZoneForward, 1300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 150, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 100, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_STOP),
};

#endif

extern ColliderJntSphElementInit D_80A84570[1];
extern ColliderJntSphInit D_80A84594;
extern InitChainEntry D_80A845E8[];

extern UNK_TYPE D_06000030;
extern UNK_TYPE D_06002068;

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A811D0.s")
void func_80A811D0(ObjMine *arg0, s32 arg1) {
    Math_Vec3s_ToVec3f(&arg0->actor.world.pos, arg0->pathPoint + arg1);
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A8120C.s")
s32 func_80A8120C(Vec3f *arg0, Vec3f *arg1) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = Math3D_Vec3fMagnitude(arg0);
    if (temp_fv0 < 0.001f) {
        return 0;
    }
    temp_fv1 = 1.0f / temp_fv0;
    arg1->x = (f32) (arg0->x * temp_fv1);
    arg1->y = (f32) (arg0->y * temp_fv1);
    arg1->z = (f32) (arg0->z * temp_fv1);
    return 1;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81288.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A8131C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81384.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A8140C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A8146C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81544.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81640.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A8164C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81684.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81714.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81818.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81868.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A819A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81A00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81AA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81B14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81B7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81D70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81DEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81E7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A81FFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A828A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A82C28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/ObjMine_Init.s")

#if 0
void ObjMine_Init(Actor *thisx, PlayState *play) {
    s32 sp44;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    ActorShape *sp30;                               /* compiler-managed */
    ColliderJntSph **sp2C;
    ActorShape *temp_a0;
    ColliderJntSph **temp_a1;
    Path *temp_v0_2;
    f32 temp_fv0;
    f32 temp_fv1;
    s16 temp_v0;
    s32 temp_v0_3;
    ObjMine *this = THIS;

    temp_v0 = this->actor.params;
    sp44 = temp_v0 & 0xFF;
    sp38 = (temp_v0 >> 0xC) & 3;
    Actor_ProcessInitChain(&this->actor, D_80A845E8);
    this->actor.shape.rot.z = 0;
    this->actor.world.rot.z = 0;
    temp_a1 = &this->collider;
    sp2C = temp_a1;
    Collider_InitJntSph(play, (ColliderJntSph *) temp_a1);
    Collider_SetJntSph(play, (ColliderJntSph *) temp_a1, &this->actor, &D_80A84594, &this->elements);
    temp_a0 = &this->actor.shape;
    if (sp38 == 0) {
        sp30 = temp_a0;
        ActorShape_Init(temp_a0, 0.0f, ActorShadow_DrawCircle, 45.0f);
        this->actor.shape.shadowAlpha = 0x8C;
        this->unk1A8 = D_80A845A4[((s16) this->actor.params >> 8) & 7];
        if (sp44 == 0xFF) {
            func_80A82F84(this);
        } else {
            this->unk1B0 = 0;
            temp_v0_2 = &play->setupPathList[sp44];
            this->unk1AC = temp_v0_2->count - 1;
            this->pathPoint = Lib_SegmentedToVirtual(temp_v0_2->points);
            func_80A811D0(this, this->unk1B0);
            func_80A82FA8(this);
        }
        Matrix_SetTranslateRotateYXZ(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, &sp30->rot);
        Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
        Collider_UpdateSpheres(0, (ColliderJntSph *) sp2C);
        this->actor.floorHeight = BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &sp3C, &this->actor, &this->actor.world.pos);
        return;
    }
    temp_v0_3 = this->actor.params & 0x3F;
    temp_fv1 = (f32) temp_v0_3;
    this->actor.update = func_80A83E7C;
    temp_fv0 = (temp_fv1 * 21.0f) + 150.0f;
    this->actor.uncullZoneScale = temp_fv0;
    this->actor.uncullZoneDownward = temp_fv0;
    sp30 = temp_fv1;
    sp34 = temp_v0_3;
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 45.0f);
    this->actor.shape.shadowAlpha = 0x8C;
    if (sp38 == 1) {
        this->actor.draw = func_80A84088;
        func_80A81868(this, sp34);
        this->actor.world.pos.y = (-10.0f - (sp30 * 12.0f)) + this->actor.home.pos.y;
        func_80A819A4(this, sp34);
        func_800B4AEC(play, &this->actor, 0.0f);
        if (sp34 == 0) {
            func_80A83A74(this);
            return;
        }
        func_80A832BC(this);
        return;
    }
    this->actor.draw = func_80A84338;
    func_80A81B7C(this, sp34);
    this->actor.world.pos.y = (sp30 * 12.0f) + 10.0f + this->actor.home.pos.y;
    func_80A81D70(this, sp34);
    if (sp34 == 0) {
        func_80A83CEC(this);
        return;
    }
    func_80A83B14(this);
}
#endif

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/ObjMine_Destroy.s")
void ObjMine_Destroy(Actor *thisx, PlayState *play) {
    ObjMine *this = THIS;
    Collider_DestroyJntSph(play, &this->collider);
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A82F84.s")
void func_80A82F84(ObjMine *arg0) {
    arg0->actionFunc = &func_80A82F98;
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A82F98.s")
void func_80A82F98(ObjMine *thisx, PlayState *play) {

}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A82FA8.s")
void func_80A82FA8(Actor *thisx) {
    ObjMine *this = THIS;
    this->actor.flags = (s32) (this->actor.flags | 0x10);
    this->func_1A4 = &func_80A82FC8;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A82FC8.s")
#if 0
static Vec3f D_80A845D0[2] = { { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };

void func_80A82FC8(Actor *arg0, s32 arg1) {
    Vec3f spA0;
    f32 sp9C;
    s32 sp90;
    Vec3f sp84;
    Vec3f sp78;
    MtxF sp38;
    Vec3f *sp2C;
    Vec3f *sp28;
    Vec3f *temp_a1;
    Vec3f *temp_a2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 var_fa0;
    f32 var_fv0;
    s32 var_a1;

    Math_Vec3s_ToVec3f(&spA0, arg0->unk1B4 + (arg0->unk1B0 * 6) + 6);
    temp_a1 = arg0 + 0x24;
    temp_a2 = arg0 + 0x64;
    sp2C = temp_a2;
    sp28 = temp_a1;
    Math_Vec3f_Diff(&spA0, temp_a1, temp_a2);
    temp_fv0 = Math3D_Vec3fMagnitude(sp2C);
    temp_fv1 = arg0->unk1A8;
    if ((temp_fv0 < (temp_fv1 * 8.0f)) && (temp_fv1 > 2.0f)) {
        var_fv0 = ((temp_fv1 - 2.0f) * 0.1f) + 2.0f;
        var_fa0 = temp_fv1 * 0.03f;
    } else {
        var_fv0 = temp_fv1;
        var_fa0 = temp_fv1 * 0.16f;
    }
    sp9C = temp_fv0;
    Math_StepToF(arg0 + 0x70, var_fv0, var_fa0);
    temp_fv0_2 = arg0->speedXZ;
    if ((temp_fv0_2 + 0.05f) < temp_fv0) {
        Math_Vec3f_Scale(sp2C, temp_fv0_2 / temp_fv0);
        arg0->world.pos.x += arg0->velocity.x;
        arg0->world.pos.y += arg0->velocity.y;
        arg0->world.pos.z += arg0->velocity.z;
    } else {
        var_a1 = arg0->unk1B0 + 1;
        arg0->unk1B0 = var_a1;
        arg0->speedXZ = temp_fv0_2 * 0.4f;
        if (var_a1 >= arg0->unk1AC) {
            arg0->unk1B0 = 0;
            var_a1 = 0;
        }
        func_80A811D0(arg0, var_a1);
    }
    arg0->floorHeight = BgCheck_EntityRaycastFloor5(arg1 + 0x830, &arg0->floorPoly, &sp90, arg0, sp28);
    if (arg0->flags & 0x40) {
        Math3D_CrossProduct(D_80A845D0, sp2C, &sp78);
        if (func_80A8120C(&sp78, &sp84) != 0) {
            Matrix_RotateAxisF(arg0->speedXZ * 0.03125f, &sp84, MTXMODE_NEW);
            Matrix_RotateYS(arg0->shape.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(arg0->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(arg0->shape.rot.z, MTXMODE_APPLY);
            Matrix_Get(&sp38);
            Matrix_MtxFToYXZRot(&sp38, &arg0->shape.rot, 0);
        }
    }
}
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83214.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83258.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A832BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A832D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83A74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83A88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83B14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83B28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83CEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83D00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/ObjMine_Update.s")

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83E7C.s")
void func_80A83E7C(Actor* thisx, PlayState* play) {
    ObjMine* this = THIS;
    this->actionFunc(this, play);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/ObjMine_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A83FBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A84088.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mine/func_80A84338.s")
