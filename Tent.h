#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

/**
 * @brief Festival tent used for an event activity or service.
 *
 * Acts as a Leaf in the Composite tree and as an Observer that responds to
 * notices from its parent event area.
 */
class Tent : public EventComponent, public EventObserver {
    
   private:
   int seatingCapacity;

   public:
   /**
    * @brief Creates a festival tent.
    * @param name Display name of the tent.
    * @param seatingCapacity Maximum number of attendees the tent can hold.
    */
   explicit Tent(const std::string& name, int seatingCapacity);

   /** @brief Destroys the festival tent. */
   ~Tent() override;

   /** @brief Opens the tent for attendees. */
   void open() override;

   /** @brief Closes the tent. */
   void close() override;

   /** @brief Prints the tent's current operational status. */
   void reportStatus() const override;

   /**
    * @brief Gets the maximum seating capacity of the tent.
    * @return Number of attendees the tent can accommodate.
    */
   int getCapacity() const override;

   /**
    * @brief Reacts to a notice sent by a registered subject.
    * @param n Notice received by this tent.
    */
   void update(Notice n) override;

};