#include <emscripten.h>
#include <cstdlib>
#include <ctime>

extern "C" {

    EMSCRIPTEN_KEEPALIVE
    void initGame() { std::srand(std::time(nullptr)); }

    EMSCRIPTEN_KEEPALIVE
    int computerMove() { return std::rand() % 3; }

    EMSCRIPTEN_KEEPALIVE
    int checkWinner(int player, int computer) {
        if (player == computer) return 0;
        if ((player == 0 && computer == 2) ||
            (player == 1 && computer == 0) ||
            (player == 2 && computer == 1)) return 1;
        return -1;
    }

}