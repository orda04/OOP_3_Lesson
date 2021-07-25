/*
**********  Third task on  OOPcourse                                         ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 24.07.2021                                                  ****
*/


//•••Done 1.Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
//•••         Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
//•••         Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//•••         Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
//•••Done 2.Создать класс Car (автомобиль) с полями company (компания) и model (модель).
//•••         Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн).
//•••         Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//•••         Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
//•••         Обратить внимание на проблему «алмаз смерти».
//•••         Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
//•••Done 3.Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
//•••         Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
//•••         математические бинарные операторы (+, -, *, /) для выполнения действий с дробями унарный оператор (-)
//•••         логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//            Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
//            Продемонстрировать использование перегруженных операторов.
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
    class Figure
    {
    public:
        virtual double area()=0;
    };
    class Parallelogram: public Figure
    {
    private:

    public:
        double m_lenght=0; //side a
        double m_width=0;  //side b
        int m_angle=0;
        double s=0;  // square
        Parallelogram()
        {}
        Parallelogram(double lenght, double width,int angle): m_lenght(lenght),m_width(width),m_angle(angle)
        {

        }
        double area()
        {

           s=m_lenght*m_width;

          return s;
        }
    };
    class Rectangle: public Parallelogram
     {

      public:
        Rectangle()
        {

        }
        Rectangle(double lenght, double width,int angle) :Parallelogram(lenght,width,angle)
        {

        }
        double area()
        {
           s= (m_lenght*m_width*sin(m_angle))/2;
           return s;
        }
     };
    class Square:    public Parallelogram
     {
      public:
        Square()
        {

        }
        Square(double lenght): Parallelogram(lenght,lenght,90)
        {

        }
        double area()
        {
             s=m_lenght*m_lenght;
           return s;
        }
     };
    class Rhombus:   public Parallelogram
     {
      public:
        Rhombus()
        {}
        Rhombus(double lenght,int angle): Parallelogram(lenght,lenght,angle)
        {}

        double area()
        {
            s=m_lenght*m_lenght*sin(m_angle);
            return s;
        }
     };
    class Circle: public Figure
    {

    public:
        double m_radius;
        double m_diameter;
        double s;
        Circle()
        {}
        Circle(double radius): m_radius(radius),m_diameter(radius*2)
        {}
        double area()
        {
            s=3.14*m_radius*m_radius;
            return s;
        }
    };

    class Car
    {
    public:
        string company;
        string model;
        Car(string company , string model)
        {
            cout << company<<" "<<model<<endl;
        }
    };

    class PassengerCar: virtual public Car
    {
    public:
        PassengerCar(string a, string c) : Car(a,c)
        {
            cout<<"PassengerCar class: ";
            cout << c << endl;
        }
    };

    class Bus: virtual public Car
    {
    public:
        Bus(string a, string m) : Car(a,m)
        {
            cout<<"Bus class: ";
            cout << m << endl;
        }
    };

    class Minivan: public PassengerCar, public Bus
    {
    public:
        Minivan(string a, string c, string m) :
        PassengerCar(a,c), Bus(a,m), Car(a,c)
        { }
    };


    class Fraction
    {
    private:
        int m_numerator; // числитель
        int m_denominator; //знаменатель
   public:
        Fraction(int numerator=1, int denominator=1 ):m_numerator(numerator),m_denominator(denominator)
        {
            assert(denominator!=0);
        }
        void printFraction()
        {
            cout<<m_numerator<<"/"<<m_denominator<<endl;
        }
        int gcd(int a,int b)
           {
             while(a!=0 &&b!=0)
              {
                if(a>b)
                 {
                  a=a%b;
                 }
                else b=b%a;
           }
        return a+b;
    }
        int lcm(int a, int b)
    {
       return gcd(a, b) * a * b;
    }
        void reduce()
     {
         int gcd1=gcd(abs(m_numerator),m_denominator);
         if(gcd1!=1)
            {
             m_numerator=m_numerator/gcd1;
             m_denominator=m_denominator/gcd1;
            }
     }
        int const getNumerator()
    {
        return m_numerator;
    }
        int const getDenominator()
    {
        return m_denominator;
    }
        Fraction& operator*( Fraction &fraction)
    {
      m_numerator=m_numerator*fraction.getNumerator();
      m_denominator=m_denominator*fraction.getDenominator();
      reduce();
      return *this;
    }
        Fraction& operator-(Fraction &fraction)
    {

            if(m_denominator!=fraction.getDenominator())
            {
              //m_denominator=m_denominator*fraction.getDenominator();
              m_numerator=m_numerator*fraction.getDenominator()-fraction.getNumerator()*m_denominator;
              m_denominator=m_denominator*fraction.getDenominator();
            }
            else
            {
                m_numerator=m_numerator-fraction.getNumerator();
            }
            reduce();
            return *this;
    }
        Fraction& operator+(Fraction &fraction)
    {
        if(m_denominator!=fraction.getDenominator())
        {
          m_numerator=m_numerator*fraction.getDenominator()+fraction.getNumerator()*m_denominator;
          m_denominator=m_denominator*fraction.getDenominator();
        }
        else
        {
            m_numerator=m_numerator+fraction.getNumerator();
        }
        reduce();
        return *this;

    }
        Fraction& operator/( Fraction &fraction)
    {
        m_numerator = m_numerator * fraction.getDenominator();
        m_denominator = m_denominator * fraction.getNumerator();
        reduce();
        return *this;
    }



    };

   int main()
    {
        Parallelogram cat(1,2,30);
        Rectangle rec(3,4,45);
        Square squ(5);
        Rhombus rho(6,15);
        Circle cir(10);
        Figure *figure1 = &cat;
        Figure *figure2 = &rec;
        Figure *figure3= &squ;
        Figure *figure4=&rho;
        Figure *figure5=&cir;


       cout<<"parallelogram area:"<<figure1->area()<<" lenght: "<<cat.m_lenght<<" width: "<<cat.m_width<<" angle: "<<cat.m_angle<<endl;// figure1 -> area();
       cout<<"rectangle area:"<<figure2->area()<<" lenght: "<<rec.m_lenght<<" width: "<<rec.m_width<<" angle: "<<rec.m_angle<<endl;
       cout<<"square area:"<<figure3->area()<<" lenght: "<<squ.m_lenght<<" width: "<<squ.m_width<<" angle: "<<squ.m_angle<<endl;
       cout<<"rhombus area:"<<figure4->area()<<" lenght: "<<rho.m_lenght<<" width: "<<rho.m_width<<" angle: "<<rho.m_angle<<endl;
       cout<<"circle:"<<figure5 -> area()<<" radius: "<<cir.m_radius<<" diamater:"<<cir.m_diameter<<endl;
       Minivan animal("HONDA", "Odyssey", "No busses");
       Fraction first(1,3);
       first.printFraction();
       Fraction second(4,10);
       second.printFraction();
       cout <<"*"<<endl;
       Fraction result1 = first * second;
       result1.printFraction();



       cout <<"/"<<endl;
       Fraction result2 =first/second;
       result2.printFraction();

       cout<<"PLUS AND MINUS PART"<<endl;
       Fraction firstplus(2,10);
       firstplus.printFraction();
       Fraction secondplus(1,9);
       secondplus.printFraction();
        cout<<"common denominator: "<<firstplus.gcd(firstplus.getDenominator(),secondplus.getDenominator())<<endl;
        cout <<"+"<<endl;
        Fraction result3 =firstplus+secondplus;
        result3.printFraction();

        cout <<"-"<<endl;
        Fraction firstminus(2,10);
        firstminus.printFraction();
        Fraction secondminus(1,9);
        secondplus.printFraction();
        Fraction result4 =firstminus-secondminus;
        result4.printFraction();


    return 0;
}
