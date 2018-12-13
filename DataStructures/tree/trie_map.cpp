#include <bits/stdc++.h>

using namespace std;

struct Trie{
	bool isLeaf;
	unordered_map<char, Trie*> map;
};

Trie* getNewTrieNode(){
	Trie* node = new Trie();
	node->isLeaf = false;
	return node;
}

void insert(Trie*& head, string& str){
	if (head == nullptr) head = getNewTrieNode();
	Trie* curr = head;
	for(char c : str){
		if(curr -> map.find(c) == curr->map.end()){
			curr -> map[c] = getNewTrieNode();
		}
		curr = curr -> map[c];
	}
	curr->isLeaf = true;
}

bool search(Trie* head, string& str){
	if (head == nullptr) return false;
	Trie* curr = head;
	for(char c : str){
		curr = curr -> map[c];
		if(curr == NULL) return false;
	}
	return curr->isLeaf;
}

string helper = "";

void dfs(char addit, Trie* node, vector<string>& sugg){
	helper += addit;
	if(node -> isLeaf) sugg.push_back(helper);
	for(auto x : node -> map){
		dfs(x.first, x.second, sugg);
	}
	helper.pop_back();
}

vector<string> suggestions(Trie* head, string& pref){
	vector<string> sugg;
	if(head == nullptr) return sugg;
	Trie* curr = head;
	for(char c : pref){
		curr = curr -> map[c];
		if(curr == NULL) return sugg;
	}
	for(auto x : curr -> map){
		dfs(x.first, x.second, sugg);
	}	
	for(int i=0 ; i<sugg.size() ; i++) {
		sugg[i] = pref + sugg[i];
	}
	return sugg;
}

bool child(Trie const* curr){
	for (auto it : curr->map){
		if(it.second != NULL) return true;
	}
	return false;
}

int main(){
	Trie* head = nullptr;
	int n;
	cin>>n;
	string str;
	
	for(int i=0 ; i<n ; i++){
		cin>>str;
		insert(head,str);
	}

	for(int i=0 ; i<n ; i++){
		cin>>str;
		vector<string> sugg = suggestions(head, str);
		for(auto x : sugg) cout<<x<<endl;
	}

	return 0;
}