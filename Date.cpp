#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <string>
#include "Date.h"
using namespace std;

Excpt::Excpt(const char* Mes) {strcpy(this->msg,Mes);}; /*Конструктор присваивания для класса исключений*/

void Check(int *y,int *m, int *d, int *h, int *min, int *s){ /*Функция проверки даты и времени на соответсвие + преобразование*/
int y1=*y,m1=*m,d1=*d,h1=*h,min1=*min,s1=*s;
try{
	if(y1<0 || m1<0 || d1<0 || h1<0 || min1<0 || s1<0)
	{
		Excpt A("Error!");
		throw A;
	}
	while(m1>12 || d1>30 || h1>23 || min1>59 || s1>59)
	{
		if(m1>12)
		{
			y1++;
			m1-=12;
		}
		if(d1>30)
		{
			m1++;
			d1-=30;
		}
		if(h1>23)
		{
			d1++;
			h1-=24;
		}
		if(min1>59)
		{
			h1++;
			min1-=60;
		}
		if(s1>59)
		{
			min1++;
			s1-=60;
		}
	}
	}
catch(Excpt& e) {throw;} /*Ловим исключение и перекидываем его в main-функцию*/
*y=y1; *m=m1; *d=d1; *h=h1; *min=min1; *s=s1;
}

void clean_stdin(void) /*Функция очистки stdin*/
{
int c;
do c = getchar();	
while (c != '\n' && c != EOF);
return;
}

int Date(char *str, int *k) /*Функция разбора строки*/
{
int res=0,j=*k;
while(str[j]!=':' && str[j]!='_' && str[j]!='\0' && str[j]!='-' && str[j]!='\n')
{
	res*=10;
	res+=str[j]-'0';
	j++;
}
j++;
*k=j;
return res; 
}

bool isValidDate(int y, int m, int d) { /*Функция проверки правильности даты*/
        if(d>30 || d<=0)
			return false;
		if(m>12 || m<=0)
			return false;
		if(y>9999 || y<=0)
			return false;
        return true;
    }

bool isValidTime(int h, int min, int s) { /*Функция проверки правильности времени*/
        if(min<0 || s<0 || min>=60 || s>=60)
			return false;
		if(h>=24 || h<0)
			return false;
        return true;
    }

Interv::Interv(){}; /*Конструктор умолчания*/

void Interv::set(int y=0,int m=0,int d=0,int h=0,int min1=0,int s=0) {
this->year=y;
this->month=m;
this->day=d;
this->hour=h;
this->min=min1;
this->sec=s;
}

Interv::Interv(char *buffer1){ /*Конструктор преобразования*/
int y,m,d,h,min,s;
int j=0;
y=Date(buffer1,&j); /*Заносим в поля соотв. значения*/
m=Date(buffer1,&j);
d=Date(buffer1,&j);
h=Date(buffer1,&j);
min=Date(buffer1,&j);
s=Date(buffer1,&j);
if(y<0 || m<0 || d<0) /*Проверяем поля на правильность*/
{
	Excpt D("DataInt Error!");
	throw D;
}
if(h<0 || min<0 || s<0)
{
	Excpt D("TimeInt Error!");
	throw D;
}
DateTwo(y,m,d);
TimeTwo(h,min,s);
}

Interv& Interv::operator + (const Interv& NewInt) { /*Int+Int=Int*/
	year+=NewInt.year;
	month+=NewInt.month; 
	day+=NewInt.day; 
	hour+=NewInt.hour; 
	min+=NewInt.min; 
	sec+=NewInt.sec; 
	Check(&year,&month,&day,&hour,&min,&sec);
	return *this;
}

Interv& Interv::operator - (const Interv& NewInt) { /*Int-Int=Int*/
int y1=NewInt.year,m1=NewInt.month,d1=NewInt.day,h1=NewInt.hour,min1=NewInt.min,s1=NewInt.sec; 
int swap;
	if(year>=y1)
		year-=y1;
	else
	{
		swap=year;
		year=y1;
		y1=swap;
	
		year-=y1;
		
		swap=month;
		month=m1;
		m1=swap;

		swap=day;
		day=d1;
		d1=swap;

		swap=hour;
		hour=h1;
		h1=swap;

		swap=min;
		min=min1;
		min1=swap;

		swap=sec;
		sec=s1;
		s1=swap;
	}
		if(month>=m1)
			month-=m1; 
		else
		{
			month+=12;
			year--;
			month-=m1;
		}
		if(day>=d1)
			day-=d1;
		else
		{
			day+=30;
			if(month==0)
			{
				year--;
				month=12;
			}
			month--;
			day-=d1;
		}
		if(hour>=h1)
			hour-=h1;
		else
		{
			hour+=24;
			if(day==0)
			{
				if(month==0)
				{
					month=12;
					year--;
				}
				month--;
				day=30;
			}
			day--;
			hour-=h1;
		}
		if(min>=min1)
			min-=min1;
		else
		{
			min+=60;
			if(hour==0)
			{
				if(day==0)
				{
					if(month==0)
					{
						month=12;
						year--;
					}
					month--;
					day=30;
				}
				day--;				
				hour=24;
			}
			hour--;
			min-=min1;
		}
		if(sec>=s1)
			sec-=s1;
		else
		{
			sec+=60;
			if(min==0)
			{
				if(hour==0)
				{
					if(day==0)
					{
						if(month==0)
						{
							month=12;
							year--;
						}
						month--;
						day=30;
					}
					day--;				
					hour=24;
				}
				hour--;
				min=60;
			}
			min--;
			sec-=s1;
		}
return *this;
}

std::ostream& operator << (std::ostream &s, const Interv& NewInt) { /*Печать интервала*/
		s << NewInt.year << '-';
		if(NewInt.month>=10)
			s << NewInt.month << '-';
		else
			s << '0' << NewInt.month << '-';
		if(NewInt.day>=10)
			s << NewInt.day << ' ';
		else
			s << '0' << NewInt.day << ' ';
		if(NewInt.hour>=10)
			s << NewInt.hour << ':';
		else
			s << '0' << NewInt.hour << ':';
		if(NewInt.min>=10)
			s << NewInt.min << ':';
		else
			s << '0' << NewInt.min << ':';
		if(NewInt.sec>=10)
			s << NewInt.sec;
		else
			s << '0' << NewInt.sec;
		s << endl;
return s;
}

void Interv::DateTwo(int y=0, int m=0, int d=0){ /*Заносим дату в поля*/
	this->year=y;
	this->month=m;
	this->day=d;
}

void Interv::TimeTwo(int h=0, int m=0, int s=0){ /*Заносим время в поля*/
	this->hour=h;
	this->min=m;
	this->sec=s;
}	

Now::Now(){};

Now::Now(char *buffer){ /*Конструктор определения полей класса*/
int y,m,d,h,min,s;
int i=0;
y=Date(buffer,&i); /*Заносим значения в соотв. поля*/
m=Date(buffer,&i);
d=Date(buffer,&i);
h=Date(buffer,&i);
min=Date(buffer,&i);
s=Date(buffer,&i);
DateOne(y,m,d); /*Проверяем поля*/
TimeOne(h,min,s);
}

Now& Now::operator + (const Interv& NewInt) { /*Mom+Int=Mom*/
	year+=NewInt.year;
	month+=NewInt.month; 
	day+=NewInt.day; 
	hour+=NewInt.hour; 
	min+=NewInt.min; 
	sec+=NewInt.sec; 
	Check(&year,&month,&day,&hour,&min,&sec);
	return *this;
}

void Now::DateOne(int y=0, int m=0, int d=0){ /*Обработка даты*/
try {
		if (isValidDate(y, m, d))
		{
			this->year=y;
			this->month=m;
			this->day=d;
		}
		else
		{
			Excpt B("Data error!");
			throw B;
		}
	}
catch(Excpt& e) {throw;}
}

void Now::TimeOne(int h=0, int m=0, int s=0){ /*Обработка времени*/
try {
		if (isValidTime(h, m, s))
		{
			this->hour=h;
			this->min=m;
			this->sec=s;
		}
		else
		{
			Excpt C("Time error!");
			throw C;
		}
	}
catch(Excpt& e) {throw;}
}

Now& Now::operator - (const Interv& NewInt) { /*Mom-Int=Mom*/
int y1=NewInt.year,m1=NewInt.month,d1=NewInt.day,h1=NewInt.hour,min1=NewInt.min,s1=NewInt.sec; 
int swap;
	if(year>=y1)
		year-=y1;
	else
	{
		swap=year;
		year=y1;
		y1=swap;
	
		year-=y1;
		
		swap=month;
		month=m1;
		m1=swap;

		swap=day;
		day=d1;
		d1=swap;

		swap=hour;
		hour=h1;
		h1=swap;

		swap=min;
		min=min1;
		min1=swap;

		swap=sec;
		sec=s1;
		s1=swap;
	}
		if(month>=m1)
			month-=m1; 
		else
		{
			month+=12;
			year--;
			month-=m1;
		}
		if(day>=d1)
			day-=d1;
		else
		{
			day+=30;
			if(month==0)
			{
				year--;
				month=12;
			}
			month--;
			day-=d1;
		}
		if(hour>=h1)
			hour-=h1;
		else
		{
			hour+=24;
			if(day==0)
			{
				if(month==0)
				{
					month=12;
					year--;
				}
				month--;
				day=30;
			}
			day--;
			hour-=h1;
		}
		if(min>=min1)
			min-=min1;
		else
		{
			min+=60;
			if(hour==0)
			{
				if(day==0)
				{
					if(month==0)
					{
						month=12;
						year--;
					}
					month--;
					day=30;
				}
				day--;				
				hour=24;
			}
			hour--;
			min-=min1;
		}
		if(sec>=s1)
			sec-=s1;
		else
		{
			sec+=60;
			if(min==0)
			{
				if(hour==0)
				{
					if(day==0)
					{
						if(month==0)
						{
							month=12;
							year--;
						}
						month--;
						day=30;
					}
					day--;				
					hour=24;
				}
				hour--;
				min=60;
			}
			min--;
			sec-=s1;
		}
return *this;
}

void Now::print() const { /*Красивая печать даты*/ /*const*/
		cout << year << '-';
		if(month>=10)
			cout << month << '-';
		else
			cout << '0' << month << '-';
		if(day>=10)
			cout << day << ' ';
		else
			cout << '0' << day << ' ';
		if(hour>=10)
			cout << hour << ':';
		else
			cout << '0' << hour << ':';
		if(min>=10)
			cout << min << ':';
		else
			cout << '0' << min << ':';
		if(sec>=10)
			cout << sec;
		else
			cout << '0' << sec;
		cout << endl;
	}

Interv& Minus(const Now& Mom1, const Now& Mom2){ /*Mom-Mom=Int*/
int y1=Mom1.year,m1=Mom1.month,d1=Mom1.day,h1=Mom1.hour,min1=Mom1.min,s1=Mom1.sec;
int y2=Mom2.year,m2=Mom2.month,d2=Mom2.day,h2=Mom2.hour,min2=Mom2.min,s2=Mom2.sec; 
int swap;
	if(y1>=y2)
		y1-=y2;
	else
	{
		swap=y1;
		y1=y2;
		y2=swap;
	
		y1-=y2;
		
		swap=m1;
		m1=m2;
		m2=swap;

		swap=d1;
		d1=d2;
		d2=swap;

		swap=h1;
		h1=h2;
		h2=swap;

		swap=min1;
		min1=min2;
		min2=swap;

		swap=s1;
		s1=s2;
		s2=swap;
	}
		if(m1>=m2)
			m1-=m2; 
		else
		{
			m1+=12;
			y1--;
			m1-=m2;
		}
		if(d1>=d2)
			d1-=d2;
		else
		{
			d1+=30;
			if(m1==0)
			{
				m1--;
				m1=12;
			}
			m1--;
			d1-=d2;
		}
		if(h1>=h2)
			h1-=h2;
		else
		{
			h1+=24;
			if(d1==0)
			{
				if(m1==0)
				{
					m1=12;
					m1--;
				}
				m1--;
				d1=30;
			}
			d1--;
			h1-=h2;
		}
		if(min1>=min2)
			min1-=min2;
		else
		{
			min1+=60;
			if(h1==0)
			{
				if(d1==0)
				{
					if(m1==0)
					{
						m1=12;
						m1--;
					}
					m1--;
					d1=30;
				}
				d1--;				
				h1=24;
			}
			h1--;
			min1-=min2;
		}
		if(s1>=s2)
			s1-=s2;
		else
		{
			s1+=60;
			if(min1==0)
			{
				if(h1==0)
				{
					if(d1==0)
					{
						if(m1==0)
						{
							m1=12;
							m1--;
						}
						m1--;
						d1=30;
					}
					d1--;				
					h1=24;
				}
				h1--;
				min1=60;
			}
			min1--;
			s1-=s2;
		}
static Interv IntRes; /*Делаем объект видимым во всей программе*/
IntRes.set(y1,m1,d1,h1,min1,s1); /*Заполняем поля объекта*/
return IntRes;
}
	
