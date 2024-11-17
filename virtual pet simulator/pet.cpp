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
void displayStatus(const Pet &pet) {
    cout << "\n--- " << pet.name << "'s Status ---\n";
    cout << "Hunger: " << pet.hunger << "/100\n";
    cout << "Happiness: " << pet.happiness << "/100\n";
    cout << "Health: " << pet.health << "/100\n";
    cout << "Energy: " << pet.energy << "/100\n";
}

// function menu for performing actions with pet
void performAction(Pet &pet, Item inventory[], int inventorySize) {
    int choice;

    cout << "\nChoose an action:\n";
    cout << "1. Feed " << pet.name << "\n";
    cout << "2. Play with " << pet.name << "\n";
    cout << "3. Rest " << pet.name << "\n";
    cout << "4. Use inventory item\n";
    cout << "5. Save and exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            pet.hunger += 20;
            pet.energy -= 10;
            if (pet.hunger > 100) pet.hunger = 100;
            cout << pet.name << " feels less hungry.\n";
            break;
        case 2:
            pet.happiness += 20;
            pet.energy -= 15;
            if (pet.happiness > 100) pet.happiness = 100;
            cout << pet.name << " had fun playing!\n";
            break;
        case 3:
            pet.energy += 30;
            pet.health += 10;
            if (pet.energy > 100) pet.energy = 100;
            if (pet.health > 100) pet.health = 100;
            cout << pet.name << " feels rested.\n";
            break;
        case 4:
            cout << "\nInventory:\n";
            for (int i = 0; i < inventorySize; ++i) {
                cout << i + 1 << ". " << inventory[i].name << " (Effect: " << inventory[i].effect << ")\n";
            }
            cout << "Choose an item to use: ";
            cin >> choice;
            if (choice >= 1 && choice <= inventorySize) {
                Item &item = inventory[choice - 1];
                pet.hunger += item.effect; // Example: Feeding item reduces hunger
                if (pet.hunger > 100) pet.hunger = 100;
                cout << pet.name << " used " << item.name << "!\n";
            } else {
                cout << "Invalid choice.\n";
            }
            break;
        case 5:
            saveGame(pet, inventory, inventorySize);
            cout << "Game saved. Goodbye!\n";
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
    }
}

// Decay the pet's attributes over time
void decayAttributes(Pet &pet) {
    pet.hunger -= 5;
    pet.happiness -= 3;
    pet.energy -= 2;

    if (pet.hunger < 0) pet.hunger = 0;
    if (pet.happiness < 0) pet.happiness = 0;
    if (pet.hunger == 0 || pet.happiness == 0) pet.health -= 10;
}

// Trigger random events
void randomEvent(Pet &pet) {
    int event = rand() % 3;

    switch (event) {
        case 0:
            cout << pet.name << " caught a bug! " << pet.name << " gains happiness.\n";
            pet.happiness += 10;
            if (pet.happiness > 100) pet.happiness = 100;
            break;
        case 1:
            cout << pet.name << " caught a mild illness. Health decreases.\n";
            pet.health -= 10;
            break;
        case 2:
            cout << pet.name << " found a comfortable spot to rest. Energy increases.\n";
            pet.energy += 10;
            if (pet.energy > 100) pet.energy = 100;
            break;
        default:
            break;
    }
}

// Save the pet's current state to a file
void saveGame(const Pet &pet, const Item inventory[], int inventorySize) {
    ofstream saveFile("pet_save.txt");
    saveFile << pet.name << " " << pet.hunger << " " << pet.happiness << " "
             << pet.health << " " << pet.energy << "\n";
    for (int i = 0; i < inventorySize; ++i) {
        saveFile << inventory[i].name << " " << inventory[i].effect << "\n";
    }
    saveFile.close();
    cout << "Game saved successfully.\n";
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
        cout << "Game loaded successfully.\n";
        return true;
    }
    return false;
}

} // namespace PetSim
