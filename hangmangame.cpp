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
        displayWord(word, guesses);  // Display the current state of the word
        cout << "Incorrect attempts left: " << (maxAttempts - incorrectAttempts) << endl;

        char guess; // Variable to hold the player's guess
        cout << "Guess a letter: ";
        cin >> guess; // Read the player's guess
        guess = tolower(guess); // Convert to lowercase for consistency

        // Check if the letter has already been guessed
        if (find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guesses.push_back(guess); // Add guesses to a list

        // Check if guess is correct
        if (word.find(guess) == string::npos) {
            incorrectAttempts++;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Good guess!" << endl;
        }

        // Check if correct word was guessed
        if (isWordGuessed(word, guesses)) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    // Check if attempts ran out
    if (incorrectAttempts == maxAttempts) {
        cout << "Game over! The word was: " << word << endl;
    }

    return 0;
}
