#include "Screen.h"
#include <iostream>

Screen::Screen(const std::string& name, int seatCapacity)
    : EventComponent(name), seatCapacity(seatCapacity), nowShowing(""), openForUse(false), projectorWorking(true)
{}

Screen::~Screen() {}

void Screen::open() {
    if (nowShowing.empty()) {
        std::cout << name << " cannot open: no film assigned" << std::endl;
        return;
    }
    setStatus("open");
    std::cout << name << " is now screening: " << nowShowing << std::endl;
}

void Screen::close() {
    setStatus("closed");
    std::cout << name << " has closed." << std::endl;
}

void Screen::reportStatus() const {
    std::cout << "Screen: "
              << (openForUse ? "open" : "closed")
              << " | Film: " << nowShowing
              << " | Projector: "
              << (projectorWorking ? "working" : "down")
              << std::endl;
}

int Screen::getCapacity() const {
    return seatCapacity;
}

void Screen::setFilm(const std::string& title) {
    nowShowing = title;
}

void Screen::update(Notice n) {
    switch (n) {
        case Notice::EVACUATION:
        case Notice::RAIN_ALERT:
            close();
            std::cout << name << " went dark due to alert." << std::endl;
            break;
        case Notice::RESUMING_OPERATION:
            if (!nowShowing.empty()) open();
            break;
        case Notice::TEMPORARILY_CLOSED:
            close();
            break;
        case Notice::SCREEN_DOWN:
            projectorWorking=false;
            close();
            break;
        default:
            // Screen does not react to notices outside its concern.
            break;
    }
}

void Screen::sendNotice(Notice n) {
    controller.sendNotice(n);
}