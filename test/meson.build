tst_alphabet = executable(
    'alphabet',
    files(['Alphabet.cpp']) + lib_sources,
    include_directories: include_dir
)

tst_character = executable(
    'character',
    files(['Character.cpp']) + lib_sources,
    include_directories: include_dir
)

test('Alphabet test', tst_alphabet)
test('Character test', tst_character)
