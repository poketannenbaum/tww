//
// Generated by dtk
// Translation Unit: d_a_kytag03.cpp
//

#include "d/actor/d_a_kytag03.h"
#include "d/d_procname.h"

/* 00000078-0000015C       .text useHeapInit__FP10fopAc_ac_c */
static BOOL useHeapInit(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 0000015C-000001D8       .text daKytag03_Draw__FP13kytag03_class */
static BOOL daKytag03_Draw(kytag03_class*) {
    /* Nonmatching */
}

/* 000001D8-00000280       .text draw_SUB__FP13kytag03_class */
void draw_SUB(kytag03_class*) {
    /* Nonmatching */
}

/* 00000280-0000050C       .text daKytag03_Execute__FP13kytag03_class */
static BOOL daKytag03_Execute(kytag03_class*) {
    /* Nonmatching */
}

/* 0000050C-00000514       .text daKytag03_IsDelete__FP13kytag03_class */
static BOOL daKytag03_IsDelete(kytag03_class*) {
    /* Nonmatching */
}

/* 00000514-00000544       .text daKytag03_Delete__FP13kytag03_class */
static BOOL daKytag03_Delete(kytag03_class*) {
    /* Nonmatching */
}

/* 00000544-00000604       .text daKytag03_Create__FP10fopAc_ac_c */
static s32 daKytag03_Create(fopAc_ac_c*) {
    /* Nonmatching */
}

static actor_method_class l_daKytag03_Method = {
    (process_method_func)daKytag03_Create,
    (process_method_func)daKytag03_Delete,
    (process_method_func)daKytag03_Execute,
    (process_method_func)daKytag03_IsDelete,
    (process_method_func)daKytag03_Draw,
};

actor_process_profile_definition g_profile_KYTAG03 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_KYTAG03,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(kytag03_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00A3,
    /* Actor SubMtd */ &l_daKytag03_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
