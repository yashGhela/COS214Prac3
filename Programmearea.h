#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "ComponentController.h"
#include "Notice.hpp"
#include "EventObserver.h"

/**
 * @brief Composite area containing scheduled talks, speakers, and activities.
 *
 * Acts as a Composite in the event tree and as an Observer. Its
 * ComponentController allows it to forward notices to registered observers.
 */
class ProgrammeArea : public EventComponent, public EventObserver{
   private:
   std::vector<EventComponent*> children;
   ComponentController controller;
   int maxcapacity;

   public:
   /**
    * @brief Creates a programme area.
    * @param name Display name of the programme area.
    * @param maxcap Maximum capacity of the programme area.
    */
   explicit ProgrammeArea(const std::string& name, int maxcap);

   /**
    * @brief Destroys the programme area and its owned child components.
    */
   ~ProgrammeArea() override;

   /**
    * @brief Adds a child component to this programme area.
    * @param child Component to add to the Composite tree.
    */
   void add(EventComponent* child) override;

   /**
    * @brief Removes a child component from this programme area.
    * @param child Component to remove.
    */
   void remove(EventComponent* child) override;

   /**
    * @brief Gets a child component at a given index.
    * @param index Index of the requested child.
    * @return Pointer to the child component, or nullptr if the index is invalid.
    */
   EventComponent* getChild(int index) const override;

   /** @brief Opens this programme area and its scheduled operations. */
   void open() override;

   /** @brief Closes this programme area and its scheduled operations. */
   void close() override;

   /** @brief Prints this programme area's status and child information. */
   void reportStatus() const override;

   /**
    * @brief Gets this programme area's capacity.
    * @return Maximum capacity of the programme area.
    */
   int getCapacity() const override;

   /**
    * @brief Gets the number of child components in this programme area.
    * @return Number of children.
    */
   int childCount() const;

   /**
    * @brief Sends a notice to observers registered with this programme area.
    * @param n Notice to broadcast.
    */
   void sendNotice(Notice n);

   /**
    * @brief Transfers a leaf from this Composite to another Composite.
    * @param newComp Destination component that will receive the leaf.
    * @param leaf Leaf component to transfer.
    */
   void transfer(EventComponent* newComp, EventComponent* leaf);

   /**
    * @brief Reacts to a notice received from a parent subject.
    * @param n Notice received by this programme area.
    */
   void update(Notice n) override;
};
