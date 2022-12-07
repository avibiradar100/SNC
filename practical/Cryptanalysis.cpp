#include<bits/stdc++.h>
using namespace std;

unordered_set<string> uset;


// Capitalize the string
void capitalize(string &str){
    for(char &c:str){
      if(c>=97 && c<=122)
        c-=32;
    }
}

int score(string text){

  string word="";
  int score=0;
  for(char &c:text){
    if(c==32){
        if(uset.find(word)!=uset.end())
           score++;
        word.clear();
        continue;
      }
      word.push_back(c);
    }
    if(uset.find(word)!=uset.end())
        score++;
    return score;
}

void decryptCrackit(string &cypherText){  
  
  string ans="";
  int maxScore=0;
  for(int i=0;i<26;i++){
    string tmp=cypherText;
    for(char &c:tmp){
      if(c==32)
        continue;
      c=((c-'A'-i+26)%26+'A');
    }
    if(score(tmp) > maxScore){
       maxScore=score(tmp);
       ans=tmp;
    }
    cout<<i<<": "<<tmp<<" "<<score(tmp)<<"\n";
  }

  cout<<"\n\nFinal output of crack the code:\n"<<ans<<endl;
}

string encrypt(string plainText,int pos){
   
   int n=plainText.size();
   for(int i=0;i<n;i++){
      if(plainText[i]==32)
        continue;
      if(plainText[i]>96 && plainText[i]<=122)
         plainText[i]-=32;
      plainText[i]+=pos;
      if(plainText[i]>90)
         plainText[i]=(plainText[i]%90+64);
   }
   cout<<"\nCypher Text :\n"<<plainText<<"\n\n";
   return plainText;
}


int main(){
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   
    string plainText;
    getline(cin,plainText);
    capitalize(plainText);
    int pos;
    cin>>pos;
    
    string cypherText=encrypt(plainText,pos);

    ifstream file;
    file.open ("words.txt");

    string word;
    while (file >> word){
      capitalize(word);
      uset.insert(word);
    }
    decryptCrackit(cypherText);

    return 0;
}