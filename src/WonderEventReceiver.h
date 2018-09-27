#ifndef WONDEREVENTRECEIVER_H
#define WONDEREVENTRECEIVER_H

#include <irrlicht.h>
#include "GraphicsUtils.h"
#include "Player.h"

class WonderEventReceiver : public irr::IEventReceiver{
    public:
        WonderEventReceiver();
        virtual bool OnEvent(const irr::SEvent &event);
        bool getKeepPlaying();
        void setKeppPlaying(bool val);
        void setGraphicsUtils(GraphicsUtils *gUtils);
        void setParams(Player *pl, GraphicsUtils *gUtils);

        //Useful for multiplayer
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode);

    private:
        GraphicsUtils *gu;
        bool keepPlaying;
        Player *player;

        //Useful for multiplayer
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];

};

#endif
