#include "stdafx.h"
#include <string>
#include <iostream>
using namespace System;
bool Guess(int number) {
     static int target = -1;
     if (target == -1) {
        Random r;
        target = r.Next() % 100 + 1;
     }
     if (number == target) {
        std::cout << "Correct !!";
        target = -1;
        return true;
        }
     else std::cout << "Wrong" << std::endl;
     return false;
}
<<<<<<< HEAD

int main(int argc, char const *argv[]) {
  int guess;
  do {
    cout << "Choose a number between 1 - 100 :";
    cin >> guess;
  } while (!Guess(guess));
  return 0;
=======
int main(array<System::String ^> ^args)
{
     int guess;
     do {
     std::cin >> guess;
     } while (!Guess(guess));
     return 0;
>>>>>>> b5cab6988706e2eb174c0e2892a32b447abe1d52
}
