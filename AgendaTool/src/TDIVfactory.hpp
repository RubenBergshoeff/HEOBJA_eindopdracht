//
//  TDIVfactory.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef TDIVfactory_hpp
#define TDIVfactory_hpp

#include <stdio.h>

#include "ofMain.h"
#include "TDIVinterface.hpp"
#include "TDIVPC.hpp"

class TDIVfactory {
public:
    static TDIVinterface * setup (ToDoItemModel * model);
    static ofVec2f getDimensions (ToDoItemModel * model, ofRectangle drawPos);
};

#endif /* TDIVfactory_hpp */
