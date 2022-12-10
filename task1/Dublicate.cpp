#include <bits/stdc++.h>
using namespace std;

string ConvertString(string str)
{
    string result;
    char dub = ')', no_dub = '(';
    vector<char> dublicates;

    for (int i = 0; i <= str.length(); i++)
        for (int j = i + 1; j <= str.length() - 1; j++) 
        if (str[i] == str[j])
        {
            dublicates.push_back(str[i]);
            break;
        }

    for (char ch : str)
    {
        bool flag = false;
        for (char val : dublicates)
            if (ch == val) {
                flag = true;
                break;
            }
        flag ? result.push_back(dub) : result.push_back(no_dub);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str = "(( @";
    for_each(str.begin(),
             str.end(),
             [](char &c)
             {
                 c = ::tolower(static_cast<unsigned char>(c));
             });
    cout << str << endl;

    clock_t start = clock();

    str = ConvertString(str);
    cout << str << endl;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
