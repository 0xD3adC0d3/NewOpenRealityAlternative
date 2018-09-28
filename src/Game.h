#ifndef GAME_H
#define GAME_H

#include <irrlicht.h>
#include "GraphicsUtils.h"
#include "WonderEventReceiver.h"
#include "Target.h"

class Game{
    public:
        Game(int w, int h, bool fs);

    private:
        void startGraphics();
        void collisionCallBack();

        GraphicsUtils                       gu;
        WonderEventReceiver                 receiver;
        irr::IrrlichtDevice                 *device;
        irr::scene::ISceneManager           *smgr;
        irr::video::IVideoDriver            *driver;
        irr::gui::IGUIEnvironment           *guienv;
        irr::gui::IGUIStaticText            *text0;
		irr::gui::IGUIStaticText            *text1;
        irr::scene::IMetaTriangleSelector   *selectorGlobal;
        Target                              *target;

        int screenW;
        int screenH;
        bool fullScreen;
};

#endif // GAME_H
