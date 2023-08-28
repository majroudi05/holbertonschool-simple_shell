#ifndef MY_SIMPLE_SHELL
#define MY_SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define INPUT_LENGTH 1024
void display_prompt();
int main(void);
#endif