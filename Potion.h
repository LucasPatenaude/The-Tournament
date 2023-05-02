#ifndef POTION_H
#define POTION_H

#include<iostream>
using namespace std;

class Potion 
{
    private:
        string name;
        int heal_amount;
        int value;
        int amount;
        int potions_amount;

    public:
        Potion();
        Potion(string potion_name, int amount_provided, int cost);
    
    // SETTER FUNCTIONS
        void setPotionName(string name);
        void setPotionValue(int cost);
        void addPotion();
        void subtractPotion();

    // GETTER FUNCTIONS
        string getPotionName();
        int getPotionValue();
        int getPotionAmount();
};

#endif