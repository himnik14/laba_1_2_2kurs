#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdio>
using namespace std;
class RavnobedTreug {
	double side;
	int base_angle;
	double osnovanie;
public:
	int Get_Apex_Angle(); // Получить угол между вершинами 
	double Set_Side(double value_side); // Установить боковую сторону
	double Get_Base_side(); // Получить значение длины основания треугольника
	int Set_Base_angle(int value_angle); // Установаить угол между основанием и боковой стороной 
	void Zoom_Treangle(); // Изменение масштаба треугольника 
	double Get_Side(); // Получить боковую сторону 
	int Get_base_angle(); // Получить угол при основании 
	void Bisecor(); // Получить длину биссекриссы 
	void Triangle_height(); // Получить длины высот треугольника
	void Lenght();
};
double RavnobedTreug::Set_Side(double value_side) {
	if (value_side <= 0) {
		cout << "Боковая сторона треугольника не может быть меньше или равна нулю!" << endl;
		exit(0);
	}
	else {
		side = value_side;
		return true;
	}
}
int RavnobedTreug::Set_Base_angle(int value_angle) {
	if (value_angle <= 0) {
		cout << "Угол при основании не может быть меньше или равен нулю!" << endl;
		exit(0);
	}
	else if (value_angle == 180) {
		cout << "Угол треугольника не может быть равен 180 градусам!" << endl;
		exit(0);
	}
	else if (value_angle * 2 == 180) {
		cout << "Сумма двух углов при основании не может быть равна 180 градусам!" << endl;
		exit(0);
	}
	else {
		base_angle = value_angle;
		return true;
	}
}
int RavnobedTreug::Get_Apex_Angle() {
	return 180 - base_angle * 2;
}
double RavnobedTreug::Get_Base_side() {
	return sqrt(pow(side, 2) + pow(side, 2) - 2 * side * side * cos((Get_Apex_Angle() * 3.14) / 180));
}
int RavnobedTreug::Get_base_angle() {
	return base_angle;
}
double RavnobedTreug::Get_Side() {
	return side;
}
void RavnobedTreug::Zoom_Treangle() {
	int N, n;
	cout << "Чтобы уменьшить треугольник, введите 0. Чтобы увеличить введите 1. " << endl;
	cin >> n;
	if (n == 1) {
		cout << "Во сколько раз вы хотите увеличить треугольник? " << endl;
		cin >> N;
	}
	else if (n == 0) {
		cout << "Во сколько раз вы хотите уменьшить треугольник? " << endl;
		cin >> N;
	}
	else cout << "Вы ввели неверное число, попробуйте в другой раз!" << endl;
	if (n == 1 && N != 0) {
		osnovanie = Get_Base_side() * N;
		side *= N;
		cout << "Две боковые стороны будут равны: " << side << endl;
		cout << "Основание будет равно: " << osnovanie << endl;
	}
	else if (n == 0 && N != 0) {
		osnovanie = Get_Base_side() / N;
		side /= N;
		cout << "Две боковые стороны будут равны: " << side << endl;
		cout << "Основание будет равно: " << osnovanie << endl;
	}
	else if (n == 0 || n == 1 && N == 0) {
		cout << "Две боковые стороны будут равны: " << side << endl;
		cout << "Основание будет равно: " << Get_Base_side() << endl;
	}
}
void RavnobedTreug::Bisecor() {
	cout << "Длины биссекрис в углы при основании: " << (sqrt(side * Get_Base_side() * (side + side + Get_Base_side()) * (side - side + Get_Base_side()))) / (Get_Base_side() + side) << endl;
	cout << "Длина биссекрисы в угол при вершинах: " << (sqrt(side * side * (side + side + Get_Base_side()) * (side + side - Get_Base_side()))) / (side + side) << endl;
}
void RavnobedTreug::Triangle_height() {
	double p = (side + side + Get_Base_side()) / 2;
	cout << "Высоты, выходящие из углов при основании: " << (2*sqrt(p*(p-side)*(p-side)*(p-Get_Base_side())))/side << endl;
	cout << "Высота, выходящая из угла при вершинах: " << (sqrt(side * side * (side + side + Get_Base_side()) * (side + side - Get_Base_side()))) / (side + side) << endl;
}
void RavnobedTreug::Lenght() {
	cout << "Длина боковой стороны A: " << side << endl;
	cout << "Длина боковой стороны B: " << side << endl;
	cout << "Длина основания C: " << Get_Base_side() << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	RavnobedTreug tr, tr1;
	double side;
	int base_angle, q = 0, n;
	cout << "Здравствуйте!" << endl;
	cout << "Введите длину боковой стороны равнобедренного треугольника: " << endl;
	cin >> side;
	tr.Set_Side(side);
	cout << "Введите значение угла при основании: " << endl;
	cin >> base_angle;
	tr.Set_Base_angle(base_angle);
	while (q <= 4) {
		cout << "___________________________________________________________________________________________" << endl;
		cout << "Увеличить/уменьшить размер треугольника - 0" << "\n" << "Вычислить длины биссектрис - 1" << "\n" << "Вычислить длины высот - 2" << "\n" << "Определить длины сторон - 3" << endl;
		cin >> n;
		if (n == 0) {
			tr.Zoom_Treangle();
			q++;
		}
		else if (n == 1) {
			tr.Bisecor();
			q++;
		}
		else if (n == 2) {
			tr.Triangle_height();
			q++;
		}
		else if (n == 3) {
			tr.Lenght();
			q++;
		}
		else cout << "Вы ввели неверную цифру! " << endl;
	}
}








