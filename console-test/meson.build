console_test_srcs = [
  'console-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
console_test_include_dirs = [
  '.',
  inc,
]
console_test_deps = [
  c_greatest_dep,
  console_dep,
  ansi_codes_dep,
  c_vector_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  log_dep,
  ms_dep,
  bytes_dep,
]
console_test_c_args = [
]
console_test_link_args = [
]

console_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  console_test_exec = executable('console-test',
     console_test_srcs,
     dependencies: console_test_deps,
     include_directories: console_test_include_dirs,
     link_args: console_test_link_args,
     c_args: console_test_c_args,
     install: false,
  )
  #test('console-test', 
  #  console_test_exec, args: ['-v','-a'],
  #  workdir: console_test_test_dir,
  #)
endif
