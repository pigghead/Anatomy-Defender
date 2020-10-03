// Anatomy-Defender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#undef main

// 16:9 aspect ratio
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* win = NULL;     // window itself
SDL_Surface* winSurface;    // what will appear in the window

// Function prototypes
bool Init();    // Startup and window creation
bool LoadMedia();   // Loading surfaces, images, etc.,
void Close();   // Free all allocated memory when done

int main(int argc, char* args[])
{
    // Start SDL + Create window
    if ( !Init() )
    {
        std::cout << "Error Initializing";
    }
    else
    {
        // Flag for the main game loop
        bool quit = false;

        SDL_Event e;

        //SDL_RenderClear(gRenderer);

        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    // Do character movement processing here
                }
            }

            SDL_UpdateWindowSurface(win);
        }
    }

    Close();

    return 0;
}

bool Init()
{
    // Flag for error catches
    bool success = true;

    // Initialize video, look for failures if any immediately
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // Report error and change our flag
        std::cout << "Init error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        // Create the window
        win = SDL_CreateWindow("Anatomy Defender", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        // If window creation was unsuccessful for any reason
        if (win == NULL)
        {
            // Report & change flag
            std::cout << "Window creation error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            // establish the surface
            winSurface = SDL_GetWindowSurface(win);
        }
    }

    return success;
}

bool LoadMedia()
{
    // Flag for error catches
    bool success = true;

    // ..
    return success;
}

// For deallocation of memory
void Close()
{
    // Dealloc surface
    SDL_FreeSurface(winSurface);

    // Dealloc win + NULL it
    SDL_DestroyWindow(win);
    win = NULL;

    // Quit SDL
    SDL_Quit();
}
