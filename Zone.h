#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "Notice.hpp"
#include "ComponentController.h"


class Zone : public EventComponent{
    
    private:
    std::vector<EventComponent*> children;
    int ratedCapacity;
    ComponentController controller;
 
    public:
    explicit Zone(const std::string& name, int ratedCapacity);
    ~Zone() override;
    void add(EventComponent* child) override;
    void remove(EventComponent* child) override;
    EventComponent* getChild(int index) const override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;
    void sendNotice(Notice n);
    void transfer(EventComponent* newComp, EventComponent* leaf);
   

};