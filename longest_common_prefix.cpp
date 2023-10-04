class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }

};

class Trie{
    TrieNode* root;
    public:

    Trie(){
        root= new TrieNode('X');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child,word.substr(1));
    }

    void insert(string word){
        insertUtil(root,word);
    }


    void find(string s,string &answer){
        int n = s.length();

        for(int i=0;i<n;i++){
            char ch = s[i];
            int index = ch - 'a';
            if(root->childCount==1){
                answer.push_back(ch);
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal)
                break;
            
        }
        return;
    }


};



string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here


    //Brute force approach is better than trie

    // string answer = "";
    // int m = arr[0].size();
    // for(int i=0;i<m;i++){
    //     char c = arr[0][i];
    //     bool check = true;
    //     for(int j=1;j<n;j++){
    //         int s = arr[j].size();
    //         if(i>=s){
    //             check = false;
    //             break;
    //         }
    //         else{
    //             if(arr[j][i]!=c){
    //                 check = false;
    //                 break;
    //             }
    //         }
    //     }
    //     if(check==false){
    //         return answer;
    //     }
    //     else{
    //         answer = answer + c;
    //     }
    // }
    // return answer;

    Trie t;
    for(int i=0;i<n;i++){
        t.insert(arr[i]);
    }
    string answer;
    t.find(arr[0],answer);
    return answer;
}


