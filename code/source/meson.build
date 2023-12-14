code = files(
    'command.c', 'errors.c',
    'money.c',   'number.c',
    'parser.c',  'random.c',
    'directory.c')

lib = static_library('tscl-xutil-c',
    code,
    include_directories: dir)

tscl_xutil_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
