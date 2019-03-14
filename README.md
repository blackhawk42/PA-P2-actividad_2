# PA-P2-actividad_3
Programación Avanzada - Parcial 2: Actividad 3

Questions:

1. What is the difference between a program, a thread, a task, a job and a process?
2. Write a program in C that counts the number of times a particular character appears in a file. Ask the user for the character to find.
3. Write a program in C that reads a file and store its lines into an array.
4. Write a program in C that counts the number of lines in a file.
5. Write a program in C that counts the number of words and the number of characters in a file.
6. Write a program in C that deletes a specific line from a file. Ask the user for the line number.
7. Write a program in C that merges two files and writes them in a new file.

# Building

All C source files can be built (assuming GCC compiler) as:

```
> gcc -o EXERCISE_NUMBER.exe EXERCISE_NUMBER.c
```

If GNU Make is installed, you can simply run:

```
> make
```

to build all exercises.

# Running

All programs show a simple help message when run without arguments.

A more complete summary is:

## 02.exe

Invoke with an arbitrary number of filenames as command-line arguments.
A character will be interactively asked. Finally, for each file passed,
the number of times that character was found on that file will be printed
followed by the filename.

Example:

```
> 02.exe texts/fox.txt texts/abc.txt
> Give me a character: c
1 texts\fox.txt
3 texts\abc.txt
```

## 03.exe
Invoke with an arbitrary number of filenames as command-line arguments. For each
file, all lines will be stored in an array, line by line, and the array printed.

Example:
```
> 03.exe texts\abc.txt
{
        "a"
        "bb"
        "ccc"
        "dddd"
        "eeeee"
        "ffffff"
        "ggggggg"
        "hhhhhhhh"
        "iiiiiiiii"
}
```

## 04.exe
Invoke with an arbitrary number of filenames as command-line arguments. For each file,
the number of lines in that file will be written, followed by the filename.

Result should be similar to the ```wc``` Unix utility, with only the line numbering
and less pretty formatting.

Example:

```
> 04.exe texts\the_old_astronomer.txt
19 texts\the_old_astronomer.txt
```

## 05.exe
Invoke with an arbitrary number of filenames as command-line arguments. For each file,
in this order, the number of words, characters and the filename will be printed.

All characters, including whitespace, will be included in the character count.
A word is defined as a the concatenation of non-whitespace characters, possibly surronded
by whitespace. Whitespace is defined by the function ```isspace()```, from the
```ctype.h``` standard header. Behavoir should be similar to the ```wc``` Unix utility,
whithout the line number and less pretty formatting.

Example:
```
> 05.exe texts\one_word.txt texts\two_words.txt texts\shoes.txt
1 4 texts\one_word.txt
2 9 texts\two_words.txt
6 33 texts\shoes.txt
```

## 06.exe

The program is run with a pair number of command-line arguments: one file to delete
a line from, followed by an output file. A line number to delete will be asked interactively.
If the line number is greater than the actual number of lines in the file, the file
will be copied as-is to it's output file.

Example:

```
> 06.exe texts\shoes.txt test_1.txt texts\one_word.txt test_2.txt
> Give me a line to delete: 2
> cat test_1.txt
For sale:
> cat test_2.txt
word
```

## 07.exe

The program is run with at least one command-line argument: the name of the output
file. The rest of the arguments will be taken as input files. If no input
file is given, the standard input will be used.

It is assumed that by "merging" the files one means literal concatenation: the contents
of the files will be respected; no extra information (e.g., line breaks) will
be added to the result. Behavior should be similar to the ```cat``` Unix utility,
when the output is redirected to a file.

Example:

```
> 07.exe test.txt texts\one_word.txt texts\two_words.txt texts\shoes.txt
> cat test.txt
wordtwo wordsFor sale:
baby shoes, never worn.
```
