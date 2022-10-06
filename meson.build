project('c_sdl',['c'],default_options:['warning_level=0','c_std=gnu99','default_library=static'],
  subproject_dir: 'submodules/c_deps/subprojects',
  version: '0.0.1',
  )
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),'submodules/c_deps')
subdir('meson')
#############################################################
inc = [
  include_directories('.'),
  include_directories('./sdl-app'),
  include_directories('./sdl-app-fonts'),
  include_directories(
    './submodules/c_deps',
    './submodules/c_deps/submodules',
    './submodules/c_deps/submodules/c_stringfn/include',
    './submodules/c_deps/submodules/dbg',
    './submodules/c_deps/submodules/generic-print',
    './submodules/c_deps/submodules/str-replace.c/src',
    './submodules/c_deps/submodules/c_ansi',
    './submodules/c_deps/submodules/progressbar/include',
    './submodules/c_deps/submodules/progressbar/include/progressbar',
    './submodules/c_deps/submodules/list/src',
    './submodules/c_deps/submodules/iowow',
    './submodules/c_deps/submodules/iowow/src',
    './submodules/c_deps/submodules/iowow/src/fs',
    './submodules/c_deps/submodules/iowow/src/platform',
    './submodules/c_deps/submodules/iowow/src/kv',
    './submodules/c_deps/submodules/iowow/src/log',
    ),
]
sdl2_dep = dependency('sdl2',fallback:['sdl2', 'sdl2'], required: true)

subdir('submodules')
subdir('sdl-app-fonts')
subdir('sdl-app')
subdir('sdl-app-test')
subdir('sdl-term-app-test')
