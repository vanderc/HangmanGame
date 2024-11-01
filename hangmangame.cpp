#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void displayWord(const string &word, const vector<char> &guesses) {
    for (char letter : word) {
        if (find(guesses.begin(), guesses.end(), letter) != guesses.end()) {
            cout << letter << ' ';
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string &word, const vector<char> &guesses) {
    for (char letter : word) {
        if (find(guesses.begin(), guesses.end(), letter) == guesses.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string word = "hangman"; // The word to guess
    vector<char> guesses;     // Store guessed letters
    int maxAttempts = 6;      // Max number of incorrect guesses
    int incorrectAttempts = 0;

    cout << "Welcome to Hangman!" << endl;

    while (incorrectAttempts < maxAttempts) {
        cout << "\nCurrent word: ";
        displayWord(word, guesses);
        cout << "Incorrect attempts left: " << (maxAttempts - incorrectAttempts) << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        guess = tolower(guess); // Convert to lowercase for consistency

        if (find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guesses.push_back(guess);

        if (word.find(guess) == string::npos) {
            incorrectAttempts++;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Good guess!" << endl;
        }

        if (isWordGuessed(word, guesses)) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (incorrectAttempts == maxAttempts) {
        cout << "Game over! The word was: " << word << endl;
    }

    return 0;
}
