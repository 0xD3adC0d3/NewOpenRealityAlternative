#include "Map.h"
#include <irrlicht.h>
#include "Building.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;
using namespace gui;
using namespace io;

Map::Map(ISceneManager *smgr, IVideoDriver *driver, IMetaTriangleSelector *selectorGlobal){
    //Sky
    smgr->addSkyDomeSceneNode(driver->getTexture("media/map/sky/skydome.jpg"), 16, 8, 0.95f, 2.0f);

    //City
    Building(smgr, selectorGlobal, smgr->getMesh("media/map/city/city.obj"), vector3df(15.f));
}
