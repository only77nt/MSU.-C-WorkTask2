#include <iostream>
#include <cstdio>
#include <string>

void Check(int *,int *, int *, int *, int *, int *); /*const*/
void clean_stdin(void); /*private*/
int Date(char *, int *);
bool isValidDate(int, int, int); /*const*/
bool isValidTime(int, int, int); /*const*/

class Excpt: public std::exception { /*КЛАСС ИСКЛЮЧЕНИЙ*/
public:
char msg[128];
Excpt(const char*); /*Считываем тип ошибки с помощью конструктора присваивания*/
};

class Interv { /*КЛАСС ИНТЕРВАЛ*/
private:
friend int Date(char *, int *);
friend bool isValidDate(int, int, int);
friend bool isValidTime(int, int, int);
friend void Check(int, int, int, int, int, int);
friend std::ostream& operator << (std::ostream&, const Interv&);
public:
int year,month,day,hour,min,sec;

Interv();
Interv(char *);
Interv& operator + (const Interv&);
Interv& operator - (const Interv&);
void DateTwo(int, int, int); /*private*/
void TimeTwo(int, int, int); /*private*/
void set(int,int,int,int,int,int); /*const*/
};

class Now{ /*КЛАСС МОМЕНТ*/
private:
friend int Date(char *, int *);
friend bool isValidDate(int, int, int);
friend bool isValidTime(int, int, int);
friend void Check(int, int, int, int, int, int);
public:
int year,month,day,hour,min,sec;

Now();
Now(char *);
Now& operator + (const Interv&);
void DateOne(int, int, int); /*private*/
void TimeOne(int, int, int); /*private*/
Now& operator - (const Interv&);
void print() const; /*const*/
};

Interv& Minus(const Now&, const Now&);
