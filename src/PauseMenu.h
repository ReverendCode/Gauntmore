#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "Game.h"

using namespace oxygine;


DECLARE_SMART(PauseMenu, spPauseMenu);
class Game;
class PauseMenu : public Scene {

public:
    static spPauseMenu instance;
    enum Selection {selectContinue, selectQuit};
    
    PauseMenu();
    
    void setContinue(string continueImage) {
        _continue->setResAnim(resources.getResAnim(continueImage));
    }
    
    void setQuit(string quitImage) {
        _quit->setResAnim(resources.getResAnim(quitImage));
    }
    
private:
    Selection _selection;
    spSprite _name;
    spSprite _continue;
    spSprite _newGame;
    spSprite _quit;
    
    bool _isReady;
    void _onEvent(Event *ev);
    void selectNext();
    
};
