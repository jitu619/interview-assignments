class TreeDef{
public:
    char ch;
    int wordend;
    TreeDef *child[26];
    
    TreeDef(char c){
        ch=c;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        wordend=0;
    }
};

class WordDictionary {
public:
    TreeDef* root=NULL;
    WordDictionary() {
        root=new TreeDef('\0');
    }
    
    void addWord(string word) {
        TreeDef* curr=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new TreeDef(word[i]);
            }
            curr=curr->child[idx];
        }
        curr->wordend++;
    }
    
    bool search(string word) {
        TreeDef* curr=root;
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(curr->child[j]!=NULL){
                        string newWord=word.substr(i+1);
                        if(searchHelper(curr->child[j],newWord)==true){
                            return true;
                        }  
                    }
                }
                return false;
            }
            else{
                int idx=word[i]-'a';
                if(curr->child[idx]==NULL){
                    return false;
                }
                curr=curr->child[idx];
            }
            
            
        }
        return curr->wordend>0?true:false;
    }
    
    bool searchHelper(TreeDef *curr,string &word){
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(curr->child[j]!=NULL){
                        string newWord=word.substr(i+1);
                        if(searchHelper(curr->child[j],newWord)==true){
                            return true;
                        }  
                    }
                }
                return false;
            }
            else{
                int idx=word[i]-'a';
                if(curr->child[idx]==NULL){
                    return false;
                }
                curr=curr->child[idx];
            }
        }
        return curr->wordend>0?true:false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
