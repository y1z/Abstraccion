#pragma once
/*!To have the ability to use function with min or max
function or variable named "min" or "max" */
#define NOMINMAX
//! disables serial communication api 
#define NOCOMM 
//! disables Cryptography, DDE, RPC, Shell, and Windows Sockets.
#define WIN32_LEAN_AND_MEAN 

#include <windows.h>
//
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "resource.h"
#include <cinttypes>

