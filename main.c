#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Game Loop funcionando!", 200, 150, 30, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
