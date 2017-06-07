{
  'targets': [
    {
      'target_name': 'cacheLineSize',
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      'sources': [ 'src/binding.cc' ],
      'xcode_settings': {
              'OTHER_CPLUSPLUSFLAGS': [
                '-std=c++11'
              ],
              'OTHER_LDFLAGS': [],
              'GCC_ENABLE_CPP_EXCEPTIONS': 'NO',
              'MACOSX_DEPLOYMENT_TARGET': '10.7'
            },
      'conditions': [
        ['OS!="win"', {
                  'cflags_cc+': [
                    '-std=c++0x'
                  ]
                }]

      ]
    }
  ]
}