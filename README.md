What is MAMEUI?
===============
MAMEUI has an inbuilt front-end allowing you to run a game from a list.


How to compile?
===============

You can only build MAMEUI on a Windows computer. It won't compile on Unix. More info at docs/compile.doc

```
make OSD=winui
```

or

```
make SUBTARGET=arcade OSD=winui
```


Any differences for original MAMEUI?
===============


##Simplied Chinese (简体中文) language


use

```
make SUBTARGET=arcade OSD=winui FRONTEND_LANG=CHS
```

to enable Simplied Chinese.


##Custom buttons

For example keyboard 'J' for button 'A', keyboard 'K" for button 'B':
usually you need both 'J'+'K' pressed for 'A+B'
but with this feature, you can map 'L' to 'A+B' then one 'L' key is doing the job.

Note: the "Custom buttons" codes comes from mameplus, which is out of date and latest version is MAME 0.168

use
```
make OSD=winui USE_CUSTOM_BUTTON=1
```
to enable custom button


##Additional custom build scripts

Minimal build for NeoGeo + CPS + PGM: NCP build.
This build has a much smaller executable, and takes extremely short time to scan roms, but with only a limited set of games.
It's a good choice if you don't play other games.

use

```
make SUBTARGET=ncp OSD=winui
```

to perform NCP build. 


Where can I find out more?
==========================

* [Official MAME Development Team Site](http://mamedev.org/) (includes binary downloads for MAME and MESS, wiki, forums, and more)
* [MAMEUI site] http://www.mameui.info/
* [MAMEUI forum] http://www.mameworld.info/ubbthreads/postlist.php?Cat=&Board=mameui


Licensing Information
=====================

Information about the MAME content can be found at https://github.com/mamedev/mame/blob/master/README.md

Information about the MAME license particulars and disclaimers can be found at https://github.com/mamedev/mame/blob/master/LICENSE.md

Information about the WINUI portion can be found at https://github.com/Robbbert/mameui/blob/master/docs/winui_license.txt

