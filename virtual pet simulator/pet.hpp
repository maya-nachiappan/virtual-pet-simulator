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

// Functions
void displayStatus(const Pet &pet); // displays all pet attribute statuses
void performAction(Pet &pet, Item inventory[], int inventorySize); // displays action menu for user
void decayAttributes(Pet &pet); // decays pet attributes after every action
void randomEvent(Pet &pet); // randomly generates pet event
void saveGame(const Pet &pet, const Item inventory[], int inventorySize); // saves game file
bool loadGame(Pet &pet, Item inventory[], int inventorySize); // loads game file

} // namespace PetSim

#endif /* pet_hpp */
