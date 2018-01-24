//
//  AgendaController.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/10/18.
//

#ifndef AgendaController_hpp
#define AgendaController_hpp

#include <stdio.h>
#include <vector>

#include "ofMain.h"
#include "ToDoItemModel.hpp"
#include "TDIVinterface.hpp"
#include "AgendaView.hpp"

class AgendaController {
public:
    void addModel (ToDoItemModel * model);
    void draw ();
    void scrollView (ofVec2f delta);
    void setViewport (ofRectangle viewport);
protected:
    
    
private:
    void redraw();
    void sort ();
    void createView (ToDoItemModel *model);
    void removeView (ToDoItemModel *model);
    static bool compareDate (const ToDoItemModel * lhs, const ToDoItemModel * rhs);
    std::vector<ToDoItemModel *> todoItems;
    std::vector<ToDoItemModel *> viewableItems;
    ofRectangle rect;
    ofVec2f scrollOfset;
};

#endif /* AgendaController_hpp */
