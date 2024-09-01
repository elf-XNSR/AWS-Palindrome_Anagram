import random

def createPalindrome(string):
    inverse = string [::-1]
    return (string + inverse)

def randomLetter():
    return chr(random.randint(ord('a'), ord('z')))

#   https://stackoverflow.com/questions/6181304/are-there-any-ways-to-scramble-strings-in-python/6181343#6181343
def randomiseWord(string):
    word = list(string)
    random.shuffle(word)
    return ''.join(word)

def main():
    inputFile = open("input.txt", "w")
    #   create a random amount of pairs
    for i in range(0, random.randint(10, 100)):
        #   create palindromes with a random amount of letters
        string = ""
        for n in range(0, random.randint(25, 50)):
            string += randomLetter()
        inputFile.write(createPalindrome(string) + "\n")
        inputFile.write(createPalindrome(randomiseWord(string)) + "\n")
    inputFile.close()

main()
