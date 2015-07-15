//
//  main.cpp
//  TestCopperlan
//
//  Created by Ludovic Laffineur on 10/07/15.
//  Copyright (c) 2015 Ludovic Laffineur. All rights reserved.
//

#include <iostream>
#include "Engine.h"
Engine g_Engine;

int main(int argc, char* argv[]) {
    //Initialisation
    if (g_Engine.Initialize())
    {
        printf("Program running... Press any key to exit\n");
        getchar();
        // Terminaison
        g_Engine.Terminate();
    }
    else
        printf("aborting...\n");
}
