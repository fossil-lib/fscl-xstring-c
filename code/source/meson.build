code = files(
    'cstring.c', 'letter.c', 'wygstring.c',
    'cipher.c', 'nlp.c', 'number.c',
    'utility.c', 'color.c')

lib = static_library('tscl-xstring-c',
    code,
    include_directories: dir)

tscl_xstring_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
