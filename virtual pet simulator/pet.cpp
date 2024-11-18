//
//  pet.cpp
//  virtual pet simulator
//
//  Created by maya nachiappan on 11/16/24.
//

#include "pet.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

namespace PetSim {

// Displays the status of each pet factor
void displayStatus(const Pet &pet) 
{
    cout << endl;
    cout << "--- " << pet.name << "'s Status ---" << endl;
    cout << "Hunger: " << pet.hunger << endl;
    cout << "Happiness: " << pet.happiness << endl;
    cout << "Health: " << pet.health << endl;
    cout << "Energy: " << pet.energy << endl;
}

// function menu for performing actions with pet
void performAction(Pet &pet, Item inventory[], int inventorySize) {
    int choice;
    cout << endl;
    cout << "Choose an action to perform:" << endl;
    cout << "1. Feed " << pet.name << endl;
    cout << "2. Play with " << pet.name << endl;
    cout << "3. Rest " << pet.name << endl;
    cout << "4. Use an inventory item" << endl;
    cout << "5. Save and exit game" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice) 
    {
        case 1:
            pet.hunger += 20;
            pet.energy -= 5;
            if (pet.hunger > 100) pet.hunger = 100;
            cout << pet.name << " feels quite full and not hungry anymore!" << endl;
            break;
        case 2:
            pet.happiness += 20;
            pet.energy -= 10;
            if (pet.happiness > 100) pet.happiness = 100;
            cout << pet.name << " had so much fun playing games with you!! good job!" << endl;
            break;
        case 3:
            pet.energy += 25;
            pet.health += 10;
            if (pet.energy > 100) pet.energy = 100;
            if (pet.health > 100) pet.health = 100;
            cout << pet.name << " had a nice nap and feels well rested!" << endl;
            break;
        case 4:
            cout << "--- Inventory ---" << endl;
            for (int i = 0; i < inventorySize; ++i)
            {
                cout << i + 1 << ". " << inventory[i].name << " (Effect: " << inventory[i].effect << ")" << endl;;
            }
            cout << "Choose an item to use: ";
            cin >> choice;
            if (choice >= 1 && choice <= 3)
            {
                Item &item = inventory[choice - 1]; // Reduces inventory after usage
                if (choice==1) // user choose treat
                {
                    pet.hunger += item.effect; // item reduces hunger
                }
                else if (choice ==2)
                {
                    pet.happiness += item.effect; // playing with toy increases happiness
                }
                else
                {
                    pet.health += item.effect; // medicine increases health
                }
                cout << pet.name << " used " << item.name << "!" << endl;
            }
            else
            {
                cout << "Invalid inventory choice." << endl;
            }
            break;
        case 5:
            saveGame(pet, inventory, inventorySize);
            cout << "Game saved. Goodbye!" << endl;
            exit(0);
        default:
            cin.clear();
            cout << "Invalid menu choice."<< endl;
            exit(0);
            
    }
}

// Decay the pet's attributes over time
void decayAttributes(Pet &pet) 
{
    pet.hunger -= 5;
    pet.happiness -= 3;
    pet.energy -= 2;
    
    // hunger and health cannot be negative, only empty
    if (pet.hunger < 0) pet.hunger = 0;
    if (pet.happiness < 0) pet.happiness = 0;
    if (pet.hunger == 0 || pet.happiness == 0) pet.health -= 10; // health decays if both hunger and happiness have decayed
}

// Trigger random events
void randomEvent(Pet &pet) 
{
    int event = rand() % 3;

    switch (event) 
    {
        case 0:
            cout << endl;
            cout << pet.name << " caught an squirrel! " << pet.name << " gains happiness." << endl;
            pet.happiness += 10;
            if (pet.happiness > 100) pet.happiness = 100;
            break;
        case 1:
            cout << endl;
            cout << pet.name << " caught a mild illness and feels sick. " << pet.name<< "'s health has decreased" << endl;
            pet.health -= 10;
            break;
        case 2:
            cout << endl;
            cout << pet.name << " found a comfortable spot to rest in the sun. " <<pet.name <<"'s energy and happiness has increased." << endl;
            pet.energy += 10;
            pet.happiness +=10;
            if (pet.energy > 100) pet.energy = 100;
            if (pet.happiness >100) pet.happiness = 100;
            break;
        default:
            cin.clear();
            break;
    }
}

// function to save the pet's current state to a local file
void saveGame(const Pet &pet, const Item inventory[], int inventorySize)
{
    ofstream saveFile("pet_save.txt");
    saveFile << pet.name << " " << pet.hunger << " " << pet.happiness << " "
             << pet.health << " " << pet.energy << endl; // saves all status of pet attributes
    for (int i = 0; i < inventorySize; ++i) 
    {
        saveFile << inventory[i].name << " " << inventory[i].effect << endl;
    }
    saveFile.close(); // closes file
    cout << endl;
    cout << "Game saved successfully. Come back to play with "<< pet.name<<" soon!" << endl;
}

// Load the pet's state from a file
bool loadGame(Pet &pet, Item inventory[], int inventorySize) {
    ifstream loadFile("pet_save.txt");
    if (loadFile) {
        loadFile >> pet.name >> pet.hunger >> pet.happiness >> pet.health >> pet.energy;
        for (int i = 0; i < inventorySize; ++i) {
            loadFile >> inventory[i].name >> inventory[i].effect;
        }
        loadFile.close();
        cout << endl;
        cout << "Game loaded successfully!" << endl;
        return true;
    }
    return false;
}

} // namespace PetSim
