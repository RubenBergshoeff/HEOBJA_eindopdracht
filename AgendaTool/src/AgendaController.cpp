//
//  AgendaController.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/10/18.
//

#include "AgendaController.hpp"

void AgendaController::addModel(ToDoItemModel * model) {
    todoItems.push_back(model);
//    for (auto it = model.subModels.begin(); it != model.subModels.end(); ++it) {
//        addModel(*(*it));
//    }
    AgendaView::setNeedRedraw(true);
}

void AgendaController::draw () {
    if (AgendaView::doesNeedRedraw()) {
        redraw();
    }
    for (auto it = viewableItems.begin(); it != viewableItems.end(); ++it) {
        AgendaView::drawView((*it)->id);
    }
}

void AgendaController::setViewport (ofRectangle viewport) {
    rect = viewport;
}

void AgendaController::redraw () {
    viewableItems.clear();
    ofRectangle viewPort = rect;
    viewPort.x += scrollOfset.x;
    viewPort.y += scrollOfset.y;
    sort ();
    for (auto it = todoItems.begin(); it != todoItems.end(); ++it) {
        if ((*it)->parent == nullptr) {
            ofVec2f viewSize = TDIVfactory::getDimensions((*it), viewPort);
            // TODO: flag system so we stop checking after viewport has been filled and just remove the rest of the views
            if (// if top is within actual viewport
                (viewPort.y >= rect.y && viewPort.y < rect.y + rect.height) ||
                // if bottom is within actual viewport
                (viewPort.y + viewSize.y >= rect.y && viewPort.y + viewSize.y < rect.y + rect.height)
                ) {
                createView((*it));
                AgendaView::redrawView((*it)->id, viewPort);
                viewableItems.push_back((*it));
            } else {
                removeView((*it));
            }
            viewPort.y += viewSize.y;
        }
    }
    AgendaView::setNeedRedraw(false);
}

void AgendaController::createView (ToDoItemModel *model) {
    AgendaView::addView(model);
    for (auto it = model->subModels.begin(); it != model->subModels.end(); ++it) {
        AgendaView::addView((*it));
    }
}

void AgendaController::removeView (ToDoItemModel *model) {
    AgendaView::removeView(model);
    for (auto it = model->subModels.begin(); it != model->subModels.end(); ++it) {
        AgendaView::addView((*it));
    }
}

void AgendaController::scrollView (ofVec2f delta) {
    scrollOfset += delta;
    AgendaView::setNeedRedraw(true);
}

void AgendaController::sort () {
    std::sort (todoItems.begin(), todoItems.end(),
               AgendaController::compareDate);
}

bool AgendaController::compareDate (const ToDoItemModel * lhs, const ToDoItemModel * rhs){
    return (lhs->date < rhs->date);
}
