#ifndef TARGET_H
#define TARGET_H

#include "GraphicsUtils.h"
#include <irrlicht.h>

class Target{
    public:
        Target(int idP, GraphicsUtils *gu);
        ~Target();
        void receiveDamage(int damage);
        bool isAlive();
    private:
        int id;
        int health;
        irr::scene::IMeshSceneNode *node;
        bool alive;
};

#endif // TARGET_H
