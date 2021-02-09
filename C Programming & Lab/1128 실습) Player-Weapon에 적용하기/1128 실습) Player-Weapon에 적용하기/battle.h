#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "dataType.h"

//함수의 프로토타입들


char *makeStr();
void makeStr_void(char **str_addr);


//리턴하는 방식
//str = makeStr_return_address(); //name공간 할당받고 입력받고 줄이기

//no return 방식
//mekeStr_void(&str);
