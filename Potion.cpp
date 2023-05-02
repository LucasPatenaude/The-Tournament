#include "Potion.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// This constructor just initializes the User to null.

Potion::Potion()
{
   name = "No Potion Stocked";
   heal_amount = 0;
   value = 0;

}

Potion::Potion(string potion_name, int amount_provided, int cost)
{
   name = potion_name;
   heal_amount = amount_provided;
   value = cost;
}

//SETTER FUNCTIONS
void Potion::setPotionName(string potion_name)
{
    name = potion_name;
}

void Potion::setPotionValue(int cost)
{
   value = cost;
}

// GETTER FUNCTIONS
string Potion::getPotionName()
{
   return name;
}

int Potion::getPotionValue()
{
   return value;
}

int Potion::getPotionAmount()
{
   return heal_amount;
}







