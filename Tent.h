#pragma once
 
#include "EventComponent.h"
#include <string>

class Tent : public EventComponent {
    
    private:
    int seatingCapacity;
 
    public:
    explicit Tent(const std::string& name, int seatingCapacity);
    ~Tent() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

};

