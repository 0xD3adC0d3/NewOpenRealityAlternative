#include "Game.h"
#include <irrlicht.h>
#include <irrKlang.h>
#include "WonderEventReceiver.h"
#include "Map.h"
#include "GraphicsUtils.h"
#include "Player.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;
using namespace gui;
using namespace irrklang;

void Game::start(int w, int h, bool fs){
    screenW = w;
    screenH = h;
    fullScreen = fs;

    startGraphics();
    Map(smgr, driver, selectorGlobal);

    ISoundEngine *soundEngine = createIrrKlangDevice();
    soundEngine->play2D("media/sounds/getout.ogg", true);

	Player player = Player(smgr, driver, selectorGlobal, soundEngine, text0, text1);

	receiver.setParams(&player, &gu);
	selectorGlobal->drop();

	u32 timeStamp = device->getTimer()->getTime(), deltaTime = 0;
    while(device->run() && receiver.getKeepPlaying()){
		if (device->isWindowActive()){
			deltaTime = device->getTimer()->getTime() - timeStamp;
            timeStamp = device->getTimer()->getTime();
            driver->beginScene(true, true, 0);
            smgr->drawAll();
            guienv->drawAll();
            gu.crosshair();
            driver->endScene();

			//If the player falls of the map, the game stops.
			if(player.getCameraY() < -500){
                receiver.setKeppPlaying(false);
            }
		} else{
			device->yield();
		}
	}

    device->closeDevice();
    soundEngine->drop();
	device->drop();
}

void Game::startGraphics(){
    gu = GraphicsUtils();
	receiver = WonderEventReceiver();
	device = createDevice(EDT_OPENGL, dimension2d<u32>(screenW, screenH), 32, fullScreen, false, false, &receiver);
    device->setEventReceiver(&receiver);

    if(fullScreen == false){
        stringw str = "N.O.R.A.";
        device->setWindowCaption(str.c_str());
    }

	smgr = device->getSceneManager();
	driver = device->getVideoDriver();
    selectorGlobal = smgr->createMetaTriangleSelector();
    gu.setParams(device, screenW, screenH);
    device->getCursorControl()->setVisible(false);

    guienv = device->getGUIEnvironment();
	IGUISkin *skin = guienv->getSkin();
    skin->setColor(EGDC_BUTTON_TEXT, SColor(255, 255, 255, 255));
    skin->setFont(guienv->getFont("media/fonts/fontlucida.png"));

    text0 = guienv->addStaticText(L"Ammo : ", rect<s32>(gu.getScreenW()*0.8, gu.getScreenH()*0.97, gu.getScreenW()-5, gu.getScreenH()-5));
    text0->setOverrideColor(SColor(255, 0, 255, 0));
    text1 = guienv->addStaticText(L"Health : ", rect<s32>(gu.getScreenW()*0.8, gu.getScreenH()*0.94, gu.getScreenW()-5, gu.getScreenH()-5));
    text1->setOverrideColor(SColor(255, 0, 255, 0));
}
