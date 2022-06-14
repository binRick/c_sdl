sdl_app_test_test_srcs = [
  'sdl-app-test.c',
]
sdl_app_test_test_inc = [
 inc,
 '../sdl-app-test',
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
    test('sdl_app_test-test', sdl_app_test_test_exec, args: [])
  endif
endif
