#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

class PopCorn : public EventComponent, public EventObserver {
    
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
    void update(Notice n);

};