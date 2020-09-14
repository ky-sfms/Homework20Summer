#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Date
{
	int year; int month; int day;
};
class File
{
public:
	File(string,float,Date,Date);
	void prinftfile();
private:
	string filename;//文件名
	float sizeoffile;//大小
	Date creatDate;//创建日期
	Date updateDate;//修改日期
};

File::File(string filename,float sizeoffile,Date creat,Date update):filename(filename), sizeoffile(sizeoffile),creatDate(creat),updateDate(update)
{
}

void File::prinftfile()
{
	cout << setw(20)<< filename << setw(10) << sizeoffile << setw(9) << creatDate.year << '.' << creatDate.month << '.' << creatDate.day << setw(9) << updateDate.year << '.' << updateDate.month << '.' << updateDate.day ;
}
enum mediatype{audio,vedio};
class MediaFile:public File
{
public:
	MediaFile(string, float, Date, Date, mediatype,int);
	void prinftfile();
private:
	mediatype type;
	int intime;
};

MediaFile::MediaFile(string filename, float sizeoffile, Date creat, Date update, mediatype type,int time):File(filename,sizeoffile,creat,update),type(type),intime(time)
{
}

void MediaFile::prinftfile()
{
	File::prinftfile();
	string ctype;
	if (type) ctype = "audio";
	else      ctype = "vedio";
	int h = intime / 60 / 60; int m = intime % (60 * 60) / 60; int s = intime - (h * 60 * 60) - m * 60;
	cout <<setw(20) <<ctype << setw(6) << h << setw(2) << ':' << m << setw(2) << ':' << s ;
}
int main() {
	cout << setw(20)<< "文件名" << setw(10) << "大小" << setw(15) << "创建日期" << setw(15) << "修改日期" << setw(20) << "类型(多媒体文件)" << setw(10) << "播放时间" << endl;
	File file1("file1", 4, { 2020,8,2 }, { 2020,9,12 });
	MediaFile mediafile1("mediafile1", 20, { 2020,8,31 }, { 2020,9,14 }, audio, 190);
	file1.prinftfile();cout << endl;
	mediafile1.prinftfile();cout << endl;
}
