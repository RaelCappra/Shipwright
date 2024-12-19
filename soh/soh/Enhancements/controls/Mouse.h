#ifndef MOUSE_H
#define MOUSE_H

#pragma once

#include "soh/OTRGlobals.h"
#include <libultraship/libultraship.h>
#include "z64player.h"
#include "global.h"

#ifdef __cplusplus
extern "C" {
#endif
void Mouse_UpdatePos();
void Mouse_UpdatePosRel();
void Mouse_UpdatePosWheel();
void Mouse_UpdateAll();
void Mouse_RecenterCursor();
void Mouse_HandleThirdPerson(f32* newCamX, f32* newCamY);
void Mouse_HandleFirstPerson(Player* player, s8 invertXAxisMulti, s8 invertYAxisMulti);
void Mouse_HandleShield(f32* sp50, f32* sp54);
bool Mouse_HandleQuickspin(s8* iter2, s8* sp3C);
void Mouse_UpdateQuickspinCount();
#ifdef __cplusplus
}; //extern "C"
#endif

//MOUSE_H
#endif
