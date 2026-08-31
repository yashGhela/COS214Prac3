#include "EventComponent.h"
#include "Venue.h"
#include "Zone.h"
#include "ProgrammeArea.h"
#include "Bathroom.h"
#include "Stage.h"
#include "FoodTruck.h"
#include "Screen.h"
#include "PopCorn.h"
#include "Medical.h"
#include "Tent.h"
#include "Notice.hpp"
#include <iostream>

static void section(const std::string& title) {
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main() {
    section("1. Building the event (Composite construction)");

    Venue* venue = new Venue("City Lights Festival", 5000);

    Zone* mainStageZone = new Zone("Main Stage Zone", 2000);
    Zone* familyZone     = new Zone("Family Zone", 800);

    ProgrammeArea* stagePrecinct  = new ProgrammeArea("Main Stage Precinct", 1600);
    ProgrammeArea* foodPrecinct   = new ProgrammeArea("Food Court", 300);
    ProgrammeArea* cinemaPrecinct = new ProgrammeArea("Cinema Precinct", 250);

    Stage*     mainStage    = new Stage("Main Stage", 1500);
    Bathroom*  bathroom1    = new Bathroom("Main Stage Bathroom", 10);
    Medical*   medical1     = new Medical("Main Stage Medical", 3);
    FoodTruck* taco         = new FoodTruck("Taco Truck", "Main Stage Zone", 20);
    PopCorn*   popcorn      = new PopCorn("Popcorn Stand", 200);
    Screen*    screen1      = new Screen("Screen 1", 120);
    Tent*      workshopTent = new Tent("Workshop Tent", 80);

    mainStage->setAct("The Night Owls");
    screen1->setFilm("North by Northwest");

    stagePrecinct->add(mainStage);
    stagePrecinct->add(bathroom1);
    stagePrecinct->add(medical1);

    foodPrecinct->add(taco);
    foodPrecinct->add(popcorn);

    cinemaPrecinct->add(screen1);
    cinemaPrecinct->add(workshopTent);

    mainStageZone->add(stagePrecinct);
    mainStageZone->add(foodPrecinct);

    familyZone->add(cinemaPrecinct);

    venue->add(mainStageZone);
    venue->add(familyZone);

    venue->reportStatus();

    section("2. Registering observers");

    venue->attachObserver(stagePrecinct);
    std::cout << "Venue is now observing Main Stage Precinct." << std::endl;

    stagePrecinct->attachObserver(bathroom1);
    stagePrecinct->attachObserver(medical1);
    std::cout << "Main Stage Precinct is now observing its Bathroom and Medical unit." << std::endl;

    mainStage->attachObserver(stagePrecinct);
    std::cout << "Main Stage Precinct is now also observing Main Stage directly." << std::endl;

    screen1->attachObserver(venue);
    std::cout << "Venue is now observing Screen 1." << std::endl;

    venue->attachObserver(stagePrecinct);

    section("Opening the venue");
    venue->open();

    section("3/4. Weather alert cascading through the tree (RAIN_ALERT)");
    venue->sendNotice(Notice::RAIN_ALERT);

    section("Weather clears (CLEAR_WEATHER) - same cascade path, opposite effect");
    venue->sendNotice(Notice::CLEAR_WEATHER);

    section("Equipment fault escalates (STAGE_DOWN)");
    mainStage->sendNotice(Notice::STAGE_DOWN);

    section("5. Registration change: detaching Medical from Main Stage Precinct");
    stagePrecinct->detachObserver(medical1);
    std::cout << "Medical no longer observes Main Stage Precinct; it will not react to the next notice." << std::endl;

    section("Resuming operation (RESUMING_OPERATION) after detach");
    mainStage->open();
    venue->sendNotice(Notice::RESUMING_OPERATION);

    section("A screen fault (SCREEN_DOWN) reaching the Venue directly");
    screen1->sendNotice(Notice::SCREEN_DOWN);
    venue->open();

    section("6. Composite traversal: listing Main Stage Zone's direct children");
    std::cout << "Main Stage Zone has " << mainStageZone->childCount() << " direct children:" << std::endl;
    for (int i = 0; i < mainStageZone->childCount(); i++) {
        EventComponent* child = mainStageZone->getChild(i);
        if (child != nullptr) {
            std::cout << "  [" << i << "] " << child->getName()
                      << " (capacity " << child->getCapacity() << ")" << std::endl;
        }
    }
    mainStageZone->getChild(99);

    section("7. Runtime reorganisation: moving the Taco Truck to the Cinema Precinct");
    taco->relocate("Family Zone - Cinema Precinct");
    foodPrecinct->transfer(cinemaPrecinct, taco);
    std::cout << "Food Court now has " << foodPrecinct->childCount() << " child(ren)." << std::endl;
    std::cout << "Cinema Precinct now has " << cinemaPrecinct->childCount() << " child(ren)." << std::endl;

    section("8. Clean shutdown");
    venue->close();

    std::cout << "\nDestroying root (\"venue\")." << std::endl;
    delete venue;
    std::cout << "Root destroyed. Simulation complete." << std::endl;

    return 0;
}
