#ifndef D_A_OBJ_EBOMZO_H
#define D_A_OBJ_EBOMZO_H

#include "f_op/f_op_actor.h"

namespace daObjEbomzo {
    class Act_c : public fopAc_ac_c {
    public:
        void prm_get_swSave() const {}
    
        void CreateHeap();
        void Create();
        void Mthd_Create();
        void Delete();
        void Mthd_Delete();
        void set_mtx();
        void init_mtx();
        void check();
        void demo();
        void fall();
        void Execute(float(**)[3][4]);
        void Draw();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_OBJ_EBOMZO_H */
