#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "Notice.hpp"
#include "ComponentController.h"

class Venue : public EventComponent {
    
    private:
    std::vector<EventComponent*> children;
    int licenseCapacity;
    ComponentController controller;
 
    public:
    explicit Venue(const std::string& name, int licenseCapacity);
    ~Venue() override;
    void add(EventComponent* child) override;
    void remove(EventComponent* child) override;
    void transfer(EventComponent* newComp, EventComponent* leaf);
    EventComponent* getChild(int index) override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;
    void sendNotice(Notice n);
    

};
