#include <iostream>
#include <fstream>
#include <iomanip> 

#include "Armor.h" // Class used to store, modify, and upgrade armor objects
#include "User.h" // Class used to store and modify items in the inventory
#include "Potion.h" // Class used to create and randomize opponents faced
#include "Weapon.h" // Class used to store, modify, and upgrade weapon objects
#include "Map.h" // Class used to view and modify the ship map
#include "Opponent.h" // Class used to store, modify, and create opponents

using namespace std;

/**
 * INSTRUCTIONS CAN ALSO BE FOUND IN readMe.md
 * 
 * To compile this file use:
 * 1. g++ -std=c++14 The_Tournament.cpp Weapon.cpp User.cpp Armor.cpp Potion.cpp Map.cpp Opponent.cpp
 * 2. ./a.out
*/

// FUNCTION DECLARATIONS

// FORMATTING FUNCTIONS
void menuDivider(); // Function to help format game areas
void storeDivider(); // Function to help format store menus in game

// GENERATE RANDOM NUMBER
int generate_random_number(int min, int max); // Function used to generate a random number between a min and max

// PROMPTS TO USER
void game_boot_prompt(Weapon equipped_weapons[], User& Player); //Function to present new game menu to menu

// GAME MENUS
void tournament_hub_menu(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player); // Called to bring user to main tournament navigation
void shopMenu(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player); // Called to bring up shop menu
void shipMenu(Map map, Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player); // Called to bringup ship map and menu

// GENERATE RANDOM WEAPON
string generate_weapon_name(); // Returns a random name from weapons name list
int generate_weapon_base_damage(int level); // Return a random value based on level to detrmine base damage
int generate_weapon_max_damage(int base_damage); // Return a random value based on base damage to decide max damage value
int generate_weapon_cost(int base_damage, int max_damage); // Return a weapon cost based on damage to determine cost

//GENERATE RANDOM ARMOR

//HELMET
string generate_helmet_name(); // Returns a random name from helmet name list
int generate_helmet_health(int level); // Return a random value based on level for helmet health value
int generate_helmet_cost(int health); // Return a helmet cost based on damage value

// CHEST PIECE GENERATION
string generate_chest_name(); // Returns a random name from chest plate name list
int generate_chest_health(int level); // Return a random value based on level for chest health value
int generate_chest_cost(int health); // Return a chest cost based on damage value

// BOOTS GENERATION
string generate_boots_name(); // Returns a random name from boots name list
int generate_boots_health(int level); // Return a random value based on level for boots health value
int generate_boots_cost(int health); // Return a boots cost based on damage value

// GENERATE RANDOM OPPONENT
string generate_opponent_name(); // Returns a random name from the opponent name list
string generate_opponent_backstory(); // Returns a random backstory from the opponent backstory list
string generate_opponent_attack_name(); // Returns a random attack type from the attack list
int generate_opponent_level(int level); // Returns a random value to be opponent level will be within 2 of user

// DISPLAY STATS
void displayPlayerStats(User Player); // Function to display current player stats
void displayWeaponStats(int input, Weapon equipped_weapons[]); // Call to display stats of currently equiiped weapons
void displayArmorStats(int input, Armor equipped_armor[]); //Function to display all armor stats
void displayPotions(int input, Potion equipped_potions[]); //Function to display all potion stats
void showAllGear(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[]); // Call to display all gear

// EXIT PROGRAM
int exit(); // Called to exit the program

// MAIN PROGRAM
int main()
{   
    srand(time(0)); // Seed random number based on clock

    // Variables to store values used through the game
    string username; // Variable to store menus chosen name
    int level = 1;
    int xp_points = 0;
    int credits = 500;
    Weapon equipped_weapons[2]; // Inventory spots for two weapons
    Armor equipped_armor[3]; // Inventory slots for each piece of gear
    Potion equipped_potions[5]; // Inventory slots to hold 5 potions
    User Player = User(username, level, credits, equipped_weapons, equipped_armor, equipped_potions);

    // Ask user if they would like to load or create a game
    int menuInput; // Variable to store user's menu inputs

    game_boot_prompt(equipped_weapons, Player);
    tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);

}

// FUNCTION BODIES

// FORMATTING FUNCTIONS 
void menuDivider() // Creates Visual Divider When Called
{
    cout << endl << setfill('-') << setw(5) << "" << setfill('*') << setw(10) << "" << setfill('-') << setw(15) << "" << setfill('*') << setw(10) << "" << setfill('-') << setw(15) << "" << setfill('*') << setw(10) << "" << setfill('-') << setw(5) << "" << endl << endl;
    // Line Width = 70
}
void storeDivider() // Creates Visual Divider In Shop When Called
{
    cout << endl << setfill('*') << setw(45) << "" << endl << endl;
}

// GENERATE RANDOM NUMBER
int generate_random_number(int min, int max) // Generates a random number
{
    return (rand() % (max - min + 1)) + min;
}

// BOOT UP PROMPTS

void game_boot_prompt(Weapon equipped_weapons[], User& Player) // If new game this outputs the story and gives user starting gear
{
    string username;

    menuDivider();
    cout << "WELCOME TO THE TOURNAMENT!" << endl;
    menuDivider();

    cout
    << "Ladies and gentlemen, welcome to the ultimate test of strength, skill, and strategy in the galaxy! It is my pleasure to introduce to you the Intergalactic Tournament, hosted here on the fierce and unforgiving Planet Kumite." << endl << endl
    << "To all the warriors who have journeyed from far and wide, seeking glory and honor in combat, we extend the most gratuitous hand. You have come to prove your mettle in the most brutal and unforgiving of arenas, where only the strongest will survive." << endl << endl
    << "For centuries, this tournament has drawn the greatest fighters from across the stars, pitting them against each other in a no-holds-barred battle for supremacy. The stakes are high, the competition is fierce, and the rewards are legendary." << endl << endl
    << "So, buckle up and get ready for the ride of your life as we witness the most epic battles ever seen in the history of the universe. May the best fighter win, and may the journey of each traveler here be one of unforgettable valor and glory!"
    << endl;
    
    menuDivider();
    cout << "INTRODUCE YOURSELF" << endl;
    menuDivider();
    // Ask menu to enter their name
    
    cout << "Welcome, fighter, to the Intergalactic Tournament. Under what name are you booked into the tournament?" << endl << endl;
    cout << "Name: "; cin >> username; cout << endl;
    Player.setUserName(username);

    cout << "Give me just one moment to look that up... " << endl;
    cout << "... " << endl << "....... " << endl << "... " << endl << endl << "Still looking... " << "one more moment... " << endl << "....... " << endl << "...!" << endl << endl << "Aha!" << endl << endl;
    cout << "There it is!" << endl << endl; 
   
    cout << "I've got one booking for " << username << " into the tournament.It appears this is your first visit to Planet Kumite. Please enjoy your stay  and we look forward to seeing you in the tournament. Please lets us know if you have any question and most functions of the event can be found at the Tournament Hub just down the road." << endl;
   
    menuDivider();

    cout << "Since this is your first time to the tournament we'd also like to give you an honorary gift from the organizers" << endl;
    
    Weapon Starter_Weapon = Weapon("The Noob", 10, 20, 0); //Pass user first weapon
    Weapon Initialize_Secondary = Weapon(); //Create a blank valued weapon to fill secondary slot
    equipped_weapons[0] = Starter_Weapon; //Set first index slot to starter weapon

    menuDivider();
    cout << "YOU JUST RECEIVED YOUR FIRST WEAPON" << endl;
    menuDivider();

    displayWeaponStats(0, equipped_weapons);

    menuDivider(); 
    // End of Travel Message

    cout 
    << "Welcome to The Tournament Hub, the heart of the Intergalactic Tournament on Planet Kumite! This bustling area is a hive of activity, where warriors from across the galaxy gather to prepare for battle and hone their skills." << endl << endl
    << "Here, you can visit The Forge, the most renowned armor and weapon shop in the galaxy, where you can upgrade your gear and make sure you're fully equipped for the challenges ahead." << endl << endl
    << "If you're looking for some action, head to the tournament arena where you can test your skills against challengers from all corners of the universe. With no-holds-barred battles and the ultimate prize of eternal glory, the competition is fierce and the stakes are high." << endl << endl
    << "But if you need a break from the intensity of battle, you can always return to your ship and modify your gear, or take some time to relax and recharge before heading back into the fray." << endl << endl
    << "So, come and experience the thrill of the ultimate test of strength, skill, and strategy in the galaxy at The Tournament Hub!" 
    << endl;
}

/**
 * GAME MENUS
 */ 

void tournament_hub_menu(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player) // Main Navigation Function of Program
{
    menuDivider();
    cout << "TRANSPORTING YOU TO THE TOURNAMENT HUB" << endl;
    menuDivider(); 

    cout << "Welcome back to the Tournament Hub, " << Player.getUserName() << ". Where would you like to go?" << endl << endl;
    displayPlayerStats(Player);

    cout
    << "1. View Current Gear" << endl
    << "2. Return to Ship" << endl
    << "3. Go the The Forge" << endl
    << "4. Enter the Arena" << endl
    << "5. Exit Game" << endl
    << endl;
    
    int menuInput = 0; //Variable to store user's input to menu
    cout << "Menu Selection: "; cin >> menuInput;

    // Check that user input is valid
    while (menuInput < 1 || menuInput > 5)
    {
        cout << endl << menuInput << " is not a valid option!" << endl;
        cout << "Please enter one of the menu options." << endl << endl;
        cout << "Where would you like to go from the Tournament Hub, " << Player.getUserName() << "?" << endl << endl;

        cout
        << "1. View Current Gear" << endl
        << "2. Return to Ship" << endl
        << "3. Go the The Forge" << endl
        << "4. Enter the Arena" << endl
        << "5. Exit Game" << endl
        << endl;

        cout << "Menu Selection: "; cin >> menuInput;

        menuDivider();
    }
    // User chooses to view their gear
    if (menuInput == 1)
    {
            showAllGear(equipped_weapons, equipped_armor, equipped_potions);
            tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
    }
    // User chooses to return to ship
    else if (menuInput == 2)
    {
        Map map;
        //Output Travel Message to menu
        menuDivider();
        cout << "TRANSPORTING YOU TO YOUR SHIP" << endl;
        menuDivider();

        // Output to welcome menu to ship
        cout << "Welcome back, " << Player.getUserName() <<  "! It's great to see you've returned to your ship safe and sound after your latest expedition to the intergalactic tournament." << endl << endl; 
        cout << "As you know, your ship serves as your base of operations during the tournament, allowing you to modify your weapons and gear to gain an edge over your opponents. Additionally, the ship's storage chamber is a secure place to store any valuable items you may have acquired during your battles. So take a deep breath and take comfort in the fact that you are back in the familiar surroundings of your ship, where you can rest, recover, and prepare for your next battle in the tournament." << endl;
        menuDivider();

        shipMenu(map,equipped_weapons, equipped_armor, equipped_potions, Player);        
    }
    // User chooses to go to shop
    else if (menuInput == 3)
    {
        menuDivider();
        cout << "TRANSPORTING YOU TO THE FORGE" << endl;
        menuDivider();

        cout << "Welcome back to the Forge, warrior! You've returned to the heart of the intergalactic battle tournament, where the galaxy's finest crafters have gathered to showcase their wares. As you step inside, you're surrounded by an array of exotic weapons and armor, each one crafted with the finest materials from across the galaxy. The air is thick with the scent of smelting metal and the sound of hammers pounding on anvils. Every corner of the Forge is alive with activity as warriors from across the universe browse the shelves and haggle with merchants. It's an adventurer's paradise, and you can feel the thrill of the tournament coursing through your veins as you step up to the counter to browse the latest wares. So take your time, warrior, and choose your weapons wisely, for your next battle in the tournament is sure to be your greatest challenge yet." << endl; 
        menuDivider();

        shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
    }
    // User chooses to battle
    else if (menuInput == 4)
    {
        menuDivider();
        cout << "TRANSPORTING YOU TO THE ARENA" << endl;
        menuDivider();

        cout << "Welcome to the arena, " << Player.getUserName() << endl << endl;

        // Ask user if they are sure they want to enter the arena
        cout << "Are you sure you would like to enter the arena? Once you enter you cannot return until after your battle slot has concluded." << endl << endl;

        cout << "1. Yes" << endl;
        cout << "2. No [Return to Tournament Hub]" << endl << endl;

        cout << "Menu Selection: "; cin >> menuInput;

        menuDivider();

        // Check that user input is valid
        while (menuInput != 1 && menuInput != 2)
        {
            cout << "Input was invalid. Please enter either 1 or 2" << endl << endl;

            cout << "Are you sure you would like to enter the arena? Once you enter you cannot return until after your battle slot has concluded." << endl << endl;

            cout << "1. Yes" << endl;
            cout << "2. No [Return to Tournament Hub]" << endl << endl;

            cout << "Menu Selection: "; cin >> menuInput;

            menuDivider();
        }

        // User chooses to enter the arena
        if (menuInput == 1)
        {
            if (Player.getUserLevel() == 1)
            {
            cout << "Welcome, interplanetary traveler, to the annual fighting tournament on Planet Kumite! As a traveler from distant worlds, you have been chosen to participate in this prestigious event, where only the strongest and most skilled warriors from across the galaxy gather to compete for glory and honor." << endl << endl;
            cout << "Before you enter the arena, you must understand the rules of this tournament. The battles here are intense and often brutal, with no holds barred and no mercy given. Your strength, agility, and strategy will be put to the test, as you face opponents who have trained their entire lives for this moment. Only the best will emerge victorious, and only the strongest will be remembered." << endl << endl;
            cout << "But fear not, for you are not alone in this journey. Many of your fellow travelers have also arrived on Planet Kumite, eager to prove themselves in battle. Some come seeking fame and fortune, while others are driven by a desire for revenge or redemption. But no matter their motivations, all share a common goal: to emerge as the ultimate champion of the interplanetary tournament." << endl << endl;
            cout << "So step into the arena, traveler, and show us what you're made of. Let your combat skills speak for themselves, and let your courage and determination be your guiding lights. For on this battlefield, only the strongest will survive, and only the bravest will triumph. The interplanetary tournament awaits you, so let the games begin!" << endl << endl;
            }

            menuDivider();
            cout << "Introducing Opponent" << endl;
            menuDivider();

            // Generate Opponent Name and Backstory
            string opponent_name = generate_opponent_name(), opponent_backstory = generate_opponent_backstory();
            int opponent_level = generate_opponent_level(Player.getUserLevel());

            cout << "Name: " << opponent_name << endl;
            cout << "Level: " << opponent_level << endl << endl;

            cout << "Opponent Background:" << endl << endl;
            cout << opponent_backstory << endl;

            int opponent_base_damage = generate_weapon_base_damage(opponent_level);
            int opponent_max_damage = generate_weapon_max_damage(opponent_base_damage);

            Opponent opponent(opponent_name, opponent_level, opponent_base_damage, opponent_max_damage); //Create an opponent object to pass to and from

            menuDivider();
            cout << "Ladies and gentlemen, we are live from the sold-out arena, and it's time for the fight you've all been waiting for! This is the moment when two warriors step into the octagon and put everything on the line!" << endl << endl;
            cout << "Introducing first, fighting out of the blue corner! He's a striker with devastating power, a submission specialist with a ground game to match, and he's hungry for victory tonight! He's trained for months, and he's ready to leave it all in the cage! So let's hear it for... " << Player.getUserName() <<  "!" << endl << endl;
            cout << "And his opponent, fighting out of the red corner! He's a force to be reckoned with, a powerhouse of pure aggression, and he's determined to come out on top! With lightning-fast reflexes and an iron will, he's a fighter you don't want to mess with! So let's give it up for..." << opponent_name << "!" << endl << endl;
            cout << "The crowd is on their feet, the energy in the arena is electric, and we are about to witness one of the greatest battles in the history of combat sports! Are you ready?! LET'S GET IT ON!" << endl << endl;
            menuDivider();
            cout << "FIGHT" << endl;
            menuDivider();

            // Initiate the fight
            bool throw_in_the_towel = false;
            int turn = 1;
            while (throw_in_the_towel == false)
            {
                cout << "Turn: " << turn << endl << endl;

                cout << Player.getUserName() << " Health: " << Player.getUserHealth() << "/" << Player.getUserMaxHealth() << endl; 
                cout << opponent.getOpponentName() << " Health: " << opponent.getOpponentHealth() << "/" << opponent.getOpponentMaxHealth() << endl << endl;

                cout << "What would you like to do, " << Player.getUserName() << "?" << endl << endl;

                cout << "1. Attack" << endl;
                cout << "2. Heal" << endl;
                cout << "3. View Gear" << endl << endl;

                cout << "Menu Selection: "; cin >> menuInput;

                while (menuInput < 1 || menuInput > 4)
                {
                    cout << "Enter a valid input!" << endl;

                     cout << "What would you like to do, " << Player.getUserName() << "?" << endl << endl;

                    cout << "1. Attack" << endl;
                    cout << "2. Heal" << endl; 
                    cout << "3. View Gear" << endl << endl;

                    cout << "Menu Selection: "; cin >> menuInput;
                }
                // User chooses to attack
                if (menuInput == 1)
                {
                    // Display Currently Equipped Weapon
                    menuDivider();
                    cout << "Currently Equipped Weapon:" << endl;
                    menuDivider();

                    cout << "Name: " << equipped_weapons[0].getWeaponName() << endl;
                    cout << "Base Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                    cout << "Hits Remaining: " << equipped_weapons[0].getWeaponHitsRemaining() << endl;

                    // Display different attack options
                    menuDivider();
                    cout << "ATTACK OPTIONS" << endl;
                    menuDivider();

                    cout << "What type of attack would you like to use?" << endl << endl;

                    cout << "1. Light Attack" << endl << endl;
                    cout << "Probability of Hit: 95%" << endl;
                    cout << "Base Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                    cout << "Potential Max Damage: " << equipped_weapons[0].getWeaponMaxDamage() << endl;

                    storeDivider();

                    cout << "2. Heavy Attack" << endl << endl;
                    cout << "Probability of Hit: 75%" << endl;
                    cout << "Base Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                    int potential_max = equipped_weapons[0].getWeaponMaxDamage() + 10 + (Player.getUserLevel() * 10);
                    cout << "Potential Max Damage: " << potential_max << endl;

                    storeDivider();

                    cout << "Press 3 to Switch Weapons" << endl;
                    cout << "Press 4 to Return to Main Battle Screen" << endl;

                    menuDivider();
                    cout << "Menu Selection: "; cin >> menuInput;
                    menuDivider();

                    // Check to make sure users input is valid
                    while (menuInput < 1 || menuInput > 4)
                    {
                        menuDivider();
                        cout << "Currently Equipped Weapon:" << endl;
                        menuDivider();

                        cout << "Name: " << equipped_weapons[0].getWeaponName() << endl;
                        cout << "Base Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                        cout << "Hits Remaining: " << equipped_weapons[0].getWeaponHitsRemaining() << endl;

                        menuDivider();
                        cout << "ATTACK OPTIONS" << endl;
                        menuDivider();

                        cout << "What type of attack would you like to use?" << endl << endl;

                        cout << "1. Light Attack" << endl << endl;
                        cout << "Probability of Hit: 95%" << endl;
                        cout << "Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                        cout << "Potential Max Damage: " << equipped_weapons[0].getWeaponMaxDamage() << endl;

                        storeDivider();

                        cout << "2. Heavy Attack" << endl << endl;
                        cout << "Probability of Hit: 75%" << endl;
                        cout << "Base Damage: " << equipped_weapons[0].getWeaponBaseDamage() << endl;
                        int potential_max = equipped_weapons[0].getWeaponMaxDamage() + 10 + (Player.getUserLevel() * 10);
                        cout << "Potential Max Damage: " << potential_max << endl;

                        storeDivider();

                        cout << "Press 3 to Switch Weapons" << endl;

                        storeDivider();

                        cout << "Press 4 to Return to Main Battle Screen" << endl;

                        menuDivider();
                        cout << "Menu Selection: "; cin >> menuInput; cout << endl;
                        menuDivider();
                    }
                    int probability;
                    int base;
                    int max;
                    int attack;
                    // User chooses Light Attack
                    if (menuInput == 1)
                    {
                        probability = generate_random_number(1, 100);
                        // If probability is between 1 and 5 attack fails
                        if (probability > 0 && probability < 6)
                        {
                            cout << "Attack failed" << endl;
                            attack = 0;
                        }
                        // If probability is between 6 and 100 run
                        else
                        {
                            base = equipped_weapons[0].getWeaponBaseDamage();
                            max =  equipped_weapons[0].getWeaponMaxDamage();
                            attack = generate_random_number(base, max);
                            cout << "Attack is: " << attack << endl;
                            opponent.setOpponentHealth(attack);
                        }
                    }
                    // User chooses Heavy Attack
                    else if (menuInput == 2)
                    {
                        probability = generate_random_number(1, 100);
                        // If probability is between 1 and 5 attack fails
                        if (probability > 0 && probability < 25)
                        {
                            cout << "Attack failed" << endl;
                            attack = 0;
                        }
                        else
                        {
                            int random = generate_random_number(1, 10);
                            base = equipped_weapons[0].getWeaponBaseHeavyDamage();
                            max = equipped_weapons[0].getWeaponMaxHeavyDamage();

                            attack = generate_random_number(base, max);
                            cout << endl << opponent.getOpponentName() << " attack generated " << attack << " damage!" << endl << endl;
                            opponent.setOpponentHealth(attack);
                            cout << opponent.getOpponentName() << "'s Health is now " << opponent.getOpponentHealth() << "/" << opponent.getOpponentMaxHealth() << endl;
                        }
                     }
                    // User chooses to switch primary with secondary
                    else if (menuInput == 3)
                    {
                        cout << "Switching  Secondary Weapon to the Primary Slot" << endl << endl;
                        Weapon tempStore[1];
                        tempStore[0] = equipped_weapons[0];
                        equipped_weapons[0] = equipped_weapons[1];
                        equipped_weapons[1] = tempStore[0];

                        menuDivider();
                        cout << "WEAPONS" << endl;
                        menuDivider();

                        cout << "Primary Weapon:" << endl;
                        displayWeaponStats(0, equipped_weapons);
                        cout << endl;

                        cout << "Secondary Weapon:" << endl;
                        displayWeaponStats(1, equipped_weapons);
                        cout << endl;

                        menuDivider();
                    }
                    // User chooses to return to main battle screen
                    else if (menuInput == 4)
                    {
                        menuDivider();
                        cout << "Returning User to Main Battle Screen" << endl;
                        menuDivider();
                    }

                    // Check if Opponent is beaten
                    if (opponent.getOpponentHealth() <= 0)
                    {
                        cout << "...and the fight is over! " << Player.getUserName() << "has defeated " << opponent.getOpponentName() << " in " << turn << " rounds. What a finish." << endl;
                        menuDivider();

                        cout << "What a win, " << Player.getUserName() << "! You really showed them how to fight. Please take this reward for your hardshipa dn we'd love to see you fight again." << endl;
                        int victory_xp = generate_random_number(100, 350);
                        int xp_earned = (200 * Player.getUserLevel()) + (victory_xp * Player.getUserLevel()) + (turn * Player.getUserLevel());
                        Player.setUserXP(xp_earned);
                        int win_credits = generate_random_number(100, 500);
                        Player.giveUserCredits(win_credits);

                        // Check if user can level up
                        if (Player.getUserXP() > Player.getUserXPNeeded())
                        {
                            Player.levelUpUser(Player.getUserLevel());
                            int xp_remaining = Player.getUserXP() - Player.getUserXPNeeded();
                            Player.resetUserXP(xp_remaining);
                            Player.setUserXPNeeded(Player.getUserLevel());
                            Player.setUserHealthFull(Player.getUserMaxHealth());

                            menuDivider();
                            cout << "Congragulations, " << Player.getUserName() << "! You just reached Level " << Player.getUserLevel() << endl;
                            menuDivider();  
                        }

                        tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                        throw_in_the_towel = true;
                    }

                    // Switch to Opponent now that user has exercised their turn

                    menuDivider();
                    cout << opponent.getOpponentName() << "'s Turn to Attack" << endl;
                    menuDivider();

                    string opponent_attacks[3]; 
                    string randomOpponentAttack1 = generate_opponent_attack_name(), randomOpponentAttack2 = generate_opponent_attack_name(), randomOpponentAttack3 = generate_opponent_attack_name();
                    opponent_attacks[0] = randomOpponentAttack1;
                    opponent_attacks[1] = randomOpponentAttack2;
                    opponent_attacks[2] = randomOpponentAttack3;
                    int opponent_chosen_attack = generate_random_number(1, 3);
                    int opponent_attack_amount = generate_random_number(opponent.getOpponentBaseDamage(), opponent.getOpponentMaxDamage());

                    cout << opponent.getOpponentName() << " uses " << opponent_attacks[opponent_chosen_attack] << endl;

                    cout << "Your attack generated " << opponent_attack_amount << " damage!" << endl << endl;
                    Player.setUserHealth(opponent_attack_amount);
                    cout << "Your health is now " << Player.getUserHealth() << "/" << Player.getUserMaxHealth() << endl; 

                    menuDivider();

                    // If Player health reaches 0
                    if (Player.getUserHealth() <= 0)
                    {
                        cout << "...and the fight is over! " << opponent.getOpponentName() << "has defeated " << Player.getUserName() << " in " << turn << " rounds. What a finish." << endl;
                        menuDivider();

                        cout << "Sorry, " << Player.getUserName() << " better luck next time. As a festival celebrating the greatness of combat sports we always welcome you back to try your luck again." << endl;
                        int loss_xp = generate_random_number(0, 150);
                        int xp_earned = (200 * Player.getUserLevel()) + (loss_xp * Player.getUserLevel()) + (turn * Player.getUserLevel());
                        Player.setUserXP(xp_earned);
                        int loss_credits = generate_random_number(100, 200);
                        Player.giveUserCredits(loss_credits);

                        // Check if user can level up
                        if (Player.getUserXP() > Player.getUserXPNeeded())
                        {
                            Player.levelUpUser(Player.getUserLevel());
                            int xp_remaining = Player.getUserXP() - Player.getUserXPNeeded();
                            Player.resetUserXP(xp_remaining);
                            Player.setUserXPNeeded(Player.getUserLevel());
                            Player.setUserHealthFull(Player.getUserMaxHealth());

                            menuDivider();
                            cout << "Congragulations, " << Player.getUserName() << "! You just reached Level " << Player.getUserLevel() << endl;
                            menuDivider();  
                        }
                        
                        tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                        throw_in_the_towel = true; // End Fight
                    }
                    turn++; // Iterate turn
                }
                // User chooses to heal
                else if (menuInput == 2)
                {
                    menuDivider();

                    cout << "Which Potion would you like to use?" << endl;
                    
                    storeDivider();

                    int counter = 0; //count how many potions there are
                    // Output potions in inventory
                    for (int i = 0; i < 5; i++)
                    {
                        if (equipped_potions[i].getPotionAmount() > 0)
                        {
                            
                            cout << i + 1 << ". " << equipped_potions[i].getPotionName() << endl;
                            cout << "Amount Healed: " << equipped_potions[i].getPotionAmount() << endl;
                            counter++;
                            storeDivider();
                        }
                    }
                    
                    int exit_input = counter + 1; //Create Variable to store input to exit at

                    // If user has 1 or more potions
                    if (counter > 0)
                    {
                        //Output rest of menu to user
                        cout << "Press " << exit_input << " to Return to Main Battle Screen" << endl;

                        storeDivider();

                        cout << "Menu Selection: "; cin >> menuInput;


                        // Check to make sure input is valid
                        while (menuInput <  1 || menuInput > 6 || menuInput > counter + 1) // Extra is to account for exit
                        {
                            menuDivider();
                            cout << "Please enter a valid input!" << endl;
                            menuDivider();

                            // Output potions in inventory to user
                            for (int i = 0; i < 5; i++)
                            {
                                if (equipped_potions[i].getPotionAmount() > 0)
                                {
                                    cout << i + 1 << ". " << equipped_potions[i].getPotionName() << endl;
                                    cout << "Amount Healed: " << equipped_potions[i].getPotionAmount() << endl;
                                    storeDivider();
                                }
                            }
                            // Output exit message to user
                            cout << "Press " << exit_input << " to Return to Main Battle Screen" << endl;

                            storeDivider();

                            cout << "Menu Selection: "; cin >> menuInput;
                        }

                        int amount_from_potion; // Variable to store amount of health from potion selected
                        if (Player.getUserHealth() < Player.getUserMaxHealth())
                        {
                            if (menuInput == exit_input)
                            {
                                cout << "Bringing User Back to Battle Screen" << endl;
                            }
                            // User chooses potion in slot 1
                            if (menuInput == 1)
                            {
                                amount_from_potion = equipped_potions[menuInput - 1].getPotionAmount();
                                Player.usePotion(amount_from_potion); 
                                // create loop to move potions down
                                for (int i = menuInput - 1; i < counter; i++)
                                {
                                    equipped_potions[menuInput - 1] = equipped_potions[menuInput]; // Set potion used slot to slot ahead of it
                                    equipped_potions[counter - 1] = Potion();
                                    exit_input = counter;
                                }  
                            }
                            // User chooses potion in slot 2
                            else if (menuInput == 2)
                            {
                                amount_from_potion = equipped_potions[menuInput - 1].getPotionAmount();
                                Player.usePotion(amount_from_potion);
                                // create loop to move potions down
                                for (int i = menuInput - 1; i < counter; i++)
                                {
                                    equipped_potions[menuInput - 1] = equipped_potions[menuInput]; // Set potion used slot to slot ahead of it
                                    equipped_potions[counter - 1] = Potion();
                                    exit_input = counter;                 
                                }    
                            }
                            // User chooses potion in slot 3
                            else if (menuInput == 3)
                            {
                                amount_from_potion = equipped_potions[menuInput - 1].getPotionAmount();
                                Player.usePotion(amount_from_potion);
                                // create loop to move potions down
                                for (int i = menuInput - 1; i < counter; i++)
                                {
                                    equipped_potions[menuInput - 1] = equipped_potions[menuInput]; // Set potion used slot to slot ahead of it
                                    equipped_potions[counter - 1] = Potion();
                                    exit_input = counter;
                                }    
                            }
                            // User chooses potion in slot 4
                            else if (menuInput == 4)
                            {
                                amount_from_potion = equipped_potions[menuInput - 1].getPotionAmount();
                                Player.usePotion(amount_from_potion);
                                // create loop to move potions down
                                for (int i = menuInput - 1; i < counter; i++)
                                {
                                    equipped_potions[menuInput - 1] = equipped_potions[menuInput]; // Set potion used slot to slot ahead of it
                                    equipped_potions[counter - 1] = Potion();
                                    exit_input = counter;
                                }
                                   
                            }
                            // User chooses potion in slot 5
                            else if (menuInput == 5)
                            {
                                amount_from_potion = equipped_potions[menuInput - 1].getPotionAmount();
                                Player.usePotion(amount_from_potion);
                                // create loop to move potions down
                                for (int i = menuInput - 1; i < counter; i++)
                                {
                                    equipped_potions[menuInput - 1] = equipped_potions[menuInput]; // Set potion used slot to slot ahead of it
                                    equipped_potions[counter - 1] = Potion();
                                    exit_input = counter;
                                }    
                            }
                            else if (menuInput == 6)
                            {
                                cout << "Bringing User Back to Battle Screen" << endl;
                            }
                        }
                        else if (Player.getUserHealth() == Player.getUserMaxHealth())
                        {     
                            menuDivider();
                            if (menuInput == exit_input)
                            {
                                cout << "Bringing User Back to Battle Screen" << endl;
                            }
                            else
                            {
                                cout << "Health is already full" << endl;
                            }  
                        }
                        menuDivider();
                    }
                    // If user has no potions
                    else if (counter == 0)
                    {
                        cout << "Sorry, you don't have any potions" << endl;
                        menuDivider();
                    }
                }
                // User chooses to view gear
                else if (menuInput == 3)
                {
                    showAllGear(equipped_weapons, equipped_armor, equipped_potions);

                    menuDivider();
                    cout << "END OF GEAR" << endl;
                    menuDivider();
                }
            } 
        }  
        // User chooses to return to tournament hub
        else
        {
            tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
        }
          
    }
    // User Chooses to exit game
    else if (menuInput == 5)
    {
        menuDivider();

        // Ask user if they would like to exit
        cout << "Are you sure you would like to exit?" << endl << endl;

        cout << "1. Yes" << endl;
        cout << "2. No [Return to Game]" << endl << endl;

        cout << "Menu Selection: "; cin >> menuInput;

        menuDivider();

        // Check user input is valid
        while (menuInput != 1 && menuInput != 2)
        {
            cout << "Please enter a valid input" << endl << endl;
            
            cout << "Are you sure you would like to exit?" << endl << endl;

            cout << "1. Yes" << endl;
            cout << "2. No [Return to Game]" << endl << endl;

            cout << "Menu Selection: "; cin >> menuInput;

            menuDivider();
        }

        // User chooses to exit game
        if (menuInput == 1)
        {
             exit();
        }
        // User chooses to return to game
        else
        {
            tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player); // Return user to main menu
        }
    }
}
void shopMenu(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player) // Shop Naviagtion
{
    int shopInput; // Variable to store menu's menu choice in store

    cout << "TRANSPORTING YOU TO THE FORGE MAIN GALLERY" << endl;

    menuDivider();

    displayPlayerStats(Player);

    cout << "What would you like to buy from The Forge today, " << Player.getUserName() << "?" << endl << endl;

    cout << "1. Browse Weaponry"<< endl;
    cout << "2. Browse Armor Pieces" << endl;
    cout << "3. Browse Potions" << endl;
    cout << "4. Return to Tournament Hub" << endl << endl;

    cout << "Menu Selection: "; cin >> shopInput;

    //Check the input is valid
    while (shopInput < 1 || shopInput > 4)
    {
        shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
    }

    // User wants to view Weapons for sale
    if (shopInput == 1)
    {
        menuDivider();
        cout << "WELCOME TO THE WEAPONS RACK" << endl;
        menuDivider();

        cout << "Have a look at our current selection" << endl << endl;
        cout << "You currently have: $" << Player.getUserCredits() << endl;

        //Generate random weapon names
        string randomWeapon1name = generate_weapon_name(), randomWeapon2name = generate_weapon_name(), randomWeapon3name = generate_weapon_name();
        //Generate random weapon base damage values
        int randomWeapon1base = generate_weapon_base_damage(Player.getUserLevel()), randomWeapon2base = generate_weapon_base_damage(Player.getUserLevel()), randomWeapon3base = generate_weapon_base_damage(Player.getUserLevel());
        // Generate random weapon max damage values
        int randomWeapon1max = generate_weapon_max_damage(randomWeapon1base), randomWeapon2max = generate_weapon_max_damage(randomWeapon2base), randomWeapon3max = generate_weapon_max_damage(randomWeapon3base);
        // Generate weapon costs based on damage ratings
        int randomWeapon1cost = generate_weapon_cost(randomWeapon1base, randomWeapon1max), randomWeapon2cost = generate_weapon_cost(randomWeapon2base, randomWeapon2max), randomWeapon3cost = generate_weapon_cost(randomWeapon3base, randomWeapon3max);

        storeDivider();

        cout << "Name: " << randomWeapon1name << endl << "Cost: $" << randomWeapon1cost << endl << "Base Damage: " << randomWeapon1base << endl << "Max Damage: " << randomWeapon1max << endl << endl << "Enter 1 to Purchase" << endl;
        storeDivider();
        cout << "Name: " << randomWeapon2name << endl << "Cost: $" << randomWeapon2cost << endl << "Base Damage: " << randomWeapon2base << endl << "Max Damage: " << randomWeapon2max << endl << endl << "Enter 2 to Purchase" << endl;
        storeDivider();
        cout << "Name: " << randomWeapon3name << endl << "Cost: $" << randomWeapon3cost << endl << "Base Damage: " << randomWeapon3base << endl << "Max Damage: " << randomWeapon3max << endl << endl << "Enter 3 to Purchase" << endl;
        storeDivider();
        cout << "Enter 4 to return to Forge Main Gallery" << endl;
        storeDivider();
        cout << "Menu Selection: "; cin >> shopInput;
        menuDivider();

        while (shopInput < 1 || shopInput > 4)
        {
            cout << endl << shopInput << " is not a valid option!" << endl;

            menuDivider();
            cout << "Please enter one of the menu options." << endl << endl;
            storeDivider();
            cout << "Name: " << randomWeapon1name << endl << "Cost: $" << randomWeapon1cost << endl << "Base Damage: " << randomWeapon1base << endl << "Max Damage: " << randomWeapon1max << endl << endl << "Enter 1 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomWeapon2name << endl << "Cost: $" << randomWeapon2cost << endl << "Base Damage: " << randomWeapon2base << endl << "Max Damage: " << randomWeapon2max << endl << endl << "Enter 2 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomWeapon3name << endl << "Cost: $" << randomWeapon3cost << endl << "Base Damage: " << randomWeapon3base << endl << "Max Damage: " << randomWeapon3max << endl << endl << "Enter 3 to Purchase" << endl;
            storeDivider();
            cout << "Enter 4 to return to Forge Main Gallery" << endl;
            storeDivider();

            cout << "Menu Selection: "; cin >> shopInput;
        }

        Weapon Purchase; //Create Object to pass purchase information into
        bool purchase_flag = false; //Set a purchase flag to make sure unwanted messages don't display
        switch (shopInput)
        {
            //User picks first option in menu
            case 1:
                cout << "You selected " << randomWeapon1name << endl;
                Purchase = Weapon(randomWeapon1name, randomWeapon1base, randomWeapon1max, randomWeapon1cost);
                purchase_flag = true;
                break;
             //User picks second option in menu  
            case 2:
                cout << "You selected " << randomWeapon2name << endl;
                Purchase = Weapon(randomWeapon2name, randomWeapon2base, randomWeapon2max, randomWeapon2cost);
                purchase_flag = true;
                break;
             //User picks third option in menu    
            case 3:
                cout << "You selected " << randomWeapon3name << endl;
                Purchase = Weapon(randomWeapon3name, randomWeapon3base, randomWeapon3max, randomWeapon3cost);
                purchase_flag = true;
                break;
             //User chooses to return to shop
            case 4:
                shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                break;
        }

        menuDivider();

        //Check if user has enough credits
        if (Player.getUserCredits() < Purchase.getWeaponValue())
        {
            cout << "Sorry, it looks like you don't have enough for this." << endl;
            menuDivider();
            shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
            purchase_flag = false;
        }

        int credits = Player.getUserCredits() - Purchase.getWeaponValue(); //Subtract value of weapons from credits

        // If this is users first purchase
        if (equipped_weapons[1].getWeaponBaseDamage() == 0 && purchase_flag == true)
        {
            cout << "Congragulations, " << Player.getUserName() << "! This is your first ever weapon purchase with us. Thanks you so much for the business. As a courtesy we've given you a complimentary satch to carry an additional weapon. You'll find you can now carry two weapons." << endl;
            equipped_weapons[1] = equipped_weapons[0]; // Move the Noob to secondary
            equipped_weapons[0] = Purchase; // Move purchase to primary weapon slot
            Player.setUserCredits(credits); //Pass Credit amount to player
            tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
        }
        else if (equipped_weapons[1].getWeaponBaseDamage() > 0 && purchase_flag == true)
        {
            cout << "Would like this purchase to replace your primary or secondary weapon?" << endl;

            storeDivider();
            cout << "Primary Weapon:" << endl;
            displayWeaponStats(0, equipped_weapons);
            cout << endl << "Enter 1 to Replace Primary"; cout << endl;

            storeDivider();

            cout << "Secondary Weapon:" << endl;
            displayWeaponStats(1, equipped_weapons);
            cout << endl << "Enter 2 to Replace Secondary"; cout << endl;
            storeDivider();

            cout << "Menu Selection: "; cin >> shopInput;

            while (shopInput != 1 && shopInput != 2)
            {
                cout << "Please enter a valid input!" << endl << endl;

                cout << "Enter 1 to Replace Primary" << endl;
                cout << "Enter 2 to Replace Secondary" << endl;
                cout << "Enter 3 to Cancel Transaction" << endl;

                cout << "Menu Selection: "; cin >> shopInput;
            }

            if (shopInput == 1 || shopInput == 2)
            {
                //Move equipped weapon at input to inventory
                equipped_weapons[shopInput - 1] = Purchase;
                Player.setUserCredits(credits); //Pass Credit amount to player
                tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
            }
            else if (shopInput == 3)
            {
                shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
            }
        }
    }
    // User wants to view armor for sale
    else if (shopInput == 2)
    {
        menuDivider();
        cout << "WELCOME TO THE ARMORY" << endl;
        menuDivider();

        cout << "Is there any kind of piece you're looking for in particular?" << endl << endl;

        cout << "1. Browse Helmet Pieces"<< endl;
        cout << "2. Browse Chest Pieces" << endl;
        cout << "3. Browse Boots" << endl;
        cout << "4. Return to Forge Main Gallery" << endl << endl;

        cout << "Menu Selection: "; cin >> shopInput;

        //Check to make sure user input is valid
        while (shopInput < 1 || shopInput > 4)
        {
            cout << endl << shopInput << " is not a valid option!" << endl;

            menuDivider();

            cout << "Please enter one of the menu options." << endl << endl;

            cout << "1. Browse Helmet Pieces"<< endl;
            cout << "2. Browse Chest Pieces" << endl;
            cout << "3. Browse Boots" << endl;
            cout << "4. Return to Forge Main Gallery" << endl << endl;

            cout << "Menu Selection: "; cin >> shopInput;
        }
        // View Helmet Shop Menu
        if (shopInput == 1)
        {
            menuDivider();
            cout << "WELCOME TO THE HELMET GALLERY" << endl;
            menuDivider();

            cout << "Have a look at our current selection" << endl << endl;
            cout << "You currently have: $" << Player.getUserCredits() << endl;

            //Generate random weapon names
            string randomHelmet1name = generate_helmet_name(), randomHelmet2name = generate_helmet_name(), randomHelmet3name = generate_helmet_name();
            //Generate random weapon base damage values
            int randomHelmet1Health = generate_helmet_health(Player.getUserLevel()), randomHelmet2Health = generate_helmet_health(Player.getUserLevel()), randomHelmet3Health = generate_helmet_health(Player.getUserLevel());
            // Generate weapon costs based on damage ratings
            int randomHelmet1cost = generate_helmet_cost(randomHelmet1Health), randomHelmet2cost = generate_helmet_cost(randomHelmet2Health), randomHelmet3cost = generate_helmet_cost(randomHelmet3Health);

            storeDivider();

            cout << "Name: " << randomHelmet1name << endl << "Cost: $" << randomHelmet1cost << endl << "Health: " << randomHelmet1Health << endl << endl << "Enter 1 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomHelmet2name << endl << "Cost: $" << randomHelmet2cost << endl << "Health: " << randomHelmet2Health << endl << endl << "Enter 2 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomHelmet3name << endl << "Cost: $" << randomHelmet3cost << endl << "Health: " << randomHelmet3Health << endl << endl << "Enter 3 to Purchase" << endl;
            storeDivider();
            cout << "Enter 4 to return to Forge Main Gallery" << endl;
            storeDivider();
            cout << "Menu Selection: "; cin >> shopInput;
            menuDivider();

            Armor Purchase; //Create Object to pass purchase information into
            bool purchase_flag = false; //Set a purchase flag to make sure unwanted messages don't display
            switch (shopInput)
            {
                //User picks first option in menu
                case 1:
                    cout << "You selected " << randomHelmet1name << endl;
                    Purchase = Armor(randomHelmet1name, randomHelmet1Health, randomHelmet1cost);
                    purchase_flag = true;
                    break;
                //User picks second option in menu  
                case 2:
                    cout << "You selected " << randomHelmet2name << endl;
                    Purchase = Armor(randomHelmet2name, randomHelmet2Health, randomHelmet2cost);
                    purchase_flag = true;
                    break;
                //User picks third option in menu    
                case 3:
                    cout << "You selected " << randomHelmet3name << endl;
                    Purchase = Armor(randomHelmet3name, randomHelmet3Health, randomHelmet3cost);
                    purchase_flag = true;
                    break;
                //User chooses to return to shop
                case 4:
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                    break;
            }

            menuDivider();

            //Check if user has enough credits
            if (Player.getUserCredits() < Purchase.getArmorValue())
            {
                cout << "Sorry, it looks like you don't have enough for this." << endl;
                menuDivider();
                shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                purchase_flag = false;
            }

            int credits = Player.getUserCredits() - Purchase.getArmorValue();
             //Subtract value of weapons from credits
            if (equipped_armor[0].getArmorHealth() == 0 && purchase_flag == true)
            {
                cout << "Congragulations, " << Player.getUserName() << "! This is your first ever head piece purchase with us. Thank you so much for the business." << endl;
                equipped_armor[0] = Purchase;
                Player.setUserCredits(credits); //Pass Credit amount to player
                Player.setMaxHealth(equipped_armor); // Update user armor rating
                Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
            }
            else if (equipped_armor[0].getArmorHealth() > 0 && purchase_flag == true)
            {
                cout << "Would like this purchase to replace your currently equipped head piece?" << endl;

                storeDivider();
                cout << "Currently Equipped:" << endl;
                displayArmorStats(0, equipped_armor);
                cout << endl << "Enter 1 to Replace Head Piece" << endl;
                cout << "Enter 2 to Cancel Transaction" << endl;

                cout << "Menu Selection: "; cin >> shopInput;

                while (shopInput != 1 && shopInput != 2)
                {
                    cout << "Please enter a valid input!" << endl << endl;

                    cout << endl << "Enter 1 to Replace Helmet" << endl;
                    cout << "Enter 2 to Cancel Transaction" << endl;

                    cout << "Menu Selection: "; cin >> shopInput;

                    storeDivider();
                }

                if (shopInput == 1)
                {
                    //Move equipped weapon at input to inventory
                    equipped_armor[0] = Purchase;
                    Player.setUserCredits(credits); //Pass Credit amount to player
                    Player.setMaxHealth(equipped_armor); // Update user armor rating
                    Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                    tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
                else
                {
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
            }
        }
        // View Chest Piece Shop Menu
        else if (shopInput == 2)
        {
            menuDivider();
            cout << "WELCOME TO THE CHEST PIECE GALLERY" << endl;
            menuDivider();

            cout << "Have a look at our current selection" << endl << endl;
            cout << "You currently have: $" << Player.getUserCredits() << endl;

            //Generate random weapon names
            string randomChest1name = generate_chest_name(), randomChest2name = generate_chest_name(), randomChest3name = generate_chest_name();
            //Generate random weapon base damage values
            int randomChest1Health = generate_chest_health(Player.getUserLevel()), randomChest2Health = generate_chest_health(Player.getUserLevel()), randomChest3Health = generate_chest_health(Player.getUserLevel());
            // Generate weapon costs based on damage ratings
            int randomChest1cost = generate_chest_cost(randomChest1Health), randomChest2cost = generate_chest_cost(randomChest2Health), randomChest3cost = generate_chest_cost(randomChest3Health);

            storeDivider();

            cout << "Name: " << randomChest1name << endl << "Cost: $" << randomChest1cost << endl << "Health: " << randomChest1Health << endl << endl << "Enter 1 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomChest2name << endl << "Cost: $" << randomChest2cost << endl << "Health: " << randomChest2Health << endl << endl << "Enter 2 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomChest3name << endl << "Cost: $" << randomChest3cost << endl << "Health: " << randomChest3Health << endl << endl << "Enter 3 to Purchase" << endl;
            storeDivider();
            cout << "Enter 4 to return to Forge Main Gallery" << endl;
            storeDivider();
            cout << "Menu Selection: "; cin >> shopInput;
            menuDivider();

            Armor Purchase; //Create Object to pass purchase information into
            bool purchase_flag = false; //Set a purchase flag to make sure unwanted messages don't display
            switch (shopInput)
            {
                //User picks first option in menu
                case 1:
                    cout << "You selected " << randomChest1name << endl;
                    Purchase = Armor(randomChest1name, randomChest1Health, randomChest1cost);
                    purchase_flag = true;
                    break;
                //User picks second option in menu  
                case 2:
                    cout << "You selected " << randomChest2name << endl;
                    Purchase = Armor(randomChest2name, randomChest2Health, randomChest2cost);
                    purchase_flag = true;
                    break;
                //User picks third option in menu    
                case 3:
                    cout << "You selected " << randomChest3name << endl;
                    Purchase = Armor(randomChest3name, randomChest3Health, randomChest3cost);
                    purchase_flag = true;
                    break;
                //User chooses to return to shop
                case 4:
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                    break;
            }

            menuDivider();

            //Check if user has enough credits
            if (Player.getUserCredits() < Purchase.getArmorValue())
            {
                cout << "Sorry, it looks like you don't have enough for this." << endl;
                menuDivider();
                shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                purchase_flag = false;
            }

            int credits = Player.getUserCredits() - Purchase.getArmorValue();
             //Subtract value of weapons from credits
            if (equipped_armor[1].getArmorHealth() == 0 && purchase_flag == true)
            {
                cout << "Congragulations, " << Player.getUserName() << "! This is your first ever chest piece purchase with us. Thank you so much for the business." << endl;
                equipped_armor[1] = Purchase;
                Player.setUserCredits(credits); //Pass Credit amount to player
                Player.setMaxHealth(equipped_armor); // Update user armor rating
                Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
            }
            else if (equipped_armor[1].getArmorHealth() > 0 && purchase_flag == true)
            {
                cout << "Would like this purchase to replace your currently equipped chest piece?" << endl;

                storeDivider();
                cout << "Currently Equipped:" << endl;
                displayArmorStats(1, equipped_armor);
                cout << endl << "Enter 1 to Replace Chest Piece" << endl;
                cout << "Enter 2 to Cancel Transaction" << endl;

                cout << "Menu Selection: "; cin >> shopInput;

                while (shopInput != 1 && shopInput != 2)
                {
                    cout << "Please enter a valid input!" << endl << endl;

                    cout << endl << "Enter 1 to Replace Helmet" << endl;
                    cout << "Enter 2 to Cancel Transaction" << endl;

                    cout << "Menu Selection: "; cin >> shopInput;

                    storeDivider();
                }

                if (shopInput == 1)
                {
                    //Move equipped weapon at input to inventory
                    equipped_armor[1] = Purchase;
                    Player.setUserCredits(credits); //Pass Credit amount to player
                    Player.setMaxHealth(equipped_armor); // Update user armor rating
                    Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                    tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
                else
                {
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
            }
        }
        // View Boots Shop
        else if (shopInput == 3)
        {
            menuDivider();
            cout << "WELCOME TO THE BOOTS GALLERY" << endl;
            menuDivider();

            cout << "Have a look at our current selection" << endl << endl;
            cout << "You currently have: $" << Player.getUserCredits() << endl;

            //Generate random weapon names
            string randomBoots1name = generate_boots_name(), randomBoots2name = generate_boots_name(), randomBoots3name = generate_boots_name();
            //Generate random weapon base damage values
            int randomBoots1Health = generate_boots_health(Player.getUserLevel()), randomBoots2Health = generate_boots_health(Player.getUserLevel()), randomBoots3Health = generate_boots_health(Player.getUserLevel());
            // Generate weapon costs based on damage ratings
            int randomBoots1cost = generate_boots_cost(randomBoots1Health), randomBoots2cost = generate_boots_cost(randomBoots2Health), randomBoots3cost = generate_boots_cost(randomBoots3Health);

            storeDivider();

            cout << "Name: " << randomBoots1name << endl << "Cost: $" << randomBoots1cost << endl << "Health: " << randomBoots1Health << endl << endl << "Enter 1 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomBoots2name << endl << "Cost: $" << randomBoots2cost << endl << "Health: " << randomBoots2Health << endl << endl << "Enter 2 to Purchase" << endl;
            storeDivider();
            cout << "Name: " << randomBoots3name << endl << "Cost: $" << randomBoots3cost << endl << "Health: " << randomBoots3Health << endl << endl << "Enter 3 to Purchase" << endl;
            storeDivider();
            cout << "Enter 4 to return to Forge Main Gallery" << endl;
            storeDivider();
            cout << "Menu Selection: "; cin >> shopInput;
            menuDivider();

            Armor Purchase; //Create Object to pass purchase information into
            bool purchase_flag = false; //Set a purchase flag to make sure unwanted messages don't display
            switch (shopInput)
            {
                //User picks first option in menu
                case 1:
                    cout << "You selected " << randomBoots1name << endl;
                    Purchase = Armor(randomBoots1name, randomBoots1Health, randomBoots1cost);
                    purchase_flag = true;
                    break;
                //User picks second option in menu  
                case 2:
                    cout << "You selected " << randomBoots2name << endl;
                    Purchase = Armor(randomBoots2name, randomBoots2Health, randomBoots2cost);
                    purchase_flag = true;
                    break;
                //User picks third option in menu    
                case 3:
                    cout << "You selected " << randomBoots3name << endl;
                    Purchase = Armor(randomBoots3name, randomBoots3Health, randomBoots3cost);
                    purchase_flag = true;
                    break;
                //User chooses to return to shop
                case 4:
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                    break;
            }

            menuDivider();

            //Check if user has enough credits
            if (Player.getUserCredits() < Purchase.getArmorValue())
            {
                cout << "Sorry, it looks like you don't have enough for this." << endl;
                menuDivider();
                shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                purchase_flag = false;
            }

            //Subtract value of weapons from credits
            int credits = Player.getUserCredits() - Purchase.getArmorValue();
            
            // Check if user has never bought from store before
            if (equipped_armor[2].getArmorHealth() == 0 && purchase_flag == true)
            {
                cout << "Congragulations, " << Player.getUserName() << "! This is your first ever boots purchase with us. Thank you so much for the business." << endl;
                equipped_armor[2] = Purchase;
                Player.setUserCredits(credits); // Update user creedit amount 
                Player.setMaxHealth(equipped_armor); // Update user armor rating
                Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
            }
            // If user has made purchase before
            else if (equipped_armor[2].getArmorHealth() > 0 && purchase_flag == true)
            {
                cout << "Would like this purchase to replace your currently equipped boots piece?" << endl;

                storeDivider();
                cout << "Currently Equipped:" << endl;
                displayArmorStats(2, equipped_armor);
                cout << endl << "Enter 1 to Replace Boots" << endl;
                cout << "Enter 2 to Cancel Transaction" << endl;

                cout << "Menu Selection: "; cin >> shopInput;

                while (shopInput != 1 && shopInput != 2)
                {
                    cout << "Please enter a valid input!" << endl << endl;

                    cout << endl << "Enter 1 to Replace Helmet" << endl;
                    cout << "Enter 2 to Cancel Transaction" << endl;

                    cout << "Menu Selection: "; cin >> shopInput;

                    storeDivider();
                }

                if (shopInput == 1)
                {
                    //Move equipped weapon at input to inventory
                    equipped_armor[1] = Purchase;
                    Player.setUserCredits(credits); //Pass Credit amount to player
                    Player.setMaxHealth(equipped_armor);
                    Player.setHealthAfterPurchase(Purchase.getArmorHealth());
                    tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
                else
                {
                    shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
                }
            }
        }
        //User wants to return to Forge Gallery
        else if (shopInput == 4 )
        {
            shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
        }
    }
    // User wants to see potions
    else if (shopInput == 3)
    {
        menuDivider();
        cout << "WELCOME TO THE ALCHEMY LOUNGE" << endl;
        menuDivider();

         cout << "Is there any kind of potion you're looking for in particular?" << endl;
        storeDivider();
        cout << "Name: Small Potion" << endl << "Health Restored: 25" << endl << "Cost: $5" << endl << endl << "Press 1 to Purchase" << endl;
        storeDivider();
        cout << "Name: Medium Potion" << endl << "Health Restored: 50" << endl << "Cost: $10" << endl << endl << "Press 2 to Purchase" << endl;
        storeDivider();
        cout << "Name: Large Potion" << endl << "Health Restored: 75" << endl << "Cost: $15" << endl << endl << "Press 3 to Purchase" << endl;
        storeDivider(); 
        cout << "Name: King's Tonic" << endl << "Health Restored: 100" << endl << "Cost: $20" << endl << endl << "Press 4 to Purchase" << endl;
        storeDivider();

        cout << "Menu Selection: "; cin >> shopInput;

        //Check to make sure user input is valid
        while (shopInput < 1 || shopInput > 4)
        {
            cout << endl << shopInput << " is not a valid option!" << endl;

            menuDivider();
            cout << "Please enter one of the menu options." << endl << endl;

            cout << "Is there any kind of potion you're looking for in particular?" << endl << endl;
            storeDivider();
            cout << "Name: Small Potion" << endl << "Health Restored: 25" << endl << "Cost: $5" << endl << endl << "Press 1 to Purchase" << endl;
            storeDivider();
            cout << "Name: Medium Potion" << endl << "Health Restored: 50" << endl << "Cost: $10" << endl << endl << "Press 2 to Purchase" << endl;
            storeDivider();
            cout << "Name: Large Potion" << endl << "Health Restored: 75" << endl << "Cost: $15" << endl << endl << "Press 3 to Purchase" << endl;
            storeDivider(); 
            cout << "Name: King's Tonic" << endl << "Health Restored: 100" << endl << "Cost: $20" << endl << endl << "Press 4 to Purchase" << endl;
            storeDivider();

            cout << "Menu Selection: "; cin >> shopInput;
        }

        menuDivider();

        Potion Purchase; //Create Object to pass purchase information into
        bool purchase_flag = false; //Set a purchase flag to make sure unwanted messages don't display
        switch (shopInput)
        {
            //User picks first option in menu
            case 1:
                cout << "You selected the small potion" << endl;
                Purchase = Potion("Small Potion", 25, 5);
                purchase_flag = true;
                break;
            //User picks second option in menu  
            case 2:
                cout << "You selected the medium potion" << endl;
                Purchase = Potion("Medium Potion", 50, 10);
                purchase_flag = true;
                break;
            //User picks third option in menu    
            case 3:
                cout << "You selected the large potion" << endl;
                Purchase = Potion("Large Potion", 75, 15);
                purchase_flag = true;
                break;
            case 4:
                cout << "You selected the King's Tonic" << endl;
                Purchase = Potion("King's Tonic", 100, 20);
                purchase_flag = true;
                break;
            //User chooses to return to shop
            case 5:
                shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
                break;
        }

        menuDivider();

        //Check if user has enough credits
        if (Player.getUserCredits() < Purchase.getPotionValue())
        {
            cout << "Sorry, it looks like you don't have enough for this." << endl;
            menuDivider();
            shopMenu(equipped_weapons, equipped_armor, equipped_potions, Player);
            purchase_flag = false;
            
        }

        int credits = Player.getUserCredits() - Purchase.getPotionValue(); //Subtract value of weapons from credits

        //Check if potion array at 0 is filled
        if (equipped_potions[0].getPotionAmount() == 0 && purchase_flag == true)
        {
            equipped_potions[0] = Purchase;
            Player.setUserCredits(credits); //Pass Credit amount to player
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
        }

        //Check if potion array at 1 is filled
        else if (equipped_potions[1].getPotionAmount() == 0 && purchase_flag == true)
        {
            equipped_potions[1] = Purchase;
            Player.setUserCredits(credits); //Pass Credit amount to player
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
        }

        //Check if potion array at 2 is filled
        else if (equipped_potions[2].getPotionAmount() == 0 && purchase_flag == true)
        {
            equipped_potions[2] = Purchase;
            Player.setUserCredits(credits); //Pass Credit amount to player
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);    
        }
        
        //Check if potion array at 3 is filled
        else if (equipped_potions[3].getPotionAmount() == 0 && purchase_flag == true)
        {
            equipped_potions[3] = Purchase;
            Player.setUserCredits(credits); //Pass Credit amount to player
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
        }

        //Check if potion array at 1 is filled
        else if (equipped_potions[4].getPotionAmount() == 0 && purchase_flag == true)
        {
            equipped_potions[4] = Purchase;
            Player.setUserCredits(credits); //Pass Credit amount to player
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
        }
        else 
        {
            cout << "POTIONS ARE FULL" << endl;
            menuDivider();
            shopMenu(equipped_weapons, equipped_armor, equipped_potions,Player);
        }
    }
    // User wants to return to menu from shop
    else
    {
        tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
    }
}
void shipMenu(Map map, Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[], User Player)
{
    cout << "Below is the map of the ship follow the icons accordingly to:" << endl << endl;

    cout << "H. Helm of Ship [RETURN TO TOURNAMENT]" << endl;
    cout << "B. Bed [Sleeping Fully Restores Health]" << endl << endl;

    cout << "o. Current Position" << endl; 

    int menuInput;
    bool menuFlag = true;
    while (menuFlag == true)
    {
        menuDivider();

        displayPlayerStats(Player);

        cout << "Current Map of Ship: " << endl << endl;
        map.displayMap(); // starting point

        menuDivider();

        cout << "What Direction would like to move?" << endl << endl;

        cout << "1. Up" << endl;
        cout << "2. Down" << endl;
        cout << "3. Right" << endl;
        cout << "4. Left" << endl << endl;

        cout << "Menu Selection: "; cin >> menuInput;

        while (menuInput < 1 || menuInput > 4)
        {
            cout << "Please enter a valid input" << endl << endl;

            cout << "What Direction would like to move?" << endl << endl;

            cout << "1. Up" << endl;
            cout << "2. Down" << endl;
            cout << "3. Right" << endl;
            cout << "4. Left" << endl << endl;

            cout << "Menu Selection: "; cin >> menuInput;
        }

        // User chooses to move up
        if (menuInput == 1)
        {
            cout << "Moving User Up One" << endl;
            map.move('w'); // go down
        }
        // User chooses to move down
        if (menuInput == 2)
        {
            cout << "Moving User Down One" << endl;
            map.move('s'); // go down
        }
        // User chooses to move down
        if (menuInput == 3)
        {
            cout << "Moving User Right One" << endl;
            map.move('d'); // go down
        }
        // User chooses to move down
        if (menuInput == 4)
        {
            cout << "Moving User Left One" << endl;
            map.move('a'); // go down
        }

        int row = map.getPlayerRow();
        int col = map.getPlayerCol();

        //Check if user is at exit
        if (map.isShipExit(row, col) == true)
        {

            menuDivider();
            cout << "You Made It To The Ship Helm" << endl;
            menuDivider();

            cout << "Would you like to return to the tournament?" << endl << endl;

            cout << "1. Yes [Return to Tournament]" << endl;
            cout << "2. No [Stay in Orbit]" << endl << endl;

            cout << "Menu Selection: "; cin >> menuInput;

            // Check to make sure input is valid
            while (menuInput != 1 && menuInput != 2)
            {
                cout << "Please enter a valid input!" << endl << endl;

                cout << "Would you like to return to the tournament?" << endl << endl;

                cout << "1. Yes [Return to Tournament]" << endl;
                cout << "2. No [Stay in Orbit]" << endl << endl;

                cout << "Menu Selection: "; cin >> menuInput;
            }

            if (menuInput == 1)
            {
                tournament_hub_menu(equipped_weapons, equipped_armor, equipped_potions, Player);
                menuFlag = false;
            }
            // User chooses to stay in ship
            else
            {
                shipMenu(map,equipped_weapons, equipped_armor, equipped_potions, Player);
                menuFlag = false;
            }
        }
        if (map.isShipBed(row, col) == true)
        {
            menuDivider();
            cout << "You Made it to Your Bed" << endl;
            menuDivider();

            cout << "Your Health Has Been Fully Rehealed" << endl;

            int max_health = Player.getUserMaxHealth();
            Player.setUserHealthFull(max_health);
        }
    }
}
// GENERATE OBJECT NAME FUNCTIONS

/**
 * WEAPON GENERATION
 */

string generate_weapon_name() // Returns a random name from weapons name list
{
    int random = generate_random_number(0, 99);

    ifstream weapons_file("Name_Generation/Weapon_Names.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    getline(weapons_file, current_line); //Store line value to string line
    string weapon_names[100];

    int weapon_name_index = 0; //Variable to store name index
    string current_field = ""; //Create variable to save current char to if if doesnt equal the delim
    int i = 0; // i = spot in character buffer
    while(i < current_line.size()) //Make sure loop is less than line length
    {
        char current_char = current_line[i]; //Set current_char to character in buffer
        if (current_char == '|') //Check if character equals divider
        {
            weapon_names[weapon_name_index] = current_field;
            weapon_name_index++;
            current_field = "";
        } 
        else 
        {
            current_field += current_char;
        }
        i++;
    }
    weapons_file.close();
    return weapon_names[random];
}
int generate_weapon_base_damage(int level) // Return a random value based on level
{
    int random = generate_random_number(3, 10) % 10;
    int base_damage = (level * 10) + (random * level);
    return base_damage;
}
int generate_weapon_max_damage(int base_damage) // Return a random value based on base damage
{
    int random = generate_random_number(3, 10) % 10;
    int max_damage = base_damage + random;
    return max_damage;
}
int generate_weapon_cost(int base_damage, int max_damage) // Return a weapon cost based on damage
{
    int weapon_cost = ((base_damage + max_damage) / 2) * 10;
    return weapon_cost;
}

/**
 *  ARMOR GENERATION
 */

// HELMET GENERATION
string generate_helmet_name() // Returns a random name from helmet name list
{
    int random = generate_random_number(0, 99);

    ifstream helmet_file("Name_Generation/Helmet_Names.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    getline(helmet_file, current_line); //Store line value to string line
    string helmet_names[100];

    int helmet_name_index = 0; //Variable to store name index
    string current_field = ""; //Create variable to save current char to if if doesnt equal the delim
    int i = 0; // i = spot in character buffer
    while(i < current_line.size()) //Make sure loop is less than line length
    {
        char current_char = current_line[i]; //Set current_char to character in buffer
        if (current_char == '|') //Check if character equals divider
        {
            helmet_names[helmet_name_index] = current_field;
            helmet_name_index++;
            current_field = "";
        } 
        else 
        {
            current_field += current_char;
        }
        i++;
    }
    helmet_file.close();
    return helmet_names[random];
}
int generate_helmet_health(int level) // Return a random value based on level
{
    int random = generate_random_number(3, 10) % 10;
    int health = (level * 13) + (random * level);
    return health;
}
int generate_helmet_cost(int health) // Return a helmet cost based on damage value
{
    int helmet_cost = ((health * 1.5) / 2) * 10;
    return helmet_cost;
}

// CHEST PIECE GENERATION
string generate_chest_name() // Returns a random name from chest plate name list
{
    int random = generate_random_number(0, 99);

    ifstream chest_file("Name_Generation/Chest_Names.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    getline(chest_file, current_line); //Store line value to string line
    string chest_names[100];

    int chest_name_index = 0; //Variable to store name index
    string current_field = ""; //Create variable to save current char to if if doesnt equal the delim
    int i = 0; // i = spot in character buffer
    while(i < current_line.size()) //Make sure loop is less than line length
    {
        char current_char = current_line[i]; //Set current_char to character in buffer
        if (current_char == '|') //Check if character equals divider
        {
            chest_names[chest_name_index] = current_field;
            chest_name_index++;
            current_field = "";
        } 
        else 
        {
            current_field += current_char;
        }
        i++;
    }
    chest_file.close();
    return chest_names[random];
}
int generate_chest_health(int level) // Return a random value based on level
{
    int random = generate_random_number(3, 10) % 10;
    int health = (level * 25) + (random * level);
    return health;
}
int generate_chest_cost(int health) // Return a chest cost based on damage value
{
    int chest_cost = ((health * 1.5) / 2) * 10;
    return chest_cost;
}

// BOOTS GENERATION
string generate_boots_name() // Returns a random name from boots name list
{
    int random = generate_random_number(0, 99);

    ifstream boots_file("Name_Generation/Boots_Names.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    getline(boots_file, current_line); //Store line value to string line
    string boots_names[100];

    int boots_name_index = 0; //Variable to store name index
    string current_field = ""; //Create variable to save current char to if if doesnt equal the delim
    int i = 0; // i = spot in character buffer
    while(i < current_line.size()) //Make sure loop is less than line length
    {
        char current_char = current_line[i]; //Set current_char to character in buffer
        if (current_char == '|') //Check if character equals divider
        {
            boots_names[boots_name_index] = current_field;
            boots_name_index++;
            current_field = "";
        } 
        else 
        {
            current_field += current_char;
        }
        i++;
    }
    boots_file.close();
    return boots_names[random];
}
int generate_boots_health(int level) // Return a random value based on level
{
    int random = generate_random_number(3, 10) % 10;
    int health = (level * 10) + (random * level);
    return health;
}
int generate_boots_cost(int health) // Return a boots cost based on damage value
{
    int boots_cost = ((health * 1.5) / 2) * 10;
    return boots_cost;
}

/**
 * Opponent Generation
 */

string generate_opponent_name() // Returns a random name from the opponent name list
{
    int random = generate_random_number(0, 95);

    ifstream opponent_file("Name_Generation/Opponent_Name.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    getline(opponent_file, current_line); //Store line value to string line
    string opponent_names[100];

    int opponent_name_index = 0; //Variable to store name index
    string current_field = ""; //Create variable to save current char to if if doesnt equal the delim
    int i = 0; // i = spot in character buffer
    while(i < current_line.size()) //Make sure loop is less than line length
    {
        char current_char = current_line[i]; //Set current_char to character in buffer
        if (current_char == '|') //Check if character equals divider
        {
            opponent_names[opponent_name_index] = current_field;
            opponent_name_index++;
            current_field = "";
        } 
        else 
        {
            current_field += current_char;
        }
        i++;
    }
    opponent_file.close();
    return opponent_names[random];
}
string generate_opponent_backstory() // Returns a random backstory from the opponent backstory list
{
    int random = generate_random_number(0, 99);

    ifstream opponent_file("Name_Generation/Opponent_Backstory.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    string opponent_names[100];
    int opponent_name_index = 0; //Variable to store name index

    while (getline(opponent_file, current_line)) 
    { 
        string current_field = ""; //Create variable to save current char to if if doesn't equal the delimiter
        int i = 0; // i = spot in character buffer
        
        while(i < current_line.size()) 
        {
            char current_char = current_line[i]; //Set current_char to character in buffer
            
            if (current_char == '|') 
            {
                opponent_names[opponent_name_index] = current_field;
                opponent_name_index++;
                current_field = "";
            } 
            else 
            {
                current_field += current_char;
            }
            i++;
        }
    }
    opponent_file.close();
    return opponent_names[random];
}
string generate_opponent_attack_name() // Returns a random attack type from the attack list
{
    int random = generate_random_number(0, 99);

    ifstream opponent_file("Name_Generation/Opponent_Attacks.txt");

    string current_line; // Create a variable to store the value of each line read at a time
    string opponent_attacks[100];
    int opponent_attacks_index = 0; //Variable to store name index

    while (getline(opponent_file, current_line)) 
    { 
        string current_field = ""; //Create variable to save current char to if if doesn't equal the delimiter
        int i = 0; // i = spot in character buffer
        
        while(i < current_line.size()) 
        {
            char current_char = current_line[i]; //Set current_char to character in buffer
            
            if (current_char == '|') 
            {
                opponent_attacks[opponent_attacks_index] = current_field;
                opponent_attacks_index++;
                current_field = "";
            } 
            else 
            {
                current_field += current_char;
            }
            i++;
        }
    }
    opponent_file.close();
    return opponent_attacks[random];
} 
int generate_opponent_level(int level) // Returns a random value to be opponent level will be within 2 of user
{
    int random = generate_random_number(-2, 2);
    int opponent_level = level + random;

    // Make sure opponent level is never less than 1
    if (opponent_level < 1)
    {
        opponent_level = 1;
    }

    return opponent_level;
}

// DISPLAY STATS
void displayPlayerStats(User Player) // Function to display current stats
{
    cout << "Current Level: " << Player.getUserLevel() << " | Current XP: " << Player.getUserXP() << "/" << Player.getUserXPNeeded() << " | Current Cash: $" << Player.getUserCredits() << endl;
    cout << "Current Health: " << Player.getUserHealth() << "/" << Player.getUserMaxHealth() << endl << endl; 
}
void displayWeaponStats(int input, Weapon equipped_weapons[]) //Function to display all armor stats
{
    cout << "Name: " << equipped_weapons[input].getWeaponName() << endl;
    cout << "Base Damage: " << equipped_weapons[input].getWeaponBaseDamage() << endl;
    cout << "Max Damage: " << equipped_weapons[input].getWeaponMaxDamage() << endl;
}
void displayArmorStats(int input, Armor equipped_armor[]) //Function to display all armor stats
{
    cout << "Name: " << equipped_armor[input].getArmorName() << endl;
    cout << "Health: " << equipped_armor[input].getArmorHealth() << endl;
}
void displayPotions(int input, Potion equipped_potions[]) //Function to display all potion stats
{
    cout << "Name: " << equipped_potions[input].getPotionName() << endl;
    cout << "Health: " << equipped_potions[input].getPotionAmount() << endl;
}
void showAllGear(Weapon equipped_weapons[], Armor equipped_armor[], Potion equipped_potions[]) // Call to display all gear
{
    // Show User Weapons
    menuDivider();
    cout << "YOU ARE VIEWING YOUR GEAR" << endl;
    menuDivider();
    cout << "WEAPONS" << endl;
    menuDivider();

    cout << "Primary Weapon:" << endl;
    displayWeaponStats(0, equipped_weapons);
    cout << endl;

    cout << "Secondary Weapon:" << endl;
    displayWeaponStats(1, equipped_weapons);
    cout << endl;

    //Show User Gear
    menuDivider();
    cout << "Armor" << endl;
    menuDivider();

    cout << "Head Piece: " << endl;
    displayArmorStats(0, equipped_armor);
    cout << endl;

    cout << "Chest Piece" << endl;
    displayArmorStats(1, equipped_armor);
    cout << endl;

    cout << "Boots" << endl;
    displayArmorStats(2, equipped_armor);
    cout << endl;
    
    //Show User Potions
    menuDivider();
    cout << "Potions" << endl;
    menuDivider();

    cout << "Potion 1: " << endl;
    displayPotions(0, equipped_potions);
    cout << endl;

    cout << "Potion 2: " << endl;
    displayPotions(1, equipped_potions);
    cout << endl;

    cout << "Potion 3: " << endl;
    displayPotions(2, equipped_potions);
    cout << endl;

    cout << "Potion 4: " << endl;
    displayPotions(3, equipped_potions);
    cout << endl;

    cout << "Potion 5: " << endl;
    displayPotions(4, equipped_potions);
    cout << endl;
}

// EXIT GAME
int exit() // When called this function ends the program
{
    return -1;
}