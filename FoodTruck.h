#pragma once
 
#include "EventComponent.h"
#include <string>
#include "EventObserver.h"
#include "Notice.hpp"

class FoodTruck : public EventComponent, public EventObserver {
    
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

    void update(Notice n) override;
    
};
