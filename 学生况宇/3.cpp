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
		Person(string name,bool sex,int num,Person*father=NULL,Person*mother=NULL,Person*children=NULL):name(name),sex(sex),num(num){
			if(father==NULL) this->father=NULL;
			else {
				this->father=new Person;
				this->father=father;
			}
			if(mother==NULL) this->mother=NULL;
			else {
				this->mother=new Person;
				this->mother=mother;
			}
			if(children==NULL) this->children=NULL;
			else {
				this->children=new Person[num];
				this->children=children;
			}
		}
		Person(){
		}
		void setPerson(string name,bool sex,int num,Person*father=NULL,Person*mother=NULL,Person*children=NULL){
			this->name=name;
			this->sex=sex;
			this->num=num;
			if(father==NULL) this->father=NULL;
			else {
				this->father=new Person;
				this->father=father;
			}
			if(mother==NULL) this->mother=NULL;
			else {
				this->mother=new Person;
				this->mother=mother;
			}
			if(children==NULL) this->children=NULL;
			else {
				this->children=new Person[num];
				this->children=children;
			}			
		}
		void inquire (string type){
			if(type=="children"){
				if(children!=NULL){
					cout<<"children:  ";
					for(int i=0;i<num;i++) cout<<children[i].name<<"  ";
				} 
				else cout<<"none";
				cout<<endl;			
			}
			else{
					if(type=="father"){
						if(father!=NULL)
						cout<<"father:  "<<father->name;
						else cout<<"death";
						cout<<endl;	
					} 
					else{
						if(type=="mother"){
						
							if(mother!=NULL) cout<<"mother:  "<<mother->name;
							else cout<<"death";
							cout<<endl;	
						}
						else{
							if(type=="grandma"){
								cout<<"grandma:  ";
								if(mother->mother!=NULL) cout<<mother->mother->name<<"  ";
								else cout<<"death";
								if(father->mother!=NULL) cout<<father->mother->name<<"  ";
								else cout<<"death";
								cout<<endl;
							}
							else{
								if(type=="grandpa"){
									cout<<"grandpa:  ";
									if(mother->father!=NULL) cout<<mother->father->name<<"  ";
									else cout<<"death";
									if(father->father!=NULL) cout<<father->father->name<<"  ";	
									else cout<<"death";
									cout<<endl;
								}
								else{
									if(type=="siblings")
									cout<<"siblings:  ";
									if(num==1)
										cout<<"none";
									else
									for(int i=0;i<father->num;i++) 
									if(father->children[i].name!=name)
									cout<<father->children[i].name<<"  ";
								} 
							}
						}
					}
					
				}
			}

		
	
		~Person(){
		if(children!=NULL){
				delete []children;
		} 
		if(father!=NULL)
				delete father;
		if(mother!=NULL)
				delete mother;
		} 
};
int main(){
	Person *f=new Person;
	Person *m=new Person;
	Person c[2]={{"c1",1,0,f,m},{"c2",1,0,f,m}};
	f->setPerson("f",1,2,NULL,NULL,c);
	m->setPerson("m",0,2,NULL,NULL,c);
	c[1].inquire("father");
	c[0].inquire("mother");
	f->inquire("children");
	c[1].inquire("siblings");
	delete f;
	delete m;
	return 0;
} 
