#include "Weapon.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// This constructor just initializes the Weapon to null.
Weapon::Weapon() 
{
   name = "No Secondary Equipped";
   base_damage = 0;
   max_damage = 0;
   hits_remaining = 0;
   upgrades_remaining = 0;
   value = 0;
}

Weapon::Weapon(string weapon_name, int base, int max, int cost)
{
   name = weapon_name;
   base_damage = base;
   base_heavy_damage = base;
   max_damage = max;
   max_heavy_damage = max;
   hits_remaining = 200;
   upgrades_remaining = 3;
   value = cost;
}

//SETTER FUNCTIONS
void Weapon::setWeaponValue(int cost)
{
   value = (cost / 2) * 1.5;
}

void Weapon::setUpgradesRemaining(int upgrades_remaining)
{
   upgrades_remaining = upgrades_remaining - 1;
}

void Weapon::setWeaponBaseHeavyDamage(int level, int base, int random)
{
   base_heavy_damage = base + random + (level * 10);
}

void Weapon::setWeaponMaxHeavyDamage(int level, int max, int random)
{
   max_heavy_damage = max + random + (level * 10);
}

// GETTER FUNCTIONS
string Weapon::getWeaponName()
{
   return name;
}

int Weapon::getWeaponValue()
{
   return value;
}

int Weapon::getWeaponBaseDamage()
{
   return base_damage;
}

int Weapon::getWeaponBaseHeavyDamage()
{
   return base_heavy_damage;
}

int Weapon::getWeaponMaxDamage()
{
   return max_damage;
}

int Weapon::getWeaponMaxHeavyDamage()
{
   return max_heavy_damage;
}

int Weapon::getWeaponHitsRemaining()
{
   return hits_remaining;
}

int Weapon::getWeaponUpgradesRemaining()
{
   return upgrades_remaining;
}



