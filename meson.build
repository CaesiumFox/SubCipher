project('SubCipher', 'cpp', default_options: [ 'cppstd=c++23' ])

include_dir = include_directories('include')

lib_sources = []
app_sources = []

subdir('src/')
subdir('test/')

cxxopts_dep = dependency('cxxopts', required: true)

executable(
    'subc',
    lib_sources + app_sources,
    include_directories:
        include_dir,
    dependencies: [
        cxxopts_dep
    ]
)
