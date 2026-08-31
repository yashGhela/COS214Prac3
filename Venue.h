#pragma once
 
#include "EventComponent.h"
#include <vector>
#include "Notice.hpp"
#include "ComponentController.h"
#include "EventObserver.h"

/**
 * @brief Composite representing a festival venue containing event areas.
 *
 * Acts as a Composite in the event tree, an Observer of higher-level notices,
 * and a Subject-by-composition through its ComponentController.
 */
class Venue : public EventComponent, public EventObserver{
    
   private:
   std::vector<EventComponent*> children;
   int licenseCapacity;
   ComponentController controller;
   bool openForVisitors;

   public:
   /**
    * @brief Creates a venue.
    * @param name Display name of the venue.
    * @param licenseCapacity Maximum capacity permitted by the venue licence.
    */
   explicit Venue(const std::string& name, int licenseCapacity);

   /**
    * @brief Destroys the venue and its owned child components.
    */
   ~Venue() override;

   /**
    * @brief Adds a child component to this venue.
    * @param child Component to add to the venue's Composite tree.
    */
   void add(EventComponent* child) override;

   /**
    * @brief Removes a child component from this venue.
    * @param child Component to remove.
    */
   void remove(EventComponent* child) override;

   /**
    * @brief Transfers a leaf from this venue to another Composite.
    * @param newComp Destination component that will receive the leaf.
    * @param leaf Leaf component to transfer.
    */
   void transfer(EventComponent* newComp, EventComponent* leaf);

   /**
    * @brief Gets a child component at a given index.
    * @param index Index of the requested child.
    * @return Pointer to the child component, or nullptr if the index is invalid.
    */
   EventComponent* getChild(int index) const override;

   /** @brief Opens the venue for visitors. */
   void open() override;

   /** @brief Closes the venue to visitors. */
   void close() override;

   /** @brief Prints the venue's current status and capacity information. */
   void reportStatus() const override;

   /**
    * @brief Gets the venue's licensed capacity.
    * @return Maximum number of attendees permitted in the venue.
    */
   int getCapacity() const override;

   /**
    * @brief Gets the number of child components contained in the venue.
    * @return Number of children.
    */
   int childCount() const;

   /**
    * @brief Sends a notice to observers registered with this venue.
    * @param n Notice to broadcast.
    */
   void sendNotice(Notice n);

   /**
    * @brief Reacts to a notice received from a parent subject.
    * @param n Notice received by this venue.
    */
   void update(Notice n) override;
    
};
