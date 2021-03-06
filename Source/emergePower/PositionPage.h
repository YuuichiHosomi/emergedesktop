/*!
  @file PositionPage.h
  @brief header for emergePower
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

#ifndef __GUARD_69472368_b6d8_42bd_a366_72f1f036dc83
#define __GUARD_69472368_b6d8_42bd_a366_72f1f036dc83

#define UNICODE 1

#ifdef __GNUC__
#include <tr1/memory>
#include <tr1/shared_ptr.h>
#else
#include <memory>
#endif

#include "resource.h"
#include "Settings.h"

class PositionPage
{
public:
  PositionPage(std::tr1::shared_ptr<Settings> pSettings);
  ~PositionPage();
  BOOL DoInitDialog(HWND hwndDlg);
  BOOL DoCommand(HWND hwndDlg, WPARAM wParam, LPARAM lParam);
  bool UpdateSettings(HWND hwndDlg);
  INT_PTR DoNotify(HWND hwndDlg, LPARAM lParam);
  static INT_PTR CALLBACK PositionPageDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);

private:
  std::tr1::shared_ptr<Settings> pSettings;
};

#endif
