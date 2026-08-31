#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

/**
 * @brief Medical support unit for the film festival.
 *
 * Acts as a Leaf in the Composite tree and as an Observer. It remains
 * operational in emergency mode during safety-related notices.
 */
class Medical : public EventComponent, public EventObserver {
    
   private:
   int staffCount;
   static const int PATIENTS_PER_STAFF = 2;
   bool openForPatients;
   bool emergencyMode;

   public:
   /**
    * @brief Creates a medical support unit.
    * @param name Display name of the medical unit.
    * @param staffCount Number of medical staff members available.
    */
   explicit Medical(const std::string& name, int staffCount);

   /** @brief Destroys the medical support unit. */
   ~Medical() override;

   /** @brief Opens the medical unit for patients. */
   void open() override;

   /** @brief Closes the medical unit when it is not in emergency mode. */
   void close() override;

   /** @brief Prints the medical unit's current operational status. */
   void reportStatus() const override;

   /**
    * @brief Gets the maximum patient capacity of the medical unit.
    * @return Number of patients that can be supported.
    */
   int getCapacity() const override;

   /**
    * @brief Reacts to an operational or emergency event notice.
    * @param n Notice received by this medical unit.
    */
   void update(Notice n) override;
};