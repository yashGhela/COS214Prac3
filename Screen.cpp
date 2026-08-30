#include "Screen.h"
#include <iostream>

Screen::Screen(const std::string& name, int seatCapacity) : EventComponent(name), seatCapacity(seatCapacity), nowShowing("") 
{}

Screen::~Screen() 
{}

void Screen::open() {
    if (nowShowing.empty()) {
        std::cout<<name<<" cannot open: no film assigned"<<std::endl;
        return;
    }
    setStatus("open");
    std::cout<<name<<" is now screening: "<< nowShowing<<std::endl;
}

void Screen::close() {
    setStatus("closed");
    std::cout<<name<<" has closed."<<std::endl;
}

void Screen::reportStatus() const {
    std::cout<<name<<" status: "<<status<<", now showing: "<<(nowShowing.empty() ? "(none)" : nowShowing)<<", seats: "<<seatCapacity<<std::endl;
}

int Screen::getCapacity() const {
    return seatCapacity;
}

void Screen::setFilm(const std::string& title) {
    nowShowing = title;
}