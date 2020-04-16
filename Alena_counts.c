# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#include <unistd.h>

int task (int i, int answer_task, int range[][2])
{
	int number1;
    int number2;
    int number3;
	number1 = range[0][0] + rand() % ( range[0][1] - range[0][0] + 1 );
    number2 = range[1][0] + rand() % ( range[1][1] - range[1][0] + 1 );
    number3 = range[2][0] + rand() % ( range[2][1] - range[2][0] + 1 );
 //   printf ("range[0][0] = %d\n, range[0][1] = %d\n, range[1][0] = %d\n, range[1][1] = %d\n", range[0][0], range[0][1], range[1][0], range[1][1]);
	printf ("\nПример №%d\n\nx = %d + %d", i, number1, number2);
    if (number3 != 0)
        printf (" + %d", number3);
	answer_task = number1 + number2 + number3;
	return (answer_task);
}

void difficulty (int level, int range[][2])
{
    if (level == 1)
    {
        range[0][0] = 3;
        range[0][1] = 10;
        range[1][0] = 3;
        range[1][1] = 10;
        range[2][1] = 0;
        range[2][1] = 0;
    }
    if (level == 2)
    {
        range[0][0] = 5;
        range[0][1] = 9;
        range[1][0] = 5;
        range[1][1] = 9;
        range[2][1] = 5;
        range[2][1] = 9;
    }
    if (level == 3)
    {
        range[0][0] = 10;
        range[0][1] = 12;
        range[1][0] = 12;
        range[1][1] = 19;
        range[2][1] = 0;
        range[2][1] = 0;        
    }
    if (level == 4)
    {
        range[0][0] = 5;
        range[0][1] = 9;
        range[1][0] = 5;
        range[1][1] = 9;
        range[2][1] = 10;
        range[2][1] = 19; 
    }
        if (level == 5)
    {
        range[0][0] = 10;
        range[0][1] = 12;
        range[1][0] = 12;
        range[1][1] = 19;
    }
}

int main (void)
{
	int task_n;
	int folce;
    int level = 1;
	int answer_task;
	int answer_scan;
    char stop;
    int range [3][2] = { {0, 0}, {0, 0} };
    srand(time(NULL));
    while (level != 6)
    {
	    printf ("\nУровень сложности №%d\n", level);
        sleep (3);
        task_n = 1;
        difficulty (level, range);
        folce = 0;
        while (task_n != 6)
	    {
            answer_task = task(task_n, answer_task, range);
		    printf ("\nОтвет:");
		    scanf("%d", &answer_scan);
		    if (answer_scan == answer_task)
		    {
			    printf ("\nПравильно! Притоговься к следующему заданию!\n");
                sleep (3);
		    }
		    if (answer_scan != answer_task)
		    {
			    printf ("Неправильно!\n Притоговся к следующему заданию!");
                folce++;
                sleep (3);
            }
            task_n++;
//            scanf("%s", &stop);
        }     
        if (folce == 0 || level != 3)
        {
            printf ("\nПоздравляю! Ты ответила правильно на все задания и переходишь на следующий уровень!\n");
            level++;
        }
        if (folce != 0)
            printf ("\nТы обишлась %d раз, переход на следующий уровень невозможен\n", folce);
	}
	printf ("\nПоздравляю! Ты прошла игру, на этот раз :)\n");
	return (0); 
}