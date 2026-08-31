#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "Notice.hpp"

class Venue : public EventComponent {
    
    private:
    std::vector<EventComponent*> children;
    int licenseCapacity;
 
    public:
    explicit Venue(const std::string& name, int licenseCapacity);
    ~Venue() override;
    void add(EventComponent* child) override;
    void remove(EventComponent* child) override;
    EventComponent* getChild(int index) override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;
    void sendNotice(Notice n);

};
