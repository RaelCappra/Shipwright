#pragma once

// Total gameplay time is tracked in tenths of seconds
// I.E. game time counts frames at 20fps/2, pause time counts frames at 30fps/3
// Frame counts in z_play.c and z_kaleido_scope_call.c
#define GAMEPLAYSTAT_TOTAL_TIME (gSaveContext.gameplayStats.playTimer / 2 + gSaveContext.gameplayStats.pauseTimer / 3)

void InitStatTracker();

typedef enum {
    // 0x00 to 0x9B (0 to 155) used for getting items,
    // see struct "ItemID" in z64item.h

    /* 0xA0 */ TIMESTAMP_DEFEAT_GOHMA = 0xA0,
    /* 0xA1 */ TIMESTAMP_DEFEAT_KING_DODONGO,
    /* 0xA2 */ TIMESTAMP_DEFEAT_BARINADE,
    /* 0xA3 */ TIMESTAMP_DEFEAT_PHANTOM_GANON,
    /* 0xA4 */ TIMESTAMP_DEFEAT_VOLVAGIA,
    /* 0xA5 */ TIMESTAMP_DEFEAT_MORPHA,
    /* 0xA6 */ TIMESTAMP_DEFEAT_BONGO_BONGO,
    /* 0xA7 */ TIMESTAMP_DEFEAT_TWINROVA,
    /* 0xA8 */ TIMESTAMP_DEFEAT_GANONDORF,
    /* 0xA9 */ TIMESTAMP_DEFEAT_GANON,
    /* 0xAA */ TIMESTAMP_MAX

}GameplayStatTimestamp;

typedef enum {
    COUNT_RUPEES_COLLECTED,
    COUNT_RUPEES_SPENT,
    COUNT_CHESTS_OPENED,
    COUNT_DAMAGE_TAKEN,
    COUNT_ICE_TRAPS,
    COUNT_ROLLS,
    COUNT_BONKS,
    COUNT_PAUSES,
    COUNT_STEPS,
    COUNT_POTS_BROKEN,
    COUNT_BUSHES_CUT,
    COUNT_SWORD_SWINGS,

    COUNT_ENEMIES_DEFEATED_ANUBIS,               // EN_ANUBICE
    COUNT_ENEMIES_DEFEATED_ARMOS,                // EN_AM
    COUNT_ENEMIES_DEFEATED_BARI,                 // EN_VALI
    COUNT_ENEMIES_DEFEATED_BEAMOS,               // EN_VM
    COUNT_ENEMIES_DEFEATED_BIG_OCTO,             // EN_BIGOKUTA
    COUNT_ENEMIES_DEFEATED_BIRI,                 // EN_BILI
    COUNT_ENEMIES_DEFEATED_BUBBLE_GREEN,         // EN_BB
    COUNT_ENEMIES_DEFEATED_BUBBLE_BLUE,          // EN_BB
    COUNT_ENEMIES_DEFEATED_BUBBLE_WHITE,         // EN_BB
    COUNT_ENEMIES_DEFEATED_BUBBLE_RED,           // EN_BB
    COUNT_ENEMIES_DEFEATED_BUSINESS_SCRUB,       // EN_DNS
    COUNT_ENEMIES_DEFEATED_DARK_LINK,            // EN_TORCH2
    COUNT_ENEMIES_DEFEATED_DEAD_HAND,            // EN_DH
    COUNT_ENEMIES_DEFEATED_DEKU_BABA,            // EN_DEKUBABA
    COUNT_ENEMIES_DEFEATED_DEKU_BABA_BIG,        // EN_DEKUBABA
    COUNT_ENEMIES_DEFEATED_DEKU_SCRUB,           // EN_HINTNUTS
    COUNT_ENEMIES_DEFEATED_DINOLFOS,             // EN_ZF
    COUNT_ENEMIES_DEFEATED_DODONGO,              // EN_DODONGO
    COUNT_ENEMIES_DEFEATED_DODONGO_BABY,         // EN_DODOJR
    COUNT_ENEMIES_DEFEATED_DOOR_TRAP,            // DOOR_KILLER
    COUNT_ENEMIES_DEFEATED_FLARE_DANCER,         // EN_FD
    COUNT_ENEMIES_DEFEATED_FLOORMASTER,          // EN_FLOORMAS
    COUNT_ENEMIES_DEFEATED_FLYING_POT,           // EN_TUBO_TRAP
    COUNT_ENEMIES_DEFEATED_FLOOR_TILE,           // EN_YUKABYUN
    COUNT_ENEMIES_DEFEATED_FREEZARD,             // EN_FZ
    COUNT_ENEMIES_DEFEATED_GIBDO,                // EN_RD
    COUNT_ENEMIES_DEFEATED_GOHMA_LARVA,          // EN_GOMA
    COUNT_ENEMIES_DEFEATED_GUAY,                 // EN_CROW
    COUNT_ENEMIES_DEFEATED_IRON_KNUCKLE,         // EN_IK
    COUNT_ENEMIES_DEFEATED_IRON_KNUCKLE_NABOORU, // EN_IK
    COUNT_ENEMIES_DEFEATED_KEESE,                // EN_FIREFLY
    COUNT_ENEMIES_DEFEATED_KEESE_FIRE,           // EN_FIREFLY
    COUNT_ENEMIES_DEFEATED_KEESE_ICE,            // EN_FIREFLY
    COUNT_ENEMIES_DEFEATED_LEEVER,               // EN_REEBA
    COUNT_ENEMIES_DEFEATED_LEEVER_BIG,           // EN_REEBA
    COUNT_ENEMIES_DEFEATED_LIKE_LIKE,            // EN_RR
    COUNT_ENEMIES_DEFEATED_LIZALFOS,             // EN_ZF
    COUNT_ENEMIES_DEFEATED_MAD_SCRUB,            // EN_DEKUNUTS
    COUNT_ENEMIES_DEFEATED_MOBLIN,               // EN_MB
    COUNT_ENEMIES_DEFEATED_MOBLIN_CLUB,          // EN_MB
    COUNT_ENEMIES_DEFEATED_OCTOROK,              // EN_OKUTA
    COUNT_ENEMIES_DEFEATED_PARASITIC_TENTACLE,   // EN_BA
    COUNT_ENEMIES_DEFEATED_PEAHAT,               // EN_PEEHAT
    COUNT_ENEMIES_DEFEATED_PEAHAT_LARVA,         // EN_PEEHAT
    COUNT_ENEMIES_DEFEATED_POE,                  // EN_POH
    COUNT_ENEMIES_DEFEATED_POE_BIG,              // EN_PO_FIELD
    COUNT_ENEMIES_DEFEATED_POE_COMPOSER,         // EN_POH
    COUNT_ENEMIES_DEFEATED_POE_SISTERS,          // EN_PO_SISTERS
    COUNT_ENEMIES_DEFEATED_REDEAD,               // EN_RD
    COUNT_ENEMIES_DEFEATED_SHABOM,               // EN_BUBBLE
    COUNT_ENEMIES_DEFEATED_SHELLBLADE,           // EN_SB
    COUNT_ENEMIES_DEFEATED_SKULLTULA,            // EN_ST
    COUNT_ENEMIES_DEFEATED_SKULLTULA_BIG,        // EN_ST
    COUNT_ENEMIES_DEFEATED_SKULLTULA_GOLD,       // EN_SW
    COUNT_ENEMIES_DEFEATED_SKULLWALLTULA,        // EN_SW
    COUNT_ENEMIES_DEFEATED_SKULL_KID,            // EN_SKJ
    COUNT_ENEMIES_DEFEATED_SPIKE,                // EN_NY
    COUNT_ENEMIES_DEFEATED_STALCHILD,            // EN_SKB
    COUNT_ENEMIES_DEFEATED_STALFOS,              // EN_TEST
    COUNT_ENEMIES_DEFEATED_STINGER,              // EN_WEIYER 
    COUNT_ENEMIES_DEFEATED_TAILPASARAN,          // EN_TP
    COUNT_ENEMIES_DEFEATED_TEKTITE_BLUE,         // EN_TITE
    COUNT_ENEMIES_DEFEATED_TEKTITE_RED,          // EN_TITE
    COUNT_ENEMIES_DEFEATED_TORCH_SLUG,           // EN_BW
    COUNT_ENEMIES_DEFEATED_WALLMASTER,           // EN_WALLMAS
    COUNT_ENEMIES_DEFEATED_WITHERED_DEKU_BABA,   // EN_KAREBABA
    COUNT_ENEMIES_DEFEATED_WOLFOS,               // EN_WF
    COUNT_ENEMIES_DEFEATED_WOLFOS_WHITE,         // EN_WF

    COUNT_AMMO_USED_STICK,
    COUNT_AMMO_USED_NUT,
    COUNT_AMMO_USED_BOMB,
    COUNT_AMMO_USED_ARROW,
    COUNT_AMMO_USED_SEED,
    COUNT_AMMO_USED_BOMBCHU,
    COUNT_AMMO_USED_BEAN,

    COUNT_MAX

} GameplayStatCount;