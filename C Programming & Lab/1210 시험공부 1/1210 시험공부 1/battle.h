#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "dataType.h"

int get_number(char *str);
int mallocPlayer(Player **par,int n);
void enter_information2(Player *p,int n);
void enter_weapon(Weapon *w);
void show_information2(Player *p,int n);
void show_start();
void attack(Player hunter,Player *target);
int find_min(Player *p,int n);
void find_loser(Player* p,int n);