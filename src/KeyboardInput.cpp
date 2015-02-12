#include <iostream>

#include "KeyboardInput.h"
#include "Input.h"
#include "SDL.h"
#include "SDL_keyboard.h"
#include "SDL_events.h"
#include "Player.h"


/**
 * Constructor.
 */
KeyboardInput::KeyboardInput():_pressed(false), _dir(0,0) {
    Input::instance.addEventListener(Input::event_platform, CLOSURE(this, &KeyboardInput::_onEvent));
}


/**
 * Gets and sets the direction Vector2 on keyboard input. Used by Player to move the sprite..
 *
 * @dir is the direction vector.
 * @return true on a button press and false when it is lifted up.
 */
bool KeyboardInput::getDirection(Vector2 &dir) const {
    dir = _dir;
    return _pressed;
    
}


void KeyboardInput::_onEvent(Event *ev) {
    SDL_Event *event = (SDL_Event*) ev->userData;
    _pressed = true;
    //if key is pressed:
    if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
        //adjust velocity
        switch (event->key.keysym.sym ) {
            case SDLK_UP:
            case SDLK_w:{
                _dir += Vector2(0, -1);
                break;
            }
            case SDLK_DOWN:
            case SDLK_s: { //for anim testing
                _dir += Vector2(0, 1);
                
                break;
            }
            case SDLK_LEFT:
            case SDLK_a: _dir += Vector2(-1, 0); break;
            case SDLK_RIGHT:
            case SDLK_d: _dir += Vector2(1, 0); break;
 
        }
    }
        if (event->type == SDL_KEYUP && event->key.repeat == 0) {
            //_pressed = false;
            switch (event->key.keysym.sym ) {
                case SDLK_UP:
                case SDLK_w: _dir -= Vector2(0, -1); break;
                case SDLK_DOWN:
                case SDLK_s: _dir -= Vector2(0, 1); break;
                case SDLK_LEFT:
                case SDLK_a: _dir -= Vector2(-1, 0); break;
                case SDLK_RIGHT:
                case SDLK_d: _dir -= Vector2(1, 0); break;
        }
    }
    
 
}