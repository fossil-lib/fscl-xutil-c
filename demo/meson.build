if get_option('with_demo').enabled()
    demo_apps = [
        'command', 'errors', 'money', 'number',
        'parser',  'random', 'directory']

    foreach iter : demo_apps
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [tscl_xutil_c_dep])
    endforeach
endif