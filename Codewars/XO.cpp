//Exes and Ohs

bool XO(const std::string& str)
{
    int licz_x = 0;
    int licz_o = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'x'||str[i]=='X') licz_x++;
        if (str[i] == 'o'||str[i]=='O') licz_o++;
    }
    if (licz_x == licz_o)return true;
    else
        return false;
}
