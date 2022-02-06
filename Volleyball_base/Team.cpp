//by Małgorzata Kosakowska
#include "Team.h"

string Team::Get_name() const { return name; }
base Team::Get_list() const { return list; }

void Team::Set_name(string n) { name = n; }
void Team::Set_list(base l) { list = l; }
