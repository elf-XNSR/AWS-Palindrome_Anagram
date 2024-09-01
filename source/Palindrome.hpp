#pragma once
#include <array>
#include <string>

class CPalindrome{
public:
    CPalindrome(std::string& string);

    bool isEqual(CPalindrome* comparePalindrome) const;

    std::string getPalindrome() const{
        return this->m_Palindrome;
    };

    std::array<int, 25> getArray() const{
        return this->m_charArray;
    }
private:
    int mapCharToIndex(const char character) const;
    bool validateChar(const char character) const;
    void addCharToArray(const char character);

    std::array<int, 25> m_charArray{};
    std::string m_Palindrome{};
};
