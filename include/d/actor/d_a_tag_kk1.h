#ifndef D_A_TAG_KK1_H
#define D_A_TAG_KK1_H

#include "f_op/f_op_actor.h"

class daTag_Kk1_c : public fopAc_ac_c {
public:
    void createInit();
    BOOL _draw();
    BOOL _execute();
    BOOL _delete();
    s32 _create();

public:
    /* Place member variables here */
};

#endif /* D_A_TAG_KK1_H */
