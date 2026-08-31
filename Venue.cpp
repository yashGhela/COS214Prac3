#include "Venue.h"
#include <iostream>

Venue::Venue(const std::string& name, int licenseCapacity) : EventComponent(name), licenseCapacity(licenseCapacity) 
{}

Venue::~Venue() {
    for (EventComponent* child : children) {
        delete child;
    }
    children.clear();
}

void Venue::addAmenity(EventComponent* child) {
    if (child == nullptr) {
        std::cout << "Warning Attempted to add a null child to " << name << std::endl;
        return;
    }
    for (EventComponent* existing : children) {
        if (existing == child) {
            std::cout << "Warning " << child->getName() << " is already a child of " << name << std::endl;
            return;
        }
    }
    children.push_back(child);
}

void Venue::remove(EventComponent* child) {
    for (size_t i = 0; i < children.size(); i++) {
        if (children[i] == child) {
            children.erase(children.begin() + i);
            return;
        }
    }
    std::cout << "Warning That component is not a child of " << name << std::endl;
}

EventComponent* Venue::getChild(int index) const {
    if (index < 0 || index >= static_cast<int>(children.size())) {
        std::cout << "Warning getChild(" << index << ") out of range for " << name << std::endl;
        return nullptr;
    }
    return children[index];
}

void Venue::open() {
    setStatus("open");
    std::cout << "Welcome to " << name << std::endl;
    for (EventComponent* child : children) {
        child->open();
    }
}

void Venue::close() {
    setStatus("closed");
    for (EventComponent* child : children) {
        child->close();
    }
    std::cout << name << " has closed. Thank you for attending" << std::endl;
}

void Venue::reportStatus() const {
    std::cout << name << " status: " << status<< ", license capacity: " << licenseCapacity<< ", children: " << children.size() << std::endl;
    for (const EventComponent* child : children) {
        child->reportStatus();
    }
}

int Venue::getCapacity() const {
    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
    return (total < licenseCapacity) ? total : licenseCapacity;
}

int Venue::childCount() const {
    return static_cast<int>(children.size());
}