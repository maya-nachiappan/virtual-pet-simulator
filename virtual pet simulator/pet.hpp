//
//  pet.hpp
//  virtual pet simulator
//
//  Created by maya nachiappan on 11/16/24.
//

#ifndef pet_hpp
#define pet_hpp

#include <stdio.h>
#include <string>
using namespace std;

namespace PetSim {

// Pet structure
struct Pet {
    string name;
    int hunger;
    int happiness;
    int health;
    int energy;
};

// Item structure for inventory
struct Item {
    string name;
    int effect; // The effect of the item on an attribute (e.g., hunger, happiness)
};

// Function prototypes
void displayStatus(const Pet &pet);
void performAction(Pet &pet, Item inventory[], int inventorySize);
void decayAttributes(Pet &pet);
void randomEvent(Pet &pet);
void saveGame(const Pet &pet, const Item inventory[], int inventorySize);
bool loadGame(Pet &pet, Item inventory[], int inventorySize);

} // namespace PetSim

#endif /* pet_hpp */
