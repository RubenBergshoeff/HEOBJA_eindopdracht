//
//  ToDoItemView.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef ToDoItemView_hpp
#define ToDoItemView_hpp

#include <stdio.h>

#include "ofMain.h"
#include "ToDoItemController.hpp"
#include "GUIBase.hpp"

#include "Panel.hpp"
#include "TextBlock.hpp"
#include "Interactable.hpp"
#include "Button.hpp"

class ToDoItemView {
public:
    void draw ();
    float draw (ofRectangle rect);
    float getDrawingHeight ();
    ToDoItemController * getController () const;
    ToDoItemView (ToDoItemController * controller);
protected:
    static const int HEIGHTROW = 20;
    void updateGUI (ofRectangle rect);
    void updateGUI (ofRectangle rect, bool nested);
private:
    ToDoItemController * controller;
    std::vector<ToDoItemView *> subViews;
    GUIBase * backgroundGUI;
    GUIBase * nameGUI;
    GUIBase * descriptionGUI;
    GUIBase * dateGUI;
    GUIBase * projectGUI;
    GUIBase * locationGUI;
    std::vector<GUIBase *> noteGUIs;
    ofRectangle subViewsRect;
    float drawingHeight;
    static ofTrueTypeFont * h1 ();
    static ofTrueTypeFont * p ();
    static ofTrueTypeFont font_h1;
    static ofTrueTypeFont font_p;
};

#endif /* ToDoItemView_hpp */
