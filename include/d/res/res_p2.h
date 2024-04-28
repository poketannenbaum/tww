#ifndef RES_P2_H
#define RES_P2_H

#include "global.h"

enum P2_RES_FILE_ID { // IDs and indexes are synced
    /* BCKS */
    P2_BCK_P2_JUMP=0x7,
    P2_BCK_P2_LANDING=0x8,
    P2_BCK_P2_MTALK01=0x9,
    P2_BCK_P2_MTALK02=0xA,
    P2_BCK_P2_MWAIT01=0xB,
    P2_BCK_P2_MWAIT02=0xC,
    P2_BCK_P2_N2RUN=0xD,
    P2_BCK_P2_NBANZAI=0xE,
    P2_BCK_P2_NICOWAIT=0xF,
    P2_BCK_P2_NKYORO2=0x10,
    P2_BCK_P2_NNOD=0x11,
    P2_BCK_P2_NODOROKI=0x12,
    P2_BCK_P2_NTALK01=0x13,
    P2_BCK_P2_NTALK02=0x14,
    P2_BCK_P2_NTALK03=0x15,
    P2_BCK_P2_NTALK04=0x16,
    P2_BCK_P2_NTHINK=0x17,
    P2_BCK_P2_NWAIT02=0x18,
    P2_BCK_P2_NWAIT03=0x19,
    P2_BCK_P2_ROPESWINGF=0x1A,
    P2_BCK_P2_ROPESWINGR=0x1B,
    P2_BCK_P2_RUN=0x1C,
    P2_BCK_P2_WAIT01=0x1D,
    P2_BCK_P2_WALK01=0x1E,
    P2_BCK_P2_ZMIAGE=0x1F,
    P2_BCK_P2_ZNOZOKU=0x20,
    P2_BCK_P2_ZTALK01=0x21,
    P2_BCK_P2_ZWAIT01=0x22,
    P2_BCK_P2BOOK_WAIT02=0x23,
    
    /* BDL */
    P2_BDL_P2=0x26,
    P2_BDL_P2_DAGGERGRIP=0x27,
    P2_BDL_P2_TELESCOPE=0x28,
    P2_BDL_P2BOOK=0x29,
    P2_BDL_P2DAGGER=0x2A,
    
    /* BDLM */
    P2_BDL_P2HEAD01=0x2D,
    P2_BDL_P2HEAD02=0x2E,
    P2_BDL_P2HEAD03=0x2F,
    
    /* BMT */
    P2_BMT_P2B=0x32,
    P2_BMT_P2C=0x33,
    
    /* BTP */
    P2_BTP_P2HEAD01=0x36,
    P2_BTP_P2HEAD02=0x37,
};

#endif /* RES_P2_H */
