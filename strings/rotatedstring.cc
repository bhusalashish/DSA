https : //www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
#include <bits/stdc++.h>
        using namespace std;
#define ll long long
typedef pair<int, int> pi;
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    return 0;
}();
template <typename T1, typename T2>
void print(const T1 array[], T2 size)
{
    for (size_t i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
template <typename T>
void print(vector<T> &vec)
{
    for (T &element : vec)
        cout << element << " ";
    cout << endl;
}
template <typename T>
void print(vector<vector<T>> &vec)
{
    for (auto &elements : vec)
    {
        for (T &element : elements)
            cout << element << " ";
        cout << endl;
    }
}
template <typename T>
void print(set<T> &set)
{
    for (auto it : set)
        cout << it << " ";
    cout << endl;
}
template <typename T1, typename T2>
void print(map<T1, T2> &map)
{
    for (auto it : map)
        cout << it.first << " -> " << it.second << "\n";
}
template <typename T>
void print(unordered_set<T> &uset)
{
    for (auto it : uset)
        cout << it << " ";
    cout << endl;
}
template <typename T1, typename T2>
void print(unordered_map<T1, T2> &umap)
{
    for (auto it : umap)
        cout << it.first << " -> " << it.second << "\n";
}
int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.size() != str2.size())
        {
            cout << "No\n";
        }
        else
        {
            string temp = str1 + str1;
            if (temp.find(str2) != string::npos)
                cout << "Yes\n";
            else
            {
                cout << "No\n";
            }
        }
    }
}