#include "Target.h"

#include "GraphicsUtils.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;

Target::~Target(){
}

Target::Target(int idP, GraphicsUtils *gu){
    health = 100;
    alive = true;
    id = idP;

    ISceneManager *smgr = gu->getDevice()->getSceneManager();
    IVideoDriver *driver = gu->getDevice()->getVideoDriver();

    float scaleX = 50.f;
	float scaleY = 50.f;
	float scaleZ = 50.f;

	node = smgr->addCubeSceneNode(1.f);
	node->setScale(vector3df(scaleX, scaleY, scaleZ));
	node->setMaterialFlag(EMF_LIGHTING, false);
	node->setMaterialFlag(EMF_NORMALIZE_NORMALS, true);
	node->setMaterialTexture(0, driver->getTexture("media/target/crate.jpg"));
}

void Target::receiveDamage(int damage){
    if(health > 0){
        health -= 1;
        if(health <=0){
            alive = false;
            node->setScale(vector3df(0, 0, 0));
        }
    }
}

bool Target::isAlive(){
    return alive;
}
