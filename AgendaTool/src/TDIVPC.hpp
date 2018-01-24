//
//  TDIVPC.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef TDIVPC_hpp
#define TDIVPC_hpp

#include <stdio.h>

#include "TDIVinterface.hpp"
#include "GUIBase.hpp"

#include "Panel.hpp"
#include "TextBlock.hpp"
#include "Interactable.hpp"
#include "AgendaView.hpp"

class Button;

class TDIVPC : public TDIVinterface {
public:
    static ofVec2f getDimensions (ToDoItemModel * model, ofRectangle drawPos);
    static ofVec2f getDimensions (ToDoItemModel * model, ofRectangle drawPos, bool nested);
    TDIVPC();
    ~TDIVPC();
    static ofTrueTypeFont * h1 ();
    static ofTrueTypeFont * p ();
    
protected:
    virtual void redrawInternal () override;
    virtual void render () override;
    static const int HEIGHTROW = 20;
    
private:
    void setDragged ();
    void released ();
    static ofTrueTypeFont font_h1;
    static ofTrueTypeFont font_p;
    GUIBase * backgroundGUI;
    GUIBase * nameGUI;
    GUIBase * descriptionGUI;
    GUIBase * dateGUI;
    GUIBase * projectGUI;
    GUIBase * locationGUI;
};
#include "Button.hpp"

#endif /* TDIVPC_hpp */
