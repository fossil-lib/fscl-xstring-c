if get_option('with_demo').enabled()
    demo_apps = [
        'string', 'letter', 'cipher', 'wygstring']

    foreach iter : demo_apps
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [tscl_xstring_c_dep])
    endforeach
endif