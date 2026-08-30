#pragma once
 
#include "EventComponent.h"
#include <vector>

class Zone : public EventComponent {
    
    private:
    std::vector<EventComponent*> children;
    int ratedCapacity;
 
    public:
    explicit Zone(const std::string& name, int ratedCapacity);
    ~Zone() override;
    void add(EventComponent* child) override;
    void remove(EventComponent* child) override;
    EventComponent* getChild(int index) override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;

};