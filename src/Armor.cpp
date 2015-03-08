//
//  Armor.cpp
//  gauntmore_macosx
//
//  Created by Steven Warren on 2/26/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "Armor.h"
#include "res.h"
#include "Game.h"
#include "Player.h"

/**
 *  Constructor.
 */
Armor::Armor(int armorType):_value(armorType) {
    _armorType = armorType;
    setType("armor");
}

/**
 *  Gets bounds of the unit Gold.
 *  @return: SDL_Rect _bounds which is the bounds of Gold.
 */
SDL_Rect Armor::getBounds() {
    Vector2 unitPosition = getPosition();
    _bounds.x = unitPosition.x + 20;
    _bounds.y = unitPosition.y + 15;
    _bounds.h = 30;
    _bounds.w = 20;

    return _bounds;
}

/**
 * Adds sprite and attachs it to the game.
 */
void Armor::addSprite() {
    _sprite = new Sprite;
    
    switch (_armorType) {
        case 2:
            _sprite->setResAnim(resources.getResAnim("armor2"));
            break;
        case 3:
            _sprite->setResAnim(resources.getResAnim("armor3"));
            break;
        default:
            break;
    }
    
    
    _sprite->attachTo(_view);
    _sprite->setAnchor(Vector2(0.5f, 0.5f));
}

/**
 * Initializes a Gold position and sprite. Called by Unit's init() method.
 */
void Armor::_init() {
    addSprite();
}

/**
 *  Adds gold value to the player's current total.
 *  Removes sprite from the game.
 */
void Armor::_interact() {
    if (!isDead()) {
        _game->getPlayer()->setDefense(_value);
        _game->updateArmorCount(_value);
        
        // Removes Sprite from game
        _view->addTween(Actor::TweenAlpha(0), 1500)->setDetachActor(true);
        _dead = true;
    }
}

/**
 * Updates Armor every frame. Called by Units update() method.
 *
 * @us is the UpdateStatus sent by Unit's update method.
 */
void Armor::_update(const UpdateState &us) {

}
