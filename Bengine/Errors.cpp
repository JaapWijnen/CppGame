// Platform specific includes
#ifdef __APPLE__
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL/SDL.h>
#endif

#include "Errors.h"

#include <cstdlib>
#include <iostream>

namespace Bengine {

    //Prints out an error message and exits the game
    void fatalError(std::string errorString) {
        std::cout << errorString << std::endl;
        std::cout << "Enter any key to quit...";
        int tmp;
        std::cin >> tmp;
        SDL_Quit();
        exit(69);
    }

}