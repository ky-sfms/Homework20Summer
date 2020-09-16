#include<iostream>
#include<algorithm>
#include<math.h>
#include<windows.h>
using namespace std;
class Fraction
{
public:
	Fraction(int,int);
	void reduce(int&, int&);
	Fraction operator+ (Fraction&);
	Fraction operator- (Fraction&);
	Fraction operator* (Fraction&);
	Fraction operator/ (Fraction&);
	operator double();
	friend ostream& operator<< (ostream&,const Fraction&);
private:
	int denominator;//分母
	int member;//分子
};

Fraction::Fraction(int m,int d):denominator(d),member(m)
{
	if (denominator <= 0) throw("分母必须大于等于零");
	reduce(denominator, member);
}

void Fraction::reduce(int &aa, int &bb)
{
	int a = abs(aa); int b = abs(bb);
	int minin = min(a, b);
	for (size_t i =minin; i>0 ; i--)
	{
		if (a%i == 0 && b%i == 0) {
			a /= i;
			b /= i;
		}
	}
	if (aa < 0) { aa = -a; bb = b; }
	else { aa = a; bb = b; }
}

Fraction  Fraction::operator+(Fraction&a)
{
	int d = this->denominator * a.denominator;
	int m = this->member*a.denominator + this->denominator*a.member;
	reduce(d, m);
	return Fraction(d, m);
}

Fraction Fraction::operator-(Fraction &a)
{
	int d = this->denominator * a.denominator;
	int m = this->member*a.denominator - this->denominator*a.member;
	reduce(d, m);
	return Fraction(d, m);
}
Fraction Fraction::operator*(Fraction &a)
{
	int d = this->denominator * a.denominator;
	int m = this->member*a.member;
	reduce(d, m);
	return Fraction(d, m);
}
Fraction Fraction::operator/(Fraction &a)
{
	Fraction b(a.member, a.denominator);
	
	return b * (*this);
}

Fraction::operator double()
{
	return double(this->member) / this->denominator;
}

int main() {
	try {
		while (1) {
			int a, b;
			cin >> a >> b;
			if (!a && !b)break;
			Fraction f1(a, b);
			Fraction f2(1, 2);
			cout << (f1 + f2) << endl;
			cout << f1 - f2 << endl;
			cout << f1 * f2 << endl;
			cout << f1 / f2 << endl;
			cout << double(f1)<<endl;
		}
	}
	catch (string) {
		MessageBox(NULL, "错误", "分母必须大于等于零", MB_OK);
	}

}

ostream & operator<<(ostream &o, const Fraction &f)
{
	o << f.member << '/' << f.denominator;
	return o;
}

