//
//  ButtonBar.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef ButtonBar_hpp
#define ButtonBar_hpp

#include <stdio.h>
#include "Interactable.hpp"
//#include "TDIVinterface.hpp"
#include "MenuBar.hpp"
//class TDIVPC;

class ButtonBar : public Interactable {
public:
    static ButtonBar * setup (GUIBase * base, MenuBar * obj, void (MenuBar::*a)());
    
    virtual bool mouseMoved(ofMouseEventArgs & args) override {return false;}
    virtual bool mousePressed(ofMouseEventArgs & args) override {return false;}
    virtual bool mouseDragged(ofMouseEventArgs & args) override {return false;}
    virtual bool mouseReleased(ofMouseEventArgs & args) override;
    virtual bool mouseScrolled(ofMouseEventArgs & args) override {return false;}
    ButtonBar();
    ~ButtonBar();
    
protected:
    virtual void render () override;
    virtual void redraw () override;
    
private:
    GUIBase * base;
    MenuBar * obj;
    void (MenuBar::*func)();
};

#endif /* Button_hpp */

