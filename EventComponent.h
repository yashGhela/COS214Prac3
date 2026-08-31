#pragma once
#include <string>

/**
 * @brief Abstract Component in the EventFlow Composite hierarchy.
 *
 * GoF role: Component. Every Leaf (Stage, Screen, Bathroom, ...) and every
 * Composite (Zone, ProgrammeArea, Venue, ...) derives from this class, so
 * client code can call open()/close()/reportStatus()/getCapacity() without
 * knowing whether it holds a single unit or an entire subtree.
 *
 * @note Design decision: addAmenity(), remove() and getChild() are given
 * safe default (no-op / nullptr) implementations here rather than being
 * pure virtual. This means a Leaf does not need to implement tree-management
 * logic it will never use; only Composite subclasses override them
 * meaningfully. The trade-off is that calling addAmenity() on a Leaf fails
 * silently (with a printed message) rather than at compile time.
 */
class EventComponent {
    protected:
        std::string name;
        std::string status;

    public:
        /**
         * @brief Construct a component with a display name.
         * @param name Human-readable name shown in status reports.
         */
        explicit EventComponent(const std::string& name);

        /** @brief Virtual destructor; every polymorphic base needs one. */
        virtual ~EventComponent();

        /** @brief Open this component for operation. */
        virtual void open() = 0;

        /** @brief Close this component. */
        virtual void close() = 0;

        /** @brief Print this component's current status to stdout. */
        virtual void reportStatus() const = 0;

        /** @return This component's capacity (meaning depends on the concrete type). */
        virtual int getCapacity() const = 0;

        /**
         * @brief Add a child component. Default: no-op (Leaves have no children).
         * @param child Component to add. Ownership rules are defined by the
         * overriding Composite subclass, not by this base default.
         */
        virtual void addAmenity(EventComponent* child);

        /**
         * @brief Remove a child component. Default: no-op (Leaves have no children).
         * @param child Component to remove.
         */
        virtual void remove(EventComponent* child);

        /**
         * @brief Access a child by index. Default: always nullptr (Leaves have no children).
         * @param index Index of the child to retrieve.
         * @return Pointer to the child, or nullptr if out of range / not a Composite.
         */
        virtual EventComponent* getChild(int index) const;

        /**
         * @brief Set this component's status string (e.g. "open", "closed").
         * @param s New status value.
         */
        void setStatus(const std::string& s);

        /** @return The current status string. */
        std::string getStatus() const;

        /** @return This component's display name. */
        std::string getName() const;
};