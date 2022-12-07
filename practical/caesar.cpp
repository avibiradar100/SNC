// Implementation of Ceasor Cypher
#include<iostream>
using namespace std;

string encrypt(string plainText,int pos){
   
   int n=plainText.size();
   for(int i=0;i<n;i++){
      if(plainText[i]==32)
        continue;
      if(plainText[i]>96 && plainText[i]<=122)
         plainText[i]-=32;
      plainText[i]=(plainText[i]-'A'+pos)%26+'A';
   }
   cout<<"\nCypher Text :"<<plainText<<endl;
   return plainText;
}

void decrypt(string cypherText,int pos){
   int n=cypherText.size();
   for(int i=0;i<n;i++){
      if(cypherText[i]==32)
        continue;
      cypherText[i]=(cypherText[i]-'A'-pos+26)%26+'A';
   }
   cout<<"\nPlain Text :"<<cypherText<<endl;
}

int main(){
   int pos;
   
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   string plain_text;
   getline(cin,plain_text);

   // cout<<"Plain text:"<<plain_text<<endl;
   cin>>pos;

   string cypher_text=encrypt(plain_text,pos);
   decrypt(cypher_text,pos);
}