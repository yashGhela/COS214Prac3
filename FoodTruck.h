#pragma once
 
#include "EventComponent.h"
#include <string>

class FoodTruck : public EventComponent {
    
    private:
    std::string location;
    int queueCapacity;
 
    public:
    explicit FoodTruck(const std::string& name, const std::string& location, int queueCapacity);
    ~FoodTruck() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void relocate(const std::string& newLocation);
    std::string getLocation() const;
    
};
