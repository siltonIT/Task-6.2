#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct clock
{
    unsigned short hour : 4;
    unsigned short minute : 6;
    unsigned short second : 6;
};

union Clocks
{
    struct clock bitfield;
};

void fill_random(Clocks*, const int);
void find_duplicate(Clocks*, const int);
void print(Clocks);
bool compare(Clocks, Clocks);


int main()
{
    const int SIZE = 10;
    Clocks clock[SIZE];

    fill_random(clock, SIZE);

    sort(std::begin(clock), std::end(clock), compare);

    for (int i = 0; i < SIZE; ++i)
    {
        print(clock[i]);
    }

    cout << endl << "Duplicate: " << endl;

    find_duplicate(clock, SIZE);
}

//Функция заполняет массив рандомными значениями 
void fill_random(Clocks* clock, const int SIZE)
{
    const int HOUR_BASE = 12;
    const int MINUTE_BASE = 60;
    const int SECOND_BASE = 60;

    for (int i = 0; i < SIZE; ++i)
    {
        clock[i].bitfield.hour = rand() % HOUR_BASE;
        clock[i].bitfield.minute = rand() % MINUTE_BASE;
        clock[i].bitfield.second = rand() % SECOND_BASE;
    }
}

//Функция ищет дубликаты в массиве
void find_duplicate(Clocks* clock, const int SIZE)
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (clock[i].bitfield.hour == clock[i + 1].bitfield.hour)
        {
            if (clock[i].bitfield.minute == clock[i + 1].bitfield.minute)
            {
                if (clock[i].bitfield.second == clock[i + 1].bitfield.second)
                {
                    print(clock[i]);
                }
            }
        }
    }
}

//Функция алгоритма сравнение в std::sort
bool compare(Clocks left, Clocks right)
{
    if (left.bitfield.hour == right.bitfield.hour)
    {
        if (left.bitfield.minute == right.bitfield.minute)
        {
            return left.bitfield.second < right.bitfield.second;
        }

        return left.bitfield.minute < left.bitfield.minute;
    }

    return left.bitfield.hour < right.bitfield.hour;
}

//Функция вывода массива
void print(Clocks clock)
{
    cout << clock.bitfield.hour << ':';
    cout << clock.bitfield.minute << ':';
    cout << clock.bitfield.second << endl;
}

/*
clock[0].bitfield.hour = 1;
clock[0].bitfield.minute = 1;
clock[0].bitfield.second = 1;
clock[1].bitfield.hour = 1;
clock[1].bitfield.minute = 1;
clock[1].bitfield.second = 1;
*/