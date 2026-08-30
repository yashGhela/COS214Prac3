#pragma once
 
#include "EventComponent.h"
#include <string>

class Screen : public EventComponent {
    
    private:
    int seatCapacity;
    std::string nowShowing;
 
    public:
    explicit Screen(const std::string& name, int seatCapacity);
    ~Screen() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void setFilm(const std::string& title);

};