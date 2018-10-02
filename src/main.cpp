#include "MainMenu.h"
#include "Game.h"

int main(){
    MainMenu menu;

    if(menu.run() == 1){
        Game g;
        g.start(menu.getScreenW(), menu.getScreenH(), menu.getFullScreen());
    }

    return 0;
}
