#include <iostream>
#include "string"
#include "stdlib.h"
#include "sstream"
#include "fstream"
#include "cmath"
#include "float.h"
#include "vector"
#include "limits"
#include "ctime"
#include "array"
using namespace std;
/* int main() {
   CMatrix A(4,INIT_RAND);
   A.print();
   /*EinmheitsMatrix mit random ziffer zwischen 0..9
    * zum Test des copy-Konstruktor und zuweisung operator
    * new Matrix mit kleinere groesse erzeugen => erwartetes Ergebnis ..anpassen der Groesse der Array A*/
//    CMatrix B(4, 4);

//  cout<<B;
// A=B;
// */
/*   cout<<"Berechne A*10"<<endl;
    A*=10;
    cout<<A;
    cout<<"Berechne C=A"<<endl;
    CMatrix C(A);
    cout<<C;
    CMatrix B(4,INIT_UNIT);
    CMatrix D=A+B;
    cout<<D;*/
void save_sore(int guess_count)
{
    ifstream input("guesses.text");
    if (!input.is_open())
    {
        cout << "Unable to openfile\n";
        return;
    }
    int best_score;
    input >> best_score;
    ofstream output("guesses.text");
    if (!output.is_open())
    {
        cout << "Unable to openfile\n";
        return;
    }
    if (guess_count < best_score)
    {
        output << guess_count;
    }
    else
    {
        output << best_score;
    }
}
void print_array(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << "\t";
    }
}
void print_vector(vector<int> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << "\t";
    }
}
void play_game()
{
    vector<int> guesses;
    int guess_count = 0;
    int random = rand() % 251;
    cout << random << endl;
    cout << "Guess a number: ";
    while (true)
    {
        int guess;
        cin >> guess;
        guess_count++;
        guesses.push_back(guess);
        if (guess == random)
        {
            cout << "You win!\n";
            break;
        }
        else if (guess < random)
        {
            cout << "Too low\n";
        }
        else
        {
            cout << "Too high\n";
        }
    }
    save_sore(guess_count);
}
void print_stl_array(array<int, 20> data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << data[i] << "\t";
    }
    cout << "\n";
}
int main()
{
    /*  int choice;
     srand(time(NULL));
     int guesses[250];
     int guess_count=0;
     do{
         cout<<"1.play"<<"\t"<<"0.quit\n";
         cin>>choice;
         switch (choice) {
             case 0:
                 cout<<"See you the next time :) \n";
                 break;
             case 1:
                 play_game();
                 break;
         }
     }while(choice!=0);
     array<int,20>ages={1,2,3};
     print_stl_array(ages,3);*/
    float str = 14;
    if (str / 1 == 0)
    {
        int temp = str / 1;
        cout << "number : " << temp << endl;
        cout << "fuhrende 0" << endl;
    }
    else
    {
        int temp = str / 1;
        cout << "number : " << temp << "\n";
        cout << "keine fuhrende null" << endl;
        int counter = 0;
        while (temp % 10)
        {
            int a = temp % 10;
            cout << a << endl;
            temp /= 10;
            counter++;
        }
        cout << "Anzahl von Zahlen : " << counter << endl;
        cout << "neue Zahl : " << str * pow(10, 4 - counter);
    }
    return 0;
}
/*const int SIZE = 100;
     int guesses[SIZE];
     int count =0;
     for (int i = 0; i < SIZE; ++i) {
        if(cin >> guesses[i]){
            count++;
        }else{
            cout<<"See you the next time :) \n";
            break;
        }
    }
     print_array(guesses,count);
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
     string str;
     cin>>str;
     cout<<str<<endl;
  return 0;*/
