#pragma once
#include <libultraship/ImGuiImpl.h>

#define PATCH_GFX(path, name, cvar, index, instruction) \
    if (CVar_GetS32(cvar, 0)) { \
        ResourceMgr_PatchGfxByName(path, name, index, instruction); \
    } else { \
        ResourceMgr_UnpatchGfxByName(path, name); \
    }

typedef struct {
    const std::string Name;
    const std::string ToolTip;
    const std::string CvarName;
    ImVec4 ModifiedColor;
    ImVec4 DefaultColor;
    bool canRainbow;
    bool hasAlpha;
    bool sameLine;
} CosmeticsColorIndividual;

static float TablesCellsWidth = 300.0f;
static ImGuiTableColumnFlags FlagsTable = ImGuiTableFlags_BordersH | ImGuiTableFlags_BordersV;
static ImGuiTableColumnFlags FlagsCell = ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_IndentEnable | ImGuiTableColumnFlags_NoSort;
static ImVec4 navi_idle_i_col;        static ImVec4 navi_idle_o_col;
static ImVec4 navi_npc_i_col;         static ImVec4 navi_npc_o_col;
static ImVec4 navi_enemy_i_col;       static ImVec4 navi_enemy_o_col;
static ImVec4 navi_prop_i_col;        static ImVec4 navi_prop_o_col;
static ImVec4 swordtrailtop_col;      static ImVec4 swordtrailbottom_col;
static ImVec4 boomtrailstart_col;     static ImVec4 boomtrailend_col;
static ImVec4 bombtrail_col;           
static ImVec4 crtfilter;
static ImVec4 normalarrow_col;        static ImVec4 firearrow_col;           static ImVec4 icearrow_col;            static ImVec4 lightarrow_col;
static ImVec4 normalarrow_colenv;     static ImVec4 firearrow_colenv;        static ImVec4 icearrow_colenv;         static ImVec4 lightarrow_colenv;
static ImVec4 charged1_col;           static ImVec4 charged2_col;
static ImVec4 charged1_colenv;        static ImVec4 charged2_colenv;
static ImVec4 Keese1_primcol;         static ImVec4 Keese2_primcol;
static ImVec4 Keese1_envcol;          static ImVec4 Keese2_envcol;
static ImVec4 doggo1col;              static ImVec4 doggo2col;
static ImVec4 df_col;                 static ImVec4 df_colenv;
static ImVec4 nl_diam_col;            static ImVec4 nl_diam_colenv;
static ImVec4 nl_orb_col;             static ImVec4 nl_orb_colenv;
static ImVec4 tc_ou_colors;           static ImVec4 tc_bu_colors;
static ImVec4 tc_fire_colors;         static ImVec4 tc_fire_colors_env; 

//Navi
static CosmeticsColorIndividual Navi_Idle_Inner = { "Navi Idle (Primary)", "Inner color for Navi (idle flying around)", "gNavi_Idle_Inner", navi_idle_i_col, ImVec4(255, 255, 255, 255), false, false, false };
static CosmeticsColorIndividual Navi_Idle_Outer = { "Navi Idle (Secondary)", "Outer color for Navi (idle flying around)", "gNavi_Idle_Outer", navi_idle_o_col, ImVec4(0, 0, 255, 255), false, false, false };
static CosmeticsColorIndividual Navi_Npc_Inner = { "Navi NPC (Primary)", "Inner color for Navi (when Navi fly around NPCs)", "gNavi_NPC_Inner", navi_npc_i_col, ImVec4(150, 150, 255, 255), false, false, false };
static CosmeticsColorIndividual Navi_Npc_Outer = { "Navi NPC (Secondary)", "Outer color for Navi (when Navi fly around NPCs)", "gNavi_NPC_Outer", navi_npc_o_col, ImVec4(150, 150, 255, 255), false, false, false };
static CosmeticsColorIndividual Navi_Enemy_Inner = { "Navi Enemy (Primary)", "Inner color for Navi (when Navi fly around Enemies or Bosses)", "gNavi_Enemy_Inner", navi_enemy_i_col, ImVec4(255, 255, 0, 255), false, false, false };
static CosmeticsColorIndividual Navi_Enemy_Outer = { "Navi Enemy (Secondary)", "Outer color for Navi (when Navi fly around Enemies or Bosses)", "gNavi_Enemy_Outer", navi_enemy_o_col, ImVec4(220, 155, 0, 255), false, false, false };
static CosmeticsColorIndividual Navi_Prop_Inner = { "Navi Props (Primary)", "Inner color for Navi (when Navi fly around props (signs etc))", "gNavi_Prop_Inner", navi_prop_i_col, ImVec4(0, 255, 0, 255), false, false, false };
static CosmeticsColorIndividual Navi_Prop_Outer = { "Navi Props (Secondary)", "Outer color for Navi (when Navi fly around props (signs etc))", "gNavi_Prop_Outer", navi_prop_o_col, ImVec4(0, 255, 0, 255), false, false, false };

//Keese
static CosmeticsColorIndividual Keese1_prim = { "Fire Primary color", "Affects the primary color of the Fire itself of the Keese", "gKeese1_Ef_Prim", Keese1_primcol, ImVec4(255, 255, 100, 255), true, false, false };
static CosmeticsColorIndividual Keese2_prim = { "Ice Primary color", "Affects the primary color of the Ice itself of the Keese", "gKeese2_Ef_Prim", Keese2_primcol, ImVec4(100, 200, 255, 255), true, false, false };
static CosmeticsColorIndividual Keese1_env = { "Fire Secondary color", "Affects the secondary color of the Fire itself of the Keese", "gKeese1_Ef_Env", Keese1_envcol, ImVec4(255, 50, 0, 255), true, false, false };
static CosmeticsColorIndividual Keese2_env = { "Ice Secondary color", "Affects the secondary color of the Ice itself of the Keese", "gKeese2_Ef_Env", Keese2_envcol, ImVec4(0, 0, 255, 255), true, false, false };

//Good old Dogs, we all love them
static CosmeticsColorIndividual DogN1 = { "Dog white", "Affects the colors of the white dog", "gDog1Col", doggo1col, ImVec4(255,255,200,255), true, false, true };
static CosmeticsColorIndividual DogN2 = { "Dog brown", "Affects the colors of the brown dog", "gDog2Col", doggo2col, ImVec4(150,100,50,255), true, false, true };

//Arrows (Fire -> Ice -> Light)
static CosmeticsColorIndividual Normal_Arrow_Prim = { "Normal Arrows (primary)", "Affects Primary color", "gNormalArrowCol", normalarrow_col, ImVec4(255, 255, 170, 255), true, false, false };
static CosmeticsColorIndividual Normal_Arrow_Env = { "Normal Arrows (Secondary)", "Affects Secondary color", "gNormalArrowColEnv", normalarrow_colenv, ImVec4(0, 150, 0, 0), true, false, false };
static CosmeticsColorIndividual Fire_Arrow_Prim = { "Fire Arrows (primary)", "Affects Primary color", "gFireArrowCol", firearrow_col, ImVec4(255,200,0,255), true, false, false };
static CosmeticsColorIndividual Fire_Arrow_Env = { "Fire Arrows (Secondary)", "Affects Secondary color", "gFireArrowColEnv", firearrow_colenv, ImVec4(255,0,0,255), true, false, false };
static CosmeticsColorIndividual Ice_Arrow_Prim = { "Ice Arrows (Primary)", "Affects Primary color", "gIceArrowCol", icearrow_col, ImVec4(170,255,255,255), true, false, false };
static CosmeticsColorIndividual Ice_Arrow_Env = { "Ice Arrows (Secondary)", "Affects Secondary color", "gIceArrowColEnv", icearrow_colenv, ImVec4(0,0,255,255), true, false, false };
static CosmeticsColorIndividual Light_Arrow_Prim = { "Light Arrows (Primary)", "Affects Primary color", "gLightArrowCol", lightarrow_col, ImVec4(255,255,170,255), true, false, false };
static CosmeticsColorIndividual Light_Arrow_Env = { "Light Arrows (Secondary)", "Affects Secondary color", "gLightArrowColEnv", lightarrow_colenv, ImVec4(255,255,0,255), true, false, false };

//Spells
static CosmeticsColorIndividual Din_Fire_Prim = { "Din's Fire (primary)", "Affects Primary color", "gDF_Col", df_col, ImVec4(255,200,0,255), true, false, false };
static CosmeticsColorIndividual Din_Fire_Env = { "Din's Fire (Secondary)", "Affects Secondary color", "gDF_Env", df_colenv, ImVec4(255,0,0,255), true, false, false };
static CosmeticsColorIndividual Nayru_Diamond_Prim = { "Nayru's Love Diamond (primary)", "Affects Primary color", "gNL_Diamond_Col", nl_diam_col, ImVec4(170,255,255,255), true, false, false };
static CosmeticsColorIndividual Nayru_Diamond_Env = { "Nayru's Love Diamond (Secondary)", "Affects Secondary color", "gNL_Diamond_Env", nl_diam_colenv, ImVec4(100,255,128,255), true, false, false };
static CosmeticsColorIndividual Nayru_Orb_Prim = { "Nayru's Love Orb (primary)", "Affects Primary color", "gNL_Orb_Col", nl_orb_col, ImVec4(170,255,255,255), true, false, false };
static CosmeticsColorIndividual Nayru_Orb_Env = { "Nayru's Love Orb (Secondary)", "Affects Secondary color", "gNL_Orb_Env", nl_orb_colenv, ImVec4(150,255,255,255), true, false, false };

//Spin attacks colors
static CosmeticsColorIndividual Spin_Lv1_Prim = { "Level 1 (primary)", "Affects Primary color", "gCharged1Col", charged1_col, ImVec4(170,255,255,255), true, false, false };
static CosmeticsColorIndividual Spin_Lv1_Env = { "Level 1 (Secondary)", "Affects Secondary color", "gCharged1ColEnv", charged1_colenv, ImVec4(0,100,255,255), true, false, false };
static CosmeticsColorIndividual Spin_Lv2_Prim = { "Level 2 (primary)", "Affects Primary color", "gCharged2Col", charged2_col, ImVec4(255,255,170,255), true, false, false };
static CosmeticsColorIndividual Spin_Lv2_Env = { "Level 2 (Secondary)", "Affects Secondary color", "gCharged2ColEnv", charged2_colenv, ImVec4(255,100,0,255), true, false, false };

//Trails
static CosmeticsColorIndividual Sword_Trails_Top_col = { "Sword Trail Top Color", "Affects top of sword slash", "gSwordTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Sword_Trails_Bottom_col = { "Sword Trail End Color", "Affects bottom of sword slash", "gSwordTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Boom_Trails_Start_col = { "Boomerang Trail Start Color", "Affects start of boomerang trail", "gBoomTrailStartCol", boomtrailstart_col, ImVec4(255,255,100,255), true, false, false };
static CosmeticsColorIndividual Boom_Trails_End_col = { "Boomerang Trail End Color", "Affects end of boomerang trail", "gBoomTrailEndCol", boomtrailend_col, ImVec4(255,255,100,255), true, false, false };
static CosmeticsColorIndividual Bomb_Trails_col = { "Bombchu Trail Color", "Affects Bomchus", "gBombTrailCol", bombtrail_col, ImVec4(250,0,0,255), true, false, false };


static CosmeticsColorIndividual KSword_Trails_Top_col = { "Kokiri Sword Top Color", "Affects top of sword slash", "gKSwordTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual KSword_Trails_Bottom_col = { "Kokiri Sword End Color", "Affects bottom of sword slash", "gKSwordTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual MSword_Trails_Top_col = { "Master Sword Top Color", "Affects top of sword slash", "gMSwordTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual MSword_Trails_Bottom_col = { "Master Sword End Color", "Affects bottom of sword slash", "gMSwordTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual BSword_Trails_Top_col = { "BG Sword Top Color", "Affects top of sword slash", "gBSwordTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual BSword_Trails_Bottom_col = { "BG Sword End Color", "Affects bottom of sword slash", "gBSwordTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Stick_Trails_Top_col = { "Stick Top Color", "Affects top of stick swing", "gStickTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Stick_Trails_Bottom_col = { "Stick End Color", "Affects bottom of stick swing", "gStickTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Hammer_Trails_Top_col = { "Hammer Top Color", "Affects top of hammer swing", "gHammerTrailTopCol", swordtrailtop_col, ImVec4(255,255,255,255), true, false, false };
static CosmeticsColorIndividual Hammer_Trails_Bottom_col = { "Hammer End Color", "Affects bottom of hammer swing", "gHammerTrailBottomCol", swordtrailbottom_col, ImVec4(255,255,255,255), true, false, false };

//Title Cards colors
static CosmeticsColorIndividual TitleCards_OW = { "Main color (Overworld)", "Affects all the overworld title cards color, white is the default value", "gCCTC_OW_U_Prim", tc_ou_colors, ImVec4(255, 255, 255, 255), false, false, false };
static CosmeticsColorIndividual TitleCards_DG = { "Main color (Dungeon)", "Affects all the bosses title cards color, white is the default value", "gCCTC_B_U_Prim", tc_bu_colors, ImVec4(255, 255, 255, 255), false, false, false };

//Misc. colors, the one I have no clue where to put nor that aren't that important
#ifdef MASTER_QUEST
static CosmeticsColorIndividual TitleScreen_fire_Prim = { "Opening logo fire (Primary)", "Affects the fire behind the title screen logo", "gCCTCFirePrim", tc_fire_colors, ImVec4(170, 255, 255, 255), false, false, false };
static CosmeticsColorIndividual TitleScreen_fire_Env = { "Opening logo fire (Secondary)", "Affects the fire behind the title screen logo", "gCCTCFireEnv", tc_fire_colors_env, ImVec4(200, 255, 0, 255), false, false, false };
#else
static CosmeticsColorIndividual TitleScreen_fire_Prim = { "Opening logo fire (Primary)", "Affects the fire behind the title screen logo", "gCCTCFirePrim", tc_fire_colors, ImVec4(255, 255, 170, 255), false, false, false };
static CosmeticsColorIndividual TitleScreen_fire_Env = { "Opening logo fire (Secondary)", "Affects the fire behind the title screen logo", "gCCTCFireEnv", tc_fire_colors_env, ImVec4(255, 100, 0, 255), false, false, false };
#endif

void InitCosmeticsEditor();//Init the menu itself
ImVec4 GetRandomValue(int MaximumPossible);
