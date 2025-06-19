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
    float playerSpeed = 350.0f;

    //Oponent
    float opponentX = SCREEN_WIDTH - 50 - 10;
    float opponentY = (SCREEN_HEIGHT / 2) - 50;
    float opponentWidth = 10;
    float opponentHeight = 100;

    //Bola
    float ballX = SCREEN_WIDTH / 2;
    float ballY = SCREEN_HEIGHT / 2;
    float ballRadius = 8;
    float ballSpeedX = 250.0f;
    float ballSpeedY = 250.0f;

    while(!WindowShouldClose()) {
        //Pega o delta time
        float dt = GetFrameTime();

        //Lógica para o jogador
        //Verifica se a teclad W está sendo pressionada e altera a lógica da posição do jogador
        if(IsKeyDown(KEY_W)) {
            playerY -= playerSpeed * dt;
        }

        if(IsKeyDown(KEY_S)) {
            playerY += playerSpeed * dt;
        }

        //Deixa a raquete dentro dos limites da tela
        if(playerY < 0) {
            playerY = 0;
        }

        if(playerY + playerHeight > SCREEN_HEIGHT) {
            playerY = SCREEN_HEIGHT - playerHeight;
        }

        //Lógica para a bola
        ballX += ballSpeedX * dt;
        ballY += ballSpeedY * dt;

        if(ballY - ballRadius < 0) {
            ballSpeedY *= -1;
        }

        if(ballY + ballRadius > SCREEN_HEIGHT) {
            ballSpeedY *= -1;
        }

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
