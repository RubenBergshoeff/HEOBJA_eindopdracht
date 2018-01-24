//
//  Button.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "Interactable.hpp"
//#include "TDIVinterface.hpp"
#include "TDIVPC.hpp"
//class TDIVPC;

class Button : public Interactable {
public:
    static Button * setup (GUIBase * base, TDIVPC * obj, void (TDIVPC::*a)(), void (TDIVPC::*b)());
    
    virtual bool mouseMoved(ofMouseEventArgs & args) override {return false;}
    virtual bool mousePressed(ofMouseEventArgs & args) override;
    virtual bool mouseDragged(ofMouseEventArgs & args) override {return false;}
    virtual bool mouseReleased(ofMouseEventArgs & args) override;
    virtual bool mouseScrolled(ofMouseEventArgs & args) override {return false;}
    
    virtual void setRect (ofRectangle rect) override;
    
    Button();
    ~Button();
    
protected:
    virtual void render () override;
    virtual void redraw () override;
    
private:
    GUIBase * base;
    TDIVPC * obj;
    void (TDIVPC::*funcReleased)();
    void (TDIVPC::*funcPressed)();
};

#endif /* Button_hpp */
