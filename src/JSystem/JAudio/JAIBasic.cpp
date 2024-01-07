//
// Generated by dtk
// Translation Unit: JAIBasic.cpp
//

#include "JSystem/JAudio/JAIBasic.h"
#include "JSystem/JAudio/JAIBankWave.h"
#include "JSystem/JAudio/JAIConst.h"
#include "JSystem/JAudio/JAIDummyObject.h"
#include "JSystem/JAudio/JAIFx.h"
#include "JSystem/JAudio/JAIGlobalParameter.h"
#include "JSystem/JAudio/JAIInitData.h"
#include "JSystem/JAudio/JAISeMgr.h"
#include "JSystem/JAudio/JAISequenceHeap.h"
#include "JSystem/JAudio/JAISequenceMgr.h"
#include "JSystem/JAudio/JAIStreamMgr.h"
#include "JSystem/JAudio/JASAudioThread.h"
#include "JSystem/JAudio/JASDriverIF.h"
#include "JSystem/JAudio/JASSystemHeap.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "stdio.h"
#include "string.h"

namespace JAIInitData = JAInter::InitData;
namespace JAISequenceMgr = JAInter::SequenceMgr;

const int JAI_INIT_MODE_MAX = 5;

JAIBasic* JAIBasic::msBasic;
JKRSolidHeap* JAIBasic::msCurrentHeap;

/* 8028FC48-8028FCC4       .text __ct__8JAIBasicFv */
JAIBasic::JAIBasic() {
    msBasic = this;
    field_0xe.flag1 = 0;
    field_0xe.flag2 = 0;
    field_0xe.flag3 = 0;
    field_0xe.flag4 = 0;
    field_0xe.flag5 = 0;
    field_0x14 = 0;
    mAudioCamera = NULL;
    field_0x10 = 0;
    initLoadFileSw = 2;
    field_0x1c = 0;
    field_0x8 = NULL;
    field_0x18 = 0;
    msCurrentHeap = JASDram;
}

/* 8028FCC4-8028FCE4       .text initDriver__8JAIBasicFP12JKRSolidHeapUlUc */
void JAIBasic::initDriver(JKRSolidHeap* param_1, u32 param_2, u8 param_3) {
    initAudioThread(param_1, param_2, param_3);
}

/* 8028FCE4-8028FD04       .text initInterface__8JAIBasicFUc */
void JAIBasic::initInterface(u8) {
    initInterfaceMain();
}

/* 8028FD04-8028FDC0       .text initInterfaceMain__8JAIBasicFv */
void JAIBasic::initInterfaceMain() {
    initHeap();
    initResourcePath();
    initArchive();
    if (initReadFile()) {
        if (!field_0xe.flag1) {
            JAInter::BankWave::setWaveScene();
        }
        JAInter::DummyObjectMgr::init();
        JAInter::Fx::init();
        JAInter::SequenceMgr::init();
        JAInter::SeMgr::init();
        JAInter::StreamMgr::init();
        JAInter::HeapMgr::init(JAIGlobalParameter::stayHeapMax, JAIGlobalParameter::stayHeapSize, JAIGlobalParameter::autoHeapMax, JAIGlobalParameter::autoHeapRoomSize);
        initCamera();
        initStream();
        JAInter::SeMgr::startSeSequence();
        if (!field_0xe.flag1) {
            JAInter::SequenceMgr::checkEntriedSeq();
        }
    }
}

/* 8028FDC0-8028FE78       .text initHeap__8JAIBasicFv */
void JAIBasic::initHeap() {
    if (JAIGlobalParameter::interfaceHeapSize) {
        field_0x8 = JKRSolidHeap::create(JAIGlobalParameter::interfaceHeapSize, JASDram, false);
        msCurrentHeap = field_0x8;
    } else {
        msCurrentHeap = JASDram;
        if (msCurrentHeap) {
            return;
        }
    }
    JUT_ASSERT_MSG(186, msCurrentHeap, "JAIBasic::initHeap オーディオヒープが異常（NULL）です。\n");
}

/* 8028FE78-8028FF20       .text initArchive__8JAIBasicFv */
void JAIBasic::initArchive() {
    char buffer[0x60];
    if (!JAISequenceMgr::arcPointer) {
        JAISequenceMgr::getArchiveName(buffer);
        JAISequenceMgr::arcPointer = JKRArchive::mount(buffer, JKRArchive::MOUNT_DVD, msCurrentHeap, JKRArchive::MOUNT_DIRECTION_HEAD);
        JUT_ASSERT_MSG(206, JAISequenceMgr::arcPointer, "JAIBasic::initArchive シーケンスアーカイブのマウントに失敗しました。\n");
    }
}

/* 8028FF20-8028FFF8       .text initResourcePath__8JAIBasicFv */
void JAIBasic::initResourcePath() {
    if (JAIGlobalParameter::audioResPath) {
        char* wavePath = (char*)JASDram->alloc(strlen(JAIGlobalParameter::audioResPath) + strlen(JAIGlobalParameter::wavePath) + 1, 0);
        sprintf(wavePath, "%s%s%c", JAIGlobalParameter::audioResPath, JAIGlobalParameter::wavePath, 0);
        JAIGlobalParameter::wavePath = wavePath;
        char* streamPath = (char*)JASDram->alloc(strlen(JAIGlobalParameter::audioResPath) + strlen(JAIGlobalParameter::streamPath) + 1, 0);
        sprintf(streamPath, "%s%s%c", JAIGlobalParameter::audioResPath, JAIGlobalParameter::streamPath, 0);
        JAIGlobalParameter::streamPath = streamPath;
    }
}

/* 8028FFF8-8029002C       .text setCameraInfo__8JAIBasicFP3VecP3VecPA4_fUl */
void JAIBasic::setCameraInfo(Vec* param_1, Vec* param_2, MtxP param_3, u32 param_4) {
    if (JAIGlobalParameter::audioCameraMax <= param_4) {
        return;
    }
    mAudioCamera[param_4].field_0x0 = param_1;
    mAudioCamera[param_4].field_0x4 = param_2;
    mAudioCamera[param_4].field_0x8 = param_3;
}

/* 8029002C-80290068       .text initStream__8JAIBasicFv */
void JAIBasic::initStream() {
    if (!field_0xe.flag4) {
        JAInter::StreamLib::init(field_0xe.flag5);
    }
}

/* 80290068-80290090       .text setRegisterTrackCallback__8JAIBasicFv */
void JAIBasic::setRegisterTrackCallback() {
    JASystem::TTrack::registerSeqCallback(setParameterSeqSync);
}

/* 80290090-8029011C       .text initAudioThread__8JAIBasicFP12JKRSolidHeapUlUc */
void JAIBasic::initAudioThread(JKRSolidHeap* param_1, u32 param_2, u8 param_3) {
    int r31 = 1;
    if (param_3 & 1) {
        r31 |= 2;
    }
    JASystem::TAudioThread::setPriority(JAIGlobalParameter::audioSystemThreadPriority, JAIGlobalParameter::audioDvdThreadPriority);
    JASystem::TAudioThread::start(param_1, param_2, r31);
    JASystem::TTrack::newMemPool(JAIGlobalParameter::systemTrackMax);
    setRegisterTrackCallback();
    JASystem::Driver::setMixerLevel(JAIGlobalParameter::inputGainDown, JAIGlobalParameter::outputGainUp);
}

/* 8029011C-8029031C       .text initCamera__8JAIBasicFv */
void JAIBasic::initCamera() {
    mAudioCamera = new (JAIBasic::getCurrentJAIHeap(), 0x20) JAInter::Camera[JAIGlobalParameter::audioCameraMax];
    JUT_ASSERT_MSG(291, mAudioCamera, "JAIBasic::initAllocParameter Cannot Alloc Heap!! (mAudioCamera)\n");
    if (!mAudioCamera->field_0x0) {
        JAInter::Const::nullCamera.field_0x0->x = 0.0f;
        JAInter::Const::nullCamera.field_0x0->y = 0.0f;
        JAInter::Const::nullCamera.field_0x0->z = -50.0f;
        JAInter::Const::nullCamera.field_0x4->x = 0.0f;
        JAInter::Const::nullCamera.field_0x4->y = 0.0f;
        JAInter::Const::nullCamera.field_0x4->z = -50.0f;
        Vec local_2c;
        local_2c.x = 0.0f;
        local_2c.y = 1.0f;
        local_2c.z = 0.0f;
        Vec local_38;
        local_38.x = JAInter::Const::dummyZeroVec.x;
        local_38.y = JAInter::Const::dummyZeroVec.y;
        local_38.z = JAInter::Const::dummyZeroVec.z;
        C_MTXLookAt(JAInter::Const::camMtx, JAInter::Const::nullCamera.field_0x0, &local_2c, &local_38);
        for (u32 i = 0; i < JAIGlobalParameter::audioCameraMax; i++) {
            setCameraInfo(JAInter::Const::nullCamera.field_0x0, JAInter::Const::nullCamera.field_0x4, JAInter::Const::camMtx, i);
        }
    }
}

/* 80290330-8029046C       .text initReadFile__8JAIBasicFv */
BOOL JAIBasic::initReadFile() {
    switch (initLoadFileSw) {
    case 2:
        if (JAIInitData::checkInitDataFile()) {
            break;
        }
        return false;
    case 4:
        if (JAIInitData::aafPointer) {
            JAIInitData::checkInitDataOnMemory();
            break;
        }
        JUT_ASSERT_MSG(349, JAIInitData::aafPointer, "JAIBasic::initReadFile Init Data Pointer is NULL !!!\n");
        break;
    default:
        JUT_ASSERT_MSG(353, initLoadFileSw>=JAI_INIT_MODE_MAX, "JAIBasic::initReadFile 初期設定読み込みモードが異常です。\n");
        break;
    }
    return true;
}

/* 8029046C-802904B4       .text processFrameWork__8JAIBasicFv */
void JAIBasic::processFrameWork() {
    /* Nonmatching */
}

/* 802904B4-802904EC       .text startSoundVec__8JAIBasicFUlPP8JAISoundP3VecUlUlUc */
void JAIBasic::startSoundVec(u32, JAISound**, Vec*, u32, u32, u8) {
    /* Nonmatching */
}

/* 802904EC-8029050C       .text startSoundActor__8JAIBasicFUlPP8JAISoundPQ27JAInter5ActorUlUc */
void JAIBasic::startSoundActor(u32 param_1, JAISound** param_2, JAInter::Actor* param_3, u32 param_4, u8 param_5) {
    startSoundDirectID(param_1, param_2, param_3, param_4, param_5);
}

/* 8029050C-8029057C       .text startSoundDirectID__8JAIBasicFUlPP8JAISoundPQ27JAInter5ActorUlUc */
void JAIBasic::startSoundDirectID(u32, JAISound**, JAInter::Actor*, u32, u8) {
    /* Nonmatching */
}

/* 8029057C-80290708       .text startSoundBasic__8JAIBasicFUlPP8JAISoundPQ27JAInter5ActorUlUcPv */
void JAIBasic::startSoundBasic(u32, JAISound**, JAInter::Actor*, u32, u8, void*) {
    /* Nonmatching */
}

/* 80290708-802907E0       .text stopSoundHandle__8JAIBasicFP8JAISoundUl */
void JAIBasic::stopSoundHandle(JAISound*, u32) {
    /* Nonmatching */
}

/* 802907E0-80290864       .text stopPlayingCategoryObjectSe__8JAIBasicFUcPv */
void JAIBasic::stopPlayingCategoryObjectSe(u8, void*) {
    /* Nonmatching */
}

/* 80290864-80290884       .text stopAllSe__8JAIBasicFUcPv */
void JAIBasic::stopAllSe(u8 param_1, void* param_2) {
    stopPlayingCategoryObjectSe(param_1, param_2);
}

/* 80290884-802908E8       .text stopActorSoundOneBuffer__8JAIBasicFPvP8JAISound */
void JAIBasic::stopActorSoundOneBuffer(void*, JAISound*) {
    /* Nonmatching */
}

/* 802908E8-8029094C       .text stopIDSoundOneBuffer__8JAIBasicFUlP8JAISound */
void JAIBasic::stopIDSoundOneBuffer(u32, JAISound*) {
    /* Nonmatching */
}

/* 8029094C-802909C0       .text stopIDActorSoundOneBuffer__8JAIBasicFUlPvP8JAISound */
void JAIBasic::stopIDActorSoundOneBuffer(u32, void*, JAISound*) {
    /* Nonmatching */
}

/* 802909C0-80290A5C       .text stopAllSound__8JAIBasicFPv */
void JAIBasic::stopAllSound(void*) {
    /* Nonmatching */
}

/* 80290A5C-80290B64       .text stopAllSound__8JAIBasicFUl */
void JAIBasic::stopAllSound(u32) {
    /* Nonmatching */
}

/* 80290B64-80290C74       .text stopAllSound__8JAIBasicFUlPv */
void JAIBasic::stopAllSound(u32, void*) {
    /* Nonmatching */
}

/* 80290C74-80290D94       .text deleteObject__8JAIBasicFPv */
void JAIBasic::deleteObject(void*) {
    /* Nonmatching */
}

/* 80290D94-80290DA0       .text getMapInfoFxline__8JAIBasicFUl */
BOOL JAIBasic::getMapInfoFxline(u32 param_1) {
    return param_1 ? TRUE : FALSE;
}

/* 80290DA0-80290DAC       .text getMapInfoGround__8JAIBasicFUl */
BOOL JAIBasic::getMapInfoGround(u32 param_1) {
    return param_1 ? TRUE : FALSE;
}

/* 80290DAC-80290DC4       .text getMapInfoFxParameter__8JAIBasicFUl */
f32 JAIBasic::getMapInfoFxParameter(u32 param_1) {
    /* Nonmatching */
    if (param_1 == 0) {
        return 0.0f;
    }
    return 1.0f;
}

/* 80290DC4-80290E14       .text getSoundOffsetNumberFromID__8JAIBasicFUl */
void JAIBasic::getSoundOffsetNumberFromID(u32) {
    /* Nonmatching */
}

/* 80290E14-80290E50       .text setSeCategoryVolume__8JAIBasicFUcUc */
void JAIBasic::setSeCategoryVolume(u8, u8) {
    /* Nonmatching */
}

/* 80290E50-80291034       .text setParameterSeqSync__8JAIBasicFPQ28JASystem6TTrackUs */
u16 JAIBasic::setParameterSeqSync(JASystem::TTrack*, u16) {
    /* Nonmatching */
}

/* 80291034-80291114       .text setSeExtParameter__8JAIBasicFP8JAISound */
void JAIBasic::setSeExtParameter(JAISound*) {
    /* Nonmatching */
}

/* 80291114-802911A8       .text makeSound__8JAIBasicFUl */
JAISound* JAIBasic::makeSound(u32) {
    /* Nonmatching */
}

/* 802911A8-80291200       .text allocStreamBuffer__8JAIBasicFPvl */
bool JAIBasic::allocStreamBuffer(void*, s32) {
    /* Nonmatching */
}

/* 80291200-80291220       .text deallocStreamBuffer__8JAIBasicFv */
bool JAIBasic::deallocStreamBuffer() {
    /* Nonmatching */
}
