#include "Opponent.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// This constructor just initializes the User to null.

Opponent::Opponent()
{
   name = "Stick McStickington";
   current_health = 0;
   max_health = 0;
   level = 1;
   base_damage = 1;
   max_damage = 1;
}

Opponent::Opponent(string opponent_name, int opponent_level, int base, int max)
{
   name = opponent_name;
   current_health = opponent_level * 100;
   max_health = current_health;
   level = opponent_level;
   base_damage = base;
   max_damage = max;
     
}

//SETTER FUNCTIONS
void Opponent::setOpponentHealth(int damage_taken)
{
   current_health = current_health - damage_taken;
}


// GETTER FUNCTIONS
string Opponent::getOpponentName()
{
   return name;
}

int Opponent::getOpponentHealth()
{
   return current_health;
}

int Opponent::getOpponentMaxHealth()
{
   return max_health;
}

int Opponent::getOpponentLevel()
{
   return level;
}

int Opponent::getOpponentBaseDamage()
{
   return base_damage;
}

int Opponent::getOpponentMaxDamage()
{
   return max_damage;
}





