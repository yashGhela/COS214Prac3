#pragma once
 
#include "EventComponent.h"
#include <vector>

class Venue : public EventComponent {
    
    private:
    std::vector<EventComponent*> children;
    int licenseCapacity;
 
    public:
    explicit Venue(const std::string& name, int licenseCapacity);
    ~Venue() override;
    void addAmenity(EventComponent* child) override;
    void remove(EventComponent* child) override;
    EventComponent* getChild(int index) const override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;

};
