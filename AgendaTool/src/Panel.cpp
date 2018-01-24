//
//  Panel.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "Panel.hpp"

// ---------------------------------------------- public
Panel::Panel () {
    
}

Panel * Panel::setup () {
    Panel * pPanel = new Panel ();
    pPanel->rect = ofRectangle(0,0,100,100);
    pPanel->color = DEFAULT_COLOR;
    pPanel->setNeedsRedraw();
    return pPanel;
}

Panel * Panel::setup (ofRectangle rect) {
    Panel * pPanel = new Panel ();
    pPanel->rect = rect;
    pPanel->color = DEFAULT_COLOR;
    pPanel->setNeedsRedraw();
    return pPanel;
}

Panel * Panel::setup (ofRectangle rect, ofColor color) {
    Panel * pPanel = new Panel ();
    pPanel->rect = rect;
    pPanel->color = color;
    pPanel->setNeedsRedraw();
    return pPanel;
}

// ---------------------------------------------- protected
void Panel::render () {
    bg.draw();
}

void Panel::redraw () {
    bg.clear();
    bg.setFillColor(color);
    bg.setFilled(true);
    bg.rectangle(rect);
}

// ---------------------------------------------- private
