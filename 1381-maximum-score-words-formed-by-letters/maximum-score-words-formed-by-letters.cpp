class Solution {
public:

    int scoree(string s,vector<int>& score){
        int size=s.size();
        int ans=0;
        for(int i=0; i<size;i++){
            ans+=score[s[i]-'a'];
        }
        return ans;
    }

    bool possible(string s, vector<int> letter){
        for(int i=0; i<s.size(); i++){
            if(letter[s[i]-'a']==0){
                return false;
            }
            letter[s[i]-'a']--;
        }
        return true;
    }

    int maxScoreWords_helper(vector<string>& words, vector<int> letter, vector<int>& score, int index){
        int size=words.size();
        if(index==words.size()){
            return 0;
        }

        int notTake=maxScoreWords_helper(words,letter,score,index+1);
        int take=0;
        if(possible(words[index],letter)){
            for(int i=0; i<words[index].size(); i++){
                letter[words[index][i]-'a']--;
            }

            take=scoree(words[index],score) + maxScoreWords_helper(words,letter,score,index+1);
        }

        return max(take,notTake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int index=0;
        int size=words.size();
        vector<int> letter(26,0);
        for(int i=0; i<letters.size(); i++){
            int index=letters[i]-'a';
            letter[index]++;
        }
        return maxScoreWords_helper(words,letter,score,index);
    }
};