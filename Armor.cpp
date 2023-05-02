#include "Armor.h"

#include <iostream>
using namespace std;

// This constructor just initializes the Armor to null.
Armor::Armor() 
{
   name = "No Armor Equipped";
   health = 0;
   hits_remaining = 0;
   upgrades_remaining = 0;
   value = 0;
}

// This constructor just initializes the Armor to the passed values.
Armor::Armor(string armor_name, int health_added, int cost) 
{
   name = armor_name;
   health = health_added;
   hits_remaining = 150;
   upgrades_remaining = 3;
   value = cost;
}

// SETTER FUNCTIONS

// GETTER FUNCTIONS

string Armor::getArmorName()
{
   return name;
}

int Armor::getArmorHealth()
{
   return health;
}

int Armor::getArmorHitsRemaining()
{
   return hits_remaining;
}

int Armor::getArmorUpgradesRemaining()
{
   return upgrades_remaining;
}

int Armor::getArmorValue()
{
   return value;
}