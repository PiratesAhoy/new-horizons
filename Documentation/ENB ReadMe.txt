Description of ENBSeries on the web page may not be equal to version in downloaded mod
archive (installer).


ENBSeries for GTA3 v0.075

WARNING! This version requires DX8 to DX9 convertor to run (included in this archieve),
but because convertor is in debug state currently, it's strongly recommended after
long time playing reboot computer.
Effects for water and shadows not implemented in this version.
For version 0.074f: version works correctly with non-fullscreen viewports, motion blur
vectors are not limited any more, added new parameter ShadowBlurRange to control
bluriness of shadows, FadeDistance to control ambient occlusion distance, UseEnvBump
to deform reflections on cars and two additional parameters for this bump deformations.
For version 0.074e: Added new parameter UsePaletteTexture, now you can change color correction by
custom bitmap image.
For version 0.074d: Activated preset OcclusionQuality for high-end videocards. Added DepthBias parameter.
For version 0.074c: This recompilation based on version 0.074b, solve some bugs and activates
disabled previously functionality. Motion blur effect still works incorrect, but i
decide to let it be, later may be i find out what is wrong. SSAO now have several
parameters, also allow to use ambient occlusion only without indirect lightning for
better performance. SSAO now activated for AlternativeDepth=0. Some problems with
dissapearing and flickering of SSAO and soft shadows now solved. Added shadows
filtering.




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
SYSTEM REQUIREMENTS:
Videocard with support of Shader Model 2.0 or better. Videocards in the list below may fit:
GeForce 6100, 6150, 6200, 6600, 6800, 7300, 7600, 7800, 7900, 8500, 8600, 8800;
Radeon 9500, 9550, 9600, 9700, 9800, 300, 600, 700, 800, 850, 1300, 1600, 1800, 1900, 1950, 2400, 2600, 2900, 3850, 3870.
I can't guarantee that mod will work on all of them by many reasons (different drivers, hardware reduced versions and just because not tested myself). ENBSeries (current version) will not run at all or will not work properly if hardware by any reason not support minimal requirements of the mod. Videocards with lower shader versions capable to work in theory, but they are too slow, no sense. Videocards of new generation (DirectX10 compatible) in common cases works much faster in this mod, than their performance equivalents in DirectX9 games.
The requirements to videomemory size are very high, depends from screen resolution and antialiasing, for example without antialiasing in a mode 1024*768 it cost 64 Mb of videomemory, and for 1280*1024 106 Mb are necessary. Operative memory and processor play an insignificant role, though all should be balanced.
 

GAME COMPATIBILITY:
Mod may work incorrect with some versions of the games, impossible to test it for every game patch and for already modded games. Some types of installed game modifications may conflict with ENBSeries.

INSTALLING:
Extract files from archive in to the game directory or where game execution file exist (.exe). For some games it is in the directories named system, bin, bin32. Warning, some games needs root game directory for mod even if .exe file is not there.

STARTING:
After game start the mod deactivated by default, to activate it use key combination (for GTASA shift+f12 by default).

SETUP:
After first game start with the mod, configuration file enbseries.ini will be created, use it to modify mod setting. Warning, if configuration file will be corrupted in any way, remove it and run mod again.

SETTING DESCRIPTION:

[PROXY]
EnableProxyLibrary=(0,1) load 3rd party library by the mod at game start. Helps to solve problem with multiple d3d9.dll files.
InitProxyFunctions=(0,1) connect to functions of 3rd party library.
ProxyLibrary=(filename) file name of 3rd party library.

[GLOBAL]
UseEffect=(0,1) activate mod at start. In some situations HUD or startup movies may be corrupted visually because of this parameter enabled.
AlternativeDepth=(0,1) increase performance of some effects, but not all videocards can use this mode at full precision, if you see large lines on the objects, disable this parameter.
AllowAntialias=(0,1) enables antialiasing setting from game to be used in the mod effects. (antialiasing, multisampling, fsaa, in other words).
BugFixMode=(0..5) every value fixes it's own unsopported feature or bug in driver or hardware. For drivers 169.xx and 171.xx do not set this parameter to 1. Values from 0 to 5 actually HDR texture formats: 0 (R32G32F)-high quality and middle performance, 1 (R32F)-high quality and fast, 2 (A32R32G32B32F)-high quality and very slow, 3 (R16F)-low quality and fastest, 4 (R16G16F)-low quality and fast, 5 (A16R16G16B16F)-low quality and middle performance.
SkipShaderOptimization=(0,1) disables optimization when compiling shader, may help to elliminate bugs.

[EFFECT]
EnableBloom=(0,1) enables bloom effect (bright areas blurred) with time dependent adaptation. Works only if mod activated already (by key combination).
EnableOcclusion=(0,1) enables ambient occlusions (ssao) and some other effects (mod version dependent).
EnableReflection=(0,1) reflection of vehicles.
EnableMotionBlur=(0,1) blurring image in fast motion of camera. Temporary disabled.
EnableWater=(0,1) enable water effects
EnableShadow=(0,1) enable shadow effects
DepthBias=(0..1000) for scene depth rendering, offset of geometry relative camera viewpoint. For some videocards may be useful to remove flickering and hiding of ambient occlusions.

[INPUT]
KeyUseEffect=(1..255) decimal key number for mod activation/deactivation.
KeyBloom=(1..255) decimal key number for bloom activation/deactivation.
KeyOcclusion=(1..255) decimal key number for ssao activation/deactivation.
KeyReflection=(1..255) decimal key number for reflection activation/deactivation.
KeyCombination=(1..255) decimal number of additional key for combining this key with others (SHIFT by default).
KeyShadow=(1..255) decimal key number for shadow activation/deactivation.
KeyWater=(1..255) decimal key number for water activation/deactivation.

[REFLECTION]
ReflectionPower=(0..100) level of cars reflection.
ChromePower=(0..100) level of steel parts reflection. Temporary disabled.
UseCurrentFrameReflection=(0,1) when 1 use for reflection image of current frame screen, otherwise use previous frame image.
ReflectionQuality=(0..2) quality, 0 means maximal quality and slowest speed.
ReflectionSourceSpecular=(0..100) percent of using "specular" material color as reflection factor. Some car parts may be reflective with this setting.
ReflectionSourceTFactor=(0..100) percent of using "texture factor" as game environment map mix level. Some car parts may not be reflective with this parameter and on the contrary.
UseAdditiveReflection=(0,1) reflections added to screen car colors, 0 means more softly reflection.
ReflectionDepthBias=(0..1000) offset of reflection geometry relative to car and camera viewpoint. For some videocards may be useful to remove flickering and hiding of reflections.
UseLowResReflection=(0,1) use small and blurred texture as reflection, looks like matte reflection.

[BLOOM]
BloomPowerDay=(0..100) power of bloom at day time, dependent from screen brightness.
BloomFadeTime=(0..100000) time of bloom adaptation to screen brightness change, in milliseconds.
BloomConstantDay=(0..100) power of bloom at day time, independent from adaptation time between screen brightness change.
BloomQuality=(0..2) bloom effect quality, 0 means maximal quality.
BloomScreenLevelDay=(0..100) level of screen brightness in percents, that determined as day time.
BloomCurveDay=(-10..10) gamma correction of bloom at day time. negative values increases halftone brightness (smoggy look), positive values decrease halftones brightness (contrast, intensive image).
BloomPowerNight=(0..100) power of bloom at night time, dependent from screen brightness.
BloomConstantNight=(0..100) power of bloom at night time, independent from adaptation time between screen brightness change.
BloomCurveNight=(-10..10) gamma correction of bloom at night time. negative values increases halftone brightness (smoggy look), positive values decrease halftones brightness (contrast, intensive image).
BloomScreenLevelNight=(0..100) level of screen brightness in percents, that determined as night time.
BloomAdaptationScreenLevel=(0..100) level of screen brightness in percents, over which bloom deactivating. It's desirable that this parameter will be greater than BloomScreenLevelDay.
BloomAdaptationMultiplier=(0..100) percent of day time bloom brightness, that will be used when screen brightness will be greater than BloomAdaptationScreenLevel. Value 100 disable adaptation
BloomAllowOversaturation=(0,1) if 0, bloom softly applied to screen and bright areas not become too oversaturated.

[SSAO]
UseFilter=(0,1) enable noise filtering, produced by ambient occlusion effect.
OcclusionQuality=(0..2) quality of ssao, 0 means maximal quality and slow performance. In current version this is disabled, using lowest quality level.
FilterQuality=(0..2) quality of ssao noise filtering, 0 is maximal quality and slowest performance.
DarkeningLevel=(0..100) darkening level by ambient occlusion
BrighteningLevel=(0..100) edge lightening level by ambient occlusion
IlluminationLevel=(0..100) light transfering level by indirect lightning
AdditiveIlluminationLevel=(0..100) lightening of dark areas by indirect lightning
UseAmbientOcclusion=(0,1) allow darkening of nearest objects (temporary disabled)
UseIndirectLightning=(0,1) compute indirect lightning (affect performance)

[COLORCORRECTION]
DarkeningAmountDay=(-100..100) how much to dark or to bright dark screen areas at day time. Negative values makes brighter, positive darker.
ScreenLevelDay=(0..100) level of screen brightness in percents, that determined as day time.
ScreenLevelNight=(0..100) level of screen brightness in percents, that determined as night time.
DarkeningAmountNight=(-100..100) how much to dark or to bright dark screen areas at night time. Negative values makes brighter, positive darker. Positive values recommended for more natural nights.
GammaCurveDay=(-10..10) gamma correction of bloom at day time. negative values increases halftone brightness (pale image), positive values decrease halftones brightness (contrast, intensive image).
GammaCurveNight=(-10..10) gamma correction of bloom at night time. negative values increases halftone brightness (pale image), positive values decrease halftones brightness (contrast, intensive image).

[PLUGIN]
WeatherMod=(0,1) activates color correction for Weather Mod installed, choosed by it's author. Temporary disabled.

[WATER]
UseWaterDeep=(0,1) use smooth transition between different deep levels.
WaterDeepness=(0..1000) factor of water semitransparencity at difference deep levels.
WaterQuality=(0..2) quality of water effects, 0 means maximal quality.

[SHADOW]
ShadowFadeStart=(0..1000) distance, at which shadow starts to be less intensive.
ShadowFadeEnd=(0..1000) distance at which shadow dissapear completely.
ShadowAmountDay=(0..100) percent of shadows intencity in the day.
ShadowAmountNight=(0..100) percent of shadows intencity in the night.
ShadowScreenLevelDay=(0..100) level of screen brightness in percents, that determined as day time.
ShadowScreenLevelNight=(0..100) level of screen brightness in percents, that determined as night time.
ShadowQuality=(0..2) quality of shadows, 0 is maximal and slowest.
UseShadowFilter=(0,1) enable filtering of shadows
FilterQuality=(0..2) quality of shadows filtering, 0 is maximal and slowest

[ENGINE]
ForceAnisotropicFiltering=(0,1) force to use anisotropic filtering for most game textures.
MaxAnisotropy=(1..16) maximal level of anisotropy filtering, greater values makes more sharp textures at low angles.
ForceDisplayRefreshRate=(0,1) force to use user defined reflresh rate.
DisplayRefreshRateHz=(60..240) custom monitor reflresh rate. Warning, incorrect use of this parameter may corrupt you display! (or what you are using)

[MOTIONBLUR]
MotionBlurQuality=(0..2) sampling quality, 0 means maximal quality
MotionBlurVelocity=(0..100) factor of movement vector length in forward or backward
MotionBlurRotation=(0..100) factor of movement to sides and rotation, recommended the same as MotionBlurVelocity


Key numbers (virtual key codes) available in key_codes.txt or key_codes.htm. In current version of the mod these lists of key codes are hex values, but mod works with decimal, i can't describe now how to convert them, may be later i'll do something.

PROBLEMS SOLVING:
Q: Mod installed, but i don't see any difference.
A: After game start mod is not activated, turn it on by hotkeys (by default SHIFT F12).
Q: When activating the mod, image makes black (objects near the camera).
A: Your videocard not support antialiasing of HDR textures, disable antialiasing in the game and in display driver control panel. Also try to set AllowAntialias=0, BugFixMode=1 or 5, AlternativeDepth=0, if not helps, disable ambient occlusions EnableOcclusion=0.
Q: Computer not responding when mod activated.
A: Perhaps video drivers too old or too new, for example forceware 169.xx and higher (171.xx last tested) working incorrectly woth some HDR textures, use older drivers (162.xx, 163.xx). Also try to change BugFixMode and disable ambient occlusions EnableOcclusion=0.
Q: Car reflections sometimes hiding and flickering.
A: For some videocards you need to set ReflectionDepthBias value to something about 100, depending from hardware. This problem was found on Radeon 2xxx.
Q: From far distance interier and wheels becomes overlapped visible through car.
A: Value of ReflectionDepthBias is too high or it's not required for your videocard.
Q: I have integrated onboard videochip and mod not works.
A: Perhaps video memory size is too small for display resolution you are playing, decrease it or in bios setting increase video memory size (typically values from 16 to 128 Mb).
Q: At high resolutions and antialiasing mod not works.
A: Not enough video memory.


PERFORMANCE TIPS:
Do not use too high display resolution with ambient occlusion enabled, this effect directly depends from number of pixels on the screen.
By setting UseWaterDeep=0, UseOcclusions=0, ShadowQuality=2 rendering of the scene to depth deactivating and performance greatly increase.
Reflections with some imported car models may work very slow, because of too many polygons that currently proceeded several times, just wait for next releases, rendering reflections with cars itself will be done later.
Bloom almost not decrease game speed, use it as you wish.
Any filtering, for shadows or for ambient occlusions are very slow, try to set their quality=2 and check framerate, may be it will be good for you.
OcclusionQuality=0 set only if your videocard is realy fast, this is the most performance costly. By setting this parameter to 0 you may olso decrease filtering quality to 1 or even 2.




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
DONATE:
If on Your opinion ENBSeries project must continue to live or simply it was useful for yourself, i'll be grateful for sponsoring project (or donation).
More questions ask boris-vorontsov@yandex.ru

Another payments methods also available, contact me via e-mail or visit web page.

For online payment:
WebMoney:
Z341642200704
R715514188135


For bank transfer:

Euro:
Correspondent bank of beneficiary's bank
RAIFFEISEN ZENRALBANK OESTERREICH (RZB-AUSTRIA), Vienna Am Stadtpark 9, P.O.Box 50, A-1011 Vienna, Austria
S.W.I.F.T   RZBAATWW
Acc. with corresp/Bank Acc.   1-50.092.584/100.EUR
Beneficiary's bank   Alfa-Bank  Moscow
S.W.I.F.T   ALFARUMM
Beneficiary's Acc.   40817978904520000418
Beneficiar   Vorontsov Boris Ivanovich

or

Correspondent bank of beneficiary's bank
B.C.E.N. - EUROBANK, Paris, 79-81, Boulevard Haussmann, 75382 Paris Cedex 08, France
S.W.I.F.T   EURO FR PP
Acc. with corresp/Bank Acc.   01811033.EUR
Beneficiary's bank   Alfa-Bank  Moscow
S.W.I.F.T   ALFARUMM
Beneficiary's Acc.   40817978904520000418
Beneficiar   Vorontsov Boris Ivanovich


US Dollars:
Correspondent bank of beneficiary's bank
Deutsche Bank Trust Company Americas, New York
130 Liberty Street, New York City, NY 10006, USA
S.W.I.F.T   BKTR US 33
Acc. with corresp/Bank   04415617
Beneficiary's bank   Alfa-Bank  Moscow
S.W.I.F.T   ALFARUMM
Beneficiary's Acc.   40817840404520000677
Beneficiar   Vorontsov Boris Ivanovich

or

Correspondent bank of beneficiary's bank
Bank of New York, New York
One Wall Street, New York, NY 10286, USA
S.W.I.F.T   IRVTUS3N
Acc. with corresp/Bank   890-0570-822
Beneficiary's bank   Alfa-Bank  Moscow
S.W.I.F.T   ALFARUMM
Beneficiary's Acc.   40817840404520000677
Beneficiar   Vorontsov Boris Ivanovich

Thanks!



http://boris-vorontsov.narod.ru
Copyright (c) 2008 Vorontsov Boris (ENB developer)
