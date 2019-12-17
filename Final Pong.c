/*******************************************************************************************
*
*   raylib game: FINAL PONG - game template
*
*   developed by [STUDENT NAME HERE]
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (Ray San)
*
********************************************************************************************/

#include "raylib.h"

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    char windowTitle[30] = "raylib game - FINAL PONG";
    
    GameScreen screen = LOGO;
    
    // TODO: Define required variables here..........................(0.5p)
    // NOTE: Here there are some useful variables (should be initialized)
    Rectangle player;
    int playerSpeedY;
    
    Rectangle enemy;
    int enemySpeedY;
    
    Vector2 ballPosition;
    Vector2 ballSpeed;
    int ballRadius;
    
    int playerLife;
    int enemyLife;
    
    int secondsCounter = 99;
    
    int framesCounter;          // General pourpose frames counter
    
    int gameResult = -1;        // 0 - Loose, 1 - Win, -1 - Not defined
    
    InitWindow(screenWidth, screenHeight, windowTitle);
    
    // NOTE: If using textures, declare Texture2D variables here (after InitWindow)
    // NOTE: If using SpriteFonts, declare SpriteFont variables here (after InitWindow)
    
    // NOTE: If using sound or music, InitAudioDevice() and load Sound variables here (after InitAudioDevice)
    
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
                
            } break;
            case TITLE: 
            {
                // Update TITLE screen data here!
                
                // TODO: Title animation logic.......................(0.5p)
                
                // TODO: "PRESS ENTER" logic.........................(0.5p)
                
            } break;
            case GAMEPLAY:
            { 
                // Update GAMEPLAY screen data here!

                // TODO: Ball movement logic.........................(0.2p)
                
                // TODO: Player movement logic.......................(0.2p)
                
                // TODO: Enemy movement logic (IA)...................(1p)
                
                // TODO: Collision detection (ball-player) logic.....(0.5p)
                
                // TODO: Collision detection (ball-enemy) logic......(0.5p)
                
                // TODO: Collision detection (ball-limits) logic.....(1p)
                
                // TODO: Life bars decrease logic....................(1p)

                // TODO: Time counter logic..........................(0.2p)

                // TODO: Game ending logic...........................(0.2p)
                
                // TODO: Pause button logic..........................(0.2p)
                
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
        
            ClearBackground(RAYWHITE);
            
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
                    
                    // TODO: Draw player and enemy...................(0.2p)
                    
                    // TODO: Draw player and enemy life bars.........(0.5p)
                    
                    // TODO: Draw time counter.......................(0.5p)
                    
                    // TODO: Draw pause message when required........(0.5p)
                    
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
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    
    return 0;
}