//
//  GUIBase.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef GUIBase_hpp
#define GUIBase_hpp

#include <stdio.h>

#include "ofMain.h"

class GUIBase {
public:
    
    void draw ();
    
    virtual void setRect (ofRectangle rect);
    virtual void setColor (ofColor color);
    virtual ofRectangle getRect ();
    virtual ofColor getColor ();
    
    virtual ~GUIBase();
    
    
protected:
    static const ofColor DEFAULT_COLOR;
    
    virtual void render () = 0;
    virtual void redraw () = 0;
    
    void setNeedsRedraw ();
    
    ofRectangle rect;
    ofColor color;
    
    
private:
    bool needsRedraw;
};

#endif /* GUIBase_hpp */
