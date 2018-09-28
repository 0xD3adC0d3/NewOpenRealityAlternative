#ifndef GRAPHICSUTILS_H
#define GRAPHICSUTILS_H

#include <irrlicht.h>

class GraphicsUtils{
    public:
        GraphicsUtils();

		int getScreenW();
		int getScreenH();

		void setParams(irr::IrrlichtDevice *deviceP, int w, int h);
		irr::IrrlichtDevice                *getDevice();

		void crosshair();
        void snapshot();

    private:
		int screenW;
		int screenH;
		irr::video::IVideoDriver *driver;
		irr::IrrlichtDevice      *device;
};

#endif // GRAPHICSUTILS_H
