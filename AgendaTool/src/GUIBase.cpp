//
//  GUIBase.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "GUIBase.hpp"

// ---------------------------------------------- public
void GUIBase::draw (){
    if (needsRedraw) {
        redraw();
        needsRedraw = false;
    }
    render();
}

void GUIBase::setRect (ofRectangle rect){
    this->rect = rect;
    needsRedraw = true;
}

void GUIBase::setColor (ofColor color) {
    this->color = color;
    needsRedraw = true;
}

ofRectangle GUIBase::getRect (){
    return rect;
}

ofColor GUIBase::getColor (){
    return color;
}


GUIBase::~GUIBase() {
    
}

// ---------------------------------------------- protected
ofColor
const GUIBase::DEFAULT_COLOR (200);

void GUIBase::setNeedsRedraw (){
    needsRedraw = true;
}

// ---------------------------------------------- private

