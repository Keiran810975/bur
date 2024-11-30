#include <iostream>
using namespace std;
class Point {   //Point ��Ķ���
public:
	Point(int xx = 0, int yy = 0) { x = xx; y = yy; }    //���캯��������
	Point(const Point& p); //���ƹ��캯��
	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
	int getX() const { return x; } //����������5�£�
	int getY() const { return y; } //����������5�£�
private:
	int x, y; //˽������
};
//��Ա������ʵ��
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor " << endl;
}
//�β�ΪPoint�����ĺ���
void fun1(Point p) {
	cout << p.getX() << endl;
}
//����ֵΪPoint�����ĺ���
Point fun2() {
	Point a(1, 2);
	return a;
}

//������
int main() {
	Point a(4, 5); //�����һ������a
	Point b = a; //���һ����a��ʼ��b����һ�ε��ø��ƹ��캯�����ȼ���b(a)
	//ע���˴����Ǹ�ֵ���㣬�뵥��b=a��ͬ��������=��������ء�
	cout << b.getX() << endl;
	fun1(b);	//�����������B��Ϊfun1��ʵ�Ρ��ڶ��ε��ø��ƹ��캯��
	b = fun2();	//������������ķ���ֵ������󣬺�������ʱ���ø��ƹ��캯��
	//ע��vc���ø��ƹ��캯�������������������Ż�
	cout << b.getX() << endl;
	return 0;
}
