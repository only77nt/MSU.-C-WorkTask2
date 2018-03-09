### Вариант задания: дата и время ###
#### Процесс сборки: ####
* 1) Скачать 4 файла: main.cpp, Data.cpp, Data.h, makefile 2) В терминале: make, после компиляции ./run.out
#### Описание файлов: ####
* makefile - сборка программы, main.cpp - функция main (меню), Data.cpp - файл с телами функций, Data.h - описания функций
######1) 1.03.2018 ######
* Уже попробовал создать класс. Есть некоторые вопросы по поводу try-catch блоков, статических объектов, функций. 
* Не совсем понимаю, как осуществить взаимосвязь между двумя классами.
######2) 9.03.2018 ######
* Программа почти готова, не хватает только одного конструктора (функции Mom-Mom=Int). Не совсем понимаю, как его сделать, т.к. уже перегрузил оператор "-". Думал использовать функцию, но что возвращать в таком случае? (return <объект класса> не работал, компилятор ругался). Или же это можно сделать используя friend функцию?
* Сделано меню, пользователь может выбирать бесконечно всё что ему захочется, пока не выберет exit (Вводятся числа от 1 до 8). Поставлена задержка для того, чтобы слишком сильно и быстро не "захламлять" экран.
* При операции "-" очень много "китайского кода", он работает, но страшно выглядит. Пока что у меня нет идей, как это исправить (чтобы было как в операции "+"), можно переводить всё в секунды - но это очень не логично. Если сможете подсказать, как это можно более проще сделать, буду очень благодарен.
* Вводить дату можно как в шаблоне, который появляется 1-ой строчкой, либо же в формате yyyy-mm-dd hh-mm-ss, вместо "-" также можно вставлять пробелы, либо ":". Можно считать это фичей, т.к. иногда лень вводить ":".
* Если же человек не будет соблюдать шаблона (4 цифры под год, 2 под месяц, 2 под день и т.д.), то дата введётся правильно (также можно вводить c начальными нулями или же без них, пример: 2018-01-1 23:30:5), но тогда fgets считает, что пользователь ввёл ещё не всё и требует ввода - нажимаем enter и он просит ввести второй интервал (момент). Такое происходит не всегда.
* Возможно функцию print лучше было унаследовать, но я побоялся, что могу сломать всё.
* При операции Int-Int=Int или же Mom-Int=Mom лучше вводить сначала больший интервал (момент), а потом уже меньший (Наоборот работает, но проверять немного трудно).
* Мог забыть какие-то проверки. Поставил немного исключений, хотел ловить их в конце функции main, но компилятор начал ругаться. Возможно он не может выпрыгнуть из конструктора.

