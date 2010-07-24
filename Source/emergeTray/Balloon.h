//---
//
//  This file is part of Emerge Desktop.
//  Copyright (C) 2004-2010  The Emerge Desktop Development Team
//
//  Emerge Desktop is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  Emerge Desktop is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//---

#ifndef __ETR_BALLOON_H
#define __ETR_BALLOON_H

// Define required for the Window Transparency
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501

// Define required for menu animation
#undef WINVER
#define WINVER 0x0501

#undef _WIN32_IE
#define _WIN32_IE 0x0501

#define OEMRESOURCE 1

#include "../emergeLib/emergeLib.h"
#include "../emergeGraphics/emergeGraphics.h"
#include "../emergeAppletEngine/emergeAppletEngine.h"
#include "Settings.h"

#define BALLOON_TIMER_ID 1

#ifndef NIIF_USER
#define NIIF_USER 0x4
#endif

#ifndef NIIF_LARGE_ICON
#define NIIF_LARGE_ICON 0x20
#endif

class TrayIcon;

class Balloon
{
public:
  Balloon(HINSTANCE hInstance, TrayIcon *pTrayIcon, Settings *pSettings);
  ~Balloon();
  bool Initialize();
  bool Show(POINT showPt);
  bool Hide();
  LRESULT DoLButtonDown();
  LRESULT DoTimer();
  bool SetInfo(WCHAR *info);
  bool SetInfoTitle(WCHAR *info);
  bool SetInfoFlags(DWORD infoFlags, HICON infoIcon);
  bool DrawAlphaBlend();

private:
  static LRESULT CALLBACK BalloonProcedure (HWND, UINT, WPARAM, LPARAM);
  HINSTANCE mainInst;
  HWND balloonWnd;
  TrayIcon *pTrayIcon;
  DWORD infoFlags;
  WCHAR info[TIP_SIZE];
  WCHAR infoTitle[TIP_SIZE];
  RECT titleRect, infoRect;
  HICON icon;
  Settings *pSettings;
  int iconSize;
};

#endif