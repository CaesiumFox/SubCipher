project('SubCipher', 'cpp', default_options: [ 'cppstd=c++23' ])

include_dir = include_directories('include')

sources = []

cxxopts_dep = dependency('cxxopts', required: true)

subdir('src/')

executable(
    'subc',
    sources,
    include_directories:
        include_dir,
    dependencies: [
        cxxopts_dep
    ]
)
