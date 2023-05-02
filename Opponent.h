#ifndef OPPONENT_H
#define OPPONENT_H

#include<iostream>
using namespace std;

class Opponent 
{
    private:
        string name;
        int current_health;
        int max_health;
        int level;
        int base_damage;
        int max_damage;

    public:
        Opponent();
        Opponent(string opponent_name, int opponent_level, int base, int max);
    
    // SETTER FUNCTIONS
        void setOpponentHealth(int damage_taken); // Set current Health minus dmaage_taken

    // GETTER FUNCTIONS
        string getOpponentName();
        int getOpponentHealth();
        int getOpponentMaxHealth();
        int getOpponentLevel();
        int getOpponentBaseDamage();
        int getOpponentMaxDamage();
        int getPotionAmount();
};

#endif