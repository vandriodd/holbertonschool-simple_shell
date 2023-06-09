<div align="center">

<img src="https://apply.holbertonschool.com/holberton-logo.png" />
<h1> Simple Shell project </h1>

> This repository contains the final project of the first term of the Holberton School curriculum, where we are proposed to create a basic functional shell that imitates the behavior of the original.

</div>

<div align="center">

![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png)

</div>

<br>

## Table of contents
* [About](#about)
* [Resources](#resources)
* [Requirements](#requirements)
* [Files](#files)
* [Usage](#usage)
* [Authors](#authors)

## About 
First, to know what the project is about, it is important to know what a shell is. A shell is a program that acts as an interface between the user and the kernel of an operating system, allowing you to interact and execute commands through command lines or graphical interface, or is, **it's a command interpreter**.
<br>
Now, for this project we were divided into groups of two to encourage programming in groups, with the aim of *creating our own shell that imitates the behavior of the original*; although prior to this we were provided with theoretical material to create a **pre-shell** step by step, in order to ensure that we start the project with sufficient knowledge regarding the inner workings of the functions necessary for a shell.

## Resources
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* *Everything you need to know to start coding your own shell* concept page

## Requirements
* Ubuntu 20.04 LTS
* All files should compile with gcc 9.4.0 with the following flags:
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
* Use [Betty's style](https://github.com/holbertonschool/Betty/wiki)

## Files

<details>
<summary>shell.c</summary>
The main function for the shell. Contains function call for all other functions.
</details>

<details>
<summary>path.c</summary>
Contains _getenv which retrieves a specific environmental variable from “environ”, and tokenize, a function for tokenization with strtok.
</details>

<details>
<summary>which.c</summary>
Generates the full path of a function, concatenating a specific part of PATH environmental variable according to the function alias it takes as an argument.
</details>

<details>
<summary>execve.c</summary>
Forks the parent process and executes the function requested on the input.
</details>

<details>
<summary>aux.c</summary>
Contains auxiliar functions used in the previously explained functions.
</details>

<details>
<summary>main.h</summary>
Header file, containing all the prototypes of the previously explained functions, macro definitions, libraries call, and the environ variable.
</details>

## Usage
### Instalation
To use this program, it's first necessary to clone this repository as follows:
```bash
git clone https://github.com/vandriodd/holbertonschool-simple_shell.git
```
Then, inside the directory compile it:
```bash
cd holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c main.h -o hsh
```

### How it works
![shell-test](https://user-images.githubusercontent.com/110431271/235328103-f701ba7f-d698-4c5d-822d-2eeeadbb43db.gif)

### Interactive and non-interactive mode
In the testing section of the project proposal it is clarified that the shell **should be functional in both interactive and non-interactive mode**, that is, it should be able to execute commands in the following ways:

```bash
$ ./hsh
```
```bash
$ echo "/bin/ls" | ./hsh
```

### Flowchart
![Simple Shell](https://user-images.githubusercontent.com/110431271/235359201-34246756-98c8-44b0-ada9-df60988ecd5e.jpg)

<div align="center">

## Authors
  
&ensp;[<img src="https://img.shields.io/badge/vandriodd-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">](https://github.com/vandriodd)
&ensp;[<img src="https://img.shields.io/badge/gonzalopedernera-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">](https://github.com/gonzalopedernera)

<br>

![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png)

<br>

_Last updated: April 30, 2023_

</div>
