#pragma once
 
#include "EventComponent.h"
#include <string>
#include "Notice.hpp"
#include "EventObserver.h"

/**
 * @brief Popcorn service unit at the film festival.
 *
 * Acts as a Leaf in the Composite tree and receives event notices as an
 * Observer. It tracks the number of popcorn bags currently in stock.
 */
class PopCorn : public EventComponent, public EventObserver {
    
   private:
   int stockBags;

   public:
   /**
    * @brief Creates a popcorn service unit.
    * @param name Display name of the popcorn unit.
    * @param stockBags Initial number of popcorn bags in stock.
    */
   explicit PopCorn(const std::string& name, int stockBags);

   /** @brief Destroys the popcorn service unit. */
   ~PopCorn() override;

   /** @brief Opens the popcorn service unit. */
   void open() override;

   /** @brief Closes the popcorn service unit. */
   void close() override;

   /** @brief Prints the current popcorn unit status. */
   void reportStatus() const override;

   /**
    * @brief Gets the current popcorn stock capacity.
    * @return Number of popcorn bags currently available.
    */
   int getCapacity() const override;

   /** @brief Serves one bag of popcorn if stock is available. */
   void serve();

   /**
    * @brief Adds popcorn bags to the available stock.
    * @param bags Number of bags to add.
    */
   void restock(int bags);

   /**
    * @brief Reacts to a notice sent by a registered subject.
    * @param n Notice received by this popcorn unit.
    */
   void update(Notice n);

};