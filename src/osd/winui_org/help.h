// For licensing and usage information, read docs/winui_license.txt
//****************************************************************************

#ifndef HELP_H
#define HELP_H

#if defined(__GNUC__)
#define HH_DISPLAY_TOPIC        0
#define HH_TP_HELP_CONTEXTMENU 16
#define HH_TP_HELP_WM_HELP     17
#define HH_CLOSE_ALL           18
#define HH_INITIALIZE          28
#define HH_UNINITIALIZE        29
#else
#include <htmlhelp.h>
#endif

typedef struct
{
	int nMenuItem;
	BOOL bIsHtmlHelp;
	LPCTSTR lpFile;
} MAMEHELPINFO;

extern const MAMEHELPINFO g_helpInfo[];

#if !defined(MAMEUIHELP)
#ifdef MESS
#define MAMEUIHELP "messui.chm"
#else
#define MAMEUIHELP "mameui.chm"
#endif
#endif

#if !defined(MAMEUICONTEXTHELP)
#ifdef MESS
#define MAMEUICONTEXTHELP "messui.chm::/cntx_help.txt"
#else
#define MAMEUICONTEXTHELP "mameui.chm::/cntx_help.txt"
#endif
#endif

extern int HelpInit(void);
extern void HelpExit(void);
extern HWND HelpFunction(HWND hwndCaller, LPCSTR pszFile, UINT uCommand, DWORD_PTR dwData);

#endif
