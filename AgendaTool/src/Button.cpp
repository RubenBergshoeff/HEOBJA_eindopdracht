//
//  Button.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#include "Button.hpp"

Button * Button::setup(GUIBase * base, TDIVPC * obj, void (TDIVPC::*a)(), void (TDIVPC::*b)()) {
    Button * pButton = new Button ();
    pButton->base = base;
    pButton->rect = base->getRect();
    pButton->obj = obj;
    pButton->funcReleased = a;
    pButton->funcPressed = b;
    return pButton;
}

bool Button::mousePressed(ofMouseEventArgs &args) {
    if (rect.inside(args.x, args.y)) {
        (obj->*funcPressed)();
        //        ofLog(OF_LOG_NOTICE, "click-release registered");
        return true;
    } else {
        return false;
    }
}

bool Button::mouseReleased(ofMouseEventArgs &args) {
    if (rect.inside(args.x, args.y)) {
        (obj->*funcReleased)();
//        ofLog(OF_LOG_NOTICE, "click-release registered"); 
        return true;
    } else {
        return false;
    }
}

void Button::setRect (ofRectangle rect){
    GUIBase::setRect(rect);
    if (base != nullptr) {
        base->setRect(rect);
    }
}

Button::Button() {
    base = nullptr;
    registerMouseEvents();
}

Button::~Button() {
    if (base != nullptr) {
        delete base;
    }
    Interactable::~Interactable();
}

void Button::render() {
    if (base != nullptr) {
        base->draw();
    }
}

void Button::redraw () {
    
}
