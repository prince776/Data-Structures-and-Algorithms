// KMP Pattern Searching Algorithm.
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string& pat, int lps[])
{
	int m = pat.size();
	lps[0] = 0; // always

	// length of the previous longest prefix siffix
	int len = 0;

	int i = 1;
	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len)
			{
				len = lps[len - 1];
			}else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string& text, string& pat)
{
	int n = text.size();
	int m = pat.size();

	int lps[m];
	computeLPSArray(pat, lps);

	int i = 0; // for text
	int j = 0; // for pat
	while (i < n)
	{
		if (pat[j] == text[i])
		{
			i++;
			j++;
		}
		if (j == m)
		{
			cout << "Patter found at: " << i - j << "\n";
			j = lps[j - 1];
		}

		else if (i < n && pat[j] != text[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}

	}

}

int32_t main()
{
	string text = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(text, pat);
	return 0;	
}