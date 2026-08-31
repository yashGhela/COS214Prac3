#include "PopCorn.h"
#include <iostream>
#include "Notice.hpp"


PopCorn::PopCorn(const std::string& name, int stockBags) : EventComponent(name), stockBags(stockBags) 
{}

PopCorn::~PopCorn() 
{}

void PopCorn::open() {
    if (stockBags <= 0) {
        std::cout << name << " cannot open: out of stock." << std::endl;
        return;
    }
    setStatus("open");
    std::cout << name << " is now open (" << stockBags << " bags in stock)." << std::endl;
}

void PopCorn::close() {
    setStatus("closed");
    std::cout<<name<<" is now closed."<<std::endl;
}

void PopCorn::reportStatus() const {
    std::cout<<name<<" status: "<<status<<", stock: "<<stockBags<<" bags"<<std::endl;
}

int PopCorn::getCapacity() const {
    return stockBags;
}

void PopCorn::serve() {
    if (status != "open") {
        std::cout << name << " is not open." << std::endl;
        return;
    }
    if (stockBags > 0) {
        stockBags--;
        if (stockBags == 0) {
            std::cout << name << " just sold out and is closing." << std::endl;
            close();
        }
    }
}

void PopCorn::restock(int bags) {
    if (bags > 0) {
        stockBags += bags;
    }
}

void PopCorn::update(Notice n){
    if (n == Notice::RAIN_ALERT || n==Notice::EVACUATION){
        close();
        std::cout<<name<<" closed"<<std::endl;
    }else if (n==Notice::CLEAR_WEATHER){
        open();
        std::cout<<name<<" opening"<<std::endl;
    }
}