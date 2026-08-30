#pragma once
 
#include "EventComponent.h"
#include <string>

class PopCorn : public EventComponent {
    
    private:
    int stockBags;
 
    public:
    explicit PopCorn(const std::string& name, int stockBags);
    ~PopCorn() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void serve();
    void restock(int bags);

};