//
//  ButtonBar.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/24/18.
//

#include "ButtonBar.hpp"


ButtonBar * ButtonBar::setup(GUIBase * base, MenuBar * obj, void (MenuBar::*a)()) {
    ButtonBar * pButton = new ButtonBar ();
    pButton->base = base;
    pButton->rect = base->getRect();
    pButton->obj = obj;
    pButton->func = a;
    return pButton;
}

bool ButtonBar::mouseReleased(ofMouseEventArgs &args) {
    if (rect.inside(args.x, args.y)) {
        (obj->*func)();
        //        ofLog(OF_LOG_NOTICE, "click-release registered");
        return true;
    } else {
        return false;
    }
}

ButtonBar::ButtonBar() {
    base = nullptr;
    registerMouseEvents();
}

ButtonBar::~ButtonBar() {
    if (base != nullptr) {
        delete base;
    }
    Interactable::~Interactable();
}

void ButtonBar::render() {
    if (base != nullptr) {
        base->draw();
    }
}

void ButtonBar::redraw () {
    
}
