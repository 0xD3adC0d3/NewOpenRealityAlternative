#ifndef __C_MAIN_MENU_H_INCLUDED__
#define __C_MAIN_MENU_H_INCLUDED__
#include <irrlicht.h>

class MainMenu : public irr::IEventReceiver{
    public:
        MainMenu();
        int run();
        int getScreenH();
        int getScreenW();
        bool getFullScreen();
        virtual bool OnEvent(const irr::SEvent& event);

    private:
        irr::IrrlichtDevice    *MenuDevice;
        irr::gui::IGUIButton   *spButton;
        irr::gui::IGUIButton   *quitButton;
        irr::gui::IGUIComboBox *resolutionBox;
        irr::gui::IGUICheckBox *fScreenBox;
        int start;

        void onResolutionChanged(irr::gui::IGUIComboBox* combo);
        void onFullScreenChanged(irr::gui::IGUICheckBox *box);
        int screenH;
        int screenW;
        bool fullScreen;
};
#endif
