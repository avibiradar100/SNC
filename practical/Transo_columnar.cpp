#include<bits/stdc++.h>
using namespace std;

// Capitalize the string
void capitalize(string &str){
    for(char &c:str){
      if(c>=97 && c<=122)
        c-=32;
    }
}

string encrypt(int n,int m,string &plaintext,vector<int> &key){

 vector<vector<char>> mat(n,vector<char>(m));

    int k=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(k>=plaintext.size())
          mat[i][j]=32;
        else
          mat[i][j]=plaintext[k++];
      }
    }

    // Matrix 
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mat[i][j]!=32)
            cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }

    string cypherText="";
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(mat[j][key[i]-1]!=32)
            cypherText.push_back(mat[j][key[i]-1]);
      }
    }
    return cypherText;
}

string decrypt(int m,string &cypherText,vector<int> key){

 int n=(cypherText.size()/m)+1;

 vector<vector<char>> mat(n,vector<char>(m));

    int k=0;
    string plainText="";
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
            if(j==n-1 && key[i]-1>=(cypherText.size()%m))
              mat[j][key[i]-1]=32;
            else
              mat[j][key[i]-1]=cypherText[k++];
      }
    }

     // Matrix 
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mat[i][j]!=32)
            cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(mat[i][j]!=32)
            plainText.push_back(mat[i][j]);
      }
    }

    return plainText;
}

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string plainText;
    getline(cin,plainText); 

    int m;
    cin>>m;

    vector<int> key(m);

    for(int i=0;i<m;i++)
       cin>>key[i];
     
    
    capitalize(plainText);
    string tmp="";

    for(char c:plainText){
      if(c!=32)
        tmp.push_back(c);
    }

    int n=(tmp.size()/m)+1;

    string Cyphertext=encrypt(n,m,tmp,key);
    
    cout<<"CypherText:"<<Cyphertext<<"\n\n";
    
    plainText=decrypt(m,Cyphertext,key);
    cout<<"plainText:"<<plainText<<"\n";

    return  0;
}