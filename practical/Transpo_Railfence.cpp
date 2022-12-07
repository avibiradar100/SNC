#include<bits/stdc++.h>
using namespace std;

// Capitalize the string
void capitalize(string &str){
    for(char &c:str){
      if(c>=97 && c<=122)
        c-=32;
    }
}

string encrypt(string &plaintext,int depth){
    
    int n=plaintext.size();
    vector<vector<char>> mat(depth,vector<char>(n,'*'));
 
    bool dirDown= false;
    int row = 0, col = 0;
 
    for (int i=0; i<n; i++)
    {
        if (row == 0 || row == depth-1)
            dirDown = !dirDown;
        mat[row][col++] = plaintext[i];
        dirDown?row++ : row--;
    }
 
    string ans;
    for (int i=0; i < depth; i++)
        for (int j=0; j <n; j++)
            if (mat[i][j]!='*')
                ans.push_back(mat[i][j]);
    return ans;
}

string decrypt(string &cypherText,int depth){

    int n=cypherText.size();
    vector<vector<char>> mat(depth,vector<char>(n,'#'));

    bool dirDown=false;
 
    int row=0, col=0;
    for (int i=0;i<n; i++)
    {
        if (row == 0 || row==depth-1)
          dirDown=!dirDown;
        mat[row][col++] = '*';
        dirDown?row++ : row--;
    }
 
    int index = 0;
    for (int i=0; i<depth; i++){
        for (int j=0; j<n; j++)
            if (mat[i][j] == '*' && index<n)
                mat[i][j] =cypherText[index++];
    }
 
    string ans;
    row = 0, col = 0;
    for (int i=0; i<n; i++)
    {
        if (row == 0)
            dirDown = true;
        if (row == depth-1)
            dirDown= false;
 
        if (mat[row][col] != '*')
            ans.push_back(mat[row][col++]);

        dirDown?row++: row--;
    }
    return ans;
}

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    string plainText;
    getline(cin,plainText);
    // cout<<plainText<<endl;
    capitalize(plainText);
    
    int depth;
    cin>>depth;

    string cypherText=encrypt(plainText,depth);

    cout<<"Cypher Text:\n"<<cypherText<<"\n\n";

    plainText=decrypt(cypherText,depth);

    cout<<"Plain Text:\n"<<plainText<<endl;

    return  0;
}