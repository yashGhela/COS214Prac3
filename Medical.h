#pragma once
 
#include "EventComponent.h"
#include <string>

class Medical : public EventComponent {
    
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
};