#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "ComponentController.h"
#include "Notice.hpp"
#include "EventObserver.h"

class ProgrammeArea : public EventComponent, public EventObserver{
    private:
    std::vector<EventComponent*> children;
    ComponentController controller;
    int maxcapacity;

 
    public:
    explicit ProgrammeArea(const std::string& name);
    ~ProgrammeArea() override;
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
    void update(Notice n) override;
};
