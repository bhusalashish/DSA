/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
https://leetcode.com/problems/jump-game/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
auto speedup = [](){
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
    for(size_t i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout<<endl;
}
template<typename T>
void print(vector<T> &vec){
	for(T &element : vec)
		cout<<element<<" ";
	cout<<endl;
}
template<typename T>
void print(vector<vector<T> > &vec){
	for(auto elements : vec){
		for(T &element : elements)
			cout<<element<<" ";
		cout<<endl;
	}
}

template<typename T>
void print(unordered_set<T> &uset){
	for(auto it : uset)
		cout<<it<<" ";
	cout<<endl;
}
template<typename T1, typename T2>
void print(unordered_map<T1, T2> &umap){
	for(auto it : umap)
		cout<<it.first<<" -> "<<it.second<<"\n";
}

bool canJump(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return true;
    int jumps[len];
    for(int &jump : jumps)
        jump = INT_MAX;
    jumps[0] = 0;
    for(int i=1; i<len; ++i){
        for(int j=0; j<i; ++j){
            if(jumps[j] != INT_MAX && (i <= (nums[j]+j))){
                jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
    }
    return jumps[len-1] != INT_MAX;
}

int minJump(vector<int> &nums){
	int len = nums.size();
	if(len < 2) return 0;
	int dp[len] = {0};
	fill(dp+1, dp+len, INT_MAX);
	for(int i=1; i<len; ++i){
		for(int j=0; j<i; ++j){
			if(dp[j] != INT_MAX && j+nums[i] >= i){
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}
	// print(dp, len);
	// vector<vector<int>> v(10, vector<int>(10, 10));
	print(nums);
	return dp[len-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> nums(n);
		for(int &num : nums) cin>>num;
		cout<<minJump(nums)<<endl;
	}
	return 0;
}
