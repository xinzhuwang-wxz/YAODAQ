/*
* Copyright (c) 2014 Clark Cianfarini
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "PluginRegistry.hpp"

#include <string>
#include <tuple>
#include <vector>

namespace FlakedTuna
{
/*******************************************************
 * Win32 platform specific
 *******************************************************/
#if defined(_WIN32) || defined(WIN32)

  #include <Windows.h>

typedef HMODULE PLUG_HANDLE;

/*******************************************************
* *NIX platform specific
*******************************************************/
#else

  #include <dirent.h>
  #include <dlfcn.h>

typedef void* PLUG_HANDLE;

#endif

/*******************************************************
* Non-platform specific code
*******************************************************/
typedef std::vector<std::pair<int, PluginRegistry*>> registryVector;

typedef PluginRegistry* (*RegFuncPtr)();
typedef void (*CloseFuncPtr)();
typedef int (*VersionFuncPtr)();

std::pair<std::vector<PLUG_HANDLE>, std::vector<std::pair<int, PluginRegistry*>>> GetPluginHandles(std::string directory, std::string extension);

void ClosePluginHandles(std::vector<PLUG_HANDLE> handles);

}  // namespace FlakedTuna
