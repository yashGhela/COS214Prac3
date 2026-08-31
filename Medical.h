#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

class Medical : public EventComponent, public EventObserver {
    
    private:
    int staffCount;
    static const int PATIENTS_PER_STAFF = 2;

    public:
    explicit Medical(const std::string& name, int staffCount);
    ~Medical() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(Notice n) override;
};