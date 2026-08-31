#include "Stage.h"
#include <iostream>

Stage::Stage(const std::string& name, int audienceCapacity)
    : EventComponent(name), audienceCapacity(audienceCapacity), currentFilm("Unscheduled"), paused(false)
{}

Stage::~Stage() {}

void Stage::open() {
    setStatus("open");
    paused = false;
    std::cout << name << " is now open, presenting: " << currentFilm << std::endl;
}

void Stage::close() {
    setStatus("closed");
    paused = false;
    std::cout << name << " has closed." << std::endl;
}

void Stage::reportStatus() const {
    std::cout << name << " status: " << status << ", paused: " << paused
               << ", act: " << currentFilm << ", capacity: " << audienceCapacity << std::endl;
}

int Stage::getCapacity() const {
    return audienceCapacity;
}

void Stage::setAct(const std::string& act) {
    currentFilm = act;
}

void Stage::pause() {
    if (status != "open") {
        std::cout << name << " cannot pause: it is not open." << std::endl;
        return;
    }
    paused = true;
    std::cout << name << " has paused " << currentFilm << std::endl;
}

void Stage::resume() {
    if (!paused) {
        std::cout << name << " is not paused" << std::endl;
        return;
    }
    paused = false;
    std::cout << name << " has resumed " << currentFilm << std::endl;
}

bool Stage::isPaused() const {
    return paused;
}

void Stage::update(Notice n) {
    switch (n) {
        case Notice::RAIN_ALERT:
        case Notice::EVACUATION:
            if (status == "open") pause();
            std::cout << name << " reacting to alert: pausing performance." << std::endl;
            break;
        case Notice::RESUMING_OPERATION:
            if (paused) resume();
            break;
        case Notice::TEMPORARILY_CLOSED:
            close();
            break;
        default:
            // Stage does not react to notices outside its concern.
            break;
    }
}

void Stage::sendNotice(Notice n) {
    controller.sendNotice(n);
}