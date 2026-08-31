#pragma once
#include "EventComponent.h"
#include <string>
#include "EventObserver.h"

class Bathroom : public EventComponent, public EventObserver{

    private:
    int stalls;
    int occupied;

    public:
    explicit Bathroom(const std::string& name, int stalls = 4);
    ~Bathroom() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void enterStall();
    void leaveStall();
    void update(Notice n) override;

};