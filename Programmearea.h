#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "ComponentController.h"
#include "Notice.hpp"

class ProgrammeArea : public EventComponent {
    private:
    std::vector<EventComponent*> children;
    ComponentController controller;

 
    public:
    explicit ProgrammeArea(const std::string& name);
    ~ProgrammeArea() override;
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
