// Author :: Sravan Kumar

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include<iostream>
#include<unordered_map>
using namespace std;

struct TrieNode{
     char c;
     int wordEnd,count;
     unordered_map<char,TrieNode*> child;
     TrieNode(char a): child(26,NULL) , c(a) , wordEnd(0),count(0) {  }
};
class trie{
     TrieNode *root;

     TrieNode* find(const string &s){
          TrieNode *temp=root;
      for(int i=0;s[i] && temp!=NULL;i++){
     int ind=s[i]-'a';
     temp=temp->child[ind];
       } 
     return temp;
     }

      bool isLastNode(TrieNode* root){
     for(int i=0;i<26;i++){
          if(root->child[i]) return false;
     }
     return true;
    }

 void autoSuggestionsRec(TrieNode* temp,string prefix,vector<string> &v){
     if(temp==NULL) return;
     if(temp->wordEnd>0){
         v.push_back(prefix);
     }
     if(isLastNode(temp)) return;
     for(int i=0;i<26;i++){
          if(temp->child[i]){
    string s=prefix+char('a'+i);
     autoSuggestionsRec(temp->child[i],s,v);
     }
     }
   }

public:
 trie(){
   root=new TrieNode('_');
 }
 void insert(const string &s){
     int n=s.size();
     TrieNode *temp=root;
  for(int i=0;s[i];i++){
     int ind=s[i]-'a';
     if(temp->child[ind]==NULL){
          temp->child[ind]=new TrieNode(s[i]);
     }
      temp=temp->child[ind];
      temp->count++;
      
  }
  temp->wordEnd+=1;
 }
 void remove(const string &s){
  TrieNode *temp;
    temp=find(s);
    try{
         if(temp==NULL or temp->wordEnd==0) throw s;
    }
    catch(string e){
         cout<<"No such word : "<<e<<"\n";
         return ;
    }
    temp->wordEnd=min(0,temp->wordEnd-1);
 }
 int prefixCount(const string &s){
  TrieNode *temp;
    temp=find(s);
    try{
         if(temp==NULL) throw s;
    }
    catch(string e){
         cout<<"No such word : "<<e<<"\n";
         return 0;
    }
    return temp->count;
 }
 bool search(const string &s){
     TrieNode *temp;
    temp=find(s);
    try{
         if(temp==NULL or temp->wordEnd==0) throw s;
    }
    catch(string e){
         cout<<"No such word : "<<e<<"\n";
         return false;
    }
   return  true;
 }

 void autoSuggestions(const string prefix, vector<string> &v){
  TrieNode* temp=find(prefix);
  autoSuggestionsRec(temp,prefix,v);
 }
};



#endif
