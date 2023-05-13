# Welcome to the Tournament

**To Boot** 

1. g++ -std=c++14 The_Tournament.cpp Weapon.cpp User.cpp Armor.cpp Potion.cpp Map.cpp Opponent.cpp
 
2. ./a.out

## Missed Implementations

### Save/Load Not Functional [Ran out of time]

In my final vision of this game it had a save/load function. My plan was to use file I/O to output the user's gear values to a text file which would then be saved to a folder called Game_Saves in the program when a user decides to exit. The game was initially designed to ask the user if they would like to do a new game or load a file but ultimately that had to be cut due to time. If I were to have I imagine the load function would been implemented by putting a label at each line like primary for the primary weapon, or helmet for the user's helmet which would then be seaparared by a separator character, which would then be followed the that weapons or gears unique attributes separated by the separator. Then a if/else would be used to filter each thing to the right object or array.

### Item Upgrades/Destruction [Ran out of time]

One of the things I wanted to add to the map/ship were two stations that could each modify weapons and armor respectively. These upgrades would've been bought from the Forge, saved into an array of type Obejcts (another class, I know) which could then return an integer value to modify a Weapon object.

Each weapon also had the idea to decremented once each cycle through combat but that didn't come out very balanced. This was something that coud be implemented easily but I didn't like how it added to gameplay

### Scoreboard/Record of Opponents [Ran out of time]

Another thing I wanted to implement into the ship/map was a scorebaord or list of opponents beaten with their names. Unfortunately, this had to be cut as a time-based decision.

### About

In the post-dystopian future world of "The Tournament," players arrive on the Planet Kumite aboard their spaceship, ready to take on the challenges of the most brutal and blood-soaked competition in the galaxy. The atmosphere is grim and dangerous, with a sense of lawlessness that permeates the air. As players disembark from their ship and step onto the dusty surface of the planet, they are immediately met with a sense of unease.

The first area that players can visit is their ship, where they can replenish their health and take stock of their weapons and gear. The ship is a haven in the midst of chaos, a place where players can regroup and prepare themselves for the next round of battles. But they must be careful not to linger too long, as danger is always lurking just outside.

The Forge, the in-game shop, is the second area that players can explore. Here, they will find a bustling marketplace filled with craftsmen and merchants hawking their wares. The Forge is a lively and colorful place, full of noise and energy, but it's also a place where players must exercise caution. The merchants here are known to be ruthless and cunning, always looking for an opportunity to make a quick profit.

The arena is where the real thrills of "The Tournament" can be found. It's a place of violence and bloodshed, where only the strongest and most skilled will survive. The arena is a massive, circular structure with towering walls and a domed roof that shields the spectators from the scorching sun. As players step into the arena, they are met with a roar of the crowd, a sea of cheering fans and bloodthirsty gamblers eager to see the action unfold.

In the arena, players will face off against a variety of opponents, each with their own unique fighting style and set of abilities. The battles are intense and frenzied, with players dodging and weaving, striking and parrying in a blur of motion. The rewards for victory are handsome, with massive payouts and valuable loot awaiting those who emerge victorious.

Overall, "The Tournament" is a thrilling and immersive game that captures the spirit of a post-dystopian future world. With its fast-paced combat, diverse cast of characters, and richly detailed environments, it's sure to be a hit with gamers looking for an unforgettable gaming experience. So sharpen your blades, stock up on ammo, and get ready for the fight of your life in "The Tournament."

## Mechanics

### The Ship

The ship where you'll find your bed. If you go to you bed you'll fully reheal your health

### The Forge

The Forge is where you'll find all items for purchase. There is no selling in this game. You're expected to keep buying between turns

The Forge is where you can buy weapons, armor, or potions. All weapons and armor are random each time you enter.

### The Arena

The Arena is where all the planning comes to play. Each opponent you get is random and could be slightly better to slightly worse. They are at least guarenteed to be within two levels of you. Don't worry about winning off the bat. You may get opponents better than you.

# !!Don't Forget to Buy Potions Between Turns and Upgrade Your Gear!!
