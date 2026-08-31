#include "Tent.h"
#include <iostream>

Tent::Tent(const std::string& name, int seatingCapacity) : EventComponent(name), seatingCapacity(seatingCapacity)
{}

Tent::~Tent() 
{}

void Tent::open() {
    setStatus("open");
    std::cout<<name<<" is now open (seating for "<<seatingCapacity<<")."<<std::endl;
}

void Tent::close() {
    setStatus("closed");
    std::cout<<name<<" is now closed."<<std::endl;
}

void Tent::reportStatus() const {
    std::cout<<name<<" status: "<<status<<", seating: "<<seatingCapacity<<std::endl;
}

int Tent::getCapacity() const {
    return seatingCapacity;
}

void Tent::update(Notice n){
    if (n == Notice::RAIN_ALERT){
        close();
    }
}