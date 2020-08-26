// https://www.acmicpc.net/problem/1339

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, Answer;
vector<string> Words;
vector<int> Alphabets;
bool Check[26];
int AtoI[26];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        Words.push_back(tmp);
        for (int j = 0; j < tmp.length(); j++) {
            if (!Check[tmp[j] - 'A']) {
                Check[tmp[j] - 'A'] = true;
                Alphabets.push_back(tmp[j] - 'A');
                K++;
            }
        }
    }
    vector<int> perm;
    for (int i = 10 - K; i <= 9; i++)
        perm.push_back(i);

    do {
        for (int i = 0; i < K; i++)
            AtoI[Alphabets[i]] = perm[i];
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int tmp = 0;
            for (int j = 0; j < Words[i].length(); j++) {
                tmp *= 10;
                tmp += AtoI[Words[i][j] - 'A'];
            }
            sum += tmp;
        }
        if (Answer < sum)
            Answer = sum;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << Answer << endl;
    return 0;
}
