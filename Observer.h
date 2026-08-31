#pragma once
#include "Notice.hpp"

/**
 * @brief GoF Observer role. Anything that can react to a Notice.
 */
class Observer {
    public:
        /** @brief Virtual destructor for safe polymorphic destruction. */
        virtual ~Observer() = default;

        /**
         * @brief Called by a Subject to push a Notice to this observer.
         * @param n The notice being broadcast.
         */
        virtual void update(Notice n) = 0;
};