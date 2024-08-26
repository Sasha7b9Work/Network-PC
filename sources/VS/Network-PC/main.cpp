// 2022/04/29 13:57:01 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Application.h"
#include "Communicator/Communicator.h"
#include "Communicator/LAN/ServerTCP.h"
#include "Communicator/ComPort/ComPort.h"
#include "Data/ReceivedData.h"
#include "Display/Diagram/Diagram.h"
#include "Utils/Clock.h"
#include "Windows/ConsoleSCPI.h"
#include "Communicator/Server/Server.h"
#include "Utils/Timer.h"
#include "Communicator/HTTP/HTTP.h"


using namespace std;


void Application::Update()
{
    Clock::Update();

    Communicator::Update();

    ReceivedData::Update();

    WindowDiagram::UpdateArea();

    ServerMeasures::Update();

    {
        static TimeMeterMS meter;

        if (meter.ElapsedTime() > 5000)
        {
            meter.Reset();

//            HTTP::SendPOST(TypeMeasure::Temperature, (float)(std::rand() % 100));
        }
    }
}
