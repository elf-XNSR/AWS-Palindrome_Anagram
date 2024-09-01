#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

#include "Palindrome.hpp"

CPalindrome* doesAnagramExist(CPalindrome* checkPalindrome, std::vector<CPalindrome*>& vecPalindromes){
    for (CPalindrome* palindrome : vecPalindromes){
        if (palindrome->getPalindrome() == checkPalindrome->getPalindrome()){
            continue;
        }
        if (palindrome->isEqual(checkPalindrome)){
            return palindrome;
        }
    }
    return nullptr;
}

int main(int argc, char *argv[]){
    std::ifstream inputFile("input.txt");
    std::string curLine{};

    std::vector<CPalindrome*> palindromes{};

    //  Push all lines from input.txt into palindromes vector.
    while(std::getline(inputFile, curLine)){
        palindromes.push_back(new CPalindrome(curLine));
    }

    std::string findMe = argv[argc - 1];
    CPalindrome findPalindrome{findMe};
    CPalindrome* palindrome = doesAnagramExist(&findPalindrome, palindromes);

    if (palindrome){
        //  we found it.
        std::cout << "Anagram Found \nOriginal:  " << findMe << "\nFound:  " << palindrome->getPalindrome() << std::endl;
    }
    else{
        std::cout << "Anagram not found." << std::endl;
    }



    return 1;
}
