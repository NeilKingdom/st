/* User configuration file for st */

/*** Appearance ***/

/* Primary font */
static char *font = "Terminess Nerd Font:style=Regular:size=14";

/*
    Fallback font(s)
    NOTE: You no longer require the lib-xft-bgra patch anymore.
    This can be uninstalled and replaced with the latest version of libXft.
*/
static char *font2[1] = { "Noto Color Emoji:style=Regular:size=12" };

/* Padding of the terminal */
static int borderpx = 20;

/*
    st will have the following preferences when choosing what shell to use
    1. Program passed with -e
    2. Scroll and/or utmp
    3. $SHELL environment variable
    4. Value of shell in /etc/passwd
    5. The shell variable in config.h below
*/
static char *shell = "/bin/zsh";

/* Legacy feature for users that utilize utmp */
char *utmp = NULL;

/* Legacy feature - use scrollback patch instead */
char *scroll = NULL;

/* TTY arguments. See man stty(1) */
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* Identification sequence returned in DA and DECID */
char *vtiden = "\033[?6c";

/* Kerning/character bounding-box multipliers */
static float cwscale = 1.0f;
static float chscale = 1.0f;

/*
   Word delimiter string (for parsing commands).
   More advanced example: L" `'\"()[]{}"
*/
wchar_t *worddelimiters = L" ";

/* Selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

int allowaltscreen = 1;

/*
   Allow certain non-interactive (insecure) window
   operations such as setting the clipboard text.
*/
int allowwindowops = 0;

/*
   Draw latency range in ms - from new content/keypress/etc until drawing.
   within this range, st draws when content stops arriving (idle). mostly it's
   near minlatency, but it waits longer for slow updates to avoid partial draw.
   low minlatency will tear/flicker more, as it can "detect" idle too early.
*/
static double minlatency = 8;
static double maxlatency = 33;

/*
    Blinking timeout (set to 0 to disable blinking)
    for the terminal blinking attribute.
*/
static unsigned int blinktimeout = 800;

/*
    Bell volume.
    Valid range is -100..100.
    Use 0 to disable it.
*/
static int bellvolume = 0;

/* Default window name */
char *termname = "st-256color";

/* Number of spaces that make up a tab */
unsigned int tabspaces = 4;

/* Background opacity */
float alpha = 0.9f;
float alpha2; /* Used for my own change alpha patch */

/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
    /* 8 normal colors */
    "black",
    "red3",
    "green3",
    "yellow3",
    "blue2",
    "magenta3",
    "cyan3",
    "gray90",

    /* 8 bright colors */
    "gray50",
    "red",
    "green",
    "yellow",
    "#5C5CFF",
    "magenta",
    "cyan",
    "white",

    [255] = 0,

    /* More colors can be added after 255 to use with DefaultX */
    "#CCCCCC",
    "#555555",
    "gray90", /* Default foreground colour */
    "black",  /* Default background colour */
};


/* Default colors (colorname index) */
unsigned int defaultfg = 258;         /* FG */
unsigned int defaultbg = 259;         /* BG */
unsigned int defaultcs = 256;         /* Cursor */
static unsigned int defaultrcs = 257; /* Reverse cursor */

/*
    List of available terminal cursor shapes:

    2 - Block ("█")
    4 - Underline ("_")
    6 - Bar ("|")
    7 - Snowman ("☃")
*/
static unsigned int cursorshape = 2;

/* Thickness of underline and bar cursors */
static unsigned int cursorthickness = 2;

/*
    0: Disable (render all U25XX glyphs normally from the font).
    1: Render most of the lines/blocks characters without using the font for
       perfect alignment between cells (U2500 - U259F except dashes/diagonals).
       Bold affects lines thickness if boxdraw_bold is not 0. Italic is ignored.
 */
const int boxdraw = 1;
const int boxdraw_bold = 1;

/*
    Braille (U28XX):

    0: Use font
    1: Render as adjacent "pixels"
*/
const int boxdraw_braille = 1;

/* Number of character columns and rows (default: 80x24) */
static unsigned int cols = 80;
static unsigned int rows = 24;

/* Default color and shape of the mouse pointer */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/*
    Color used to display font attributes when fontconfig selected a font which
    doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;

/*
    Force mouse select/shortcuts while mask is active (when MODE_MOUSE is set).
    Note that if you want to use ShiftMask with selmasks, set this to an other
    modifier, set to 0 to not use it.
 */
static uint forcemousemod = ShiftMask;

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
    { "font",         STRING,  &font },
    { "color0",       STRING,  &colorname[0] },
    { "color1",       STRING,  &colorname[1] },
    { "color2",       STRING,  &colorname[2] },
    { "color3",       STRING,  &colorname[3] },
    { "color4",       STRING,  &colorname[4] },
    { "color5",       STRING,  &colorname[5] },
    { "color6",       STRING,  &colorname[6] },
    { "color7",       STRING,  &colorname[7] },
    { "color8",       STRING,  &colorname[8] },
    { "color9",       STRING,  &colorname[9] },
    { "color10",      STRING,  &colorname[10] },
    { "color11",      STRING,  &colorname[11] },
    { "color12",      STRING,  &colorname[12] },
    { "color13",      STRING,  &colorname[13] },
    { "color14",      STRING,  &colorname[14] },
    { "color15",      STRING,  &colorname[15] },
    { "background",   STRING,  &colorname[256] },
    { "foreground",   STRING,  &colorname[257] },
    { "cursorColor",  STRING,  &colorname[258] },
    { "termname",     STRING,  &termname },
    { "shell",        STRING,  &shell },
    { "minlatency",   INTEGER, &minlatency },
    { "maxlatency",   INTEGER, &maxlatency },
    { "blinktimeout", INTEGER, &blinktimeout },
    { "bellvolume",   INTEGER, &bellvolume },
    { "tabspaces",    INTEGER, &tabspaces },
    { "borderpx",     INTEGER, &borderpx },
    { "cwscale",      FLOAT,   &cwscale },
    { "chscale",      FLOAT,   &chscale },
};

/*
    Internal mouse shortcuts:

    Button 1 = Left click
    Button 2 = Scroll wheel
    Button 3 = Right click
    Button 4 = Scroll up
    Button 5 = Scroll down
    Button 6 = Scroll left
    Button 7 = Scroll right
    Button 8 = Back button
    Button 9 = Forwards button
*/
static MouseShortcut mshortcuts[] = {
    /* Mask       Button   Function     Argument              Release */
    { XK_ANY_MOD, Button2, clippaste,   { .i = 0 },           1 }, /* Paste clipboard */
 	{ XK_NO_MOD,  Button4, kscrollup,   { .i = 1 },           0 }, /* Scroll buffer up */
 	{ XK_NO_MOD,  Button5, kscrolldown, { .i = 1 },           0 }, /* Scroll buffer down */
    { ShiftMask,  Button5, ttysend,     { .s = "\033[6;2~" }, 0 },
    { XK_ANY_MOD, Button5, ttysend,     { .s = "\005" },      0 },
};

/* Internal keyboard shortcuts */
#define MODKEY Mod1Mask /* Mod1Mask = Alt */
#define TERMMOD (ControlMask | ShiftMask)

static Shortcut shortcuts[] = {
    /* Mask               Keysym         Function       Argument */
    { XK_ANY_MOD,         XK_Break,      sendbreak,     { .i =  0 }},
    { ControlMask,        XK_Print,      toggleprinter, { .i =  0 }},
    { ShiftMask,          XK_Print,      printscreen,   { .i =  0 }},
    { XK_ANY_MOD,         XK_Print,      printsel,      { .i =  0 }},
    { TERMMOD,            XK_Num_Lock,   numlock,       { .i =  0 }},
    { MODKEY,             XK_minus,      zoom,          { .f = -2 }}, /* Decrease zoom */
    { MODKEY | ShiftMask, XK_plus,       zoom,          { .f = +2 }}, /* Increase zoom */
    { MODKEY,             XK_equal,      zoomreset,     { .f =  0 }}, /* Reset zoom */
    { MODKEY,             XK_c,          clipcopy,      { .i =  0 }}, /* Copy to clipboard */
    { MODKEY,             XK_v,          clippaste,     { .i =  0 }}, /* Paste from clipboard */
    { MODKEY,             XK_y,          selpaste,      { .i =  0 }}, /* Copy to selection */
    { ShiftMask,          XK_Insert,     selpaste,      { .i =  0 }}, /* Paste from selection */
    { MODKEY,             XK_Return,     newterm,       { .i =  0 }}, /* Open new shell in the current directory */
    { MODKEY,             XK_9,          chgalpha,      { .f = -1 }}, /* Decrease opacity */
    { MODKEY | ShiftMask, XK_parenright, chgalpha,      { .f = +1 }}, /* Increase opacity */
    { MODKEY,             XK_0,          chgalpha,      { .f =  0 }}, /* Reset alpha */
};

/*
   Defines Xorg key codes, modifiers (masks), ANSI VT100 terminal codes,
   for each and every key combination.

   Special keys (change & recompile st.info accordingly):

   Mask value:
   - Use XK_ANY_MOD to match the key no matter modifiers state
   - Use XK_NO_MOD to match the key alone (no modifiers)

   Appkey value:
   - 0: no value
   - > 0: keypad application mode enabled
   - = 2: term.numlock = 1
   - < 0: keypad application mode disabled

   Appcursor value:
   - 0: no value
   - > 0: cursor application mode enabled
   - < 0: cursor application mode disabled

   Be careful with the order of the definitions because st searches in
   this table sequentially, so any XK_ANY_MOD must be in the last
   position for a key.
*/

/*
   If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
   to be mapped below, add them to this array.
*/
static KeySym mappedkeys[] = { -1 };

/*
   State bits to ignore when matching key or button events. By default,
   numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
*/
static uint ignoremod = (Mod2Mask | XK_SWITCH_MOD);

static Key key[] = {
    /* Keysym           Mask                            String          Appkey Appcursor */
    { XK_KP_Home,       ShiftMask,                      "\033[2J",      0,     -1 },
    { XK_KP_Home,       ShiftMask,                      "\033[1;2H",    0,     +1 },
    { XK_KP_Home,       XK_ANY_MOD,                     "\033[H",       0,     -1 },
    { XK_KP_Home,       XK_ANY_MOD,                     "\033[1~",      0,     +1 },
    { XK_KP_Up,         XK_ANY_MOD,                     "\033Ox",      +1,      0 },
    { XK_KP_Up,         XK_ANY_MOD,                     "\033[A",       0,     -1 },
    { XK_KP_Up,         XK_ANY_MOD,                     "\033OA",       0,     +1 },
    { XK_KP_Down,       XK_ANY_MOD,                     "\033Or",      +1,      0 },
    { XK_KP_Down,       XK_ANY_MOD,                     "\033[B",       0,     -1 },
    { XK_KP_Down,       XK_ANY_MOD,                     "\033OB",       0,     +1 },
    { XK_KP_Left,       XK_ANY_MOD,                     "\033Ot",      +1,      0 },
    { XK_KP_Left,       XK_ANY_MOD,                     "\033[D",       0,     -1 },
    { XK_KP_Left,       XK_ANY_MOD,                     "\033OD",       0,     +1 },
    { XK_KP_Right,      XK_ANY_MOD,                     "\033Ov",      +1,      0 },
    { XK_KP_Right,      XK_ANY_MOD,                     "\033[C",       0,     -1 },
    { XK_KP_Right,      XK_ANY_MOD,                     "\033OC",       0,     +1 },
    { XK_KP_Prior,      ShiftMask,                      "\033[5;2~",    0,      0 },
    { XK_KP_Prior,      XK_ANY_MOD,                     "\033[5~",      0,      0 },
    { XK_KP_Begin,      XK_ANY_MOD,                     "\033[E",       0,      0 },
    { XK_KP_End,        ControlMask,                    "\033[J",      -1,      0 },
    { XK_KP_End,        ControlMask,                    "\033[1;5F",   +1,      0 },
    { XK_KP_End,        ShiftMask,                      "\033[K",      -1,      0 },
    { XK_KP_End,        ShiftMask,                      "\033[1;2F",   +1,      0 },
    { XK_KP_End,        XK_ANY_MOD,                     "\033[4~",      0,      0 },
    { XK_KP_Next,       ShiftMask,                      "\033[6;2~",    0,      0 },
    { XK_KP_Next,       XK_ANY_MOD,                     "\033[6~",      0,      0 },
    { XK_KP_Insert,     ShiftMask,                      "\033[2;2~",   +1,      0 },
    { XK_KP_Insert,     ShiftMask,                      "\033[4l",     -1,      0 },
    { XK_KP_Insert,     ControlMask,                    "\033[L",      -1,      0 },
    { XK_KP_Insert,     ControlMask,                    "\033[2;5~",   +1,      0 },
    { XK_KP_Insert,     XK_ANY_MOD,                     "\033[4h",     -1,      0 },
    { XK_KP_Insert,     XK_ANY_MOD,                     "\033[2~",     +1,      0 },
    { XK_KP_Delete,     ControlMask,                    "\033[M",      -1,      0 },
    { XK_KP_Delete,     ControlMask,                    "\033[3;5~",   +1,      0 },
    { XK_KP_Delete,     ShiftMask,                      "\033[2K",     -1,      0 },
    { XK_KP_Delete,     ShiftMask,                      "\033[3;2~",   +1,      0 },
    { XK_KP_Delete,     XK_ANY_MOD,                     "\033[P",      -1,      0 },
    { XK_KP_Delete,     XK_ANY_MOD,                     "\033[3~",     +1,      0 },
    { XK_KP_Multiply,   XK_ANY_MOD,                     "\033Oj",      +2,      0 },
    { XK_KP_Add,        XK_ANY_MOD,                     "\033Ok",      +2,      0 },
    { XK_KP_Enter,      XK_ANY_MOD,                     "\033OM",      +2,      0 },
    { XK_KP_Enter,      XK_ANY_MOD,                     "\r",          -1,      0 },
    { XK_KP_Subtract,   XK_ANY_MOD,                     "\033Om",      +2,      0 },
    { XK_KP_Decimal,    XK_ANY_MOD,                     "\033On",      +2,      0 },
    { XK_KP_Divide,     XK_ANY_MOD,                     "\033Oo",      +2,      0 },
    { XK_KP_0,          XK_ANY_MOD,                     "\033Op",      +2,      0 },
    { XK_KP_1,          XK_ANY_MOD,                     "\033Oq",      +2,      0 },
    { XK_KP_2,          XK_ANY_MOD,                     "\033Or",      +2,      0 },
    { XK_KP_3,          XK_ANY_MOD,                     "\033Os",      +2,      0 },
    { XK_KP_4,          XK_ANY_MOD,                     "\033Ot",      +2,      0 },
    { XK_KP_5,          XK_ANY_MOD,                     "\033Ou",      +2,      0 },
    { XK_KP_6,          XK_ANY_MOD,                     "\033Ov",      +2,      0 },
    { XK_KP_7,          XK_ANY_MOD,                     "\033Ow",      +2,      0 },
    { XK_KP_8,          XK_ANY_MOD,                     "\033Ox",      +2,      0 },
    { XK_KP_9,          XK_ANY_MOD,                     "\033Oy",      +2,      0 },
    { XK_Up,            ShiftMask,                      "\033[1;2A",    0,      0 },
    { XK_Up,            Mod1Mask,                       "\033[1;3A",    0,      0 },
    { XK_Up,            ShiftMask|Mod1Mask,             "\033[1;4A",    0,      0 },
    { XK_Up,            ControlMask,                    "\033[1;5A",    0,      0 },
    { XK_Up,            ShiftMask|ControlMask,          "\033[1;6A",    0,      0 },
    { XK_Up,            ControlMask|Mod1Mask,           "\033[1;7A",    0,      0 },
    { XK_Up,            ShiftMask|ControlMask|Mod1Mask, "\033[1;8A",    0,      0 },
    { XK_Up,            XK_ANY_MOD,                     "\033[A",       0,     -1 },
    { XK_Up,            XK_ANY_MOD,                     "\033OA",       0,     +1 },
    { XK_Down,          ShiftMask,                      "\033[1;2B",    0,      0 },
    { XK_Down,          Mod1Mask,                       "\033[1;3B",    0,      0 },
    { XK_Down,          ShiftMask|Mod1Mask,             "\033[1;4B",    0,      0 },
    { XK_Down,          ControlMask,                    "\033[1;5B",    0,      0 },
    { XK_Down,          ShiftMask|ControlMask,          "\033[1;6B",    0,      0 },
    { XK_Down,          ControlMask|Mod1Mask,           "\033[1;7B",    0,      0 },
    { XK_Down,          ShiftMask|ControlMask|Mod1Mask, "\033[1;8B",    0,      0 },
    { XK_Down,          XK_ANY_MOD,                     "\033[B",       0,     -1 },
    { XK_Down,          XK_ANY_MOD,                     "\033OB",       0,     +1 },
    { XK_Left,          ShiftMask,                      "\033[1;2D",    0,      0 },
    { XK_Left,          Mod1Mask,                       "\033[1;3D",    0,      0 },
    { XK_Left,          ShiftMask|Mod1Mask,             "\033[1;4D",    0,      0 },
    { XK_Left,          ControlMask,                    "\033[1;5D",    0,      0 },
    { XK_Left,          ShiftMask|ControlMask,          "\033[1;6D",    0,      0 },
    { XK_Left,          ControlMask|Mod1Mask,           "\033[1;7D",    0,      0 },
    { XK_Left,          ShiftMask|ControlMask|Mod1Mask, "\033[1;8D",    0,      0 },
    { XK_Left,          XK_ANY_MOD,                     "\033[D",       0,     -1 },
    { XK_Left,          XK_ANY_MOD,                     "\033OD",       0,     +1 },
    { XK_Right,         ShiftMask,                      "\033[1;2C",    0,      0 },
    { XK_Right,         Mod1Mask,                       "\033[1;3C",    0,      0 },
    { XK_Right,         ShiftMask|Mod1Mask,             "\033[1;4C",    0,      0 },
    { XK_Right,         ControlMask,                    "\033[1;5C",    0,      0 },
    { XK_Right,         ShiftMask|ControlMask,          "\033[1;6C",    0,      0 },
    { XK_Right,         ControlMask|Mod1Mask,           "\033[1;7C",    0,      0 },
    { XK_Right,         ShiftMask|ControlMask|Mod1Mask, "\033[1;8C",    0,      0 },
    { XK_Right,         XK_ANY_MOD,                     "\033[C",       0,     -1 },
    { XK_Right,         XK_ANY_MOD,                     "\033OC",       0,     +1 },
    { XK_ISO_Left_Tab,  ShiftMask,                      "\033[Z",       0,      0 },
    { XK_Return,        Mod1Mask,                       "\033\r",       0,      0 },
    { XK_Return,        XK_ANY_MOD,                     "\r",           0,      0 },
    { XK_Insert,        ShiftMask,                      "\033[4l",     -1,      0 },
    { XK_Insert,        ShiftMask,                      "\033[2;2~",   +1,      0 },
    { XK_Insert,        ControlMask,                    "\033[L",      -1,      0 },
    { XK_Insert,        ControlMask,                    "\033[2;5~",   +1,      0 },
    { XK_Insert,        XK_ANY_MOD,                     "\033[4h",     -1,      0 },
    { XK_Insert,        XK_ANY_MOD,                     "\033[2~",     +1,      0 },
    { XK_Delete,        ControlMask,                    "\033[M",      -1,      0 },
    { XK_Delete,        ControlMask,                    "\033[3;5~",   +1,      0 },
    { XK_Delete,        ShiftMask,                      "\033[2K",     -1,      0 },
    { XK_Delete,        ShiftMask,                      "\033[3;2~",   +1,      0 },
    { XK_Delete,        XK_ANY_MOD,                     "\033[P",      -1,      0 },
    { XK_Delete,        XK_ANY_MOD,                     "\033[3~",     +1,      0 },
    { XK_BackSpace,     XK_NO_MOD,                      "\177",         0,      0 },
    { XK_BackSpace,     Mod1Mask,                       "\033\177",     0,      0 },
    { XK_Home,          ShiftMask,                      "\033[2J",      0,     -1 },
    { XK_Home,          ShiftMask,                      "\033[1;2H",    0,     +1 },
    { XK_Home,          XK_ANY_MOD,                     "\033[H",       0,     -1 },
    { XK_Home,          XK_ANY_MOD,                     "\033[1~",      0,     +1 },
    { XK_End,           ControlMask,                    "\033[J",      -1,      0 },
    { XK_End,           ControlMask,                    "\033[1;5F",   +1,      0 },
    { XK_End,           ShiftMask,                      "\033[K",      -1,      0 },
    { XK_End,           ShiftMask,                      "\033[1;2F",   +1,      0 },
    { XK_End,           XK_ANY_MOD,                     "\033[4~",      0,      0 },
    { XK_Prior,         ControlMask,                    "\033[5;5~",    0,      0 },
    { XK_Prior,         ShiftMask,                      "\033[5;2~",    0,      0 },
    { XK_Prior,         XK_ANY_MOD,                     "\033[5~",      0,      0 },
    { XK_Next,          ControlMask,                    "\033[6;5~",    0,      0 },
    { XK_Next,          ShiftMask,                      "\033[6;2~",    0,      0 },
    { XK_Next,          XK_ANY_MOD,                     "\033[6~",      0,      0 },
    { XK_F1,            XK_NO_MOD,                      "\033OP" ,      0,      0 },
    { XK_F1,  /* F13 */ ShiftMask,                      "\033[1;2P",    0,      0 },
    { XK_F1,  /* F25 */ ControlMask,                    "\033[1;5P",    0,      0 },
    { XK_F1,  /* F37 */ Mod4Mask,                       "\033[1;6P",    0,      0 },
    { XK_F1,  /* F49 */ Mod1Mask,                       "\033[1;3P",    0,      0 },
    { XK_F1,  /* F61 */ Mod3Mask,                       "\033[1;4P",    0,      0 },
    { XK_F2,            XK_NO_MOD,                      "\033OQ" ,      0,      0 },
    { XK_F2,  /* F14 */ ShiftMask,                      "\033[1;2Q",    0,      0 },
    { XK_F2,  /* F26 */ ControlMask,                    "\033[1;5Q",    0,      0 },
    { XK_F2,  /* F38 */ Mod4Mask,                       "\033[1;6Q",    0,      0 },
    { XK_F2,  /* F50 */ Mod1Mask,                       "\033[1;3Q",    0,      0 },
    { XK_F2,  /* F62 */ Mod3Mask,                       "\033[1;4Q",    0,      0 },
    { XK_F3,            XK_NO_MOD,                      "\033OR" ,      0,      0 },
    { XK_F3,  /* F15 */ ShiftMask,                      "\033[1;2R",    0,      0 },
    { XK_F3,  /* F27 */ ControlMask,                    "\033[1;5R",    0,      0 },
    { XK_F3,  /* F39 */ Mod4Mask,                       "\033[1;6R",    0,      0 },
    { XK_F3,  /* F51 */ Mod1Mask,                       "\033[1;3R",    0,      0 },
    { XK_F3,  /* F63 */ Mod3Mask,                       "\033[1;4R",    0,      0 },
    { XK_F4,            XK_NO_MOD,                      "\033OS" ,      0,      0 },
    { XK_F4,  /* F16 */ ShiftMask,                      "\033[1;2S",    0,      0 },
    { XK_F4,  /* F28 */ ControlMask,                    "\033[1;5S",    0,      0 },
    { XK_F4,  /* F40 */ Mod4Mask,                       "\033[1;6S",    0,      0 },
    { XK_F4,  /* F52 */ Mod1Mask,                       "\033[1;3S",    0,      0 },
    { XK_F5,            XK_NO_MOD,                      "\033[15~",     0,      0 },
    { XK_F5,  /* F17 */ ShiftMask,                      "\033[15;2~",   0,      0 },
    { XK_F5,  /* F29 */ ControlMask,                    "\033[15;5~",   0,      0 },
    { XK_F5,  /* F41 */ Mod4Mask,                       "\033[15;6~",   0,      0 },
    { XK_F5,  /* F53 */ Mod1Mask,                       "\033[15;3~",   0,      0 },
    { XK_F6,            XK_NO_MOD,                      "\033[17~",     0,      0 },
    { XK_F6,  /* F18 */ ShiftMask,                      "\033[17;2~",   0,      0 },
    { XK_F6,  /* F30 */ ControlMask,                    "\033[17;5~",   0,      0 },
    { XK_F6,  /* F42 */ Mod4Mask,                       "\033[17;6~",   0,      0 },
    { XK_F6,  /* F54 */ Mod1Mask,                       "\033[17;3~",   0,      0 },
    { XK_F7,            XK_NO_MOD,                      "\033[18~",     0,      0 },
    { XK_F7,  /* F19 */ ShiftMask,                      "\033[18;2~",   0,      0 },
    { XK_F7,  /* F31 */ ControlMask,                    "\033[18;5~",   0,      0 },
    { XK_F7,  /* F43 */ Mod4Mask,                       "\033[18;6~",   0,      0 },
    { XK_F7,  /* F55 */ Mod1Mask,                       "\033[18;3~",   0,      0 },
    { XK_F8,            XK_NO_MOD,                      "\033[19~",     0,      0 },
    { XK_F8,  /* F20 */ ShiftMask,                      "\033[19;2~",   0,      0 },
    { XK_F8,  /* F32 */ ControlMask,                    "\033[19;5~",   0,      0 },
    { XK_F8,  /* F44 */ Mod4Mask,                       "\033[19;6~",   0,      0 },
    { XK_F8,  /* F56 */ Mod1Mask,                       "\033[19;3~",   0,      0 },
    { XK_F9,            XK_NO_MOD,                      "\033[20~",     0,      0 },
    { XK_F9,  /* F21 */ ShiftMask,                      "\033[20;2~",   0,      0 },
    { XK_F9,  /* F33 */ ControlMask,                    "\033[20;5~",   0,      0 },
    { XK_F9,  /* F45 */ Mod4Mask,                       "\033[20;6~",   0,      0 },
    { XK_F9,  /* F57 */ Mod1Mask,                       "\033[20;3~",   0,      0 },
    { XK_F10,           XK_NO_MOD,                      "\033[21~",     0,      0 },
    { XK_F10, /* F22 */ ShiftMask,                      "\033[21;2~",   0,      0 },
    { XK_F10, /* F34 */ ControlMask,                    "\033[21;5~",   0,      0 },
    { XK_F10, /* F46 */ Mod4Mask,                       "\033[21;6~",   0,      0 },
    { XK_F10, /* F58 */ Mod1Mask,                       "\033[21;3~",   0,      0 },
    { XK_F11,           XK_NO_MOD,                      "\033[23~",     0,      0 },
    { XK_F11, /* F23 */ ShiftMask,                      "\033[23;2~",   0,      0 },
    { XK_F11, /* F35 */ ControlMask,                    "\033[23;5~",   0,      0 },
    { XK_F11, /* F47 */ Mod4Mask,                       "\033[23;6~",   0,      0 },
    { XK_F11, /* F59 */ Mod1Mask,                       "\033[23;3~",   0,      0 },
    { XK_F12,           XK_NO_MOD,                      "\033[24~",     0,      0 },
    { XK_F12, /* F24 */ ShiftMask,                      "\033[24;2~",   0,      0 },
    { XK_F12, /* F36 */ ControlMask,                    "\033[24;5~",   0,      0 },
    { XK_F12, /* F48 */ Mod4Mask,                       "\033[24;6~",   0,      0 },
    { XK_F12, /* F60 */ Mod1Mask,                       "\033[24;3~",   0,      0 },
    { XK_F13,           XK_NO_MOD,                      "\033[1;2P",    0,      0 },
    { XK_F14,           XK_NO_MOD,                      "\033[1;2Q",    0,      0 },
    { XK_F15,           XK_NO_MOD,                      "\033[1;2R",    0,      0 },
    { XK_F16,           XK_NO_MOD,                      "\033[1;2S",    0,      0 },
    { XK_F17,           XK_NO_MOD,                      "\033[15;2~",   0,      0 },
    { XK_F18,           XK_NO_MOD,                      "\033[17;2~",   0,      0 },
    { XK_F19,           XK_NO_MOD,                      "\033[18;2~",   0,      0 },
    { XK_F20,           XK_NO_MOD,                      "\033[19;2~",   0,      0 },
    { XK_F21,           XK_NO_MOD,                      "\033[20;2~",   0,      0 },
    { XK_F22,           XK_NO_MOD,                      "\033[21;2~",   0,      0 },
    { XK_F23,           XK_NO_MOD,                      "\033[23;2~",   0,      0 },
    { XK_F24,           XK_NO_MOD,                      "\033[24;2~",   0,      0 },
    { XK_F25,           XK_NO_MOD,                      "\033[1;5P",    0,      0 },
    { XK_F26,           XK_NO_MOD,                      "\033[1;5Q",    0,      0 },
    { XK_F27,           XK_NO_MOD,                      "\033[1;5R",    0,      0 },
    { XK_F28,           XK_NO_MOD,                      "\033[1;5S",    0,      0 },
    { XK_F29,           XK_NO_MOD,                      "\033[15;5~",   0,      0 },
    { XK_F30,           XK_NO_MOD,                      "\033[17;5~",   0,      0 },
    { XK_F31,           XK_NO_MOD,                      "\033[18;5~",   0,      0 },
    { XK_F32,           XK_NO_MOD,                      "\033[19;5~",   0,      0 },
    { XK_F33,           XK_NO_MOD,                      "\033[20;5~",   0,      0 },
    { XK_F34,           XK_NO_MOD,                      "\033[21;5~",   0,      0 },
    { XK_F35,           XK_NO_MOD,                      "\033[23;5~",   0,      0 },
};

/*
   Selection type masks.
   Use the same masks as usual.
   Button1Mask is always unset, to make masks match between ButtonPress.
   ButtonRelease and MotionNotify.
   If no match is found, regular selection is used.
*/
static uint selmasks[] = {
    [SEL_RECTANGULAR] = Mod1Mask,
};

/*
   Printable characters in ASCII, used to estimate the advance width
   of single wide characters.
*/
static char ascii_printable[] =
    " !\"#$%&'()*+,-./0123456789:;<=>?"
    "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
    "`abcdefghijklmnopqrstuvwxyz{|}~";
