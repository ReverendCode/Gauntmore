#include <iostream>
#include "oxygine-framework.h"
#include "Game.h"

using namespace oxygine;

DECLARE_SMART(CollisionDetector, spCollisionDetector)

#ifndef __gauntmore__CollisionDetector__
#define __gauntmore__CollisionDetector__

class CollisionDetector : public Object {
    
public:
    CollisionDetector(Game *game);
    
    bool detectWalls(std::vector<SDL_Rect> tiles, SDL_Rect spriteRect);
    bool detectUnits(std::list<spUnit> units, SDL_Rect spriteRect);
    
private:
    Game *_game;
};

#endif