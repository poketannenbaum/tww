#ifndef RES_KO_H
#define RES_KO_H

#include "global.h"

enum KO_RES_FILE_ID {
    /* BCKS */
    KO_BCK_BALLOON_BANG=0x0,
    KO_BCK_BALLOON_SLEEP04=0x1,
    KO_BCK_KOHEAD01_BANG=0x2,
    KO_BCK_KOHEAD01_BUTUKARI=0x3,
    KO_BCK_KOHEAD01_OISI=0x4,
    KO_BCK_KOHEAD01_RUN01=0x5,
    KO_BCK_KOHEAD01_SLEEP03=0x6,
    KO_BCK_KOHEAD01_SLEEP04=0x7,
    KO_BCK_KOHEAD01_SUSURI=0x8,
    KO_BCK_KOHEAD01_TALK01=0x9,
    KO_BCK_KOHEAD01_WAIT01=0xA,
    KO_BCK_KOHEAD01_WALK01=0xB,
    KO_BCK_KO_BANG=0xC,
    KO_BCK_KO_BUTUKARI=0xD,
    KO_BCK_KO_OISI=0xE,
    KO_BCK_KO_RUN01=0xF,
    KO_BCK_KO_SLEEP01=0x10,
    KO_BCK_KO_SLEEP02=0x11,
    KO_BCK_KO_SLEEP03=0x12,
    KO_BCK_KO_SLEEP04=0x13,
    KO_BCK_KO_SUSURI=0x14,
    KO_BCK_KO_TALK01=0x15,
    KO_BCK_KO_WAIT01=0x16,
    KO_BCK_KO_WAIT02=0x17,
    KO_BCK_KO_WALK01=0x18,
    KO_BCK_KOHEAD02_WAIT01=0x25,
    KO_BCK_KO_OHOHO=0x26,
    
    /* BDL */
    KO_BDL_KOEDA=0x19,
    KO_BDL_KO_BALLOON=0x1A,
    
    /* BDLM */
    KO_BDL_KO=0x1B,
    KO_BDL_KOHEAD01=0x1C,
    KO_BDL_KOHEAD02=0x1D,
    
    /* BMT */
    KO_BMT_KO02=0x1E,
    
    /* BTP */
    KO_BTP_KOHEAD01=0x1F,
    KO_BTP_KOHEAD01_SLEEP=0x20,
    KO_BTP_KOHEAD01_SLEEP04=0x21,
    KO_BTP_KOHEAD01_SUSURI=0x22,
    KO_BTP_KOHEAD02=0x23,
    KO_BTP_KOHEAD02_SLEEP=0x24,
};

enum KO_RES_FILE_INDEX {
    /* BCKS */
    KO_INDEX_BCK_BALLOON_BANG=0x7,
    KO_INDEX_BCK_BALLOON_SLEEP04=0x8,
    KO_INDEX_BCK_KOHEAD01_BANG=0x9,
    KO_INDEX_BCK_KOHEAD01_BUTUKARI=0xA,
    KO_INDEX_BCK_KOHEAD01_OISI=0xB,
    KO_INDEX_BCK_KOHEAD01_RUN01=0xC,
    KO_INDEX_BCK_KOHEAD01_SLEEP03=0xD,
    KO_INDEX_BCK_KOHEAD01_SLEEP04=0xE,
    KO_INDEX_BCK_KOHEAD01_SUSURI=0xF,
    KO_INDEX_BCK_KOHEAD01_TALK01=0x10,
    KO_INDEX_BCK_KOHEAD01_WAIT01=0x11,
    KO_INDEX_BCK_KOHEAD01_WALK01=0x12,
    KO_INDEX_BCK_KO_BANG=0x13,
    KO_INDEX_BCK_KO_BUTUKARI=0x14,
    KO_INDEX_BCK_KO_OISI=0x15,
    KO_INDEX_BCK_KO_RUN01=0x16,
    KO_INDEX_BCK_KO_SLEEP01=0x17,
    KO_INDEX_BCK_KO_SLEEP02=0x18,
    KO_INDEX_BCK_KO_SLEEP03=0x19,
    KO_INDEX_BCK_KO_SLEEP04=0x1A,
    KO_INDEX_BCK_KO_SUSURI=0x1B,
    KO_INDEX_BCK_KO_TALK01=0x1C,
    KO_INDEX_BCK_KO_WAIT01=0x1D,
    KO_INDEX_BCK_KO_WAIT02=0x1E,
    KO_INDEX_BCK_KO_WALK01=0x1F,
    KO_INDEX_BCK_KOHEAD02_WAIT01=0x20,
    KO_INDEX_BCK_KO_OHOHO=0x21,
    
    /* BDL */
    KO_INDEX_BDL_KOEDA=0x24,
    KO_INDEX_BDL_KO_BALLOON=0x25,
    
    /* BDLM */
    KO_INDEX_BDL_KO=0x28,
    KO_INDEX_BDL_KOHEAD01=0x29,
    KO_INDEX_BDL_KOHEAD02=0x2A,
    
    /* BMT */
    KO_INDEX_BMT_KO02=0x2D,
    
    /* BTP */
    KO_INDEX_BTP_KOHEAD01=0x30,
    KO_INDEX_BTP_KOHEAD01_SLEEP=0x31,
    KO_INDEX_BTP_KOHEAD01_SLEEP04=0x32,
    KO_INDEX_BTP_KOHEAD01_SUSURI=0x33,
    KO_INDEX_BTP_KOHEAD02=0x34,
    KO_INDEX_BTP_KOHEAD02_SLEEP=0x35,
};

#endif /* RES_KO_H */
