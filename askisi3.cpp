#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Floor;

class Stairs;
class Schoolyard;




string names[40] = { "Mike", "Kwstas", "Panos","Giannis","lampros","Giorgos","Axileas","Periklis","Alexis","iraklis","Tasos","Pavlo","Dimitris"
					,"Grigoris","Vaggelis","Alexandros","Manos","Marios","Andreas" ,"Panagiotis","Maria", "Dimitra","Mariana","Giota","Margarita","Iliana ","Efthimia",
						"Alexandra","Lamprini","Roza","Lili","Katia","Asimina","Lia","Aggeliki","Sia","Eva","Erieta","Paraskevi","Xrysa" };

//abstract class Person ===========================================================================

class Person {
	public:
		Person(int in_rate_of_exaustion) : rate_of_exhaustion(in_rate_of_exaustion) , tiredness(0){
			cout << " A new Person has been created! " << endl;
			name = names[rand() % 40];
		}
		virtual ~Person() = 0 {}
		virtual void print() const = 0 {}




	protected:
		
		string name;
		
		int tiredness;
		int rate_of_exhaustion;


};

// class Student ===========================================================================

class Student : public Person {
	public:	
		Student(int in_fl_no,int in_cl_no,int in_rate_of_exhaustion) : Person(in_rate_of_exhaustion) ,fl_no(in_fl_no) , cl_no(in_cl_no) ,is_inside(false){
		cout << " A Student has been created! " << endl;
		
		
		}

		~Student()
		{
			cout << "A student to be Destroyed" << endl;
		}
		void print() const {
			cout << name << " floor number " <<	fl_no  << " class number " << cl_no ;
		}
		void attend() {
			tiredness += rate_of_exhaustion;
		}
		int get_fl_no() const {
			return fl_no;

		}
		int get_cl_no() const {
			return cl_no;
		}
		void set_inside() {

			is_inside = true;
		}
		int get_tiredness() const {
			return tiredness;
		}
		
	protected : 

		int fl_no;
		int cl_no;
		bool is_inside;
};

// class Teacher ===========================================================================

class Teacher : public Person {
	
	public:

		Teacher(int in_fl_no, int in_cl_no,int in_rate_of_exaustion) : Person(in_rate_of_exaustion) , fl_no(in_fl_no) , cl_no (in_cl_no) ,is_inside(false) {
			cout << "A new teacher has been created! " << endl;
		}
		~Teacher() {


		}
		void print() const{

			cout << name << " class number " << cl_no << " floor number" << fl_no << endl;
		}
		int get_fl_no() const {
			return fl_no;

		}
		int get_cl_no() const {
			return cl_no;
		}
		void teach() {
			tiredness += rate_of_exhaustion;
			
		}
		void set_inside() {

			is_inside = true;
		}
		int get_tiredness() const {
			return tiredness;
		}


	private:
		int fl_no;
		int cl_no;
		bool is_inside;
};

// class junior Student ===========================================================================

class junior_Student : public Student {

	public:
		junior_Student(int in_fl_no, int in_cl_no , int in_rate_of_exhaustion) : Student(in_fl_no, in_cl_no,in_rate_of_exhaustion) {
			cout << " A junior Student has been created! " << endl;
		}

		~junior_Student()
		{
			cout << "A junior Student to be destroyed" << endl;
		}


	private:

};

// class Senior Student ===========================================================================

class senior_Student : public Student {

	public:
		senior_Student(int in_fl_no, int in_cl_no , int in_rate_of_exhaustion) : Student(in_fl_no, in_cl_no, in_rate_of_exhaustion) {
			cout << " A senior Student has been created! " << endl;
		}

		~senior_Student()
		{
			cout << "A senior Student to be destroyed" << endl;
		}

	private:

};

// abstract class standing Area =====================================================================

class standing_area {

	public:
		standing_area() {
			students = new Student * [1];
			students[0] = NULL;
			
		}
		virtual ~standing_area() = 0 {}
		virtual void enter(Student* s) {

			students[0] = s;

		}
		virtual Student* exit() {

			return students[0];

		}

	protected:
		Student** students;
};

//abstract class operating Area =====================================================================

class operating_area {
	
	public:
		operating_area(int N) : operating_hours(N) {
		
			students = new Student * [1];
			teacher = new Teacher * [1];
		
		}
		virtual ~operating_area() = 0 {}

		virtual void enter(Student* s) {

			students[0] = s;

		}
		virtual void place(Teacher* t) {

			teacher[0] = t;

		}
		virtual void operate() = 0 {}
	protected:
		Teacher** teacher;
		Student** students;
		int operating_hours;
};


// class Schoolyard =====================================================================

class Schoolyard : public standing_area {

	public:
		Schoolyard() {
			cout << " A new Schoolyard has been created!" << endl;
			//students = new Student * [1];
			//students[0] = NULL;
		}
		~Schoolyard()
		{

		}

		void enter(Student* s) {

			students[0] = s;
			students[0]->print();
			cout << " enters Schoolyard" << endl;

			
		}
		Student* exit() {

			students[0]->print();
			cout << " exits Schoolyard" << endl;
			return students[0];

		}

	private:
		//Student** students;
		
};

// class Stairs =====================================================================

class Stairs : public standing_area {

	public:
		Stairs() {

			//students = new Student * [1];
			//students[0] = NULL;
			cout << " A new Stairs has been created!" << endl;

		}
		~Stairs()
		{

		}
		void enter(Student* s) {

			students[0] = s;
			students[0]->print();
			cout << " enters Stairs!" << endl;

		}
		Student* exit() {
			
			students[0]->print();
			cout << " exits Stiars!" << endl;
			return students[0];

		}

	private:

		//Student** students;
};


// class Corridor =====================================================================

class Corridor : public standing_area
{
public:
	Corridor() {

		cout << " A new Corridor has been created!" << endl;

	}
	~Corridor() {


	}
	void enter(Student* s) {

		students[0] = s;
		students[0]->print();
		cout << " enters Corridor!" << endl;
	}
	Student* exit() {
		
		students[0]->print();
		cout << " exits Corridor" << endl;
		return students[0];
	}

private:

};

// class Classroom =====================================================================

class Classroom : public operating_area {

public:
	Classroom(int in_cl_no,int in_Cclass,int N) : operating_area(N), cl_no(in_cl_no) ,Cclass(in_Cclass) {
	
		cl_students = new Student * [Cclass];
		for (int i = 0; i < Cclass; i++)
			cl_students[i] = NULL;
		cout << " A new Class has been created!" << cl_no <<  endl;

	}
	~Classroom()
	{

	}
	void operate() {

		cout << "Classroom operating!!!" << endl;
		for (int i = 0; i < Cclass; i++) {
			if (cl_students[i] != NULL) {
				for (int j = 0; j < operating_hours; j++) {
					cl_students[i]->attend();

				}
			}
		}
		for (int j = 0; j < operating_hours; j++)
			teacher[0]->teach();
	}

	void enter(Student* s) {
		int i = 0;
		while (i<Cclass)
		{
			if (cl_students[i] == NULL) {
				cl_students[i] = s;
				cl_students[i]->print();
				cout << " enters Classroom no " << cl_no << endl;
				cout << i << endl;
				cl_students[i]->set_inside();
				break;

			}
			i++;
		}
	

	}
	void place(Teacher* t) {

		teacher[0] = t;
		teacher[0]->set_inside();
	}
	int get_class_no() const {
		return cl_no;
	}
	void print() const {

		cout << "Classroom " << cl_no << " contains : " << endl;
		for (int i = 0; i < Cclass; i++) {

			cl_students[i]->print();
			cout << "  " << cl_students[i]->get_tiredness() << endl;
		}
		cout << "The Teacher is :" << endl; 
		teacher[0]->print();
		cout << "  " << teacher[0]->get_tiredness() << endl;

	}
	


private:
	Student** cl_students;
	int cl_no;
	int Cclass;
	
};

// class Floor =====================================================================

class Floor : public operating_area {

	public:
		Floor(int in_fl_no,int in_Cclass, int N) : operating_area(N) , fl_no(in_fl_no) , Cclass(in_Cclass) {
			cout << " A new Floor has been created!" << fl_no << endl;
			p_to_Corr = new Corridor;
			p_to_class = new Classroom * [6];
			for (int i = 0; i < 6; i++) {
				switch (fl_no)
				{
				case(1) :
					p_to_class[i] = new Classroom(i + 1, Cclass , operating_hours);
					break;
				case(2) :
					p_to_class[i] = new Classroom(i + 7, Cclass , operating_hours);
					break;
				case(3) :
					p_to_class[i] = new Classroom(i + 13, Cclass , operating_hours);
					break;
				}
				
			}
				

		}
		~Floor()
		{
			delete p_to_Corr;

			for (int i = 0; i < 6; i++)
				delete p_to_class[i];

			delete[] p_to_class;
		}
		void enter(Student* s) {

			students[0] = s;
			students[0]->print();
			cout << " enters Floor no " << fl_no << endl;
			p_to_Corr->enter(students[0]);
			for (int i = 0; i < 18; i++) {
				if (p_to_class[i]->get_class_no() == students[0]->get_cl_no()) {
					p_to_class[i]->enter(p_to_Corr->exit());
					break;
				}
			}
		}

		int get_floor_no() {
			return fl_no;
		}
		void place(Teacher* t) {

			teacher[0] = t;
			for (int i = 0; i < 18; i++) {
				if (p_to_class[i]->get_class_no() == teacher[0]->get_cl_no()) {
					p_to_class[i]->place(teacher[0]);
					break;
				}
			}
		}
		void operate() {

			for (int i = 0; i < 6; i++)
				p_to_class[i]->operate();

		}
		void print() const {

			cout << "Floor " << fl_no << " contais :" << endl;
			for (int i = 0; i < 6; i++)
				p_to_class[i]->print();
		}
		
	private:
		Classroom** p_to_class;
		standing_area* p_to_Corr;
		int fl_no;
		int Cclass;
};

// class School =====================================================================

class School : public operating_area {
public:
	School(int in_Cclass,int N) : operating_area(N) , Cclass(in_Cclass) {
		cout << " A new School has been created!" << endl;
		p_to_yard = new Schoolyard;
		p_to_stairs = new Stairs;
		p_to_floor = new Floor * [3];
		for (int i = 0; i < 3; i++)
			p_to_floor[i] = new Floor(i + 1 , Cclass , operating_hours);

		students = new Student * [1];
		students[0] = NULL;
	}
	~School() {
		
		delete p_to_yard;
		delete p_to_stairs;

		for (int i = 0; i < 3; i++)
			delete p_to_floor[i];

		delete[] p_to_floor;
	}

	void enter(Student* s) {

		
		students[0] = s;
		students[0]->print();
		cout << " enters School" << endl;
		p_to_yard->enter(students[0]);

		p_to_stairs->enter(p_to_yard->exit());

		for (int i = 0; i < 3; i++) {
			if (students[0]->get_fl_no() == p_to_floor[i]->get_floor_no()) {
				p_to_floor[i]->enter(p_to_stairs->exit());
				break;
			}

		}
	}

	void place(Teacher* t) {

		teacher[0] = t;
		for (int i = 0; i < 3; i++) {
			if (teacher[0]->get_fl_no() == p_to_floor[i]->get_floor_no()) {
				p_to_floor[i]->place(teacher[0]);
				break;
			}
		}

	}


	void operate() {

		for (int i = 0; i < 3; i++)
			p_to_floor[i]->operate();

	}
	void print() const {

		cout << "School life consists of :" << endl;
		for (int i = 0; i < 3; i++)
		{

			p_to_floor[i]->print();

		}
	}




private:

	//Student** students;
	int Cclass;
	standing_area* p_to_yard;
	standing_area* p_to_stairs;
	Floor** p_to_floor;
};







int main() {

	int Cclass = 10;
	int Ls = 3;
	int Lj = 5;
	int Lt = 2;
	int N = 5;
	int temp = Cclass;
	Student** s;
	Teacher** t;
	School school1(Cclass, N);
	s = new Student * [Cclass*18];
	t = new Teacher * [18];
	static int ii = 0;
	int temp2 = 1;
	for (int i = 1; i <= 3; i++) {
		int j = 1;
		while (j <= 6) {
			while (ii < temp) {
				if (j <= 3) s[ii] = new junior_Student(i, temp2, Lj);
				else s[ii] = new senior_Student(i, temp2, Ls);
				ii++;

			}
			temp += Cclass;
			j++;
			temp2++;
		}
	}

	for (int i = 0; i < 18; i++) {
		if (i < 6) t[i] = new Teacher(1, i + 1, Lt);
		else if (i >= 6 && i < 12) t[i] = new Teacher(2, i + 1, Lt);
		else t[i] = new Teacher(3, i + 1, Lt);
	}
		

	

	for (int i = 0; i < Cclass*18; i++)
		school1.enter(s[i]);

	for (int i = 0; i < 18; i++)
		school1.place(t[i]);

	school1.operate();
	school1.print();

	for (int i = 0; i < Cclass * 18; i++)
		delete s[i];


	for (int i = 0; i < 18; i++)
		delete t[i];

	


	delete[] s;
	delete[] t;

	return 0;


}



