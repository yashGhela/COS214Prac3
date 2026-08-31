#pragma once
#include "Subject.h"
#include "Notice.hpp"
#include <vector>
#include <string>

/**
 * @brief Concrete Subject. Holds a non-owning list of Observers and pushes
 * Notice values to them via notify().
 *
 * @note Design decision (ownership): ComponentController stores raw,
 * non-owning Observer* pointers. It never calls delete on anything in
 * observerList, including in its own destructor. Whatever owns a given
 * Observer (typically an EventComponent Leaf owned by the Composite tree)
 * is responsible for calling detach() on every controller it registered
 * with before that observer is destroyed, to avoid dangling pointers.
 */
class ComponentController : public Subject {
    private:
        std::vector<Observer*> observerList;
        Notice currentNotice;

    public:
        /** @brief Construct a controller with no observers registered. */
        ComponentController();

        /**
         * @brief Destructor. Clears the observer list but does not delete
         * any observer (see ownership note above).
         */
        ~ComponentController() override;

        /**
         * @brief Register an observer. If o is already registered, or is
         * nullptr, the call is ignored and a message is printed.
         * @param o Observer to register. Non-owning.
         */
        void attach(Observer* o) override;

        /**
         * @brief Deregister an observer. If o is not currently registered,
         * the call is ignored and a message is printed.
         * @param o Observer to remove.
         */
        void detach(Observer* o) override;

        /** @brief Push currentNotice to every registered observer's update(). */
        void notify() override;

        /**
         * @brief Set the notice that the next notify() call will push.
         * @param n Notice value to store as the current notice.
         */
        void setNotice(Notice n);

        /**
         * @brief Convenience: set the notice and notify in one call.
         * @param n Notice value to broadcast immediately.
         */
        void sendNotice(Notice n);

        /** @return A short human-readable summary of how many observers are registered. */
        std::string printObservers() const;
};