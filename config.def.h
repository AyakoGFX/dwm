/* See LICENSE file for copyright and license details. */

#include "theme.c"
#include "layouts.c"
#include "movestack.c"

#define Button6 6
#define Button7 7
#define Button8 8
#define Button9 9

/* Appearance */
static const unsigned int borderpx        = 2;        /* Border pixel of windows */
static const unsigned int gappx           = 6;        /* Gaps between windows */
static const unsigned int snap            = 32;       /* Snap pixel */
static const int showbar                  = 1;        /* 0 means no bar */
static const int swallowfloating          = 0;        /* 1 means swallow floating windows by default */
static const int topbar                   = 0;        /* 0 means bottom bar */
static const char *fonts[]                = { "monospace:size=11:antialias=true:hinting=true",
                                              "FiraCode Nerd Font:size=11:antialias=true:autohint=true" };
static const char dmenufont[]             = "monospace:size=10";

/* Systray */
static const unsigned int systraypinning       = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft        = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing       = 2;   /* systray spacing */
static const int systraypinningfailfirst       = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray                   = 1;   /* 0 means no systray */

/* Colors */
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

// Add this new structure for scratchpads
typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {"alacritty", "--class", "spterm", "--config-file", "/home/ayako/.config/alacritty/srcpad/ala.toml", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",      spcmd1},
    {"spranger",    spcmd2},
    {"keepassxc",   spcmd3},
};

/* Tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class      instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    // { "obs",      NULL,     NULL,           1 << 8,    0,          0,           0,        -1 },
    { "Gimp",     NULL,     NULL,           0,         0,          0,           0,        -1 },
    { "Firefox",  NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
    { "St",       NULL,     NULL,           0,         0,          1,           0,        -1 },
    { "Alacritty",NULL,     NULL,           0,         0,          1,           0,        -1 },
    { NULL,       NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
    { "Volapplet",NULL,     NULL,           0,         1,          0,           1,        -1 },
    { "Blueman-manager",NULL,NULL,           0,         1,          0,           1,        -1 },
    // Add these new rules for scratchpads
    { NULL,       "spterm",    NULL,        SPTAG(0),  1,          0,           0,        -1 },
    { NULL,       "spfm",      NULL,        SPTAG(1),  1,          0,           0,        -1 },
    { NULL,       "keepassxc", NULL,        SPTAG(2),  0,          0,           0,        -1 },
};
// tagmask for 
// 1 << 0 = tag 1
// 1 << 1 = tag 2
// 1 << 2 = tag 3
// 1 << 3 = tag 4
// 1 << 4 = tag 5
// 1 << 5 = tag 6
// 1 << 6 = tag 7
// 1 << 7 = tag 8
// 1 << 8 = tag 9

/* Audio controls */
#include <X11/XF86keysym.h>
static const char *upvol[]   = { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "10%+", NULL };
static const char *downvol[] = { "/usr/bin/wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "10%-", NULL };
static const char *mutevol[] = { "/usr/bin/wpctl", "set-mute",   "@DEFAULT_AUDIO_SINK@", "toggle", NULL };

/* Layout(s) */
static const float mfact     = 0.55; /* Factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* Number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* First entry is default */
    { "[M]",      monocle },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "III",      horizontal },
    { "HHH",      grid },
    { "><>",      NULL },    /* No layout function means floating behavior */
    { NULL,       NULL },
};

/* Key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    &((Keychord){1, {{MODKEY, KEY}},                           view,           {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ControlMask, KEY}},               toggleview,     {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ShiftMask, KEY}},                 tag,            {.ui = 1 << TAG} }), \
    &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},     toggletag,      {.ui = 1 << TAG} }),

/* Helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Commands */
static char dmenumon[2] = "0"; /* Component of dmenucmd, manipulated in spawn() */
static const char *DmenuRun[]        = { "/usr/bin/dmenu_run", NULL };
static const char *dmenucmd[]        = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]         = { "alacritty", NULL };
static const char *brightness_up[]   = { "brightnessctl", "set", "5%+", NULL };
static const char *brightness_down[] = { "brightnessctl", "set", "5%-", NULL };


static Keychord *keychords[] = {

    /* Brightness control */
    &((Keychord){1, {{MODKEY, XK_w}},                spawn,          {.v = brightness_up } }),
    &((Keychord){1, {{MODKEY, XK_s}},                spawn,          {.v = brightness_down } }),

    /*wk*/
    &((Keychord){1, {{MODKEY, XK_o}},                spawn,          SHCMD("wk") }),
    
    /* Audio control */
    &((Keychord){1, {{MODKEY|ShiftMask, XK_w}},      spawn,          {.v = upvol   } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_s}},      spawn,          {.v = downvol } }),
    &((Keychord){1, {{MODKEY, XK_F1}},               spawn,          {.v = mutevol } }),

    /* Application launchers */
    &((Keychord){1, {{MODKEY, XK_d}},                spawn,          {.v = dmenucmd } }),
    &((Keychord){1, {{MODKEY, XK_g}},                spawn,          {.v = DmenuRun } }),
    &((Keychord){1, {{MODKEY, XK_Return}},           spawn,          {.v = termcmd } }),

    /* Window management */
    &((Keychord){1, {{MODKEY, XK_b}},                togglebar,      {0} }),
    &((Keychord){1, {{MODKEY, XK_j}},                focusstack,     {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_k}},                focusstack,     {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_h}},                setmfact,       {.f = -0.05} }),
    &((Keychord){1, {{MODKEY, XK_l}},                setmfact,       {.f = +0.05} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_f}},      zoom,           {0} }),
    &((Keychord){1, {{MODKEY, XK_Tab}},              view,           {0} }),
    &((Keychord){1, {{MODKEY, XK_q}},                killclient,     {0} }),

    /* Layout manipulation */
    &((Keychord){1, {{MODKEY, XK_comma}},   cyclelayout,    {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_period}},  cyclelayout,    {.i = +1 } }),
    &((Keychord){1, {{MODKEY, XK_space}},            setlayout,      {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_space}},  setlayout,      {.v = &layouts[0]} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_f}},      togglefloating, {0} }),
    &((Keychord){1, {{MODKEY, XK_f}},                togglefullscr,  {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_j}},      movestack,      {.i = +1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_k}},      movestack,      {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_space}},            setlayout,      {.v = &layouts[1]} }),

    /* Tag management */
    &((Keychord){1, {{MODKEY, XK_0}},                view,           {.ui = ~0 } }),
 //   &((Keychord){1, {{MODKEY|ShiftMask, XK_0}},      tag,            {.ui = ~0 } }), removed due to the issue where switching tags with a sticky window causes the sticky window to move to the center 
    &((Keychord){1, {{MODKEY|ShiftMask, XK_0}},      togglesticky,   {0} }),
    &((Keychord){1, {{MODKEY|ControlMask, XK_comma}},  focusmon,       {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ControlMask, XK_period}}, focusmon,       {.i = +1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_comma}},  tagmon,         {.i = -1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_period}}, tagmon,         {.i = +1 } }),

    /* Gaps */
    &((Keychord){1, {{MODKEY, XK_minus}},            setgaps,        {.i = -1 } }),
    &((Keychord){1, {{MODKEY, XK_equal}},            setgaps,        {.i = +1 } }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_equal}},  setgaps,        {.i = 0  } }),

    /* Tag keys */
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)

    /* Quit and restart Dwm */
    &((Keychord){1, {{MODKEY|ShiftMask, XK_e}},             quit,           {0} }),
    &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, XK_q}}, quit,           {1} }), 

    /* Scratchpad dianamic */
    &((Keychord){1, {{MODKEY, XK_n}},                       scratchpad_show,   {0} }),
    &((Keychord){1, {{MODKEY|ShiftMask, XK_n}},             scratchpad_hide,   {0} }),
    &((Keychord){1, {{MODKEY, XK_m}},                       scratchpad_remove, {0} }),

        /* Scratchpads  */
    &((Keychord){1, {{MODKEY, XK_y}},            togglescratch,  {.ui = 0} }),
    &((Keychord){1, {{MODKEY, XK_u}},            togglescratch,  {.ui = 1} }),
    &((Keychord){1, {{MODKEY, XK_i}},            togglescratch,  {.ui = 2} }),
};

/* Button definitions */
/* Click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};



/* examples
 *
 /* Application open 
static const char *browser[]     = { "google-chrome-stable", NULL };
static const char *filemanager[] = { "pcmanfm", NULL };
static const char *videoeditor[] = { "org.kde.kdenlive", NULL };
static const char *photoditor[]  = { "gimp", NULL };
static const char *githubdesk[]  = { "github-desktop", NULL };
static const char *recording[]   = { "obs", NULL };
static const char *texteditor[] = { "cursor", NULL };

Mod3Mask

    &((Keychord){2, {{MODKEY, XK_e}, {MODKEY, XK_e}},           spawn,          SHCMD("emacsclient -c -a 'emacs'") }),
    &((Keychord){2, {{MODKEY, XK_e}, {MODKEY, XK_x}},           spawn,          SHCMD("emacsclient -e '(kill-emacs)'") }),
    /* Application open 
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_b}},                spawn,          {.v = browser } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_f}},                spawn,          {.v = filemanager } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_v}},                spawn,          {.v = videoeditor } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_p}},                spawn,          {.v = photoditor } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_d}},                spawn,          {.v = githubdesk } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_r}},                spawn,          {.v = recording } }),
    &((Keychord){2, {{MODKEY, XK_o}, {0, XK_e}},                spawn,          {.v = texteditor } }),

    /*emacs
    &((Keychord){2, {{MODKEY, XK_e}, {0, XK_e}},                spawn,          SHCMD("emacsclient -c -a 'emacs'") }),
    &((Keychord){2, {{MODKEY, XK_e}, {0, XK_x}},                spawn,          SHCMD("emacsclient -e '(kill-emacs)'") }),

    /*kill all volapplet and cbatticon 
    &((Keychord){2, {{MODKEY, XK_x}, {0, XK_x}},                spawn,          SHCMD("killall volapplet && killall cbatticon") }),

    /* Terminal app 
    &((Keychord){3, {{MODKEY, XK_o}, {0, XK_t}, {0, XK_n}},     spawn,          SHCMD("alacritty -e nvim") }),
    &((Keychord){3, {{MODKEY, XK_o}, {0, XK_t}, {0, XK_b}},     spawn,          SHCMD("alacritty -e btop") }),

    /* Screenshot with flameshot 
    &((Keychord){3, {{MODKEY, XK_x}, {0, XK_s}, {0, XK_s}},     spawn,          SHCMD("flameshot gui") }),
    &((Keychord){3, {{MODKEY, XK_x}, {0, XK_s}, {0, XK_f}},     spawn,          SHCMD("flameshot full --path ~/Pictures/SS/") }),
    &((Keychord){3, {{MODKEY, XK_x}, {0, XK_s}, {0, XK_d}},     spawn,          SHCMD("flameshot full --delay 5000") }),
    &((Keychord){3, {{MODKEY, XK_x}, {0, XK_s}, {0, XK_c}},     spawn,          SHCMD("flameshot full --clipboard") }),

    /* Lock Screen 
    &((Keychord){2, {{MODKEY, XK_x}, {0, XK_l}},      spawn,          SHCMD("slock") }),
    
    /* Rofi scripts 
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_e}},     spawn,          SHCMD("rofi -modi emoji -show emoji") }),
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_c}},     spawn,          SHCMD("clipmenu") }),
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_w}},     spawn,          SHCMD("rofi-wifi") }),
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_b}},     spawn,          SHCMD("rofi-bluetooth") }),
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_p}},     spawn,          SHCMD("rofi-passmenu") }),
    &((Keychord){2, {{MODKEY, XK_r}, {0, XK_o}},     spawn,          SHCMD("rofi -show power-menu -modi power-menu:rofi-power-menu") }),

*/


