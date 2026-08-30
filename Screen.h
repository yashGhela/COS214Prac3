#pragma once

#include "EventComponent.h"
#include "EventObserver.h"
#include "ComponentController.h"
#include "Notice.hpp"
#include <string>

/**
 * @brief A screening room.
 *
 * GoF roles: Leaf (Component) in the Composite tree, and Observer (reacts
 * to notices pushed down from its parent Composite). It also holds its own
 * ComponentController and so acts as a Subject-by-composition for anything
 * that wants to observe this specific screen.
 *
 * @note See Stage.h for the design-decision note on why composition
 * (a ComponentController member) was chosen over inheriting Subject
 * directly -- the same reasoning applies here.
 */
class Screen : public EventComponent, public EventObserver {
    private:
        int seatCapacity;
        std::string nowShowing;
        ComponentController controller;

    public:
        /**
         * @brief Construct a screen.
         * @param name Display name.
         * @param seatCapacity Maximum seating capacity.
         */
        explicit Screen(const std::string& name, int seatCapacity);

        /** @brief Destructor. */
        ~Screen() override;

        /** @brief Open the screen. Fails with a message if no film is assigned. */
        void open() override;

        /** @brief Close the screen. */
        void close() override;

        /** @brief Print this screen's status, current film and seat count to stdout. */
        void reportStatus() const override;

        /** @return Maximum seat capacity. */
        int getCapacity() const override;

        /**
         * @brief Assign the film currently showing on this screen.
         * @param title Title of the film.
         */
        void setFilm(const std::string& title);

        /**
         * @brief Reaction to a notice pushed from this screen's parent Composite.
         * @param n The notice received.
         */
        void update(Notice n) override;

        /**
         * @brief Broadcast a notice of this screen's own (e.g. SCREEN_DOWN)
         * to whatever is attached to this screen's controller.
         * @param n Notice to broadcast.
         */
        void sendNotice(Notice n);
};