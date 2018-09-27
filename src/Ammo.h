#ifndef AMMO_H
#define AMMO_H

#include <irrlicht.h>

class Ammo{
    public:
        Ammo(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver);
    private:
        float radius;
};

#endif // AMMO_H
