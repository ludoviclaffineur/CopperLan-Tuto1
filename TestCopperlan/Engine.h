//
//  Engine.h
//  TestCopperlan
//
//  Created by Ludovic Laffineur on 10/07/15.
//  Copyright (c) 2015 Ludovic Laffineur. All rights reserved.
//

#ifndef __TestCopperlan__Engine__
#define __TestCopperlan__Engine__

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

#endif /* defined(__TestCopperlan__Engine__) */
