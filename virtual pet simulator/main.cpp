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

int main() 
{
    srand(static_cast<unsigned>(time(0))); // Seed random number generator
    Pet myPet;
    char userChoice;
    const int inventorySize = 3;
    Item inventory[inventorySize] = {{"Treat", 10}, {"Toy", 10}, {"Medicine", 20}}; // Sets a fixed amount of items in inventory
    cout << "Welcome to the Virtual Pet Simulator!" << endl;
    cout << "Would you like to load a saved game? (y/n):" << endl;
    cin >> userChoice;
    if (userChoice == 'y' || userChoice == 'Y') 
    {
        if (!loadGame(myPet, inventory, inventorySize)) {
            cout << "You have no saved games. Starting a new game." << endl;
            userChoice = 'n';
        }
    }
    else if (userChoice == 'n' || userChoice == 'N')
    {
        cout << "What would you like to name your pet: ";
        cin >> myPet.name;
        // Starting stats for pet attributes
        myPet.hunger = 50;
        myPet.happiness = 50;
        myPet.health = 50;
        myPet.energy = 50;
    }
    else
    {
        cin.clear();
        cout << "Invalid user input! please try again!" << endl;
        main();
    }
    // Main game loop
       while (true) {
           displayStatus(myPet);

           // Check for win/lose conditions
           if (myPet.health <= 0) 
           {
               cout << endl;
               cout << myPet.name << " has died. Game over!" << endl; // User loses if Pet dies when health reaches 0
               break;
           }
           if (myPet.happiness >= 100 && myPet.health >= 100) 
           {
               cout << endl;
               cout << myPet.name << " is very happy and healthy! You are a great owner, congratulations!!" << endl; // User wins if pet happiness and health reaches 100
               break;
           }
           performAction(myPet, inventory, inventorySize); // User interacts with pet
           decayAttributes(myPet); // Pet attributes continuously decay
           randomEvent(myPet); // Randomly generated events affect pet
       }

       return 0;
   }
