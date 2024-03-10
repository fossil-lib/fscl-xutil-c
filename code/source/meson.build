cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

code = files(
    'command.c',    'lavalamp.c',
    'filesystem.c', 'arguments.c',
    'bitwise.c')

lib = static_library('fscl-xutil-c',
    code,
    dependencies: m_dep,
    include_directories: dir)

fscl_xutil_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
