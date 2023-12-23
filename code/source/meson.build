code = files(
    'command.c',    'lavalamp.c',
    'filesystem.c', 'arguments.c',
    'sortable.c',   'searchable.c',
    'shuffle.c',    'ranges.c')

lib = static_library('tscl-xutil-c',
    code,
    include_directories: dir)

tscl_xutil_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
