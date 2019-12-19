#include <iostream>
#include <string>

using namespace std;


/*
 * Declaration of functions
 * */
int menuSelection();

string base10ToRoman(int);

int romanToBase10(string);

void romanAddition();

string removeSubtractives(string);

string addSubtractives(string);

bool isValidRomanNumeral(string);

bool isValidBase10(int);

void romanToBase10InputOutput();

void base10ToRomanInputOutput();

string sortRomanNumeral(string);

string combineGroups(string);


int main() {
    menuSelection();
}

/*
 * This function prints the menu options in the terminal
 * This function presents the user with an error message upon out of bounds exception,
 *  then re-polls menu using recurrsion
 * */

int menuSelection() {
    int userMenuInput;
    cout << "Menu" << endl;
    cout << "1: Roman numeral to base 10" << endl;
    cout << "2: Base 10 to Roman numeral" << endl;
    cout << "3: Add 2 Roman numerals" << endl;
    cout << "4: Exit" << endl;
    cin >> userMenuInput;
    if (userMenuInput == 1) {
        romanToBase10InputOutput();
    } else if (userMenuInput == 2) {
        base10ToRomanInputOutput();
    } else if (userMenuInput == 3) {
        romanAddition();
    } else if (userMenuInput == 4) {
        cout << "\nExiting Program" << endl;
        return 0;
    } else if (userMenuInput > 5 || userMenuInput < 0) {
        cout << "\nInvalid entry, please enter the number corresponding to your menu choice\n" << endl;
        return menuSelection();
    } else {
        return menuSelection();
    }
    return 0;
}

/*
 * This function is called poll user for input and display base 10 value to terminal.
 * */
void romanToBase10InputOutput() {
    string romanNumerals;
    int base10Value;

    cout << "\nPlease enter a valid Roman numeral to be converted to base 10.\n\n"
            "Input the Roman number: ";
    cin >> romanNumerals;

    if (isValidRomanNumeral(romanNumerals)) {
        cout << "\n\nStarting Roman numeral: " << romanNumerals << endl;
        romanNumerals = removeSubtractives(romanNumerals);
        cout << "Expanded with no subtractives: " << romanNumerals << endl;
        base10Value = romanToBase10(romanNumerals);
        cout << "Base 10 value: " << base10Value << "\n" << endl;

    } else {
        romanToBase10InputOutput();
    }
    menuSelection();
}

/*
 *  This function checks that the users input are valid characters
 * */

bool isValidRomanNumeral(string romanNumerals) {
    if (romanNumerals.find_first_not_of("IVXLCDM") != -1) {
        cout << "Input not valid. Please enter a valid Roman numeral";
        return false;
    } else {
        return true;
    }
}

/*
 *  This function finds and replaces all the Roman numeral subtractives with their expanded form
 * */

string removeSubtractives(string romanNumerals) {
    string subtractivesArray[] = {"IV", "IX", "XL", "XC", "CD", "CM"};

    for (int i = 0; i < 6; i++) {
        int temp = romanNumerals.rfind(subtractivesArray[i]);
        if (temp != -1) {
            switch (i) {
                case 0:
                    romanNumerals.replace(temp, 2, "IIII");
                    break;
                case 1:
                    romanNumerals.replace(temp, 2, "VIIII");
                    break;
                case 2:
                    romanNumerals.replace(temp, 2, "XXXX");
                    break;
                case 3:
                    romanNumerals.replace(temp, 2, "LXXXX");
                    break;
                case 4:
                    romanNumerals.replace(temp, 2, "CCCC");
                    break;
                case 5:
                    romanNumerals.replace(temp, 2, "DCCCC");
                    break;
                default:
                    cout << "Error, invalid case" << endl;
            }
            removeSubtractives(romanNumerals);
        }
    }
    return romanNumerals;
}


/*
 * This function is called to convert Roman numerals into their base 10 value.
 * */
int romanToBase10(string romanNumerals) {
    string romanNumeralArray[] = {"I", "V", "X", "L", "C", "D", "M"};
    int base10Value{0};
    for (int i = 0; i < 7; i++) {
        while (romanNumerals.rfind(romanNumeralArray[i]) != -1) {
            int temp = romanNumerals.rfind(romanNumeralArray[i]);
            switch (i) {
                case 0:
                    romanNumerals.erase(temp, 1);
                    base10Value += 1;
                    break;
                case 1:
                    romanNumerals.erase(temp, 1);
                    base10Value += 5;
                    break;
                case 2:
                    romanNumerals.erase(temp, 1);
                    base10Value += 10;
                    break;
                case 3:
                    romanNumerals.erase(temp, 1);
                    base10Value += 50;
                    break;
                case 4:
                    romanNumerals.erase(temp, 1);
                    base10Value += 100;
                    break;
                case 5:
                    romanNumerals.erase(temp, 1);
                    base10Value += 500;
                    break;
                case 6:
                    romanNumerals.erase(temp, 1);
                    base10Value += 1000;
                    break;
                default:
                    cout << "Error, invalid case" << endl;
            }
        }
    }
    return base10Value;
}

string base10ToRoman(int base10Value) {
    string romanNumerals;
    int tempInt;

    tempInt = base10Value / 1000;
    base10Value %= 1000;
    while (tempInt > 0) {
        romanNumerals.append("M");
        tempInt--;
    }

    tempInt = base10Value / 500;
    base10Value %= 500;
    while (tempInt > 0) {
        romanNumerals.append("D");
        tempInt--;
    }

    tempInt = base10Value / 100;
    base10Value %= 100;
    while (tempInt > 0) {
        romanNumerals.append("C");
        tempInt--;
    }

    tempInt = base10Value / 50;
    base10Value %= 50;
    while (tempInt > 0) {
        romanNumerals.append("L");
        tempInt--;
    }

    tempInt = base10Value / 10;
    base10Value %= 10;
    while (tempInt > 0) {
        romanNumerals.append("X");
        tempInt--;
    }

    tempInt = base10Value / 5;
    base10Value %= 5;
    while (tempInt > 0) {
        romanNumerals.append("V");
        tempInt--;
    }

    tempInt = base10Value / 1;
    while (tempInt > 0) {
        romanNumerals.append("I");
        tempInt--;
    }
    cout << romanNumerals << endl;
    return romanNumerals;
}

void base10ToRomanInputOutput() {
    string romanNumerals;
    int base10Value;

    cout << "\nPlease enter a valid integer to be converted to Roman numerals.\n\n"
            "Input your integer: ";
    cin >> base10Value;

    if (isValidBase10(base10Value)) {
        cout << "\n\nStarting Integer: " << base10Value << endl;
        romanNumerals = base10ToRoman(base10Value);
        cout << "Roman numeral with no subtractives: " << romanNumerals << endl;
        romanNumerals = addSubtractives(romanNumerals);
        cout << "Roman numeral value: " << romanNumerals << "\n" << endl;

    } else {
        base10ToRomanInputOutput();
    }
    menuSelection();
}

bool isValidBase10(int base10Value) {
    if (base10Value < 1 || base10Value > 9999) {
        cout << "Input not valid. Please enter a valid integer between 1 and 9999";
        return false;
    } else {
        return true;
    }
}

string addSubtractives(string romanNumerals) {
    string groupingsArray[] = {"DCCCC", "CCCC", "LXXXX", "XXXX", "VIIII", "IIII"};

    for (int i = 0; i < 6; i++) {
        int temp = romanNumerals.rfind(groupingsArray[i]);
        if (temp != -1) {
            switch (i) {
                case 0:
                    romanNumerals.replace(temp, 5, "CM");
                    break;
                case 1:
                    romanNumerals.replace(temp, 4, "CD");
                    break;
                case 2:
                    romanNumerals.replace(temp, 5, "XC");
                    break;
                case 3:
                    romanNumerals.replace(temp, 4, "XL");
                    break;
                case 4:
                    romanNumerals.replace(temp, 5, "IX");
                    break;
                case 5:
                    romanNumerals.replace(temp, 4, "IV");
                    break;
                default:
                    cout << "Error, invalid case" << endl;
            }
            addSubtractives(romanNumerals);
        }
    }
    return romanNumerals;
}


void romanAddition() {
    string romanNumerals, userInput1, userInput2;

    cout << "\nPlease enter valid Roman numerals for addition...\n\n";
    cout << "First Roman numeral: ";
    cin >> userInput1;
    cout << "Second Roman numeral: ";
    cin >> userInput2;


    if (isValidRomanNumeral(userInput1) && isValidRomanNumeral(userInput2)) {
        userInput1 = removeSubtractives(userInput1);
        userInput2 = removeSubtractives(userInput2);
        romanNumerals.append(userInput1);
        romanNumerals.append(userInput2);
        romanNumerals = sortRomanNumeral(romanNumerals);
        romanNumerals = combineGroups(romanNumerals);
        romanNumerals = addSubtractives(romanNumerals);

        cout << "\nThe sum of " << userInput1 << " + " << userInput2 << " = " << romanNumerals << endl << endl;
    } else {
        romanAddition();
    }
    menuSelection();
}

string sortRomanNumeral(string romanNumerals) {
    string sortedRomanNumeral;
    int temp;

    while (romanNumerals.find('M') != -1) {
        temp = romanNumerals.find('M');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("M");

    }
    while (romanNumerals.find('D') != -1) {
        temp = romanNumerals.find('D');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("D");
    }
    while (romanNumerals.find('C') != -1) {
        temp = romanNumerals.find('C');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("C");
    }
    while (romanNumerals.find('L') != -1) {
        temp = romanNumerals.find('L');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("L");
    }
    while (romanNumerals.find('X') != -1) {
        temp = romanNumerals.find('X');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("X");

    }
    while (romanNumerals.find('V') != -1) {
        temp = romanNumerals.find('V');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("V");

    }
    while (romanNumerals.find('I') != -1) {
        temp = romanNumerals.find('I');
        romanNumerals.erase(temp, 1);
        sortedRomanNumeral.append("I");
    }
    romanNumerals = sortedRomanNumeral;
    return romanNumerals;
}

string combineGroups(string romanNumerals){
    string romanNumeralGroupings[] = {"IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD"};

    for (int i = 0; i < 6; i++) {
        int temp = romanNumerals.find(romanNumeralGroupings[i]);
        if (temp != -1) {
            switch (i) {
                case 0:
                    romanNumerals.replace(temp, 5, "V");
                    break;
                case 1:
                    romanNumerals.replace(temp, 2, "X");
                    break;
                case 2:
                    romanNumerals.replace(temp, 5, "L");
                    break;
                case 3:
                    romanNumerals.replace(temp, 2, "C");
                    break;
                case 4:
                    romanNumerals.replace(temp, 5, "D");
                    break;
                case 5:
                    romanNumerals.replace(temp, 2, "M");
                    break;
                default:
                    cout << "Error, invalid case" << endl;
            }
            combineGroups(romanNumerals);
        }
    }
    return romanNumerals;
}









