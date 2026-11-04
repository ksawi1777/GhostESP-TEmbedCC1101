#pragma once
#include <stdint.h>
#include <stddef.h>

/* Built-in IR code database organised as:
 *   Category  →  Brand  →  Command
 *
 * Codes use the parsed (protocol/address/command) format and are sent via
 * infrared_manager_transmit().  Results may vary by model year; for exact
 * codes load a brand-specific .ir file from the SD card instead.
 */

typedef struct {
    const char    *name;
    const char    *protocol;
    uint32_t       address;
    uint32_t       command;
} ir_db_entry_t;

typedef struct {
    const char           *brand;
    const ir_db_entry_t  *entries;
    uint8_t               entry_count;
} ir_db_brand_t;

typedef struct {
    const char           *name;
    const ir_db_brand_t  *brands;
    uint8_t               brand_count;
} ir_db_category_t;

/* ── TV commands ──────────────────────────────────────────────────────────── */

static const ir_db_entry_t ir_tv_samsung[] = {
    {"Power",   "Samsung32", 0x0007, 0x0002},
    {"Vol+",    "Samsung32", 0x0007, 0x0007},
    {"Vol-",    "Samsung32", 0x0007, 0x000B},
    {"Mute",    "Samsung32", 0x0007, 0x000F},
    {"CH+",     "Samsung32", 0x0007, 0x0012},
    {"CH-",     "Samsung32", 0x0007, 0x0010},
    {"Source",  "Samsung32", 0x0007, 0x000D},
    {"Menu",    "Samsung32", 0x0007, 0x001A},
};

static const ir_db_entry_t ir_tv_lg[] = {
    {"Power",   "NEC", 0x0004, 0x0008},
    {"Vol+",    "NEC", 0x0004, 0x0002},
    {"Vol-",    "NEC", 0x0004, 0x0003},
    {"Mute",    "NEC", 0x0004, 0x0009},
    {"CH+",     "NEC", 0x0004, 0x0000},
    {"CH-",     "NEC", 0x0004, 0x0001},
    {"Input",   "NEC", 0x0004, 0x000B},
    {"Menu",    "NEC", 0x0004, 0x001C},
};

static const ir_db_entry_t ir_tv_sony[] = {
    {"Power",   "SIRC", 0x0001, 0x0015},
    {"Vol+",    "SIRC", 0x0001, 0x0012},
    {"Vol-",    "SIRC", 0x0001, 0x0013},
    {"Mute",    "SIRC", 0x0001, 0x0014},
    {"CH+",     "SIRC", 0x0001, 0x0010},
    {"CH-",     "SIRC", 0x0001, 0x0011},
    {"Input",   "SIRC", 0x0001, 0x0025},
    {"Menu",    "SIRC", 0x0001, 0x0060},
};

static const ir_db_entry_t ir_tv_philips[] = {
    {"Power",   "RC5", 0x0000, 0x000C},
    {"Vol+",    "RC5", 0x0000, 0x0010},
    {"Vol-",    "RC5", 0x0000, 0x0011},
    {"Mute",    "RC5", 0x0000, 0x000D},
    {"CH+",     "RC5", 0x0000, 0x0020},
    {"CH-",     "RC5", 0x0000, 0x0021},
    {"Input",   "RC5", 0x0000, 0x0038},
    {"Menu",    "RC5", 0x0000, 0x0012},
};

static const ir_db_entry_t ir_tv_panasonic[] = {
    {"Power",   "Kaseikyo", 0x20280, 0x03D0},
    {"Vol+",    "Kaseikyo", 0x20280, 0x0370},
    {"Vol-",    "Kaseikyo", 0x20280, 0x03F0},
    {"Mute",    "Kaseikyo", 0x20280, 0x0310},
    {"CH+",     "Kaseikyo", 0x20280, 0x03C0},
    {"CH-",     "Kaseikyo", 0x20280, 0x0340},
    {"Input",   "Kaseikyo", 0x20280, 0x0360},
    {"Menu",    "Kaseikyo", 0x20280, 0x03A0},
};

static const ir_db_entry_t ir_tv_sharp[] = {
    {"Power",   "NEC", 0x00AA, 0x0017},
    {"Vol+",    "NEC", 0x00AA, 0x0057},
    {"Vol-",    "NEC", 0x00AA, 0x00D7},
    {"Mute",    "NEC", 0x00AA, 0x0097},
    {"CH+",     "NEC", 0x00AA, 0x0037},
    {"CH-",     "NEC", 0x00AA, 0x00B7},
    {"Input",   "NEC", 0x00AA, 0x00F7},
    {"Menu",    "NEC", 0x00AA, 0x0077},
};

static const ir_db_entry_t ir_tv_toshiba[] = {
    {"Power",   "NEC", 0x0002, 0x000A},
    {"Vol+",    "NEC", 0x0002, 0x001A},
    {"Vol-",    "NEC", 0x0002, 0x001E},
    {"Mute",    "NEC", 0x0002, 0x0012},
    {"CH+",     "NEC", 0x0002, 0x001C},
    {"CH-",     "NEC", 0x0002, 0x001D},
    {"Input",   "NEC", 0x0002, 0x000F},
    {"Menu",    "NEC", 0x0002, 0x001B},
};

static const ir_db_entry_t ir_tv_tcl[] = {
    {"Power",   "NEC", 0x0014, 0x0040},
    {"Vol+",    "NEC", 0x0014, 0x0002},
    {"Vol-",    "NEC", 0x0014, 0x0003},
    {"Mute",    "NEC", 0x0014, 0x0009},
    {"CH+",     "NEC", 0x0014, 0x0000},
    {"CH-",     "NEC", 0x0014, 0x0001},
    {"Input",   "NEC", 0x0014, 0x000B},
    {"Menu",    "NEC", 0x0014, 0x001C},
};

static const ir_db_entry_t ir_tv_hisense[] = {
    {"Power",   "NEC", 0x0040, 0x0012},
    {"Vol+",    "NEC", 0x0040, 0x0002},
    {"Vol-",    "NEC", 0x0040, 0x0003},
    {"Mute",    "NEC", 0x0040, 0x0009},
    {"CH+",     "NEC", 0x0040, 0x0000},
    {"CH-",     "NEC", 0x0040, 0x0001},
    {"Input",   "NEC", 0x0040, 0x000B},
    {"Menu",    "NEC", 0x0040, 0x001C},
};

static const ir_db_entry_t ir_tv_hitachi[] = {
    {"Power",   "NEC", 0x0028, 0x0057},
    {"Vol+",    "NEC", 0x0028, 0x001A},
    {"Vol-",    "NEC", 0x0028, 0x001E},
    {"Mute",    "NEC", 0x0028, 0x0012},
    {"CH+",     "NEC", 0x0028, 0x001C},
    {"CH-",     "NEC", 0x0028, 0x001D},
    {"Input",   "NEC", 0x0028, 0x000F},
    {"Menu",    "NEC", 0x0028, 0x001B},
};

static const ir_db_entry_t ir_tv_jvc[] = {
    {"Power",   "NEC", 0x00C5, 0x0001},
    {"Vol+",    "NEC", 0x00C5, 0x0004},
    {"Vol-",    "NEC", 0x00C5, 0x0005},
    {"Mute",    "NEC", 0x00C5, 0x0002},
    {"CH+",     "NEC", 0x00C5, 0x0012},
    {"CH-",     "NEC", 0x00C5, 0x0013},
    {"Input",   "NEC", 0x00C5, 0x000D},
    {"Menu",    "NEC", 0x00C5, 0x0040},
};

static const ir_db_entry_t ir_tv_grundig[] = {
    {"Power",   "RC5", 0x0000, 0x000C},
    {"Vol+",    "RC5", 0x0000, 0x0010},
    {"Vol-",    "RC5", 0x0000, 0x0011},
    {"Mute",    "RC5", 0x0000, 0x000D},
    {"CH+",     "RC5", 0x0000, 0x0020},
    {"CH-",     "RC5", 0x0000, 0x0021},
    {"Input",   "RC5", 0x0000, 0x0038},
    {"Menu",    "RC5", 0x0000, 0x0012},
};

static const ir_db_entry_t ir_tv_pioneer[] = {
    {"Power",   "Pioneer", 0x00A5A5A5, 0x00BCF740},
    {"Vol+",    "Pioneer", 0x00A5A5A5, 0x00B4F740},
    {"Vol-",    "Pioneer", 0x00A5A5A5, 0x00B0F740},
    {"Mute",    "Pioneer", 0x00A5A5A5, 0x00B8F740},
    {"CH+",     "Pioneer", 0x00A5A5A5, 0x00A4F740},
    {"CH-",     "Pioneer", 0x00A5A5A5, 0x00A0F740},
    {"Input",   "Pioneer", 0x00A5A5A5, 0x00A8F740},
    {"Menu",    "Pioneer", 0x00A5A5A5, 0x00B6F740},
};

static const ir_db_entry_t ir_tv_rca[] = {
    {"Power",   "RCA", 0x000F, 0x0054},
    {"Vol+",    "RCA", 0x000F, 0x0012},
    {"Vol-",    "RCA", 0x000F, 0x0013},
    {"Mute",    "RCA", 0x000F, 0x000F},
    {"CH+",     "RCA", 0x000F, 0x001E},
    {"CH-",     "RCA", 0x000F, 0x001F},
    {"Input",   "RCA", 0x000F, 0x0028},
    {"Menu",    "RCA", 0x000F, 0x0038},
};

static const ir_db_entry_t ir_tv_vizio[] = {
    {"Power",   "NEC", 0x0020, 0x0052},
    {"Vol+",    "NEC", 0x0020, 0x0007},
    {"Vol-",    "NEC", 0x0020, 0x000B},
    {"Mute",    "NEC", 0x0020, 0x000F},
    {"CH+",     "NEC", 0x0020, 0x0012},
    {"CH-",     "NEC", 0x0020, 0x0010},
    {"Input",   "NEC", 0x0020, 0x000D},
    {"Menu",    "NEC", 0x0020, 0x001A},
};

static const ir_db_entry_t ir_tv_beko[] = {
    {"Power",   "NEC", 0x0046, 0x0054},
    {"Vol+",    "NEC", 0x0046, 0x0019},
    {"Vol-",    "NEC", 0x0046, 0x001A},
    {"Mute",    "NEC", 0x0046, 0x0045},
    {"CH+",     "NEC", 0x0046, 0x0017},
    {"CH-",     "NEC", 0x0046, 0x0018},
    {"Input",   "NEC", 0x0046, 0x0051},
    {"Menu",    "NEC", 0x0046, 0x0053},
};

/* ── Projector commands ───────────────────────────────────────────────────── */

static const ir_db_entry_t ir_proj_epson[] = {
    {"Power",   "NEC", 0x17EE, 0x0017},
    {"Vol+",    "NEC", 0x17EE, 0x0001},
    {"Vol-",    "NEC", 0x17EE, 0x0002},
    {"Mute",    "NEC", 0x17EE, 0x000A},
    {"Menu",    "NEC", 0x17EE, 0x0040},
    {"Freeze",  "NEC", 0x17EE, 0x0030},
};

static const ir_db_entry_t ir_proj_benq[] = {
    {"Power",   "NEC", 0x2626, 0x0002},
    {"Vol+",    "NEC", 0x2626, 0x0010},
    {"Vol-",    "NEC", 0x2626, 0x0011},
    {"Mute",    "NEC", 0x2626, 0x0012},
    {"Menu",    "NEC", 0x2626, 0x0040},
    {"Freeze",  "NEC", 0x2626, 0x0030},
};

static const ir_db_entry_t ir_proj_optoma[] = {
    {"Power",   "NEC", 0x08F7, 0x0097},
    {"Vol+",    "NEC", 0x08F7, 0x0001},
    {"Vol-",    "NEC", 0x08F7, 0x0002},
    {"Mute",    "NEC", 0x08F7, 0x000A},
    {"Menu",    "NEC", 0x08F7, 0x0040},
    {"Freeze",  "NEC", 0x08F7, 0x0030},
};

static const ir_db_entry_t ir_proj_viewsonic[] = {
    {"Power",   "NEC", 0x0010, 0x0045},
    {"Vol+",    "NEC", 0x0010, 0x001A},
    {"Vol-",    "NEC", 0x0010, 0x001B},
    {"Mute",    "NEC", 0x0010, 0x001C},
    {"Menu",    "NEC", 0x0010, 0x0040},
    {"Freeze",  "NEC", 0x0010, 0x0030},
};

/* ── Audio/Receiver commands ──────────────────────────────────────────────── */

static const ir_db_entry_t ir_audio_sony[] = {
    {"Power",   "SIRC", 0x0011, 0x0015},
    {"Vol+",    "SIRC", 0x0011, 0x0012},
    {"Vol-",    "SIRC", 0x0011, 0x0013},
    {"Mute",    "SIRC", 0x0011, 0x0014},
    {"Input",   "SIRC", 0x0011, 0x0025},
    {"Play",    "SIRC", 0x0011, 0x0032},
    {"Pause",   "SIRC", 0x0011, 0x0033},
    {"Stop",    "SIRC", 0x0011, 0x0031},
};

static const ir_db_entry_t ir_audio_samsung[] = {
    {"Power",   "Samsung32", 0x0007, 0x00E0},
    {"Vol+",    "Samsung32", 0x0007, 0x00E7},
    {"Vol-",    "Samsung32", 0x0007, 0x00E3},
    {"Mute",    "Samsung32", 0x0007, 0x00EF},
    {"Input",   "Samsung32", 0x0007, 0x00ED},
    {"Play",    "Samsung32", 0x0007, 0x00CE},
    {"Pause",   "Samsung32", 0x0007, 0x00CA},
    {"Stop",    "Samsung32", 0x0007, 0x00C6},
};

static const ir_db_entry_t ir_audio_lg[] = {
    {"Power",   "NEC", 0x0004, 0x0088},
    {"Vol+",    "NEC", 0x0004, 0x0082},
    {"Vol-",    "NEC", 0x0004, 0x0083},
    {"Mute",    "NEC", 0x0004, 0x0089},
    {"Input",   "NEC", 0x0004, 0x008B},
    {"Play",    "NEC", 0x0004, 0x00B6},
    {"Pause",   "NEC", 0x0004, 0x00BA},
    {"Stop",    "NEC", 0x0004, 0x00B5},
};

/* ── Brand tables per category ────────────────────────────────────────────── */

static const ir_db_brand_t ir_db_tv_brands[] = {
    {"Samsung",   ir_tv_samsung,   8},
    {"LG",        ir_tv_lg,        8},
    {"Sony",      ir_tv_sony,      8},
    {"Philips",   ir_tv_philips,   8},
    {"Panasonic", ir_tv_panasonic, 8},
    {"Sharp",     ir_tv_sharp,     8},
    {"Toshiba",   ir_tv_toshiba,   8},
    {"TCL",       ir_tv_tcl,       8},
    {"Hisense",   ir_tv_hisense,   8},
    {"Hitachi",   ir_tv_hitachi,   8},
    {"JVC",       ir_tv_jvc,       8},
    {"Grundig",   ir_tv_grundig,   8},
    {"Pioneer",   ir_tv_pioneer,   8},
    {"RCA",       ir_tv_rca,       8},
    {"Vizio",     ir_tv_vizio,     8},
    {"Beko",      ir_tv_beko,      8},
};

static const ir_db_brand_t ir_db_projector_brands[] = {
    {"Epson",      ir_proj_epson,     6},
    {"BenQ",       ir_proj_benq,      6},
    {"Optoma",     ir_proj_optoma,    6},
    {"ViewSonic",  ir_proj_viewsonic, 6},
};

static const ir_db_brand_t ir_db_audio_brands[] = {
    {"Sony",    ir_audio_sony,    8},
    {"Samsung", ir_audio_samsung, 8},
    {"LG",      ir_audio_lg,      8},
};

/* ── Top-level categories ─────────────────────────────────────────────────── */

static const ir_db_category_t ir_db_categories[] = {
    {"TV",         ir_db_tv_brands,         16},
    {"Projector",  ir_db_projector_brands,   4},
    {"Audio",      ir_db_audio_brands,       3},
};

#define IR_DB_CATEGORY_COUNT  3
