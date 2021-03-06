#include<iostream>
#include<fstream>

using namespace std;

int dp[19000][19000];
//global aligner for finding the edit distance between every two strings
int aligner(string ref, string read){
    int n = ref.size();
    int m = read.size();
    int match = 0;
    int mismatch = 1;
    int gap_open = 1;
    for (int i = 0; i < n+1; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i < m+1; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++){
            if (ref[i-1] == read[j-1]){
                dp[j][i] = min(dp[j-1][i-1] + match, min(dp[j-1][i] + gap_open, dp[j][i-1] + gap_open));
            }
            if (ref[i-1] != read[j-1]){
                dp[j][i] = min(dp[j-1][i-1] + mismatch, min(dp[j-1][i] + gap_open, dp[j][i-1] + gap_open));
            }
        }
    }

    return dp[m][n];
}

int main() {
    string genome[5];
    string dict[] = {"Reston_genome", "Sudan_genome", "TaiForest_genome", "Zaire_genome", "Bundibugyo_genome"};
    string dict2[] = {"NP", "VP35", "VP40", "GP", "VP30", "VP24", "L"};
    for (int i = 0; i < 5; i++) {
        ifstream cin("BioProjectFiles/" + dict[i] + ".fasta");
        string s;
        cin >> s;
        cin >> s;
        while (cin >> s) {
            genome[i] += s;
        }
    }
    int alignes[5][5];
    ofstream cout("global.csv");
    for (int j = 0; j < 5; j++){
        cout<< dict[j];
        if(j != 4){
            cout<<",";
        }
    }
    cout<<endl;
	//call the global aligner for every two genome and save the edit distances
    for (int i = 0; i < 5; i++){
        for (int j = i+1; j < 5; j++){
            alignes[i][j] = aligner(genome[i], genome[j]);
            alignes[j][i] = aligner(genome[i], genome[j]);
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(i == j){
                cout<<0;
            }
            else{
                cout<<alignes[i][j];
            }
            if (j!=4){
                cout<<",";
            }
        }
        cout<<endl;
    }
}


