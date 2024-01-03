//
// Generated by dtk
// Translation Unit: d_event_data.cpp
//

#include "d/d_event_data.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"
#include "f_op/f_op_actor_mng.h"
#include "m_Do/m_Do_graphic.h"

/* 80071778-8007195C       .text dEvDt_Next_Stage__Fii */
BOOL dEvDt_Next_Stage(int staffIdx, int wipePrm) {
    u32 roomNo;
    u32 layerNo;
    u32 mode;
    u32 wipe;
    const char * pStageName;
    u32 * pStartCode;
    u32 * pRoomNo;
    u32 * pLayer;
    f32 * pHour;
    u32 * pMode;
    u32 * pWipe;

    roomNo = 0;
    layerNo = -1;
    mode = 0;
    wipe = wipePrm;

    pStageName = dComIfGp_evmng_getMyStringP(staffIdx, "Stage");
    if (pStageName == NULL)
        return FALSE;

    pStartCode = dComIfGp_evmng_getMyIntegerP(staffIdx, "StartCode");
    pRoomNo = dComIfGp_evmng_getMyIntegerP(staffIdx, "RoomNo");
    if (pRoomNo != NULL)
        roomNo = *pRoomNo;
    pLayer = dComIfGp_evmng_getMyIntegerP(staffIdx, "Layer");
    if (pLayer != NULL)
        layerNo = *pLayer;
    pHour = dComIfGp_evmng_getMyFloatP(staffIdx, "Hour");
    pMode = dComIfGp_evmng_getMyIntegerP(staffIdx, "Mode");
    if (pMode != NULL)
        mode = *pMode;
    pWipe = dComIfGp_evmng_getMyIntegerP(staffIdx, "Wipe");
    if (pWipe != NULL)
        wipe = *pWipe;

    if (pStageName != NULL && pStartCode != NULL) {
        if (pHour != NULL)
            dKy_set_nexttime(*pHour * 15.0f);
        dComIfGp_setNextStage(pStageName, *pStartCode, roomNo, layerNo, 0.0f, mode, TRUE, wipe);
    } else {
        JUT_ASSERT(0x88, 0);
    }

    return TRUE;
}

/* 8007195C-800719C4       .text flagCheck__11dEvDtFlag_cFi */
BOOL dEvDtFlag_c::flagCheck(int flag_id) {
    if (flagMaxCheck(flag_id))
        return FALSE;

    u32 byteNo = ((u32)flag_id / 0x20);
    u32 bitNo = 1 << (flag_id & 0x1F);
    if (mFlag[byteNo] & bitNo)
        return TRUE;
    return FALSE;
}

/* 800719C4-80071A2C       .text flagSet__11dEvDtFlag_cFi */
BOOL dEvDtFlag_c::flagSet(int flag_id) {
    if (flagMaxCheck(flag_id))
        return FALSE;

    u32 byteNo = ((u32)flag_id / 0x20);
    u32 bitNo = 1 << (flag_id & 0x1F);
    mFlag[byteNo] |= bitNo;
    return TRUE;
}

/* 80071A2C-80071AA8       .text flagMaxCheck__11dEvDtFlag_cFi */
BOOL dEvDtFlag_c::flagMaxCheck(int flag_id) {
    if (flag_id == -1) {
        return TRUE;
    } else if (flag_id >= FlagMax) {
        JUT_ASSERT(0xc0, flag_id < FlagMax);
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 80071AA8-80071AC8       .text init__11dEvDtFlag_cFv */
void dEvDtFlag_c::init() {
    for (u32 i = 0; i < ARRAY_SIZE(mFlag); i++)
        mFlag[i] = 0;
}

inline BOOL dEvDtFlagCheck(int flag_id) {
    return dComIfGp_getPEvtManager()->getFlags().flagCheck(flag_id);
}

inline BOOL dEvDtFlagSet(int flag_id) {
    return dComIfGp_getPEvtManager()->getFlags().flagSet(flag_id);
}

/* 80071AC8-80071B4C       .text finish_check__12dEvDtEvent_cFv */
BOOL dEvDtEvent_c::finish_check() {
    for (s32 i = 0; i < (s32)ARRAY_SIZE(mFlagCheckFinish); i++) {
        int flag_id = mFlagCheckFinish[i];
        if (flag_id == -1)
            return TRUE;
        if (!dEvDtFlagCheck(flag_id))
            return FALSE;
    }

    return TRUE;
}

/* 80071B4C-80071BB4       .text specialStaffProc__12dEvDtEvent_cFP12dEvDtStaff_c */
void dEvDtEvent_c::specialStaffProc(dEvDtStaff_c* staff) {
    for (s32 i = 0; i < getNStaff(); i++)
        staff[getStaff(i)].specialProc();
}

/* 80071BB4-80071C18       .text specialProc_WaitStart__12dEvDtStaff_cFi */
void dEvDtStaff_c::specialProc_WaitStart(int staffIdx) {
    u32 * pTimer = dComIfGp_evmng_getMyIntegerP(staffIdx, "Timer");
    if (pTimer == NULL)
        mTimer = 0;
    else
        mTimer = *pTimer;
}

/* 80071C18-80071C5C       .text specialProc_WaitProc__12dEvDtStaff_cFi */
void dEvDtStaff_c::specialProc_WaitProc(int staffIdx) {
    if (mTimer > 0)
        mTimer--;
    else
        dComIfGp_evmng_cutEnd(staffIdx);
}

/* 80071C5C-80071D08       .text specialProc__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProc() {
    switch (mStaffType) {
    case PACKAGE_e:
        specialProcPackage();
        break;
    case DIRECTOR_e:
        specialProcDirector();
        break;
    case TIMEKEEPER_e:
        specialProcTimekeeper();
        break;
    case ALL_e:
        dComIfGp_evmng_cutEnd(mStaffIdx);
        break;
    case CREATE_e:
        specialProcCreate();
        dComIfGp_evmng_cutEnd(mStaffIdx);
        break;
    case SOUND_e:
        specialProcSound();
        break;
    case MESSAGE_e:
        specialProcMessage();
        break;
    case LIGHT_e:
        specialProcLight();
        break;
    }
}

/* 80071D08-80071D58       .text init__12dEvDtStaff_cFv */
void dEvDtStaff_c::init() {
    mCurCutIdx = mFirstCutIdx;
    mTimer = 0;
    mWipeDirection = 0;
    m45 = 0;
    m44 = 0;
    mAdvance = 2;
    mbNeedsAction = false;
    mCurActionIdx = -1;
    if (mStaffType == CAMERA_e)
        dComIfGp_getPEvtManager()->setCameraPlay(1);
}

/* 80071D58-80071D88       .text advanceCut__12dEvDtStaff_cFi */
void dEvDtStaff_c::advanceCut(int cutIdx) {
    mCurCutIdx = cutIdx;
    mTimer = 0;
    mWipeDirection = 0;
    m45 = 0;
    m44 = 0;
    mAdvance = 1;
    mbNeedsAction = false;
    mCurActionIdx = -1;
}

/* 80071D88-80071F58       .text specialProcLight__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcLight() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("LIGHT");
    if (staffIdx == -1) {
        JUT_ASSERT(0x16a, 0);
        return;
    }

    static char * action_table[] = {
        "WAIT",
        "CHANGE",
        "ADD_TIME",
    };
    int act = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);

    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (act) {
        case 1: // CHANGE
            {
                f32 * pHour = dComIfGp_evmng_getMyFloatP(staffIdx, "Hour");
                if (pHour != NULL) {
                    dKy_instant_timechg(*pHour * 15.0f);
                }

                s32 * pWeather = (s32*)dComIfGp_evmng_getMyIntegerP(staffIdx, "Weather");
                if (pWeather != NULL) {
                    switch (*pWeather) {
                    case 0:
                        dKy_instant_rainchg();
                        break;
                    }
                }
            }
            break;
        case 2: // ADD_TIME
            {
                f32 * pHour = dComIfGp_evmng_getMyFloatP(staffIdx, "Hour");
                if (pHour != NULL) {
                    f32 hour = dComIfGs_getTime() * (1.0f / 15.0f);
                    hour += *pHour;
                    while (hour >= 24.0)
                        hour -= 24.0;
                    dKy_instant_timechg(hour * 15.0f);
                }
            }
            break;
        }
    }
    dComIfGp_evmng_cutEnd(staffIdx);
}

/* 80071F58-80072458       .text specialProcMessage__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcMessage() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("MESSAGE");
    if (staffIdx == -1) {
        JUT_ASSERT(0x1C2, 0);
        return;
    }

    static char* action_table[] = {
        "WAIT",
        "CREATE_MSG",
        "PUSHBUTTON",
        "FINISH",
        "CONTINUE",
        "END",
        "DELETE",
        "TELOP_ON",
        "TELOP_OFF",
    };
    static u32 l_msgId;
    static msg_class* l_msg;
    static int l_msgNo;

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
        case 0: // WAIT
            specialProc_WaitStart(staffIdx);
            break;
        case 1: // CREATE_MSG
            l_msgId = fpcM_ERROR_PROCESS_ID_e;
            l_msg = NULL;
            u32* idata = dComIfGp_evmng_getMyIntegerP(staffIdx, "msgNo");
            JUT_ASSERT(0x1D2, idata);
            l_msgNo = *idata;
            mWipeDirection = 0;
            break;
        case 3: // FINISH
        case 5: // END
            JUT_ASSERT(0x1D8, l_msg);
            l_msg->mMode = 0x10;
            break;
        case 4: // CONTINUE
            JUT_ASSERT(0x1DC, l_msg);
            l_msg->mMode = 0xF;
            idata = dComIfGp_evmng_getMyIntegerP(staffIdx, "msgNo");
            JUT_ASSERT(0x1DF, idata);
            l_msgNo = *idata;
            fopMsgM_messageSet(l_msgNo);
            break;
        case 7: // TELOP_ON
            idata = dComIfGp_evmng_getMyIntegerP(staffIdx, "tlpNo");
            JUT_ASSERT(0x1E5, idata);
            dComIfGp_setStageNameOn(*idata);
            specialProc_WaitStart(staffIdx);
            break;
        case 8: // TELOP_OFF
            dComIfGp_setStageNameOff();
            break;
        }
    }

    switch (actIdx) {
    case 0: // WAIT
    case 7: // TELOP_ON
        specialProc_WaitProc(staffIdx);
        break;
    case 1: // CREATE_MSG
        switch (mWipeDirection) {
        case 0:
            l_msgId = fopMsgM_messageSet(l_msgNo);
            if (l_msgId != fpcM_ERROR_PROCESS_ID_e) {
                mWipeDirection++;
            }
            break;
        case 1:
            l_msg = fopMsgM_SearchByID(l_msgId);
            if (l_msg) {
                mWipeDirection++;
            }
            break;
        case 2:
            dComIfGp_evmng_cutEnd(staffIdx);
            break;
        }
        break;
    case 2: // PUSHBUTTON
        JUT_ASSERT(0x209, l_msg);
        if (l_msg->mMode == 0xE) {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        break;
    case 3: // FINISH
    case 6: // DELETE
        if (!l_msg) {
            dComIfGp_evmng_cutEnd(staffIdx);
        } else if (l_msg->mMode == 0x12) {
            l_msg->mMode = 0x13;
            l_msgId = fpcM_ERROR_PROCESS_ID_e;
            l_msg = NULL;
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        break;
    case 4: // CONTINUE
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    case 5: // END
        switch (l_msg->mMode) {
        case 0x11:
        case 0x12:
            dComIfGp_evmng_cutEnd(staffIdx);
            break;
        }
        break;
    case 8: // TELOP_OFF
        if (dComIfGp_checkStageName() == 0) {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        break;
    default:
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    }
}

/* 80072458-80072748       .text specialProcSound__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcSound() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("SOUND");
    if (staffIdx == -1) {
        JUT_ASSERT(0x254, 0);
        return;
    }

    static char* action_table[] = {
        "WAIT",
        "STRM_PLAY",
        "STRM_DEMO_MJ_SISTER",
        "STRM_DEMO_GO_MAJU",
        "NOMSG_WAIT",
        "RIDDLE",
        "LANDING_DEMO",
        "BGMSTOP",
    };

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
            case 0: // WAIT
                specialProc_WaitStart(staffIdx);
                break;
            case 1: // STRM_PLAY
                mDoAud_bgmStreamPlay();
                break;
            case 2: // STRM_DEMO_MJ_SISTER
                mDoAud_bgmStreamPrepare(0xC0000004);
                break;
            case 3: // STRM_DEMO_GO_MAJU
                mDoAud_bgmStreamPrepare(0xC0000005);
                break;
            case 4: // NOMSG_WAIT
                specialProc_WaitStart(staffIdx);
                break;
            case 5: // RIDDLE
                mDoAud_seStart(JA_SE_READ_RIDDLE_1);
                break;
            case 6: // LANDING_DEMO
                {
                    s32* pPrepare = (s32*)dComIfGp_evmng_getMyIntegerP(staffIdx, "PREPARE");
                    if (pPrepare != NULL) {
                        static u32 landing_table[] = {
                            2, 3, 4, 5, 6, 1, 7,
                        };
                        if (*pPrepare > 6)
                            JUT_ASSERT(0x293, 0);
                        mDoAud_prepareLandingDemo(landing_table[*pPrepare]);
                    }

                    u32 * pStart = dComIfGp_evmng_getMyIntegerP(staffIdx, "START");
                    if (pStart != NULL)
                        mDoAud_startLandingDemo();

                    u32 * pEnd = dComIfGp_evmng_getMyIntegerP(staffIdx, "END");
                    if (pEnd != NULL)
                        mDoAud_endLandingDemo();
                }
                break;
            case 7: // BGMSTOP
                {
                    u32* pTimer = dComIfGp_evmng_getMyIntegerP(staffIdx, "Timer");
                    if (pTimer != NULL)
                        mDoAud_bgmStop(*pTimer);
                }
                break;
        }
    }
    
    switch (actIdx) {
    case 0: // WAIT
        specialProc_WaitProc(staffIdx);
        break;
    case 4: // NOMSG_WAIT
        if (mTimer <= dComIfGp_demo_get()->getFrameNoMsg())
            dComIfGp_evmng_cutEnd(staffIdx);
        break;
    default:
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    }
}

/* 80072748-80072A28       .text specialProcCreate__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcCreate() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("CREATER");
    if (staffIdx == -1) {
        JUT_ASSERT(0x2d3, 0);
        return;
    }

    static char* action_table[] = {
        "WAIT",
        "CREATE",
    };

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
            case 0: // WAIT
                break;
            case 1: // CREATE
            {
                const char * name = dComIfGp_evmng_getMyStringP(staffIdx, "MAKECAST");
                JUT_ASSERT(0x2e3, name);

                dStage_objectNameInf * objectName = dStage_searchName(name);
                JUT_ASSERT(0x2e5, objectName);

                u32* pArg = dComIfGp_evmng_getMyIntegerP(staffIdx, "ARG");
                u32 arg;
                if (pArg == NULL) {
                    arg = 0xFFFFFFFF;
                } else {
                    arg = *pArg;
                }

                cXyz* pPos = dComIfGp_evmng_getMyXyzP(staffIdx, "POS");
                cXyz pos;
                if (pPos == NULL) {
                    pos = dComIfGp_getPlayer(0)->current.pos;
                } else {
                    pos = *pPos;
                }

                s32* pAngle = (s32*)dComIfGp_evmng_getMyIntegerP(staffIdx, "ANGLE");
                csXyz angle;
                if (pAngle == NULL) {
                    angle.setall(0);
                } else {
                    s16 x = pAngle[0];
                    s16 z = pAngle[2];
                    s16 y = pAngle[1];
                    angle.x = x;
                    angle.y = y;
                    angle.z = z;
                }

                cXyz* pScale = dComIfGp_evmng_getMyXyzP(staffIdx, "SCALE");
                cXyz scale;
                if (pScale == NULL) {
                    scale.setall(1.0f);
                } else {
                    scale = *pScale;
                }

                fopAcM_create(objectName->mProcName, arg, &pos, dComIfGp_roomControl_getStayNo(), &angle, &scale, objectName->mSubtype);
            }
            break;
        }
    }
}

/* 80072A28-80073064       .text specialProcDirector__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcDirector() {
    daPy_py_c* player = (daPy_py_c*)dComIfGp_getLinkPlayer();
    int staffIdx = dComIfGp_evmng_getMyStaffId("DIRECTOR");
    if (staffIdx == -1) {
        JUT_ASSERT(0x330, 0);
        return;
    }

    static char* action_table[] = {
        "WAIT",
        "NEXT",
        "FADE",
        "BGM_START",
        "VIBRATION",
        "SE_START",
        "WIPE",
        "PLAYER_DRAW",
        "PLAYER_NODRAW",
    };

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
            case 0: // WAIT
                specialProc_WaitStart(staffIdx);
                break;
            case 1: // NEXT
                dEvDt_Next_Stage(staffIdx, 0);
                break;
            case 2: // FADE
                {
                    f32* rate = dComIfGp_evmng_getMyFloatP(staffIdx, "Rate");
                    u32* color = dComIfGp_evmng_getMyIntegerP(staffIdx, "Color");
                    JUT_ASSERT(0x343, rate);
                    if (*rate > 0.0f) {
                        mDoGph_gInf_c::setFadeRate(0.0f);
                    }

                    if (color != NULL) {
                        GXColor fadeColor;
                        fadeColor.r = color[0];
                        fadeColor.g = color[1];
                        fadeColor.b = color[2];
                        fadeColor.a = color[3];
                        mDoGph_gInf_c::fadeOut(*rate, fadeColor);
                    } else {
                        mDoGph_gInf_c::fadeOut(*rate);
                    }
                }
                break;
            case 3: // BGM_START
                {
                    u32* pBGM = dComIfGp_evmng_getMyIntegerP(staffIdx, "BGM_ID");
                    u32 bgm;
                    static u32 bgm_table[] = {
                        JA_BGM_I_MAJU,
                        JA_BGM_TETRA_MEET,
                        JA_BGM_I_LINK_FOREST,
                    };

                    if (pBGM != NULL) {
                        bgm = *pBGM;
                    } else {
                        bgm = 0;
                    }

                    mDoAud_bgmStart(bgm_table[bgm]);
                }
                break;
            case 4: // VIBRATION
                {
                    specialProc_WaitStart(staffIdx);
                    if (mTimer == 0)
                        JUT_ASSERT(0x36b, 0);

                    const u8* pattern = (const u8*)dComIfGp_evmng_getMyIntegerP(staffIdx, "Pattern");
                    const u32* type = dComIfGp_evmng_getMyIntegerP(staffIdx, "Type");
                    if (pattern == NULL || type == NULL)
                        JUT_ASSERT(0x36f, 0);

                    Vec xyz;
                    xyz.x = 0.0f;
                    xyz.y = 1.0f;
                    xyz.z = 0.0f;
                    dComIfGp_getVibration().StartQuake(pattern, 0, *type, xyz);
                }
                break;
            case 5: // SE_START
                {
                    s32* pSE = (s32*)dComIfGp_evmng_getMyIntegerP(staffIdx, "SENUM");
                    if (pSE != NULL) {
                        static u32 se_table[] = {
                            JA_SE_CM_ZL_FDEMO_JIMEN,
                        };

                        if (*pSE < (s32)ARRAY_SIZE(se_table)) {
                            mDoAud_seStart(se_table[*pSE]);
                        }
                    }
                }
                break;
            case 6: // WIPE
                {
                    f32* rate = dComIfGp_evmng_getMyFloatP(staffIdx, "Rate");
                    JUT_ASSERT(0x384, rate);
                    dDlst_list_c::wipeIn(-*rate);
                    if (*rate > 0.0f)
                        mWipeDirection = 0;
                    else
                        mWipeDirection = 1;
                    u32* sound = dComIfGp_evmng_getMyIntegerP(staffIdx, "SOUND");
                    if (sound != NULL) {
                        switch (*sound) {
                        case 0:
                            mDoAud_seStart(JA_SE_CHUYA_SWITCH);
                            break;
                        }
                    }
                }
                break;
            case 7: // PLAYER_DRAW
                player->offPlayerNoDraw();
                break;
            case 8: // PLAYER_NODRAW
                player->onPlayerNoDraw();
                break;
        }
    }
    
    switch (actIdx) {
        case 0: // WAIT
            specialProc_WaitProc(staffIdx);
            break;
        case 1: // NEXT
            break;
        case 2: // FADE
            {
                if (!mDoGph_gInf_c::isFade()) {
                    dComIfGp_evmng_cutEnd(staffIdx);
                } else if (mDoGph_gInf_c::getFadeRate() >= 1.0f) {
                    f32* rate = dComIfGp_evmng_getMyFloatP(staffIdx, "Rate");
                    JUT_ASSERT(0x3b8, rate);
                    if (*rate > 0.0f)
                        dComIfGp_evmng_cutEnd(staffIdx);
                }
            }
            break;
        case 4: // VIBRATION
            {
                if (mTimer > 0) {
                    mTimer--;
                    if (mTimer == 0)
                        dComIfGp_getVibration().StopQuake(-1);
                } else {
                    dComIfGp_evmng_cutEnd(staffIdx);
                }
            }
            break;
        case 6: // WIPE
            {
                if (mWipeDirection) {
                    if (dDlst_list_c::getWipeRate() == 0.0f)
                        dComIfGp_evmng_cutEnd(staffIdx);
                } else {
                    if (dDlst_list_c::getWipeRate() >= 1.0f)
                        dComIfGp_evmng_cutEnd(staffIdx);
                }
            }
            break;
        default:
            dComIfGp_evmng_cutEnd(staffIdx);
            break;
    }
}

/* 80073064-800733CC       .text specialProcPackage__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcPackage() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("PACKAGE");
    if (staffIdx == -1) {
        JUT_ASSERT(0x3f2, 0);
        return;
    }

    static char* action_table[] = {
        "WAIT",
        "PLAY",
        "PLAY2",
    };

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
        case 0: // WAIT
            specialProc_WaitStart(staffIdx);
            break;
        case 1: // PLAY
        case 2: // PLAY2
            {
                const char* filename = dComIfGp_evmng_getMyStringP(staffIdx, "FileName");
                cXyz* pOffsetPos = dComIfGp_evmng_getMyXyzP(staffIdx, "OffsetPos");
                f32* pOffsetAngY = dComIfGp_evmng_getMyFloatP(staffIdx, "OffsetAngY");

                f32 offsetAngY;
                if (pOffsetAngY != NULL)
                    offsetAngY = *pOffsetAngY;
                else
                    offsetAngY = 0.0f;

                void* demo_data = NULL;
                const char* demo_arc = dStage_roomControl_c::getDemoArcName();
                if (demo_arc[0] != '\0')
                    demo_data = dComIfG_getObjectRes(demo_arc, filename);
                if (demo_data == NULL)
                    demo_data = dComIfG_getStageRes("Stage", filename);
                JUT_ASSERT(0x42e, demo_data);
                dComIfGp_demo_create((const u8*)demo_data, pOffsetPos, offsetAngY);
                dComIfGp_event_setCullRate(10.0f);
                u32* eventFlag = dComIfGp_evmng_getMyIntegerP(staffIdx, "EventFlag");
                if (eventFlag != NULL)
                    dComIfGs_onEventBit(*eventFlag);
            }
            break;
        }
    }

    switch (actIdx) {
    case 0: // WAIT
        specialProc_WaitProc(staffIdx);
        break;
    case 1: // PLAY
        {
            if (mWipeDirection == 0) {
                if (dComIfGp_demo_mode() == 2) {
                    if (dEvDt_Next_Stage(staffIdx, 5)) {
                        mWipeDirection = 1;
                    } else {
                        dComIfGp_demo_remove();
                    }
                }

                if (dComIfGp_demo_mode() == 0) {
                    dComIfGp_evmng_cutEnd(staffIdx);
                }
            }
        }
        break;
    case -1:
        JUT_ASSERT(0x45c, 0);
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    }
}

/* 800733CC-800735BC       .text specialProcTimekeeper__12dEvDtStaff_cFv */
void dEvDtStaff_c::specialProcTimekeeper() {
    int staffIdx = dComIfGp_evmng_getMyStaffId("TIMEKEEPER");
    if (staffIdx == -1) {
        JUT_ASSERT(0x471, 0);
        return;
    }

    static char* action_table[] = {
        "COUNTDOWN",
        "WAIT",
    };

    int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, ARRAY_SIZE(action_table), 0, 0);
    if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
        switch (actIdx) {
        case 0: // COUNTDOWN
            {
                u32* idata = dComIfGp_evmng_getMyIntegerP(staffIdx, "Timer");
                JUT_ASSERT(0x482, idata);
                mTimer = *idata;
            }
            break;
        case 1: // WAIT
            break;
        }
    }

    switch (actIdx) {
    case 0: // COUNTDOWN
        {
            if (mTimer > 0)
                mTimer--;
            else
                dComIfGp_evmng_cutEnd(staffIdx);
        }
        break;
    case 1: // WAIT
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    case -1:
        JUT_ASSERT(0x49f, 0);
        dComIfGp_evmng_cutEnd(staffIdx);
        break;
    }
}

/* 800735BC-8007364C       .text startCheck__10dEvDtCut_cFv */
s32 dEvDtCut_c::startCheck() {
    for (s32 i = 0; i < (s32)ARRAY_SIZE(mFlagCheck); i++) {
        int flag_id = mFlagCheck[i];
        if (flag_id == -1) {
            return i == 0 ? -1 : 1;
        }
        if (!dEvDtFlagCheck(flag_id))
            return 0;
    }
    return 1;
}

/* 8007364C-80073674       .text init__11dEvDtBase_cFv */
void dEvDtBase_c::init() {
    mHeaderP = NULL;
    mEventP = NULL;
    mStaffP = NULL;
    mCutP = NULL;
    mDataP = NULL;
    mFDataP = NULL;
    mIDataP = NULL;
    mSDataP = NULL;
}

/* 80073674-800736E4       .text advanceCut__11dEvDtBase_cFP12dEvDtEvent_c */
void dEvDtBase_c::advanceCut(dEvDtEvent_c* evt) {
    for (s32 i = 0; i < evt->getNStaff(); i++)
        advanceCutLocal(&mStaffP[evt->getStaff(i)]);
}

/* 800736E4-800737DC       .text advanceCutLocal__11dEvDtBase_cFP12dEvDtStaff_c */
bool dEvDtBase_c::advanceCutLocal(dEvDtStaff_c* staff) {
    dEvDtCut_c * cutP = &mCutP[staff->getCurrentCut()];

    if (cutP->getNext() != -1) {
        switch (mCutP[cutP->getNext()].startCheck()) {
        case -1:
            u32 flag_id = cutP->getFlagId();
            if (dEvDtFlagCheck(flag_id)) {
                staff->advanceCut(cutP->getNext());
                return true;
            }
            break;
        case 1:
            flag_id = cutP->getFlagId();
            dEvDtFlagSet(flag_id);
            staff->advanceCut(cutP->getNext());
            return true;
        }
    }

    if (staff->mAdvance > 1)
        staff->mAdvance = 1;
    else
        staff->mAdvance = 0;
    return false;
}

