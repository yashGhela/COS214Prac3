#pragma once
#include "Observer.h"

/**
 * @brief Domain-level Observer root for EventFlow.
 *
 * @note Design decision: update() is re-declared here as pure virtual
 * (rather than given a default/stub body). This keeps EventObserver
 * abstract, so the compiler forces every concrete leaf (Stage, Screen,
 * Bathroom, ...) to implement its own reaction to a Notice. The
 * alternative -- a default stub with a warning message -- would let a
 * class silently "forget" to override update() and only fail at runtime.
 */
class EventObserver : public Observer {
    public:
        /** @brief Default constructor. */
        EventObserver();

        /** @brief Virtual destructor. */
        virtual ~EventObserver();

        /**
         * @brief Re-declared pure virtual; concrete leaves must implement this.
         * @param n The notice being broadcast.
         */
        void update(Notice n) override = 0;
};