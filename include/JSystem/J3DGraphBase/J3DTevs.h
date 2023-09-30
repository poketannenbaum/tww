#ifndef J3DTEVS_H
#define J3DTEVS_H

#include "JSystem/J3DGraphBase/J3DGD.h"
#include "JSystem/J3DGraphBase/J3DStruct.h"

extern u8 j3dTevSwapTableTable[1024];

extern const J3DLightInfo j3dDefaultLightInfo;
extern const J3DTexCoordInfo j3dDefaultTexCoordInfo[8];
extern const J3DTexMtxInfo j3dDefaultTexMtxInfo;
extern const J3DIndTexMtxInfo j3dDefaultIndTexMtxInfo;
extern const J3DTevStageInfo j3dDefaultTevStageInfo;
extern const J3DIndTevStageInfo j3dDefaultIndTevStageInfo;
extern const J3DFogInfo j3dDefaultFogInfo;
extern const J3DNBTScaleInfo j3dDefaultNBTScaleInfo;

extern const GXColor j3dDefaultColInfo;
extern const GXColor j3dDefaultAmbInfo;
extern const u8 j3dDefaultColorChanNum;
extern const J3DTevOrderInfo j3dDefaultTevOrderInfoNull;
extern const J3DIndTexOrderInfo j3dDefaultIndTexOrderNull;
extern const GXColorS10 j3dDefaultTevColor;
extern const J3DIndTexCoordScaleInfo j3dDefaultIndTexCoordScaleInfo;
extern const GXColor j3dDefaultTevKColor;
extern const J3DTevSwapModeInfo j3dDefaultTevSwapMode;
extern const J3DTevSwapModeTableInfo j3dDefaultTevSwapModeTable;
extern const J3DBlendInfo j3dDefaultBlendInfo;
extern const J3DColorChanInfo j3dDefaultColorChanInfo;
extern const u16 j3dDefaultTevSwapTableID;
extern const u16 j3dDefaultAlphaCmpID;
extern const u16 j3dDefaultZModeID;

struct J3DTevStageTevSwapModeInfo {
    u8 field_0x0_29 : 2;
    u8 field_0x0_31 : 2;
};

struct J3DTevStage {
    J3DTevStage() {
        setTevStageInfo(j3dDefaultTevStageInfo);
        mTevSwapModeInfo.field_0x0_29 = 0;
        mTevSwapModeInfo.field_0x0_31 = 0;
    }
    J3DTevStage(const J3DTevStageInfo& info) {
        setTevStageInfo(info);
        mTevSwapModeInfo.field_0x0_29 = 0;
        mTevSwapModeInfo.field_0x0_31 = 0;
    }
    J3DTevStage& operator=(const J3DTevStage& other) {
        this->field_0x1 = other.field_0x1;
        this->field_0x2 = other.field_0x2;
        this->field_0x3 = other.field_0x3;
        this->field_0x5 = other.field_0x5;
        this->field_0x6 = other.field_0x6;
        this->mTevSwapModeInfo = other.mTevSwapModeInfo;
        return *this;
    }

    void setTevStageInfo(const J3DTevStageInfo&);

    void load(u32) const {
        J3DGDWriteBPCmd(*(u32*)&field_0x0);
        J3DGDWriteBPCmd(*(u32*)&field_0x4);
    }

    /* 0x0 */ u8 field_0x0;
    /* 0x1 */ u8 field_0x1;
    /* 0x1 */ u8 field_0x2;
    /* 0x3 */ u8 field_0x3;
    /* 0x4 */ u8 field_0x4;
    /* 0x5 */ u8 field_0x5;
    /* 0x6 */ u8 field_0x6;
    /* 0x7 */ J3DTevStageTevSwapModeInfo mTevSwapModeInfo;
};

struct J3DIndTevStage {
    J3DIndTevStage();

    void load(u32 param_1) {
        J3DGDWriteBPCmd(mInfo | (param_1 + 16) << 24);
    }

    /* 0x0 */ u32 mInfo;
};

struct J3DTevOrder : public J3DTevOrderInfo {
    J3DTevOrder();

    J3DTevOrderInfo& getTevOrderInfo() { return *this; }
    u8 getTexMap() { return mTexMap; }
};

struct J3DTevSwapModeTable {
    J3DTevSwapModeTable();

    u8 getR() { return j3dTevSwapTableTable[field_0x0 * 4]; }
    u8 getG() { return j3dTevSwapTableTable[field_0x0 * 4 + 1]; }
    u8 getB() { return j3dTevSwapTableTable[field_0x0 * 4 + 2]; }
    u8 getA() { return j3dTevSwapTableTable[field_0x0 * 4 + 3]; }

    /* 0x0 */ u8 field_0x0;
};  // Size: 0x1

class J3DLightObj {
public:
    /* 80018C0C */ J3DLightObj() { mInfo = j3dDefaultLightInfo; }
    /* 80323590 */ void load(u32) const;

    J3DLightInfo& getLightInfo() { return mInfo; }
    J3DLightObj& operator=(J3DLightObj const& other) {
        mInfo = other.mInfo;
        return *this;
    }

    /* 0x00 */ J3DLightInfo mInfo;
    /* 0x34 */ u8 field_0x34[64];
};  // Size = 0x74

struct J3DNBTScale : public J3DNBTScaleInfo {
    J3DNBTScale() {}
    J3DNBTScale(J3DNBTScaleInfo const& info) {
        mbHasScale = info.mbHasScale;
        mScale = info.mScale;
    }
    Vec* getScale() { return &mScale; }
};

class J3DTexCoord;
void loadTexCoordGens(u32, J3DTexCoord*);
void loadNBTScale(J3DNBTScale& param_0);

#endif /* J3DTEVS_H */
