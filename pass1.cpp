#include<bits/stdc++.h>
using namespace std;

// This code is brought to you by Shreyas Joshi
// Always admire him in your heart
int main(){

    fstream input,ic,mnt,mdt,ala;
    input.open("input.txt",ios::in);
    ic.open("ic.txt",ios::out);
    mnt.open("mnt.txt",ios::out);
    mdt.open("mdt.txt",ios::out);
    ala.open("ala.txt",ios::out);
    
    string line;
    
    int mnt_ct = 0, mdt_ct = 0, ala_ct=0;
    bool is_macro = false;
    bool is_first = false;
    
    map<string,string>mp;
    
    while(getline(input,line)){
    	// line=line.substr(0,line.size()-1);
        if(line=="MACRO"){
            is_macro = true;
            is_first=true;
            continue;
        }
        if(is_macro == false){
        	ic<<line<<endl;
        }
        else{
       
        	if(is_first){
        	
        		mdt<< mdt_ct << "\t" << line << endl;
        		mdt_ct ++;
        	
        		string name = "";
        		for(char c:line){
        			if(c==' ')break;
        			name.push_back(c);
        		}
        		mnt<<mnt_ct<<"\t"<<name<<"\t"<<mdt_ct - 1<<endl;
        		mnt_ct++;
        		
        		ala<<"ALA for the macro "<<name<<": "<<endl;
        		ala_ct = 0;
        		mp.clear();
        		
        		int n = line.size();
        		line.push_back(',');
        		for(int i =0 ; i< n; i ++){
        			if(line[i]=='&'){
        				string s;
        				while(line[i]!=','){
        					s.push_back(line[i]);
        					i++;
        				}
        				
        				if(mp[s]!="")continue;
        				
        				ala<<ala_ct<<"\t"<<s<<endl;
        				ala_ct++;
        				
        				string s2 = to_string(ala_ct-1);
        				string s1 = "#" + s2;
        				mp[s]=s1;
        				
        			}
        		}
        		
        		is_first = false;
        		continue;
        	}
        	
        	
        	string L = "";
        	int n = line.size();
        	line.push_back(',');
        	for(int i =0 ; i< n ; i ++){
        		if(line[i]=='&'){
        			string s;
        			while(line[i]!=','){
        				s.push_back(line[i]);
        				i++;
        			}
        			L+=mp[s];
        			i--;
        		}
        		else{
        			L.push_back(line[i]);
        		}
        	}
        	
        	mdt<< mdt_ct << "\t" << L << endl;
        	mdt_ct ++;
        	
        	if(line=="MEND,"){
        		is_macro = false;
        	}
        }
    }
        
    input.close();
    ic.close();
    mnt.close();
    mdt.close();
    ala.close();
    return 0;
}
