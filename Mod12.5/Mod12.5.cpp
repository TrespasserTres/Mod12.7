#include<iostream>
#include <string>
using namespace std;
#pragma runtime_checks( "", off )
#pragma warning( push )
#pragma warning( disable : 4700 )

void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(const string& pat, const string& txt, int K)
{
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);
    int a = 0;
    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size() && (i != j) && (((txt.size()) % i) == 0) && (j == K))
        {
            a++;
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) 
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return a;
}

void IsKPeriodic(string txt, int K)
{
    int kn = 0;
    string pat;
    for (int i = 1; i < txt.size(); i++)
    {
        for (int j = 0; j < i; j++)
         pat += txt[j];
        if (KMPSearch(pat, txt, K) > 0)
            kn++;
        pat = "";
    }
    if (kn > 0)
    cout << "True" << endl;
    else cout << "False" << endl;
}

int main()
{
    string Str1;
    int K;
    int c;
    bool menu = true;
    while (menu)
    {
        cout << "1 - Start; 2 - Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "enter string" << endl;
            cin >> Str1;
            cout << "enter K" << endl;
            cin >> K;
            IsKPeriodic(Str1, K);
            break;
        case 2:
            menu = false;
            break;
        }
    }
    return 0;
}