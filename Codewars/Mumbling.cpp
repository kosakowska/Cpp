//Mumbling

class Accumul
{
public:
    static std::string accum(const std::string& s);
};
std::string Accumul::accum(const std::string& s)
{
    std::string a = s;
    std::string temp;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0)temp += toupper(a[i]);
            else temp += tolower(a[i]);
        }
        if(i!=a.size()-1) temp += '-';
    }
    return temp;
}
