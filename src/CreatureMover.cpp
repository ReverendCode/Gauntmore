//
//  CreatureMover.cpp
//  gauntmore_macosx
//
//  Created by David Wenzel on 2/24/15.
//  Copyright (c) 2015 oxygine. All rights reserved.
//

#include "CreatureMover.h"


CreatureMover::CreatureMover() {

}

CreatureMover::~CreatureMover() {
}

bool CreatureMover::isEmpty() {
    return thePath.empty();
}

bool CreatureMover::updatePath(vector<Vector2> newPath) {
    for (int i = 0; i < newPath.size();i++) {
        thePath.push_back(newPath.back());
        newPath.pop_back();
    }
    
    return true;
}

Vector2 CreatureMover::peekNext() {
//    if ( thePath.size() == 0) return {0,0};
    return thePath.back();
}

Vector2 CreatureMover::popNext() {
    Vector2 temp = thePath.back();
    thePath.pop_back();
    return temp;

}


