#include "Holiday.hpp"
#include <libultraship/libultraship.h>
#include "soh/UIWidgets.hpp"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/Enhancements/custom-message/CustomMessageManager.h"
#include "include/message_data_fmt.h"
#include "soh/OTRGlobals.h"

extern "C" {
#include "macros.h"
#include "functions.h"
#include "variables.h"
extern PlayState* gPlayState;
}

static void ConfigurationChanged() {
    COND_ID_HOOK(OnOpenText, 0x406B, IS_RANDO, [](u16 * textId, bool* loadFromMessageTable) {
        if (gPlayState->sceneNum != SCENE_KAKARIKO_VILLAGE) {
            return;
        }

        std::string message;
        uint8_t current = gSaveContext.triforcePiecesCollected;
        uint8_t required = OTRGlobals::Instance->gRandomizer->GetRandoSettingValue(RSK_TRIFORCE_HUNT_PIECES_REQUIRED);

        if (current < required) {
            message = "The %yChristmas tree%w seems to be&missing some of %gits magic%w... Find all&ornaments to save %rChristmas%w!";
        } else {
            message = "The tree's magic has been fully&restored. %gMerry %rChristmas%w!";
        }

        auto messageEntry = CustomMessage(message);
        messageEntry.Format();
        messageEntry.LoadIntoFont();
        *loadFromMessageTable = false;
    });
}

static void RegisterMod() {
    // #region Leave this alone unless you know what you are doing
    ConfigurationChanged();
    // #endregion

    GameInteractor::Instance->RegisterGameHook<GameInteractor::OnLoadGame>([](int16_t fileNum) {
        ConfigurationChanged();
    });
}

static Holiday holiday([]() {}, RegisterMod);
