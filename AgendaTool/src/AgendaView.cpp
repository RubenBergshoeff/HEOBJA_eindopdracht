//
//  AgendaView.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#include "AgendaView.hpp"

bool AgendaView::drawView (long view) {
    auto it = Instance()->todoViews.find(view);
    if (it != Instance()->todoViews.end()) {
        (*it).second->draw();
        return true;
    } else {
        return false;
    }
}

void AgendaView::redrawView (long view, ofRectangle drawPos) {
    redrawView(view, drawPos, false);
}

void AgendaView::redrawView (long view, ofRectangle drawPos, bool nested) {
    auto it = Instance()->todoViews.find(view);
    if (it != Instance()->todoViews.end()) {
        (*it).second->redraw(drawPos, nested);
    }
}

void AgendaView::addView (ToDoItemModel * model) {
    auto it = Instance ()->todoViews.find(model->id);
    if (it == Instance()->todoViews.end()) {
        Instance()->todoViews[model->id] = TDIVfactory::setup(model);
    }
}

void AgendaView::removeView (ToDoItemModel * model) {
    auto it = Instance ()->todoViews.find(model->id);
    if (it != Instance()->todoViews.end()) {
        delete (*it).second;
        Instance()->todoViews.erase(it);
    }
}

bool AgendaView::doesNeedRedraw() {
    return Instance()->needsRedraw;
}

void AgendaView::setNeedRedraw (bool state){
    Instance()->needsRedraw = state;
}

void AgendaView::pressedMouseOn (long view) {
    Instance ()->draggedView = view;
}

void AgendaView::releasedMouseOn (long view) {
//    if (view >= 0 && Instance ()->draggedView >= 0) {
//        Instance()->todoViews[view]->getController()->addSubModel(
//                                                                  Instance()->todoViews[Instance()->draggedView]->getController()->getModel()
//                                                                  );
//        setNeedRedraw(true);
//    }else if (Instance()->draggedView >= 0) {
////        ToDoItemController * pC = Instance()->todoViews[Instance()->draggedView]->getController();
//        
//    }
//    Instance ()->draggedView = -1;
}

std::shared_ptr<AgendaView> AgendaView::Instance() {
    if (privateInstance == nullptr) {
        privateInstance = std::make_shared<AgendaView>();
    }
    return privateInstance;
}

AgendaView::AgendaView () {
    needsRedraw = true;
}

AgendaView::~AgendaView() {
    for (auto it = todoViews.begin(); it != todoViews.end(); ++it) {
        delete (*it).second;
    }
}

std::shared_ptr<AgendaView> AgendaView::privateInstance = nullptr;
