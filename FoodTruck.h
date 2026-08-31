#pragma once
 
#include "EventComponent.h"
#include <string>
#include "EventObserver.h"
#include "Notice.hpp"

/**
 * @brief Mobile food service unit at the festival.
 *
 * Acts as a Leaf in the Composite tree and as an Observer that responds to
 * operational notices. Its location can change during the event.
 */
class FoodTruck : public EventComponent, public EventObserver {
    
   private:
   std::string location;
   int queueCapacity;

   public:
   /**
    * @brief Creates a food truck.
    * @param name Display name of the food truck.
    * @param location Initial operating location.
    * @param queueCapacity Maximum number of attendees allowed in the queue.
    */
   explicit FoodTruck(const std::string& name, const std::string& location, int queueCapacity);

   /** @brief Destroys the food truck. */
   ~FoodTruck() override;

   /** @brief Opens the food truck for service. */
   void open() override;

   /** @brief Closes the food truck. */
   void close() override;

   /** @brief Prints the food truck's current status and location. */
   void reportStatus() const override;

   /**
    * @brief Gets the maximum queue capacity.
    * @return Maximum number of attendees allowed in the queue.
    */
   int getCapacity() const override;

   /**
    * @brief Moves the food truck to a new location.
    * @param newLocation New operating location.
    */
   void relocate(const std::string& newLocation);

   /**
    * @brief Gets the food truck's current operating location.
    * @return Current location of the food truck.
    */
   std::string getLocation() const;

   /**
    * @brief Reacts to a notice sent by a registered subject.
    * @param n Notice received by this food truck.
    */
   void update(Notice n) override;
    
};