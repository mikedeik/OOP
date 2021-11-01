#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>





using namespace std;



//CLASS School=============================================================




class Schoolyard;

class Stairs;

class Floor;

class Corridor;

class Classroom;

class Student;

class Teacher;


class School
{
public:

	School(int in_Cclass, int in_Cyard, int in_Cstairs, int in_Ccorr, int in_N);                    //dhlwsh Constructor sxoleiou
	~School();																						//dhlwsh Destructor sxoleiou
	void enter_school(Student** s);																	// enter gia pinaka mathitwn
	void enter_school(Student* s);																	// enter gia mathiti


	void call_print_student();																		// kalei thn print gia object typou Student
	void call_enter_yard(int i);																	// kalei thn enter gia object typou Schoolyard

	void call_get_stairs();																			// kalei thn enter gia object typou Stairs

	void call_get_floor();																			// kalei thn get_floor gia object typou Stairs

	void place_teacher(Teacher* t, int in_t_cl_no);													// place teacher
	void call_place_teacher(Teacher*);																// kalei thn place ths Classroom
	void print_school();																			// kanei ektypwsh tou sxoleiou	




	Student** array_of_s_in_school;                                                                  // dhmiourgia pinaka deiktwn se antikeimena typou Student 
	Teacher** array_of_t_in_school;                                                                  // dhmiourgia pinaka deiktwn se antikeimena typou Teacher 




private:
	int Cyard;                                                    // akeraios xwrhtikothta proauliou
	int Cclass;                                                   // xwrhtikothta takshs               
	int Cstairs;                                                  // xwrhtikothta klimakwstasiou      
	int Ccorr;                                                    // xwrhtikothta diadromwn     
	int t_cl_no;
	Schoolyard* p_to_yard;                                        // deikths se antikeimeno typou Schoolyard  
	Stairs* p_to_stairs;                                          // deikths se antikeimeno typou Stairs
	Floor* p_to_floor;                                            // deikths se antikeimeno typou Floor  

	bool is_full = false;                                          // boolean metavlhth pou mas deixnei an to sxoleio exei gemisei 

	Floor* p_to_floor1;                                            // deikths ston prwto orofo     
	Floor* p_to_floor2;                                            // deikths ston 2o orofo 
	Floor* p_to_floor3;                                            // deikths ston 3o orofo 

	Classroom* p_to_class;                                          // deikths se antikeimeno typou Classroom tha mas xreiastei gia tous daskalous
    int N;                                                          // to synolo twn mathitwn


};




// Class Schoolyard===================================================================


class Schoolyard
{
public:                                                               //dhlwseis  

	Schoolyard(int in_Cyard);                                       // constructor tou proauliou pairnei san orisma th xwrhtikothta tou
	~Schoolyard();                                                  // destructor sxoleiou  
	void call_enter_stairs(int i, int in_Cstairs);                  // kalei thn synarthsh enter ths klashs Stairs

	void enter_yard(Student* s);                                    // eisagei mathiti sto proaulio
	void exit(int i, Student* s);                                   // afairei mathiti apo to proaulio
	void get_stairs(int in_Cstairs, Stairs* p);                     // dexetai th skala apo to sxoleio gia na mporesei na perasei mathitis ekei    





	void call_print_student();                                      // kalei thn print tou mathiti



private:
	int Cstairs;                                                     // tha dextei thn xwrhtikothta ths skalas apo to sxoleio 
	int Cyard;                                                       // exei th xwrhtikothta tou proauliou   
	Stairs* p_to_stairs;                                             // exei ena deikth stis skales    
	Student** array_of_s_in_yard;                                    // pinakas deiktwn se mathites               
    
	bool is_full = false;                                             // boolean gia na kseroume an exei gemisei 


};

// Class Stairs==================================================================================

class Stairs {

public:                                                             // dhlwseis 
	Stairs(int in_Cstairs);                                         // costructor
	~Stairs();                                                      // destructor   
	void get_floor(int Ccorr, int Cclass, Floor* p);                // synarthsh gia na parei ton orofo pou xreiazetai    
	void call_print_student();                                      // kalei thn print gia mathiti
	void exit(int i, Student* s);                                    
	void enter(Student* s);                                                                     

	bool is_full = false;                                           // boolean gia na kseroume an exoun gemisei oi skales


private:
	int Ccorr;                                                       // xwrhtikothta tou diadromou       
	int Cclass;                                                      // xwrhtikothta takshs
	int Cstairs;                                                     // xwrhtikothta klimakostasiou
	Floor* p_to_floor;                                               // deikths se orofo   
	Student** array_of_s_in_stairs;                                  // pinakas deiktwn se mathiti       


};

//Class Floor======================================================================================



class Floor {

public:
	Floor(int f_no, int in_Ccorr, int in_Cclass);                      // constructor orofou
	~Floor();                                                          // destructor orofou

	void enter_floor(Student* s);                                      // synarthsh eisodou         
	bool is_full = false;                                              // boolean pou mas deixnei an exei gemisei  


	Student** array_of_s_in_floor;                                     // pinakas deiktwn se mathites tou orofou 
	Classroom* p_cl1;                                                  // deiktes se kathe taksh einai public giati tha xreiastei na exei prosvash to
	Classroom* p_cl2;                                                   // sxoleio
	Classroom* p_cl3;
	Classroom* p_cl4;
	Classroom* p_cl5;
	Classroom* p_cl6;
	Classroom* p_cl7;
	Classroom* p_cl8;
	Classroom* p_cl9;
	Classroom* p_cl10;
	Classroom* p_cl11;
	Classroom* p_cl12;
	Classroom* p_cl13;
	Classroom* p_cl14;
	Classroom* p_cl15;
	Classroom* p_cl16;
	Classroom* p_cl17;
	Classroom* p_cl18;

private:
	int f_no;                               // arithmos orofou
	int Ccorr;                              // xwrhtikothta diadromou
	int Cclass;                             // xwrhtikothta takshs 
	Corridor* p_to_corr;                    // deikths se 

	Corridor* p_to_corr1;                   // deiktes se kathe orofo
	Corridor* p_to_corr2;                   
	Corridor* p_to_corr3;

	Classroom* p_to_classroom;               // deikths se taksh   








};

//Class Corridor ==================================================================================

class Corridor {


public:

	Corridor(int in_c_no, int in_Ccorr);                    // constructor diadromou
	~Corridor();                                            // destructor diadromou    

	void enter_corridor(Student* s);                        // h enter tou diadromou

	void get_classroom(int in_c_no, int in_Cclass, Classroom* p);      // tha parei thn taksh apo ton orofo 

	void exit(int i, Student* s);                                      // h exit tou diadromou

	void call_enter_classroom(int i);                                  // kalei thn enter ths takshs

	bool is_full = false;                                               // boolean gia na kseroume pote exei gemisei


private:
	Student** array_of_s_in_corridor;                                    // pinakas deiktwn twn mathitwn ston diadromo           
	int c_no;                                                            // arithmos diadromou (orofou)   
	int class_no;                                                        // arithmos takshs   
	int Ccorr;                                                           // xwrithkothta diadromou    
	int Cclass;                                                          // xwrithkothta takshs 
	Classroom* p_to_classroom;                                           // deikths se taksh


};
// Class Classroom ====================================================================================

class Classroom {

public:
	Classroom(int in_c_no, int in_Cclass);                               // constructor takshs               
	~Classroom();                                                        // destructor takshs       
	void enter_classroom(Student* s);                                    // enter ths takshs

	void place_teacher(Teacher* t);                                      // place gia ton daskalo    

	bool is_full = false;                                                 // boolean gia na kseroume pote einai gemath h taksh      

private:
	Student** array_of_p_in_classroom;                                    // pinakas deiktwn se taksh  
	Teacher* teacher;                                                     // deikths se daskalo  
	int Cclass;                                                           // xwrhtikothta takshs  
	int c_no;                                                             // arithmos takshs  
};






//Class Student=====================================================================


class Student
{
public:

	Student();              // constructor mathiti
	~Student();             // destructor mathiti
	void print();           // synarthsh print tou mathiti    
	int class_no;           // public gia na exoun prosvash oi klaseis pou to xreiazontai
	int floor_no;           // 
	string place;           // thesi tou mathiti typou string 

private:
	string name;            // to onoma einai private giati den xreiazetai na exoun prosvash oi alles klaseis



};



//Class Teacher======================================================================


class Teacher
{
public:
	Teacher(int in_cl_no);                  // constructor 
	~Teacher();                             // destructor    

	void print();                           // h print tou daskalou

	int cl_no;                              // public arithmos takshs kai boolean gia na gnwrizoume an exei mpei sthn taksh tou
	bool is_inside;


private:

	string name;

};
















//Main =============================================================================

int main(int argc, char* argv[]) {
	int i;
	int in_Cyard, in_Cclass, in_Ccorr, in_Cstairs;
    const int N = atoi(argv[5]);


	in_Cclass = atoi(argv[1]);
	in_Cyard = atoi(argv[2]);
	in_Cstairs = atoi(argv[3]);
	in_Ccorr = atoi(argv[4]);
    


	School school1(in_Cclass, in_Cyard, in_Cstairs, in_Ccorr,N); // dinontai ta orismata kai kataskevazetai  to sxoleio
    srand(time(NULL));

	Student** s;
	s = new Student * [N];                        // dynamikh desmeysh mnhmhs gia ton pinaka deiktwn se mathites  
	for (i = 0; i < N; i++) {

		s[i] = new Student();                     // dynamikh desmeysh mnhmhs mathitwn


	}

	Teacher** t;
	t = new Teacher * [18];
	for (i = 0; i < 18; i++)
	{
		t[i] = new Teacher(i + 1);                  // omoiws gia tous daskalous

	}


	unsigned int seed;
	seed = time(0);
	srand(seed);

	static int j = 0;
	int random = 0 , no, teachers_no;
	
	while (j < N) {																// N epanalipseis 
		no = rand() % (N/2);													// O arithmos twn mathitwn pou tha mpoun tyxaia
		for (i = 0; i < no; i++) {												// loop eisodou mathitwn   
			random = rand() % N;												// random mathiis (arithmos tou pinaka)
			if (s[random]->place == "Outside of School")						// elegxos na mhn exei ksanampei o mathitis
				school1.enter_school(s[random]);								// eisodos mathiti sto sxoleio

			
		}
		if (random % 2 == 1) {													// elegxos an tha mpei daskalos
			teachers_no = (rand() % 3) + 1;										// paradoxh pws mexri 3 daskaloi mporoun na mpoun
			 
			for (i = 0; i < teachers_no; i++) {									// loop eisodou kathigitwn
				random = rand() % 18;											// tyxaios kathigiths
				school1.place_teacher(t[random], random + 1);					// eisodos kathigiti sthn taksh

			}

		}
		j++;
	}

	school1.print_school();							// ektypwsh sxoleiou



	for (i = 0; i < N; i++) {

		delete s[i];          // katastrofh mathitwn


	}
	for (i = 0; i < 18; i++) {

		delete t[i];		// katastrofi mathitwn


	}					
	delete[] s;				// katastrofi pinaka deiktwn mathitwn
	delete[] t;				// katastrofi pinaka deiktwn daskalwn

	return 0;
}












//school code===============================================================






School::School(int in_Cclass, int in_Cyard, int in_Cstairs, int in_Ccorr, int in_N)
{



	Cclass = in_Cclass;                                        // to sxoleio pernaei ta orismata stis eswterikes metavlites tou     
	Cyard = in_Cyard;                               
	Cstairs = in_Cstairs;
	Ccorr = in_Ccorr;
    N = in_N;

	p_to_yard = new Schoolyard(Cyard);                        // dynamikh desmeysh mnhmhs gia to proaulio tis skales kai tous 3 orofous   

	p_to_stairs = new Stairs(Cstairs);                        // kataskeyazei tous xwrous pou periexei kai tous pernaei ta orismata   

	p_to_floor1 = new Floor(1, Ccorr, Cclass);
	p_to_floor2 = new Floor(2, Ccorr, Cclass);
	p_to_floor3 = new Floor(3, Ccorr, Cclass);


	p_to_yard->get_stairs(Cstairs, p_to_stairs);             // mesw ths synarthshs get stairs pernaei sto proaulio ton deikth stis skales kai thn        
                                                             // xwrhtikothta   
	p_to_stairs->get_floor(Ccorr, Cclass, p_to_floor);       // omoiws gia tis skales kai ton orofo   



	cout << "A new school is being created!!!" << endl;         

	array_of_s_in_school = new Student * [N];               // desmeysh mnhmhs gia tous mathites kai tous daskalous tou sxoleiou   
                                                            // kai arxikooiei tous deiktes se NULL    
	for (int i = 0; i < N; i++) {

		array_of_s_in_school[i] = NULL;                     
	}

	array_of_t_in_school = new Teacher * [18];

	for (int i = 0; i < 18; i++)
		array_of_t_in_school[i] = NULL;


}



School::~School()
{
	delete p_to_floor1;                             // katastrefontai oi orofoi to proaulio kai oi skales
	delete p_to_floor2;
	delete p_to_floor3;
	delete p_to_yard;
	delete p_to_stairs;
	cout << "a school is being destroyed..." << endl;

}

void School::enter_school(Student** s)
{

	array_of_s_in_school = s;
	for (int i = 0; i < 5; i++) {
		array_of_s_in_school[rand() % 5]->print();
		cout << "  is part of the array" << endl;
	}
}


void School::enter_school(Student* s)                                     
{
	int i = 0;
	while (i < N)                                         // gia na mhn ksefygoume ektos oriou tou pinaka  
	{
		if (!array_of_s_in_school[i])                     // oso yparxei kenh thesi gia mathiti mpainei sto sxoleio  
		{
			array_of_s_in_school[i] = s;                  // vazoume ton mathiti ston pinaka tou sxoleiou  
			if (array_of_s_in_school[i]->floor_no == 1)   // analoga me ton orofo tou mathiti vazoume ton deikth se orofo na deixnei ston       
				p_to_floor = p_to_floor1;                 // swsto orofo pou tha kateuthinthei o mathitis  
			else if (array_of_s_in_school[i]->floor_no == 2)
				p_to_floor = p_to_floor2;
			else
				p_to_floor = p_to_floor3;


			p_to_stairs->get_floor(Ccorr, Cclass, p_to_floor); // pername ton swsto orofo kai stis skales pou tha diaxeiristoun ton mathiti
			array_of_s_in_school[i]->place = "School";         // allazoume th thesh tou mathiti 
			

			p_to_yard->enter_yard(array_of_s_in_school[i]);    // kalei thn enter tou proauliou gia ton mathiti


			break;                                             // afou mphke o mathitis stamatame na psaxnoume gia xwro sto sxoleio 
		}
		i++;

	}



}

void School::call_print_student() {													//calling print for student				

	Student student;
	student.print();
}

void School::call_enter_yard(int i) {                                                      // kalei thn synarthsh enter tou proauliou

	Schoolyard yard1(Cyard);
	yard1.enter_yard(array_of_s_in_school[i]);



}

void School::call_get_stairs()                                                            // kalei thn synarthsh get stairs gia to proaulio
{
	Schoolyard yard(Cyard);
	yard.get_stairs(Cstairs, p_to_stairs);                                                
}

void School::call_get_floor()                                           // kalei thn synarthsh get floor gia tis skales
{

	Stairs stairs1(Cstairs);
	stairs1.get_floor(Ccorr, Cclass, p_to_floor);

}



void School::place_teacher(Teacher* t, int in_t_cl_no) {

	t_cl_no = in_t_cl_no;                                           // dexetai orisma ton daskalo kai ton arithmo ths takshs tou
	array_of_t_in_school[t_cl_no - 1] = t;
	if (!array_of_t_in_school[t_cl_no - 1]->is_inside) {            // an den exei hdh mpei sthn taksh o daskalos

		if (t_cl_no < 7) {                                          // analoga me thn taksh tou daskalou o voithitikos deikths tou orofou tha 
			p_to_floor = p_to_floor1;                               // deixnei ston antistoixo orofo
			switch (t_cl_no)                                        // analoga me thn taksh tou daskalou o orofos pou exei thn sygkekrimenh taksh
			{                                                       // tha kalesei thn place_teacher ths antistoixhs takshs
			case(1):
				p_to_floor->p_cl1->place_teacher(array_of_t_in_school[t_cl_no - 1]);  
				break;
			case(2):
				p_to_floor->p_cl2->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(3):
				p_to_floor->p_cl3->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(4):
				p_to_floor->p_cl4->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(5):
				p_to_floor->p_cl5->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(6):
				p_to_floor->p_cl6->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			}
		}
		else if (t_cl_no >= 7 && t_cl_no < 13) {                    // omoia gia ton 2o orofo
			p_to_floor = p_to_floor2;
			switch (t_cl_no)
			{
			case(7):
				p_to_floor->p_cl7->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(8):
				p_to_floor->p_cl8->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(9):
				p_to_floor->p_cl9->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(10):
				p_to_floor->p_cl10->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(11):
				p_to_floor->p_cl11->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(12):
				p_to_floor->p_cl12->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;

			}
		}
		else {
			p_to_floor = p_to_floor3;                           // omoiws kai gia ton 3o orofo
			switch (t_cl_no)
			{
			case(13):
				p_to_floor->p_cl13->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(14):
				p_to_floor->p_cl14->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(15):
				p_to_floor->p_cl15->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(16):
				p_to_floor->p_cl16->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(17):
				p_to_floor->p_cl17->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			case(18):
				p_to_floor->p_cl18->place_teacher(array_of_t_in_school[t_cl_no - 1]);
				break;
			}

		}



	}
}

void School::call_place_teacher(Teacher* t) {               // kalei thn place teacher ths klashs taksh
	Classroom c(t_cl_no, Cclass);
	c.place_teacher(t);

}

void School::print_school()                                 // ektypwsh tou sxolikou kthriou
{
	

	cout << " School life consists of :" << endl;           // h ylopoihsh pou skefthka gia thn print einai analoga me ton xwro pou thelw na ektypwsw 
	cout << " People in Schoolyard are :" << endl;          // tha koitaw gia tous mathites se poion xwro vriskontai kai an einai ston xwro pou
	for (int i = 0; i < N; i++) {                           // ektypwnw tha ektypwnetai enw gia tous daskalous an einai mesa tha ektypwnetai
		if (array_of_s_in_school[i]) {                              // sthn sygkekrimenh main tha mpoun oloi oi daskaloi   
			if (array_of_s_in_school[i]->place == "Schoolyard") {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	cout << "People in Stairs are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Stairs") {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}

	cout << "Floor nummber 1 contains : " << endl;
	cout << "People in Corridor are : " << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Corridor" && array_of_s_in_school[i]->floor_no == 1) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	cout << "People in Classroom 1 are :" << endl;
	for (int i = 0; i < N; i++) {
		if(array_of_s_in_school[i]){
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 1) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[0]) {
		if (array_of_t_in_school[0]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[0]->print();
		}
			
	}
	cout << "People in Classroom 2 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 2) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}

		
	}
	if (array_of_t_in_school[1]) {
		if (array_of_t_in_school[1]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[1]->print();
		}

	}
	cout << "People in Classroom 3 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 3) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[2]) {
		if (array_of_t_in_school[2]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[2]->print();
		}

	}
	cout << "People in Classroom 4 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 4) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[3]) {
		if (array_of_t_in_school[3]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[3]->print();
		}

	}
	cout << "People in Classroom 5 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 5) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[4]) {
		if (array_of_t_in_school[4]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[4]->print();
		}

	}
	cout << "People in Classroom 6 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 6) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[5]) {
		if (array_of_t_in_school[5]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[5]->print();
		}

	}
	cout << "Floor nummber 2 contains : " << endl;
	cout << "People in Corridor are : " << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Corridor" && array_of_s_in_school[i]->floor_no == 2) {
				array_of_s_in_school[i]->print();
				cout << endl;
	
			}
		}
		
	}
	


	cout << "People in Classroom 7 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 7) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[6]) {
		if (array_of_t_in_school[6]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[6]->print();
		}

	}
	cout << "People in Classroom 8 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 8) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[7]) {
		if (array_of_t_in_school[7]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[7]->print();
		}

	}
	cout << "People in Classroom 9 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 9) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[8]) {
		if (array_of_t_in_school[8]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[8]->print();
		}

	}
	cout << "People in Classroom 10 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 10) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[9]) {
		if (array_of_t_in_school[9]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[9]->print();
		}

	}
	cout << "People in Classroom 11 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 11) {
				array_of_s_in_school[i]->print();
				cout << endl;
;
			}
		}

		
	}
	if (array_of_t_in_school[10]) {
		if (array_of_t_in_school[10]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[10]->print();
		}

	}
	cout << "People in Classroom 12 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 12) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[11]) {
		if (array_of_t_in_school[11]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[11]->print();
		}

	}
	cout << "Floor nummber 3 contains : " << endl;
	cout << "People in Corridor are : " << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Corridor" && array_of_s_in_school[i]->floor_no == 3) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}

		
	}
	cout << "People in Classroom 13 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 13) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[12]) {
		if (array_of_t_in_school[12]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[12]->print();
		}

	}
	cout << "People in Classroom 14 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 14) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[13]) {
		if (array_of_t_in_school[13]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[13]->print();
		}

	}
	cout << "People in Classroom 15 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 15) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
	}
	if (array_of_t_in_school[14]) {
		if (array_of_t_in_school[14]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[14]->print();
		}

	}
		
	cout << "People in Classroom 16 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 16) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
			
	}
	if (array_of_t_in_school[15]) {
		if (array_of_t_in_school[15]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[15]->print();
		}

	}

	cout << "People in Classroom 17 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 17) {
				array_of_s_in_school[i]->print();
				cout << endl;
				
			}
		}
		
	}
	if (array_of_t_in_school[16]) {
		if (array_of_t_in_school[16]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[16]->print();
		}

	}
	cout << "People in Classroom 18 are :" << endl;
	for (int i = 0; i < N; i++) {
		if (array_of_s_in_school[i]) {
			if (array_of_s_in_school[i]->place == "Classroom" && array_of_s_in_school[i]->class_no == 18) {
				array_of_s_in_school[i]->print();
				cout << endl;

			}
		}
		
	}
	if (array_of_t_in_school[17]) {
		if (array_of_t_in_school[17]->is_inside) {
			cout << "The teacher is :";
			array_of_t_in_school[17]->print();
		}

	}


}




// Schoolyard code============================================================





Schoolyard::Schoolyard(int in_Cyard)
{
	Cyard = in_Cyard;


	cout << "A new Schoolyard has been created! " << endl;                  

	array_of_s_in_yard = new Student * [Cyard];                              // pinakas deiktwn se mathites mesa sto proaulio

	for (int i = 0; i < Cyard; i++)
		array_of_s_in_yard[i] = NULL;                                       // arxikopoihsh NULL
}




void Schoolyard::enter_yard(Student* s)
{
	int i = 0;
	while (i < Cyard)
	{
		if (!array_of_s_in_yard[i]) {

			array_of_s_in_yard[i] = s;													    // vazw ton mathiti ston pinaka tou proauliou
			array_of_s_in_yard[i]->place = "Schoolyard";									// allazoume thn topothesia tou mathiti
			
			array_of_s_in_yard[i]->print();													//ektypwsh tis eisodou mathiti sto sxoleio
			cout << " enters School" << endl;

			array_of_s_in_yard[i]->print();													//ektypwsh tis eisodou mathiti sto proaulio
			cout << " enters Schoolyard" << endl;

			if (!p_to_stairs->is_full) {													// elegxos an oi skales exoun xwro

				this->exit(i, array_of_s_in_yard[i]);                                       // o mathitis vgainei apo to proaulio


			}
			break;
		}
		i++;
	}

}

void Schoolyard::call_print_student() {													//kalei thn print gia mathiti			

	Student student;
	student.print();
}
void Schoolyard::exit(int i, Student* s) {                            // h exit tou proaulio kalei thn enter tou                                        
                                                                      // klhmakostasiou kai allazei ton deikth pali se NULL       
                                                                      // afou efyge o mathitis apo ton xwro  
	array_of_s_in_yard[i]->print();
	cout << " exits Schoolyard" << endl;

	p_to_stairs->enter(array_of_s_in_yard[i]);
	array_of_s_in_yard[i] = NULL;


}

void Schoolyard::get_stairs(int in_Cstairs, Stairs* p)               // To proaulio dexetai to Cstairs kai ton pointer stis skales
{
	Cstairs = in_Cstairs;                                               
	p_to_stairs = p;

}



Schoolyard::~Schoolyard()                                                   
{
	cout << "A Schoolyard to be destroyed" << endl;
}

void Schoolyard::call_enter_stairs(int i, int in_Cstairs) {            // kalei thn enter tou klimakostasiou
                                                                                                    

	Stairs stairs1(in_Cstairs);
	stairs1.enter(array_of_s_in_yard[i]);
}













// Code of Stairs=========================================================================



Stairs::Stairs(int in_Cstairs)
{
	Cstairs = in_Cstairs;

	array_of_s_in_stairs = new Student * [Cstairs];                             // desmeuoume mnhmh gia antikeimena typou mathitis

	cout << "Stairs have been created!" << endl;                                // kai arxikopoieitai me NULL    

	for (int i = 0; i < Cstairs; i++)
		array_of_s_in_stairs[i] = NULL;
}

Stairs::~Stairs()                                                              // destructor tou klimakwstasiou
{


	cout << "Stairs to be destroyed !" << endl;

}
void Stairs::call_print_student() {													//kalei thn print gia student				

	Student student;
	student.print();
}

void Stairs::enter(Student* s)                                                 // h enter tou klimakostasiou      
{
	int i = 0;
	while (i < Cstairs)
	{
		if (array_of_s_in_stairs[i] == NULL) {                                 // elegxei gia kathe thesi tou pinaka an exei xwro 

			array_of_s_in_stairs[i] = s;                                       // pairnei ton mathiti an xwraei     

			array_of_s_in_stairs[i]->place = "Stairs";                         // allazei to pou vrisketai o mathitis 

			array_of_s_in_stairs[i]->print();                                  //  ektypwsh mathiti
			cout << " enters Stairs" << endl;

			if (i == (Cstairs - 1)){
               if(p_to_floor->is_full)                                         // an einai i teleutaia thesi tou pinaka kai den exei xwro na 
			        is_full = true;                                            // proxwrisei epistrefei pws exei gemisei 
            }
			if (!p_to_floor->is_full) {
				this->exit(i, array_of_s_in_stairs[i]);                         // an o orofos exei xwro kalei thn exit ths skalas


			}
			break;

		}

		i++;
	}


}

void Stairs::exit(int i, Student* s)                            // h exit tis skalas kanei mia ektypwsh kai 
{                                                               // kalei thn enter tou orofou   
	array_of_s_in_stairs[i]->print();
	cout << " exits Stairs" << endl;
	p_to_floor->enter_floor(array_of_s_in_stairs[i]);
	array_of_s_in_stairs[i] = NULL;



}
void Stairs::get_floor(int in_Ccorr, int in_Cclass, Floor* p)               // oi skales pairnoun ton deikth se orofo mazi me tis
{                                                                           // xwrhtikothtes 
	p_to_floor = p;
	Ccorr = in_Ccorr;
	Cclass = in_Cclass;

}

// Code of Floor=========================================================================




Floor::Floor(int in_f_no, int in_Ccorr, int in_Cclass)                      // constructor tou sxoleiou
{


	Ccorr = in_Ccorr;
	Cclass = in_Cclass;
	f_no = in_f_no;


	cout << "A floor has been created!" << endl;                            // kataskevazei tous xwrous tou diadromos kai takseis 
	if (f_no == 1) {                                                        // analoga ton orofo
		p_to_corr1 = new Corridor(1, Ccorr);
		p_cl1 = new Classroom(1, Cclass);
		p_cl2 = new Classroom(2, Cclass);
		p_cl3 = new Classroom(3, Cclass);
		p_cl4 = new Classroom(4, Cclass);
		p_cl5 = new Classroom(5, Cclass);
		p_cl6 = new Classroom(6, Cclass);

	}
	else if (f_no == 2) {


		p_to_corr2 = new Corridor(2, Ccorr);
		p_cl7 = new Classroom(7, Cclass);
		p_cl8 = new Classroom(8, Cclass);
		p_cl9 = new Classroom(9, Cclass);
		p_cl10 = new Classroom(10, Cclass);
		p_cl11 = new Classroom(11, Cclass);
		p_cl12 = new Classroom(12, Cclass);
	}
	else {
		p_to_corr3 = new Corridor(3, Ccorr);
		p_cl13 = new Classroom(13, Cclass);
		p_cl14 = new Classroom(14, Cclass);
		p_cl15 = new Classroom(15, Cclass);
		p_cl16 = new Classroom(16, Cclass);
		p_cl17 = new Classroom(17, Cclass);
		p_cl18 = new Classroom(18, Cclass);
	}
	array_of_s_in_floor = new Student * [Ccorr];                        // kataskevazei ena pinaka deiktwn se mathites

	for (int i = 0; i < Ccorr; i++)                                     // ton arxikopoiei NULL alla yparxei kathara gia 
		array_of_s_in_floor[i] = NULL;                                  // na pernaei tous mathites parakatw


}

Floor::~Floor()
{
	delete p_to_corr1;                                                  // katastrofi twn xwrwn tou orofou
	delete p_to_corr2;
	delete p_to_corr3;

	delete p_cl1;
	delete p_cl2;
	delete p_cl3;
	delete p_cl4;
	delete p_cl5;
	delete p_cl6;
	delete p_cl7;
	delete p_cl8;
	delete p_cl9;
	delete p_cl10;
	delete p_cl11;
	delete p_cl12;
	delete p_cl13;
	delete p_cl14;
	delete p_cl15;
	delete p_cl16;
	delete p_cl17;
	delete p_cl18;
	cout << "A floor to be destroyed" << endl;


}

void Floor::enter_floor(Student* s) {               // h enter tou orofou kanei elegxo analoga me to pou prepei na proxwrisei o mathitis 
                                                    // den krataei mathites kai an den exei xwro o diadromos tou thetoume pws exei gemisei o
                                                    // orofos

	int i = 0;
	while (i < Ccorr)

	{

		if (!array_of_s_in_floor[i]) {
			switch (s->floor_no)
			{
			case(1):
				array_of_s_in_floor[i] = s;        // nalagoa me ton orofo tou mathiti vazei ton voithitiko deikth se diadromo 
				p_to_corr = p_to_corr1;            // na deixnei ston analogo diadromo
				switch (s->class_no)               // omoiws kai gia tis takseis     
				{
				case(1):                                
					p_to_classroom = p_cl1;                 
					p_to_corr->get_classroom(1, Cclass, p_to_classroom);
					break;
				case(2):
					p_to_classroom = p_cl2;
					p_to_corr->get_classroom(2, Cclass, p_to_classroom);
					break;
				case(3):
					p_to_classroom = p_cl3;
					p_to_corr->get_classroom(3, Cclass, p_to_classroom);
					break;
				case(4):
					p_to_classroom = p_cl4;
					p_to_corr->get_classroom(4, Cclass, p_to_classroom);
					break;
				case(5):
					p_to_classroom = p_cl5;
					p_to_corr->get_classroom(5, Cclass, p_to_classroom);
					break;
				case(6):
					p_to_classroom = p_cl6;
					p_to_corr->get_classroom(6, Cclass, p_to_classroom);
					break;
				}

				if (!p_to_corr->is_full) {                         // an den einai gematos o diadromos kalei thn enter tou diadromou         

					p_to_corr->enter_corridor(array_of_s_in_floor[i]);

					array_of_s_in_floor[i] = NULL;
				}
				else
					is_full = true;                               // alliws epistrefei pws exei gemisei  
				break;



			case(2):
				array_of_s_in_floor[i] = s;
				p_to_corr = p_to_corr2;
				switch (s->class_no)

				{
				case(7):
					p_to_classroom = p_cl7;
					p_to_corr->get_classroom(7, Cclass, p_to_classroom);
					break;
				case(8):
					p_to_classroom = p_cl8;
					p_to_corr->get_classroom(8, Cclass, p_to_classroom);
					break;
				case(9):
					p_to_classroom = p_cl9;
					p_to_corr->get_classroom(9, Cclass, p_to_classroom);
					break;
				case(10):
					p_to_classroom = p_cl10;
					p_to_corr->get_classroom(10, Cclass, p_to_classroom);
					break;
				case(11):
					p_to_classroom = p_cl11;
					p_to_corr->get_classroom(11, Cclass, p_to_classroom);
					break;
				case(12):
					p_to_classroom = p_cl12;
					p_to_corr->get_classroom(12, Cclass, p_to_classroom);
					break;
				}

				if (!p_to_corr->is_full) {

					p_to_corr->enter_corridor(array_of_s_in_floor[i]);
					array_of_s_in_floor[i] = NULL;
				}
				else
				{
					is_full = true;
				}
				break;
			case(3):
				array_of_s_in_floor[i] = s;
				p_to_corr = p_to_corr3;

				switch (s->class_no)
				{
				case(13):
					p_to_classroom = p_cl13;
					p_to_corr->get_classroom(13, Cclass, p_to_classroom);
					break;
				case(14):
					p_to_classroom = p_cl14;
					p_to_corr->get_classroom(14, Cclass, p_to_classroom);
					break;
				case(15):
					p_to_classroom = p_cl15;
					p_to_corr->get_classroom(15, Cclass, p_to_classroom);
					break;
				case(16):
					p_to_classroom = p_cl16;
					p_to_corr->get_classroom(16, Cclass, p_to_classroom);
					break;
				case(17):
					p_to_classroom = p_cl17;
					p_to_corr->get_classroom(17, Cclass, p_to_classroom);
					break;
				case(18):
					p_to_classroom = p_cl18;
					p_to_corr->get_classroom(18, Cclass, p_to_classroom);
					break;

				}

				if (!p_to_corr->is_full) {

					p_to_corr->enter_corridor(array_of_s_in_floor[i]);
					array_of_s_in_floor[i] = NULL;
				}
				else
				{
					is_full = true;
				}
				break;
			}


			break;

		}


		i++;

	}
}



// Code of Corridor =========================================================================

Corridor::Corridor(int in_c_no, int in_Ccorr) {

	c_no = in_c_no;                                                 
	Ccorr = in_Ccorr;

	cout << " A Corridor has been created " << endl;


	array_of_s_in_corridor = new Student * [Ccorr];                 // o diadromos dhmiourgei ton pinaka deiktwn se mathith    
                                                                    // kai tous arxikopoiei NULL(kenos diadromos)
	for (int i = 0; i < Ccorr; i++)
		array_of_s_in_corridor[i] = NULL;

}



Corridor::~Corridor()
{

	cout << "A Corridor to be destroyed" << endl;

}


void Corridor::enter_corridor(Student* s) {                     // i enter tou diadromou                
	int i = 0;
	while (i < Ccorr)                                           // gia kathe thesi tou pinaka
	{
		if (!array_of_s_in_corridor[i]) {                       //        

			array_of_s_in_corridor[i] = s;

			array_of_s_in_corridor[i]->place = "Corridor";

			array_of_s_in_corridor[i]->print();

			cout << " enters Corridor  " << c_no << endl;

			
			if (i == (Ccorr - 1)){                              // an einai h teleutaia thesh tou pinaka kai h taksh pou thelei na
			    if(p_to_classroom->is_full)                     // paei o mathitis einai gemath o diadromos exei gemisei    
            	    is_full = true;

            }
			if (!p_to_classroom->is_full) {                     // an exei xwro i taksi kalei thn exit tou diadromou
				this->exit(i, array_of_s_in_corridor[i]);


			}

			break;
		}

		i++;
	}




}
void Corridor::get_classroom(int in_c_no, int in_Cclass, Classroom* p) {        // o diadromos pairnei apo ton orofo ton deikth sthn 
                                                                                // taksi gia ton ekastote mathiti        
	class_no = in_c_no;
	Cclass = in_Cclass;
	p_to_classroom = p;

}


void Corridor::exit(int i, Student* s) {                    // h exit tou diadromou kanei mia ektypwsh kai kalei thn enter ths takshs
	array_of_s_in_corridor[i]->print();
	cout << " exits Corridor!" << endl;
	p_to_classroom->enter_classroom(s);
	array_of_s_in_corridor[i] = NULL;






}


void Corridor::call_enter_classroom(int i) {                // kalei thn enter ths takshs 

	Classroom c(c_no, Cclass);
	c.enter_classroom(array_of_s_in_corridor[i]);


}
// Code of Classroom ===========================================================================

Classroom::Classroom(int in_c_no, int in_Cclass) {                 

	Cclass = in_Cclass;                                             //o constructor pernaei ta orismata stis eswterikes metavlites
	c_no = in_c_no;
	


	cout << " A New Classroom has been created!!" << endl;

	array_of_p_in_classroom = new Student * [Cclass];             // desmeuei mnhmh gia ton pinaka deiktwn se mathites  

	for (int i = 0; i < Cclass; i++)                              //   ton arxikopoiei adeio
		array_of_p_in_classroom[i] = NULL;

}

Classroom::~Classroom()
{


	cout << " A Classroom to be destroyed " << endl;

}
void Classroom::enter_classroom(Student* s)
{
	int i = 0;
	while (i < Cclass)                             // elegxos gia kathe thesi tou pinaka 
	{
		if (array_of_p_in_classroom[i] == NULL) {         // an i thesi einai kenh  

			array_of_p_in_classroom[i] = s;               // mpainei o mathitis  

			array_of_p_in_classroom[i]->place = "Classroom";    // thetei ton xwro pou vrisketai o mathitis na einai h taksh

			array_of_p_in_classroom[i]->print();            
			cout << " enters Classroom " << c_no << endl;
			if (i == (Cclass - 1))                        // an einai i teleutaia thesi tou pinaka epistrefei pws einai gemath  
			{
				is_full = true;
			}
			break;
		}
		i++;
	}
}

void Classroom::place_teacher(Teacher* t)                   // topothetei ton daskalo thn taksh 
{                                                               
	teacher = t;

	teacher->is_inside = true;                              // vazei ton daskalo na einai mesa sthn taksh
	t->print();
	cout << " was placed in Classroom " << t->cl_no << endl;
	is_full = true;                                         // kai deixnei pws einai gemath wste na mhn mporei na mpei mathitis



}


// Student code==========================================================================


string names[40] = { "Mike", "Kwstas", "Panos","Giannis","lampros","Giorgos","Axileas","Periklis","Alexis","iraklis","Tasos","Pavlos","Dimitris","Grigoris  ","Vaggelis  ","Alexandros","Manos","Marios","Andreas" ,"Panagiotis" "Maria", "Dimitra","Mariana","Giota","Margarita ","Iliana","Efthimia","Alexandra ","Lamprini","Roza","Lili","Katia","Asimina","Lia","Aggeliki","Sia","Eva","Erieta","Paraskevi ","Xrysa"  };



Student::Student()
{

 
	name = names[rand() % 40];      // arxikopoiei to onoma me ena tyxaio apo ena pinaka apo strings

	floor_no = rand() % 3 + 1;      // pairnei enan tyxaio orofo apo 1 ews 3
	if (floor_no == 1)              // analoga ton orofo pairnei kai mia tyxaia taksi
		class_no = rand() % 6 + 1;
	if (floor_no == 2)
		class_no = rand() % 6 + 7;
	if (floor_no == 3)
		class_no = rand() % 6 + 13;
	place = "Outside of School";

	cout << "A new Student has been created! :" << name << " floor no :" << floor_no << " class no :" << class_no << endl;
}
Student::~Student() {

	cout << "A Student to be destroyed! :" << name << " floor no :" << floor_no << " class no :" << class_no << endl;



}

void Student::print()
{
	cout << "Student: " << name ;
}



//Code of Teacher ===================================================================================



Teacher::Teacher(int in_cl_no)  // o daskalos arxikopoieitai me to onoma tou tyxaio apo ton pinaka 
{                               // thn taksh tha thn parei apo th main     
	name = names[rand() % 40];  // kai to boolean an einai mesa pou arxikopoieitai false    
	cl_no = in_cl_no;
	is_inside = false;

	cout << "A Teacher has been Created!!   " << name << "  class no " << cl_no << endl;
}

Teacher::~Teacher()
{

	cout << " A Teacher to be destroyed!!" << endl;


}

void Teacher::print() {

	cout << name << endl;

}
