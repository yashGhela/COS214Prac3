#include "FoodTruck.h"
#include <iostream>
#include "Notice.hpp"

FoodTruck::FoodTruck(const std::string& name, const std::string& location, int queueCapacity) : EventComponent(name), location(location), queueCapacity(queueCapacity) 
{}

FoodTruck::~FoodTruck() 
{}

void FoodTruck::open() {
    setStatus("open");
    std::cout<<name<<" is now serving at "<<location<<"."<<std::endl;
}

void FoodTruck::close() {
    setStatus("closed");
    std::cout<<name<<" has closed its window at "<<location<<"."<<std::endl;
}

void FoodTruck::reportStatus() const {
    std::cout<<name<<" status: "<<status<<", location: "<<location<<", queue capacity: "<<queueCapacity<<std::endl;
}

int FoodTruck::getCapacity() const {
    return queueCapacity;
}

void FoodTruck::relocate(const std::string& newLocation) {
    std::cout<<name<<" relocating from "<<location<<" to "<<newLocation<<"."<<std::endl;
    location = newLocation;
}

std::string FoodTruck::getLocation() const {
    return location;
}

void FoodTruck::update(Notice n){
    if (n == Notice::RAIN_ALERT){
        close();
    }
}