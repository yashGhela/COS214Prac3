#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "Notice.hpp"
#include "ComponentController.h"

/**
 * @brief Composite event area within a festival venue.
 *
 * A Zone owns child event components and uses its ComponentController to
 * distribute notices to observers registered for that zone.
 */
class Zone : public EventComponent{
    
   private:
   std::vector<EventComponent*> children;
   int ratedCapacity;
   ComponentController controller;

   public:
   /**
    * @brief Creates a zone.
    * @param name Display name of the zone.
    * @param ratedCapacity Maximum permitted capacity of the zone.
    */
   explicit Zone(const std::string& name, int ratedCapacity);

   /**
    * @brief Destroys the zone and its owned child components.
    */
   ~Zone() override;

   /**
    * @brief Adds a child component to this zone.
    * @param child Component to add to the zone's Composite tree.
    */
   void add(EventComponent* child) override;

   /**
    * @brief Removes a child component from this zone.
    * @param child Component to remove.
    */
   void remove(EventComponent* child) override;

   /**
    * @brief Gets a child component at a given index.
    * @param index Index of the requested child.
    * @return Pointer to the child component, or nullptr if the index is invalid.
    */
   EventComponent* getChild(int index) const override;

   /** @brief Opens the zone. */
   void open() override;

   /** @brief Closes the zone. */
   void close() override;

   /** @brief Prints the zone's current operational status. */
   void reportStatus() const override;

   /**
    * @brief Gets the zone's rated capacity.
    * @return Maximum number of attendees permitted in the zone.
    */
   int getCapacity() const override;

   /**
    * @brief Gets the number of child components contained in this zone.
    * @return Number of children.
    */
   int childCount() const;

   /**
    * @brief Sends a notice to observers registered with this zone.
    * @param n Notice to broadcast.
    */
   void sendNotice(Notice n);

   /**
    * @brief Registers an observer to receive future notices broadcast
    * by this zone's controller. Delegates to the controller's attach().
    * @param o Observer to register. Non-owning.
    */
   void attachObserver(Observer* o);

   /**
    * @brief Deregisters an observer from this zone's controller.
    * @param o Observer to remove.
    */
   void detachObserver(Observer* o);

   /**
    * @brief Transfers a leaf from this zone to another Composite.
    * @param newComp Destination component that will receive the leaf.
    * @param leaf Leaf component to transfer.
    */
   void transfer(EventComponent* newComp, EventComponent* leaf);
  
};