# VIRTUAL PET SIMULATOR GAME

## Overview

Welcome to the Virtual pet simulator game! This game allows players to take care of their very own virtual pet by letting them manage its health, hunger and happiness! Players can interact with the pet by feeding them, letting them rest or playing with them!


## Table of Contents

- [Features](#Features)
- [Gameplay](#Gameplay)
- [Installation](#Installation)
- [Demo](#demo)
- [License](https://github.com/maya-nachiappan/virtual-pet-simulator/blob/main/LICENSE)

  
## Features
 - Pet Management: Track the pet's hunger, happiness, health, and energy levels throughout the game after each action.
 - Inventory System: The player can use items like treats and toys, as well as medicine if the pet randomly falls sick.
 - Random Events: Randomly generated events can alter the health or happiness of the pet.
 - Save/Load: Save your progress with your pet and continue any time later!
 - Win/Loss Conditions: The player wins if the happiness reaches 100% and loses if the pet dies.

## Gameplay

1. Start a new game or load a saved game; if there are no saved games, a new game will be started for you.
   
2. Perform actions to manage your individual pet’s needs:
   - Feed: Reduce hunger.
   - Play: Increase happiness.
   - Rest: Restore energy.
   - Use Inventory: Apply items to increase the health, happiness or energy of your pet.
     
3. Display and check on the pet's status to monitor:
   - Hunger
   - Happiness
   - Health
   - Energy
(make sure not to let the levels drop! pet attributes will decay!)

4. Win the game by keeping your pet happy and healthy the entire time and reaching maximum happiness


## Installation

1. Clone the repository:
- git clone https://github.com/maya-nachiappan/virtual-pet-simulator.git
- cd virtual-pet-simulator

2. Compile the program:
- g++ -c pet.cpp -o pet.o
- g++ -c main.cpp -o main.o
- g++ pet.o main.o -o virtual_pet_simulator

3. Run the game:
- ./virtual_pet_simulator

4. Enjoy the simulator!!


## Demo
<img width="1470" alt="Screenshot 2024-11-17 at 11 04 12 PM" src="https://github.com/user-attachments/assets/f6fafdc8-f887-48fe-9c43-6a0a4a71d7ad">
[Watch the explanation here](https://drive.google.com/file/d/1OAtNK4HVuCBJCjskTGN3G3BaTwqZ6Z-i/view?usp=sharing)
