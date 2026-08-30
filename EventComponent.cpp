#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name) : name(name), status("closed")
{}

EventComponent::~EventComponent()
{}

void EventComponent::add(EventComponent *child)
{

}

void EventComponent::remove(EventComponent *child)
{
}

EventComponent *EventComponent::getChild(int index)
{
    return nullptr;
}

void EventComponent::setStatus(const std::string &newStatus)
{
    status = newStatus;
}

std::string EventComponent::getName() const
{
    return name;
}
