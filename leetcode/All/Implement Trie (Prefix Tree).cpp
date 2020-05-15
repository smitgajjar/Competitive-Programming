class Trie {
public:
    Trie* child[26];
    bool isLeaf;
    /** Initialize your data structure here. */
    Trie() {
        isLeaf=false;
        for(int i=0; i<26; i++)
            child[i]=NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* ptr = this;
        for(int i=0; i<word.length(); i++) {
            if(ptr->child[word[i]-'a']==NULL)
                ptr->child[word[i]-'a']=new Trie();
            ptr=ptr->child[word[i]-'a'];
        }
        ptr->isLeaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* ptr=this;
        
        for(int i=0; i<word.length(); i++) {
            if(ptr->child[word[i]-'a']==NULL)
                return false;
            ptr=ptr->child[word[i]-'a'];
        }
        if(ptr->isLeaf)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* ptr=this;
        
        for(int i=0; i<prefix.length(); i++) {
            if(ptr->child[prefix[i]-'a']==NULL)
                return false;
            ptr=ptr->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */