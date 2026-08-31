#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name) : name(name), status("closed") {}

EventComponent::~EventComponent() {}

void EventComponent::addAmenity(EventComponent* child) {
    std::cout << name << " cannot contain children (it is a leaf)." << std::endl;
}

void EventComponent::remove(EventComponent* child) {
    std::cout << name << " has no children to remove (it is a leaf)." << std::endl;
}

EventComponent* EventComponent::getChild(int index) const {
    return nullptr;
}

void EventComponent::setStatus(const std::string& s) {
    status = s;
}

std::string EventComponent::getStatus() const {
    return status;
}

std::string EventComponent::getName() const {
    return name;
}