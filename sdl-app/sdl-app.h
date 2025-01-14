#pragma once
#include "sdl-app-fonts-16.h"
#include "sdl-app-fonts-8.h"
#include "sdl-app-fonts.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <SDL.h>

/** The size of the internal text formatting buffer used by DBGP_Printf */
#ifndef DBGP_MAX_STR_LEN
#define DBGP_MAX_STR_LEN    SDL_MAX_LOG_MESSAGE
#endif

/** The escape character used for changing colors in the middle of a string.
 * By default, it's "$", meaning that "$0F" will print in white on a transparent
 * background */
#ifndef DBGP_ESCAPE_CHAR
#define DBGP_ESCAPE_CHAR    '$'
#endif

/** Whether color escapes codes such as "$F0" should be parsed. */
#ifndef DBGP_ENABLE_ESCAPING
#define DBGP_ENABLE_ESCAPING    1
#endif

/** The default color to draw in (white on transparent background) */
#define DBGP_DEFAULT_COLORS    0x0f

/**
 * \struct DBGP_Font
 * \brief Represents a font that will be used to display glyphes on screen.
 *
 * This struct should be considered read-only.
 *
 * \sa DBGP_OpenFont
 */
struct DBGP_Font {
  uint8_t      glyph_width;         /**< the width in pixels of each glyph */
  uint8_t      glyph_height;        /**< the height in pixels of each glyph */
  unsigned int nb_glyphs;           /**< the number of glyphs in font */
  SDL_Texture  *tex;                /**< texture used when drawing text */
};
typedef struct DBGP_Font DBGP_Font; /**< Convenience typedef */

/**
 * \fn int DBGP_OpenFont(DBGP_Font* font, SDL_Renderer* renderer, const char*
 * const raw_data, size_t raw_data_len, uint8_t glyph_width, uint8_t glyph_height)
 * \brief Loads a font to use with DBGP_Print and DBGP_Printf
 *
 * For convenience, DBGP provides two fonts: UNSCII-8 (8x8px) and UNSCII-16
 * (8x16px). To use the 8x16 one, use:
 *
 * \code
 * DBGP_Font font;
 * DBGP_OpenFont(&font, renderer, DBGP_UNSCII16, sizeof(DBGP_UNSCII16),
 *  DBGP_UNSCII16_WIDTH, DBGP_UNSCII16_HEIGHT)
 * \endcode
 *
 *    \param font The DBGP_Font object
 *    \param renderer The SDL2 renderer object that will be used to render
 *    \param raw_data A pointer to the font raw data
 *    \param raw_data_len The size in bytes of raw_data
 *    \param glyph_width the width in pixels of one glyph (character)
 *    \param glyph_height the height in pixels of one glyph (character)
 *   \return zero on success, -1 on error. You can retrieve the error
 *           message with a call to SDL_GetError()
 *
 * \sa DBGP_CloseFont
 */
int DBGP_OpenFont(DBGP_Font *font, SDL_Renderer *renderer, const char * const raw_data, size_t raw_data_len, uint8_t glyph_width, uint8_t glyph_height);

/**
 * \fn void DBGP_CloseFont(DBGP_Font* font)
 * \brief Frees all memory allocated during DBGP_OpenFont.
 *
 * \sa DBGP_OpenFont
 */
void DBGP_CloseFont(DBGP_Font *font);

/**
 * \fn int DBGP_Print(DBGP_Font* font, SDL_Renderer* renderer, int x, int y,
 * uint8_t colors, const char* str)
 * \brief Draws some text on a renderer
 *
 * The colors parameter is an unsigned byte, where the four least significant
 * bits represent the foreground code, and the four most significant bits
 * represent the background color.
 * Note that background color of 0 will result in a transparent background.
 *
 * For example, to display "Hello world" in white at (10, 50):
 * \code
 * DBGP_Print(font, renderer, 10, 50, 0xF, "Hello world")
 * \endcode
 *
 * This function supports color escape codes to change colors in the middle of
 * a string. These should be in the form `$f0`,
 * where "f" is the background color, and "0" is the foreground color. This
 * feature can be disabled by setting DBGP_ENABLE_ESCAPING to 0.
 *
 *    \param font The DBGP_Font object
 *    \param renderer The SDL2 renderer object that will be used to render
 *    \param x The X coordinate of the text
 *    \param y The Y coordinate of the text
 *    \param colors The colors that will be used to draw (4 most significant
 * bits correspond to the background color, 4 least significant bits correspond
 * to the foreground color)
 *    \param str The text to draw
 *   \return zero on success, -1 on error. You can retrieve the error message
 *           with a call to SDL_GetError()
 *
 * \sa DBGP_Printf
 */
int DBGP_Print(DBGP_Font *font, SDL_Renderer *renderer, int x, int y, uint8_t colors, const char *str);

/**
 * \fn int DBGP_Printf(DBGP_Font* font, SDL_Renderer* renderer, int x, int y,
 * uint8_t colors, const char* fmt, ...)
 * \brief Formats and draws some text on a renderer
 *
 * Same as DBGP_Print, but formats the string `fmt` with variable arguments
 * first. The maximum output size is fixed and can be changed by defining
 * `DBGP_MAX_STR_LEN` before including DBGP.h. See DBGP_Print documentation
 * for more information about the other parameters.
 *
 *    \param font The font to draw with
 *    \param renderer The SDL2 renderer to use
 *    \param x The X coordinate of the text
 *    \param y The Y coordinate of the text
 *    \param colors The colors that will be used to draw (4 upper bits
 * correspond to the background color, 4 lower bits correspond to the foreground
 * color)
 *    \param fmt The string to format
 *    \param ... Variable arguments to format the string with
 *   \return zero on success, -1 on error. You can retrieve the error message
 *           with a call to SDL_GetError()
 *
 * \sa DBGP_Print
 */
int DBGP_Printf(DBGP_Font *font, SDL_Renderer *renderer, int x, int y, uint8_t colors, const char *fmt, ...);
