#ifndef RES_KK_H
#define RES_KK_H

#include "global.h"

enum KK_RES_FILE_ID {
    /* BCKS */
    KK_BCK_GFKDS00=0x0,
    KK_BCK_KK_FURIMUKI=0x1,
    KK_BCK_KK_FURIMUKI02=0x2,
    KK_BCK_KK_OJIGI=0x3,
    KK_BCK_KK_RUN=0x4,
    KK_BCK_KK_TALK01=0x5,
    KK_BCK_KK_TALK02=0x6,
    KK_BCK_KK_TALK03=0x7,
    KK_BCK_KK_TEBYOUSHI=0x8,
    KK_BCK_KK_WAIT01=0x9,
    KK_BCK_KK_WAIT02=0xA,
    KK_BCK_KK_WAIT03=0xB,
    KK_BCK_KK_WALK=0xC,
    
    /* BDLM */
    KK_BDL_KK=0xD,
    
    /* BMDM */
    KK_BMD_GFKDS00=0xE,
    
    /* BPK */
    KK_BPK_GFKDS00=0xF,
    
    /* BTK */
    KK_BTK_GFKDS00=0x10,
    
    /* BTP */
    KK_BTP_KK=0x11,
};

enum KK_RES_FILE_INDEX {
    /* BCKS */
    KK_INDEX_BCK_GFKDS00=0x8,
    KK_INDEX_BCK_KK_FURIMUKI=0x9,
    KK_INDEX_BCK_KK_FURIMUKI02=0xA,
    KK_INDEX_BCK_KK_OJIGI=0xB,
    KK_INDEX_BCK_KK_RUN=0xC,
    KK_INDEX_BCK_KK_TALK01=0xD,
    KK_INDEX_BCK_KK_TALK02=0xE,
    KK_INDEX_BCK_KK_TALK03=0xF,
    KK_INDEX_BCK_KK_TEBYOUSHI=0x10,
    KK_INDEX_BCK_KK_WAIT01=0x11,
    KK_INDEX_BCK_KK_WAIT02=0x12,
    KK_INDEX_BCK_KK_WAIT03=0x13,
    KK_INDEX_BCK_KK_WALK=0x14,
    
    /* BDLM */
    KK_INDEX_BDL_KK=0x17,
    
    /* BMDM */
    KK_INDEX_BMD_GFKDS00=0x1A,
    
    /* BPK */
    KK_INDEX_BPK_GFKDS00=0x1D,
    
    /* BTK */
    KK_INDEX_BTK_GFKDS00=0x20,
    
    /* BTP */
    KK_INDEX_BTP_KK=0x23,
};

#endif /* RES_KK_H */
