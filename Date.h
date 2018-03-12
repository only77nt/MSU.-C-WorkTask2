#include <iostream>
#include <cstdio>
#include <string>

void Check(int *,int *, int *, int *, int *, int *);
void clean_stdin(void);
int Date(char *, int *);
bool isValidDate(int, int, int);
bool isValidTime(int, int, int);

class Excpt: public std::exception {
public:
char msg[128];
Excpt(const char*);
};

class Interv { /*КЛАСС ИНТЕРВАЛ*/
private:
friend int Date(char *, int *);
friend bool isValidDate(int, int, int);
friend bool isValidTime(int, int, int);
friend void Check(int, int, int, int, int, int);
public:
int year,month,day,hour,min,sec;

Interv();
Interv(char *);
Interv& operator + (const Interv&);
Interv& operator - (const Interv&);
void DateTwo(int, int, int);
void TimeTwo(int, int, int);
void print() const;
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
void DateOne(int, int, int);
void TimeOne(int, int, int);
Now& operator - (const Interv&);
void print() const;
};
