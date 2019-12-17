/*******************************************************************************************

*

*   raylib game: FINAL PONG - game template

*

*   developed by [STUDENT Iván Carrizosa]

*

*   This example has been created using raylib 1.0 (www.raylib.com)

*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)

*

*   Copyright (c) 2014 Ramon Santamaria (Ray San)

*

********************************************************************************************/



#include "raylib.h"

#include <stdio.h>

#include <stdlib.h>



typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;



int main()

{

    // Initialization

    //--------------------------------------------------------------------------------------

    int screenWidth = 800;

    int screenHeight = 450;

    int velocidady = 8;

    char windowTitle[30] = "raylib game - FINAL PONG";

    

    GameScreen screen = LOGO;

    

    // TODO: Define required variables here..........................(0.5p)

    char *texto;

    Vector2 tamanoTexto;

    // NOTE: Here there are some useful variables (should be initialized)

    

    Rectangle player;

    

    player.width = 20;

    player.height = 100;    

    player.x = 50;

    player.y = screenHeight/2 - player.height/2;

    

    Rectangle enemy;

    

    enemy.width = 20;

    enemy.height = 100;    

    enemy.x = screenWidth - 50 - enemy.width;

    enemy.y = screenHeight/2 - enemy.height/2;

    

    

    Vector2 ball;

    

    ball.x = screenWidth/2;

    ball.y = screenHeight/2;

    

    int playerSpeedY;

    int enemySpeed = 2;

    

    int maxVelocity = 8;

    int minVelocity = 8;

    

    Vector2 ballVelocity;

    

    ballVelocity.x = minVelocity;

    ballVelocity.y = minVelocity;

    //int ballRadius;

    int ballSize = 25;

    

    int playerLife;

    int enemyLife;

    

    //

    

    int frameCount = 0;

    int frameCount2 = 0;

    int timeCounter = 0;

    

    Rectangle backRect = { screenWidth/2 - 200, screenHeight/2 - 50, 400, 100}; //Background Rectangle

    int margin = 5; 

    Rectangle fillRect = { backRect.x + margin, backRect.y + margin, backRect.width - (2 * margin), backRect.height - (2 * margin)};

    Rectangle lifeRect = fillRect;

    lifeRect.width /= 2;

    Color lifeColor = YELLOW;

    

    bool blink = true;

    bool win = false;

    bool lose = false;

    

    int winNum = 0;

    int loseNum = 0;

    

    int drainLife = 1;

    int healLife = 3;

    

    //

    

    bool pause = false;

    

    int secondsCounter = 99;

    

    int framesCounter;          // General pourpose frames counter

    

    int gameResult = -1;        // 0 - Loose, 1 - Win, -1 - Not defined

    

    int iaLinex = screenWidth/2;

    

    InitWindow(screenWidth, screenHeight, windowTitle);

    

    // NOTE: If using textures, declare Texture2D variables here (after InitWindow)

    // NOTE: If using SpriteFonts, declare SpriteFont variables here (after InitWindow)

    

    // NOTE: If using sound or music, InitAudioDevice() and load Sound variables here (after InitAudioDevice)

    InitAudioDevice();

    

    SetTargetFPS(60);

    //--------------------------------------------------------------------------------------

    

    // Main game loop

    while (!WindowShouldClose())    // Detect window close button or ESC key

    {

        // Update

        //----------------------------------------------------------------------------------

        switch(screen) 

        {

            case LOGO: 

            {

                // Update LOGO screen data here!

                

                // TODO: Logo fadeIn and fadeOut logic...............(0.5p)

                

                

                if (IsKeyPressed(KEY_ENTER))

                     screen = TITLE;                             

            } break; 

            case TITLE: 

            {

                // Update TITLE screen data here!

                

                // TODO: Title animation logic.......................(0.5p)

                

                // TODO: "PRESS ENTER" logic.........................(0.5p)

                

                

                if (IsKeyPressed(KEY_ENTER))

                     screen = GAMEPLAY;

            } break;

            case GAMEPLAY:

            { 

                // Update GAMEPLAY screen data here!



                // TODO: Ball movement logic.........................(0.2p)

                if(ball.x > screenWidth - ballSize){

                    //Marca la pala izquierda

                    //PlaySound(fxGoal);

                    //player++;

                    ball.x = screenWidth/2;

                    ball.y = screenHeight/2;

                    ballVelocity.x = -minVelocity;

                    ballVelocity.y = minVelocity;

                   

                }else if(ball.x < ballSize){

                    //Marca la pala derecha

                    //PlaySound(fxGoal);

                    //enemy++;

                    ball.x = screenWidth/2;

                    ball.y = screenHeight/2;

                    ballVelocity.x = minVelocity;

                    ballVelocity.y = minVelocity;

                }

               

                 if((ball.y > screenHeight - ballSize) || (ball.y < ballSize) ){

                    ballVelocity.y *=-1;

                    //PlaySound(fxWav);

                }

                

                // TODO: Player movement logic.......................(0.2p)

                  if (IsKeyDown(KEY_UP)){

                  player.y -= velocidady;

                }

               

                  if (IsKeyDown(KEY_DOWN)){

                  player.y += velocidady;

                }

                

                // TODO: Enemy movement logic (IA)...................(1p)

                    if( ball.x > iaLinex){

                    if(ball.y > enemy.y)

                    enemy.y+=velocidady;

                }

               

                    if(ball.y < enemy.y){

                    enemy.y-=velocidady;

                }

            

                

                // TODO: Collision detection (ball-player) logic.....(0.5p)

                    if(player.y<0){

                    player.y = 0;

                }

               

                    if(player.y > (screenHeight - player.height)){

                    player.y = screenHeight - player.height;

                }

                

                if(CheckCollisionCircleRec(ball, ballSize, player)){

                if(ballVelocity.x<0){

                        //PlaySound(fxWav);

                    if(abs(ballVelocity.x)<maxVelocity){                    

                            ballVelocity.x *=-1.5;

                            ballVelocity.y *= 1.5;

                        }else{

                            ballVelocity.x *=-1;

                        }

                    }

                }                 

                

                // TODO: Collision detection (ball-enemy) logic......(0.5p)

                if(enemy.y<0){

                    enemy.y = 0;

                }

               

                if(enemy.y > (screenHeight - enemy.height)){

                    enemy.y = screenHeight - enemy.height;

                }

                

                    if(CheckCollisionCircleRec(ball, ballSize, enemy)){

                    if(ballVelocity.x>0){

                        //PlaySound(fxWav);

                        if(abs(ballVelocity.x)<maxVelocity){                    

                            ballVelocity.x *=-1.5;

                            ballVelocity.y *= 1.5;

                        }else{

                            ballVelocity.x *=-1;

                        }

                    }

                }

                

                // TODO: Collision detection (ball-limits) logic.....(1p)

                if(!pause){

                    ball.x += ballVelocity.x;

                    ball.y += ballVelocity.y;

                }

                

                // TODO: Life bars decrease logic....................(1p)

                

                    if (!win && !lose)

                {

                    if (ball.x > screenWidth - ballSize) lifeRect.width -= healLife;

                    

                

                    if (lifeRect.width <= 0)

                    {

                        lose = true;

                        ++loseNum;

                        lifeRect.width = 0;        

                    }

                    

                    

                    frameCount--;

                    if (frameCount%20  == 0)

                    {

                        blink = !blink;

                        frameCount = 0;

                    }

                    

                    frameCount2--;

                    if (frameCount2%60 == 0)

                    {

                        timeCounter++;

                        frameCount2 = 0;

                    }

                    

                    if (lifeRect.width >= 2*(fillRect.width/3)) 

                    {

                        lifeColor = GREEN;

                    } 

                    

                    else if (lifeRect.width <= fillRect.width/3) 

                    {

                        lifeColor = ORANGE;

                    }

                    

                    else 

                    {

                        lifeColor = YELLOW;

                    }

                }

                     

                else 

                {

                    blink = false;

                    if (IsKeyPressed(KEY_R))

                    {

                        win = false;

                        lose = false;

                        lifeRect.width = fillRect.width/2;

                    }

                }



                // TODO: Time counter logic..........................(0.2p)



                // TODO: Game ending logic...........................(0.2p)

                

                // TODO: Pause button logic..........................(0.2p)

                if (IsKeyPressed(KEY_P)){

                pause = !pause;

                }

                

            } break;

            case ENDING: 

            {

                // Update END screen data here!

                

                // TODO: Replay / Exit game logic....................(0.5p)

                

            } break;

            default: break;

        }

        //----------------------------------------------------------------------------------

        

        // Draw

        //----------------------------------------------------------------------------------

        BeginDrawing();

        

            ClearBackground(WHITE);

            

            switch(screen) 

            {

                case LOGO: 

                {

                    // Draw LOGO screen here!

                    

                    // TODO: Draw Logo...............................(0.2p)

                    

                } break;

                case TITLE: 

                {

                    // Draw TITLE screen here!

                    

                    // TODO: Draw Title..............................(0.2p)

                    

                    // TODO: Draw "PRESS ENTER" message..............(0.2p)

                    

                } break;

                case GAMEPLAY:

                { 

                    // Draw GAMEPLAY screen here!

                    DrawLine(iaLinex, 0, iaLinex , screenHeight, BLACK);

                    // TODO: Draw player and enemy...................(0.2p)

                    DrawRectangleRec(player, GREEN);                              

                    DrawRectangleRec(enemy, GREEN);

                    DrawCircleV(ball, ballSize, BLACK);

                            

                    // TODO: Draw player and enemy life bars.........(0.5p)

                    

                    DrawRectangleRec (backRect, BLACK);

                    DrawRectangleRec (fillRect, RED);

                    DrawRectangleRec (lifeRect, lifeColor);

                    if (win == false && lose == false) //DrawText("Press Space!", (screenWidth - MeasureText("Press Space!", 60))/2, screenHeight/2 - (screenHeight/4), 60, BLACK);

                    if (blink) DrawText("FIGHT!", (screenWidth - MeasureText("FIGHT!", 60))/2, screenHeight/2 + (screenHeight/5), 60, BLACK);

                    if (win) DrawText("YOU WIN!", (screenWidth - MeasureText("YOU WIN!", 60))/2, screenHeight/2 - (screenHeight/4), 60, GREEN);

                    if (lose) DrawText("YOU LOSE...", (screenWidth - MeasureText("YOU LOSE...", 60))/2, screenHeight/2 - (screenHeight/4), 60, RED);

                    if (win || lose) DrawText("PRESS R TO RETRY", (screenWidth - MeasureText("PRESS R TO RETRY", 40))/2, screenHeight/2 + (screenHeight/5), 40, PURPLE);

                    if (lifeRect.width <= fillRect.width/3) DrawText("NEVER GIVE UP!", (screenWidth - MeasureText("NEVER GIVE UP!", 40))/2, screenHeight/2 + (screenHeight/3), 40, ORANGE);

                    if (lifeRect.width <= 2*(fillRect.width/3)) DrawText("YOU'RE ALMOST THERE!", (screenWidth - MeasureText("YOU'RE ALMOST THERE!", 40))/2, screenHeight/2 + (screenHeight/3), 40, GREEN);

                    

                    DrawText(FormatText("Wins: %i", winNum), screenWidth/4 - MeasureText(FormatText("Wins: %i", winNum), 40)/2, screenHeight/7, 40, BLACK); 

                    DrawText(FormatText("Loses: %i", loseNum), 3*screenWidth/4 - MeasureText(FormatText("Loses: %i", loseNum), 40)/2, screenHeight/7, 40, BLACK); 

                    

                    // TODO: Draw time counter.......................(0.5p)

                    

                    // TODO: Draw pause message when required........(0.5p)

                    if(pause){

                        DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 255, 0, 255/2 });  

                        DrawText("Press p to continue", screenWidth/2 - MeasureText("Press p to continue", 40)/2 , screenHeight/2, 40, RED);

                    }

                            

                } break;

                case ENDING: 

                {

                    // Draw END screen here!

                    

                    // TODO: Draw ending message (win or loose)......(0.2p)

                    

                } break;

                default: break;

            }

        

            DrawFPS(10, 10);

        

        EndDrawing();

        //----------------------------------------------------------------------------------

    }



    // De-Initialization

    //--------------------------------------------------------------------------------------

    

    // NOTE: Unload any Texture2D or SpriteFont loaded here 

  

    

    CloseWindow();        

    //--------------------------------------------------------------------------------------

    

        return 0;

}