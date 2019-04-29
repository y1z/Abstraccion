#pragma once
/**
*@file "Usable_Window.h"
*@brief this is just a header that deactivates some Windows macros, for
*convenience
*/


//! disables Cryptography, DDE, RPC, Shell, and Windows Sockets.
#define WIN32_LEAN_AND_MEAN 
/*!To have the ability to use functions or variables with the names "min" or "max"*/
#define NOMINMAX 
//! disables serial communication api because i don't use it.
#define NOCOMM 

#define NODEFERWINDOWPOS
//! disables modem configuration because I don't need it .
#define NOMCX

#include <windows.h>