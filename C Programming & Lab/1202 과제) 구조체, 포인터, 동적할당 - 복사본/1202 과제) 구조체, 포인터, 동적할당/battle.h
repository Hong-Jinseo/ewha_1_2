#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "dataType.h"
#define MAX 10

//함수의 프로토타입들
int get_number(char *str);
int makePlayers(Player **p_addr);
int *makeWeapons(Weapon **w_addr);
int makeName(char **name_addr);
void setPlayer(Player *p);
void setWeapon(Weapon *p);
void showPlayer(Player *p,Weapon *w, int playerNum, int weaponNum);
void attack(Player hunter,Player *target);
void showPlayersHp(Player p1, Player p2);