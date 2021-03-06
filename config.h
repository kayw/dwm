
/* appearance */
static const char font[]              = "-*-ohsnap.icons-medium-r-*-*-14-*-*-*-*-*-*-*"
                                        ","
                                        "-*-DejaVu Sans-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char dmenufont[]         = "-*-ohsanp.icons-medium-r-*-*-16-*-*-*-*-*-*-*";
static const unsigned int tagspacing  = 3;      /* space between tags */
static const unsigned int tagpadding  = 20;     /* inner padding of tags */
static const unsigned int taglinepx   = 2;      /* height of tag underline */
static const unsigned int gappx       = 8;      /* gaps between windows */
static const unsigned int borderpx    = 1;      /* border pixel of windows */
static const unsigned int snap        = 32;     /* snap pixel */
static const Bool showbar             = True;   /* False means no bar */
static const Bool topbar              = True;   /* False means bottom bar */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray = True;           /* false means no systray */

#define NUMCOLORS       13
static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg         bg */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 01 - regular */
    { "#D64937", "#FFFFFF", "#D64937" },        /* 02 - selected */
    { "#2D2D2D", "#FF0000", "#2D2D2D" },        /* 03 - urgent */
    { "#2D2D2D", "#FFFFFF", "#349147" },        /* 04 - occupied green */
    { "#2D2D2D", "#A82222", "#2D2D2D" },        /* 05 - red */
    { "#2D2D2D", "#1F7B94", "#2D2D2D" },        /* 06 - blue */
    { "#2D2D2D", "#349147", "#2D2D2D" },        /* 07 - green */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 08 - dark grey */
    { "#2D2D2D", "#DCDCDC", "#2D2D2D" },        /* 09 - light grey */
    { "#2D2D2D", "#D64937", "#2D2D2D" },        /* 0A - orange */
    { "#2D2D2D", "#B86A6A", "#2D2D2D" },        /* 0B - pink */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 0C - white */
    { "#2D2D2D", "#000000", "#2D2D2D" },        /* 0D - black */
};

/* key definitions */
#define MODKEY          Mod1Mask
#define MONKEY          Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* layout(s) */
static const float mfact = 0.50;                /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;                   /* number of clients in master area */
static const Bool resizehints = False;          /* true means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol   gaps    arrange */
    { "þ",      True,   tile },
    { "ü",      True,   bstack },
    { "ÿ",      False,  monocle },
    { "ý",      False,  NULL },
};


/* tagging */
static const Tag tags[] = {
    /* name     layout          mfact   nmaster */
    { "main",   &layouts[2],    -1,     -1 },
    { "dev",    &layouts[0],    -1,     -1 },
    { "droid",  &layouts[0],    -1,     -1 },
    { "doc",    &layouts[0],    -1,     -1 },
    { "chat",   &layouts[0],    -1,     -1 },
    { "mail",   &layouts[2],    -1,     -1 },
    { "file",   &layouts[0],    -1,     -1 },
    { "media",  &layouts[1],    -1,     -1 },
    { "web",    &layouts[1],    -1,     -1 },
    { "vbox",   &layouts[0],    -1,     -1 },
    { "fterm",  &layouts[0],    -1,     -1 },
};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class                instance    title       tags mask       isfloating      iscentred       monitor */
    { "GVim",               NULL,       NULL,       1 << 1,         False,          False,          -1 },
    { "jetbrains-webstorm", NULL,       NULL,       1 << 1,         False,          False,          -1 },
    { "Brackets",           NULL,       NULL,       1 << 1,         False,          False,          -1 },
    { "jetbrains-studio",   NULL,       NULL,       1 << 2,         False,          False,          -1 },
    { "tabbed-zathura",     NULL,       NULL,       1 << 3,         False,          False,          -1 },
    { "Skype",              NULL,       NULL,       1 << 4,         False,          False,          -1 },
    { "Mutt",               NULL,       "Mutt",     1 << 5,         False,          False,          -1 },
    { "Chromium",           NULL,       NULL,       1 << 7,         False,          False,          -1 },
    { "Feh",                NULL,       NULL,       1 << 6,         False,          False,          -1 },
    { "Pcmanfm",            NULL,       NULL,       1 << 6,         False,          False,          -1 },
    { "firefox",            NULL,       NULL,       1 << 8,         False,          False,          -1 },
    { "VirtualBox",         NULL,       NULL,       1 << 9,         False,          False,          -1 },
    { "VLC",                NULL,       NULL,       1 << 10,        False,          False,          -1 },
    { "Fqterm.bin",         NULL,       NULL,       1 << 10,        False,          False,          -1 },
};

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenu[]  = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *chrom[]  = { "chromium", "--incognito", NULL, NULL, NULL, "Chromium" };
static const char *chat[]   = { "skype", NULL, NULL, NULL, NULL, "Skype" };
static const char *urxvtd[] = { "urxvtd", NULL };
static const char *term[]   = { "urxvtc", NULL, NULL, NULL, NULL,"URXVTC" };
static const char *aterm[]   = { "alacritty", NULL, NULL, NULL, NULL,"ALacritty" };
static const char *email[]   = { "urxvtc", "-title", "mutt", "-e", "mutt", "Mutt" };
/*static const char *edit[]   = { "gvim", NULL, NULL, NULL, NULL, "GVim" };
static const char *vlc[]    = { "vlc", NULL, NULL, NULL, NULL, "VLC" };*/
static const char *pdf[]    = { "bash", "-c", "$HOME/bin/zathuratab", NULL, NULL, "Zathura" };
static const char *pcfm[]   = { "pcmanfm", NULL, NULL, NULL, NULL, "Pcmanfm" };
static const char *prts[]   = { "bash", "-c", "maim -s -k $HOME/Downloads/shots/$(date +%F_%H-%M-%S).png"};
static const char *play[]   = { "ncmpcpp", "toggle" };
static const char *stop[]   = { "ncmpcpp", "stop" };
static const char *prev[]   = { "ncmpcpp", "prev" };
static const char *next[]   = { "ncmpcpp", "next" };
static const char *mute[]   = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volu[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *vold[]   = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *vbox[]   = { "virtualbox",  NULL, NULL, NULL, NULL, "VirtualBox" };
static const char *fq[]     = { "fqterm", NULL, NULL, NULL, NULL, "fqterm.bin" };
static const char *studio[] = { "/usr/local/android-studio/bin/studio.sh", NULL, NULL, NULL, NULL, "jetbrains-studio" };
static const char *wstorm[] = { "/opt/webstorm/bin/webstorm.sh", NULL, NULL, NULL, NULL, "jetbrains-webstorm" };
static const char *brackets[] = { "/usr/local/brackets/brackets", NULL, NULL, NULL, NULL, "Brackets" };

static Key keys[] = {
    /* modifier         key         function        argument */
    { MONKEY,           XK_p,       spawn,          {.v = dmenu } },
    { MONKEY,           XK_z,       runorraise,     {.v = pdf } },
    { MONKEY,           XK_a,       runorraise,     {.v = studio } },
    { MONKEY,           XK_w,       runorraise,     {.v = wstorm } },
    { MONKEY,           XK_b,       runorraise,     {.v = brackets } },
    { MONKEY,           XK_c,       runorraise,     {.v = chrom } },
    { MONKEY,           XK_s,       runorraise,     {.v = chat } },
    { MODKEY|ShiftMask, XK_Return,  spawn,          {.v = urxvtd } },
    { MONKEY,           XK_Return,  spawn,          {.v = aterm } },
    { MONKEY|ControlMask,           XK_Return,      spawn,          {.v = term } },
    /*{ MONKEY,           XK_v,       runorraise,     {.v = vlc } },*/
    { MONKEY,           XK_f,       runorraise,     {.v = pcfm } },
    { MONKEY,           XK_e,       runorraise,     {.v = email } },
    { MONKEY,           XK_v,       runorraise,     {.v = vbox } },
    { MONKEY,           XK_q,       runorraise,     {.v = fq } },
    { MONKEY,           XK_Print,   spawn,          {.v = prts } },
    { MONKEY,           XK_F5,      spawn,          {.v = play } },
    { MONKEY,           XK_F6,      spawn,          {.v = stop } },
    { MONKEY,           XK_F7,      spawn,          {.v = prev } },
    { MONKEY,           XK_F8,      spawn,          {.v = next } },
    { MONKEY,           XK_F10,     spawn,          {.v = mute } },
    { MONKEY,           XK_F11,     spawn,          {.v = vold } },
    { MONKEY,           XK_F12,     spawn,          {.v = volu } },
    { MODKEY|ShiftMask, XK_b,       togglebar,      {0} },
    { MODKEY|ShiftMask, XK_c,       killclient,     {0} },
    { MODKEY,           XK_Return,  zoom,           {0} },
    { MODKEY,           XK_Tab,     view,           {0} },
    { MODKEY|ShiftMask, XK_f,       togglefloating, {0} },
    { MODKEY,           XK_space,   setlayout,      {0} },
    { MODKEY,           XK_t,       setlayout,      {.v = &layouts[0] } },
    { MODKEY,           XK_b,       setlayout,      {.v = &layouts[1] } },
    { MODKEY,           XK_m,       setlayout,      {.v = &layouts[2] } },
    { MODKEY,           XK_f,       setlayout,      {.v = &layouts[3] } },
    { MODKEY,           XK_k,       focusstack,     {.i = +1 } },
    { MODKEY,           XK_j,       focusstack,     {.i = -1 } },
    { MODKEY,           XK_h,       setmfact,       {.f = -0.05 } },
    { MODKEY,           XK_l,       setmfact,       {.f = +0.05 } },
    { MODKEY,           XK_equal,   incnmaster,     {.i = +1 } },
    { MODKEY,           XK_minus,   incnmaster,     {.i = -1 } },
    { MODKEY,           XK_0,       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0,       tag,            {.ui = ~0 } },
    { MODKEY,           XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,           XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask, XK_period,  tagmon,         {.i = +1 } },
    { MODKEY,                       XK_Left,   cycle,          {.i = -1 } },
    { MODKEY,                       XK_Right,  cycle,          {.i = +1 } },
    { MODKEY|ControlMask,           XK_Left,   tagcycle,       {.i = -1 } },
    { MODKEY|ControlMask,           XK_Right,  tagcycle,       {.i = +1 } },
    { MODKEY|ControlMask,           XK_j,      pushdown,       {0} },
    { MODKEY|ControlMask,           XK_k,      pushup,         {0} },
    { MODKEY|ShiftMask, XK_q,       quit,           {0} },
    TAGKEYS(            XK_1,       0)
    TAGKEYS(            XK_2,       1)
    TAGKEYS(            XK_3,       2)
    TAGKEYS(            XK_4,       3)
    TAGKEYS(            XK_5,       4)
    TAGKEYS(            XK_6,       5)
    TAGKEYS(            XK_7,       6)
    TAGKEYS(            XK_8,       7)
    TAGKEYS(            XK_9,       8)
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click            event mask  button          function        argument */
    { ClkLtSymbol,      0,          Button1,        setlayout,      {0} },
    { ClkLtSymbol,      0,          Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,      0,          Button2,        zoom,           {0} },
    { ClkStatusText,    0,          Button2,        spawn,          {.v = term } },
    { ClkClientWin,     MODKEY,     Button1,        movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button2,        togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3,        resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,        view,           {0} },
    { ClkTagBar,        0,          Button3,        toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1,        tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3,        toggletag,      {0} },
};
