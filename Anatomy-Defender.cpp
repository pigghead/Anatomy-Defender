// Anatomy-Defender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#undef main

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;     // window itself
SDL_Surface* winSurface;    // what will appear in the window

// Function prototypes
bool Init();    // Startup and window creation
bool LoadMedia();   // Loading surfaces, images, etc.,
void Close();   // Free all allocated memory when done

int main()
{
    std::cout << "Hello World!\n";

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
            std::cout << "Window creation error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
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
