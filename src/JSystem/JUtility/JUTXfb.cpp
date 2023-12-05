//
// Generated by dtk
// Translation Unit: JUTXfb.cpp
//

#include "JSystem/JUtility/JUTXfb.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "dolphin/gx/GX.h"

JUTXfb* JUTXfb::sManager;

/* 802C81D8-802C81EC       .text clearIndex__6JUTXfbFv */
void JUTXfb::clearIndex() {
    mDrawingXfbIndex = -1;
    mDrawnXfbIndex = -1;
    mDisplayingXfbIndex = -1;
}

/* 802C81EC-802C8224       .text common_init__6JUTXfbFi */
void JUTXfb::common_init(int bufNum) {
    mBufferNum = bufNum;
    clearIndex();
    mSDrawingFlag = 99;
}

/* 802C8224-802C82CC       .text __ct__6JUTXfbFPC16_GXRenderModeObjP7JKRHeapQ26JUTXfb10EXfbNumber */
JUTXfb::JUTXfb(const _GXRenderModeObj* pObj, JKRHeap* pHeap, JUTXfb::EXfbNumber xfbNum) {
    common_init(xfbNum);

    if (pObj) {
        initiate(pObj->fb_width, pObj->xfb_height, pHeap, xfbNum);
    } else {
#if VERSION == VERSION_JPN
        GXRenderModeObj* obj = JUTVideo::getManager()->getRenderMode();
        initiate(obj->fb_width, obj->xfb_height, pHeap, xfbNum);
#else
        u16 fb_width = JUTVideo::getManager()->getFbWidth();
        u16 efb_height = JUTVideo::getManager()->getEfbHeight();
        u16 xfb_height = JUTVideo::getManager()->getXfbHeight();
        f32 scale_factor = GXGetYScaleFactor(efb_height, xfb_height);
        u16 xfb_lines = GXGetNumXfbLines(efb_height, scale_factor);

        initiate(fb_width, xfb_lines, pHeap, xfbNum);
#endif
    }
}

/* 802C82CC-802C833C       .text __dt__6JUTXfbFv */
JUTXfb::~JUTXfb() {
    for (int i = 0; i < 3; i++) {
        delXfb(i);
    }
    sManager = NULL;
}

/* 802C833C-802C837C       .text delXfb__6JUTXfbFi */
void JUTXfb::delXfb(int xfbIdx) {
    if (mXfbAllocated[xfbIdx] && mBuffer[xfbIdx]) {
        delete mBuffer[xfbIdx];
    }
}

/* 802C837C-802C8410       .text createManager__6JUTXfbFPC16_GXRenderModeObjP7JKRHeapQ26JUTXfb10EXfbNumber */
JUTXfb* JUTXfb::createManager(const _GXRenderModeObj* pObj, JKRHeap* pHeap, JUTXfb::EXfbNumber xfbNum) {
    JUT_CONFIRM(VERSION_SELECT(198, 203, 203), sManager == 0);
    if (sManager == NULL) {
        sManager = new JUTXfb(pObj, pHeap, xfbNum);
    }
    return sManager;
}

/* 802C8410-802C8468       .text destroyManager__6JUTXfbFv */
void JUTXfb::destroyManager() {
    JUT_CONFIRM(VERSION_SELECT(339, 344, 344), sManager);
    delete sManager;
    sManager = NULL;
}

/* 802C8468-802C8544       .text initiate__6JUTXfbFUsUsP7JKRHeapQ26JUTXfb10EXfbNumber */
void JUTXfb::initiate(u16 width, u16 height, JKRHeap* pHeap, JUTXfb::EXfbNumber xfbNum) {
    if (pHeap == NULL) {
        pHeap = JKRHeap::getSystemHeap();
    }

    int size = ((u32)width + 0xf & 0xfff0) * (u32)height * 2;

    void* buf = ::operator new[](size, pHeap, 0x20);
    mBuffer[0] = buf;
    mXfbAllocated[0] = true;

    if (xfbNum >= 2) {
        buf = ::operator new[](size, pHeap, 0x20);
        mBuffer[1] = buf;
        mXfbAllocated[1] = true;
    } else {
        mBuffer[1] = NULL;
        mXfbAllocated[1] = false;
    }

    if (xfbNum >= 3) {
        buf = ::operator new[](size, pHeap, 0x20);
        mBuffer[2] = buf;
        mXfbAllocated[2] = true;
    } else {
        mBuffer[2] = NULL;
        mXfbAllocated[2] = false;
    }
}

void dummy() {
	OSReport("JX:: disp = %d\n");
	OSReport("JX:: drawing %d -> ");
	OSReport("%d\n");
}
