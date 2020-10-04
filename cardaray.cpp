// cardaray.cpp
// класс игральных карт

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hears, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
///////////////////////////
class card
{
      private:
          int number;
          Suit suit;
      public:
          card()                 // Конструктор
          { }
      void set ( int n, Suit s ) // установка значений
          { suit = s; number = n; }
      void display ( );          // показ карты
};
///////////////////////////
void card::display( )
{
     if(number >= 2 && number <= 10)
       cout << number;
     else 
     {
       switch (number)
       {
         case jack: 
              cout << 'J'; 
              break;
         case queen: 
              cout << 'Q'; 
              break;
         case king: 
              cout << 'K'; 
              break;
         case ace: 
              cout << 'A'; 
              break;
       }
     }
       switch (suit)
       {
       case clubs: 
            cout << static_cast<char>(5);
                 break;
       case diamonds: 
            cout << static_cast<char>(4);
            break;
       case hears: 
            cout << static_cast<char>(3);
       break;
       case spades: 
            cout << static_cast<char>(6);
            break;
       }
};
///////////////////////////
int main ( )
{
    setlocale (LC_ALL, "Russian");
    setlocale (LC_ALL, "rus");

    card deck [ 52 ];
    int j;
    
    cout<<endl;
    for( j=0; j<52; j++) // Создаем упорядочкнную колоду карт
    {
         int num = ( j % 13 ) +2;
         Suit su = Suit (j/13);
         deck [j].set (num, su);
    }  
    // Показываем исходную колоду
    cout << "Исходная колода: \n";
    for( j=0; j<52; j++)
    {
         deck [j].display( );
         cout<<" ";
         if( !( (j+1) % 13) ) // Начинаем новую строку после каждой 13-й карты
           cout<< endl;
    }
    srand (time (NULL) );     // инициализируем генератор случайных чисел
    for( j=0; j<52; j++)
    {
      int k = rand ( ) %52;   // выбираем случайную карту
      card temp = deck [j];   // и меняем ее с текущей
      deck [j] = deck [k];
      deck [k] = temp;
    }
    // Показываем переменную колоду
    cout << "\nПеременная колода:\n";
    for( j=0; j<52; j++)
    {
      deck [j].display( );
      cout<<" ";
      if( !( (j+1) % 13) ) // Начинаем новую строку после каждой 13-й карты
           cout<< endl;     
    }
    system("pause");
    return 0;
}



