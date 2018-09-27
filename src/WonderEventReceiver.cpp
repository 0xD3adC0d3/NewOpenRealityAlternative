#include "WonderEventReceiver.h"
#include <irrlicht.h>
#include "GraphicsUtils.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;
using namespace gui;
using namespace io;

WonderEventReceiver::WonderEventReceiver(){
    keepPlaying = true;
    gu = 0;
    player = 0;

    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i){
        KeyIsDown[i] = false;
    }
}

bool WonderEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode){
    return KeyIsDown[keyCode];
}

void WonderEventReceiver::setParams(Player *pl, GraphicsUtils *gUtils){
    player = pl;
    gu = gUtils;
}

bool WonderEventReceiver::OnEvent(const SEvent& event){
	if(event.EventType == EET_MOUSE_INPUT_EVENT && event.MouseInput.Event == EMIE_LMOUSE_LEFT_UP){
        player->getPlayerWeapon()->shoot();
	} else if(event.EventType == EET_KEY_INPUT_EVENT && event.KeyInput.Key == KEY_F1 && event.KeyInput.PressedDown == false){
        gu->snapshot();
	} else if(event.EventType == EET_KEY_INPUT_EVENT && event.KeyInput.Key == KEY_ESCAPE && event.KeyInput.PressedDown == false){
        keepPlaying = false;
	} else if(event.EventType == EET_KEY_INPUT_EVENT && event.KeyInput.Key == KEY_KEY_R && event.KeyInput.PressedDown == false){
        player->getPlayerWeapon()->reload();
	}

	if (event.EventType == EET_KEY_INPUT_EVENT){
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

	return false;
}

bool WonderEventReceiver::getKeepPlaying(){
    return keepPlaying;
}

void WonderEventReceiver::setKeppPlaying(bool val){
    keepPlaying = val;
}
