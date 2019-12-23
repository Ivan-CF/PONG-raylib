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
    
    // TODO: Define required variables here..........................(0.5p)
    GameScreen screen = LOGO;
    
    bool fadeOut = true;
    float alpha = 0;
    float fadeSpeed = 0.01f;
    
    
    bool fadeOut2 = true;
    float alpha2 = 0;
    float fadeSpeed2 = 0.01f;
    
    int secondsCounter = 99;
    
    
    
    
    // NOTE: Here there are some useful variables (should be initialized)
    
    Rectangle player;
    
    player.width = 20;
    player.height = 100;    
    player.x = 50;
    player.y = screenHeight/2 - player.height/2;
    
    Rectangle enemy;
    
    enemy.width = 20;
    enemy.height = 2;    
    enemy.x = screenWidth - 50 - enemy.width;
    enemy.y = screenHeight/2 - enemy.height/2;
    
    //int ballRadius;
    int maxVelocity = 8;
    int minVelocity = 8;
    
    int ballSize = 15;
    
    Vector2 ball;
    
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    
    Vector2 ballVelocity;
    
    ballVelocity.x = minVelocity;
    ballVelocity.y = minVelocity;
    
    int enemySpeed = 1;
    

    //int ballRadius;

    
    //



    
    Rectangle backRect = { 30, 25, 100, 15} ; //Background Rectangle
    int margin = 2; 
    Rectangle fillRect = { backRect.x + margin, backRect.y + margin, backRect.width - (2 * margin), backRect.height - (2 * margin)};
    Rectangle lifeRect = fillRect;
    lifeRect.width = 96;
    Color lifeColor = GREEN;
    
    Rectangle backRect2 = { screenWidth - 140, 25, 100, 15} ; //Background Rectangle
    int margin2 = 2; 
    Rectangle fillRect2 = { backRect2.x + margin2, backRect2.y + margin2, backRect2.width - (2 * margin2), backRect2.height - (2 * margin2)};
    Rectangle lifeRect2 = fillRect2;
    lifeRect2.width = 96;
    Color lifeColor2 = GREEN;
    
   
    
    bool blink = true;
    bool win = false;
    bool lose = false;
    

    
    int drainLife = 1;
    int healLife = 3;
    
    //
    
    bool pause = false;
    

    
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

              if(fadeOut)
            {
                alpha += fadeSpeed;
               
                if(alpha >= 1.0f)
                {
                    alpha = 1.0f;
                }
            }
            else
            {
                alpha -= fadeSpeed;
                if(alpha <= 0.0f)
                {
                    alpha = 0.0f;
                }
            }
           
            if (alpha >= 1.0f)
            {
                fadeOut = !fadeOut;              
            }
            
            if (alpha == 0.0f)
            {
                screen = TITLE;
            }
            } break; 
            
            case TITLE: 
            {
                // Update TITLE screen data here!
                
                // TODO: Title animation logic.......................(0.5p)
                if(fadeOut2)
            {
                alpha2 += fadeSpeed2;
               
                if(alpha2 >= 1.0f)
                {
                    alpha2 = 1.0f;
                }
            }
            else
            {
                alpha2 -= fadeSpeed2;
                if(alpha2 <= 0.0f)
                {
                    alpha2 = 0.0f;
                }
            }
                        
            // TODO: "PRESS ENTER" logic.........................(0.5p)
            if (IsKeyPressed(KEY_ENTER)) screen = GAMEPLAY;
               
               framesCounter++;
                
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
                    lifeRect2.width -= 20;
                    
                    
                   
                }else if(ball.x < ballSize){
                    //Marca la pala derecha
                    //PlaySound(fxGoal);
                    //enemy++;
                    ball.x = screenWidth/2;
                    ball.y = screenHeight/2;
                    ballVelocity.x = minVelocity;
                    ballVelocity.y = minVelocity;
                    lifeRect.width -= 20;
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
                    enemy.y+=enemySpeed;
                }
               
                    if(ball.y < enemy.y){
                    enemy.y-=enemySpeed;
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
                

                // TODO: Time counter logic..........................(0.2p)
                    if (!(framesCounter++%60)){
                        secondsCounter --;
                    }

                // TODO: Game ending logic...........................(0.2p)
                if (lifeRect.width <= 0 || lifeRect2.width <= 0 || secondsCounter < 0) screen = ENDING;               
                // TODO: Pause button logic..........................(0.2p)
                if (IsKeyPressed(KEY_P)){
                pause = !pause;
                }
                
            } break;
            case ENDING: 
            {
                // Update END screen data here!
                
                // TODO: Replay / Exit game logic....................(0.5p)

                
            if (IsKeyPressed(KEY_R)){
               screen = GAMEPLAY;
               lifeRect.width = 96;
               lifeRect2.width = 96;
               ball.x = screenWidth/2;
               ball.y = screenHeight/2;
               secondsCounter = 99;
            } 
                
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
                    DrawText("Programmed with 'Raylib' by Ivan Carrizosa",25,200,35, Fade(BROWN, alpha));
                
                    
                } break;
                case TITLE: 
                {
                    // Draw TITLE screen here!
                    
                    // TODO: Draw Title..............................(0.2p)
                    DrawText("FINAL PONG", 100, 100, 100,Fade(BEIGE, alpha2));
                   
                    
                    // TODO: Draw "PRESS ENTER" message..............(0.2p)
                    if ((framesCounter/30)%2) DrawText("PRESS ENTER", 300, 300, 30, BLUE);
                    
                } break;
                case GAMEPLAY:
                { 
                    // Draw GAMEPLAY screen here!
                    DrawLine(iaLinex, 0, iaLinex , screenHeight, BLACK);
                    // TODO: Draw player and enemy...................(0.2p)
                    DrawRectangleRec(player, BLUE);                              
                    DrawRectangleRec(enemy, RED);
                    DrawCircleV(ball, ballSize, BLACK);
                            
                    // TODO: Draw player and enemy life bars.........(0.5p)
                    
                    DrawRectangleRec (backRect, BLACK);
                    DrawRectangleRec (backRect2, BLACK);
                    DrawRectangleRec (lifeRect, lifeColor);
                    DrawRectangleRec (lifeRect2, lifeColor2);
                                       
                    // TODO: Draw time counter.......................(0.5p)
                    DrawText(FormatText("%i", secondsCounter), screenWidth/2 - 20, 10 , 40, BROWN);
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
                    if(lifeRect.width <= 0){
                        DrawText("WINNER IS ENEMY", screenWidth/2 + 100, screenHeight/2 + 20, 30, RED);
                        DrawText("ERES UNA MIERDA", screenWidth/2 - 350, screenHeight/2 + 20, 30, BLUE);
                    }
                    if(lifeRect2.width <= 0){
                        DrawText("WINNER IS PLAYER 1", screenWidth/2 - 350, screenHeight/2 + 20, 30, BLUE);
                        DrawText("VA OTRA, CAGAO!", screenWidth/2 + 50, screenHeight/2 + 20, 30, RED);
                    }
                    if (secondsCounter < 0){
                        DrawText("FIN DEL TIEMPO, ES UN EMPATE", screenWidth/2 - 100, screenHeight/2, 30, ORANGE);
                    }
                DrawText("Press R to PLAY AGAIN", 250, 320, 20, GRAY);
                DrawText("Press ESCAPE to QUIT", 250, 360, 20, GRAY);
                if (IsKeyPressed(KEY_R)){

                screen = GAMEPLAY;
                }
                    
                } break;
                default: break;
            }
        
           // DrawFPS(10, 10);
        
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