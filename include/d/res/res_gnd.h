#ifndef RES_GND_H
#define RES_GND_H

#include "global.h"

enum GND_RES_FILE_ID { // IDs and indexes are synced
    /* BAS */
    GND_BAS_AATTACK1=0x8,
    GND_BAS_AATTACK2=0x9,
    GND_BAS_AATTACK3=0xA,
    GND_BAS_BATTACK1=0xB,
    GND_BAS_BATTACK2=0xC,
    GND_BAS_BATTACK3_ATTACK=0xD,
    GND_BAS_BATTACK3_END=0xE,
    GND_BAS_BATTACK3_TAME=0xF,
    GND_BAS_BINTA1=0x10,
    GND_BAS_BINTA2=0x11,
    GND_BAS_BOUGYO3=0x12,
    GND_BAS_COUNTERL=0x13,
    GND_BAS_COUNTERR=0x14,
    GND_BAS_DAMAGEJ_END=0x15,
    GND_BAS_HI_JUMP_END_1=0x16,
    GND_BAS_HI_JUMP_START=0x17,
    GND_BAS_JATTACK_ATTACK=0x18,
    GND_BAS_JATTACK_END=0x19,
    GND_BAS_JATTACK_TAME=0x1A,
    GND_BAS_JUMP1=0x1B,
    GND_BAS_JUMP3=0x1C,
    GND_BAS_KERI1=0x1D,
    GND_BAS_LAST_ATTACK_ATTACK=0x1E,
    GND_BAS_NOM_ATTACK1=0x1F,
    GND_BAS_NOM_ATTACK2=0x20,
    GND_BAS_WALK=0x21,
    
    /* BCK */
    GND_BCK_AATTACK1=0x24,
    GND_BCK_AATTACK2=0x25,
    GND_BCK_AATTACK3=0x26,
    GND_BCK_BATTACK1=0x27,
    GND_BCK_BATTACK2=0x28,
    GND_BCK_BATTACK3_ATTACK=0x29,
    GND_BCK_BATTACK3_END=0x2A,
    GND_BCK_BATTACK3_TAME=0x2B,
    GND_BCK_BINTA1=0x2C,
    GND_BCK_BINTA2=0x2D,
    GND_BCK_BOUGYO1=0x2E,
    GND_BCK_BOUGYO2=0x2F,
    GND_BCK_BOUGYO3=0x30,
    GND_BCK_BOUGYO4=0x31,
    GND_BCK_BOUGYO5=0x32,
    GND_BCK_BOUGYO6=0x33,
    GND_BCK_BOUGYO7=0x34,
    GND_BCK_COMBO_GANON=0x35,
    GND_BCK_COUNTERL=0x36,
    GND_BCK_COUNTERR=0x37,
    GND_BCK_DAMAGEA=0x38,
    GND_BCK_DAMAGEA_LOOP=0x39,
    GND_BCK_DAMAGEB=0x3A,
    GND_BCK_DAMAGEB_LOOP=0x3B,
    GND_BCK_DAMAGEC=0x3C,
    GND_BCK_DAMAGEJ=0x3D,
    GND_BCK_DAMAGEJ_END=0x3E,
    GND_BCK_FURIMUKU=0x3F,
    GND_BCK_GANON=0x40,
    GND_BCK_HI_JUMP_END1=0x41,
    GND_BCK_HI_JUMP_END2=0x42,
    GND_BCK_HI_JUMP_LOOP=0x43,
    GND_BCK_HI_JUMP_START=0x44,
    GND_BCK_JATTACK_ATTACK=0x45,
    GND_BCK_JATTACK_END=0x46,
    GND_BCK_JATTACK_JUMP=0x47,
    GND_BCK_JATTACK_TAME=0x48,
    GND_BCK_JUMP=0x49,
    GND_BCK_JUMP1=0x4A,
    GND_BCK_JUMP2=0x4B,
    GND_BCK_JUMP3=0x4C,
    GND_BCK_KERI1=0x4D,
    GND_BCK_KERI2=0x4E,
    GND_BCK_KIZUKUL=0x4F,
    GND_BCK_KUZUKU=0x50,
    GND_BCK_LAST_ATTACK_ATTACK=0x51,
    GND_BCK_LAST_ATTACK_TAME=0x52,
    GND_BCK_NOM_ATTACK1=0x53,
    GND_BCK_NOM_ATTACK2=0x54,
    GND_BCK_SAMPLE=0x55,
    GND_BCK_SURETIGAI=0x56,
    GND_BCK_WAIT=0x57,
    GND_BCK_WAIT2=0x58,
    GND_BCK_WALK=0x59,
    
    /* BDLM */
    GND_BDL_GND=0x5C,
    
    /* BRK */
    GND_BRK_SAMPLE=0x5F,
    
    /* BTK */
    GND_BTK_KIZUKU_EYE=0x62,
    GND_BTK_SAMPLE=0x63,
    
    /* BTP */
    GND_BTP_SAMPLE=0x66,
};

#endif /* RES_GND_H */
