#pragma once

typedef struct weapon{
	char *name;
	int power;
}Weapon;

typedef struct palyer{
	char *name;
	Weapon *w;
	int power;
	int defensivePower;
	int hp;
}Player;