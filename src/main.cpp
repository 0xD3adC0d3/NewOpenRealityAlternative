#include "MainMenu.h"
#include "Game.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;

int main(){
    MainMenu menu;

    if(menu.run() == 1){
        Game g;
        g.start(menu.getScreenW(), menu.getScreenH(), menu.getFullScreen());
    }

    return 0;
}
