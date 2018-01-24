//
//  ToDoItemController.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "ToDoItemController.hpp"

void ToDoItemController::addSubModel (ToDoItemModel * model){
    this->model->equalize(model);
    model->parent = this->model;
    this->model->subModels.push_back(model);
    dirty = true;
}

ToDoItemModel * ToDoItemController::removeSubModel (int model) {
    ToDoItemModel * pModel = this->model->subModels[model];
    this->model->subModels.erase(this->model->subModels.begin() + model);
    return pModel;
    dirty = true;
}

std::string ToDoItemController::getName () const{
    return model->name;
}

std::string ToDoItemController::getDescription () const{
    return model->description;
}

long ToDoItemController::getID() const {
    return model->id;
}

DateAndTime ToDoItemController::getDate () const{
    return model->date;
}

Project * ToDoItemController::getProject () const {
    return model->project;
}

Location * ToDoItemController::getLocation () const{
    return model->location;
}

Note * ToDoItemController::getNote (int note) const {
    return &model->notes[note];
}

long int ToDoItemController::notesSize() const {
    return model->notes.size();
}

ToDoItemModel * ToDoItemController::getParent() const {
    return model->parent;
}

ToDoItemModel * ToDoItemController::getModel() const {
    return model;
}

std::vector<ToDoItemModel *> ToDoItemController::getSubModels () const {
    return model->subModels;
}

bool ToDoItemController::isDirty () {
    bool childDirty = false;
    // make big boss dirty
    return (dirty || childDirty);
}

void ToDoItemController::setClean () {
    dirty = false;
}

void ToDoItemController::setName (std::string name) {
    model->name = name;
    dirty = true;
}

void ToDoItemController::setDescription (std::string description){
    model->description = description;
    dirty = true;
}

void ToDoItemController::setDate (DateAndTime date){
    model->date = date;
    model->equalizeContent();
    dirty = true;
}

void ToDoItemController::setProject (Project * project){
    model->project = project;
    model->equalizeContent();
    dirty = true;
}

void ToDoItemController::setLocation (Location * location){
    model->location = location;
    model->equalizeContent();
    dirty = true;
}

void ToDoItemController::addNote(Note note) {
    model->notes.push_back(note);
    dirty = true;
}

void ToDoItemController::replaceNote (int index, Note note){
    model->notes[index] = note;
    dirty = true;
}

void ToDoItemController::removeNote(int note){
    model->notes.erase(model->notes.begin() + note);
    dirty = true;
}

void ToDoItemController::setParent (ToDoItemModel * parent) {
    model->parent = parent;
}

bool ToDoItemController::isConnected() {
    return (model != nullptr);
}

ToDoItemController::ToDoItemController() {
    this->model = nullptr;
}

ToDoItemController::ToDoItemController(ToDoItemModel * model) {
    this->model = model;
    dirty = true;
}
