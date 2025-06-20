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
    float opponentSpeed = 300.0f;

    //Bola
    float ballX = SCREEN_WIDTH / 2;
    float ballY = SCREEN_HEIGHT / 2;
    float ballRadius = 8;
    float ballSpeedX = 250.0f;
    float ballSpeedY = 250.0f;

    //Pontuação
    int playerScore = 0;
    int opponentScore = 0;

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

        //Ia do oponente
        float opponentCenterY = opponentY + (opponentHeight / 2.0f);

        if(opponentCenterY < ballY) {
            opponentY += opponentSpeed * dt;
        }

        if(opponentCenterY > ballY) {
            opponentY -= opponentSpeed * dt;
        }

        //Limites na tela para o oponente
        if(opponentY < 0) {
            opponentY = 0;
        }

        if(opponentY + opponentHeight > SCREEN_HEIGHT) {
            opponentY = SCREEN_HEIGHT - opponentHeight;
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

        //Colisao da bola com os retangulos
        Rectangle playerRectangle = {playerX, playerY, playerWidth, playerHeight};
        Rectangle opponentRectangle = {opponentX, opponentY, opponentWidth, opponentHeight};
        Vector2 ball = {ballX, ballY,};

        if(CheckCollisionCircleRec(ball, ballRadius, playerRectangle) || CheckCollisionCircleRec(ball, ballRadius, opponentRectangle)) {
            ballSpeedX *= -1;

            //Acelera a bola gradativamente
            float aceleracao = 20.0f;

            if(ballSpeedX > 0) {
                ballSpeedX += aceleracao;
            } else {
                ballSpeedX -= aceleracao;
            }

            if(ballSpeedY > 0) {
                ballSpeedY += aceleracao;
            } else {
                ballSpeedY -= aceleracao;
            }
        }

        //Lógica de pontos e reset
        if(ballX - ballRadius < 0) {
            opponentScore++;

            ballX = SCREEN_WIDTH / 2.0f;
            ballY = SCREEN_HEIGHT /2.0f;

            ballSpeedX = -250.0f;
            ballSpeedY = 250.0f;
        }

        if(ballX + ballRadius > SCREEN_WIDTH) {
            playerScore++;

            ballX = SCREEN_WIDTH / 2.0f;
            ballY = SCREEN_HEIGHT / 2.0f;

            ballSpeedX = 250.0f;
            ballSpeedY = 250.0f;
        }

        //Desenhar na tela
        BeginDrawing();
            ClearBackground(BLACK);
            //Desenha jogador
            DrawRectangle(playerX, playerY, playerWidth, playerHeight, WHITE);
            //Desenha oponente
            DrawRectangle(opponentX, opponentY, opponentWidth, opponentHeight, WHITE);
            //Desenha bola
            DrawCircle(ballX, ballY, ballRadius, WHITE);
            //Desenha placar
            const char *playerScoreText = TextFormat("%d", playerScore);
            const char *opponentScoreText = TextFormat("%d", opponentScore);

            DrawText(playerScoreText, SCREEN_WIDTH / 4, 20, 40, WHITE);
            DrawText(opponentScoreText, 3 * SCREEN_WIDTH / 4 - 40, 20, 40, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
