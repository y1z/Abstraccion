#pragma once
/*!To have the ability to use functions or variables with the names "min" or "max"*/
#define NOMINMAX
//! disables serial communication api 
#define NOCOMM 
//! disables Cryptography, DDE, RPC, Shell, and Windows Sockets.
#define WIN32_LEAN_AND_MEAN 

#include <windows.h>