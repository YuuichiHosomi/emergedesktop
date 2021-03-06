/*!
  @file StyleEditor.h
  @brief header for emergeStyleEngine
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

#ifndef __GUARD_9342eb10_3e7a_4f76_b466_1179afec8c83
#define __GUARD_9342eb10_3e7a_4f76_b466_1179afec8c83

#define UNICODE 1

#define MAX_LINE_LENGTH 4096

#ifdef _MSC_VER
#pragma warning(push) //store the existing compiler warning level
#pragma warning(disable: 4251) //'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'

#define _CRT_SECURE_NO_WARNINGS 1 //suppress warnings about old versions of wcscpy, wcscat, etc.
#define _CRT_NON_CONFORMING_SWPRINTFS 1 //suppress warnings about old swprintf format
#endif

#undef _WIN32_IE
#define _WIN32_IE	0x501

#undef _WIN32_WINNT
#define _WIN32_WINNT	0x501

#ifdef EMERGESTYLEENGINE_EXPORTS
#undef DLL_EXPORT
#define DLL_EXPORT  __declspec(dllexport)
#else
#ifndef DLL_EXPORT
#define DLL_EXPORT  __declspec(dllimport)
#endif
#endif

#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

#ifdef __GNUC__
#include <tr1/memory>
#include <tr1/shared_ptr.h>
#else
#include <memory>
#endif

#include <shlwapi.h>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include "../emergeLib/emergeCoreLib.h"
#include "../emergeLib/emergeFileRegistryLib.h"
#include "../emergeLib/emergeOSLib.h"
#include "../emergeLib/emergeUtilityLib.h"
#include "../emergeLib/emergeWindowLib.h"
#include "emergeStyleEngine.h"
#include "resource.h"

typedef std::set<HWND> PanelSet;

class DLL_EXPORT StyleEditor
{
public:
  StyleEditor(HWND mainWnd, std::wstring instanceName);
  ~StyleEditor();
  int Edit(std::wstring styleName);
  BOOL DoInitDialog(HWND hwndDlg, bool updatePos);
  BOOL DoCommand(HWND hwndDlg, WPARAM wParam, LPARAM lParam);
  BOOL DoNotify(HWND hwndDlg, LPARAM lParam);
  BOOL DoColourChooser(COLORREF* colour, HWND hwndDlg);
  BOOL DoLoad(HWND hwndDlg);
  BOOL DoSwitch(HWND hwndDlg);
  void DoSaveAs(HWND hwndDlg);
  static INT_PTR CALLBACK StyleEditorDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
  LPCTSTR GetTemplate();

private:
  std::map< HTREEITEM, std::tr1::shared_ptr<PanelSet> > panelMap;
  std::wstring tmpFile, instanceName;
  RECT colourRect;
  COLORREF colourBackground, colourForeground, colourSelected, colourFrame, colourFont;
  COLORREF colourFrom, colourTo, colourBorder;
  HWND mainWnd, toolWnd;
  GUIINFO guiInfo, origGuiInfo, defaultGuiInfo;
  std::wstring style, font, origStyle;
  HBITMAP hbmColourBackground, hbmColourForeground, hbmColourSelected, hbmColourFrame, hbmColourFont;
  HBITMAP hbmColourFrom, hbmColourTo, hbmColourBorder;
  std::wstring DoSaveStyle(HWND hwndDlg, std::wstring fileName);
  BOOL DoDefaults(HWND hwndDlg);
  void BuildPanelMap(HWND hwndDlg);
  void ClearPanelMap();
  void ShowPanel(HTREEITEM panel);
  HTREEITEM hitemOpacity, hitemColor, hitemGradient, hitemMisc;
};

#ifdef _MSC_VER
#pragma warning(pop) //restore the old compiler warning level
#endif

#endif
