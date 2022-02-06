//by Małgorzata Kosakowska
#pragma once
#include "Player.h"
#include "Team.h"

using base = vector <Player>;
using list = vector<Team>;
using VDi = vector<int>;


void Add_to_base(Player, base&);
void Add_a_team(Team, list&);
void Add_to_team(base, int, base&);
base Choose_to_add(base&, list&, base&, Team&);
int Add_by_case(base&, list&, base&, base&);
base Add(list&, base&, Team&);


void Print(base);
void Show_a_team(list);
void Only_team_names(list);



void Save_Teams(string, list);
void Save(string, base);
int Read(string, base&);
int Load(base&);
int Files();



void Find(base&);
int Find_by_name(base&);
int Find_by_surname(base&);
int Find_by_age(base&);
int Find_by_position(base&);
int Find_to_Edit(base&);



void Delete(base&);
int Delete_by_name(base&);
int Delete_by_surname(base&);
int Delete_by_age(base&);
int Delete_by_position(base&);
void Delete_everyone(base&);



void Sort(base&);
void Sort_by_name(base&);
void Sort_by_surname(base&);
void Sort_by_age(base&);
void Sort_by_height(base&);




void Edit(base&);
void Random(base, int);
base Pos_check(base, int);
void Rand_Team(base);
void Rand_switch(base);
Player::Volley_position Interprate(string);
void Overwrite(string, list&, base);
int Check_pos(base, VDi, VDi);
base Ret_list_by_name(string, list);


int Full_program(list&, base&);
base Program(base&);
void Secure_cin();
void Clear();
