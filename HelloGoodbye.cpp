#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  // Print "Sup" with the names in the order of the arguments
  for (int i = 1; i < argc; i++) {
    // cout << argv[1] << endl;
    cout << "Sup, " << argv[i] << "!" << endl;
  }

  // Print "Peace fam" with the names in reverse order
  for (int i = argc - 1; i >= 1; i--) {
    cout << "Peace fam, " << argv[i] << "!" << endl;
  }

  return 0;

//   // Check the number of command-line arguments
//   if (argc != 3) {
//     cout << "Please enter exactly two names." << endl;
//     return 1;
//   }

//   // Print "Hello" with the first name
//   cout << "Hello, " << argv[1] << " and " << argv[2] << "!" << endl;

//   // Print "Goodbye" with the names in reverse order
//   cout << "Goodbye, " << argv[2] << " and " << argv[1] << "!" << endl;

//   return 0;

}

//Notes 
//the first argument (argv[0]) is the name of the program itself. Therefore, we start the loop from i = 1 to process only the arguments containing the names.