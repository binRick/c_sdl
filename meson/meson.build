mui_global_linkflags = ['-Wl,-framework,OpenGL']
add_project_link_arguments(mui_global_linkflags, language : ['c'])                                              

sdl2_dep = dependency('sdl2',fallback:['sdl2', 'sdl2'], required: true)

timeout_bin = find_program('timeout', required : true)
passh_program = find_program('passh', required : true)
