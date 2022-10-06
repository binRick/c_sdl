sdl_app_fonts_srcs = [
  'sdl-app-fonts.c',
  'sdl-app-fonts-8.c',
  'sdl-app-fonts-16.c',
]
sdl_app_fonts_inc = [
 inc,
 '.',
 '../sdl-app-fonts',
]
sdl_app_fonts_deps = [
  sdl2_dep,
]


sdl_app_fonts_lib = library('sdl-app-fonts',
  sdl_app_fonts_srcs,
  install: false,
  dependencies: sdl_app_fonts_deps,
  include_directories: [
    sdl_app_fonts_inc,
  ],
)

sdl_app_fonts_dep = declare_dependency(
  include_directories: sdl_app_fonts_inc,
  link_with: sdl_app_fonts_lib,
)
