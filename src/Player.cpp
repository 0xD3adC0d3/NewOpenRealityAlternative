#include "Player.h"
#include <irrlicht.h>
#include "PlayerWeapon.h"
#include <irrKlang.h>

using namespace irr;
using namespace video;
using namespace scene;
using namespace core;
using namespace gui;

using namespace irrklang;

Player::Player(ISceneManager *smgr, IVideoDriver *driver, IMetaTriangleSelector *selectorGlobal, ISoundEngine *soundEngine, IGUIStaticText *textAmmo, IGUIStaticText *textHealth){
    alive = true;
    health = 100;
    jumpSpeed = 4.f;
	noVerticalMovement = true;
	spawn = vector3df(0, 1000, 0);
	target = vector3df(0, 300, -2000);
	farValue = 30000.0f;

	text = textHealth;
    stringw strHealth = L"Health : ";
    strHealth += health;
    text->setText(strHealth.c_str());

    int keyMapSize = 9;
	SKeyMap keyMap[keyMapSize];
	keyMap[0].Action = EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = KEY_UP;
	keyMap[1].Action = EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = KEY_DOWN;
	keyMap[2].Action = EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = KEY_LEFT;
	keyMap[3].Action = EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = KEY_RIGHT;
	keyMap[4].Action = EKA_JUMP_UP;
	keyMap[4].KeyCode = KEY_SPACE;
	keyMap[5].Action = EKA_MOVE_FORWARD;
	keyMap[5].KeyCode = KEY_KEY_Z;
	keyMap[6].Action = EKA_MOVE_BACKWARD;
	keyMap[6].KeyCode = KEY_KEY_S;
	keyMap[7].Action = EKA_STRAFE_LEFT;
	keyMap[7].KeyCode = KEY_KEY_Q;
	keyMap[8].Action = EKA_STRAFE_RIGHT;
	keyMap[8].KeyCode = KEY_KEY_D;

	//camera = smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, -1, keyMap, keyMapSize, noVerticalMovement, jumpSpeed);
	camera = smgr->addCameraSceneNodeFPS(0, 100.0f, 1.f, -1, keyMap, keyMapSize, noVerticalMovement, jumpSpeed);
	camera->setPosition(spawn);
	camera->setTarget(target);
	camera->setFarValue(farValue);

	ISceneNodeAnimatorCameraFPS *anim = (ISceneNodeAnimatorCameraFPS*) smgr->createCollisionResponseAnimator(selectorGlobal, camera, vector3df(20,60,20), vector3df(0, -10, 0), vector3df(0,30,0));
	camera->addAnimator(anim);
	anim->drop();

	pw = new PlayerWeapon(smgr, driver, soundEngine, textAmmo);
}

Player::~Player(){
    delete pw;
}

float Player::getCameraX(){
    return camera->getPosition().X;
}

float Player::getCameraY(){
    return camera->getPosition().Y;
}

float Player::getCameraZ(){
    return camera->getPosition().Z;
}

PlayerWeapon *Player::getPlayerWeapon(){
    return pw;
}

void Player::receiveDamage(int damage){
    health -= damage;
    stringw strHealth = L"Health : ";
    strHealth += health;
    text->setText(strHealth.c_str());

    if (health <= 0){
        text->setOverrideColor(SColor(255, 255, 0, 0));
        alive = false;
    }
}

ICameraSceneNode *Player::getCamera(){
    return camera;
}
