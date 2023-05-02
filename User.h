#ifndef USER_H
#define USER_H

#include "Weapon.h" // include the Weapon header file
#include "Armor.h"
#include "Potion.h"

#include <string>

class User 
{
    private:
        string name;
        int current_health;
        int max_health;
        int level;
        int xp_points;
        int xp_needed;
        int credits;
        Weapon equipped_weapon[2]; // declare the user_weapons array to hold 2 Weapon objects
        Armor equipped_armor[3];
        Potion equipped_potions[5];

    public:
        User(string username, int current_level, int current_credits, Weapon current_weapons[], Armor current_armor[], Potion current_potions[]);
    
    // SETTER FUNCTIONS
        void setUserName(string username);
        void setUserHealth(int damage_taken);
        void setHealthAfterPurchase(int armor_amount_added);
        void setUserHealthFull(int full_health);
        void addArmorToHealth(Armor current_armor);
        void setMaxHealth(Armor current_armor[]);
        void setUserCredits(int current_credits);
        void giveUserCredits(int credits_added);
        void setUserXP(int xp_earned);
        void resetUserXP(int xp_remaining);
        void setUserXPNeeded(int level); //Returns amount of XP needed to level up (random each time)
        void usePotion(int potion_amount);
        void levelUpUser(int current_level);

    // GETTER FUNCTIONS
        string getUserName();
        int getUserHealth();
        int getUserMaxHealth();
        int getUserLevel();
        int getUserXP();
        int getUserCredits();
        int getUserXPNeeded(); 
        Weapon getUserWeapon(int input); // add a semicolon at the end of the function definition
};

#endif
