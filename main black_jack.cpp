/*
**********  Third task on  OOPcourse                                         ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 26.07.2021                                                  ****
*/

//        3.Создать класс Card, описывающий карту в игре БлэкДжек.
//         У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
//         Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
//         метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//         метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;


enum Suit
{HEARTS=1,
    DIAMONDS=2,
          CLUBS=3,
             SPADES=4 };
enum Rank
{ACE=1,
    DOUBLE=2,
       TRIPLE=3,
          FOUR=4,
             FIVE=5,
                SIX=6,
                  SEVEN=7,
                     EIGHT=8,
                        NINE=9,
                           TEN=10,
                              JACK=11,
                                 QUEEN=12,
                                    KING=13};

class Card
{


  bool card_face;

  Suit card_suit;
  Rank card_rank;

public:
 Card(Suit suit, Rank rank,bool face=false): card_suit(suit),card_rank(rank),card_face(face)
   {
   }

  void Flip()  // нужно будет доработать, чтобы в случае если карта уже цифрой вверх-ее невозножно было перевернуть и был возврат ошибки
    {
     if(card_face)
     {
         card_face=false;
     }
     else
     {
         card_face=true;
     }
    }
 int GetValue()
 {
     return card_rank;
 }

};

int main()
{
   Card first_card(HEARTS,ACE);

   cout<<"Первая карта: "<<first_card.GetValue()<<endl;

    return 0;
}
