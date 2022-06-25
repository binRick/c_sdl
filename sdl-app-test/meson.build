sdl_app_test_test_srcs = [
  'sdl-app-test.c',
]
sdl_app_test_test_inc = [
 '.',
 '../sdl-app-test',
 inc,
]
sdl_app_test_test_deps = [
 sdl2_dep,
 sdl_app_dep,
]

if get_option('enable-binaries')
  sdl_app_test_test_exec = executable('sdl_app_test-test', 
     sdl_app_test_test_srcs,
     dependencies: sdl_app_test_test_deps,
     include_directories: sdl_app_test_test_inc,
  )
  if get_option('enable-binary-tests')
    #    test('sdl_app_test-test', timeout_bin, args:['5', '--preserve-status',sdl_app_test_test_exec, '-v','-a'])
  endif
endif
