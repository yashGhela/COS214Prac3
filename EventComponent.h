#pragma once
#include <string>

class EventComponent{

    protected:
    std::string name;
    std::string status;

    public:
    explicit EventComponent(const std::string& name);
    virtual ~EventComponent();
    virtual void add(EventComponent* child);
    virtual void remove(EventComponent* child);
    virtual EventComponent* getChild(int index);
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;
    void setStatus(const std::string& newStatus);
    std::string getName() const;
    
};