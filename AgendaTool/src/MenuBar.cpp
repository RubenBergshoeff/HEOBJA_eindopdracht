//
//  MenuBar.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/24/18.
//

#include "MenuBar.hpp"

MenuBar::MenuBar (AgendaController * ac, ofRectangle rect){
    this->ac = ac;
    this->rect = rect;
    addButton = nullptr;
    background = nullptr;
    redraw ();
}

void MenuBar::draw () {
    background->draw();
    addButton->draw();
}

void MenuBar::redraw () {
    if (addButton != nullptr) {
        delete addButton;
    }
    if (background != nullptr) {
        delete background;
    }
    background = Panel::setup(rect, ofColor(255));
    ofRectangle buttonRect = ofRectangle (rect.x + rect.width / 5, rect.y + rect.height / 3, rect.height / 3, rect.height / 3);
    addButton = ButtonBar::setup(TextBlock::setup(Panel::setup(buttonRect, ofColor(150,150,150)), TDIVPC::h1(), "Add", 5, ofColor(255,255,255)), this, &MenuBar::addModel);
}

void MenuBar::addModel (){
    ac->addModel(new ToDoItemModel(ToDoItemModel::provideID(), "Another Model"));
}
