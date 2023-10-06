//
// Generated by dtk
// Translation Unit: d_a_kytag05.cpp
//
#include "JSystem/JKernel/JKRHeap.h"
#include "JAZelAudio/JAIZelBasic.h"
#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_camera_mng.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo_wether.h"
#include "d/actor/d_a_player.h"
#include "d/actor/d_a_ykgr.h"
#include "m_Do/m_Do_audio.h"
#include "d/d_procname.h"


class kytag05_class : public fopAc_ac_c {
public:
    /* 0x00 */ u8 mWindIndex;
    /* 0x04 */ int mCurrWindDir;
    /* 0x08 */ int field_0x298;
}; /* size = 0x29C */

BOOL daKytag05_Draw(kytag05_class*) {
    return true;
}

static const s16 wind_table[] = {
    0x00,
    0x00,
    0x80,
    0x01,
    0xC0,
    0x00,
    0x40,
    0x00
};

static const s16 fuu_timer[] = {
    0x00,
    0x96,
    0x00,
    0x96,
    0x00,
    0x96,
    0x00,
    0x96
};

static const s16 mufuu_timer[] = {
    0x00,
    0x0A,
    0x00,
    0x0A,
    0x00,
    0x00,
    0x00,
    0x5A
};

/* 00000080-000003F4       .text daKytag05_Execute__FP13kytag05_class */
int daKytag05_Execute(kytag05_class* a_this) {
    /* Nonmatching */
    daPy_py_c *playerActor;
    camera_class *mpCamera;
    f32 cameraEyeZ;
    f32 i_blend;
    f32 windPow;
    u32 demoField;
    mpCamera = dComIfGp_getCamera(0);
    playerActor = daPy_getPlayerActorClass();
    windPow = dKyw_get_wind_pow();
    i_blend = 5;

    if (g_env_light.mWind.mEvtWindSet == 0xFF) {
        return 1;
    }
    if (g_dComIfG_gameInfo.play.mEvtCtrl.mMode != 0 &&
        dComIfGp_getEventManager().startCheckOld("demo41") != 0 &&
        g_dComIfG_gameInfo.play.getDemo() != NULL) {
        demoField = g_dComIfG_gameInfo.play.getDemo()->field_0xd4;
        if(demoField >= 0x186) {
            f32 var_f1 = ((f32)demoField - 90.0f) / 180.0f;
            if(var_f1 > i_blend) {
                var_f1 = i_blend;
            }
            i_blend = 0.5f - var_f1;
            g_env_light.mSnowCount = (int)(259 * i_blend);
        } else if (demoField == 0x187 && daYkgr_c::m_emitter != 0) {
            daYkgr_c::m_alpha_flag = 0;
        }
    }
    dKy_custom_colset(0, 7, i_blend);
    if((a_this->mWindIndex & 1) == 0) {
        if (a_this->mCurrWindDir >= fuu_timer[(a_this->mWindIndex & ~0x1) >> 1]) {
            a_this->mCurrWindDir = 0;
            a_this->mWindIndex += 1;
            g_env_light.mWind.mEvtWindSet = 2;
        } else {
            a_this->mCurrWindDir += 1;
        }
    } else {
        if (a_this->mCurrWindDir >=  mufuu_timer[(a_this->mWindIndex & ~0x1) >> 1]) {
            a_this->mWindIndex += 1;
            if(a_this->mWindIndex >> 1 >= 4) {
                a_this->mWindIndex = 0;
            }
            dKyw_evt_wind_set(0, wind_table[a_this->mWindIndex]);
            a_this->mCurrWindDir = 0;
            g_env_light.mWind.mEvtWindSet = 1;
        } else {
            a_this->mCurrWindDir += 1;
        }
    }
    cameraEyeZ = mpCamera->mLookat.mEye.z;
    if(cameraEyeZ > 360.0f || cameraEyeZ > 360.0f &&
       mpCamera->mLookat.mEye.x > 450 || playerActor->current.pos.x > 450.0f){
        if(cameraEyeZ > 540.0f || playerActor->current.pos.z < 540.0f) {
            dKyw_evt_wind_set(0, 0x61A8);
        } else if(cameraEyeZ > 630.0f || playerActor->current.pos.z > 630.0f) {
            dKyw_evt_wind_set(0, 0x4E20);
        } else {
            dKyw_evt_wind_set(0,0x4650);
        }
    } else if(mpCamera->mLookat.mEye.z < 720 ||  playerActor->current.pos.z < 720) {
        dKyw_evt_wind_set(0, -0x3E80);
    } else if(mpCamera->mLookat.mEye.z < 810 || playerActor->current.pos.z < 810 ) {
        dKyw_evt_wind_set(0, -0x4B00);
    } else if(mpCamera->mLookat.mEye.z < 900 || playerActor->current.pos.z < 900) {
        dKyw_evt_wind_set(0, -0x32C8);
    }

    mDoAud_seStart(0x106A, 0, (u32)(windPow * 180), 0);
    return 1;
}

BOOL daKytag05_IsDelete(kytag05_class*) {
    return true;
}

BOOL daKytag05_Delete(kytag05_class*) {
    return true;
}

int daKytag05_Create(fopAc_ac_c* i_this) {
    fopAcM_SetupActor(i_this, kytag05_class);
    kytag05_class *a_this = (kytag05_class*)i_this;
    if (dComIfGs_isSymbol(1) != 0) {
        return 3;
    }
    a_this->mWindIndex = 0;
    a_this->mCurrWindDir = 0;
    a_this->field_0x298 = i_this->mBase.mParameters & 0xff;
    dKyw_evt_wind_set_go();
    dKyw_evt_wind_set(0,0);
    g_env_light.mSnowCount = 200;
    g_env_light.mMoyaMode = 0;
    g_env_light.mMoyaCount = 100;

    return 4;
}

static actor_method_class l_daKytag05_Method = {
    (process_method_func)daKytag05_Create,
    (process_method_func)daKytag05_Delete,
    (process_method_func)daKytag05_Execute,
    (process_method_func)daKytag05_IsDelete,
    (process_method_func)daKytag05_Draw,
};

extern actor_process_profile_definition g_profile_KYTAG06 = {
    fpcLy_CURRENT_e,
    7,
    fpcLy_CURRENT_e,
    PROC_KYTAG05,
    &g_fpcLf_Method.mBase,
    sizeof(kytag05_class),
    0,
    0,
    &g_fopAc_Method.base,
    0xA5,
    &l_daKytag05_Method,
    0x00000044000,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};