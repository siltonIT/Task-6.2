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
    Clocks dup;
    dup.bitfield.hour = -1;
    dup.bitfield.minute = -1;
    dup.bitfield.second = -1;

    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (clock[i].bitfield.hour == dup.bitfield.hour)
        {
            if (clock[i].bitfield.minute == dup.bitfield.minute)
            {
                if (clock[i].bitfield.second == dup.bitfield.second)
                {
                    continue;
                }
            }
        }

        if (clock[i].bitfield.hour == clock[i + 1].bitfield.hour)
        {
            if (clock[i].bitfield.minute == clock[i + 1].bitfield.minute)
            {
                if (clock[i].bitfield.second == clock[i + 1].bitfield.second)
                {
                    print(clock[i]);
                    dup.bitfield.hour = clock[i].bitfield.hour;
                    dup.bitfield.minute = clock[i].bitfield.minute;
                    dup.bitfield.second = clock[i].bitfield.second;

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

        return left.bitfield.minute < right.bitfield.minute;
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

    clock[0].bitfield.hour = 0;
    clock[0].bitfield.minute = 0;
    clock[0].bitfield.second = 0;

    clock[1].bitfield.hour = 0;
    clock[1].bitfield.minute = 0;
    clock[1].bitfield.second = 1;

    clock[2].bitfield.hour = 0;
    clock[2].bitfield.minute = 2;
    clock[2].bitfield.second = 0;

    clock[3].bitfield.hour = 1;
    clock[3].bitfield.minute = 2;
    clock[3].bitfield.second = 1;

    clock[4].bitfield.hour = 1;
    clock[4].bitfield.minute = 0;
    clock[4].bitfield.second = 1;

    clock[5].bitfield.hour = 1;
    clock[5].bitfield.minute = 1;
    clock[5].bitfield.second = 1;

    clock[6].bitfield.hour = 1;
    clock[6].bitfield.minute = 1;
    clock[6].bitfield.second = 1;

    clock[7].bitfield.hour = 2;
    clock[7].bitfield.minute = 2;
    clock[7].bitfield.second = 2;

    clock[8].bitfield.hour = 2;
    clock[8].bitfield.minute = 2;
    clock[8].bitfield.second = 2;

    clock[9].bitfield.hour = 2;
    clock[9].bitfield.minute = 2;
    clock[9].bitfield.second = 2;
*/