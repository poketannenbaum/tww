#ifndef D_A_TAMA_H
#define D_A_TAMA_H

#include "f_op/f_op_actor.h"

class daTama_c : public fopAc_ac_c {
public:
    void setDis(float) {}
    void setPartnerID(unsigned int) {}
    void setSpd(float) {}

    void createInit();
    BOOL _draw();
    BOOL _execute();
    BOOL _delete();
    s32 _create();

public:
    /* Place member variables here */
};

#endif /* D_A_TAMA_H */
