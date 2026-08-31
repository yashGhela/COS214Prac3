#include "ComponentController.h"
#include <algorithm>
#include <sstream>
#include <iostream>

ComponentController::ComponentController() : currentNotice(Notice::CLOSING) {}

ComponentController::~ComponentController() {
    observerList.clear();
}


void ComponentController::attach(Observer* o) {
    if (o == nullptr) {
        std::cout << "Cannot attach a null observer." << std::endl;
        return;
    }
    if (std::find(observerList.begin(), observerList.end(), o) != observerList.end()) {
        std::cout << "Observer already registered, ignoring duplicate attach." << std::endl;
        return;
    }
    observerList.push_back(o);
}

void ComponentController::detach(Observer* o) {
    auto it = std::find(observerList.begin(), observerList.end(), o);
    if (it == observerList.end()) {
        std::cout << "Observer not found, nothing to detach." << std::endl;
        return;
    }
    observerList.erase(it);
}

void ComponentController::notify() {
    for (Observer* o : observerList) {
        o->update(currentNotice);
    }
}

void ComponentController::setNotice(Notice n) {
    currentNotice = n;
}

void ComponentController::sendNotice(Notice n) {
    setNotice(n);
    notify();
}

std::string ComponentController::printObservers() const {
    std::ostringstream oss;
    oss << observerList.size() << " observer(s) registered.";
    return oss.str();
}