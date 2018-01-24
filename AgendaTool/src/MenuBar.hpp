//
//  MenuBar.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/24/18.
//

#ifndef MenuBar_hpp
#define MenuBar_hpp

#include <stdio.h>

#include "AgendaController.hpp"
#include "GUIBase.hpp"
#include "TDIVPC.hpp"

#include "Panel.hpp"
#include "TextBlock.hpp"
#include "Interactable.hpp"

class ButtonBar;

class MenuBar {
public:
    MenuBar (AgendaController * ac, ofRectangle rect);
    void draw ();
private:
    void redraw ();
    void addModel ();
    AgendaController * ac;
    ofRectangle rect;
    GUIBase * addButton;
    GUIBase * background;
};

#include "ButtonBar.hpp"
#endif /* MenuBar_hpp */
