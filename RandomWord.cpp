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
