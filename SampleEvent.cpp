#include "SampleEvent.h"

void runEvent()
{

    Venue* venue = new Venue("City Lights Festival", 5000);
 
    Zone* mainStageZone = new Zone("Main Stage Zone", 2000);
    Zone* familyZone     = new Zone("Family Zone", 800);
 
    ProgrammeArea* stagePrecinct  = new ProgrammeArea("Main Stage Precinct");
    ProgrammeArea* foodPrecinct   = new ProgrammeArea("Food Court");
    ProgrammeArea* cinemaPrecinct = new ProgrammeArea("Cinema Precinct");
 
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
 
    std::cout << "--- Built event tree ---\n";
    venue->reportStatus();
 
    std::cout << "\n--- Destroying root (\"venue\") ---\n";
    delete venue;
    std::cout << "Root destroyed. Entire owned subtree released.\n";

}