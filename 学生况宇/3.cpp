#include<iostream>
#include<string>
using namespace std;
class Person{
	public:
		string name;
		bool sex;
		Person*father;
		Person*mother;
		Person*children;
		int num;
		Person(string name,bool sex,int num,Person*father=nullptr,Person*mother=nullptr,Person*children=nullptr):name(name),sex(sex),num(num){
			if(father==nullptr) this->father=nullptr;
			else {
				this->father=new Person;
				this->father=father;
			}
			if(mother==nullptr) this->mother=nullptr;
			else {
				this->mother=new Person;
				this->mother=mother;
			}
			if(children==nullptr) this->children=nullptr;
			else {
				this->children=new Person[num];
				this->children=children;
			}
		}
		Person(){
		}
		void setPerson(string name,bool sex,int num,Person*father=nullptr,Person*mother=nullptr,Person*children=nullptr){
			this->name=name;
			this->sex=sex;
			this->num=num;
			if(father==nullptr) this->father=nullptr;
			else {
				this->father=new Person;
				this->father=father;
			}
			if(mother==nullptr) this->mother=nullptr;
			else {
				this->mother=new Person;
				this->mother=mother;
			}
			if(children==nullptr) this->children=nullptr;
			else {
				this->children=new Person[num];
				this->children=children;
			}			
		}
		void inquire (string type){
			if(type=="children"){
				if(children!=nullptr){
					cout<<"children:  ";
					for(int i=0;i<num;i++) cout<<children[i].name<<"  ";
				} 
				else cout<<"none";
				cout<<endl;			
			}
			else{
					if(type=="father"){
						if(father!=nullptr)
						cout<<"father:  "<<father->name;
						else cout<<"death";
						cout<<endl;	
					} 
					else{
						if(type=="mother"){
						
							if(mother!=nullptr) cout<<"mother:  "<<mother->name;
							else cout<<"death";
							cout<<endl;	
						}
						else{
							if(type=="grandma"){
								cout<<"grandma:  ";
								if(mother->mother!=nullptr) cout<<mother->mother->name<<"  ";
								else cout<<"death";
								if(father->mother!=nullptr) cout<<father->mother->name<<"  ";
								else cout<<"death";
								cout<<endl;
							}
							else{
								if(type=="grandpa"){
									cout<<"grandpa:  ";
									if(mother->father!=nullptr) cout<<mother->father->name<<"  ";
									else cout<<"death";
									if(father->father!=nullptr) cout<<father->father->name<<"  ";	
									else cout<<"death";
									cout<<endl;
								}
							}
						}
					}
					
				}
			}

		
	
		~Person(){
		if(children!=nullptr){
				delete []children;
		} 
		if(father!=nullptr)
				delete father;
		if(mother!=nullptr)
				delete mother;
		} 
};
int main(){
	Person *f=new Person;
	Person *m=new Person;
	Person c[2]={{"c1",1,0,f,m},{"c2",1,0,f,m}};
	f->setPerson("f",1,2,nullptr,nullptr,c);
	m->setPerson("m",0,2,nullptr,nullptr,c);
	c[1].inquire("father");
	c[0].inquire("mother");
	f->inquire("children");
	delete f;
	delete m;
	return 0;
} 
