//
//  ToDoItemModel.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef ToDoItemModel_hpp
#define ToDoItemModel_hpp

#include <stdio.h>
#include <string>
#include <vector>
//#include <algorithm>

#include "DateAndTime.hpp"
#include "Project.hpp"
#include "Location.hpp"
#include "Note.hpp"

struct ToDoItemModel {
    static std::vector<long> existingIDs;
    static long provideID ();
    
    void equalize (ToDoItemModel * model);
    void equalizeContent ();
    ToDoItemModel (long id, std::string name);
    ToDoItemModel (long id, std::string name, std::string description);
    ToDoItemModel (long id, std::string name, std::string description, DateAndTime date);
    ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project);
    ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, std::vector<ToDoItemModel *> subModels);
    ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project, Location * location);
    ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project, Location * location, std::vector<ToDoItemModel *> subModels);
    
    long id;
    std::string name;
    std::string description;
    DateAndTime date;
    Project * project;
    Location * location;
    std::vector<Note> notes;
    std::vector<ToDoItemModel *> subModels;
    ToDoItemModel * parent;
    bool deleted;
};

#endif /* ToDoItemModel_hpp */
