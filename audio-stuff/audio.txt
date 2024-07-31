/**
 * dwmconfig.h 
 * Hardware multimedia keys
 */
/* Somewhere at the beginning of config.h include: */

/* 
 You obviously need the X11 development packages installed, X11proto in particular, but 
 here is the location of the keysyms header upstream copy if you can't bother 
 using the contents of your own hard drive. ;-P
 
 https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h
*/

#include <X11/XF86keysym.h>

/* If you use pipewire add somewhere in your constants definition section. Use "wpctl status" to
   find out the real sink ID, 0 is a placeholder here. */
static const char *upvol[]      = { "/usr/bin/wpctl",   "set-volume", "0",      "5%+",      NULL };
static const char *downvol[]    = { "/usr/bin/wpctl",   "set-volume", "0",      "5%-",      NULL };
static const char *mutevol[]    = { "/usr/bin/wpctl",   "set-mute",   "0",      "toggle",   NULL };

/* czardien made it work with @DEFAULT_AUDIO_SINK@ */
static const char *upvol[]      = { "/usr/bin/wpctl",   "set-volume", "@DEFAULT_AUDIO_SINK@",      "5%+",      NULL };
static const char *downvol[]    = { "/usr/bin/wpctl",   "set-volume", "@DEFAULT_AUDIO_SINK@",      "5%-",      NULL };
static const char *mutevol[]    = { "/usr/bin/wpctl",   "set-mute",   "@DEFAULT_AUDIO_SINK@",      "toggle",   NULL };

/* If you use pulsaudio add somewhere in your constants definition section instead. */
static const char *upvol[]      = { "/usr/bin/pactl",   "set-sink-volume", "0",      "+5%",      NULL };
static const char *downvol[]    = { "/usr/bin/pactl",   "set-sink-volume", "0",      "-5%",      NULL };
static const char *mutevol[]    = { "/usr/bin/pactl",   "set-sink-mute",   "0",      "toggle",   NULL };

/* AidenThing suggests using this general solution for dynamically changing outputs. */
static const char *upvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };

/* If you use amixer, use this instead. Thanks go to DaniOrt3ga. */
static const char *upvol[]      = { "/usr/bin/amixer",  "set", "Master", "5%+", NULL };
static const char *downvol[]    = { "/usr/bin/amixer",  "set", "Master", "5%-", NULL };
static const char *mutevol[]    = { "/usr/bin/amixerl", "set", "Master", "toggle", NULL };

/* To use light add this to the constant definition section. Thanks Hritik14. */
static const char *light_up[]   = { "/usr/bin/light",   "-A", "5", NULL };
static const char *light_down[] = { "/usr/bin/light",   "-U", "5", NULL };


/* Add to keys[] array. With 0 as modifier, you are able to use the keys directly. */
static Key keys[] = {
	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                       XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
};

/* If you have a small laptop keyboard or don't want to spring your fingers too far away. */
static Key keys[] = {
	{ MODKEY,                       XK_F11, spawn, {.v = downvol } },
	{ MODKEY,                       XK_F9,  spawn, {.v = mutevol } },
	{ MODKEY,                       XK_F12, spawn, {.v = upvol   } },
};

/* To use light add this to the keys[] array. Thanks Hritik14. */
static Key keys[] = {
	{ 0,				XF86XK_MonBrightnessUp,		spawn,	{.v = light_up} },
	{ 0,				XF86XK_MonBrightnessDown,	spawn,	{.v = light_down} },
};
