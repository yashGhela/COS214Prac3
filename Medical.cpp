#include "Medical.h"
#include <iostream>
#include "Notice.hpp"

Medical::Medical(const std::string& name, int staffCount) : EventComponent(name), staffCount(staffCount) 
{
    status = "standby";
}

Medical::~Medical() 
{}

void Medical::open() {
    setStatus("active");
    std::cout<<name<<" is now active with "<<staffCount<<" staff on duty."<<std::endl;
}

void Medical::close() {
    setStatus("standby");
    std::cout<<name<<" is now on standby (still reachable in an emergency)."<<std::endl;
}

void Medical::reportStatus() const {
    std::cout<<name<<" status: "<<status<<", staff: "<<staffCount<<std::endl;
}

int Medical::getCapacity() const {
    return staffCount * PATIENTS_PER_STAFF;
}

void Medical::update(Notice n){
     if ( n==Notice::EVACUATION){
        close();
        std::cout<<name<<" closed"<<std::endl;
    }else if (n==Notice::CLEAR_WEATHER){
        open();
        std::cout<<name<<" opening"<<std::endl;
    }
}