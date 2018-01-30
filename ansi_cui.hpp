#pragma once

#include <iostream>

namespace ansi_cui
{
    const auto ESC = "\x1b";
    const auto CSI = "\x1b\x5b";

    namespace cursor
    {
        /**
         * Moves the cursor to the specified position (coordinates).
         * If you do not specify a position, the cursor moves to the home 
         * position at the upper-left corner of the screen (line 0, column 0).
         * This escape sequence works the same way as the following
         * Cursor Position escape sequence.
         */
        static void move_to(unsigned int line, unsigned int column, std::ostream & stream = std::cout)
        {
            stream << CSI << line << ';' << column << 'H';
        }

        /**
         *	Moves the cursor up by the specified number of lines without 
         *	changing columns. 
         *	If the cursor is already on the top line, ANSI.SYS ignores this 
         *	sequence.
         */
        static void move_up(unsigned int length, std::ostream & stream = std::cout)
        {
            stream << CSI << length << 'A';
        }

        /**
         * Moves the cursor down by the specified number of lines without 
         * changing columns. If the cursor is already on the bottom line,
         * ANSI.SYS ignores this sequence.
         */
        static void move_down(unsigned int length, std::ostream & stream = std::cout)
        {
            stream << CSI << length << 'B';
        }

        /**
         * Moves the cursor forward by the specified number of columns 
         * without changing lines. If the cursor is already in the 
         * rightmost column, ANSI.SYS ignores this sequence.
         */
        static void move_forward(unsigned int length, std::ostream & stream = std::cout)
        {
            stream << CSI << length << 'C';
        }

        /**
         * Moves the cursor back by the specified number of columns without
         * changing lines. If the cursor is already in the leftmost column, 
         * ANSI.SYS ignores this sequence.
         */
        static void move_backward(unsigned int length, std::ostream & stream = std::cout)
        {
            stream << CSI << length << 'D';
        }

        /**
         * Saves the current cursor position. You can move the cursor to 
         * the saved cursor position by using the Restore Cursor Position 
         * sequence.
         */
        static void save_pos(std::ostream & stream = std::cout)
        {
            stream << CSI << 's';
        }

        /**
         * Returns the cursor to the position stored by the Save Cursor 
         * Position sequence.
         */
        static void restore_pos(std::ostream & stream = std::cout)
        {
            stream << CSI << 'u';
        }

        
    }

    namespace screen
    {
        /**
         * Clears the screen and moves the cursor to the home position 
         * (line 0, column 0).
         */
        static void clear(std::ostream & stream = std::cout)
        {
            stream << CSI << "2J";
        }

        /**
         *  Clears all characters from the cursor position to the end of
         *  the line (including the character at the cursor position).
         */
        static void earse_line(std::ostream & stream = std::cout)
        {
            stream << CSI << "K";
        }

        enum text_attr
        {
            text_none_attr = 0,
            text_bold = 1,
            text_underscore = 2,
            text_blink = 5,
            text_reverse = 7,
            text_concealed = 8
        };

        enum foreground_colors
        {
            foreground_black = 30,
            foreground_red = 31,
            foreground_green = 32,
            foreground_yellow = 33,
            foreground_blue = 34,
            foreground_magenta = 35,
            foreground_cyan = 36,
            foreground_white = 37
        };

        enum background_colors
        {
            background_black = 40,
            background_red = 41,
            background_green = 42,
            background_yellow = 43,
            background_blue = 44,
            background_magenta = 45,
            background_cyan = 46,
            background_white = 47
        };

        union graphic_setting
        {
            text_attr text;
            foreground_colors foreground;
            background_colors background;
            int value;

            graphic_setting(text_attr text)
                : text(text)
            {
            }


            graphic_setting(foreground_colors foreground)
                : foreground(foreground)
            {
            }


            graphic_setting(background_colors background)
                : background(background)
            {
            }
        };

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
        static void set_graphic(graphic_setting setting, std::ostream & stream = std::cout)
        {
            stream << CSI << setting.value << 'm';
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
        static void set_mode(unsigned int mode, std::ostream & stream = std::cout)
        {
            stream << CSI << '=' << mode << 'h';
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
        static void reset_mode(unsigned int mode, std::ostream & stream = std::cout)
        {
            stream << CSI << '=' << mode << 'l';
        }
    }
}
