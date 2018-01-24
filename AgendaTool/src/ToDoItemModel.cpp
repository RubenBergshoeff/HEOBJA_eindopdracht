//
//  ToDoItemModel.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "ToDoItemModel.hpp"

std::vector<long> ToDoItemModel::existingIDs;

long ToDoItemModel::provideID () {
    long value = 0;
    auto it = std::find(existingIDs.begin(), existingIDs.end(), value);
    while (it != existingIDs.end()) {
        value = (long)rand();
        it = std::find(existingIDs.begin(), existingIDs.end(), value);
    }
    existingIDs.push_back(value);
    return value;
}

void ToDoItemModel::equalize (ToDoItemModel * model){
    model->date = this->date;
    model->project = this->project;
    model->location = this->location;
    model->equalizeContent();
}

void ToDoItemModel::equalizeContent (){
    for (auto it = subModels.begin(); it != subModels.end(); ++it) {
        equalize(*it);
    }
}

ToDoItemModel::ToDoItemModel (long id, std::string name)
: ToDoItemModel::ToDoItemModel(id,name, "") {}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description)
: ToDoItemModel::ToDoItemModel(id,name, description, DateAndTime::Today()){}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description, DateAndTime date)
: ToDoItemModel::ToDoItemModel(id,name, description, date, nullptr){}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project)
: ToDoItemModel::ToDoItemModel(id,name, description, date, project, nullptr){}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, std::vector<ToDoItemModel *> subModels)
: ToDoItemModel::ToDoItemModel(id,name, description, date, nullptr, nullptr, subModels){}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project, Location * location) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->date = date;
    this->project = project;
    this->location = location;
    this->parent = nullptr;
    existingIDs.push_back(id);
}

ToDoItemModel::ToDoItemModel (long id, std::string name, std::string description, DateAndTime date, Project * project, Location * location, std::vector<ToDoItemModel *> subModels) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->date = date;
    this->project = project;
    this->location = location;
    this->subModels = subModels;
    this->parent = nullptr;
    this->equalizeContent();
    existingIDs.push_back(id);
}
