#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

class Tent : public EventComponent, public EventObserver {
    
    private:
    int seatingCapacity;
 
    public:
    explicit Tent(const std::string& name, int seatingCapacity);
    ~Tent() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(Notice n) override;

};

