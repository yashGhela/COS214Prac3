#pragma once
 
#include "EventComponent.h"
#include <string>

class Stage : public EventComponent {
    private:
    int audienceCapacity;
    std::string currentFilm;
    bool paused;
 
    public:
    explicit Stage(const std::string& name, int audienceCapacity);
    ~Stage() override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void setAct(const std::string& act);
    void pause();
    void resume();
    bool isPaused() const;

};    
