#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

//If the user wants a random word selected from a text file, enter the filename
//If the user wants to select a random word from console, enter words and then ctrl-D

int main(int argc, char* argv[]) {
    std::vector<std::string> words;
    std::string word;

    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Check if a file name was specified as a command-line argument
    if (argc > 1) {
        // Open the file for reading
        std::ifstream file(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << argv[1] << std::endl;
            return 1;
        }

        // Read all words from the file and store them in a vector
        while (file >> word) {
            words.push_back(word);
        }

        // Close the file
        file.close();
    } else {
        // Read words from standard input and store them in a vector
        while (std::cin >> word) {
            words.push_back(word);
        }
    }

    // Choose a random word from the vector and print it
    if (words.size() > 0) {
        int index = std::rand() % words.size();
        std::cout << words[index] << std::endl;
    }

    return 0;
}

//Notes
//std::vector is typically implemented as a dynamic array rather than a linked list.
//A dynamic array is an array that can be resized during program execution, whereas a static array has a
//fixed size that is determined at compile time. A std::vector is a dynamic array that can grow or shrink in size as elements are added or removed.
//A dynamic array implementation typically uses a contiguous block of memory to store the elements of the array, which allows for efficient random 
//access to elements using an index. This is in contrast to a linked list, which stores elements in separate nodes that are linked together using pointers. 
//Random access to elements in a linked list is generally less efficient than with a dynamic array.