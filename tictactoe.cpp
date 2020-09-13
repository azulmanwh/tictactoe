#include <iostream>
using namespace std;

int counter = 0;

void display(char a[],char b[],char c[]) {
    for (int i = 0; i < 3; i++) {
        cout << '|';
        cout << a[i];
        cout << '|';

    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << '|';
        cout << b[i];
        cout << '|';
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << '|';
        cout << c[i];
        cout << '|';
    }
    cout << endl;
}

void turn(char a[],char b[], char c[], char symbol) {

    counter++;

    cout << "Where will you choose? ";
    string pos;
    cin >> pos;

    //the problem lies in the following lines of code
    //even if the input is neither a b or c the else statement
    //doesnt run, which means the lines 40 to 44 need fixing

    char char_array[3];

    strcpy_s(char_array, pos.c_str());

    int temp;
    if (char_array[1] == '1') {
        temp = 0;
    }
    else if (char_array[1] == '2') {
        temp = 1;
    }
    else {
        temp = 2;
    }

    if (char_array[0] == 'a') {
        a[temp] = symbol;
    } 
    else if (char_array[0] == 'b') {
        b[temp] = symbol;
    }
    else if (char_array[0] == 'c') {
        c[temp] = symbol;
    }
    else {
        cout << "Invalid input, try again: " << endl;
        if (counter < 10) {
            turn(a, b, c, symbol);
        }
        else {
            exit(1);
        }
    }
}

int main() {
    char player = 'x';
    char a[3] = {
        ' ', ' ', ' '
    };
    char b[3] = {
        ' ', ' ', ' '
    };
    char c[3] = {
        ' ', ' ', ' '
    };
    do {
        system("cls");
        display(a, b, c);
        turn(a, b, c, player);
        if (player == 'x') {
            player = 'o';
        }
        else {
            player = 'x';
        }
    } while (true);
}
