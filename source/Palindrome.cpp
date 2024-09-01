#include "Palindrome.hpp"

CPalindrome::CPalindrome(std::string& string){
    this->m_Palindrome = string;
    for (const char character : string){
        if (!validateChar(character)){
            break;
        }
        addCharToArray(character);
    }
}

bool CPalindrome::isEqual(CPalindrome* comparePalindrome) const{
    for (int nIndex = 0; nIndex < this->m_charArray.size(); nIndex++){
        if (this->m_charArray[nIndex] != comparePalindrome->getArray()[nIndex]){
            return false;
        }
    }
    return true;
    //return std::equal(this->getArray().begin(), this->getArray().end(), comparePalindrome->getArray().begin());
}

bool CPalindrome::validateChar(const char character) const{
    return ((int)character >= (int)'a' && (int)character <= 'z');
}

//  works for lowercase a-z
int CPalindrome::mapCharToIndex(const char character) const{
    return (int)character - (int)'a';
}

//  increases appropriate count in array
void CPalindrome::addCharToArray(const char character){
    this->m_charArray[this->mapCharToIndex(character)]++;
}
