/*!
  @file SystemProcessInfo.h
  @brief internal header for emergeLib
  @author The Emerge Desktop Development Team

  @attention This file is part of Emerge Desktop.
  @attention Copyright (C) 2004-2013  The Emerge Desktop Development Team

  @attention Emerge Desktop is free software; you can redistribute it and/or
  modify  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  @attention Emerge Desktop is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  @attention You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifndef __GUARD_cb3e9d70_25b0_44ac_9494_317b79fda720
#define __GUARD_cb3e9d70_25b0_44ac_9494_317b79fda720

#define UNICODE 1

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1 //suppress warnings about old versions of wcscpy, wcscat, etc.
#define _CRT_NON_CONFORMING_SWPRINTFS 1 //suppress warnings about old swprintf format
#endif

#include <windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include <string>
#include "../emergeOSLib.h"

//Helper functions
bool MapDevicePathToDrivePath(LPWSTR path);

//TODO: expand this into a full-fledged system/process monitoring API.
//Add functions for monitoring everything from general memory usage to per-process memory usage to (if possible) HDD activity.

#endif
