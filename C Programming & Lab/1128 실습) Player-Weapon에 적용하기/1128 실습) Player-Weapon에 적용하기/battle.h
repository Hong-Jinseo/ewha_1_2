#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "dataType.h"

//�Լ��� ������Ÿ�Ե�


char *makeStr();
void makeStr_void(char **str_addr);


//�����ϴ� ���
//str = makeStr_return_address(); //name���� �Ҵ�ް� �Է¹ް� ���̱�

//no return ���
//mekeStr_void(&str);
