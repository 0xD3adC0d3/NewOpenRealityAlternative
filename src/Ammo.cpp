#include "Ammo.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;

Ammo::Ammo(ISceneManager *smgr, IVideoDriver *driver){
    radius = 3;

    ISceneNode *bulletNode = smgr->addSphereSceneNode(radius, 32);
    bulletNode->setMaterialFlag(EMF_LIGHTING, false);
    bulletNode->setMaterialTexture(0, driver->getTexture("media/gun/bullet/fireball.bmp"));
    bulletNode->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
}
