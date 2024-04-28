#ifndef RES_DEMO50_H
#define RES_DEMO50_H

#include "global.h"

enum DEMO50_RES_FILE_ID {
    /* BCKS */
    DEMO50_BCK_21_SWMS_CUT10_O=0x0,
    DEMO50_BCK_21_SWMS_CUT12A_O=0x1,
    DEMO50_BCK_21_SWMS_CUT12B_O=0x2,
    DEMO50_BCK_SWGRIPMSAB=0x3,
    
    /* BTK */
    DEMO50_BTK_21_SWMS_CUT12B_O=0x4,
    DEMO50_BTK_SWMS_NO_FLASH=0x5,
    DEMO50_BTK_21_SWMS_CUT12A_O=0x6,
    
    /* BDLM */
    DEMO50_BDL_MASTERSW_LV1=0x8,
    
    /* STB */
    DEMO50_STB_SWING_SWORD=0x9,
};

enum DEMO50_RES_FILE_INDEX {
    /* BCKS */
    DEMO50_INDEX_BCK_21_SWMS_CUT10_O=0x6,
    DEMO50_INDEX_BCK_21_SWMS_CUT12A_O=0x7,
    DEMO50_INDEX_BCK_21_SWMS_CUT12B_O=0x8,
    DEMO50_INDEX_BCK_SWGRIPMSAB=0x9,
    
    /* BTK */
    DEMO50_INDEX_BTK_21_SWMS_CUT12B_O=0xC,
    DEMO50_INDEX_BTK_SWMS_NO_FLASH=0xD,
    DEMO50_INDEX_BTK_21_SWMS_CUT12A_O=0xE,
    
    /* BDLM */
    DEMO50_INDEX_BDL_MASTERSW_LV1=0x11,
    
    /* STB */
    DEMO50_INDEX_STB_SWING_SWORD=0x14,
};

#endif /* RES_DEMO50_H */
