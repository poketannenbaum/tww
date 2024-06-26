#ifndef RES_NITEN_H
#define RES_NITEN_H

#include "global.h"

enum NITEN_RES_FILE_ID {
    /* BCKS */
    NITEN_BCK_MT_TALK01=0x3,
    NITEN_BCK_MT_TALK02=0x4,
    NITEN_BCK_MT_TALK03=0x5,
    NITEN_BCK_MT_TALK04=0x6,
    NITEN_BCK_MT_WAIT01=0x7,
    NITEN_BCK_MT_TUKURU=0x8,
    
    /* BDLM */
    NITEN_BDL_MT=0x1,
    
    /* BTP */
    NITEN_BTP_MT_MABA=0x2,
};

enum NITEN_RES_FILE_INDEX {
    /* BCKS */
    NITEN_INDEX_BCK_MT_TALK01=0x5,
    NITEN_INDEX_BCK_MT_TALK02=0x6,
    NITEN_INDEX_BCK_MT_TALK03=0x7,
    NITEN_INDEX_BCK_MT_TALK04=0x8,
    NITEN_INDEX_BCK_MT_WAIT01=0x9,
    NITEN_INDEX_BCK_MT_TUKURU=0xA,
    
    /* BDLM */
    NITEN_INDEX_BDL_MT=0xD,
    
    /* BTP */
    NITEN_INDEX_BTP_MT_MABA=0x10,
};

#endif /* RES_NITEN_H */
