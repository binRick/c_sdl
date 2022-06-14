project('c_sdl',['c'],default_options:['warning_level=0','c_std=gnu99'])
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
meson_deps_dir = meson.current_source_dir()
#############################################################
inc = [
  include_directories('.'),
  include_directories('./sdl-app'),
  include_directories('./sdl-app-fonts'),
]
sdl2_dep = dependency('sdl2',fallback:['sdl2', 'sdl2'], required: true)

subdir('sdl-app-fonts')
subdir('sdl-app')
subdir('sdl-app-test')
