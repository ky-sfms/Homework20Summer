#include<iostream>
#include<string>
using namespace std;
class Cat{
	int age;
	int weight;
	string color;
	public:
	Cat(){};
	Cat(int age,int weight,string color){
		this->age=age;
		this->weight=weight;
		this->color=color;
	} 
	setage(int age){
		this->age=age;
	}
	setweight(int weight){
		this->weight=weight;
	}
	setcolor(string color){
		this->color=color;
	}	
	int getage(){
		return age;
	}
	int getweight(){
		return weight;
	}
	string getcolor(){
		return color;
	}		
};
int main(){
	Cat cat1;
	Cat cat2(1,50,"white");
	cat1.setage(2);
	cat1.setweight(100);
	cat1.setcolor("black");
	cout<<"cat1"<<endl<<"age:"<<cat1.getage()<<endl<<"weight:"<<cat1.getweight()<<endl<<"color:"<<cat1.getcolor()<<endl;
	cout<<"cat2"<<endl<<"age:"<<cat2.getage()<<endl<<"weight:"<<cat2.getweight()<<endl<<"color:"<<cat2.getcolor()<<endl;
	system("pause");
	return 0; 
}

