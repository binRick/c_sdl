sdl_term_app_test_srcs = [
  'sdl-term-app-test.c',
  'sdl-term-app-test.h',
]
sdl_term_app_test_dirs = [
  '.',
  inc,
]
sdl_term_app_test_deps = [
 sdl2_dep,
 sdl_app_dep,
 sdl_app_fonts_dep,
 chan_dep,
 ansi_codes_dep,
 logh_dep,
 ms_dep,
 timestamp_dep,
 c_timer_dep,
 bytes_dep,  
 app_utils_dep,
 window_utils_dep,
 active_app_dep,
]

if get_option('enable-binaries')
    sdl_term_app_test_exec = executable('sdl-term-app-test',
     sdl_term_app_test_srcs,
     dependencies: sdl_term_app_test_deps,
     include_directories: sdl_term_app_test_dirs,
  )
  if get_option('enable-binary-tests')
    #    test('sdl-term-app-test', sdl_term_app_test_exec, args: [])
  endif
endif
