/*
 * Font data is "UNSCII-8" in the public domain.
 * See https://github.com/viznut/unscii
 */

#ifndef DBGP_DBGP_UNSCII8_H
#define DBGP_DBGP_UNSCII8_H

static const unsigned int DBGP_UNSCII8_WIDTH     = 8;
static const unsigned int DBGP_UNSCII8_HEIGHT    = 8;
static const unsigned int DBGP_UNSCII8_NB_GLYPHS = 256;
static const char         DBGP_UNSCII8[256 * 8]  = {
  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xe0, 0x80, 0xea, 0x2a,
  0xee, 0xa,  0xa,  0x0,  0xe0, 0x80, 0xea, 0x2a, 0xe4, 0xa,  0xa,  0x0,
  0xe0, 0x80, 0xca, 0x8a, 0xe4, 0xa,  0xa,  0x0,  0xe0, 0x80, 0xce, 0x84,
  0xe4, 0x4,  0x4,  0x0,  0xe0, 0x80, 0xce, 0x8a, 0xea, 0xe,  0x4,  0x0,
  0xe0, 0xa0, 0xea, 0xaa, 0xac, 0xa,  0xa,  0x0,  0xc0, 0xa0, 0xc8, 0xa8,
  0xc8, 0x8,  0xe,  0x0,  0xc0, 0xa0, 0xce, 0xa8, 0xce, 0x2,  0xe,  0x0,
  0xa0, 0xa0, 0xee, 0xa4, 0xa4, 0x4,  0x4,  0x0,  0x80, 0x80, 0x8e, 0x88,
  0xec, 0x8,  0x8,  0x0,  0xa0, 0xa0, 0xae, 0xa4, 0x44, 0x4,  0x4,  0x0,
  0xe0, 0x80, 0xce, 0x88, 0x8c, 0x8,  0x8,  0x0,  0xe0, 0x80, 0x8e, 0x8a,
  0xee, 0xc,  0xa,  0x0,  0xe0, 0x80, 0xee, 0x2a, 0xea, 0xa,  0xe,  0x0,
  0xe0, 0x80, 0xee, 0x24, 0xe4, 0x4,  0xe,  0x0,  0xc0, 0xa0, 0xa8, 0xa8,
  0xc8, 0x8,  0xe,  0x0,  0xc0, 0xa0, 0xa4, 0xac, 0xc4, 0x4,  0xe,  0x0,
  0xc0, 0xa0, 0xae, 0xa2, 0xce, 0x8,  0xe,  0x0,  0xc0, 0xa0, 0xae, 0xa2,
  0xc6, 0x2,  0xe,  0x0,  0xc0, 0xa0, 0xaa, 0xaa, 0xce, 0x2,  0x2,  0x0,
  0xe0, 0xa0, 0xaa, 0xaa, 0xac, 0xa,  0xa,  0x0,  0xe0, 0x80, 0xea, 0x2a,
  0xee, 0x4,  0x4,  0x0,  0xe0, 0x80, 0xcc, 0x8a, 0xec, 0xa,  0xc,  0x0,
  0xe0, 0x80, 0x8e, 0x8a, 0xea, 0xa,  0xa,  0x0,  0xe0, 0x80, 0xca, 0x8e,
  0xea, 0xa,  0xa,  0x0,  0x3c, 0x66, 0x66, 0x30, 0x18, 0x0,  0x18, 0x0,
  0xe0, 0x80, 0xce, 0x88, 0xe8, 0x8,  0xe,  0x0,  0xe0, 0x80, 0xce, 0x88,
  0x8e, 0x2,  0xe,  0x0,  0xe0, 0x80, 0xae, 0xa8, 0xee, 0x2,  0xe,  0x0,
  0xe0, 0xa0, 0xee, 0xc8, 0xae, 0x2,  0xe,  0x0,  0xa0, 0xa0, 0xae, 0xa8,
  0xee, 0x2,  0xe,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x0,  0x18, 0x0,  0x66, 0x66, 0x66, 0x0,
  0x0,  0x0,  0x0,  0x0,  0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x0,
  0x18, 0x3e, 0x60, 0x3c, 0x6,  0x7c, 0x18, 0x0,  0x0,  0xc6, 0xcc, 0x18,
  0x30, 0x66, 0xc6, 0x0,  0x38, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0x76, 0x0,
  0x18, 0x18, 0x30, 0x0,  0x0,  0x0,  0x0,  0x0,  0xc,  0x18, 0x30, 0x30,
  0x30, 0x18, 0xc,  0x0,  0x30, 0x18, 0xc,  0xc,  0xc,  0x18, 0x30, 0x0,
  0x0,  0x66, 0x3c, 0xff, 0x3c, 0x66, 0x0,  0x0,  0x0,  0x18, 0x18, 0x7e,
  0x18, 0x18, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x18, 0x18, 0x30,
  0x0,  0x0,  0x0,  0x7e, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
  0x0,  0x18, 0x18, 0x0,  0x3,  0x6,  0xc,  0x18, 0x30, 0x60, 0xc0, 0x0,
  0x3c, 0x66, 0x6e, 0x76, 0x66, 0x66, 0x3c, 0x0,  0x18, 0x38, 0x18, 0x18,
  0x18, 0x18, 0x7e, 0x0,  0x3c, 0x66, 0xc,  0x18, 0x30, 0x60, 0x7e, 0x0,
  0x3c, 0x66, 0x6,  0x1c, 0x6,  0x66, 0x3c, 0x0,  0x1c, 0x3c, 0x6c, 0xcc,
  0xfe, 0xc,  0xc,  0x0,  0x7e, 0x60, 0x7c, 0x6,  0x6,  0x66, 0x3c, 0x0,
  0x1c, 0x30, 0x60, 0x7c, 0x66, 0x66, 0x3c, 0x0,  0x7e, 0x6,  0x6,  0xc,
  0x18, 0x18, 0x18, 0x0,  0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x0,
  0x3c, 0x66, 0x66, 0x3e, 0x6,  0xc,  0x38, 0x0,  0x0,  0x18, 0x18, 0x0,
  0x0,  0x18, 0x18, 0x0,  0x0,  0x18, 0x18, 0x0,  0x0,  0x18, 0x18, 0x30,
  0xc,  0x18, 0x30, 0x60, 0x30, 0x18, 0xc,  0x0,  0x0,  0x0,  0x7e, 0x0,
  0x7e, 0x0,  0x0,  0x0,  0x60, 0x30, 0x18, 0xc,  0x18, 0x30, 0x60, 0x0,
  0x3c, 0x66, 0x6,  0xc,  0x18, 0x0,  0x18, 0x0,  0x7c, 0xc6, 0xde, 0xde,
  0xde, 0xc0, 0x7c, 0x0,  0x18, 0x3c, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x0,
  0x7c, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x7c, 0x0,  0x3c, 0x66, 0x60, 0x60,
  0x60, 0x66, 0x3c, 0x0,  0x78, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0x78, 0x0,
  0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x7e, 0x0,  0x7e, 0x60, 0x60, 0x7c,
  0x60, 0x60, 0x60, 0x0,  0x3c, 0x66, 0x60, 0x6e, 0x66, 0x66, 0x3e, 0x0,
  0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x0,  0x7e, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x7e, 0x0,  0x6,  0x6,  0x6,  0x6,  0x6,  0x66, 0x3c, 0x0,
  0xc6, 0xcc, 0xd8, 0xf0, 0xd8, 0xcc, 0xc6, 0x0,  0x60, 0x60, 0x60, 0x60,
  0x60, 0x60, 0x7e, 0x0,  0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x0,
  0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x0,  0x3c, 0x66, 0x66, 0x66,
  0x66, 0x66, 0x3c, 0x0,  0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0x0,
  0x3c, 0x66, 0x66, 0x66, 0x66, 0x6c, 0x36, 0x0,  0x7c, 0x66, 0x66, 0x7c,
  0x6c, 0x66, 0x66, 0x0,  0x3c, 0x66, 0x60, 0x3c, 0x6,  0x66, 0x3c, 0x0,
  0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0,  0x66, 0x66, 0x66, 0x66,
  0x66, 0x66, 0x3c, 0x0,  0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x0,
  0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x0,  0xc3, 0x66, 0x3c, 0x18,
  0x3c, 0x66, 0xc3, 0x0,  0xc3, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x0,
  0x7e, 0x6,  0xc,  0x18, 0x30, 0x60, 0x7e, 0x0,  0x3c, 0x30, 0x30, 0x30,
  0x30, 0x30, 0x3c, 0x0,  0xc0, 0x60, 0x30, 0x18, 0xc,  0x6,  0x3,  0x0,
  0x3c, 0xc,  0xc,  0xc,  0xc,  0xc,  0x3c, 0x0,  0x10, 0x38, 0x6c, 0xc6,
  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,
  0x18, 0xc,  0x6,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3c, 0x6,
  0x3e, 0x66, 0x3e, 0x0,  0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x7c, 0x0,
  0x0,  0x0,  0x3c, 0x60, 0x60, 0x60, 0x3c, 0x0,  0x6,  0x6,  0x3e, 0x66,
  0x66, 0x66, 0x3e, 0x0,  0x0,  0x0,  0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x0,
  0x1c, 0x30, 0x7c, 0x30, 0x30, 0x30, 0x30, 0x0,  0x0,  0x0,  0x3e, 0x66,
  0x66, 0x3e, 0x6,  0x7c, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x0,
  0x18, 0x0,  0x38, 0x18, 0x18, 0x18, 0x1e, 0x0,  0xc,  0x0,  0xc,  0xc,
  0xc,  0xc,  0xc,  0x78, 0x60, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0x0,
  0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1e, 0x0,  0x0,  0x0,  0xcc, 0xfe,
  0xd6, 0xd6, 0xc6, 0x0,  0x0,  0x0,  0x7c, 0x66, 0x66, 0x66, 0x66, 0x0,
  0x0,  0x0,  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x0,  0x0,  0x0,  0x7c, 0x66,
  0x66, 0x7c, 0x60, 0x60, 0x0,  0x0,  0x3e, 0x66, 0x66, 0x3e, 0x6,  0x6,
  0x0,  0x0,  0x7c, 0x66, 0x60, 0x60, 0x60, 0x0,  0x0,  0x0,  0x3e, 0x60,
  0x3c, 0x6,  0x7c, 0x0,  0x30, 0x30, 0x7e, 0x30, 0x30, 0x30, 0x1e, 0x0,
  0x0,  0x0,  0x66, 0x66, 0x66, 0x66, 0x3e, 0x0,  0x0,  0x0,  0x66, 0x66,
  0x66, 0x3c, 0x18, 0x0,  0x0,  0x0,  0xc6, 0xc6, 0xd6, 0x7c, 0x6c, 0x0,
  0x0,  0x0,  0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x0,  0x0,  0x0,  0x66, 0x66,
  0x66, 0x3e, 0x6,  0x3c, 0x0,  0x0,  0x7e, 0xc,  0x18, 0x30, 0x7e, 0x0,
  0xe,  0x18, 0x18, 0x70, 0x18, 0x18, 0xe,  0x0,  0x18, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x0,  0x70, 0x18, 0x18, 0xe,  0x18, 0x18, 0x70, 0x0,
  0x76, 0xdc, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xc0, 0xa0, 0xae, 0xa4,
  0xc4, 0x4,  0x4,  0x0,  0xe0, 0xa0, 0xee, 0xaa, 0xea, 0xa,  0xe,  0x0,
  0xe0, 0xa0, 0xe4, 0xac, 0xe4, 0x4,  0xe,  0x0,  0xe0, 0xa0, 0xee, 0xa2,
  0xee, 0x8,  0xe,  0x0,  0xe0, 0xa0, 0xee, 0xa2, 0xee, 0x2,  0xe,  0x0,
  0xe0, 0x40, 0x4e, 0x4a, 0xea, 0xa,  0xa,  0x0,  0xe0, 0xa0, 0xa8, 0xa8,
  0xa8, 0x8,  0xe,  0x0,  0xe0, 0x80, 0xee, 0x28, 0xee, 0x2,  0xe,  0x0,
  0xe0, 0x80, 0xce, 0x88, 0xee, 0x2,  0xe,  0x0,  0xa0, 0xa0, 0xee, 0xa8,
  0xae, 0x2,  0xe,  0x0,  0xa0, 0xa0, 0xe2, 0xa2, 0xa2, 0xa,  0xe,  0x0,
  0xa0, 0xa0, 0xae, 0xa8, 0x4e, 0x2,  0xe,  0x0,  0xe0, 0xa0, 0xec, 0x8a,
  0x8a, 0xa,  0xc,  0x0,  0xe0, 0xa0, 0xea, 0x8a, 0x8a, 0xa,  0xe,  0x0,
  0xc0, 0xa0, 0xce, 0xa4, 0xa4, 0x4,  0xe,  0x0,  0xe0, 0x80, 0xee, 0x22,
  0xee, 0x8,  0xe,  0x0,  0xe0, 0x80, 0xee, 0x22, 0xe6, 0x2,  0xe,  0x0,
  0xc0, 0xa0, 0xae, 0xa8, 0xc8, 0x8,  0xe,  0x0,  0xe0, 0xa0, 0xe4, 0x8c,
  0x84, 0x4,  0xe,  0x0,  0xe0, 0xa0, 0xee, 0x82, 0x8e, 0x8,  0xe,  0x0,
  0xe0, 0x80, 0xee, 0x28, 0xec, 0x8,  0xe,  0x0,  0xe0, 0x80, 0x8e, 0x88,
  0xe8, 0x8,  0xe,  0x0,  0xa0, 0xe0, 0xea, 0xaa, 0xae, 0xe,  0xa,  0x0,
  0xe0, 0x80, 0xee, 0x2a, 0xee, 0x8,  0x8,  0x0,  0xe0, 0x80, 0xce, 0x8a,
  0xee, 0x8,  0x8,  0x0,  0xe0, 0xa0, 0xee, 0x2a, 0xee, 0xa,  0xe,  0x0,
  0xe0, 0xa0, 0xee, 0x2a, 0xee, 0x2,  0xe,  0x0,  0xe0, 0xa0, 0xee, 0x2a,
  0xee, 0xa,  0xa,  0x0,  0xe0, 0x80, 0x8e, 0x88, 0xee, 0x2,  0xe,  0x0,
  0xe0, 0x80, 0xee, 0x24, 0xe4, 0x4,  0x4,  0x0,  0xe0, 0xa0, 0xae, 0xa8,
  0xee, 0x2,  0xe,  0x0,  0xe0, 0xa0, 0xea, 0x8e, 0x8e, 0xa,  0xa,  0x0,
  0xe0, 0xa0, 0xee, 0xaa, 0xae, 0x8,  0x8,  0x0,  0x0,  0x0,  0x0,  0x0,
  0x0,  0x0,  0x0,  0x0,  0x18, 0x0,  0x18, 0x18, 0x18, 0x18, 0x18, 0x0,
  0x0,  0x18, 0x7e, 0xd8, 0xd8, 0x7e, 0x18, 0x0,  0x38, 0x6c, 0x60, 0xf0,
  0x60, 0x66, 0xfc, 0x0,  0x66, 0x3c, 0x66, 0x3c, 0x66, 0x0,  0x0,  0x0,
  0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x18, 0x18, 0x0,  0x18, 0x18, 0x18, 0x0,
  0x18, 0x18, 0x18, 0x0,  0x3c, 0x60, 0x3c, 0x66, 0x66, 0x3c, 0x6,  0x3c,
  0x66, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7e, 0x81, 0x9d, 0xb1,
  0xb1, 0x9d, 0x81, 0x7e, 0x3c, 0x6c, 0x6c, 0x3e, 0x0,  0x7e, 0x0,  0x0,
  0x0,  0x33, 0x66, 0xcc, 0x66, 0x33, 0x0,  0x0,  0x0,  0x7e, 0x6,  0x6,
  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3c, 0x0,  0x0,  0x0,  0x0,
  0x7e, 0x81, 0xb9, 0xa5, 0xb9, 0xa5, 0x81, 0x7e, 0x7e, 0x0,  0x0,  0x0,
  0x0,  0x0,  0x0,  0x0,  0x3c, 0x66, 0x3c, 0x0,  0x0,  0x0,  0x0,  0x0,
  0x18, 0x18, 0x7e, 0x18, 0x18, 0x0,  0x7e, 0x0,  0x70, 0x18, 0x30, 0x60,
  0x78, 0x0,  0x0,  0x0,  0x78, 0xc,  0x18, 0xc,  0x78, 0x0,  0x0,  0x0,
  0xc,  0x18, 0x30, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x66, 0x66,
  0x66, 0x7c, 0x60, 0xc0, 0x3e, 0x7a, 0x7a, 0x3a, 0x1a, 0x1a, 0x1a, 0x0,
  0x0,  0x0,  0x0,  0x18, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
  0x0,  0x0,  0x8,  0x18, 0x30, 0x70, 0x30, 0x30, 0x30, 0x0,  0x0,  0x0,
  0x38, 0x6c, 0x6c, 0x38, 0x0,  0x7c, 0x0,  0x0,  0x0,  0xcc, 0x66, 0x33,
  0x66, 0xcc, 0x0,  0x0,  0x40, 0xc6, 0x4c, 0x5a, 0x36, 0x6a, 0xcf, 0x2,
  0x40, 0xc6, 0x4c, 0x5e, 0x33, 0x66, 0xcc, 0xf,  0xc0, 0x26, 0x6c, 0x3a,
  0xf6, 0x6a, 0xcf, 0x2,  0x18, 0x0,  0x18, 0x30, 0x60, 0x66, 0x3c, 0x0,
  0x70, 0x0,  0x3c, 0x66, 0x7e, 0x66, 0x66, 0x0,  0xe,  0x0,  0x3c, 0x66,
  0x7e, 0x66, 0x66, 0x0,  0x18, 0x66, 0x0,  0x3c, 0x66, 0x7e, 0x66, 0x0,
  0x76, 0xdc, 0x0,  0x3c, 0x66, 0x7e, 0x66, 0x0,  0x66, 0x0,  0x3c, 0x66,
  0x7e, 0x66, 0x66, 0x0,  0x18, 0x18, 0x0,  0x3c, 0x66, 0x7e, 0x66, 0x0,
  0x3f, 0x6c, 0xcc, 0xfe, 0xcc, 0xcc, 0xcf, 0x0,  0x3c, 0x66, 0x60, 0x60,
  0x60, 0x66, 0x3c, 0x18, 0x70, 0x0,  0xfe, 0xc0, 0xf8, 0xc0, 0xfe, 0x0,
  0xe,  0x0,  0xfe, 0xc0, 0xf8, 0xc0, 0xfe, 0x0,  0x18, 0x66, 0x0,  0xfe,
  0xf0, 0xc0, 0xfe, 0x0,  0x66, 0x0,  0xfe, 0xc0, 0xf8, 0xc0, 0xfe, 0x0,
  0x70, 0x0,  0x7e, 0x18, 0x18, 0x18, 0x7e, 0x0,  0xe,  0x0,  0x7e, 0x18,
  0x18, 0x18, 0x7e, 0x0,  0x18, 0x66, 0x0,  0x7e, 0x18, 0x18, 0x7e, 0x0,
  0x66, 0x0,  0x7e, 0x18, 0x18, 0x18, 0x7e, 0x0,  0x78, 0x6c, 0x66, 0xf6,
  0x66, 0x6c, 0x78, 0x0,  0x76, 0xdc, 0x0,  0xc6, 0xf6, 0xde, 0xc6, 0x0,
  0x70, 0x0,  0x7c, 0xc6, 0xc6, 0xc6, 0x7c, 0x0,  0xe,  0x0,  0x7c, 0xc6,
  0xc6, 0xc6, 0x7c, 0x0,  0x18, 0x66, 0x0,  0x7c, 0xc6, 0xc6, 0x7c, 0x0,
  0x76, 0xdc, 0x0,  0x7c, 0xc6, 0xc6, 0x7c, 0x0,  0x66, 0x0,  0x7c, 0xc6,
  0xc6, 0xc6, 0x7c, 0x0,  0x0,  0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x0,  0x0,
  0x3e, 0x66, 0x6e, 0x7e, 0x76, 0x66, 0x7c, 0x0,  0x70, 0x0,  0xc6, 0xc6,
  0xc6, 0xc6, 0x7c, 0x0,  0xe,  0x0,  0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x0,
  0x18, 0x66, 0x0,  0xc6, 0xc6, 0xc6, 0x7c, 0x0,  0x66, 0x0,  0xc6, 0xc6,
  0xc6, 0xc6, 0x7c, 0x0,  0xe,  0x0,  0x66, 0x66, 0x3c, 0x18, 0x18, 0x0,
  0xc0, 0xc0, 0xfc, 0xc6, 0xfc, 0xc0, 0xc0, 0x0,  0x3c, 0x66, 0x66, 0x6c,
  0x66, 0x66, 0x6c, 0x0,  0x70, 0x0,  0x3c, 0x6,  0x3e, 0x66, 0x3e, 0x0,
  0xe,  0x0,  0x3c, 0x6,  0x3e, 0x66, 0x3e, 0x0,  0x18, 0x66, 0x0,  0x3e,
  0x66, 0xc6, 0x7e, 0x0,  0x76, 0xdc, 0x0,  0x3e, 0x66, 0xc6, 0x7e, 0x0,
  0x66, 0x0,  0x3c, 0x6,  0x3e, 0x66, 0x3e, 0x0,  0x18, 0x18, 0x0,  0x3e,
  0x66, 0xc6, 0x7e, 0x0,  0x0,  0x0,  0x7e, 0x1b, 0x7f, 0xd8, 0x77, 0x0,
  0x0,  0x0,  0x3c, 0x60, 0x60, 0x60, 0x3c, 0x18, 0x70, 0x0,  0x3c, 0x66,
  0x7e, 0x60, 0x3c, 0x0,  0xe,  0x0,  0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x0,
  0x18, 0x66, 0x0,  0x3c, 0x7e, 0x60, 0x3c, 0x0,  0x66, 0x0,  0x3c, 0x66,
  0x7e, 0x60, 0x3c, 0x0,  0x70, 0x0,  0x38, 0x18, 0x18, 0x18, 0x3c, 0x0,
  0xe,  0x0,  0x38, 0x18, 0x18, 0x18, 0x3c, 0x0,  0x18, 0x66, 0x0,  0x38,
  0x18, 0x18, 0x3c, 0x0,  0x66, 0x0,  0x38, 0x18, 0x18, 0x18, 0x3c, 0x0,
  0xc,  0x3e, 0xc,  0x7c, 0xcc, 0xcc, 0x78, 0x0,  0x76, 0xdc, 0x0,  0x7c,
  0x66, 0x66, 0x66, 0x0,  0x70, 0x0,  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x0,
  0xe,  0x0,  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x0,  0x18, 0x66, 0x0,  0x3c,
  0x66, 0x66, 0x3c, 0x0,  0x76, 0xdc, 0x0,  0x3c, 0x66, 0x66, 0x3c, 0x0,
  0x66, 0x0,  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x0,  0x18, 0x18, 0x0,  0x7e,
  0x0,  0x18, 0x18, 0x0,  0x0,  0x2,  0x7c, 0xce, 0xd6, 0xe6, 0x7c, 0x80,
  0x70, 0x0,  0x66, 0x66, 0x66, 0x66, 0x3e, 0x0,  0xe,  0x0,  0x66, 0x66,
  0x66, 0x66, 0x3e, 0x0,  0x18, 0x66, 0x0,  0x66, 0x66, 0x66, 0x3e, 0x0,
  0x66, 0x0,  0x66, 0x66, 0x66, 0x66, 0x3e, 0x0,  0xe,  0x0,  0x66, 0x66,
  0x66, 0x3e, 0x6,  0x3c, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60,
  0x66, 0x0,  0x66, 0x66, 0x66, 0x3e, 0x6,  0x3c
};

#endif // DBGP_DBGP_UNSCII8_H
