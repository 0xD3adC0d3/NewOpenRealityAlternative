#include "Building.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;
using namespace gui;
using namespace io;

Building::Building(ISceneManager *smgr, IMetaTriangleSelector *selectorGlobal, IAnimatedMesh *mesh, vector3df scale){
    IMeshSceneNode *mapNode = smgr->addMeshSceneNode(mesh);
	mapNode->setMaterialFlag(EMF_LIGHTING, false);
	mapNode->setScale(scale);
	ITriangleSelector *selectorMap = smgr->createOctreeTriangleSelector(mapNode->getMesh(), mapNode, 128);
	mapNode->setTriangleSelector(selectorMap);
	selectorGlobal->addTriangleSelector(selectorMap);

    selectorMap->drop();
}
