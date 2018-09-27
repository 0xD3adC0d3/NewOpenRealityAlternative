#ifndef BUILDING_H
#define BUILDING_H

#include <irrlicht.h>

class Building
{
    public:
        Building(irr::scene::ISceneManager *smgr, irr::scene::IMetaTriangleSelector *selectorGlobal, irr::scene::IAnimatedMesh *mesh, irr::core::vector3df scale);
    private:
};

#endif // BUILDING_H
