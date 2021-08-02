# Изброен тип. Указатели към функции

## Задача 1:

Да се състави програма, която прочита **N** (N < 100) числа от клавиатурата в масив.
Да се напише функция, която извършва операция върху всяко едно число приемаща указател към функция.
Реализирайте 2 помощни функции, които да се подават с указател:

- увеличаващи числата с процент подаден от клавиатурата
- намяляващи числата с процент подаден от клавиатурата

_Вход:_  
6  
1 2 3 4 5 6  
50  
50

_Изход:_  
1.5 3 4.5 6 7.5 9  
0.5 1 1.5 2 2.5 3

## Задача 2:

Да се реализира програма валидатор, която прочита дата във формат `YYYY MM DD HH mm ss` и чрез exit code-a на програмата определя дали датата е валидна или има проблем. Приложете знанията си по изброени типове и използвайте следната конвенция:

```
0 - ОК
1 - Invalid month
2 - Invalid day
3 - Invalid hour
4 - Invalid minutes
5 - Invalid seconds
```

_Вход:_  
2021 1 15 8 24 0

_Exit code_  
0

_Вход:_  
2021 1 15 68 24 0

_Exit code_  
3

_NB!_ За проверка на exit code-a на системата си изтеглете файла [exitCode.bat](<https://github.com/fmi-lab/up-kn-2020-group-4/tree/master/Practicum/Week%2013%20Function%20Pointers%20(15.01)/Solutions/exitCode.bat>) и го поставете в папката, където се намира cpp файла ви, след това изпъленете следната команда `exitCode.bat [source name]`

## Задача 3:

Да се състави програма приемаща символен низ от клавиатурата с **N** елемента (N < 100).
Да се напише функция, която извършва операция върху всяко една буква приемаща указател към функция.
Реализирайте 2 помощни функции, които да се подават с указател:

- toLowerCase - преобразувам главните букви в малки
- toUpperCase - преобразува малките букви в главни

_Вход:_  
C++ is Great!

_Изход:_  
c++ is great!  
C++ IS GREAT!

## Задача 4:

Да се състави програма, която реализира играта Морски шах. Имаме максимум 9 итерации, при всяка итерация се прочитат _i_ и _j_ позицията на съответния ход.
Използвайте изброен тип за описване ходовете на играчите. Напишете функция, която използва изброен тип за определяне дали има печеливша последователност по хоризонтала/вертикала/диагонал или няма.

_Вход_  
1 1  
3 3  
1 3  
1 2  
3 1  
2 1  
2 2

_Изход_  
Player 1 win!

```
1 2 1
2 1 0
1 0 2
```

## Задача 5:

Да се състави програма, която прочита **N** (N < 100) числа от клавиатурата в масив.
Да се напише функция sort, която сортира числата в масива. Функцията да приема указател към функция, която сравнява числата.
Реализирайте 2 помощни функции сравняващи числата:

- за възходящ ред
- за низходящ ред

_Вход:_  
6  
4 3 6 1 5 2

_Изход:_  
1 2 3 4 5 6  
6 5 4 3 2 1

## Задача 6:

Да се състави програма, която прочита **N** (N < 100) числа от клавиатурата в масив.
Да се напише функция sort, която приема функция за сортиранe като указател.
Реализирайте функции за сортиране със следните алгоритми:

- bubble sort
- insertion sort
- merge sort

_Вход:_  
6  
4 3 6 1 5 2

_Изход:_  
Bubble sort: 1 2 3 4 5 6  
Insertion sort: 1 2 3 4 5 6  
Merge sort: 1 2 3 4 5 6

## Function Pointers

### Syntax:

```
	<type> (*<name>)(<params>)
```

#### Assigning a function to a function pointer:

```
	<return_type> (*<func_ptr_name>)(<param_type>) { &<func_name> };
or
	<return_type> (*<func_ptr_name>)(<param_type>);
	<func_ptr_name> = &<func_name>;
```

- <b>Task:</b> Ok or Wrong?

```
	// function prototypes
	int foo();
	double goo();
	int hoo(int x);

	// function pointer assignments
	int (*fcnPtr1)(){ &foo };
	int (*fcnPtr2)(){ &goo };
	double (*fcnPtr4)(){ &goo };
	fcnPtr1 = &hoo;
	int (*fcnPtr3)(int){ &hoo };
```

### Calling a function using a function pointer:

```
	<return_type> (*<func_ptr_name>)(<param_type>){ &<func_name> };

    (*<func_ptr_name>)(<param>);
or
    <func_ptr_name>(<param>);
```

### Passing functions as arguments to other functions:

```
	// declate function1
	<return_type1> <func_name1>(<params>, <return_type2> (*<func_ptr_name>)(<param_type>));
	{
		body
	}

	// function2
	<return_type2> <func_name2>(<params>);
	{
		body
	}

	// calling a function1
	<func_name1>(<params>, <func_name2>);

```

- <b>Note</b>: If a function parameter is of a function type, it will be converted to a pointer to the function type. This means:

```
		<return_type1> <func_name>(<params>, <return_type2> (*<func_ptr_name>)(<param_type>));
equals
		<return_type1> <func_name>(<params>, <return_type2> <func_ptr_name>(<param_type>));
```

- Providing default functions:

```
		<return_type1> <func_name>(<params>, <return_type2> (*<func_ptr_name>)(<param_type>) = <default_func_name>);
```

### Making function pointers prettier with type aliases:

```
	using FuncPtr = <return_type1>(*)(<param_type>);

	<return_type2> <func_name>(<params>, FuncPtr funcPtrName);
```

# ЗАДАЧИ

## Указатели към функции:

### Задача 1:

Напишете функцията <b>any_of</b>, която проверява дали някой от елементите в масив отговаря на предикатната функция(на определено условие). Нека функцията има следните параметри: масив от тип int, размер на масива и указател към функция от тип:

```
	bool (*<name>)(int <param_name>);
```

### Задача 2:

Напишете функцията <b>all_of</b>, която проверява дали всички елементи в масив отговаря на предикатната функция(на определено условие). Нека функцията има следните параметри: масив от тип int, размер на масива и указател към функция от тип:

```
	bool (*<name>)(int <param_name>);
```

### Задача 3:

Напишете функцията <b>sort</b>, която сортира елементите в масив спрямо сравняваща функция. Нека функцията има следните параметри: масив от тип int, размер на масива и указател към функция от тип:

```
	bool (*<name>)(int <param_name1>, int <param_name2>);
```

### Задача 4:

Да се напишат 2 функции, с имплементации по ваш избор, и тествайте задачи 1 и 2. Функциите да имат следния вид:

```
	bool <name>(int <param_name>);
```

### Задача 5:

Да се напишат 2 функции, с имплементации по ваш избор, и тествайте задачa 3. Функциите да имат следния вид:

```
	bool <name>(int <param_name1>, int <param_name2>);
```
