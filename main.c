#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
    SetTargetFPS(60);

    //Jogador
    float playerX = 50;
    float playerY = (SCREEN_HEIGHT / 2) - 50;
    float playerWidth = 10;
    float playerHeight = 100;

    //Oponent
    float opponentX = SCREEN_WIDTH - 50 - 10;
    float opponentY = (SCREEN_HEIGHT / 2) - 50;
    float opponentWidth = 10;
    float opponentHeight = 100;

    //Bola
    float ballX = SCREEN_WIDTH / 2;
    float ballY = SCREEN_HEIGHT / 2;
    float ballRadius = 8;

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            //Desenha jogador
            DrawRectangle(playerX, playerY, playerWidth, playerHeight, WHITE);
            //Desenha oponente
            DrawRectangle(opponentX, opponentY, opponentWidth, opponentHeight, WHITE);
            //Desenha bola
            DrawCircle(ballX, ballY, ballRadius, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
