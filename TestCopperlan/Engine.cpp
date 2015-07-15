//
//  Engine.cpp
//  TestCopperlan
//
//  Created by Ludovic Laffineur on 10/07/15.
//  Copyright (c) 2015 Ludovic Laffineur. All rights reserved.
//

#include "Engine.h"




Engine::Engine() :
m_pCHAI(NULL),
m_pDevice(NULL),
m_pInput(NULL),
m_pOutput(NULL)
{
}

Engine::~Engine()
{
}

bool Engine::Initialize()
{

    // Creation of one instance of the CHAI; the freeware key provides its identity.
    // The key contains the identity of the freeware and the name of the application
    // You can get a new key for your freeware at no cost and on simple request.
    m_pCHAI = CPNS::Factory::CreateCHAI("@7ZSwec9Pk@Yg5vjw1hQekXiuih8wWn2&3&@");

    // Addition of a generic device.
    // This device is declared as being in the Performance device category,
    // which means that it is used for musical performance.
    // Beware: the pointer returned is relating to an object maintained by the CHAI
    // (it derives from IObject). It is forbidden to try deleting such object.
    // Device deletion is done through the CHAI's RemoveLocalDevice method.

    m_pDevice = m_pCHAI->AddLocalDevice(34,
                                        423,
                                        CPNS::Enums::DuplicateModes::DM_Auto,
                                        false,
                                        CPNS::Enums::ExtendedDeviceCapabilities::EDC_Any,
                                        "MyPlugIn");

    if (!m_pDevice) return false;


    // Addition of an Input to the device.
    // The parameters are:
    // 1) a combination of the Input capabilities, here able to receive Event,
    // Modifier, and Selector messages.
    // 2) the name of the input

    m_pInput = m_pDevice->AddInput(
                                   CPNS::Enums::IOC_Msg_Event | CPNS::Enums::IOC_Msg_Modifier | CPNS::Enums::IOC_Msg_Selector, "Input",CPNS::SectionID::AnyInstanceOf(CPNS::Enums::SECT_Other));

    if (!m_pInput) return false;


    // Addition of an Output to the Device.
    // The parameters are:
    // 1) a combination of the Output capabilities, here able to emit Event,
    // Modifier, and Selector messages
    // 2) the name of the output

    m_pOutput = m_pDevice->AddOutput(
                                     CPNS::Enums::IOC_Msg_Modifier | CPNS::Enums::IOC_Msg_Event | CPNS::Enums::IOC_Msg_Selector,
                                     "Output",CPNS::SectionID::AnyInstanceOf(CPNS::Enums::SECT_Other));

    if (!m_pOutput) return false;

    // A ce stade, le Device n'est pas encore visible sur le réseau CopperLan.
    // Lors de la connexion du CHAI, un test est réalisé pour vérifier si il n'y a pas un
    // conflit d'identité. Ceci peut arriver si on exécute plusieurs fois le même
    // programme en même temps. Dans ce cas, CopperLan attribue automatiquement
    // un nouveau DuplicateNumber afin de résoudre le conflit.

    // At this stage, the Device is not visible yet on the CopperLan network.
    // During the CHAI connection, a test is effected to ensure that there is no identity conflict.
    // This can happen if the same program is run more than once at the same time.
    // In such case, CopperLan will automatically allocate a new DuplicateNumber in order
    // to solve the conflict.

    bool fConnected = (m_pCHAI->Connect() == CPNS::Enums::ERR_None);

    return fConnected;
}

void Engine::Terminate()
{
    // CHAI disconnection
    m_pCHAI->Disconnect();
    // Destruction of the CHAI and all associated resources
    m_pCHAI->Destroy();
    m_pCHAI = NULL;
    m_pDevice = NULL;
    m_pInput = NULL;
    m_pOutput = NULL;
}