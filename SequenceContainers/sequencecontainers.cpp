#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimeter "\n------------------------------\n"

template<typename T> void vector_info(const std::vector<T>& vec);
template<typename T>void deque_info(const std::deque<T>& vec);

//#define STL_ARRAY
#define STIL_VECTOR
#define STL_DEQUE
//#define STL_LIST
//#define STL_FORWARD_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cout << "Error: Something went wrong" << endl;
	}
	cout << endl;
	for (int i :arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif

#ifdef STIL_VECTOR
	/*
	Vector

	Это контейнер, который хранит данные, в виде динамического массива
	*/
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit(); урезает capacity до фактического размера
	//vec.reserve(16);
	//vec.push_back(1024);
	vec.resize(8);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	///////////////////////////////
	int index;
	int value;
	do
	{
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
	} while (index > vec.capacity());
	vec.insert(vec.begin() + index, value);
	for (int i : vec)cout << i << tab; cout << endl;

	do
	{
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
	} while (index > vec.capacity());
	vec.erase(vec.begin() + index);
	for (int i : vec)cout << i << tab; cout << endl;
#endif // STIL_VECTOR

#ifdef STL_DEQUE
	//deque - это контейнер, который хранит данные в виде списка векторов.
	//Это позволяет обеспечить относительно быстрый доступ к элементам, и относительно быстрое добавление и удаление элементов.
	//deque - double-ended queue (двунаправленная очередь).
	//deque по своим возможностям очень напоминает vector, и дополняет его методами push_front и pop_front.

	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_front(2);

	/*std::vector<int>vec;
	cout << typeid(vec.data()).name() << endl;*/

	deque_info(deque);
	deque.assign(vec.begin() + 3, vec.end() - 3);
	for (int i : deque)cout << i << tab; cout << endl;

	/*
	В то время как vector гарантированно хранит данные в одном массиве, для изменения размера которого, его нужно переопределить - элементы deque могут быть разбросаны в памяти.
	Именно поэтому vector предоставляет доступ к хранилищу в виде указателя на массив, а deque этого не делает.

	Deque внутренне устроен сложнее, чем вектор. Это позволяет ему изменять размер гораздо эффективнее при тех же обстоятельствах, что и вектор, особенно при больших размерах.
	*/

#endif // STL_DEQUE

#ifdef STL_LIST
	//List - это контейнер, который хранит данные в виде двусвязного списка.
	std::list<int> list = { 3, 5, 8, 13, 21, 34, 55, 89 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;

	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//list.insert(list.begin() + index, value);     //Списки не поддерживают арифметику указателей
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	//std::advance(position, index);    //Функция advande() смещает итератор вправо, на заданное количество элементов.
	//list.insert(position, value);

	std::list<int>::reverse_iterator r_positiion = list.rbegin();
	std::advance(r_positiion, list.size() - index);
	position = r_positiion.base();
	list.insert(position, value);

	for (int i : list)cout << i << tab; cout << endl;

	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	position = list.begin();
	std::advance(position, index);
	list.erase(position);
	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_LIST

#ifdef STL_FORWARD_LIST

	std::forward_list<int> list = { 3, 5, 8, 13, 21 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::forward_list<int>::iterator position = list.before_begin();
	std::advance(position, index);
	list.insert_after(position, value);
	list.insert_after(list.begin(), 16384);
	for (int i : list)cout << i << tab; cout << endl;

#endif // STL_FORWARD_LIST


}

template<typename T> void vector_info(const std::vector<T>& vec)
{
	cout << "Size: " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //Объем зарезервированной памяти. Зарезервированная память нужна для того, чтобы ускорить процесс добавления элементов и избежать необходимости переопределять память при каждом добавлении элемента.
	cout << delimeter << endl;
}
template<typename T>void deque_info(const std::deque<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;		//Фактический размер Вектора, показывающий сколько элементов хранит Вектор.
	cout << "MaxSize: " << vec.max_size() << endl;
	//cout << "Capacity:" << vec.capacity() << endl;	
	cout << delimeter << endl;
}
	/*
	Каждый контейнер объявлен в отдельном заголовочном файле. Для использования любого контейнера нужно подключить соответствующий одноименный заголовок.
	
	Абсолютно все сущности в STL являются шаблонными (могут работать с любыми типами данных). В особенности это касается контейнеров. Для каждого контейнера обязательно явно указывать тип данных,
	который будет хранится в этом контейнере.

	Array - это контейнер, который хранит данные в виде статического массива.

	Если контейнер для хранения данных использует массив, то в нем обязательно будут перегружены квадратные скобки.
	Если в контейнере есть квадратные скобки, то в нем так же обязательно будет метод "at", который так же возвращает значение по индексу.

	Метод "at" при выходе за пределы контейнера бросает исключение "out_of_range exception", чего не делают квадратные скобки.

	Исключения:

	Исключительная ситуаиця - это ошибка на этапе выполнения, которая приводит к аварийному завершению программы с потерей данных. Такие ошибки могут быть вызваны неверными действиями программиста или пользователя.
	Неверные действия программиста могут быть исправлены изменением исходного кода программы.
	На неверные действия пользователя повлиять никак нельзя. Мы можем лишь обработать эту исключительную ситуацию.

	Для того, чтобы обработать исключение его нужно поймать(catch), а для его поимки нужен бросок (throw). 
	Исключение может бросить процессор(аппаратное исключение), операционная система(системное исключение) или программа(прикладное исключение).

	Языки C и C++ позволяют обрабатывать только прикладные исключения, которые явно бросает какая-то функция, написанная на этих языках.

	Для обработки исключений, код, который потенциально может сгенерировать исключение, помещается в блок try. Блок try - это поле, на которое прилетают исключения.
	У блока try должен быть хотя бы один обработчик (блок catch). Обработчик исключения - это функция с одним параметром, которая неявно вызывается при возникноввении соответствующего исключения.

	У одного блока try не может быть двух однотипных обработчиков, но может быть один универсальный.

	Обработка исключения позволяет восстановить работу без аварийного завершения.
	*/