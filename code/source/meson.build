cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

code = files(
    'command.c',    'lavalamp.c',
    'filesystem.c', 'arguments.c',
    'sortable.c',   'searchable.c',
    'shuffle.c',    'ranges.c',
    'platform.c',   'assume.c',)

lib = static_library('tscl-xutil-c',
    code,
    dependencies: m_dep,
    include_directories: dir)

tscl_xutil_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
