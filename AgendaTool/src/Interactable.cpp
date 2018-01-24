//
//  Interactable.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#include "Interactable.hpp"


void Interactable::registerMouseEvents(){
    if(registeredForMouseEvents == true){
        return; // already registered.
    }
    registeredForMouseEvents = true;
    ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

void Interactable::unregisterMouseEvents(){
    if(registeredForMouseEvents == false){
        return; // not registered.
    }
    ofUnregisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
    registeredForMouseEvents = false;
}

Interactable::~Interactable() {
    unregisterMouseEvents();
    GUIBase::~GUIBase();
}
