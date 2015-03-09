#pragma once

#include "Unit.h"
#include "PathFinder.h"
#include "Game.h"
#include "Player.h"
#include "Thing.h"
#include "CreatureMover.h"


DECLARE_SMART(Creature, spCreature);
class Creature : public Unit {
    
public:
    Creature();
    
    enum Facing {up, right, down, left};
    
    /**
     * Returns the direction the creature should face
     * based off a direction
     * 
     * @direction a pair of ints (-1, 0, 1) that we use to detemine direction
     * 
     * @return a Facing enum
     */
    Facing getFacing(Vector2 direction);
    
    /**
     * Used to damage the player
     */
    virtual void damage();
    
protected:
    time_t _lastTimeAttack;
    spThing _contents;
    PathFinder findPath;
    CreatureMover moveQ;
    
    /**
     * Figures out which direction the creature should move
     *
     * @returns a vector2 of ints (-1, 0, 1) which is used to set facing
     */
    Vector2 moveMe();
    
    /**
     * Gives the creature gold or a potion
     */
    void _setContents();
    
    /**
     * Puts the creatures contents on the ground when it dies
     */
    void _dropContents();
    
    /**
     * Initializes a creatures position and sprite. Called by Unit's init() method.
     */
    virtual void _init() = 0;
    
    /**
     * Reduces the creature's hit points.
     */
    virtual void _interact();
    
    /**
     * Updates the creature every frame. Called by Units update() method.
     *
     * @us is the UpdateStatus sent by Unit's update method.
     */
    virtual void _update(const UpdateState &us) = 0;
};