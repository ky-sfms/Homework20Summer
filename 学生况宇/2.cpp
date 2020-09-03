#include<iostream>
#include<time.h>
using namespace std;
class Date{
	int year,month,day;
	public:
	Date(){}
	Date(int y,int m,int d):year(y),month(m),day(d){}
	void setterdate(int y,int m,int d){
		year=y;
		month=m;
		day=d;
	}
	int getteryear(){
		return year;
	}
	int gettermonth(){
		return month;
	}
	int getterday(){
		return day;
	}
};
class DateTime{
	int hour,min,sec;
	Date date;
	public:
		DateTime(){
			time_t mytime=time(NULL);
			tm*today=localtime(&mytime);
			date.setterdate(today->tm_year+1900,today->tm_mon+1,today->tm_mday);
			hour=today->tm_hour;
			min=today->tm_min;
			sec=today->tm_sec;
		}
		DateTime(int year,int month,int day,int hour,int min,int sec):date(year,month,day),hour(hour),min(min),sec(sec){
		}
		void setterhour(int h){hour=h;} 
		void settermin(int m){min=m;}
		void settersec(int s){sec=s;}
		int getterhour(){
			return hour;
		}
		int gettermin(){
			return min;
		}
		int gettersec(){
			return sec;
		}
		void show(){
			cout<<date.getteryear()<<"年"<<date.gettermonth()<<"月"<<date.getterday()<<"日"<<getterhour()<<"时"<<gettermin()<<"分"<<gettersec()<<"秒"<<endl; 
		}
};
int main(){
	DateTime time1;
	DateTime time2(2001,6,13,12,11,12);
	time1.show();
	time2.show();
	system("pause"); 
	return 0;
}
