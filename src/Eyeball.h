#pragma once

#include "Creature.h"
#include "Thing.h"

using namespace std;

DECLARE_SMART(Eyeball, spEyeball);
class Eyeball : public Creature {
    
public:
    Eyeball();
    
    /* Virtual Methods */
    
    /**
     * Returns the bounds of the Creature
     *
     * @return SDL_Rect that is the bounds for Creature
     */
    virtual SDL_Rect getBounds();
    
    /**
     * Puts a Worm sprite in the game
     */
    virtual void addSprite();
    
    
    /**
     * Plays the move animation.
     */
    void move();
    
private:
    Facing _facing;
    spThing _contents;
    int _speed = 100;
    spTween _moveTween;
    
    /**
     * Initializes position and sprite of Chest. Called by Unit's init() method.
     */
    void _init();
    
    /**
     * Updates the Chest every frame. Called by Units update() method.
     *
     * @us is the UpdateStatus sent by Unit's update method.
     */
    void _update(const UpdateState &us);
};