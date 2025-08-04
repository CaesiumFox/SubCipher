#include "CipherBase.hpp"

using namespace sub_cipher;

CipherBase::CipherBase(const Alphabet& alphabet):
    alphabet(alphabet)
{}

const Alphabet& CipherBase::get_alphabet() const {
    return alphabet;
}
