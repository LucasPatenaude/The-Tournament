#ifndef ARMOR_H
#define ARMOR_H

#include<iostream>
using namespace std;


class Armor
{
   // data members
   private:
      string name;
      int health;
      int hits_remaining;
      int upgrades_remaining;
      int value;
      
   public:
      // Constructors of Armor class
         Armor();
         Armor(string armor_name, int health_added, int cost);

      // SETTER FUNCIONS

      // GETTER FUNCTIONS
         string getArmorName();
         int getArmorHealth();
         int getArmorHitsRemaining();
         int getArmorUpgradesRemaining();
         int getArmorValue();

};

#endif