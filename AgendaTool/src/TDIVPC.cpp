//
//  TDIVPC.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#include "TDIVPC.hpp"

ofVec2f TDIVPC::getDimensions (ToDoItemModel * model, ofRectangle drawPos){
    return getDimensions(model, drawPos, false);
}

ofVec2f TDIVPC::getDimensions (ToDoItemModel * model, ofRectangle drawPos, bool nested){
    ofVec2f size = ofVec2f(0,0);
    
    // name
    size.y += HEIGHTROW * 1.5f;
    
    if (!nested) {
        // date
        size.y += HEIGHTROW * .7f;
        
        // description -> later we'll add height calc, for now we'll cut overflow
        size.y += HEIGHTROW * 3;
        
        // project
        // lets put that one next to the name
        
        // location
        if (model->location != nullptr) {
            size.y += HEIGHTROW;
        }
    }
    
    ofRectangle subViewsRect = ofRectangle (drawPos.x + HEIGHTROW * 1.5f, drawPos.y + size.y, drawPos.width - HEIGHTROW * 1.5f, 0);
        
    // subModels
    if (!model->subModels.empty()) {
        for (auto it = model->subModels.begin(); it != model->subModels.end(); ++it) {
            ofVec2f submodelSize = getDimensions(*it, subViewsRect, true);
            size.y += submodelSize.y;
            subViewsRect.y += submodelSize.y;
            if (it + 1 != model->subModels.end()) {
                size.y += HEIGHTROW;
            }
        }
    }
    
    size.x = drawPos.width;
    
    return size;
}

TDIVPC::TDIVPC () {
    backgroundGUI = nullptr;
    nameGUI = nullptr;
    descriptionGUI = nullptr;
    dateGUI = nullptr;
    projectGUI = nullptr;
    locationGUI = nullptr;
}

TDIVPC::~TDIVPC() {
    if (backgroundGUI != nullptr) {
        delete backgroundGUI;
    }
    if (nameGUI != nullptr) {
        delete nameGUI;
    }
    if (descriptionGUI != nullptr) {
        delete descriptionGUI;
    }
    if (dateGUI != nullptr) {
        delete dateGUI;
    }
    if (projectGUI != nullptr) {
        delete projectGUI;
    }
    if (locationGUI != nullptr) {
        delete locationGUI;
    }
}


// ---------------------------------------------- protected

void TDIVPC::redrawInternal() {
    // --------------------------------- name
    ofRectangle tempRect = ofRectangle(rect.x, rect.y, rect.width, HEIGHTROW * 1.5);
    if (nameGUI == nullptr) {
        nameGUI = Button::setup(TextBlock::setup(Panel::setup (tempRect, ofColor(189,209,255)), h1(), controller.getName(), 9, ofColor(0,0,0)), this, &TDIVPC::released, &TDIVPC::setDragged);
    } else {
        nameGUI->setRect(tempRect);
    }
    // add height to y
    tempRect.y += tempRect.height;
    if (!nested) {
        // --------------------------------- date
        // set new height
        tempRect.height = HEIGHTROW * .7;
        if (dateGUI == nullptr) {
            dateGUI = TextBlock::setup(Panel::setup (tempRect, ofColor(169,160,232, 15)), p(), controller.getDate().dateAsString(), 3, ofColor(0,0,0));
        } else {
            dateGUI->setRect(tempRect);
        }
        // add height to y
        tempRect.y += tempRect.height;
        // --------------------------------- description
        // set new height
        tempRect.height = HEIGHTROW * 3;
        if (descriptionGUI == nullptr) {
            descriptionGUI = /*TextBlock::setup(*/Panel::setup (tempRect, ofColor(150,181,192))/*, p(), controller.getDescription(), ofColor(0,0,0))*/;
        } else {
            descriptionGUI->setRect(tempRect);
        }
        // add height to y
        tempRect.y += tempRect.height;
        // --------------------------------- project
        if (controller.getProject() != nullptr) {
            // set new height
            tempRect.height = HEIGHTROW;
            if (projectGUI == nullptr) {
                projectGUI = Panel::setup (tempRect);
            } else {
                projectGUI->setRect(tempRect);
            }
            // add height to y
            tempRect.y += tempRect.height;
        }
        // --------------------------------- location
        if (controller.getLocation() != nullptr) {
            // set new height
            tempRect.height = HEIGHTROW;
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
    
    ofRectangle subViewsRect = ofRectangle (tempRect.x + HEIGHTROW * 1.5, tempRect.y, tempRect.width - HEIGHTROW * 1.5, 0);
    
    if (!controller.getSubModels().empty()) {
        subViewsRect.y +=  HEIGHTROW * .75;
        for (auto it = controller.getSubModels().begin(); it != controller.getSubModels().end(); ++it) {
            AgendaView::redrawView((*it)->id, subViewsRect, true);
            ofVec2f submodelSize = getDimensions(*it, subViewsRect, true);
            subViewsRect.y += submodelSize.y;
            if (it+1 != controller.getSubModels().end()) {
                subViewsRect.y +=  HEIGHTROW;
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
}

void TDIVPC::render() {
    if (controller.isDirty()) {
        redrawInternal();
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
    
    for (auto it = controller.getSubModels().begin(); it != controller.getSubModels().end(); ++it) {
        AgendaView::drawView((*it)->id);
    }
}

// ---------------------------------------------- private

void TDIVPC::setDragged () {
    AgendaView::pressedMouseOn(controller.getID());
}

void TDIVPC::released() {
    AgendaView::releasedMouseOn(controller.getID());
}

ofTrueTypeFont TDIVPC::font_h1;
ofTrueTypeFont TDIVPC::font_p;

ofTrueTypeFont * TDIVPC::h1 () {
    if (!font_h1.isLoaded()) {
        font_h1.load("Arial Bold.ttf", 13);
    }
    return &font_h1;
}

ofTrueTypeFont * TDIVPC::p () {
    if (!font_p.isLoaded()) {
        font_p.load("Arial.ttf", 9);
    }
    return &font_p;
}
