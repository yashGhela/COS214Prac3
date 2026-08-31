#include "Zone.h"
#include <iostream>

Zone::Zone(const std::string& name, int ratedCapacity) : EventComponent(name), ratedCapacity(ratedCapacity) 
{}

Zone::~Zone() {
    for (EventComponent* child : children) {
        delete child;
    }
    children.clear();
}

void Zone::add(EventComponent* child) {
    if (child == nullptr) {
        std::cout << "Warning Attempted to add a null child to " << name << std::endl;
        return;
    }
    for (EventComponent* existing : children) {
        if (existing == child) {
            std::cout << "Warning " << child->getName() << " is already a child of " << name << "." << std::endl;
            return;
        }
    }
    children.push_back(child);
}

void Zone::remove(EventComponent* child) {
    for (size_t i = 0; i < children.size(); i++) {
        if (children[i] == child) {
            children.erase(children.begin() + i);
            return;
        }
    }
    std::cout << "Warning That component is not a child of " << name << std::endl;
}

EventComponent* Zone::getChild(int index) {
    if (index < 0 || index >= static_cast<int>(children.size())) {
        std::cout << "Warning getChild(" << index << ") out of range for " << name << std::endl;
        return nullptr;
    }
    return children[index];
}

void Zone::open() {
    if (children.empty()) {
        std::cout << name << " cannot open: it has no areas or units yet." << std::endl;
        return;
    }
    setStatus("open");
    std::cout << name << " opening" << std::endl;
    for (EventComponent* child : children) {
        child->open();
    }
}

void Zone::close() {
    setStatus("closed");
    std::cout << name << " closing" << std::endl;
    for (EventComponent* child : children) {
        child->close();
    }
}

void Zone::reportStatus() const {
    std::cout << name << " status: " << status<< ", rated capacity: " << ratedCapacity<< ", cildren: " << children.size() << std::endl;
    for (const EventComponent* child : children) {
        child->reportStatus();
    }
}

int Zone::getCapacity() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
    return (total < ratedCapacity) ? total : ratedCapacity;
}

int Zone::childCount() const {
    return static_cast<int>(children.size());
}


void Zone::sendNotice(Notice n){

    controller.sendNotice(n);

}

void Zone::transfer(EventComponent* newComp, EventComponent* leaf){
    newComp->add(leaf);
    remove(leaf);
}