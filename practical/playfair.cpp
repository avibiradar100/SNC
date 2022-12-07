#include<bits/stdc++.h>
using namespace std;
map<char,pair<int,int>> charPos;

// Capitalize the character
void capitalize(string &str){
 
    for(char &c:str){
      if(c>=97 && c<=122)
        c-=32;
    }
}
 
// add char pairs to the set
void addToSet(vector<pair<char,char>> &v,char a,char b){
    v.push_back({a,b});
}

// build matrix
void buildMatrix(vector<vector<char>> &mat,string key){

    vector<bool>vis(26,false);

    int i=0,j=0;
    for(int k=0;k<key.length();k++){

        if(!vis[key[k]-65]){
            mat[i][j]=key[k];
            if(key[k]=='I'||key[k]=='J'){
                vis['I'-65]=true;
                vis['J'-65]=true;
            }
           else vis[key[k]-65]=true;
           j++;
           if(j==5){
              j%=5;
             i++;
          }
        }

    }
    for(int k=0;k<26;k++){

        if(!vis[k]){
            if(k+'A'=='I'||k+'A'=='J'){
                vis['I'-65]=true;
                vis['J'-65]=true;
            }
            mat[i][j]=k+'A';
            j++;
           if(j==5){
             j%=5;
             i++;
            }
        }

    }
    // cout<<"\n \nMatrix:\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }
}

void encrypt(vector<vector<char>> &mat,vector<pair<char,char>> &pairSet){
    
    // storing position of chars in the matrix
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++)
        if(mat[i][j]=='I' || mat[i][j]=='J')
          charPos['J']=charPos['I']=make_pair(i,j);
        else
          charPos[mat[i][j]]=make_pair(i,j);
    }

    // print 
    cout<<"\n";
    // cout<<"Plain Text:";
    for(auto it:pairSet)
      cout<<it.first<<it.second<<" ";
    cout<<endl;
   
    // cout<<"Cypher Text: ";
    for(auto &it:pairSet){
       int i1=charPos[it.first].first;
       int j1=charPos[it.first].second;
       int i2=charPos[it.second].first;
       int j2=charPos[it.second].second;
      
       if(i1==i2){
        it.first=mat[i1][(j1+1)%5];
        it.second=mat[i1][(j2+1)%5];
        cout<<mat[i1][(j1+1)%5]<<mat[i1][(j2+1)%5]<<" ";
       }
       else if(j1==j2){
        it.first=mat[(i1+1)%5][j1];
        it.second=mat[(i2+1)%5][j2];
        cout<<mat[(i1+1)%5][j1]<<mat[(i2+1)%5][j2]<<" ";
       }
       else{
        it.first=mat[i1][j2];
        it.second=mat[i2][j1];
        cout<<mat[i1][j2]<<mat[i2][j1]<<" ";
       }
          
    }
    cout<<"\n\n";
}

void decrypt(vector<vector<char>> &mat,vector<pair<char,char>> &pairSet){
    
    // print 
    // for(auto it:charPos)
    //   cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    // cout<<endl;

    // cout<<"Plain Text: ";
    for(auto it:pairSet){
       int i1=charPos[it.first].first;
       int j1=charPos[it.first].second;
       int i2=charPos[it.second].first;
       int j2=charPos[it.second].second;
       
      //  cout<<i1<<j1<<" "<<i2<<j2<<endl;

       if(i1==i2){
        cout<<mat[i1][((j1-1)+5)%5]<<mat[i1][((j2-1)+5)%5]<<" ";
       }
       else if(j1==j2){
        cout<<mat[((i1-1)+5)%5][j1]<<mat[((i2-1)+5)%5][j2]<<" ";
       }
       else{
        cout<<mat[i1][j2]<<mat[i2][j1]<<" ";
       }
          
    }
}

int main(){

   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

    
    string tmp,key,plainText;
    vector<pair<char,char>> pairSet;

    getline(cin,tmp);

    for(char c:tmp){
      if(c!=32)
        plainText.push_back(c);
    }
     
    // cout<<plainText<<endl;
    capitalize(plainText);

    string key1;
    getline(cin,key1);

    for(char c:key1){
      if(c!=32)
        key.push_back(c);
    }
 
    capitalize(key);
    
    // cout<<key<<endl;

    int n=plainText.size();
    for(int i=0;i<n;){
       char a=plainText[i];
       if(i==n-1 || plainText[i+1]==a){
         addToSet(pairSet,a,'X');  // added if x as dummy for same chars
         i++;
       }
       else{
         addToSet(pairSet,a,plainText[i+1]);
         i+=2;
       }
    }
  // breaking the plain text into 2chars 
  // for(auto it:pairSet)
  //   cout<<it.first<<it.second<<" ";

  // build matrix
  vector<vector<char>> mat(5,vector<char>(5));
  buildMatrix(mat,key);
   
  // Encrypt the text
  // cout<<"Encryption\n";
  encrypt(mat,pairSet);

  // Decrypt the Cypher Text
  // cout<<"Decryption\n";
  decrypt(mat,pairSet);
}