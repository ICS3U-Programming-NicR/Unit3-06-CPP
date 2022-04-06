// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on: March 29 2022
// This program makes a random number game

#include <stdlib.h>
#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::string;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main() {
    int randomNum, biggestNum, usersNum;
    string biggestNumStr, usersNumStr;
    cout<< GREEN << "Enter the largest number to be generated: ";
    cin >> biggestNumStr;
    // get the guess from the user as a string
    try {
        // convert the user's guess to an int
        biggestNum = std::stoi(biggestNumStr);
        // check if the guess is correct
    } catch (std::invalid_argument) {
    // The user did not enter an integer.
    cout << biggestNumStr << " is not an integer.\n";
    main();
    }
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, biggestNum);
    randomNum = idist(rgen);

    while (true) {
        cout << "Guess a number between 1 and " << biggestNum << ": ";
        cin >> usersNumStr;
        try {
            // convert the user's guess to an int
            usersNum = std::stoi(usersNumStr);
            // check if the guess is correct
        } catch (std::invalid_argument) {
            // The user did not enter an integer.
            cout << usersNumStr << " is not an integer.\n";
            main();
        }
        if (randomNum < usersNum) {
            cout << "The secret number is lower\n";
        } else if (randomNum > usersNum) {
            cout << "The secret number is higher\n";
        } else {
            cout << "You guessed the right number!\n";
        break;
        }
  }
    string tryAgain;
    cout << "would you like to try again? ";
    cin >> tryAgain;
    if (tryAgain == "y"
        || tryAgain == "Y"
        || tryAgain == "yes"
        || tryAgain == "YES") {
        main();
    } else if (tryAgain == "n"
        || tryAgain == "N"
        || tryAgain == "no"
        || tryAgain == "NO") {
        exit(1);
    }
}
