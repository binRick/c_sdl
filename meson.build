project('c_sdl',['c'],default_options:['warning_level=0','c_std=gnu99'],
  subproject_dir: 'submodules/meson_deps/subprojects',
  )
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
meson_deps_dir = join_paths(meson.current_source_dir(),'submodules/meson_deps')
subdir('meson')
#############################################################
inc = [
  include_directories('.'),
  include_directories('./sdl-app'),
  include_directories('./sdl-app-fonts'),
  include_directories(
    './submodules/meson_deps',
    './submodules/meson_deps/submodules',
    './submodules/meson_deps/submodules/c_stringfn/include',
    './submodules/meson_deps/submodules/dbg',
    './submodules/meson_deps/submodules/generic-print',
    './submodules/meson_deps/submodules/str-replace.c/src',
    './submodules/meson_deps/submodules/c_ansi',
    './submodules/meson_deps/submodules/progressbar/include',
    './submodules/meson_deps/submodules/progressbar/include/progressbar',
    './submodules/meson_deps/submodules/list/src',
    './submodules/meson_deps/submodules/c_darwin/app-utils',
    ),
]
sdl2_dep = dependency('sdl2',fallback:['sdl2', 'sdl2'], required: true)

subdir('submodules')
subdir('sdl-app-fonts')
subdir('sdl-app')
subdir('sdl-app-test')
subdir('sdl-term-app-test')
