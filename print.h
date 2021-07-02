// Author :: Sravan Kumar

#ifndef PRINT_H
#define PRINT_H

#include<iostream>
#include<vector>
#include<map>
#include<set>


template<typename T>
std::ostream &operator<<(std:: ostream &output, std::vector<T> v) { 
     int n=v.size();
         output<<"[";
         for(int i=0;i<n-1;i++)
         output<<v[i]<<",";
         output<<v[n-1]<<"]";
         return output;            
      }
template<typename T>
std::ostream &operator<<( std::ostream &output, std::set<T> s) { 
      auto it=s.end();
       it--;
         output<<"[";
         for(auto i=begin(s);i!=it;i++)
         output<<*i<<",";
         output<<*it<<"]";
         return output;            
      }
template<typename T1,typename T2>
std::ostream &operator<<( std::ostream &output, std::map<T1,T2> m) { 
      auto it=m.end();
       it--;
         output<<"[";
         for(auto i=begin(m);i!=it;i++)
         output<<"["<<(*i).first<<","<<(*i).second<<"],";
         output<<"["<<(*it).first<<","<<(*it).second<<"]]";
         return output;            
      }      
 template<std::size_t n>
std::ostream &operator<<( std::ostream &output, int (&v)[n]) { 
         output<<"[";
         for(int i=0;i<n-1;i++)
         output<<v[i]<<",";
         output<<v[n-1]<<"]";
         return output;            
      }     
template<typename T>
std::ostream &operator<<( std::ostream &output, std::vector<std::vector<T>> v) { 
     int n=v.size(),m=v[0].size();
         output<<"[";
         for(int i=0;i<n-1;i++){
               output<<"[";
              for(int j=0;j<m;j++){
              output<<v[i][j]<<",";
              }
               output<<"],";
         }
          output<<"[";
         for(int j=0;j<m;j++)
         output<<v[n-1][j]<<",";
         output<<"]]";
         return output;            
      }

      #endif