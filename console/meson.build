console_srcs = [
  'console.c',
]

inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))

console_include_dirs = [
  '.',
  inc,
]

console_deps = [
  ansi_codes_dep,
  c_vector_dep,
  incbin_dep,
  tempdir_dep,
  c_fsio_dep,
  c_stringfn_dep,
  c_string_buffer_dep,
  timestamp_dep,
  tmt_dep,
  sdl2_dep,
  sdl2_ttf_dep,
  sdl2_image_dep,
  log_dep,
  ms_dep,
  bytes_dep,
]

console_c_args = [
]

console_link_args = [
]

console_lib = library('console',
  console_srcs,
  install: false,
  dependencies: console_deps,
  c_args: console_c_args,
  include_directories: console_include_dirs
)

console_dep = declare_dependency(
  include_directories: console_include_dirs,
  link_with: console_lib,
  link_args: console_link_args,
)
