#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <fstream> 
#include <bits/stdc++.h> 

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();

class head_tail_value{
	public:
		string head;
		string tail;
		int value;
};

bool cmp(head_tail_value a, head_tail_value b) {
	if(a.value < b.value)
		return a.value < b.value;
	else
		return a.value > b.value;
}

int Degree(string a){
	int count = 0;
	Edge *ptr_e = nm->elist;
	while(ptr_e!=NULL){
		if(ptr_e->head->name == a)
			count++;
		else if(ptr_e->tail->name == a)
			count--;
		ptr_e = ptr_e->next;		
	}
	return count;
}
	
int find_min_weight(string a, string b){
	int weight=0;
//	vector<vector<head_tail_value>> P(20);
//	head_tail_value A;
	vector <int> W;
	Path *path;
	path=new Path();
	path->append(nm->elist);
	vector<vector<Edge *>> aaaa(path->find_paths(a,b));
	//path->find_paths(a,b);
//	cout << aaaa.size()<<"  aaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;	
	for(int i=0;i<path->paths.size();i++){
		for(int j=0;j<path->paths[i].size();j++){
			Edge *e = nm->get_edge(path->paths[i][j]->head->name, path->paths[i][j]->tail->name);
			
//			cout << "Edge`"<< path->paths[i][j]->head->name << "<->" << path->paths[i][j]->tail->name << "`=>[cap:" 
//					<< e->cap << ",val:" << e->flowval << "]  ";
			weight = weight + path->paths[i][j]->flowval;
/*			A.head = path->paths[i][j]->head->name;
			A.tail = path->paths[i][j]->tail->name;
			A.value = 0;
			P[i].push_back(A);
*/
		}
		W.push_back(weight); 
//		cout<<endl;
//		cout<<W[i]<<endl;
		weight = 0;
	}
	vector<int>::iterator iter = min_element(W.begin(), W.end());
	weight = *iter;
//	int size = distance(W.begin(), iter);
//	for(int j=0;j<P[size].size();j++)
//		cout<< P[size][j].head<< " " <<P[size][j].tail<<" "<<endl;
	
//	cout<< "min_path_weight:" <<weight<<endl<<endl;
/*	
	cout<<"1233"<<endl;
		for(int j=0;j<path->paths[size].size();j++){
			cout<< P[size][j].head << " "<<P[size][j].tail<<endl;
		}
	cout<<"3211"<<endl;
*/	
	return weight;
}

vector<string> printCircuit(vector< vector<int> > ABC){
    unordered_map<int,int> edge_count; 
  
    for (int i=0; i<ABC.size(); i++){
        edge_count[i] = ABC[i].size(); 
    } 
/*  
    if (!ABC.size()) 
        return 0;
*/
    stack<int> curr_path; 
    vector<int> circuit;
    curr_path.push(0); 
    int curr_v = 0;
  
    while (!curr_path.empty()){
        if (edge_count[curr_v]){ 
            curr_path.push(curr_v); 
  
            int next_v = ABC[curr_v].back(); 
  
            edge_count[curr_v]--; 
            ABC[curr_v].pop_back(); 
  
            curr_v = next_v; 
        } 
        else{ 
            circuit.push_back(curr_v); 
            curr_v = curr_path.top(); 
            curr_path.pop(); 
        } 
    } 
	string A;
	vector<string> B;
    for (int i=circuit.size()-1; i>=0; i--){ 
		if(circuit[i]==0)	A="a";
		if(circuit[i]==1)	A="b";
		if(circuit[i]==2)	A="c";
		if(circuit[i]==3)	A="d";
		if(circuit[i]==4)	A="e";
		if(circuit[i]==5)	A="f";
		if(circuit[i]==6)	A="g";
		if(circuit[i]==7)	A="h";
		if(circuit[i]==8)	A="i";
		if(circuit[i]==9)	A="j";
		if(circuit[i]==10)	A="k";
		if(circuit[i]==11)	A="l";
		if(circuit[i]==12)	A="m";
		if(circuit[i]==13)	A="n";
		if(circuit[i]==14)	A="o";
		if(circuit[i]==15)	A="p";
		if(circuit[i]==16)	A="q";
		if(circuit[i]==17)	A="r";
		if(circuit[i]==18)	A="s";
		if(circuit[i]==19)	A="t";
		if(circuit[i]==20)	A="u";
		if(circuit[i]==21)	A="v";
		if(circuit[i]==22)	A="w";
		if(circuit[i]==23)	A="x";
		if(circuit[i]==24)	A="y";
		if(circuit[i]==25)	A="z";
        cout << A; 
		B.push_back(A);
        if (i) 
           cout<<" -> "; 
    }
	return B;
}

int main(int argc, char** argv){
	
	nm->interpret("topo.txt");
    nm->print_all_e();
	nm->print_all_v();
	
	//calculate all nodes degree
	Vertex *ptr_v = nm->get_all_nodes(); 
	vector <string> pos;
	vector <string> neg;
	
	while(ptr_v!=NULL){
		if(Degree(ptr_v->name) > 0){
			for(int i=0;i<Degree(ptr_v->name);i++)
				pos.push_back(ptr_v->name);
		}
		else if(Degree(ptr_v->name) < 0){
			for(int i=0;i<-Degree(ptr_v->name);i++)
				neg.push_back(ptr_v->name);
		}
		cout<<ptr_v->name<<" degrees : "<<Degree(ptr_v->name)<<endl;
		ptr_v = ptr_v->next;
	}
	cout << "positive degree:" ;
	for(int i=0;i<pos.size();i++)
		cout << pos[i] << " " ;
	cout << endl;
	cout << "negative degree:";
	for(int j=0;j<neg.size();j++)
		cout << neg[j] << " " ;
	cout << endl;

	Path *path;
	path=new Path();
	path->append(nm->elist);
//	path->find_paths("2","0");
//	path->debug();

	vector <int> value;
/*	
	for(int i=0;i<pos.size();i++){
		for(int j=0;j<neg.size();j++){
			find_min_weight(neg[j], pos[i]);
//			value.push_back(find_min_weight(neg[j], pos[i]));
		}
	}
*/	
//	find_min_weight("f","b");



	int val=0;
	head_tail_value a_;
	int count=0;	//how many kinds of permutation
	vector<vector<head_tail_value>> min(30);

	
	do{
		for(int i=0;i<neg.size();i++){
			val = find_min_weight(neg[i], pos[i]);
//			cout << neg.size() << endl << pos.size() << endl;
			a_.head = neg[i];
							

			a_.tail = pos[i];
			a_.value = val;
//			cout<< a_.head << " "<<a_.tail<<" "<<a_.value <<endl;
			min[count].push_back(a_);
		}
		a_.value = 0;
		for(int i=0;i<neg.size();i++)
			a_.value = a_.value + min[count][i].value;
		min[count].push_back(a_);
		val = 0;
		count++;
	}
	while (next_permutation(neg.begin(),neg.end()));  
	
	if(prev_permutation(neg.begin(),neg.end())){
		do{
		for(int i=0;i<neg.size();i++){
			val = find_min_weight(neg[i], pos[i]);
			a_.head = neg[i];
			a_.tail = pos[i];
			a_.value = val;
//			cout<< A.head << " "<<A.tail<<" "<<A.value <<endl;
			min[count].push_back(a_);
		}
		a_.value = 0;
		for(int i=0;i<neg.size();i++)
			a_.value = a_.value + min[count][i].value;
		min[count].push_back(a_);
		val = 0;
		count++;
		} 
		while (prev_permutation(neg.begin(),neg.end())); 	
	}
	
	for(int i=0;i<count;i++){
		for(int j=0;j<min[i].size();j++)
			cout<<min[i][j].head<<" "<<min[i][j].tail<<" "<<min[i][j].value<<"   ";
			cout<<endl;
	}
	cout<<endl;
//	cout<<min.size()<<endl;
	head_tail_value MIN;
	int count_i=0;
	
	//------------------
	//	compare minimum	
	//------------------
	if(min[1].size()!=0){
		if(min[0][min[0].size()-1].value <= min[1][min[1].size()-1].value){
			MIN = min[0][min[0].size()-1];
			count_i = 0;
			}
		else {
			MIN = min[1][min[1].size()-1];
			count_i = 1;
		}
		for(int i=1;i<count;i++){
			if(MIN.value <= min[i][min[i].size()-1].value){
				MIN = MIN;
				count_i = count_i;
			}
			else{
				MIN = min[i][min[i].size()-1];
				count_i = i;
			}
		}
	}
	else{
		MIN = min[0][min[0].size()-1];
		count_i = 0;
	}
	cout<< "MIN_path:" <<MIN.value << " " << count_i <<endl;
	
	for(int j=0;j<min[count_i].size()-1;j++)
		cout<<min[count_i][j].head<<" "<<min[count_i][j].tail<<" "<<min[count_i][j].value<<endl;
	cout<<endl;
	
	//------------------
	//	find_min_path	
	//------------------
	int weight_=0;
	vector<vector<head_tail_value>> P_(20);
	vector<head_tail_value> M_;
	head_tail_value A_, B_;
	vector <int> W_;
	Path *bath;
	bath=new Path();
	bath->append(nm->elist);
	for(int i=0;i<=count_i;i++){
		for(int j=0;j<min[count_i].size()-1;j++){
			bath->find_paths(min[i][j].head, min[i][j].tail);

			for(int i=0;i<bath->paths.size();i++){
				for(int j=0;j<bath->paths[i].size();j++){
					weight_ = weight_ + bath->paths[i][j]->flowval;
					A_.head = bath->paths[i][j]->head->name;
					A_.tail = bath->paths[i][j]->tail->name;
					A_.value = bath->paths[i][j]->flowval;
					P_[i].push_back(A_);
				}
				W_.push_back(weight_); 
				weight_ = 0;
			}
			vector<int>::iterator iter = min_element(W_.begin(), W_.end());
			weight_ = *iter;
			int size = distance(W_.begin(), iter);
//			cout<<"size:"<<size<<endl;
//			cout<<P_[size].size()<<endl;
			for(int j=0;j<P_[size].size();j++){
//				cout<<P_[size][j].head<<" "<<P_[size][j].tail<<" "<<P_[size][j].value<<endl;
				nm->connect(P_[size][j].head, P_[size][j].tail);
			}
			P_.clear();
			P_.resize(20);
		}
	}
	cout<<endl;
	
	nm->print_all_e();
	int a=0, b=0;
	Edge *edge_ptr = nm->elist;

	vector<vector<int>> abc(20);
	
	while(edge_ptr!=NULL){
		if(edge_ptr->head->name == "a" || edge_ptr->head->name == "0")	a = 0;
		if(edge_ptr->head->name == "b" || edge_ptr->head->name == "1")	a = 1;
		if(edge_ptr->head->name == "c" || edge_ptr->head->name == "2")	a = 2;
		if(edge_ptr->head->name == "d" || edge_ptr->head->name == "3")	a = 3;
		if(edge_ptr->head->name == "e" || edge_ptr->head->name == "4")	a = 4;
		if(edge_ptr->head->name == "f" || edge_ptr->head->name == "5")	a = 5;
		if(edge_ptr->head->name == "g" || edge_ptr->head->name == "6")	a = 6;
		if(edge_ptr->head->name == "h" || edge_ptr->head->name == "7")	a = 7;
		if(edge_ptr->head->name == "i" || edge_ptr->head->name == "8")	a = 8;
		if(edge_ptr->head->name == "j" || edge_ptr->head->name == "9")	a = 9;
		if(edge_ptr->head->name == "k" || edge_ptr->head->name == "10")	a = 10;
		if(edge_ptr->head->name == "l" || edge_ptr->head->name == "11")	a = 11;
		if(edge_ptr->head->name == "m" || edge_ptr->head->name == "12")	a = 12;
		if(edge_ptr->head->name == "n" || edge_ptr->head->name == "13")	a = 13;
		if(edge_ptr->head->name == "o" || edge_ptr->head->name == "14")	a = 14;
		if(edge_ptr->head->name == "p" || edge_ptr->head->name == "15")	a = 15;
		if(edge_ptr->head->name == "q" || edge_ptr->head->name == "16")	a = 16;
		if(edge_ptr->head->name == "r" || edge_ptr->head->name == "17")	a = 17;
		if(edge_ptr->head->name == "s" || edge_ptr->head->name == "18")	a = 18;
		if(edge_ptr->head->name == "t" || edge_ptr->head->name == "19")	a = 19;
		if(edge_ptr->head->name == "u" || edge_ptr->head->name == "20")	a = 20;
		if(edge_ptr->head->name == "v" || edge_ptr->head->name == "21")	a = 21;
		if(edge_ptr->head->name == "w" || edge_ptr->head->name == "22")	a = 22;
		if(edge_ptr->head->name == "x" || edge_ptr->head->name == "23")	a = 23;
		if(edge_ptr->head->name == "y" || edge_ptr->head->name == "24")	a = 24;
		if(edge_ptr->head->name == "z" || edge_ptr->head->name == "25")	a = 25;
		
		if(edge_ptr->tail->name == "a" || edge_ptr->tail->name == "0")	b = 0;
		if(edge_ptr->tail->name == "b" || edge_ptr->tail->name == "1")	b = 1;
		if(edge_ptr->tail->name == "c" || edge_ptr->tail->name == "2")	b = 2;
		if(edge_ptr->tail->name == "d" || edge_ptr->tail->name == "3")	b = 3;
		if(edge_ptr->tail->name == "e" || edge_ptr->tail->name == "4")	b = 4;
		if(edge_ptr->tail->name == "f" || edge_ptr->tail->name == "5")	b = 5;
		if(edge_ptr->tail->name == "g" || edge_ptr->tail->name == "6")	b = 6;
		if(edge_ptr->tail->name == "h" || edge_ptr->tail->name == "7")	b = 7;
		if(edge_ptr->tail->name == "i" || edge_ptr->tail->name == "8")	b = 8;
		if(edge_ptr->tail->name == "j" || edge_ptr->tail->name == "9")	b = 9;
		if(edge_ptr->tail->name == "k" || edge_ptr->tail->name == "10")	b = 10;
		if(edge_ptr->tail->name == "l" || edge_ptr->tail->name == "11")	b = 11;
		if(edge_ptr->tail->name == "m" || edge_ptr->tail->name == "12")	b = 12;
		if(edge_ptr->tail->name == "n" || edge_ptr->tail->name == "13")	b = 13;
		if(edge_ptr->tail->name == "o" || edge_ptr->tail->name == "14")	b = 14;
		if(edge_ptr->tail->name == "p" || edge_ptr->tail->name == "15")	b = 15;
		if(edge_ptr->tail->name == "q" || edge_ptr->tail->name == "16")	b = 16;
		if(edge_ptr->tail->name == "r" || edge_ptr->tail->name == "17")	b = 17;
		if(edge_ptr->tail->name == "s" || edge_ptr->tail->name == "18")	b = 18;
		if(edge_ptr->tail->name == "t" || edge_ptr->tail->name == "19")	b = 19;
		if(edge_ptr->tail->name == "u" || edge_ptr->tail->name == "20")	b = 20;
		if(edge_ptr->tail->name == "v" || edge_ptr->tail->name == "21")	b = 21;
		if(edge_ptr->tail->name == "w" || edge_ptr->tail->name == "22")	b = 22;
		if(edge_ptr->tail->name == "x" || edge_ptr->tail->name == "23")	b = 23;
		if(edge_ptr->tail->name == "y" || edge_ptr->tail->name == "24")	b = 24;
		if(edge_ptr->tail->name == "z" || edge_ptr->tail->name == "25")	b = 25;
		
//		cout<<a<<" "<<b<<endl;
		abc[a].push_back(b);
		edge_ptr = edge_ptr->next;
	}
	ofstream outfile;
	outfile.open("outfile.txt");
	vector<string> result;
	result = printCircuit(abc);
	cout<<endl;
	int cost=0;
	Edge *_ptr = nm->elist;
	while(_ptr!=NULL){
		cost = cost + _ptr->flowval;
		_ptr = _ptr->next;
	}
	cost = cost + MIN.value;
	cout<<"cost: "<<cost<<endl;
	outfile<<"path:";
	for(int i=0;i<result.size();i++){
		if(i!=result.size()-1)
			outfile<<result[i]<<"->";
		else 
			outfile<<result[i];
	}
	return 0;
}