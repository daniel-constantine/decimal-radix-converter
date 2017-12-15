/*  Programmer: Daniel Constantine
    Contact: daniel.k.constantine@gmail.com
    Description: This program get a number from the user in the base-10
        and convert the number into any radix of user choice (base 2-10 and 16)
*/

#include <iostream>
#include <vector>
using namespace std;

void askUser(int&, int&); //prompt user to input the number and the radix of user choice
void calculateNumber(int, int, int, int, vector<int>&); //convert the number from decimal to different radix
void printNumber(vector<int>&); //print the number inside the vector
int exitLoop(); //exiting the loop

int main()
{
    vector<int> storage;
    int number, radix, remainder, quotient, stopLoop;

    while(true){
        askUser(radix, number);

        calculateNumber(quotient, number, remainder, radix, storage);

        printNumber(storage);

        stopLoop = exitLoop();
        if(stopLoop == 0)
            break;
        cout << endl;
    }
    return 0;
}

void askUser(int& radix, int& number){
    cout << "Enter the radix you want me to convert: ";
    cin >> radix;
    cout << "Enter the number you want to convert: ";
    cin >> number;
    cout << "Converting number " << number << " to radix " << radix << endl;
}

void calculateNumber(int quotient, int number, int remainder, int radix, vector<int>& storage ){
    quotient = number;
    int i = 0;
    while(quotient != 0){
        remainder = quotient % radix;
        quotient = quotient / radix;
        storage.push_back(remainder);
        i++;
    }
}

void printNumber(vector<int>& storage){
    cout << "The number now is ";
    while(!storage.empty()){
        if(storage.back() == 10){
            cout << "A";
        } else if(storage.back() == 11){
            cout << "B";
        } else if(storage.back() == 12){
            cout << "C";
        } else if(storage.back() == 13){
            cout << "D";
        } else if(storage.back() == 14){
            cout << "E";
        } else if(storage.back() == 15){
            cout << "F";
        } else {
            cout << storage.back();
        }
        storage.pop_back();
    }
}

int exitLoop(){
    int exit;
    cout << "\n\nDo you want to continue? Enter 0 to exit the program: ";
    cin >> exit;
    return exit;
}
