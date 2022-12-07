#include<bits/stdc++.h>
using namespace std;

// Capitalize the character
void capitalize(string &str){
    for(char &c:str){
      if(c>=97 && c<=122)
        c-=32;
    }
}

string encrypt(string &plainText,string &key){
   int n=key.size();
   int i=0;
   for(char &c:plainText){
       if(c>=65 && c<=90){
         int a=c-65;
         int b=key[i%n]-65;
         c=((a+b)%26+65);
         i++;
       }
   }
   return plainText;
}

string decrypt(string &cypherText,string &key){

   int n=key.size();
   int i=0;
   for(char &c:cypherText){
       if(c>=65 && c<=90){
         int a=c-65;
         int b=key[i%n]-65;
         c=(a-b+26)%26+65;
         i++;
       }
   }
   return cypherText;
}
 
int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    string key,plainText;
    getline(cin,plainText);

    // cout<<plainText<<endl;
    capitalize(plainText);
    getline(cin,key);
    capitalize(key);

    string CypherText=encrypt(plainText,key);
    cout<<"Cypher Text:"<<CypherText<<"\n\n";

    plainText=decrypt(CypherText,key);

    cout<<"Plain Text:"<<plainText<<endl;
    return  0;
}