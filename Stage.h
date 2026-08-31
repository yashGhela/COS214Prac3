#pragma once

#include "EventComponent.h"
#include "EventObserver.h"
#include "ComponentController.h"
#include "Notice.hpp"
#include <string>

/**
 * @brief A performance stage.
 *
 * GoF roles: Leaf (Component) in the Composite tree, and Observer (reacts
 * to notices pushed down from its parent Composite). It also holds its own
 * ComponentController and so acts as a Subject-by-composition for anything
 * that wants to observe this specific stage.
 *
 * @note Design decision: Stage does not inherit Subject directly. Instead
 * it holds a ComponentController member and delegates to it via
 * sendNotice(). This was chosen over multiple-inheriting Subject as well
 * as EventComponent/EventObserver, to avoid a three-way inheritance
 * diamond and keep Stage's own Subject-side bookkeeping (its observer
 * list) fully encapsulated rather than exposed as part of Stage's own
 * interface.
 */
class Stage : public EventComponent, public EventObserver {
    private:
        int audienceCapacity;
        std::string currentFilm;
        bool paused;
        ComponentController controller;

    public:
        /**
         * @brief Construct a stage.
         * @param name Display name.
         * @param audienceCapacity Maximum audience size.
         */
        explicit Stage(const std::string& name, int audienceCapacity);

        /** @brief Destructor. */
        ~Stage() override;

        /** @brief Open the stage for its current act. */
        void open() override;

        /** @brief Close the stage. */
        void close() override;

        /** @brief Print this stage's status, act and capacity to stdout. */
        void reportStatus() const override;

        /** @return Maximum audience capacity. */
        int getCapacity() const override;

        /**
         * @brief Set the act currently scheduled/performing on this stage.
         * @param act Name of the act.
         */
        void setAct(const std::string& act);

        /** @brief Pause the current performance. No-op with a message if not open. */
        void pause();

        /** @brief Resume a paused performance. No-op with a message if not paused. */
        void resume();

        /** @return true if the stage is currently paused. */
        bool isPaused() const;

        /**
         * @brief Reaction to a notice pushed from this stage's parent Composite.
         * @param n The notice received.
         */
        void update(Notice n) override;

        /**
         * @brief Broadcast a notice of this stage's own (e.g. STAGE_DOWN)
         * to whatever is attached to this stage's controller.
         * @param n Notice to broadcast.
         */
        void sendNotice(Notice n);
};