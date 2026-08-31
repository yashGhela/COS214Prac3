#pragma once
 
#include "EventComponent.h"
#include <vector>

class ProgrammeArea : public EventComponent {
    private:
    std::vector<EventComponent*> children;
 
    public:
    explicit ProgrammeArea(const std::string& name);
    ~ProgrammeArea() override;
    void addAmenity(EventComponent* child) override;
    void remove(EventComponent* child) override;
    EventComponent* getChild(int index) const override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    int childCount() const;

};
