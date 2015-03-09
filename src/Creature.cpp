#include <cmath>
#include <iostream>
#include "Creature.h"
#include "Potion.h"
#include "Gold.h"
#include "res.h"
#include <cmath>


/**
 * Constructor
 */
Creature::Creature() {
    setType("creature");
}


/**
 * Returns the direction the creature should face
 * based off a direction
 *
 * @direction a pair of ints (-1, 0, 1) that we use to detemine direction
 *
 * @return a Facing enum
 */
Creature::Facing Creature::getFacing(Vector2 direction){
    if((direction.x == 1 && direction.y == 0)){
        // if direction is moving east or northeast or southeast
        return right;
    }else if ((direction.x == 0 && direction.y == 1)
              || (direction.x == -1 && direction.y == 1)
              || (direction.x == 1 && direction.y == 1)){
        // if direction is moving north
        return up;
    }else if((direction.x == 0 && direction.y == -1)
             || (direction.x == -1 && direction.y == -1)
             || (direction.x == 1 && direction.y == -1)){
        // if moving south
        return down;
    } else{
        // if moving west or north west or south west
        return left;
    }
}


/**
 * Used to damage the player
 */
void Creature::damage() {
    _game->getPlayer()->updateHealth(-_attack);
}


/**
 * Figures out which direction the creature should move
 *
 * @returns a vector2 of ints (-1, 0, 1) which is used to set facing
 */
Vector2 Creature::moveMe() {
    Vector2 moveDir = {0,0};
    
    //player's position
    Vector2 pPos = _game->getPlayer()->getPosition();
    
    //creature's position
    Vector2 cPos = getPosition();
    
    //you are less than 64 pixels away, do nothing
    if ( abs(pPos.x - cPos.x) <= 50 && abs(pPos.y - cPos.y) <= 50 ) {
        return moveDir;
    }
    
    //otherwise, check the movement Queue
    if ( moveQ.isEmpty() ) {
        moveQ.updatePath(findPath.aStar(cPos, pPos) );
    }
    
    //if the Q is NOT empty
    Vector2 nextSpot = moveQ.peekNext();//look at where you are going
    if ( abs(cPos.x - nextSpot.x) <= 10 && abs(cPos.y - nextSpot.y) <= 10) {
        moveQ.updatePath(findPath.aStar(pPos, cPos) );
    }
    nextSpot = moveQ.peekNext();//start moving to the next spot
    
    if ( (cPos.x - nextSpot.x) < -4 ) moveDir.x = 1;
    if ( (cPos.x - nextSpot.x) > 4 ) moveDir.x = -1;
    if ( (cPos.y - nextSpot.y) < -4 ) moveDir.y = 1;
    if ( (cPos.y - nextSpot.y) > 4 ) moveDir.y = -1;
    
    return moveDir;
}


/**
 * Gives the creature gold or a potion
 */
void Creature::_setContents() {
    int randNum = rand() % 2;
    
    if (randNum == 0) {
        int randContents = rand() % 2;
        if (randContents == 0) {
            _contents = new Potion();
        } else {
            _contents = new Gold();
        }
    }
}


/**
 * Puts the creatures contents on the ground when it dies
 */
void Creature::_dropContents() {
    if (_contents) {
        _contents->init(getPosition(), _game);
        _contents->setLocation(getPosition());
        _game->getMap()->getRoom()->getUnits()->push_back(_contents);
    }
}


/**
 * Reduces the creature's hit points.
 */
void Creature::_interact() {
    int damage = _game->getPlayer()->getAttack();
    _hp -= damage;
    if (_hp == 0) {
        // The creature is dead, hide it with an alpha tween.
        _dead = true;
        _view->addTween(Actor::TweenAlpha(0), 300)->setDetachActor(true);
        _dropContents();
    }
}