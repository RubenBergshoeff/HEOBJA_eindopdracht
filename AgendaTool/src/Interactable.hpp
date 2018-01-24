//
//  Interactable.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef Interactable_hpp
#define Interactable_hpp

#include <stdio.h>
#include "GUIBase.hpp"

class Interactable : public GUIBase {
public:
    void registerMouseEvents();
    void unregisterMouseEvents();

    
    virtual bool mouseMoved(ofMouseEventArgs & args) = 0;
    virtual bool mousePressed(ofMouseEventArgs & args) = 0;
    virtual bool mouseDragged(ofMouseEventArgs & args) = 0;
    virtual bool mouseReleased(ofMouseEventArgs & args) = 0;
    virtual bool mouseScrolled(ofMouseEventArgs & args) = 0;
    virtual void mouseEntered(ofMouseEventArgs & args){}
    virtual void mouseExited(ofMouseEventArgs & args){}
    
    virtual ~Interactable();
    
protected:
private:
    bool registeredForMouseEvents;
};

#endif /* Interactable_hpp */
