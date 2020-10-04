// Anatomy-Defender.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <SDL.h>
#undef main

// 16:9 aspect ratio
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//Global Everything
//Window
SDL_Window* gameWindow = NULL;

//Renderer (g stands for global)
SDL_Renderer* gRenderer = NULL;

//Surfaces
SDL_Surface* tempSurface = NULL;

//Textures
SDL_Texture* texture1 = NULL;
SDL_Texture* texture2 = NULL;

//Rectangles
SDL_Rect rect1;     //SpaceShip rectangle
SDL_Rect rect2;    //Background rectangle

//Function Prototypes
bool ProgramIsRunning();
void FillRect(SDL_Rect& rect, int x, int y, int width, int height);
SDL_Surface* loadImage(const char* path);
SDL_Texture* loadTexture(SDL_Surface* surface);
void CloseShop();

int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL failed to initialize!\n");
        SDL_Quit();
        return 0;
    }
    //Create a window
    gameWindow = SDL_CreateWindow("Use the arrow keys to move the sprite around and ESC to exit.", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    //Create a renderer for the window
    gRenderer = SDL_CreateRenderer(gameWindow, -1, 0);

    // set the renderer color
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);  // produce black

    //load background
    tempSurface = loadImage("graphics/Ship.bmp");

    //create texture
    texture1 = loadTexture(tempSurface);

    // Create a rectangle at position 0, 0 for background
    FillRect(rect2, 0, 0, 800, 600);

    //Load spaceShip bitmap
    tempSurface = loadImage("graphics/Ship_Top.bmp");

    //Create texture
    texture2 = loadTexture(tempSurface);

    // Create a rectangle at position 0, 0 for spaceShip
    FillRect(rect1, 0, 0, 120, 95);

    /* MAIN GAME LOOP */
    while (ProgramIsRunning())
    {
        //Get the key press from the keyboard
        const Uint8* keys = SDL_GetKeyboardState(NULL);
        //if the escape key was pressed
        if (keys[SDL_SCANCODE_ESCAPE])
        {
            CloseShop();
        }
        //if the left arrow was pressed then move to the left
        if (keys[SDL_SCANCODE_LEFT])
        {
            rect1.x -= 8;
        }
        //if the right arrow was pressed then move to the right
        if (keys[SDL_SCANCODE_RIGHT])
        {
            rect1.x += 8;
        }
        //if the up arrow was pressed then move up
        if (keys[SDL_SCANCODE_UP])
        {
            rect1.y -= 8;
        }
        //if the down arrow was pressed then move down
        if (keys[SDL_SCANCODE_DOWN])
        {
            rect1.y += 8;
        }

        //Clear the window
        SDL_RenderClear(gRenderer);

        //Copy the background);
        SDL_RenderCopy(gRenderer, texture1, NULL, &rect2);

        //Copy SpaceShip
        SDL_RenderCopy(gRenderer, texture2, NULL, &rect1);

        //display the game screen with updated position of spaceShip
        SDL_RenderPresent(gRenderer);
        SDL_Delay(10);  //delay a bit

    }//end game loop

    printf("You will never be able to make everyone happy.  You are not a Nutella jar.");
    CloseShop();

    return 1;  //Because it's C
}//end main

//Function Section
SDL_Surface* loadImage(const char* path)
{
    //Load image at specified path
    tempSurface = SDL_LoadBMP(path);

    if (tempSurface == NULL)
    {
        printf("Unable to load image at path: %s\n", path);
    }
    return tempSurface;
}//end loadImage

SDL_Texture* loadTexture(SDL_Surface* tempSurface)
{
    //texture
    SDL_Texture* newTexture = NULL;
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(gRenderer, tempSurface);
    if (newTexture == NULL)
    {
        printf("Unable to create texture");
    }
    //Get rid of the surface
    SDL_FreeSurface(tempSurface);
    return newTexture;
}//end create a texture

void FillRect(SDL_Rect& rect, int x, int y, int width, int height)
{
    //Initialize the rectangle
    rect.x = x;         //initial x position of upper left corner
    rect.y = y;         //initial y position of upper left corner
    rect.w = width;     //width of rectangle
    rect.h = height;    //height of rectangle
}//end rectangle initializing

void CloseShop()
{
    //Destroy all objects
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gameWindow);
    SDL_Quit(); //Quit the program
}//End Close Shop

bool ProgramIsRunning()
{
    SDL_Event event;
    bool running = true;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
    }
    return running;
}//end is running
