#include "User.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// This constructor just initializes the User to null.

User::User(string username, int current_level, int current_credits, Weapon current_weapons[], Armor current_armor[], Potion current_potions[])
{
   name = username;
   current_health = 100;
   max_health = 100;
   level = current_level;
   xp_points = 0;
   xp_needed = 500;
   credits = current_credits;

   for (int i = 0; i < 2; i++) 
    {
        equipped_weapon[i] = current_weapons[i];
    }

    for (int i = 0; i < 3; i++)
    {
        equipped_armor[i] = current_armor[i];
    }
    for (int i = 0; i < 4; i++)
    {
        equipped_potions[i] = current_potions[i];
    }
}

//SETTER FUNCTIONS
void User::setUserName(string username)
{
    name = username;
}

void User::setUserHealth(int damage_taken)
{
    current_health = current_health - damage_taken;

    // Set Health to zero if it goes below 0
    if (current_health < 0)
    {
        current_health = 0;
    }
}

void User::setHealthAfterPurchase(int armor_amount_added)
{
    current_health += armor_amount_added;
}

void User::setUserHealthFull(int full_health)
{
    current_health = full_health;
}

void User::setMaxHealth(Armor current_armor[])
{
    int armor_rating = 0;
    for (int i = 0; i < 3; i++)
    {
        armor_rating += current_armor[i].getArmorHealth();
    }
    max_health = 100 + armor_rating;
}

void User::setUserCredits(int current_credits)
{
    credits = current_credits;
}

void User::giveUserCredits(int credits_added)
{
    credits += credits_added;
}

void User::setUserXP(int xp_earned)
{
    xp_points += xp_earned;
}

void User::resetUserXP(int xp_remaining)
{
    xp_points = xp_remaining;
}


void User::setUserXPNeeded(int level)
{
    xp_needed = (level * pow(100, 1.2)) + (level * 100) + (level * 10) + (level * pow(1, 2));
    xp_needed = floor(xp_needed); // Round down to nearest whole number 
}

void User::usePotion(int potion_amount)
{
    current_health += potion_amount;
    // Make sure potion doesn't overheal
    if (current_health > max_health)
    {
        current_health = max_health;
    }
}

void User::levelUpUser(int current_level)
{
    level = current_level + 1;
}

// GETTER FUNCTIONS
string User::getUserName()
{
   return name;
}

int User::getUserHealth()
{
   return current_health;
}

int User::getUserMaxHealth()
{
    return max_health;
}

int User::getUserLevel()
{
   return level;
}

int User::getUserXP()
{
   return xp_points;
}

int User::getUserCredits()
{
   return credits;
}

int User::getUserXPNeeded()
{
    return xp_needed;
}

Weapon User::getUserWeapon(int input)
{
    while (input < 0 && input > 1) // assuming the array size is 2
    {
        cout << "Please enter a valid input" << endl;
        cin >> input;
    }
    return equipped_weapon[input];
}







