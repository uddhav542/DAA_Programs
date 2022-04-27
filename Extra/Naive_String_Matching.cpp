// C++ program for Naive Pattern 
// Searching algorithm 
#include <bits/stdc++.h> 
using namespace std; 

void search(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
                << i << endl; 
    } 
} 

// Driver Code 
int main() 
{ 
	cout<<"Enter Full String:";
	string txt;
	cout<<"Enter String to be Matched:";
	cin>>txt;
	string pat;
	cin>>pat;
//    char txt[] = "AABAACAADAABAAABAA"; 
//    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
}
