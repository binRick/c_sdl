sdl_app_srcs = [
  'sdl-app.c',
]
sdl_app_inc = [
 inc,
 '.',
 '../sdl-app',
]
sdl_app_deps = [
  sdl_app_fonts_dep,
  sdl2_dep,
]

sdl_app_lib = library('sdl-app',
  sdl_app_srcs,
  install: false,
  dependencies: sdl_app_deps,
  include_directories: [
    sdl_app_inc,
  ],
)

sdl_app_dep = declare_dependency(
  include_directories: sdl_app_inc,
  link_with: sdl_app_lib,
)
