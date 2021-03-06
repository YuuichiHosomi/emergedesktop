/*!
  @file Config.h
  @brief header for emergeCore
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

#ifndef __GUARD_9053bf6b_166f_4dc3_a419_6323db4c2aa7
#define __GUARD_9053bf6b_166f_4dc3_a419_6323db4c2aa7

#define UNICODE 1

#undef _WIN32_IE
#define _WIN32_IE 0x0600

#ifdef __GNUC__
#include <tr1/memory>
#include <tr1/shared_ptr.h>
#else
#include <memory>
#endif

#include "AliasEditor.h"
#include "ConfigPage.h"
#include "LaunchEditor.h"
#include "resource.h"
#include "Settings.h"

class Config
{
public:
  Config(HINSTANCE hInstance, HWND mainWnd, std::tr1::shared_ptr<Settings> pSettings);
  ~Config();
  int Show(UINT startPage);
  INT_PTR DoInitDialog(HWND hwndDlg);

private:
  std::tr1::shared_ptr<ConfigPage> pConfigPage;
  std::tr1::shared_ptr<LaunchEditor> pLaunchEditor;
  std::tr1::shared_ptr<AliasEditor> pAliasEditor;
  std::tr1::shared_ptr<Settings> pSettings;
  HINSTANCE hInstance;
  HWND mainWnd;
  UINT startPage;
  static INT_PTR CALLBACK ConfigDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif
