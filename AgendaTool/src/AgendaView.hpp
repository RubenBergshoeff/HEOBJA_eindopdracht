//
//  AgendaView.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/11/18.
//

#ifndef AgendaView_hpp
#define AgendaView_hpp

#include <stdio.h>
#include <map>
#include <memory>

#include "TDIVfactory.hpp"
#include "TDIVinterface.hpp"

class AgendaView {
public:
    AgendaView ();
    static bool drawView (long view);
    static void redrawView (long view, ofRectangle drawPos);
    static void redrawView (long view, ofRectangle drawPos, bool nested);
    static void addView (ToDoItemModel * model);
    static void removeView (ToDoItemModel * model);
    static bool doesNeedRedraw ();
    static void setNeedRedraw(bool state);
    static void pressedMouseOn (long view);
    static void releasedMouseOn (long view);
    ~AgendaView();
private:
    static std::shared_ptr<AgendaView> Instance ();
    static std::shared_ptr<AgendaView> privateInstance; // shared_ptr so it will be destroyed for sure when program goes out of scope
    std::map<long, TDIVinterface *> todoViews;
    bool needsRedraw;
    long draggedView;
};

#endif /* AgendaView_hpp */
