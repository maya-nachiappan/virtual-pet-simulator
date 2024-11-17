//
//  main.cpp
//  virtual pet simulator
//
//  Created by maya nachiappan on 11/16/24.
//

#include "pet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace PetSim;

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    Pet myPet;
    char choice;
    const int inventorySize = 3;
    Item inventory[inventorySize] = {{"Treat", 15}, {"Toy", 20}, {"Medicine", 30}};

    cout << "Welcome to the Virtual Pet Simulator!\n";
    cout << "Would you like to load a saved game? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (!loadGame(myPet, inventory, inventorySize)) {
            cout << "No saved game found. Starting a new game.\n";
            choice = 'n';
        }
    }

    if (choice == 'n' || choice == 'N') {
        cout << "Enter a name for your pet: ";
        cin >> myPet.name;
        myPet.hunger = 50;
        myPet.happiness = 50;
        myPet.health = 50;
        myPet.energy = 50;
    }

    // Main game loop
    while (true) {
        displayStatus(myPet);

        // Check for win/lose conditions
        if (myPet.health <= 0) {
            cout << myPet.name << " has died. Game over!\n";
            break;
        }
        if (myPet.happiness >= 100 && myPet.health >= 100) {
            cout << myPet.name << " is thriving and incredibly happy! You win!\n";
            break;
        }

        performAction(myPet, inventory, inventorySize);
        decayAttributes(myPet);
        randomEvent(myPet);
    }

    return 0;
}
