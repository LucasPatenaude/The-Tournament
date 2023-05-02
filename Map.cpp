#include "Map.h"

using namespace std;

Map::Map()
{
    resetMap();
}

/*
 * Algorithm: Resets positions of player, NPCs, and rooms and clears map_data_
 * Set Player position coordinates to 0
 * Set npc_count_ to false
 * Set room_count_ to 0
 * loop i from 0 to max_npcs_
 *      Set row and col of location to -1
 * loop i from 0 to max_rooms
 *      Set row and col of room location to -1
 * loop i from 0 to num_rows_
 *      loop j from 0 to num_cols_
 *          Set (i,j) location on map_data_ to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap()
{
    // resets player position, count values, and initializes values in position arrays to -1
    player_position_[0] = 0; //Puts Player in top row
    player_position_[1] = num_cols_/2; // Centers Players

    // set ship exit
    ship_exit_[0] = num_rows_ - 2; // Set Exit to second last row
    ship_exit_[1] = num_cols_ / 2; // Set exit in middle

    // set bed position on map
    ship_bed_[0] = 5;
    ship_bed_[1] = 0;

    for (int i = 0; i < max_rooms_; i++)
    {
        room_positions_[i][0] = -1;
        room_positions_[i][1] = -1;
    }

    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            map_data_[i][j] = SHIP;
        }
    }
    map_data_[ship_exit_[0]][ship_exit_[1]] = EXIT;
    map_data_[ship_bed_[0]][ship_bed_[1]] = BED;
}

// return player's row position
int Map::getPlayerRow()
{
    return player_position_[0];
}

// return player's column position
int Map::getPlayerCol()
{
    return player_position_[1];
}

// return ship exit row
int Map::getShipExitRow()
{
    return ship_exit_[0];
}

// return ship exit col
int Map::getShipExitCol()
{
    return ship_exit_[1];
}

// set player position, if in range
void Map::setPlayerPosition(int row, int col)
{
    if (isOnMap(row, col))
    {
        player_position_[0] = row;
        player_position_[1] = col;
    }
}

// set ship exit position, if in range
void Map::setShipExit(int row, int col)
{
    if (isOnMap(row, col))
    {
        ship_exit_[0] = row;
        ship_exit_[1] = col;
    }
}

// set location of players bed
void Map::setShipBed(int row, int col)
{
    if (isOnMap(row, col))
    {
        ship_bed_[0] = row;
        ship_bed_[1] = col;
    }
}

// returns member variable num_rows_
int Map::getNumRows()
{
    return num_rows_;
}

// returns member variable num_cols_
int Map::getNumCols()
{
    return num_cols_;
}

/*
 * @brief Checks if the given (row, col) position is on the map
 *
 * Algorithm:
 *  if 0 <= row < num_rows_ and 0 <= col < num_cols_:
 *      return true
 *  else:
 *      return false
 *
 * Parameters: row (int), col (int)
 * Returns: bool
 */
bool Map::isOnMap(int row, int col)
{
    if (0 <= row && row < num_rows_ && 0 <= col && col < num_cols_)
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: checks if (row, col) is ship_exit_
 *
 */
bool Map::isShipExit(int row, int col)
{
    if (row == ship_exit_[0] && col == ship_exit_[1])
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: checks if (row, col) is ship_exit_
 *
 */
bool Map::isShipBed(int row, int col)
{
    if (row == ship_bed_[0] && col == ship_bed_[1])
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: Make the player move based on the given command
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 * if player moved
 *      if new location is an NPC location
 *          mark new location as explored
 *      return true
 * else
 *      return false
 *
 * Parameters: direction (char)
 * Return: boolean (bool)
 */
bool Map::move(char direction)
{
    // check input char and move accordingly
    switch (tolower(direction))
    {
    case 'w': // if user inputs w, move up if it is an allowed move
        if (player_position_[0] > 0)
        {
            player_position_[0] -= 1;
        }
        else // Keep user in bounds
        {
            return false;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1)
        {
            player_position_[0] += 1;
        }
        else // Keep user in bounds
        {
            return false;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0)
        {
            player_position_[1] -= 1;
        }
        else // Keep user in bounds
        {
            return false;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1)
        {
            player_position_[1] += 1;
        }
        else // Keep user in bounds
        {
            return false;
        }
        break;
    default:
        return false;
    }
    return true;
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print 'X'
 *          else if npc is at (i,j)
 *              if npc has been found:
 *                  print 'N'
 *              else
 *                  print '-'
 *          else
 *              print the value of (i,j) in map_data_
 *
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap()
{
    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            if (player_position_[0] == i && player_position_[1] == j)
            {
                cout << FIGHTER;
            }
            else
            {
                cout << map_data_[i][j];
            }
        }
        cout << endl;
    }
}
