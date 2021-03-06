/*!
  @file Settings.h
  @brief header for emergeVWM
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

#ifndef __GUARD_0a680bc1_a71a_4bd3_a83d_7e695f0be18d
#define __GUARD_0a680bc1_a71a_4bd3_a83d_7e695f0be18d

#define UNICODE 1

#include <string>
#include <vector>
#include "../emergeBaseClasses/BaseSettings.h"

class Settings : public BaseSettings
{
public:
  Settings();
  ~Settings();
  int GetDesktopRows();
  int GetDesktopColumns();
  bool SetDesktopRows(int rows);
  bool SetDesktopColumns(int columns);
  UINT GetStickyListSize();
  WCHAR* GetStickyListItem(UINT item);
  void DeleteStickyListItem(UINT item);
  bool CheckSticky(std::wstring appName);
  void AddStickyListItem(WCHAR* item);
  void WriteStickyList();
  bool GetHideSticky();
  bool SetHideSticky(bool hideSticky);
  void BuildStickyList();

protected:
  virtual void DoReadSettings(IOHelper& helper);
  virtual void DoWriteSettings(IOHelper& helper);
  virtual void ResetDefaults();

private:
  std::vector<std::wstring> stickyList;
  std::wstring xmlFile;
  int rows, columns;
  bool hideSticky;
};

#endif
