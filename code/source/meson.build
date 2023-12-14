cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

code = files(
    'command.c', 'errors.c',
    'money.c',   'number.c',
    'parser.c',  'random.c',
    'directory.c')

lib = static_library('tscl-xutil-c',
    code,
    link_with: m_lib,
    include_directories: dir)

tscl_xutil_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
