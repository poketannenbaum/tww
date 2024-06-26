//
// Generated by dtk
// Translation Unit: d_a_sail.cpp
//

#include "d/actor/d_a_sail.h"
#include "d/res/res_kaizokusen.h"
#include "d/res/res_cloth.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_obj_pirateship.h"
#include "f_op/f_op_actor_mng.h"
#include "m_Do/m_Do_mtx.h"
#include "SSystem/SComponent/c_lib.h"

static u8 dummy_bss[0x4C];

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};
static u8 dummy3[4] = {0x02, 0x00, 0x02, 0x01};
static f64 dummy4[2] = {3.0, 0.5};

static daObjPirateship::Act_c* l_p_ship;
static daSail_HIO_c l_HIO;

Vec l_pos[] = {
    {-840.0f, 0.0f, 0.0f},
    {-560.0f, 0.0f, 0.0f},
    {-280.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.0f},
    {280.0f, 0.0f, 0.0f},
    {560.0f, 0.0f, 0.0f},
    {840.0f, 0.0f, 0.0f},
    {-840.0f, -100.0f, 0.0f},
    {-560.0f, -100.0f, 0.0f},
    {-280.0f, -100.0f, 0.0f},
    {0.0f, -100.0f, 0.0f},
    {280.0f, -100.0f, 0.0f},
    {560.0f, -100.0f, 0.0f},
    {840.0f, -100.0f, 0.0f},
    {-840.0f, -200.0f, 0.0f},
    {-560.0f, -200.0f, 0.0f},
    {-280.0f, -200.0f, 0.0f},
    {0.0f, -200.0f, 0.0f},
    {280.0f, -200.0f, 0.0f},
    {560.0f, -200.0f, 0.0f},
    {840.0f, -200.0f, 0.0f},
    {-840.0f, -300.0f, 0.0f},
    {-560.0f, -300.0f, 0.0f},
    {-280.0f, -300.0f, 0.0f},
    {0.0f, -300.0f, 0.0f},
    {280.0f, -300.0f, 0.0f},
    {560.0f, -300.0f, 0.0f},
    {840.0f, -300.0f, 0.0f},
    {-840.0f, -400.0f, 0.0f},
    {-560.0f, -400.0f, 0.0f},
    {-280.0f, -400.0f, 0.0f},
    {0.0f, -400.0f, 0.0f},
    {280.0f, -400.0f, 0.0f},
    {560.0f, -400.0f, 0.0f},
    {840.0f, -400.0f, 0.0f},
    {-840.0f, -500.0f, 0.0f},
    {-560.0f, -500.0f, 0.0f},
    {-280.0f, -500.0f, 0.0f},
    {0.0f, -500.0f, 0.0f},
    {280.0f, -500.0f, 0.0f},
    {560.0f, -500.0f, 0.0f},
    {840.0f, -500.0f, 0.0f},
    {-840.0f, -600.0f, 0.0f},
    {-560.0f, -600.0f, 0.0f},
    {-280.0f, -600.0f, 0.0f},
    {0.0f, -600.0f, 0.0f},
    {280.0f, -600.0f, 0.0f},
    {560.0f, -600.0f, 0.0f},
    {840.0f, -600.0f, 0.0f},
    {-840.0f, -700.0f, 0.0f},
    {-560.0f, -700.0f, 0.0f},
    {-280.0f, -700.0f, 0.0f},
    {0.0f, -700.0f, 0.0f},
    {280.0f, -700.0f, 0.0f},
    {560.0f, -700.0f, 0.0f},
    {840.0f, -700.0f, 0.0f},
    {-840.0f, -800.0f, 0.0f},
    {-560.0f, -800.0f, 0.0f},
    {-280.0f, -800.0f, 0.0f},
    {0.0f, -800.0f, 0.0f},
    {280.0f, -800.0f, 0.0f},
    {560.0f, -800.0f, 0.0f},
    {840.0f, -800.0f, 0.0f},
    {-840.0f, -900.0f, 0.0f},
    {-560.0f, -900.0f, 0.0f},
    {-280.0f, -900.0f, 0.0f},
    {0.0f, -900.0f, 0.0f},
    {280.0f, -900.0f, 0.0f},
    {560.0f, -900.0f, 0.0f},
    {840.0f, -900.0f, 0.0f},
    {-840.0f, -1000.0f, 0.0f},
    {-560.0f, -1000.0f, 0.0f},
    {-280.0f, -1000.0f, 0.0f},
    {0.0f, -1000.0f, 0.0f},
    {280.0f, -1000.0f, 0.0f},
    {560.0f, -1000.0f, 0.0f},
    {840.0f, -1000.0f, 0.0f},
    {-840.0f, -1100.0f, 0.0f},
    {-560.0f, -1100.0f, 0.0f},
    {-280.0f, -1100.0f, 0.0f},
    {0.0f, -1100.0f, 0.0f},
    {280.0f, -1100.0f, 0.0f},
    {560.0f, -1100.0f, 0.0f},
    {840.0f, -1100.0f, 0.0f},
};

f32 l_texCoord[][2] = {
    {0.0f, 0.0f},
    {0.165f, 0.0f},
    {0.33f, 0.0f},
    {0.495f, 0.0f},
    {0.66f, 0.0f},
    {0.825f, 0.0f},
    {1.0f, 0.0f},
    {0.0f, 0.09f},
    {0.165f, 0.09f},
    {0.33f, 0.09f},
    {0.495f, 0.09f},
    {0.66f, 0.09f},
    {0.825f, 0.09f},
    {1.0f, 0.09f},
    {0.0f, 0.18f},
    {0.165f, 0.18f},
    {0.33f, 0.18f},
    {0.495f, 0.18f},
    {0.66f, 0.18f},
    {0.825f, 0.18f},
    {1.0f, 0.18f},
    {0.0f, 0.27f},
    {0.165f, 0.27f},
    {0.33f, 0.27f},
    {0.495f, 0.27f},
    {0.66f, 0.27f},
    {0.825f, 0.27f},
    {1.0f, 0.27f},
    {0.0f, 0.36f},
    {0.165f, 0.36f},
    {0.33f, 0.36f},
    {0.495f, 0.36f},
    {0.66f, 0.36f},
    {0.825f, 0.36f},
    {1.0f, 0.36f},
    {0.0f, 0.45f},
    {0.165f, 0.45f},
    {0.33f, 0.45f},
    {0.495f, 0.45f},
    {0.66f, 0.45f},
    {0.825f, 0.45f},
    {1.0f, 0.45f},
    {0.0f, 0.54f},
    {0.165f, 0.54f},
    {0.33f, 0.54f},
    {0.495f, 0.54f},
    {0.66f, 0.54f},
    {0.825f, 0.54f},
    {1.0f, 0.54f},
    {0.0f, 0.63f},
    {0.165f, 0.63f},
    {0.33f, 0.63f},
    {0.495f, 0.63f},
    {0.66f, 0.63f},
    {0.825f, 0.63f},
    {1.0f, 0.63f},
    {0.0f, 0.72f},
    {0.165f, 0.72f},
    {0.33f, 0.72f},
    {0.495f, 0.72f},
    {0.66f, 0.72f},
    {0.825f, 0.72f},
    {1.0f, 0.72f},
    {0.0f, 0.81f},
    {0.165f, 0.81f},
    {0.33f, 0.81f},
    {0.495f, 0.81f},
    {0.66f, 0.81f},
    {0.825f, 0.81f},
    {1.0f, 0.81f},
    {0.0f, 0.9f},
    {0.165f, 0.9f},
    {0.33f, 0.9f},
    {0.495f, 0.9f},
    {0.66f, 0.9f},
    {0.825f, 0.9f},
    {1.0f, 0.9f},
    {0.0f, 1.0f},
    {0.165f, 1.0f},
    {0.33f, 1.0f},
    {0.495f, 1.0f},
    {0.66f, 1.0f},
    {0.825f, 1.0f},
    {1.0f, 1.0f},
};

u8 l_sail_DL[] ALIGN_DECL(32) = {
    0x98, 0x00, 0x0E, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x01, 0x01, 0x01, 0x09,
    0x09, 0x09, 0x02, 0x02, 0x02, 0x0A, 0x0A, 0x0A, 0x03, 0x03, 0x03, 0x0B, 0x0B, 0x0B, 0x04, 0x04,
    0x04, 0x0C, 0x0C, 0x0C, 0x05, 0x05, 0x05, 0x0D, 0x0D, 0x0D, 0x06, 0x06, 0x06, 0x98, 0x00, 0x0E,
    0x0E, 0x0E, 0x0E, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x09,
    0x09, 0x09, 0x11, 0x11, 0x11, 0x0A, 0x0A, 0x0A, 0x12, 0x12, 0x12, 0x0B, 0x0B, 0x0B, 0x13, 0x13,
    0x13, 0x0C, 0x0C, 0x0C, 0x14, 0x14, 0x14, 0x0D, 0x0D, 0x0D, 0x98, 0x00, 0x0E, 0x15, 0x15, 0x15,
    0x0E, 0x0E, 0x0E, 0x16, 0x16, 0x16, 0x0F, 0x0F, 0x0F, 0x17, 0x17, 0x17, 0x10, 0x10, 0x10, 0x18,
    0x18, 0x18, 0x11, 0x11, 0x11, 0x19, 0x19, 0x19, 0x12, 0x12, 0x12, 0x1A, 0x1A, 0x1A, 0x13, 0x13,
    0x13, 0x1B, 0x1B, 0x1B, 0x14, 0x14, 0x14, 0x98, 0x00, 0x0E, 0x1C, 0x1C, 0x1C, 0x15, 0x15, 0x15,
    0x1D, 0x1D, 0x1D, 0x16, 0x16, 0x16, 0x1E, 0x1E, 0x1E, 0x17, 0x17, 0x17, 0x1F, 0x1F, 0x1F, 0x18,
    0x18, 0x18, 0x20, 0x20, 0x20, 0x19, 0x19, 0x19, 0x21, 0x21, 0x21, 0x1A, 0x1A, 0x1A, 0x22, 0x22,
    0x22, 0x1B, 0x1B, 0x1B, 0x98, 0x00, 0x0E, 0x23, 0x23, 0x23, 0x1C, 0x1C, 0x1C, 0x24, 0x24, 0x24,
    0x1D, 0x1D, 0x1D, 0x25, 0x25, 0x25, 0x1E, 0x1E, 0x1E, 0x26, 0x26, 0x26, 0x1F, 0x1F, 0x1F, 0x27,
    0x27, 0x27, 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x21, 0x21, 0x21, 0x29, 0x29, 0x29, 0x22, 0x22,
    0x22, 0x98, 0x00, 0x0E, 0x2A, 0x2A, 0x2A, 0x23, 0x23, 0x23, 0x2B, 0x2B, 0x2B, 0x24, 0x24, 0x24,
    0x2C, 0x2C, 0x2C, 0x25, 0x25, 0x25, 0x2D, 0x2D, 0x2D, 0x26, 0x26, 0x26, 0x2E, 0x2E, 0x2E, 0x27,
    0x27, 0x27, 0x2F, 0x2F, 0x2F, 0x28, 0x28, 0x28, 0x30, 0x30, 0x30, 0x29, 0x29, 0x29, 0x98, 0x00,
    0x0E, 0x31, 0x31, 0x31, 0x2A, 0x2A, 0x2A, 0x32, 0x32, 0x32, 0x2B, 0x2B, 0x2B, 0x33, 0x33, 0x33,
    0x2C, 0x2C, 0x2C, 0x34, 0x34, 0x34, 0x2D, 0x2D, 0x2D, 0x35, 0x35, 0x35, 0x2E, 0x2E, 0x2E, 0x36,
    0x36, 0x36, 0x2F, 0x2F, 0x2F, 0x37, 0x37, 0x37, 0x30, 0x30, 0x30, 0x98, 0x00, 0x0E, 0x38, 0x38,
    0x38, 0x31, 0x31, 0x31, 0x39, 0x39, 0x39, 0x32, 0x32, 0x32, 0x3A, 0x3A, 0x3A, 0x33, 0x33, 0x33,
    0x3B, 0x3B, 0x3B, 0x34, 0x34, 0x34, 0x3C, 0x3C, 0x3C, 0x35, 0x35, 0x35, 0x3D, 0x3D, 0x3D, 0x36,
    0x36, 0x36, 0x3E, 0x3E, 0x3E, 0x37, 0x37, 0x37, 0x98, 0x00, 0x0E, 0x3F, 0x3F, 0x3F, 0x38, 0x38,
    0x38, 0x40, 0x40, 0x40, 0x39, 0x39, 0x39, 0x41, 0x41, 0x41, 0x3A, 0x3A, 0x3A, 0x42, 0x42, 0x42,
    0x3B, 0x3B, 0x3B, 0x43, 0x43, 0x43, 0x3C, 0x3C, 0x3C, 0x44, 0x44, 0x44, 0x3D, 0x3D, 0x3D, 0x45,
    0x45, 0x45, 0x3E, 0x3E, 0x3E, 0x98, 0x00, 0x0E, 0x46, 0x46, 0x46, 0x3F, 0x3F, 0x3F, 0x47, 0x47,
    0x47, 0x40, 0x40, 0x40, 0x48, 0x48, 0x48, 0x41, 0x41, 0x41, 0x49, 0x49, 0x49, 0x42, 0x42, 0x42,
    0x4A, 0x4A, 0x4A, 0x43, 0x43, 0x43, 0x4B, 0x4B, 0x4B, 0x44, 0x44, 0x44, 0x4C, 0x4C, 0x4C, 0x45,
    0x45, 0x45, 0x98, 0x00, 0x0E, 0x4D, 0x4D, 0x4D, 0x46, 0x46, 0x46, 0x4E, 0x4E, 0x4E, 0x47, 0x47,
    0x47, 0x4F, 0x4F, 0x4F, 0x48, 0x48, 0x48, 0x50, 0x50, 0x50, 0x49, 0x49, 0x49, 0x51, 0x51, 0x51,
    0x4A, 0x4A, 0x4A, 0x52, 0x52, 0x52, 0x4B, 0x4B, 0x4B, 0x53, 0x53, 0x53, 0x4C, 0x4C, 0x4C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 l_sail_matDL[] ALIGN_DECL(32) = {
    0x61, 0x43, 0x00, 0x00, 0x01, 0x61, 0x40, 0x00, 0x00, 0x17, 0x61, 0x41, 0x00, 0x04, 0xAD, 0x61,
    0xF3, 0x64, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

u8 l_Txa_kizoku_mastTEX[] ALIGN_DECL(32) = {
    0x4A, 0x69, 0x18, 0xE3, 0x15, 0x15, 0x15, 0x35, 0x42, 0x08, 0x18, 0xE3, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x8A, 0x18, 0xE3, 0x35, 0x35, 0x35, 0x35, 0x42, 0x28, 0x21, 0x04, 0x52, 0x52, 0x52, 0x52,
    0xC5, 0x51, 0x9C, 0x4E, 0xC0, 0xC0, 0xC0, 0x7A, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0xBF, 0x55,
    0xB4, 0xEF, 0x9C, 0x2E, 0x60, 0x60, 0x60, 0x60, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0x55, 0x55,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBD, 0x31, 0xB4, 0xEF, 0xFF, 0xF0, 0xFF, 0xFF,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x02, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x80, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0xFF, 0x00, 0xF8, 0x55, 0xC5, 0x51, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0xFE,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xA0, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0xFF, 0x55,
    0xC5, 0x51, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0x80, 0xC5, 0x51, 0xB4, 0xEF, 0xD5, 0x0A, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xFF, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xFE, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xBD, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xB5, 0x0D,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xAA, 0x55, 0xC5, 0x51, 0xB4, 0xF0, 0x00, 0x00, 0x00, 0xFE,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xBD, 0x31, 0x00, 0x02, 0x00, 0xE0, 0xC5, 0x72, 0xBD, 0x10, 0x00, 0xAD, 0x00, 0x00,
    0xBD, 0x10, 0xB4, 0xEF, 0xE0, 0xFF, 0xFF, 0xFF, 0xC5, 0x51, 0xB4, 0xEF, 0xE0, 0x57, 0x55, 0x55,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xD5, 0x2B, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x57, 0x55, 0x2B,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0xE8, 0x57, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xFA, 0x55,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0xD5, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x55,
    0xC5, 0x51, 0xBD, 0x10, 0x0B, 0x00, 0x00, 0x5A, 0xC5, 0x51, 0xB4, 0xEF, 0xD5, 0x02, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xBD, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0xAA, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFE, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xAB, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xFF, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xA0, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xF0, 0x00, 0x08, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xFF, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0xFE, 0x00,
    0xC5, 0x72, 0xB4, 0xF0, 0x00, 0x00, 0x7F, 0x55, 0xC5, 0x51, 0x9C, 0x2E, 0x03, 0x03, 0x8B, 0xA9,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0xAA, 0x00, 0xC5, 0x51, 0x9C, 0x2E, 0xA9, 0xA9, 0x03, 0x03,
    0x4A, 0x69, 0x18, 0xE3, 0xC9, 0xC9, 0xCD, 0xCD, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4A, 0x69, 0x18, 0xE3, 0xCD, 0xC9, 0xC9, 0xC1, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x52, 0x8A, 0x18, 0xE3, 0x35, 0x35, 0x35, 0x35, 0x4A, 0x69, 0x18, 0xE3, 0x72, 0x72, 0x72, 0x72,
    0x52, 0x8A, 0x18, 0xE3, 0x35, 0x35, 0x35, 0x35, 0x42, 0x28, 0x21, 0x04, 0x52, 0x52, 0x52, 0x52,
    0xC5, 0x51, 0x9C, 0x4F, 0x7A, 0x6A, 0xC0, 0x60, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0x2A, 0x00,
    0xB4, 0xF0, 0x9C, 0x2E, 0x60, 0x60, 0x60, 0x60, 0xBD, 0x31, 0xB4, 0xEF, 0x80, 0x55, 0xFF, 0xFF,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0xAA, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x55, 0xAA, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x7E, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xFA, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xF8, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xAF, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x5F,
    0xC5, 0x51, 0xB4, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0xC5, 0x51, 0xBD, 0x10, 0x00, 0x00, 0x00, 0x09,
    0xC5, 0x51, 0xB4, 0xEF, 0x0A, 0x55, 0x57, 0x80, 0xC5, 0x51, 0xB4, 0xEF, 0xF5, 0x57, 0xA0, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x0B, 0x35, 0x55, 0xC5, 0x71, 0xB4, 0xEF, 0x25, 0xD5, 0x55, 0x55,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xEA, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xF0, 0xFE, 0x00, 0x00, 0x00,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xBD, 0x10, 0x7F, 0x00, 0x00, 0xAB, 0xC5, 0x72, 0xBD, 0x31, 0xFD, 0x00, 0x00, 0xD7,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xBD, 0x10, 0xF5, 0x00, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xF0, 0xFD, 0x00, 0x00, 0x00,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAF, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xD5, 0x0A, 0x00,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBD, 0x30, 0xB4, 0xEF, 0xF8, 0xF5, 0xFF, 0xFF,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xF5, 0x02, 0xBD, 0x10, 0xB4, 0xEF, 0xFF, 0xFF, 0xFF, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x80, 0x5F, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0xFF, 0x55, 0x55,
    0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x02, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0xFA, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xAF, 0x55, 0x55,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0xA8, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0xFE, 0x55,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xF0, 0x00, 0x00, 0x00, 0xE8, 0xC5, 0x51, 0xA4, 0x90, 0x09, 0x09, 0x09, 0x09,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xF0, 0x9C, 0x2E, 0x03, 0x09, 0x09, 0x01,
    0x4A, 0x69, 0x29, 0x45, 0x41, 0x41, 0x41, 0x43, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x52, 0xAA, 0x29, 0x45, 0x63, 0x62, 0x62, 0x62, 0x21, 0x04, 0x18, 0xE3, 0xC0, 0x00, 0x20, 0x20,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x52, 0x8A, 0x18, 0xE3, 0x35, 0x35, 0x35, 0x35, 0x42, 0x29, 0x21, 0x04, 0x52, 0x52, 0x52, 0x52,
    0x52, 0x8A, 0x18, 0xE3, 0x35, 0x35, 0x35, 0x35, 0x4A, 0x8A, 0x18, 0xE3, 0x72, 0x72, 0x62, 0x62,
    0xC5, 0x51, 0x9C, 0x2E, 0x7A, 0xEA, 0xC0, 0xC0, 0xC5, 0x51, 0xB4, 0xF0, 0x55, 0xFF, 0x00, 0x00,
    0xC5, 0x51, 0x9C, 0x4E, 0xC0, 0xC0, 0xE0, 0x7A, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xAB, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xFA, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xEA, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0xBF, 0x55, 0xC5, 0x71, 0xB4, 0xEF, 0x00, 0xAD, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xF0, 0xFE, 0x00, 0x00, 0x02, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0xB5,
    0xBD, 0x31, 0xB4, 0xEF, 0x2D, 0xDF, 0xFD, 0x7E, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0x5F, 0x80,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x00, 0xBD, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x2F, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x57, 0x80, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xFA, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x0A, 0x55, 0x55, 0x55, 0xBD, 0x10, 0xB4, 0xEF, 0x0B, 0xFF, 0xFF, 0xFF,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAA, 0x00, 0x00, 0xC5, 0x51, 0xBD, 0x10, 0x55, 0x00, 0x00, 0x2B,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xF0, 0xFA, 0x00, 0x00, 0xFF, 0xC5, 0x72, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0x55,
    0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0xA0, 0xBD, 0x10, 0xB4, 0xEF, 0x80, 0xFF, 0xFF, 0xFF,
    0xC5, 0x51, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0xFE, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0x2A, 0x00, 0xEA,
    0xC5, 0x51, 0xB4, 0xEF, 0xA0, 0x57, 0x55, 0x55, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0xFA, 0x55, 0x55,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xAB, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xD5, 0x0A, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x80, 0x7E, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x00, 0xA8, 0x57,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xAF, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0x55, 0x2A,
    0xC5, 0x72, 0xBD, 0x10, 0xAA, 0x00, 0x00, 0x57, 0xC5, 0x72, 0xBD, 0x10, 0xF5, 0x00, 0x00, 0xEA,
    0xBD, 0x10, 0xB4, 0xEF, 0xFF, 0xFF, 0xFF, 0x02, 0xB4, 0xF0, 0xB4, 0xEF, 0xA0, 0x00, 0x00, 0x0A,
    0xC5, 0x51, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xF0, 0xFF, 0x00, 0x00, 0x00,
    0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAA, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAA, 0x00, 0x00,
    0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xF0, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x00, 0x00, 0x00, 0xC5, 0x51, 0x9C, 0x2E, 0xA9, 0x03, 0x03, 0x03,
    0xBD, 0x10, 0xB4, 0xEF, 0x00, 0xFF, 0xFF, 0xFF, 0xB4, 0xEF, 0x9C, 0x2E, 0x03, 0x01, 0x01, 0x01,
    0x52, 0x8A, 0x29, 0x45, 0x42, 0x42, 0x42, 0x42, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x52, 0xAA, 0x29, 0x45, 0x62, 0x63, 0x63, 0x63, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x52, 0x8A, 0x18, 0xE3, 0x25, 0x25, 0x35, 0x35, 0x4A, 0x69, 0x18, 0xE3, 0x62, 0x72, 0x72, 0x72,
    0x4A, 0x69, 0x18, 0xE3, 0x35, 0x35, 0x15, 0x15, 0x42, 0x28, 0x18, 0xE3, 0x72, 0x72, 0x52, 0x52,
    0xC5, 0x51, 0x9C, 0x4E, 0x7A, 0x7A, 0xE0, 0xC0, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x5F, 0x00, 0x00,
    0xC5, 0x51, 0xAC, 0xB0, 0x60, 0x60, 0x60, 0x60, 0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xFA, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x5E, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xBD, 0x31, 0xC0, 0x00, 0x00, 0x00, 0xC5, 0x72, 0xC5, 0x51, 0x0A, 0xAA, 0xAA, 0xAA,
    0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xF0, 0x00, 0x00, 0x02, 0x0D, 0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x2B, 0xD5, 0x55,
    0xC5, 0x51, 0xBD, 0x31, 0x02, 0x00, 0x00, 0x00, 0xC5, 0x51, 0xBD, 0x30, 0x2F, 0x00, 0x00, 0x00,
    0xBD, 0x31, 0xB4, 0xEF, 0x03, 0xD7, 0xFF, 0x5F, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xF0, 0xAD, 0x00, 0x00, 0x00, 0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAA, 0x00, 0x00,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x72, 0xB4, 0xEF, 0x55, 0xAB, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xA8, 0x00, 0x00,
    0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB4, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xAB, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xFF, 0x00, 0x00,
    0xBD, 0x10, 0xB4, 0xEF, 0xE0, 0xFF, 0xFF, 0xFF, 0xBD, 0x31, 0xB4, 0xEF, 0x00, 0x57, 0xFF, 0xFF,
    0xC5, 0x51, 0xB4, 0xF0, 0x55, 0xFF, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xFF, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x00, 0x7E, 0x55, 0x55, 0xC5, 0x72, 0xB4, 0xEF, 0x00, 0x80, 0x7E, 0x55,
    0xC5, 0x51, 0xB4, 0xF0, 0x55, 0xFF, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xF5, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xF0, 0x00, 0x00, 0x00, 0xF8, 0xC5, 0x51, 0xBD, 0x10, 0x29, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x5F, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xF0, 0xE0, 0xF0, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0xD5, 0x0B, 0x00, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0xD5, 0x02, 0x00,
    0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0xBF, 0x00, 0xC5, 0x51, 0xB4, 0xEF, 0x55, 0x55, 0x55, 0x02,
    0xC5, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC5, 0x72, 0xC5, 0x51, 0x80, 0xAA, 0xAA, 0xAA,
    0xBD, 0x31, 0xB4, 0xEF, 0xFF, 0xFF, 0xD7, 0x00, 0xBD, 0x31, 0x9C, 0x2E, 0x89, 0x09, 0xA9, 0x03,
    0xC5, 0x72, 0xC5, 0x51, 0x00, 0xAA, 0xAA, 0xAA, 0xC5, 0x51, 0xA4, 0x90, 0x01, 0x01, 0x01, 0x01,
    0x4A, 0x69, 0x29, 0x45, 0x43, 0x43, 0x41, 0x41, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4A, 0x69, 0x18, 0xE3, 0xC1, 0xC1, 0xC9, 0xC9, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xE3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

Vec l_mast_pos[] = {
    {900.0f, 9.676933f, -16.760941f},
    {900.0f, -9.676933f, -16.760941f},
    {900.0f, -19.353867f, -0.000004f},
    {900.0f, -9.676933f, 16.760941f},
    {900.0f, 9.676933f, 16.760941f},
    {900.0f, 19.353867f, -0.000001f},
    {-900.0f, 9.676933f, -16.760941f},
    {-900.0f, -9.676933f, -16.760941f},
    {-900.0f, -19.353867f, -0.000004f},
    {-900.0f, -9.676933f, 16.760941f},
    {-900.0f, 9.676933f, 16.760941f},
    {-900.0f, 19.353867f, -0.000001f},
    {900.0f, -0.000001f, -0.000001f},
    {-900.0f, -0.000001f, -0.000001f},
    {0.0f, 6.105309f, 28.277588f},
    {0.0f, -26.54686f, 28.277588f},
    {0.0f, -42.875366f, -0.000005f},
    {0.0f, -26.546822f, -28.277588f},
    {0.0f, 6.105347f, -28.277588f},
    {0.0f, 22.42897f, 0.0f},
};

u8 l_mast_color[] = {
    0xA8, 0xA8, 0xA8, 0xFF, 0x5D, 0x5D, 0x5D, 0xFF, 0xF3, 0xF3, 0xF3, 0xFF, 0xC6, 0xC6, 0xC6, 0xFF,
    0x38, 0x38, 0x38, 0xFF, 0x56, 0x56, 0x56, 0xFF, 0x0B, 0x0B, 0x0B, 0xFF, 0xA1, 0xA1, 0xA1, 0xFF,
};

f32 l_mast_texCoord[][2] = {
    {1.0f, 0.0f},
    {1.0f, 1.0f},
    {0.0f, 1.0f},
    {0.0f, 0.0f},
    {0.881686f, 1.0f},
    {0.89115f, 0.0f},
    {0.888606f, 1.0f},
    {0.888606f, 0.0f},
};

u8 l_AmastDL[] ALIGN_DECL(32) = {
    0x98, 0x00, 0x04, 0x00, 0x02, 0x02, 0x05, 0x02, 0x03, 0x12, 0x02, 0x01, 0x13, 0x02, 0x00, 0x98,
    0x00, 0x04, 0x05, 0x02, 0x02, 0x04, 0x02, 0x03, 0x13, 0x02, 0x01, 0x0E, 0x02, 0x00, 0x98, 0x00,
    0x04, 0x04, 0x00, 0x02, 0x03, 0x00, 0x03, 0x0E, 0x00, 0x01, 0x0F, 0x00, 0x00, 0x98, 0x00, 0x04,
    0x03, 0x01, 0x02, 0x02, 0x01, 0x03, 0x0F, 0x01, 0x01, 0x10, 0x01, 0x00, 0x98, 0x00, 0x04, 0x02,
    0x01, 0x02, 0x01, 0x01, 0x03, 0x10, 0x01, 0x01, 0x11, 0x01, 0x00, 0x98, 0x00, 0x04, 0x01, 0x00,
    0x02, 0x00, 0x00, 0x03, 0x11, 0x00, 0x01, 0x12, 0x00, 0x00, 0x98, 0x00, 0x04, 0x0E, 0x05, 0x00,
    0x0F, 0x05, 0x01, 0x0A, 0x05, 0x03, 0x09, 0x05, 0x02, 0x98, 0x00, 0x04, 0x0F, 0x06, 0x00, 0x10,
    0x06, 0x01, 0x09, 0x06, 0x03, 0x08, 0x06, 0x02, 0x98, 0x00, 0x04, 0x10, 0x06, 0x00, 0x11, 0x06,
    0x01, 0x08, 0x06, 0x03, 0x07, 0x06, 0x02, 0x98, 0x00, 0x04, 0x11, 0x05, 0x00, 0x12, 0x05, 0x01,
    0x07, 0x05, 0x03, 0x06, 0x05, 0x02, 0x98, 0x00, 0x04, 0x12, 0x07, 0x00, 0x13, 0x07, 0x01, 0x06,
    0x07, 0x03, 0x0B, 0x07, 0x02, 0x98, 0x00, 0x04, 0x13, 0x07, 0x00, 0x0E, 0x07, 0x01, 0x0B, 0x07,
    0x03, 0x0A, 0x07, 0x02, 0x98, 0x00, 0x03, 0x0C, 0x03, 0x01, 0x00, 0x03, 0x04, 0x01, 0x03, 0x05,
    0x98, 0x00, 0x03, 0x0C, 0x03, 0x01, 0x01, 0x03, 0x04, 0x02, 0x03, 0x05, 0x98, 0x00, 0x03, 0x0C,
    0x03, 0x01, 0x02, 0x03, 0x04, 0x03, 0x03, 0x05, 0x98, 0x00, 0x03, 0x0C, 0x03, 0x01, 0x03, 0x03,
    0x04, 0x04, 0x03, 0x05, 0x98, 0x00, 0x03, 0x0C, 0x03, 0x01, 0x04, 0x03, 0x04, 0x05, 0x03, 0x05,
    0x98, 0x00, 0x03, 0x0C, 0x03, 0x01, 0x05, 0x03, 0x04, 0x00, 0x03, 0x05, 0x98, 0x00, 0x03, 0x0D,
    0x04, 0x01, 0x07, 0x04, 0x06, 0x06, 0x04, 0x07, 0x98, 0x00, 0x03, 0x0D, 0x04, 0x01, 0x08, 0x04,
    0x06, 0x07, 0x04, 0x07, 0x98, 0x00, 0x03, 0x0D, 0x04, 0x01, 0x09, 0x04, 0x06, 0x08, 0x04, 0x07,
    0x98, 0x00, 0x03, 0x0D, 0x04, 0x01, 0x0A, 0x04, 0x06, 0x09, 0x04, 0x07, 0x98, 0x00, 0x03, 0x0D,
    0x04, 0x01, 0x0B, 0x04, 0x06, 0x0A, 0x04, 0x07, 0x98, 0x00, 0x03, 0x0D, 0x04, 0x01, 0x06, 0x04,
    0x06, 0x0B, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

/* 000000EC-00000364       .text setCorrectNrmAngle__15daSail_packet_cFsf */
void daSail_packet_c::setCorrectNrmAngle(short, float) {
    /* Nonmatching */
}

/* 00000364-00000398       .text setNrmMtx__15daSail_packet_cFv */
void daSail_packet_c::setNrmMtx() {
    mDoMtx_YrotS(*calc_mtx, m1C34);
}

/* 00000398-00000424       .text setBackNrm__15daSail_packet_cFv */
void daSail_packet_c::setBackNrm() {
    /* Nonmatching */
}

/* 00000424-00000834       .text setNrmVtx__15daSail_packet_cFP4cXyzii */
void daSail_packet_c::setNrmVtx(cXyz*, int, int) {
    /* Nonmatching */
}

/* 00000870-000010D8       .text draw__15daSail_packet_cFv */
void daSail_packet_c::draw() {
    /* Nonmatching */
    dComIfG_getObjectRes("Kaizokusen", KAIZOKUSEN_INDEX_BTI_TXA_KAIZOKU_HO);
    dComIfG_getObjectRes("Cloth", CLOTH_BTI_CLOTHTOON);
}

/* 000010D8-000013CC       .text daSail_Draw__FP10sail_class */
static BOOL daSail_Draw(sail_class* i_this) {
    /* Nonmatching */
}

/* 000013CC-00001CEC       .text sail_pos_move__FP10sail_class */
static void sail_pos_move(sail_class* i_this) {
    /* Nonmatching */
}

/* 00001CEC-00001DB0       .text demo_move__FP10sail_class */
static void demo_move(sail_class* i_this) {
    /* Nonmatching */
}

/* 00001DB0-00002094       .text sail_move__FP10sail_class */
static void sail_move(sail_class* i_this) {
    /* Nonmatching */
}

/* 00002094-00002154       .text daSail_Execute__FP10sail_class */
static BOOL daSail_Execute(sail_class* i_this) {
    static cXyz sail_offset(0.0f, 2100.0f, 100.0f);
    cMtx_multVec(l_p_ship->mpModel->getBaseTRMtx(), &sail_offset, &i_this->current.pos);
    i_this->current.angle = l_p_ship->shape_angle;
    sail_move(i_this);
    return TRUE;
}

/* 00002154-0000215C       .text daSail_IsDelete__FP10sail_class */
static BOOL daSail_IsDelete(sail_class* i_this) {
    return TRUE;
}

/* 0000215C-000021D8       .text daSail_Delete__FP10sail_class */
static BOOL daSail_Delete(sail_class* i_this) {
    dComIfG_resDelete(&i_this->mClothPhase, "Cloth");
    dComIfG_resDelete(&i_this->mKaizokusenPhase, "Kaizokusen");
    
    if (l_HIO.mChildID >= 0) {
        mDoHIO_root.m_subroot.deleteChild(l_HIO.mChildID);
        l_HIO.mChildID = -1;
    }
    
    return TRUE;
}

/* 000021D8-00002254       .text daSail_checkCreateHeap__FP10fopAc_ac_c */
static BOOL daSail_checkCreateHeap(fopAc_ac_c* i_actor) {
    sail_class* i_this = (sail_class*)i_actor;
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes("Kaizokusen", KAIZOKUSEN_INDEX_BDL_AMAST);
    if (modelData == NULL) {
        return FALSE;
    }
    i_this->mSailPacket.m1C3C = mDoExt_J3DModel__create(modelData, 0x00080000, 0x11000002);
    if (i_this->mSailPacket.m1C3C) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 00002254-000024E4       .text daSail_Create__FP10fopAc_ac_c */
static s32 daSail_Create(fopAc_ac_c* i_actor) {
    /* Nonmatching */
    fopAcM_SetupActor(i_actor, sail_class);
    sail_class* i_this = (sail_class*)i_actor;
    
    int phase_state = dComIfG_resLoad(&i_this->mClothPhase, "Cloth");
    if (phase_state != cPhs_COMPLEATE_e) {
        return phase_state;
    }
    phase_state = dComIfG_resLoad(&i_this->mKaizokusenPhase, "Kaizokusen");
    if (phase_state != cPhs_COMPLEATE_e) {
        return phase_state;
    }
    
    phase_state = cPhs_COMPLEATE_e;
    if (fopAcM_entrySolidHeap(i_this, daSail_checkCreateHeap, 0x4C0)) {
        if (l_HIO.mChildID < 0) {
            l_HIO.mChildID = mDoHIO_root.m_subroot.createChild("海賊船の帆", &l_HIO); // "Pirate Ship's Sail"
        }
        
        i_this->mSailPacket.m1C44 = 0.0f;
        i_this->mSailPacket.m1C48 = 0.0f;
        cXyz* r6 = &i_this->mSailPacket.m0884[0];
        cXyz* r7 = &i_this->mSailPacket.m00A4[i_this->mSailPacket.m1C3A * 0x54]; // this is probably one of daSail_packet_c's inlines
        for (int i = 0; i < ARRAY_SIZE(l_pos); i++, r6++, r7++) {
            r6->setall(0.0f);
            r7->set(l_pos[i]);
        }
        
        l_p_ship = (daObjPirateship::Act_c*)fopAcM_SearchByID(i_this->parentActorID);
        if (l_p_ship->m2CE == 0) {
            l_HIO.m06 = 0;
            i_this->mSailPacket.m1C44 = 0.6f;
        } else {
            l_HIO.m06 = 1;
        }
        
        sail_move(i_this);
    } else {
        phase_state = cPhs_ERROR_e;
    }
    
    return phase_state;
}

static actor_method_class l_daSail_Method = {
    (process_method_func)daSail_Create,
    (process_method_func)daSail_Delete,
    (process_method_func)daSail_Execute,
    (process_method_func)daSail_IsDelete,
    (process_method_func)daSail_Draw,
};

actor_process_profile_definition g_profile_SAIL = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_SAIL,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(sail_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0069,
    /* Actor SubMtd */ &l_daSail_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
