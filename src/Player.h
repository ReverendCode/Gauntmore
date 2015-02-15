#pragma once
#include "Unit.h"

DECLARE_SMART(Player, spPlayer);
class Player: public Unit {
    
public:
	Player();
    
    enum Facings {up, right, down, left};
    Facings facing;
    
    /**
     * Reduces the player's hit points.
     */
    void damage();
    
    
    void interact();
    
    /**
     * Add sprite to the game scene.
     */
    void addSprite();
    
    void removeSprite();
    
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void removeTween();
    
protected:
    spTween _moveTween;
    bool _hasTween;
    
    void _checkTween();
    
    Vector2 correctDirection(Vector2 position, Vector2 direction);
    
    /**
     * Initializes the player's position and sprite. Called by Unit's init() method.
     */
	void _init();
    
    void setFacing(Vector2 dir);
    
    /**
     * Updates the player every frame.
     *
     * @us is the UpdateStatus sent by the global update method.
     */
	void _update(const UpdateState &us);
};
