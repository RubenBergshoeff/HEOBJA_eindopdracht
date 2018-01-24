//
//  ToDoItemView.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "ToDoItemView.hpp"

// ---------------------------------------------- public

void ToDoItemView::draw() {
    ofSetColor(0,0,0);
    ofDrawRectangle(0,0,100,100);
}

float ToDoItemView::draw(ofRectangle rect) {
    if (controller->isDirty()) {
        updateGUI(rect);
    }
    
    backgroundGUI->draw();
    nameGUI->draw();
    if (descriptionGUI != nullptr) {
        descriptionGUI->draw();
    }
    if (dateGUI != nullptr) {
        dateGUI->draw();
    }
    if (projectGUI != nullptr) {
        projectGUI->draw();
    }
    if (locationGUI != nullptr) {
        locationGUI->draw();
    }
    
    // TODO :: notedraw
    //    for (auto it = note.begin(); it != guiElements.end(); ++it) {
    //        (*it)->draw();
    //    }
    
    subViewsRect.height = 0;
    for (auto it = subViews.begin(); it != subViews.end(); ++it) {
        (*it)->draw(ofRectangle());
    }
    
    return drawingHeight;
}

float ToDoItemView::getDrawingHeight() {
    return drawingHeight;
}


// ---------------------------------------------- protected

void ToDoItemView::updateGUI (ofRectangle rect) {
    updateGUI (rect, false);
}

void ToDoItemView::updateGUI (ofRectangle rect, bool nested) {
    // --------------------------------- name
    ofRectangle tempRect = ofRectangle(rect.x, rect.y, rect.width, ToDoItemView::HEIGHTROW * 1.5);
    if (nameGUI == nullptr) {
        nameGUI = TextBlock::setup(Panel::setup (tempRect, ofColor(189,209,255)), h1(), controller->getName(), 9, ofColor(0,0,0));
    } else {
        nameGUI->setRect(tempRect);
    }
    // add height to y
    tempRect.y += tempRect.height;
    if (!nested) {
        // --------------------------------- date
        // set new height
        tempRect.height = ToDoItemView::HEIGHTROW * .7;
        if (dateGUI == nullptr) {
            dateGUI = TextBlock::setup(Panel::setup (tempRect, ofColor(169,160,232, 15)), p(), controller->getDate().dateAsString(), 3, ofColor(0,0,0));
        } else {
            dateGUI->setRect(tempRect);
        }
        // add height to y
        tempRect.y += tempRect.height;
        // --------------------------------- description
        // set new height
        tempRect.height = ToDoItemView::HEIGHTROW * 3;
        if (descriptionGUI == nullptr) {
            descriptionGUI = TextBlock::setup(Panel::setup (tempRect, ofColor(150,181,192)), p(), controller->getDescription(), ofColor(0,0,0));
        } else {
            descriptionGUI->setRect(tempRect);
        }
        // add height to y
        tempRect.y += tempRect.height;
        // --------------------------------- project
        if (controller->getProject() != nullptr) {
            // set new height
            tempRect.height = ToDoItemView::HEIGHTROW;
            if (projectGUI == nullptr) {
                projectGUI = Panel::setup (tempRect);
            } else {
                projectGUI->setRect(tempRect);
            }
            // add height to y
            tempRect.y += tempRect.height;
        }
        // --------------------------------- location
        if (controller->getLocation() != nullptr) {
            // set new height
            tempRect.height = ToDoItemView::HEIGHTROW;
            if (locationGUI == nullptr) {
                locationGUI = Panel::setup (tempRect);
            } else {
                locationGUI->setRect(tempRect);
            }
            // add height to y
            tempRect.y += tempRect.height;
        }
        // --------------------------------- notes
        // TODO :: implement notes
    }
    
    subViewsRect = ofRectangle (tempRect.x + ToDoItemView::HEIGHTROW * 1.5, tempRect.y, tempRect.width - ToDoItemView::HEIGHTROW * 1.5, 0);
    
    if (!subViews.empty()) {
        subViewsRect.y +=  ToDoItemView::HEIGHTROW * .75;
        for (auto it = subViews.begin(); it != subViews.end(); ++it) {
            (*it)->updateGUI(ofRectangle(subViewsRect), true);
            subViewsRect.y += (*it)->getDrawingHeight();
            if (it+1 != subViews.end()) {
                subViewsRect.y +=  + ToDoItemView::HEIGHTROW;
            }
        }
    }
    
    tempRect.width = rect.width;
    tempRect.height = tempRect.y + (subViewsRect.y - tempRect.y) - rect.y;
    tempRect.x = rect.x;
    tempRect.y = rect.y;
    if (backgroundGUI == nullptr) {
        backgroundGUI = Panel::setup (tempRect, ofColor(169,160,232, 30));
    } else {
        backgroundGUI->setRect(tempRect);
    }
    
    drawingHeight = tempRect.height;
    controller->setClean();
}

ToDoItemController * ToDoItemView::getController () const {
    return controller;
}

ToDoItemView::ToDoItemView (ToDoItemController * controller){
    this->controller = controller;
    backgroundGUI = nullptr;
    nameGUI = nullptr;
    descriptionGUI = nullptr;
    dateGUI = nullptr;
    projectGUI = nullptr;
    locationGUI = nullptr;
}


// ---------------------------------------------- private

ofTrueTypeFont ToDoItemView::font_h1;
ofTrueTypeFont ToDoItemView::font_p;

ofTrueTypeFont * ToDoItemView::h1 () {
    if (!font_h1.isLoaded()) {
        font_h1.load("Arial Bold.ttf", 13);
    }
    return &font_h1;
}

ofTrueTypeFont * ToDoItemView::p () {
    if (!font_p.isLoaded()) {
        font_p.load("Arial.ttf", 9);
    }
    return &font_p;
}
