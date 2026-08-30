#pragma once
#include "EventComponent.h"
#include <string>

class Bathroom : public EventComponent{

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

};