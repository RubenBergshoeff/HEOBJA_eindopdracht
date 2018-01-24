//
//  TDIVfactory.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#include "TDIVfactory.hpp"

TDIVinterface * TDIVfactory::setup(ToDoItemModel *model) {
    // conditional creation, for now just pc version
    TDIVinterface *pTDIV = new TDIVPC ();
    pTDIV->setController(ToDoItemController(model));
    return pTDIV;
}

ofVec2f TDIVfactory::getDimensions (ToDoItemModel *model, ofRectangle drawPos) {
    // conditional getDimensions, for now just pc version
    return TDIVPC::getDimensions(model, drawPos);
}
