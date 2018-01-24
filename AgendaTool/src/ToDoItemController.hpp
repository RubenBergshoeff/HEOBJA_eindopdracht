//
//  ToDoItemController.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef ToDoItemController_hpp
#define ToDoItemController_hpp

#include <stdio.h>
#include <memory>

#include "ToDoItemModel.hpp"

class ToDoItemController {
public:
    void addSubModel (ToDoItemModel * model);
    ToDoItemModel * removeSubModel (int model);
    std::string getName () const;
    std::string getDescription () const;
    long getID () const;
    DateAndTime getDate () const;
    Project * getProject () const;
    Location * getLocation () const;
    Note * getNote (int note) const;
    long int notesSize () const;
    ToDoItemModel * getParent () const;
    ToDoItemModel * getModel () const;
    std::vector<ToDoItemModel *> getSubModels () const;
    bool isDirty ();
    void setClean ();
    void setName (std::string name);
    void setDescription (std::string description);
    void setDate (DateAndTime date);
    void setProject (Project * project);
    void setLocation (Location * location);
    void addNote (Note note);
    void replaceNote (int index, Note note);
    void removeNote (int note);
    void setParent (ToDoItemModel * parent);
    bool isConnected ();
    ToDoItemController ();
    ToDoItemController (ToDoItemModel * model);
    
protected:
    
private:
    ToDoItemModel * model;
    bool dirty;
};

#endif /* ToDoItemController_hpp */
