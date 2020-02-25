#include <iostream>
#include <stdlib.h> 
#include <array>

#include <thread>
#include <chrono>

using std::array;

const int xWidth = 25;
const int yWidth = 25;

// functions say hello
int countDeadCells(array<array<bool, xWidth>, yWidth>& gameField, int x, int y);

array<array<bool, xWidth>, yWidth>& simulateRound(array<array<bool, xWidth>, yWidth> &gameField) {
    array<array<bool, xWidth>, yWidth> gameFieldNew{};
    for (size_t x = 0; x < xWidth; x++) {
        for (size_t y = 0; y < yWidth; y++) {
            int deadCells;
            deadCells = 0;
            // cell dead
            if (gameField[x][y] == false) {
                deadCells = countDeadCells(gameField, x, y);
                if (deadCells == 5) {
                    gameFieldNew[x][y] = true;
                }
            }
            else {
                deadCells = countDeadCells(gameField, x, y);
                if (deadCells == 5 || deadCells == 6) {
                    gameFieldNew[x][y] = true;
                }
                else {
                    // nothing to do here
                }
            }
        }
    }
    // TODO: nicer possibility (new)
    gameField = gameFieldNew;
    return gameField;
}


int countDeadCells(array<array<bool, xWidth>, yWidth>& gameField, int x, int y) {
    int livingCells = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int xCoordinate = x + i;
            int yCoordinate = y + j;
            if (xCoordinate >= 0 && yCoordinate >= 0 && xCoordinate < xWidth && yCoordinate < yWidth) {
                if (gameField[xCoordinate][yCoordinate] == true) {
                    livingCells++;
                }
            }
        }
    }
    int deadCells = 8 - livingCells;
    return deadCells;
}

void printArray(array<array<bool, xWidth>, yWidth>& gameField) {
    for (size_t x = 0; x < xWidth; x++) {
        // std::cout << "x Wert: " <<x;
        for (size_t y = 0; y < yWidth; y++) {
            // std::cout << "y Wert: " <<y;
            if (gameField[x][y] == false) {
                std::cout << "  ";
            }
            else {
                std::cout << " *";
            }
            // std::cout << gameField[x][y];
        }
        std::cout << std::endl;
    }
}

int main() {
    // create a game Field
    array<array<bool, xWidth>, yWidth> gameField{};
    
    // generate random living cells
    int x, y;
    int i = 1;
    while(i < 150) {
        /* generate random numbers between 0 and Widths: */
        x = rand() % xWidth;
        y = rand() % yWidth;

        if (gameField[x][y] == false) {
            gameField[x][y] = true;
            i++;
        }
    }
    
    while (1) {
        printArray(gameField);       
        gameField = simulateRound(gameField);        
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        // everything inside system -> sent to command promt
        // since using powershell -> clear
        system("clear");
    }
}
