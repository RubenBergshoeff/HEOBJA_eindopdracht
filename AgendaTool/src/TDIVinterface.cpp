//
//  TDIVinterface.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/10/18.
//

#include "TDIVinterface.hpp"

void TDIVinterface::draw () {
    if (needsRedraw) {
        redrawInternal ();
    }
    render();
}

void TDIVinterface::redraw (ofRectangle drawPos, bool nested) {
    rect = drawPos;
    this->nested = nested;
    redrawInternal();
    controller.setClean();
}

void TDIVinterface::setController (ToDoItemController controller) {
    this->controller = controller;
}

ToDoItemController * TDIVinterface::getController () {
    return &controller;
}

bool TDIVinterface::isActive() {
    if (this->controller.isConnected()) {
        return true;
    } else {
        return false;
    }
}

TDIVinterface::~TDIVinterface() {
    
}
