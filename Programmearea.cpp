#include "ProgrammeArea.h"
#include <iostream>

ProgrammeArea::ProgrammeArea(const std::string& name) : EventComponent(name) 
{}

ProgrammeArea::~ProgrammeArea() {
    for (EventComponent* child : children) {
        delete child;
    }
    children.clear();
}

void ProgrammeArea::addAmenity(EventComponent* child) {
    if (child == nullptr) {
        std::cout<<"Warning Attempted to add a null child to "<<name<<std::endl;
        return;
    }
    for (EventComponent* existing : children) {
        if (existing == child) {
            std::cout<<"Warning "<<child->getName()<<" is already a child of " << name << "." << std::endl;
            return;
        }
    }
    children.push_back(child);
}

void ProgrammeArea::remove(EventComponent* child) {
    for (size_t i = 0; i < children.size(); i++) {
        if (children[i] == child) {
            children.erase(children.begin() + i);
            return;
        }
    }
    std::cout << "Warning That component is not a child of " << name << "." << std::endl;
}

EventComponent* ProgrammeArea::getChild(int index) const {
    if (index < 0 || index >= static_cast<int>(children.size())) {
        std::cout << "Warning getChild(" << index << ") out of range for " << name << std::endl;
        return nullptr;
    }
    return children[index];
}

void ProgrammeArea::open() {
    setStatus("open");
    std::cout << name << " opening" << std::endl;
    for (EventComponent* child : children) {
        child->open();
    }
}

void ProgrammeArea::close() {
    setStatus("closed");
    std::cout << name << " closing" << std::endl;
    for (EventComponent* child : children) {
        child->close();
    }
}

void ProgrammeArea::reportStatus() const {
    std::cout << name << " status: " << status << ", cildren " << children.size() << std::endl;
    for (const EventComponent* child : children) {
        child->reportStatus();
    }
}

int ProgrammeArea::getCapacity() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
    return total;
}

int ProgrammeArea::childCount() const {
    return static_cast<int>(children.size());
}