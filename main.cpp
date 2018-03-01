#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void find_divider (int N, int *prime_numbers, bool *result, int i)
{
    if (!result[N])
    {
        result[N] = true;
        while(prime_numbers[i])
        {
            if (!(N % prime_numbers[i]))                          //если это делитель
            {
                int divider = N / prime_numbers[i];
                find_divider(divider, prime_numbers, result, i);
            }
                i++;
        }
    }
}
void Eratrosphen (int N)
{
    int sqrtN = sqrt(N), arr[sqrtN], prime_numbers[sqrtN], iter = 0;
    bool result[N+1];
    for (int i = 0; i <= N; i++)
        result[i] = false;
    result[1] = true;
    if (!(N % 2))                //если число парное
    {
        prime_numbers[iter] = 2;
        result[2] = true;
        iter++;
    }
    for (int i = 3; i <= sqrtN; i += 2)
        arr[i] = i;                              //простым делителем может быть только нпарное число, кроме 2
    for (int i = 3; i <= sqrtN; i += 2)
    {
        if (arr[i])
            {
               if (!(N % arr[i])) {                //если это делитель
                    prime_numbers[iter] = arr[i];
                    result[arr[i]] = true;
                    iter++ ;
               }
                for (int j = i * i; j <= sqrtN; j += 2 * i){   //если найден простой делитель, все остальные делители
                     arr[j] = 0;                               //что он образует, удаляем
                     }
            }
    }
    if (!iter){                                                //проверка на ввод простого числа
        cout << "This is prime number" << endl;
        return;
    }
    prime_numbers[iter] = 0;                                   //остановка рекурсии, когда простой делитель равен 0
    find_divider(N, prime_numbers, result, 0);
    for (int i = 0; i <= N; i++)                               //вывод
        if (result[i]) cout << i << " ";
}

int main()
{
    cout << "Write your number" << endl;
    int N;
    cin >> N;
    Eratrosphen(N);
    return 0;
}
