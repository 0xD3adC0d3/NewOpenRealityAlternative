#ifndef PLAYERWEAPON_H
#define PLAYERWEAPON_H

#include <irrlicht.h>
#include <irrKlang.h>

class PlayerWeapon{
    public:
        PlayerWeapon(irr::scene::ISceneManager *smgrP, irr::video::IVideoDriver *driverP, irrklang::ISoundEngine *se, irr::gui::IGUIStaticText *textP);
        void shoot();
        void reload();
        void updateHUD();
	private:
        int ammoNbr;
        int maxAmmo;
        int spareAmmo;
        irr::scene::ISceneManager *smgr;
        irr::video::IVideoDriver *driver;
        irrklang::ISoundEngine *soundEngine;
        irr::gui::IGUIStaticText *text;
};

#endif

