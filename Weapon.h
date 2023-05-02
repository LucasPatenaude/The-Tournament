#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>

using namespace std;

class Weapon
{
   // data members
   private:
      string name;
      int base_damage;
      int base_heavy_damage;
      int max_damage;
      int max_heavy_damage;
      int hits_remaining;
      int upgrades_remaining;
      int value;
      
   public:
      // Constructors of Weapon class
      Weapon();
      Weapon(string weapon_name, int base, int max, int cost);

      // SETTER FUNCIONS
      void setWeaponValue(int cost);
      void setUpgradesRemaining(int upgrades_remaining);
      void setWeaponBaseHeavyDamage(int level, int base, int random);
      void setWeaponMaxHeavyDamage(int level, int base, int random);


      // GETTER FUNCTIONS
      string getWeaponName();
      int getWeaponValue();
      int getWeaponBaseDamage();
      int getWeaponBaseHeavyDamage();
      int getWeaponMaxDamage();
      int getWeaponMaxHeavyDamage();
      int getWeaponHitsRemaining();
      int getWeaponUpgradesRemaining();  
};

#endif