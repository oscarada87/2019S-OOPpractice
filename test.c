#include <iostream>
using namespace std;

bool Guess(int number) {

}

int main(int argc, char const *argv[]) {
  int guess;
  do {
    cout << "Choose a number between 1 - 100 :";
    cin >> guess;
  } while (!Guess(guess));
  return 0;
}
