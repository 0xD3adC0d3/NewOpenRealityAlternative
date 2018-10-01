#include "MainMenu.h"

#include <iostream>
using namespace std;

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;
using namespace scene;

MainMenu::MainMenu() : spButton(0), quitButton(0), menuDevice(0), start(0){
    screenW = 800;
    screenH = 600;
    fullScreen = false;
}

int MainMenu::run(){
    menuDevice = createDevice(EDT_OPENGL, dimension2d<u32>(512, 384), 16, false, false, false, this);
	IVideoDriver    *driver = menuDevice->getVideoDriver();
	ISceneManager   *smgr   = menuDevice->getSceneManager();
	IGUIEnvironment *guienv = menuDevice->getGUIEnvironment();

	stringw str = "N.O.R.A.";
	menuDevice->setWindowCaption(str.c_str());

	IGUIFont* font = guienv->getFont("media/fonts/fonthaettenschweiler.bmp");
	guienv->getSkin()->setFont(font);

	IGUITabControl *tabctrl = guienv->addTabControl(rect<int>(260, 10, 502, 374), 0, true, true);
	IGUITab *gameTab  = tabctrl->addTab(L"Game");
	IGUITab *optionsTab = tabctrl->addTab(L"Options");
	IGUITab *aboutTab = tabctrl->addTab(L"About");

	spButton      = guienv->addButton  (rect<int>(30, 20,  200, 50),        gameTab,    0, L"Single player");
	quitButton    = guienv->addButton  (rect<int>(30, 270, 200, 300),       gameTab,    1, L"Exit");
	resolutionBox = guienv->addComboBox(rect<int>(30, 20, 200, 50),         optionsTab, 2);
	fScreenBox    = guienv->addCheckBox(fullScreen, rect<int>(30, 60,  200, 90), optionsTab, 3, L"Full screen");

	resolutionBox->addItem(L"800*600");
	resolutionBox->addItem(L"1024*768");
	resolutionBox->addItem(L"1280*600");
	resolutionBox->addItem(L"1280*720");
	resolutionBox->addItem(L"1280*768");
	resolutionBox->addItem(L"1360*768");
	resolutionBox->addItem(L"1366*768");

	const wchar_t* text = L"N.O.R.A.\n"\
                          L"New Open Reality Alternative\n"\
                          L"\nA 3D game engine powered by IrrLicht and IrrKlang.";

	guienv->addStaticText(text, rect<int>(10, 10, 230, 320), true, true, aboutTab);

	IAnimatedMesh* mesh = smgr->getMesh("media/characters/sydney.md2");
	IAnimatedMeshSceneNode* modelNode = smgr->addAnimatedMeshSceneNode(mesh);
	if (modelNode){
		modelNode->setPosition(vector3df(0.f, -4.f, -10.f));
		modelNode->setMaterialTexture(0, driver->getTexture("media/characters/sydney.bmp"));
		modelNode->setMaterialFlag(EMF_LIGHTING, false);
		modelNode->getMaterial(0).Shininess = 50.f;
		modelNode->getMaterial(0).NormalizeNormals = true;
		modelNode->setMD2Animation(EMAT_STAND);
	}

	smgr->addCameraSceneNode(0, vector3df(45,0,0), vector3df(0,0,10));

	bool oldMipMapState = driver->getTextureCreationFlag(ETCF_CREATE_MIP_MAPS);
	driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
	ITexture* irrlichtBack = driver->getTexture("media/menu/demoback.jpg");
	driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, oldMipMapState);

	while(menuDevice->run()){
		if (menuDevice->isWindowActive()){
			driver->beginScene(false, true, SColor(0,0,0,0));
			if (irrlichtBack)
				driver->draw2DImage(irrlichtBack, position2d<int>(0,0));

			smgr->drawAll();
			guienv->drawAll();
			driver->endScene();
		}
	}
	menuDevice->drop();
	return start;
}
int MainMenu::getScreenH(){
 return screenH;
}

int MainMenu::getScreenW(){
    return screenW;
}

bool MainMenu::getFullScreen(){
    return fullScreen;
}

bool MainMenu::OnEvent(const SEvent& event){
	if (event.EventType == EET_GUI_EVENT){
		s32 id = event.GUIEvent.Caller->getID();
		switch(id){
		    case 0:
                if (event.GUIEvent.EventType == EGET_BUTTON_CLICKED){
                    menuDevice->closeDevice();
                    start = 1;
                }
                break;
            case 1:
                if (event.GUIEvent.EventType == EGET_BUTTON_CLICKED){
                    menuDevice->closeDevice();
                    start = 0;
                }
                break;
            case 2:
                if(event.GUIEvent.EventType == EGET_COMBO_BOX_CHANGED){
                    onResolutionChanged((IGUIComboBox*)event.GUIEvent.Caller);
                }
                break;
            case 3:
                if(event.GUIEvent.EventType == EGET_CHECKBOX_CHANGED){
                    if(fullScreen == false){
                        fullScreen = true;
                    } else{
                        fullScreen = false;
                    }
                }
                break;
		}
	}
	return false;
}

void MainMenu::onResolutionChanged(IGUIComboBox* combo){
    s32 pos = combo->getSelected();
    switch (pos){
        case 0:
            screenW = 800;
            screenH = 600;
            break;
        case 1:
            screenW = 1024;
            screenH = 768;
            break;
        case 2:
            screenW = 1280;
            screenH = 600;
            break;
        case 3:
            screenW = 1280;
            screenH = 720;
            break;
        case 4:
            screenW = 1280;
            screenH = 768;
            break;
        case 5:
            screenW = 1360;
            screenH = 768;
            break;
        case 6:
            screenW = 1366;
            screenH = 768;
            break;
    }
}
