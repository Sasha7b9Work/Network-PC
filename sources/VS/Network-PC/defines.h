// 2022/04/29 14:52:10 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#define WIN32_LEAN_AND_MEAN
#include "opt.h"


#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_BUILD 154

#define DATE_BUILD "2024-08-29 13:42:01"


typedef const char *pchar;
typedef unsigned char uchar;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint;
typedef signed char int8;
typedef const char *pchar;


#include "Utils/Log.h"

#pragma warning(push, 0)
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/socket.h>
#include <wx/fileconf.h>
#include <wx/webrequest.h>
#include <map>
#include <vector>
#pragma warning(pop)


enum
{
    SOCKET_ID = wxID_HIGHEST + 1000
};
