#ifndef PLAYER_H
#define PLAYER_H

#include <irrlicht.h>
#include "PlayerWeapon.h"
#include <irrKlang.h>

class Player
{
    public:
        Player(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver, irr::scene::IMetaTriangleSelector *selectorGlobal, irrklang::ISoundEngine *soundEngine, irr::gui::IGUIStaticText *textAmmo, irr::gui::IGUIStaticText *textHealth);
        float getCameraX();
        float getCameraY();
        float getCameraZ();
        PlayerWeapon *getPlayerWeapon();
        virtual ~Player();
        void receiveDamage(int damage);
        irr::scene::ICameraSceneNode *getCamera();
    private:
        bool noVerticalMovement;
		irr::f32 jumpSpeed;
		irr::core::vector3df spawn;
		irr::core::vector3df target;
		float farValue;
		irr::scene::ICameraSceneNode *camera;
		PlayerWeapon *pw;
		int health;
		irr::gui::IGUIStaticText *text;
		bool alive;

};

#endif // PLAYER_H
