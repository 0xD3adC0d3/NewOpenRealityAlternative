#include "GraphicsUtils.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;
using namespace core;
using namespace gui;

GraphicsUtils::GraphicsUtils(){
    screenW = 1366;
	screenH = 768;
	driver = 0;
	device = 0;
}

int GraphicsUtils::getScreenH(){
    return screenH;
}

int GraphicsUtils::getScreenW(){
    return screenW;
}

void GraphicsUtils::setParams(IrrlichtDevice *deviceP){
    device = deviceP;
    driver = device->getVideoDriver();
}

void GraphicsUtils::crosshair(){
	int cenW = screenW / 2;
	int cenH = screenH / 2;

	driver->draw2DRectangle(SColor(255,255,255,255), rect<s32>(cenW, cenH-8, cenW+2, cenH-3)); //above
	driver->draw2DRectangle(SColor(255,255,255,255), rect<s32>(cenW+5, cenH, cenW+10, cenH+2)); //right
	driver->draw2DRectangle(SColor(255,255,255,255), rect<s32>(cenW, cenH+5, cenW+2, cenH+10)); //down
	driver->draw2DRectangle(SColor(255,255,255,255), rect<s32>(cenW-8, cenH, cenW-3, cenH+2)); //left
	driver->draw2DRectangle(SColor(255,255,255,255), rect<s32>(cenW, cenH, cenW+2, cenH+2)); //center of screen
}

void GraphicsUtils::snapshot(){
    IImage *image = driver->createScreenShot();
    if(image){
        driver->writeImageToFile(image, "screenshot.jpg");
    }
    image->drop();
}

IrrlichtDevice *GraphicsUtils::getDevice(){
    return device;
}
