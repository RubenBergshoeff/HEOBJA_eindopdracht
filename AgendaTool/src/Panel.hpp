//
//  Panel.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef Panel_hpp
#define Panel_hpp

#include <stdio.h>
#include "GUIBase.hpp"

class Panel : public GUIBase {
public:
    Panel ();
    
    static Panel * setup ();
    static Panel * setup (ofRectangle rect);
    static Panel * setup (ofRectangle rect, ofColor color);
    
    
protected:
    virtual void render () override;
    virtual void redraw () override;
    
    ofPath bg;
    
    
private:
    
};

#endif /* Panel_hpp */
