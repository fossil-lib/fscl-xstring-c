code = files(
    'cstring.c', 'letter.c', 'wygstring.c',
    'cipher.c', 'nlp.c', 'number.c',
    'utility.c', 'skittles.c')

lib = static_library('fscl-xstring-c',
    code,
    include_directories: dir)

fscl_xstring_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
