#include <stdio.h>
#include <random>
#include <time.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	//Ввод размера
	int Cmas[5], Umas[5], n, Uvar, count = 0, UvarD, bulls = 0, cows = 0;
	printf("Укажите длину загадываемого чиса от 2 до 5 включительно \n");
	scanf_s("%i", &n);
	while (n > 5 || n < 2)
	{
		printf("Неверное значение. Укажите длину загадываемого чиса от 2 до 5 включительно \n");
		scanf_s("%i", &n);
	}
	//Конец ввода размера

	//Создание рандомного числа с нужным размером и без повторений
	Cmas[0] = rand() % (10 - 1) + 1;
	for (int i = 1; i < n; ++i)
	{
		if (n <= 3)
		{
			do
			{
				Cmas[i] = rand() % 10;
			} while (Cmas[i] == Cmas[0]
				|| Cmas[i] == Cmas[i - 1]);
		}
		else if (n == 4)
		{
			do
			{
				Cmas[i] = rand() % 10;
			} while (Cmas[i] == Cmas[0]
				|| Cmas[i] == Cmas[i - 1]
				|| Cmas[i] == Cmas[i - 2]);
		}
		else if (n == 5)
		{
			do
			{
				Cmas[i] = rand() % 10;
			} while (Cmas[i] == Cmas[0]
				|| Cmas[i] == Cmas[i - 1]
				|| Cmas[i] == Cmas[i - 2]
				|| Cmas[i] == Cmas[i - 3]);
		}
	}
	//Конец создания рандомного числа с нужным размером и без повторений

	//Цикл игры
	do
	{
		//Введение пользователем варианта
		cows = 0;
		bulls = 0;
		count = 0;
		printf("Введите ваш вариант числа из %i цифр. \n", n);
		scanf_s("%i", &Uvar);
		UvarD = Uvar;
		while (UvarD != 0)
		{
			count += 1;
			UvarD /= 10;
		}
		while (count != n)
		{
			count = 0;
			printf("Неверное значение. Введите число состоящее из %i цифр. Введите верное число. \n", n);
			scanf_s("%i", &Uvar);
			UvarD = Uvar;
			while (UvarD != 0)
			{
				count += 1;
				UvarD /= 10;
			}
		}


		for (int i = 0; i < n; ++i)
		{
			Umas[(n - 1) - i] = Uvar % 10;
			Uvar /= 10;
		}
		//Конец ввода пользователем варианта

		//Сравнение массивов
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (Cmas[i] == Umas[j] and i == j)
				{
					bulls += 1;
				}
				else if (Cmas[i] == Umas[j] and i != j)
				{
					cows += 1;
				}
			}
		}
		//Конец сравнения массивов

		printf("Быки и коровы %i %i \n", bulls, cows);
	} while (bulls != n);
	printf("Вы победили.");
	//Конец цикла игры
	
	return 0;
}