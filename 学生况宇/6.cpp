#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[]){
fstream infile, outfile;
infile.open(argv[1], ios:: in | ios:: binary ) ;
outfile. open(argv[2], ios:: out | ios:: binary);
if (!infile){
	cout<<"���ܴ������ļ�:"<< argv[0]<<'n';
	return 0;
}

if(!outfile) {
	cout<<"���ܴ�Ŀ���ļ�:"<< argv[1]<<'n';
	return 0;	
}
char buff [4096];
int n;
while(! infile.eof()){
	infile.read(buff, 4096);
	n=infile.gcount();
	outfile. write(buff, n);}
	infile.close();
	outfile.close();
	return 0;

}
//int main(){
//char f1[]="t1.txt";
//char f2[]="t2.txt";
//fstream infile, outfile;
//infile.open(f1, ios:: in | ios:: binary ) ;
//outfile. open(f2, ios:: out | ios:: binary);
//if (!infile){
//	cout<<"���ܴ������ļ�:"<< f1<<'n';
//	return 0;
//}
//
//if(!outfile) {
//	cout<<"���ܴ�Ŀ���ļ�:"<< f2<<'n';
//	return 0;	
//}
//char buff [4096];
//int n;
//while(! infile.eof()){
//	infile.read(buff, 4096);
//	n=infile.gcount();
//	outfile. write(buff, n);}
//	infile.close();
//	outfile.close();
//	return 0;
//
//}
