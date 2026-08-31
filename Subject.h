#pragma once
#include "Observer.h"

/**
 * @brief GoF Subject role. Anything that maintains observers and notifies them.
 */
class Subject {
    public:
        /** @brief Virtual destructor for safe polymorphic destruction. */
        virtual ~Subject() = default;

        /**
         * @brief Register an observer. Duplicate registration is ignored.
         * @param o Observer to register. Must not be nullptr. Non-owning:
         * the Subject does not take ownership of o and will not delete it.
         */
        virtual void attach(Observer* o) = 0;

        /**
         * @brief Deregister an observer. No-op if not currently registered.
         * @param o Observer to remove.
         */
        virtual void detach(Observer* o) = 0;

        /** @brief Push the current notice to every registered observer. */
        virtual void notify() = 0;
};