<h1>Tutorial 1: The basics</h1>
This is the first of a string of articles intended to teach you how to write your first CopperLan application.

<h2>Prerequisites</h2>
It is of course necessary to have the latest version of CopperLan installed on your computer. You need to go to the Copperlan website, make an account and download the SDK.

<h2>Goal</h2>
The goal of this first lesson is to write a console application that declares a device on the CopperLan network.
It fits well with the global intent of the tutorial which about a black-box type of application, lacking direct interaction with the user, that allows to apply changes to a CopperLan message flow. The idea is to have access to small applications that can run in any machine on the network, are remote editable, and can, for example, be inserted between a keyboard and a sound generator to apply effects such as delay, transpose, arpeggiator, ...

<h2>Engine Class</h2>
As its name implies, this class is the engine of the application. It should be instantiated in the main() and its Initialize() method be called for the application to run. A call to Terminate allows to quit in a clean way.
Here is the main body of the program:

```cpp
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
```
We will now define the prototype of the Engine class, and thus make use of CopperLan resources.
Given that our example is based on the freeware SDK, it is needed to do the following include and ensure that the path to that file is defined globally for the whole project, or in the default parameters of your development environment.
```cpp
#include <stdio.h>
#include "CHAI.h"

class Engine
{
public:
    //====================
    // Constructor/Destructor
    //====================
    Engine();
    ~Engine();
    //====================
    // Public methods
    //====================
    bool Initialize();
    void Terminate();
private:
    //====================
    // Members
    //====================
    CPNS::ICHAI* m_pCHAI;
    CPNS::IBaseLocalDevice* m_pDevice;
    CPNS::IInput* m_pInput;
    CPNS::IOutput* m_pOutput;
};
```
