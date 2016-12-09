// For licensing and usage information, read docs/winui_license.txt
//****************************************************************************
#ifndef __MESSUI_H__
#define __MESSUI_H__

#include "devview.h"

extern char g_szSelectedItem[MAX_PATH];
extern char g_szSelectedSoftware[MAX_PATH];
extern char g_szSelectedDevice[26];

void InitMessPicker(void);
void MessUpdateSoftwareList(void);
void MyFillSoftwareList(int nGame, BOOL bForce);
BOOL MessCommand(HWND hwnd,int id, HWND hwndCtl, UINT codeNotify);
void MessReadMountedSoftware(int nGame);
BOOL CreateMessIcons(void);
BOOL MessApproveImageList(HWND hParent, int nDriver);
void MySoftwareListClose(void);

#endif // __MESSUI_H__
