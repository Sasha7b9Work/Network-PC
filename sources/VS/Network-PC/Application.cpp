﻿// 2022/04/29 13:56:38 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Application.h"
#include "Communicator/Server/Server.h"
#include "Windows/WindowTerminal.h"
#include "Communicator/Communicator.h"
#include "Utils/Config.h"
#include "Settings/Settings.h"
#include "Windows/MainWindow/MainWindow.h"
#include "Windows/WindowDiagram/WindowDiagram.h"
#include "Windows/WindowEmulator.h"


wxIMPLEMENT_APP(Application);


enum
{
    TIMER_ID = 111
};


bool Application::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    Config::Init();

    SET::Init();

    Log::Init();

    // we use a PNG image in our HTML page
    wxImage::AddHandler(new wxPNGHandler);

    WindowEmulator::Create();

    FrameDiagram::Create();

    WindowTerminal::Create();

    MainWindow::Create();

    Communicator::Init();

    Bind(wxEVT_TIMER, &Application::OnTimer, this, TIMER_ID);

    timer.SetOwner(this, TIMER_ID);

    timer.Start();

    MainWindow::Show();

    return true;
}


void Application::OnTimer(wxTimerEvent &)
{
    Update();
}


int Application::OnExit()
{
    SET::DeInit();

    Config::DeInit();

    ServerMeasures::DeInit();

    return wxApp::OnExit();
}
