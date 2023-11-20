#include<bits/stdc++.h>
using namespace std;

// This code is presented to you by Shreyas Joshi
// Suck his cock

int main(){
    fstream mnt,ic,pass2;
    mnt.open("mnt.txt",ios::in);
    ic.open("ic.txt",ios::in);
    
    pass2.open("pass2.txt",ios::out);
    string line;
    
    map<string,int>is_macro;
    map<string,int>index;

    while(getline(mnt,line)){
    	
    	int n = line.size();
    	
    	string name;
    	for(int i =2;i<n;i++){
    		if(line[i]=='\t')break;
    		name.push_back(line[i]);
    	}
    	is_macro[name]=1;
    	
    	string ind;
    	for(int i = n-1;i>=0;i--){
    		if(line[i]=='\t')break;
    		ind.push_back(line[i]);
    	}
    	reverse(ind.begin(),ind.end());
    	int x = stoi(ind);
    	
    	index[name]=x;
    }
    
    
    while(getline(ic,line)){
    	int n = line.size();
    	string first;
		int j=0;
    	for(int i =0 ; i< n ; i ++){
    		if(line[i]==' '){
    		   j=i;
    			break;
    		}
    		else first.push_back(line[i]);
    	}
    	
    	if(is_macro[first]==0){
    		pass2<<line<<endl;continue;
    	}
    	else{
    		int ind = index[first];
    		
			string temp;int num=0;
			map<int,string>mp;
			for(int i=j+1;i<n;i++){
				if(line[i]==','){mp[num]=temp;num++;temp="";continue;}
				temp.push_back(line[i]);
				if(i==n-1){
					mp[num]=temp;num++;
				}
				
			}
			
			fstream mdt;
    		mdt.open("mdt.txt",ios::in);
    		
    		string mdt_line;
    		for(int i = 0;i<ind;i++){getline(mdt,mdt_line);}
    		
    		while(getline(mdt,mdt_line)){
    			int m = mdt_line.size();
    			for(int i =0 ; i < m ; i ++){
    				if(mdt_line[i]=='\t'){
    					mdt_line=mdt_line.substr(i+1,m-(i+1));break;
    				}
    			}
    			m=mdt_line.size();
    			if(mdt_line=="MEND")break;
    			
    			string L;
    			for(int i=0;i<m;i++){
    				if(mdt_line[i]!='#'){
    					L.push_back(mdt_line[i]);
    				}
    				else{
    					i++;
    					string temp;
    					while(i<m && mdt_line[i]>='0' && mdt_line[i]<='9'){
    						temp.push_back(mdt_line[i]);
    						i++;
    					}
    					int x = stoi(temp);
    					string s = mp[x];
    					
    					L+=s;
    				}
    			}
    			pass2<<L<<endl;
    		}		
    		mdt.close();
    	}
    }
    
    mnt.close();
    
    pass2.close();
    ic.close();
    return 0;
}
