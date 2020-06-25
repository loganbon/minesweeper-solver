#include "Board.h"

Board::Board(int level) {
    switch (level) {
        case 1:
            width = 8; height = 8;
            break;
        case 2:
            width = 16; height = 16;
            break;
        default:
            width = 30; height = 16;
            break;
    }
}
