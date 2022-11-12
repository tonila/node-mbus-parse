{
    'targets': [
        {
            "target_name": "mbus",
            'cflags': [
                '-w'
            ],
            "sources": [ "./src/mbus-parse.cc" ],
            'include_dirs': [
                './libmbus/mbus',
                "<!(node -e \"require('nan')\")"
            ],
            'dependencies': [
                'libmbus'
            ]
        },
        {
            'target_name': 'libmbus',
            'type': 'static_library',
            'cflags': [
                '-w'
            ],
            'include_dirs': [
                './libmbus/mbus',
            ],
            'sources': [
                './libmbus/mbus/mbus-protocol-aux.c',
                './libmbus/mbus/mbus-protocol.c',
                './libmbus/mbus/mbus-serial.c',
                './libmbus/mbus/mbus-tcp.c',
                './libmbus/mbus/mbus.c'
            ],
            'conditions': [
                ['OS=="mac"', {
                    'xcode_settings': {
                        'OTHER_CFLAGS': [
                            '-w'
                        ],
                    }
                }],
                ['OS=="win"', {
                'sources': [
                        './libmbus/win/termiWin.c'
                    ]
                }]
            ]
        }
    ]
}
