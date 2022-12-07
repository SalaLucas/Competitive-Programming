int idx = 1;
int trie[MAX][26];
bool finish[MAX];
void addi(string s){
    int no = 0;
    for(int i =0;i<s.size();i++){
        if(trie[no][s[i]-'a'] == 0){
            trie[no][s[i]-'a'] = idx;
            idx++;
        }
        no = trie[no][s[i]-'a'];
        if(i == s.size()-1){
            finish[no] = 1;
        }
    }
}
int querie(string s){
    int no = 0;
    int ans =0;
    for(int i =0;i<s.size();i++){
        no = trie[no][s[i]-'a'];
    }
    return ans;
}