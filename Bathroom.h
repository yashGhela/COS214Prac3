#pragma once

#include "EventComponent.h"
#include "EventObserver.h"
#include "Notice.hpp"
#include <string>

/**
 * @brief Festival bathroom facility.
 *
 * Acts as a Leaf in the Composite tree and as an Observer in the
 * Observer pattern. It closes during evacuation or cleaning notices.
 */
class Bathroom : public EventComponent, public EventObserver {
private:
    int stalls;
    int occupied;
    bool openForUse;
    bool cleaning;

public:
    /**
     * @brief Creates a bathroom facility.
     *
     * @param name Display name of the bathroom.
     * @param stalls Number of available stalls.
     */
    explicit Bathroom(const std::string& name, int stalls = 4);

    /** @brief Destroys the bathroom facility. */
    ~Bathroom() override;

    /** @brief Opens the bathroom when it is not being cleaned. */
    void open() override;

    /** @brief Closes the bathroom. */
    void close() override;

    /** @brief Prints the bathroom's current operational status. */
    void reportStatus() const override;

    /**
     * @brief Gets the number of bathroom stalls.
     *
     * @return Maximum number of simultaneous users.
     */
    int getCapacity() const override;

    /** @brief Records one attendee entering an available stall. */
    void enterStall();

    /** @brief Records one attendee leaving a stall. */
    void leaveStall();

    /**
     * @brief Reacts to an event notice.
     *
     * @param n Notice pushed by the registered subject.
     */
    void update(Notice n) override;
};