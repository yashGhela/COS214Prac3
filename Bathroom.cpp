#include "Bathroom.h"
#include <iostream>

Bathroom::Bathroom(const std::string &name, int stalls) : EventComponent(name), stalls(stalls), occupied(0)
{}

Bathroom::~Bathroom()
{}

void Bathroom::open()
{
    if(stalls <= 0)
    {
        std::cout<<name<<" cannot open: no stalls available"<<std::endl;
        return; 
    }
    setStatus("open");
    std::cout<<name<<" is now open ("<<stalls<<" stalls)"<<std::endl;
}

void Bathroom::close()
{
    setStatus("closed");
    occupied = 0;
    std::cout<<name<<" is now closed"<<std::endl;
}

void Bathroom::reportStatus() const
{
    std::cout<<"Bathroom "<<name<<" status: "<<status<<", occupancy: "<<occupied<<"/"<<stalls<<std::endl;
}

int Bathroom::getCapacity() const
{
    return stalls;
}

void Bathroom::enterStall()
{
    if(status != "open")
    {
        std::cout<<name<<" is not open"<<std::endl;
        return;
    }
    if(occupied < stalls)
    {
        occupied++;
    }
    else
    {
        std::cout<<name<<" is at full capactiy"<<std::endl;
    }
}

void Bathroom::leaveStall()
{
    if(occupied > 0)
    {
        occupied--;
    }
}


void Bathroom::update(Notice n){
    if (n == Notice::RAIN_ALERT || n==Notice::EVACUATION){
        close();
        std::cout<<name<<" closed"<<std::endl;
    }else if (n==Notice::CLEAR_WEATHER){
        open();
        std::cout<<name<<" opening"<<std::endl;
    }
}