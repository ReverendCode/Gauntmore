#ifndef __gauntmore__Gold__
#define __gauntmore__Gold__

#include "Thing.h"

DECLARE_SMART(Gold, spGold);
class Gold: public Thing {
    
public:
    Gold();
    
    /**
     *  Gets bounds of the unit Gold.
     *  @return: SDL_Rect which is the bounds of Gold.
     */
    SDL_Rect getBounds();
    
    /**
     * Adds sprite and attachs it to the game.
     */
    virtual void addSprite();
    
    /**
     *  Method to determine whether unit is a Potion.
     *  @return: false since the current unit is a Gold.
     */
    virtual bool isPotion();
    
private:
    int _value;
    
    /**
     * Initializes a Gold position and sprite. Called by Unit's init() method.
     */
    void _init();
    
    /**
     *  Adds gold value to the player's current total.
     *  Removes sprite from the game.
     */
    void _interact();
        
    /**
     * Updates the Gold every frame. Called by Units update() method.
     *
     * @us is the UpdateStatus sent by Unit's update method.
     */
    void _update(const UpdateState &us);
};

#endif /* defined(__gauntmore__Gold__) */
