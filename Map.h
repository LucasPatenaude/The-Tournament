
#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
private:
    const char SHIP = '-';
    const char BED = 'B';      // marker for room locations
    const char FIGHTER = 'o';      // marker for party position
    const char EXIT = 'H';       // marker for ship exit

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_npcs_ = 5;  // max non-player characters
    static const int max_rooms_ = 5; // max number of rooms

    int player_position_[2];              // player position (row,col)
    int ship_exit_[2];  
    int ship_bed_[2];               // exit location of the ship
    int npc_positions_[max_npcs_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int room_positions_[max_rooms_][2];   // stores the (row,col) positions of rooms present on map
    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

    int npc_count_;  // stores number of misfortunes currently on map
    int room_count_; // stores number of sites currently on map
public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getShipExitRow();
    int getShipExitCol();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isShipExit(int row, int col);
    bool isShipBed(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);
    void setShipExit(int row, int col);
    void setShipBed(int row, int col);

    // other
    void displayMap();
    bool move(char);
};

#endif