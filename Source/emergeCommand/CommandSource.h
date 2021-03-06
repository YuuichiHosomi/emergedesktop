/*!
  @file CommandSource.h
  @brief header for emergeCommand
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

#ifndef __GUARD_4a494358_741d_4556_bff6_4af8fb8f3604
#define __GUARD_4a494358_741d_4556_bff6_4af8fb8f3604

#define UNICODE 1

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1 //suppress warnings about old versions of wcscpy, wcscat, etc.
#endif

#include <objidl.h>
#include <stdio.h>
#include "../emergeLib/emergeFileRegistryLib.h"

//#define MAX_HISTORY 9

class CommandSource : public IEnumString
{
private:
  ULONG refCount;
  ULONG currentElement;
  HWND commandWnd;
  HINSTANCE hInst;

public:
  CommandSource(HINSTANCE hInst);
  virtual ~CommandSource();
  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID, void**);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();
  STDMETHODIMP Next(ULONG, LPOLESTR*, ULONG*);
  STDMETHODIMP Skip(ULONG jump);
  STDMETHODIMP Reset();
  STDMETHODIMP Clone(IEnumString**);
};

#endif

