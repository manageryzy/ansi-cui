#ifndef ANSI_CUI_H
#define ANSI_CUI_H

#include <stdio.h>

#define ESC "\x1b"
#define CSI "\x1b\x5b"

/**
* Moves the cursor to the specified position (coordinates).
* If you do not specify a position, the cursor moves to the home
* position at the upper-left corner of the screen (line 0, column 0).
* This escape sequence works the same way as the following
* Cursor Position escape sequence.
*/

static inline void cursor_move_to(unsigned int line, unsigned int column,FILE * fp = stdout)
{
    fprintf(fp, CSI"%u;%uH", line, column);
}

/**
*	Moves the cursor up by the specified number of lines without
*	changing columns.
*	If the cursor is already on the top line, ANSI.SYS ignores this
*	sequence.
*/
static inline void cursor_move_up(unsigned int length, FILE * fp = stdout)
{
    fprintf(fp, CSI"%uA", length);
}

/**
* Moves the cursor down by the specified number of lines without
* changing columns. If the cursor is already on the bottom line,
* ANSI.SYS ignores this sequence.
*/
static inline void cursor_move_down(unsigned int length, FILE * fp = stdout)
{
    fprintf(fp, CSI"%uB", length);
}

/**
* Moves the cursor forward by the specified number of columns
* without changing lines. If the cursor is already in the
* rightmost column, ANSI.SYS ignores this sequence.
*/
static inline void cursor_move_forward(unsigned int length, FILE * fp = stdout)
{
    fprintf(fp, CSI"%uC", length);
}

/**
* Moves the cursor back by the specified number of columns without
* changing lines. If the cursor is already in the leftmost column,
* ANSI.SYS ignores this sequence.
*/
static inline void cursor_move_backward(unsigned int length, FILE * fp = stdout)
{
    fprintf(fp, CSI"%uC", length);
}

/**
* Saves the current cursor position. You can move the cursor to
* the saved cursor position by using the Restore Cursor Position
* sequence.
*/
static inline void cursor_save_pos(FILE * fp = stdout)
{
    fprintf(fp, CSI"s");
}

/**
* Returns the cursor to the position stored by the Save Cursor
* Position sequence.
*/
static inline void cursor_restore_pos(FILE * fp = stdout)
{
    fprintf(fp, CSI"u");
}

/**
* Clears the screen and moves the cursor to the home position
* (line 0, column 0).
*/
static inline void screen_clear(FILE * fp = stdout)
{
    fprintf(fp, CSI"2J");
}

/**
*  Clears all characters from the cursor position to the end of
*  the line (including the character at the cursor position).
*/
static inline void screen_earse_line(FILE * fp = stdout)
{
    fprintf(fp, CSI"K");
}

/**
* Calls the graphics functions specified by the following values.
* These specified functions remain active until the next occurrence
* of this escape sequence. Graphics mode changes the colors and
* attributes of text (such as bold and underline) displayed on
* the screen.
* 
* Text attributes
* 0	All attributes off
* 1	Bold on
* 4	Underscore (on monochrome display adapter only)
* 5	Blink on
* 7	Reverse video on
* 8	Concealed on
* 
* Foreground colors
* 30	Black
* 31	Red
* 32	Green
* 33	Yellow
* 34	Blue
* 35	Magenta
* 36	Cyan
* 37	White
* 
* Background colors
* 40	Black
* 41	Red
* 42	Green
* 43	Yellow
* 44	Blue
* 45	Magenta
* 46	Cyan
* 47	White
*/
static inline void screen_set_graphic(unsigned int setting, FILE * fp = stdout)
{
    fprintf(fp, CSI"%um",setting);
}

/**
*  Changes the screen width or type to the mode specified by one of
*  the following values:
*
*  0	40 x 25 monochrome (text)
*  1	40 x 25 color (text)
*  2	80 x 25 monochrome (text)
*  3	80 x 25 color (text)
*  4	320 x 200 4-color (graphics)
*  5	320 x 200 monochrome (graphics)
*  6	640 x 200 monochrome (graphics)
*  7	Enables line wrapping
*  13	320 x 200 color (graphics)
*  14	640 x 200 color (16-color graphics)
*  15	640 x 350 monochrome (2-color graphics)
*  16	640 x 350 color (16-color graphics)
*  17	640 x 480 monochrome (2-color graphics)
*  18	640 x 480 color (16-color graphics)
*  19	320 x 200 color (256-color graphics)
**/
static inline void screen_set_mode(unsigned int setting, FILE * fp = stdout)
{
    fprintf(fp, CSI"=%uh", setting);
}

/**
*  Resets the mode by using the same values that Set Mode uses,
*  except for 7, which disables line wrapping
*
*  0	40 x 25 monochrome (text)
*  1	40 x 25 color (text)
*  2	80 x 25 monochrome (text)
*  3	80 x 25 color (text)
*  4	320 x 200 4-color (graphics)
*  5	320 x 200 monochrome (graphics)
*  6	640 x 200 monochrome (graphics)
*  13	320 x 200 color (graphics)
*  14	640 x 200 color (16-color graphics)
*  15	640 x 350 monochrome (2-color graphics)
*  16	640 x 350 color (16-color graphics)
*  17	640 x 480 monochrome (2-color graphics)
*  18	640 x 480 color (16-color graphics)
*  19	320 x 200 color (256-color graphics)
**/
static inline void screen_reset_mode(unsigned int setting, FILE * fp = stdout)
{
    fprintf(fp, CSI"=%ul", setting);
}

#undef ESC
#undef CSI
#endif
