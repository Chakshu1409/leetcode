class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal = false;

    bool contains(char ch) { return children[ch - 'a'] != NULL; }
};

class Trie {
public:
TrieNode* root;


    
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                node->children[word[i] - 'a'] = new TrieNode();
            } 
                node = node->children[word[i] - 'a'];
            
        }
        node->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                return false;
            } else {
                node = node->children[word[i] - 'a'];
            }
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->contains(prefix[i])) {
                return false;
            } else {
                node = node->children[prefix[i] - 'a'];
            }
        }
        return true;
    }
};
class Solution {
public:
    void helper(string s, Trie& trie, int index, string current, vector<string>& ans){
        if(index==s.size()){
            ans.push_back(current);
            return;
        }
        TrieNode* temp=trie.root;
        while(index<s.size()){
            if(temp->children[s[index]-'a'] != NULL){
                temp=temp->children[s[index]-'a'];
                current+=s[index];
                if(temp->isTerminal){
                    if(index==s.size()-1){
                        ans.push_back(current);
                        return;
                    }
                    helper(s,trie,index+1,current+" ",ans);
                }
            }
            else{
                break;
            }
            index++;
        }
        // if(index==s.size()){

        // }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i=0; i<wordDict.size(); i++){
            trie.insert(wordDict[i]);
        }
        vector<string> ans;
        string current="";
        int index=0;
        helper(s,trie,index,current,ans);
        return ans;
    }
};