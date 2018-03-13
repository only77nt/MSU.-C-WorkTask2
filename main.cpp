#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <unistd.h> 
#include <string>
#include "Date.h"
using namespace std;

int main() /*Main-вызов меню*/
{
char buffer2[20];
char buffer1[20];
time_t rawtime;
struct tm * timeinfo;
int input,i=0;
int y=0,m=0,d=0,h=0,min=0,s=0;
Interv InRes;
Now MomRes;
while(1)
{
try{
sleep(1); /*Можно убрать*/
printf("\nВводите дату в формате yyyy-mm-dd_hh:mm:ss\n"); /*Между датой и временем пробел*/
printf("Выберете пункт, который хотите выполнить: \n");
printf("1. Int + Int = Int\n");
printf("2. Int - Int = Int\n");
printf("3. Mom + Int = Mom\n");
printf("4. Mom - Int = Mom\n");
printf("5. Mom - Mom = Int\n");
printf("6. Show me the Date\n");
printf("7. Clear\n");
printf("8. Exit\n");
scanf("%d",&input);
switch(input){
case 1: {	/*Int + Int = Int*/
			clean_stdin();
			printf("Введите первый интервал:\n");
			cin >> buffer1;
			Interv Inter(buffer1); /*Работает*/
			clean_stdin();
			printf("Введите второй интервал: \n");
			cin >> buffer2;
			Interv In1(buffer2);
			InRes=Inter+In1;
			printf("Результат: \n");
			cout << InRes;
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 2: {	/*Int - Int = Int*/
			clean_stdin();
			printf("Введите первый интервал:\n");
			cin >> buffer1;
			Interv Inter(buffer1); /*Работает*/
			clean_stdin();
			printf("Введите второй интервал: \n");
			cin >> buffer2;
			Interv In1(buffer2);
			InRes=Inter-In1;
			printf("Результат: \n");
			cout << InRes;
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 3: {	/*Mom + Int = Mom*/
			clean_stdin();
			printf("Введите момент: \n");
			cin >> buffer1;
			Now Moment(buffer1);
			clean_stdin();
			printf("Введите интервал:\n");
			cin >> buffer2;
			Interv Inter(buffer2); /*Работает*/
			MomRes=Moment+Inter;
			printf("Результат: \n");
			MomRes.print();
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 4: {	/*Mom - Int = Mom*/
			clean_stdin();
			printf("Введите момент: \n");
			cin >> buffer1;
			Now Moment(buffer1);
			clean_stdin();
			printf("Введите интервал:\n");
			cin >> buffer2;
			Interv Inter(buffer2); /*Работает*/
			MomRes=Moment-Inter;
			printf("Результат: \n");
			MomRes.print();
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 5: {   /*Mom-Mom=Int*/
			clean_stdin();
			printf("Введите первый момент: \n");
			cin >> buffer1;
			Now Moment1(buffer1);
			clean_stdin();
			printf("Введите второй момент:\n");
			cin >> buffer2;
			Now Moment2(buffer2);
			InRes=Minus(Moment1,Moment2);
			printf("Результат: \n");
			cout << InRes;
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 6: {	/*Show the Date*/
			time( &rawtime ); // Получить текущую дату, выраженную в секундах
			timeinfo = localtime( &rawtime ); //Функция localtime () преобразует время в секундах, истекшее с 0 часов 1 января 1970 года в местное время и дату.
			std::cout << "Текущее локальное время и дата "
					  << asctime(timeinfo);  // Текущая дата, представленная в нормальной форме. (Красивый вывод, из структуры)
			break;
		}
case 7: {   /*Clear*/
			system("clear");
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);
			break;
		}
case 8: {   /*Exit*/
			memset(&buffer1, 0, 20);
			memset(&buffer2, 0, 20);			
			exit(0);
		}
}
}
catch(Excpt& e) {cout << e.msg << endl;}
}
return 0;
}
