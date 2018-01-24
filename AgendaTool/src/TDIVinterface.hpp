//
//  TDIVinterface.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/10/18.
//

#ifndef TDIVinterface_hpp
#define TDIVinterface_hpp

#include <stdio.h>
#include <memory>

#include "ofMain.h"
#include "ToDoItemController.hpp"

class TDIVinterface {
public:
    void draw ();
    void redraw (ofRectangle drawPos, bool nested);
    void setController (ToDoItemController controller);
    ToDoItemController * getController ();
    bool isActive ();
    virtual ~TDIVinterface ();
    
protected:
    virtual void redrawInternal () = 0;
    virtual void render () = 0;
    ToDoItemController controller;
    bool needsRedraw;
    ofRectangle rect;
    bool nested;
};

#endif /* TDIVinterface_hpp */
