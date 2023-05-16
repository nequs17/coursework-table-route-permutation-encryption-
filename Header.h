#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define COLS 6

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <TCHAR.H>
#include <stdbool.h>
#include <math.h>

bool decrypto(int ROWS);
int encrypto(int ROWS, wchar_t temp[]);