//
// Generated by dtk
// Translation Unit: JUTResFont.cpp
//

#include "JSystem/JUtility/JUTResFont.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JSupport/JSupport.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/JUtility/JUTConsole.h"
#include "JSystem/JUtility/JUTDataHeader.h"
#include "dolphin/gx/GX.h"
#include "dolphin/types.h"

IsLeadByte_func const JUTResFont::saoAboutEncoding_[3] = {
    isLeadByte_1Byte,
    isLeadByte_2Byte,
    isLeadByte_ShiftJIS,
};

/* 802C2044-802C2090       .text __ct__10JUTResFontFv */
JUTResFont::JUTResFont() {
    initialize_state();
    JUTFont::initialize_state();
}

/* 802C2090-802C20F4       .text __ct__10JUTResFontFPC7ResFONTP7JKRHeap */
JUTResFont::JUTResFont(const ResFONT* pFont, JKRHeap* pHeap) {
    initialize_state();
    initiate(pFont, pHeap);
}

/* 802C20F4-802C2180       .text __dt__10JUTResFontFv */
JUTResFont::~JUTResFont() {
    if (mValid) {
        delete_and_initialize();
        JUTFont::initialize_state();
    }
}

/* 802C2180-802C21A4       .text deleteMemBlocks_ResFont__10JUTResFontFv */
void JUTResFont::deleteMemBlocks_ResFont() {
    delete[] mpMemBlocks;
}

/* 802C21A4-802C21D0       .text initialize_state__10JUTResFontFv */
void JUTResFont::initialize_state() {
    mResFont = NULL;
    mpMemBlocks = NULL;
    mpWidthBlocks = NULL;
    mpGlyphBlocks = NULL;
    mpMapBlocks = NULL;
    mWidth = 0;
    mHeight = 0;
    mTexPageIdx = -1;
}

/* 802C21D0-802C2230       .text initiate__10JUTResFontFPC7ResFONTP7JKRHeap */
bool JUTResFont::initiate(const ResFONT* pFont, JKRHeap* pHeap) {
    u8 initiated = protected_initiate(pFont, pHeap);
    if (!initiated) {
        delete_and_initialize();
        JUTFont::initialize_state();
        mValid = false;
        return false;
    }
    return true;
}

/* 802C2230-802C233C       .text protected_initiate__10JUTResFontFPC7ResFONTP7JKRHeap */
bool JUTResFont::protected_initiate(const ResFONT* pFont, JKRHeap* pHeap) {
    delete_and_initialize();
    JUTFont::initialize_state();
    if (pFont == NULL) {
        return false;
    }
    mResFont = pFont;
    mValid = true;
    countBlock();

    u32 blockNum = mWidthBlockNum + mGlyphBlockNum + mMapBlockNum;
    mpMemBlocks = new (pHeap, 0) void*[blockNum];

    void** block = mpMemBlocks;

    if (block == NULL) {
        return false;
    } else {
        if (mWidthBlockNum != 0) {
            mpWidthBlocks = (ResFONT::WID1**)block;
            block += mWidthBlockNum;
        }
        if (mGlyphBlockNum != 0) {
            mpGlyphBlocks = (ResFONT::GLY1**)block;
            block += mGlyphBlockNum;
        }
        if (mMapBlockNum != 0) {
            mpMapBlocks = (ResFONT::MAP1**)block;
        }
        setBlock();
        return true;
    }
}

/* 802C233C-802C2438       .text countBlock__10JUTResFontFv */
void JUTResFont::countBlock() {
    mWidthBlockNum = 0;
    mGlyphBlockNum = 0;
    mMapBlockNum = 0;

    const JUTDataBlockHeader* header = (JUTDataBlockHeader*)mResFont->data;
    for (u32 i = 0; i < mResFont->numBlocks; i++, header = header->getNext()) {
        switch (header->mType) {
        case 'WID1':
            mWidthBlockNum++;
            break;
        case 'GLY1':
            mGlyphBlockNum++;
            break;
        case 'MAP1':
            mMapBlockNum++;
            break;
        case 'INF1':
            break;
        default:
            JUTReportConsole("JUTResFont: Unknown data block\n");
        }
    }
}

/* 802C2438-802C25C0       .text setBlock__10JUTResFontFv */
void JUTResFont::setBlock() {
    int widthNum = 0;
    int glyphNum = 0;
    int mapNum = 0;
    mMaxCode = -1;

    const JUTDataBlockHeader* header = (JUTDataBlockHeader*)mResFont->data;
    for (u32 i = 0; i < mResFont->numBlocks; i++, header = header->getNext()) {
        switch (header->mType) {
        case 'INF1':
            mInfoBlock = (ResFONT::INF1*)header;
            u32 u = mInfoBlock->fontType;
            JUT_ASSERT(0xF3, u < suAboutEncoding_)
            mIsLeadByte = (IsLeadByte_func*)&saoAboutEncoding_[u];
            break;
        case 'WID1':
            mpWidthBlocks[widthNum] = (ResFONT::WID1*)header;
            widthNum++;
            break;
        case 'GLY1':
            mpGlyphBlocks[glyphNum] = (ResFONT::GLY1*)header;
            glyphNum++;
            break;
        case 'MAP1':
            mpMapBlocks[mapNum] = (ResFONT::MAP1*)header;
            if (mMaxCode > mpMapBlocks[mapNum]->startCode) {
                mMaxCode = mpMapBlocks[mapNum]->startCode;
            }
            mapNum++;
            break;
        default:
            JUTReportConsole("Unknown data block\n");
            break;
        }
    }
}

/* 802C25C0-802C26B8       .text setGX__10JUTResFontFv */
void JUTResFont::setGX() {
    GXSetNumChans(1);
    GXSetNumTevStages(1);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRC_ALPHA, GX_BL_INV_SRC_ALPHA, GX_LO_SET);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 0xf);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
}

/* 802C26B8-802C28F8       .text setGX__10JUTResFontFQ28JUtility6TColorQ28JUtility6TColor */
void JUTResFont::setGX(JUtility::TColor col1, JUtility::TColor col2) {
    if (col1 == 0 && col2 == -1) {
        setGX();
    } else {
        GXSetNumChans(1);
        GXSetNumTevStages(2);
        GXSetNumTexGens(1);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
        GXSetTevColor(GX_TEVREG0, col1);
        GXSetTevColor(GX_TEVREG1, col2);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C0, GX_CC_C1, GX_CC_TEXC, GX_CC_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A0, GX_CA_A1, GX_CA_TEXA, GX_CA_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRC_ALPHA, GX_BL_INV_SRC_ALPHA, GX_LO_SET);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 15);
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    }
}

/* 802C28F8-802C2D6C       .text drawChar_scale__10JUTResFontFffffib */
f32 JUTResFont::drawChar_scale(f32 posX, f32 posY, f32 scaleX, f32 scaleY, int chr, bool flag) {
    JUTFont::TWidth width;
    f32 x1;
    f32 y1;
    f32 scaledHeight;
    f32 x2;

    JUT_ASSERT(0x179, mValid)
    loadFont(chr, GX_TEXMAP0, &width);

    if (mFixed || !flag) {
        x1 = posX;
    } else {
        x1 = (posX - width.field_0x0 * (scaleX / getCellWidth()));
    }
    f32 retval = mFixedWidth * (scaleX / getCellWidth());
    if (!mFixed) {
        if (!flag) {
            retval = (width.field_0x1 + width.field_0x0) * (scaleX / getCellWidth());
        } else {
            retval = width.field_0x1 * (scaleX / getCellWidth());
        }
    }
    x2 = x1 + scaleX;
    y1 = posY - getAscent() * (scaleY / getHeight());
    scaledHeight = scaleY / getHeight();
    f32 descent = getDescent();
    f32 y2 = descent * scaledHeight + posY;

    // Glyph details
    int u1 = (mWidth * 0x8000) / mpGlyphBlocks[field_0x66]->textureWidth;
    int v1 = (mHeight * 0x8000) / mpGlyphBlocks[field_0x66]->textureHeight;
    s32 u2 = ((mWidth + mpGlyphBlocks[field_0x66]->cellWidth) * 0x8000) / mpGlyphBlocks[field_0x66]->textureWidth;
    s32 v2 = ((mHeight + mpGlyphBlocks[field_0x66]->cellHeight) * 0x8000) / mpGlyphBlocks[field_0x66]->textureHeight;

    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);

    // Bottom Left
    GXPosition3f32(x1, y1, 0.0f);
    GXColor1u32(mColor1);
    GXTexCoord2s16(u1, v1);

    // Bottom Right
    GXPosition3f32(x2, y1, 0.0f);
    GXColor1u32(mColor2);
    GXTexCoord2s16(u2, v1);

    // Top Right
    GXPosition3f32(x2, y2, 0.0f);
    GXColor1u32(mColor4);
    GXTexCoord2s16(u2, v2);

    // Top Left
    GXPosition3f32(x1, y2, 0.0f);
    GXColor1u32(mColor3);
    GXTexCoord2s16(u1, v2);

    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);

    return retval;
}

/* 802C2D6C-802C2DE8       .text loadFont__10JUTResFontFi11_GXTexMapIDPQ27JUTFont6TWidth */
void JUTResFont::loadFont(int code, _GXTexMapID texMapID, JUTFont::TWidth* pDstWidth) {
    if (pDstWidth) {
        getWidthEntry(code, pDstWidth);
    }
    u32 fontCode = getFontCode(code);
    loadImage(fontCode, texMapID);
}

/* 802C2DE8-802C2E90       .text getWidthEntry__10JUTResFontCFiPQ27JUTFont6TWidth */
void JUTResFont::getWidthEntry(int code, JUTFont::TWidth* width) const {
    int fontCode = getFontCode(code);
    width->field_0x0 = 0;
    width->field_0x1 = mInfoBlock->width;

    for (int i = 0; i < mWidthBlockNum; i++) {
        if (mpWidthBlocks[i]->startCode <= fontCode && fontCode <= mpWidthBlocks[i]->endCode) {
            int chunkNum = (fontCode - mpWidthBlocks[i]->startCode) * 2;
            u8* ptr = &mpWidthBlocks[i]->mChunkNum[chunkNum];
            width->field_0x0 = ptr[0];
            width->field_0x1 = ptr[1];
            break;
        }
    }
}

/* 802C2E90-802C2EDC       .text getCellWidth__10JUTResFontCFv */
int JUTResFont::getCellWidth() const {
    if (mpGlyphBlocks) {
        ResFONT::GLY1* glyph = *mpGlyphBlocks;
        if (glyph) {
            return glyph->cellWidth;
        }
    }
    return getWidth();
}

/* 802C2EDC-802C2F28       .text getCellHeight__10JUTResFontCFv */
s32 JUTResFont::getCellHeight() const {
    if (mpGlyphBlocks) {
        ResFONT::GLY1* glyph = *mpGlyphBlocks;
        if (glyph) {
            return glyph->cellHeight;
        }
    }
    return getHeight();
}

/* 802C2F28-802C2F5C       .text isLeadByte__10JUTResFontCFi */
bool JUTResFont::isLeadByte(int chr) const {
    return (*mIsLeadByte)(chr);
}

/* 802C2F5C-802C30E4       .text getFontCode__10JUTResFontCFi */
int JUTResFont::getFontCode(int chr) const {
    static const u16 halftofull[95] = {
        0x8140, 0x8149, 0x8168, 0x8194, 0x8190, 0x8193, 0x8195, 0x8166, 0x8169, 0x816A, 0x8196,
        0x817B, 0x8143, 0x817C, 0x8144, 0x815E, 0x824F, 0x8250, 0x8251, 0x8252, 0x8253, 0x8254,
        0x8255, 0x8256, 0x8257, 0x8258, 0x8146, 0x8147, 0x8183, 0x8181, 0x8184, 0x8148, 0x8197,
        0x8260, 0x8261, 0x8262, 0x8263, 0x8264, 0x8265, 0x8266, 0x8267, 0x8268, 0x8269, 0x826A,
        0x826B, 0x826C, 0x826D, 0x826E, 0x826F, 0x8270, 0x8271, 0x8272, 0x8273, 0x8274, 0x8275,
        0x8276, 0x8277, 0x8278, 0x8279, 0x816D, 0x818F, 0x816E, 0x814F, 0x8151, 0x8165, 0x8281,
        0x8282, 0x8283, 0x8284, 0x8285, 0x8286, 0x8287, 0x8288, 0x8289, 0x828A, 0x828B, 0x828C,
        0x828D, 0x828E, 0x828F, 0x8290, 0x8291, 0x8292, 0x8293, 0x8294, 0x8295, 0x8296, 0x8297,
        0x8298, 0x8299, 0x829A, 0x816F, 0x8162, 0x8170, 0x8160,
    };

    int ret = mInfoBlock->defaultCode;
    if ((getFontType() == 2) && (mMaxCode >= 0x8000u) && (chr >= 0x20) && (chr < 0x7Fu)) {
        chr = halftofull[chr - 32];
    }
    for (int i = 0; i < mMapBlockNum; i++) {
        if ((mpMapBlocks[i]->startCode <= chr) && (chr <= mpMapBlocks[i]->endCode)) {
            ResFONT::MAP1* map = mpMapBlocks[i];
            if (map->mappingMethod == 0) {
                ret = chr - map->startCode;
                break;
            } else if (map->mappingMethod == 2) {
                ret = *(&mpMapBlocks[i]->mLeading + ((chr - mpMapBlocks[i]->startCode)));
                break;
            } else if (map->mappingMethod == 3) {
                u16* leading_temp = &map->mLeading;
                int phi_r5 = 0;
                int phi_r6_2 = map->numEntries - 1;

                while (phi_r6_2 >= phi_r5) {
                    int temp_r7 = (phi_r6_2 + phi_r5) / 2;

                    if (chr < leading_temp[temp_r7 * 2]) {
                        phi_r6_2 = temp_r7 - 1;
                        continue;
                    }

                    if (chr > leading_temp[temp_r7 * 2]) {
                        phi_r5 = temp_r7 + 1;
                        continue;
                    }

                    ret = leading_temp[temp_r7 * 2 + 1];
                    break;
                }
            } else if (map->mappingMethod == 1) {
                u16* phi_r5_2 = NULL;
                if (map->numEntries == 1) {
                    phi_r5_2 = &map->mLeading;
                }
                ret = convertSjis(chr, phi_r5_2);
                break;
            }
            break;
        }
    }
    return ret;
}

/* 802C30E4-802C3248       .text loadImage__10JUTResFontFi11_GXTexMapID */
void JUTResFont::loadImage(int code, _GXTexMapID id) {
    int i = 0;
    for (; i < mGlyphBlockNum; i++) {
        if (mpGlyphBlocks[i]->startCode <= code && code <= mpGlyphBlocks[i]->endCode) {
            code -= mpGlyphBlocks[i]->startCode;
            break;
        }
    }

    if (i == mGlyphBlockNum)
        return;

    s32 pageNumCells = mpGlyphBlocks[i]->numRows * mpGlyphBlocks[i]->numColumns;
    s32 pageIdx = code / pageNumCells;
    s32 cellIdxInPage = code % pageNumCells;
    s32 cellCol = (cellIdxInPage % mpGlyphBlocks[i]->numRows);
    s32 cellRow = (cellIdxInPage / mpGlyphBlocks[i]->numRows);
    mWidth = cellCol * mpGlyphBlocks[i]->cellWidth;
    mHeight = cellRow * mpGlyphBlocks[i]->cellHeight;

    if (pageIdx != mTexPageIdx || i != field_0x66) {
        GXInitTexObj(&mTexObj, &mpGlyphBlocks[i]->data[pageIdx * mpGlyphBlocks[i]->textureSize],
                     mpGlyphBlocks[i]->textureWidth, mpGlyphBlocks[i]->textureHeight,
                     (GXTexFmt)mpGlyphBlocks[i]->textureFormat, GX_CLAMP, GX_CLAMP, 0);

        GXInitTexObjLOD(&mTexObj, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, 0U, 0U, GX_ANISO_1);
        mTexPageIdx = pageIdx;
        field_0x66 = i;
    }

    GXLoadTexObj(&mTexObj, id);
}

/* 802C3248-802C328C       .text convertSjis__10JUTResFontCFiPUs */
int JUTResFont::convertSjis(int inChar, u16* inLead) const {
    int hi = JSUHiByte(inChar);
    int lo = JSULoByte(inChar) - 0x40;
    if (0x40 <= lo) {
        lo--;
    }
    u16 lead = 0x31C;
    if (inLead) {
        lead = *inLead;
    }
    return lo + (hi - 0x88) * 0xBC + -0x5E + lead;
}
