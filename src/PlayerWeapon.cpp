#include "PlayerWeapon.h"
#include <irrKlang.h>
#include <irrlicht.h>
#include "Ammo.h"

using namespace irr;
using namespace video;
using namespace core;
using namespace scene;
using namespace gui;

using namespace irrklang;

PlayerWeapon::PlayerWeapon(ISceneManager *smgrP, IVideoDriver *driverP, ISoundEngine *se, IGUIStaticText *textP){
    spareAmmo = 90;
    maxAmmo = 10;
    ammoNbr = maxAmmo;
    smgr = smgrP;
    driver = driverP;
    soundEngine = se;

    text = textP;
    updateHUD();

	IAnimatedMeshSceneNode *weaponNode = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/gun/gun.md2"), smgr->getActiveCamera(), 10, vector3df(0, 0, 0), vector3df(-90, -90, 90));
	weaponNode->setMaterialTexture(0, driver->getTexture("media/gun/gun.jpg"));
	weaponNode->setMaterialFlag(EMF_LIGHTING, false);
	weaponNode->setFrameLoop(20, 180);
	weaponNode->setAnimationSpeed(15);
	weaponNode->setLoopMode(true);
}

void PlayerWeapon::shoot(){
   if (ammoNbr > 0){
        soundEngine->play2D("media/sounds/explosion.wav");
        Ammo(smgr, driver);
        ammoNbr--;
        updateHUD();
	}
}

void PlayerWeapon::reload(){
    int need = maxAmmo - ammoNbr;
    if (spareAmmo <= need){
        need = spareAmmo;
    }

    ammoNbr += need;
    spareAmmo -= need;

    updateHUD();
}

void PlayerWeapon::updateHUD(){
    stringw strAmmo = L"Ammo : ";
    strAmmo += ammoNbr;
    strAmmo += "/";
    strAmmo += spareAmmo;
    text->setText(strAmmo.c_str());

    if (ammoNbr > 0 && spareAmmo > 0){
        text->setOverrideColor(SColor(255, 0, 255, 0));
    } else if (ammoNbr > 0 && spareAmmo <= 0){
        text->setOverrideColor(SColor(255, 255, 198, 0));
    } else if (ammoNbr <= 0 && spareAmmo <= 0){
        text->setOverrideColor(SColor(255, 255, 0, 0));
    } else if (ammoNbr <= 0 && spareAmmo > 0){
        text->setOverrideColor(SColor(255, 255, 198, 0));
    } else{
        //Shouldn't happen
        text->setOverrideColor(SColor(255, 0, 0, 255));
    }
}
