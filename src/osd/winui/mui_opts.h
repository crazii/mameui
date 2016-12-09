// For licensing and usage information, read docs/winui_license.txt
// MASTER
//****************************************************************************

#ifndef MUI_OPTS_H
#define MUI_OPTS_H

#include "winmain.h"
#include "winui.h"

// These help categorise the folders on the left side
// This list is mainly for documentation, although a few are used in code
typedef enum {
	// Global types
	OPTIONS_GLOBAL = 0,
	OPTIONS_HORIZONTAL,
	OPTIONS_VERTICAL,
	OPTIONS_RASTER,
	OPTIONS_VECTOR,
	OPTIONS_LCD,
	OPTIONS_ARCADE,
	OPTIONS_CONSOLE,
	OPTIONS_COMPUTER,
	OPTIONS_OTHERSYS,
	// Local types
	OPTIONS_SOURCE,
	OPTIONS_GPARENT,
	OPTIONS_PARENT,
	OPTIONS_GAME,
	// EOF marker
	OPTIONS_MAX
} OPTIONS_TYPE;

// List of columns in the main game list
enum
{
	COLUMN_GAMES = 0,
	COLUMN_SRCDRIVERS,
	COLUMN_DIRECTORY,
	COLUMN_TYPE,
	COLUMN_ORIENTATION,
	COLUMN_MANUFACTURER,
	COLUMN_YEAR,
	COLUMN_PLAYED,
	COLUMN_PLAYTIME,
	COLUMN_CLONE,
	COLUMN_TRACKBALL,
#ifdef SHOW_COLUMN_SAMPLES
	COLUMN_SAMPLES,
#endif
#ifdef SHOW_COLUMN_ROMS
	COLUMN_ROMS,
#endif
	COLUMN_MAX
};

#define LOCAL_OPTIONS   -10
#define GLOBAL_OPTIONS  -1

typedef struct
{
	int x, y, width, height;
} AREA;

typedef struct
{
	char* screen;
	char* aspect;
	char* resolution;
	char* view;
} ScreenParams;

// List of artwork types to display in the screen shot area
enum
{
	// these must match array of strings image_tabs_long_name in options.c
	// if you add new Tabs, be sure to also add them to the ComboBox init in dialogs.c
	TAB_SCREENSHOT = 0,
	TAB_FLYER,
	TAB_CABINET,
	TAB_MARQUEE,
	TAB_TITLE,
	TAB_CONTROL_PANEL,
	TAB_PCB,
	TAB_HISTORY,

	MAX_TAB_TYPES,
	BACKGROUND,
	TAB_ALL,
	TAB_NONE
};
// Because we have added the Options after MAX_TAB_TYPES, we have to subtract 3 here
// (that's how many options we have after MAX_TAB_TYPES)
#define TAB_SUBTRACT 3

class winui_options : public core_options
{
public:
	// construction/destruction
	winui_options();

private:
	static const options_entry s_option_entries[];
};

BOOL OptionsInit(HINSTANCE hInstance);
void OptionsExit(void);

#define OPTIONS_TYPE_GLOBAL -1
#define OPTIONS_TYPE_FOLDER -2

void SetDirectories(windows_options &opts);

void load_options(windows_options &opts, OPTIONS_TYPE opt_type, int game_num);
void save_options(windows_options &opts, OPTIONS_TYPE opt_type, int game_num);

void CreateGameOptions(windows_options &opts, OPTIONS_TYPE opt_type, int driver_index);

winui_options & MameUISettings(void);
windows_options & MameUIGlobal(void);

void LoadFolderFlags(void);

// Start interface to directories.h
const char* GetRomDirs(void);
void SetRomDirs(const char* paths);

const char* GetSampleDirs(void);
void  SetSampleDirs(const char* paths);

const char* GetArtDir(void);
void SetArtDir(const char* path);

const char* GetCabinetDir(void);
void SetCabinetDir(const char* path);

const char* GetCheatDir(void);
void SetCheatDir(const char* path);

const char* GetCfgDir(void);
void SetCfgDir(const char* path);

const char* GetControlPanelDir(void);
void SetControlPanelDir(const char* path);

const char* GetCtrlrDir(void);
void SetCtrlrDir(const char* path);

const char* GetCrosshairDir(void);
void SetCrosshairDir(const char* paths);

const char* GetDatsDir(void);
void SetDatsDir(const char *path);

const char* GetFlyerDir(void);
void SetFlyerDir(const char* path);

const char* GetFolderDir(void);
void SetFolderDir(const char* path);

const char* GetFontDir(void);
void SetFontDir(const char* paths);

const char* GetHashDirs(void);
void SetHashDirs(const char* paths);

const char* GetDiffDir(void);
void SetDiffDir(const char* path);

const char* GetIconsDir(void);
void SetIconsDir(const char* path);

const char* GetIniDir(void);
void SetIniDir(const char *path);

const char* GetInpDir(void);
void SetInpDir(const char* path);

const char* GetLangDir(void);
void SetLangDir(const char* path);

const char* GetMarqueeDir(void);
void SetMarqueeDir(const char* path);

const char* GetNvramDir(void);
void SetNvramDir(const char* path);

const char* GetPcbDir(void);
void SetPcbDir(const char* path);

const char* GetPluginsDir(void);
void SetPluginsDir(const char* path);

const char* GetImgDir(void);
void SetImgDir(const char* path);

const char* GetStateDir(void);
void SetStateDir(const char* path);

const char* GetTitlesDir(void);
void SetTitlesDir(const char* path);

const char* GetSLDir(void);
void SetSLDir(const char* path);
const char* GetSWDir(void);
void SetSWDir(const char* path);
// End interface to directories.h

void SaveOptions(void);
void SaveDefaultOptions(void);
void SaveGameListOptions(void);

void ResetGUI(void);
void ResetGameDefaults(void);
void ResetAllGameOptions(void);

const TCHAR * GetImageTabLongName(int tab_index);
const char * GetImageTabShortName(int tab_index);

void SetViewMode(int val);
int  GetViewMode(void);

void SetGameCheck(BOOL game_check);
BOOL GetGameCheck(void);

void SetVersionCheck(BOOL version_check);
BOOL GetVersionCheck(void);

void SetJoyGUI(BOOL use_joygui);
BOOL GetJoyGUI(void);

void SetKeyGUI(BOOL use_keygui);
BOOL GetKeyGUI(void);

void SetCycleScreenshot(int cycle_screenshot);
int GetCycleScreenshot(void);

void SetStretchScreenShotLarger(BOOL stretch);
BOOL GetStretchScreenShotLarger(void);

void SetScreenshotBorderSize(int size);
int GetScreenshotBorderSize(void);

void SetScreenshotBorderColor(COLORREF uColor);
COLORREF GetScreenshotBorderColor(void);

void SetFilterInherit(BOOL inherit);
BOOL GetFilterInherit(void);

void SetOffsetClones(BOOL offset);
BOOL GetOffsetClones(void);

void SetSavedFolderID(UINT val);
UINT GetSavedFolderID(void);

void SetShowScreenShot(BOOL val);
BOOL GetShowScreenShot(void);

void SetShowSoftware(BOOL val);
BOOL GetShowSoftware(void);

void SetShowFolderList(BOOL val);
BOOL GetShowFolderList(void);

BOOL GetShowFolder(int folder);
void SetShowFolder(int folder,BOOL show);

void SetShowStatusBar(BOOL val);
BOOL GetShowStatusBar(void);

void SetShowToolBar(BOOL val);
BOOL GetShowToolBar(void);

void SetShowTabCtrl(BOOL val);
BOOL GetShowTabCtrl(void);

void SetCurrentTab(const char *shortname);
const char *GetCurrentTab(void);

void SetDefaultGame(const char *name);
const char *GetDefaultGame(void);

void SetWindowArea(const AREA *area);
void GetWindowArea(AREA *area);

void SetWindowState(UINT state);
UINT GetWindowState(void);

void SetColumnWidths(int widths[]);
void GetColumnWidths(int widths[]);

void SetColumnOrder(int order[]);
void GetColumnOrder(int order[]);

void SetColumnShown(int shown[]);
void GetColumnShown(int shown[]);

void SetSplitterPos(int splitterId, int pos);
int  GetSplitterPos(int splitterId);

void SetCustomColor(int iIndex, COLORREF uColor);
COLORREF GetCustomColor(int iIndex);

void SetListFont(const LOGFONT *font);
void GetListFont(LOGFONT *font);

DWORD GetFolderFlags(int folder_index);

void SetListFontColor(COLORREF uColor);
COLORREF GetListFontColor(void);

void SetListCloneColor(COLORREF uColor);
COLORREF GetListCloneColor(void);

int GetHistoryTab(void);
void SetHistoryTab(int tab,BOOL show);

int GetShowTab(int tab);
void SetShowTab(int tab,BOOL show);
BOOL AllowedToSetShowTab(int tab,BOOL show);

void SetSortColumn(int column);
int  GetSortColumn(void);

void SetSortReverse(BOOL reverse);
BOOL GetSortReverse(void);

const char* GetLanguageUI(void);

bool GetEnablePlugins(void);

const char* GetPlugins(void);

const char* GetSnapName(void);
void SetSnapName(const char* pattern);

const char* GetBgDir(void);
void SetBgDir(const char* path);

void ResetGameOptions(int driver_index);

int GetRomAuditResults(int driver_index);
void SetRomAuditResults(int driver_index, int audit_results);

int GetSampleAuditResults(int driver_index);
void SetSampleAuditResults(int driver_index, int audit_results);

void IncrementPlayCount(int driver_index);
int GetPlayCount(int driver_index);
void ResetPlayCount(int driver_index);

void IncrementPlayTime(int driver_index,int playtime);
int GetPlayTime(int driver_index);
void GetTextPlayTime(int driver_index,char *buf);
void ResetPlayTime(int driver_index);

const char * GetVersionString(void);

void SaveDefaultOptions(void);

BOOL IsGlobalOption(const char *option_name);



// Keyboard control of ui
input_seq* Get_ui_key_up(void);
input_seq* Get_ui_key_down(void);
input_seq* Get_ui_key_left(void);
input_seq* Get_ui_key_right(void);
input_seq* Get_ui_key_start(void);
input_seq* Get_ui_key_pgup(void);
input_seq* Get_ui_key_pgdwn(void);
input_seq* Get_ui_key_home(void);
input_seq* Get_ui_key_end(void);
input_seq* Get_ui_key_ss_change(void);
input_seq* Get_ui_key_history_up(void);
input_seq* Get_ui_key_history_down(void);

input_seq* Get_ui_key_context_filters(void);
input_seq* Get_ui_key_select_random(void);
input_seq* Get_ui_key_game_audit(void);
input_seq* Get_ui_key_game_properties(void);
input_seq* Get_ui_key_help_contents(void);
input_seq* Get_ui_key_update_gamelist(void);
input_seq* Get_ui_key_view_folders(void);
input_seq* Get_ui_key_view_fullscreen(void);
input_seq* Get_ui_key_view_pagetab(void);
input_seq* Get_ui_key_view_picture_area(void);
input_seq* Get_ui_key_view_software_area(void);
input_seq* Get_ui_key_view_status(void);
input_seq* Get_ui_key_view_toolbars(void);

input_seq* Get_ui_key_view_tab_cabinet(void);
input_seq* Get_ui_key_view_tab_cpanel(void);
input_seq* Get_ui_key_view_tab_flyer(void);
input_seq* Get_ui_key_view_tab_history(void);
input_seq* Get_ui_key_view_tab_marquee(void);
input_seq* Get_ui_key_view_tab_screenshot(void);
input_seq* Get_ui_key_view_tab_title(void);
input_seq* Get_ui_key_view_tab_pcb(void);
input_seq* Get_ui_key_quit(void);


int GetUIJoyUp(int joycodeIndex);
void SetUIJoyUp(int joycodeIndex, int val);

int GetUIJoyDown(int joycodeIndex);
void SetUIJoyDown(int joycodeIndex, int val);

int GetUIJoyLeft(int joycodeIndex);
void SetUIJoyLeft(int joycodeIndex, int val);

int GetUIJoyRight(int joycodeIndex);
void SetUIJoyRight(int joycodeIndex, int val);

int GetUIJoyStart(int joycodeIndex);
void SetUIJoyStart(int joycodeIndex, int val);

int GetUIJoyPageUp(int joycodeIndex);
void SetUIJoyPageUp(int joycodeIndex, int val);

int GetUIJoyPageDown(int joycodeIndex);
void SetUIJoyPageDown(int joycodeIndex, int val);

int GetUIJoyHome(int joycodeIndex);
void SetUIJoyHome(int joycodeIndex, int val);

int GetUIJoyEnd(int joycodeIndex);
void SetUIJoyEnd(int joycodeIndex, int val);

int GetUIJoySSChange(int joycodeIndex);
void SetUIJoySSChange(int joycodeIndex, int val);

int GetUIJoyHistoryUp(int joycodeIndex);
void SetUIJoyHistoryUp(int joycodeIndex, int val);

int GetUIJoyHistoryDown(int joycodeIndex);
void SetUIJoyHistoryDown(int joycodeIndex, int val);

int GetUIJoyExec(int joycodeIndex);
void SetUIJoyExec(int joycodeIndex, int val);

const char* GetExecCommand(void);
void SetExecCommand(char* cmd);

int GetExecWait(void);
void SetExecWait(int wait);

BOOL GetHideMouseOnStartup(void);
void SetHideMouseOnStartup(BOOL hide);

BOOL GetRunFullScreen(void);
void SetRunFullScreen(BOOL fullScreen);

void ColumnEncodeStringWithCount(const int *value, char *str, int count);
void ColumnDecodeStringWithCount(const char* str, int *value, int count);

int GetDriverCache(int driver_index);
void SetDriverCache(int driver_index, int val);
BOOL RequiredDriverCache(void);

// from optionsms.h (MESSUI)

enum
{
	SW_COLUMN_IMAGES,
	SW_COLUMN_MAX
};

enum
{
	SL_COLUMN_IMAGES,
	SL_COLUMN_GOODNAME,
	SL_COLUMN_MANUFACTURER,
	SL_COLUMN_YEAR,
	SL_COLUMN_PLAYABLE,
	SL_COLUMN_USAGE,
	SL_COLUMN_MAX
};

void SetSWColumnWidths(int widths[]);
void GetSWColumnWidths(int widths[]);
void SetSWColumnOrder(int order[]);
void GetSWColumnOrder(int order[]);
void SetSWColumnShown(int shown[]);
void GetSWColumnShown(int shown[]);
void SetSWSortColumn(int column);
int  GetSWSortColumn(void);
void SetSWSortReverse(BOOL reverse);
BOOL GetSWSortReverse(void);

void SetSLColumnWidths(int widths[]);
void GetSLColumnWidths(int widths[]);
void SetSLColumnOrder(int order[]);
void GetSLColumnOrder(int order[]);
void SetSLColumnShown(int shown[]);
void GetSLColumnShown(int shown[]);
void SetSLSortColumn(int column);
int  GetSLSortColumn(void);
void SetSLSortReverse(BOOL reverse);
BOOL GetSLSortReverse(void);

void SetSelectedSoftware(int driver_index, const machine_config *config, const device_image_interface *device, const char *software);

void SetCurrentSoftwareTab(const char *shortname);
const char *GetCurrentSoftwareTab(void);


#endif

