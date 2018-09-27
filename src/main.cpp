#include "MainMenu.h"
#include "Game.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;

int main(){
	MainMenu menu;
	int action = menu.run();

	if(action == 1){
        Game g = Game(menu.getScreenW(), menu.getScreenH(), menu.getFullScreen());
	}

    return 0;
}
