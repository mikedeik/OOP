#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>


using namespace std;


//Class Student ==========================================================

string boynames[20] = { "Mike      ", "Kwstas    ", "Panos     ","Giannis   ","lampros   ","Giorgos   ","Axileas   ","Periklis  ","Alexis    ","iraklis   ","Tasos     ","Pavlos    ","Dimitris  "
					,"Grigoris  ","Vaggelis  ","Alexandros","Manos     ","Marios    ","Andreas   " ,"Panagiotis" };

string girlnames[20] = { "Maria     ", "Dimitra   ","Mariana   ","Giota     ","Margarita ","Iliana    ","Efthimia  ","Alexandra ","Lamprini  ","Roza      ","Lili      ",
						"Katia     ","Asimina   ","Lia       ","Aggeliki  ","Sia       ","Eva       ","Erieta    ","Paraskevi ","Xrysa     " };





class Student {

public:

	Student(int in_cl_no, string in_gender) : cl_no(in_cl_no), gender(in_gender), is_naughty(false) {					// constructor mathiti pairnei ar. taksis kai fylo apo th main
		if (gender == "boy")
			name = boynames[rand() % 20];															// arxikopoihsh onomatos gia agori
		if (gender == "girl")
			name = girlnames[rand() % 20];															// arxikopoihsh onomatos gia agori
		cout << "A student has been created!" << endl;
	}

	~Student()	{																					// destructor mathiti
		cout << "A student to be destroyed" << endl;
	}

	
	void print() const {																			// ektypwsh mathiti	
		if(is_naughty)
			cout << name << " class no : " << cl_no << " the gender is " << gender << " is naughty!";
		else
			cout << name << " class no : " << cl_no << " the gender is " << gender << " is quiet!  ";
	}

	bool is_naughty;																		// metavlhth elegxou an einai ataktos		// public giati xreiazetai prosvash apo tis akolouthies
	string gender;																			// to fylo tou mathiti se string			// public giati xreiazetai prosvash apo tis akolouthies
	int cl_no;																				// h taksh tou mathiti se int               // public giati xreiazetai prosvash apo thn big sequence
private:
	
	
	string name;																					// to onoma tou mathiti typou string private giati den theloume na exei prosvasi kapoia klash




};


// Class Sequence of students ==========================================================================
class Sequence {

public:
	friend class bigSequence;													// dhlwnoume friend class thn big sequence giati xreiazetai na kanei allages stis akolouthies		
																				// eidikotera tha prepei na allaksei ta zeugaria metaksy akolouthiwn opws kai to athroisma ataksias
																				
	
	Sequence(Student** s, int in_cl_no, int X,double Tmessy , double Tquiet) : start(NULL), last(NULL), size(0), s_in(X), array_of_students(s), cl_no(in_cl_no), mess(Tmessy),quiet(Tquiet) {
		cout << " A sequence has been created!!!!!!!!!!!! " << endl;            // constructor akolouthias zeugariwn me initializer list
																				// pairnei orismata ton pinaka mathitwn pou ths analogoun kai ton arithmo takis
																				// opws kai ta pososta Tmessy,Tquiet kai kataskeuazei ta zeugaria
		array_of_students = s;
		for (int i = 0; i < s_in; i += 2) {
			if (i % 4 == 0) {													// theloume h katataksh twn zeugariwn na einai swsth apo thn arxh opote 	
				create_pairs(array_of_students[i], array_of_students[i + 1]);	// ftiaxnw ta zeugaria enalax agori/koritsi > koritsi/agori h to antistrofo	

			}																	// 				
			else
			{
				create_pairs(array_of_students[i + 1], array_of_students[i]);

			}


		}

		if (s_in % 4 == 1)														// dinoume NULL th mia thesi zeugariou analoga me to pou prepei na einai to keno
			last->data[1] = NULL;
		if (s_in % 4 == 3)
			last->data[0] = NULL;



	}
	~Sequence() {
		Pair* t1 = start;														// destructor akolouthias katastrefoume ta zeugaria
		while (t1 != NULL)
		{
			Pair* t2 = t1;
			t1 = t1->next;
			delete t2;

		}


		cout << "a sequence to be detroyed" << endl;
	}
	void create_pairs(Student* s1, Student* s2) {								// kataskeuh twn zeugariwn h alliws eisodos tou "Node" zeugariwn sto telos ths "listas" akolouthia 

		Pair* t1 = new Pair(s1, s2);

		int i = 1;
		if (start == NULL) {
			start = t1;
			t1->index = i;

		}
		else
		{
			i = 2;
			Pair* t2 = start;
			while (t2->next != NULL) {

				t2 = t2->next;
				i++;
			}
			t2->next = t1;
			t1->index = i;
		}
		last = t1;
		size++;
	}
	void print_pairs() const {													// ektypwnei ta zeugaria ths listas

		Pair* s;
		s = start;



		while (s != NULL)
		{
			if (s_in % 2 == 0) {												// an o arithmos mathitwn sth lista einai zygos ektypwnei kai tous duo mathites
				cout << "Pair " << s->index << ".";
				s->data[0]->print();
				s->data[1]->print();
				cout << endl;
				s = s->next;
			}
			else {

				if (s->next == NULL) {											// an o arithimos mathitwn einai perittos elegxoume th thesi pou einai kenh kai ektypwnoume analoga
					if (s_in % 4 == 3) {												
						cout << "Pair " << s->index << ".";
						cout << "                                                             ";
						s->data[1]->print();
						cout << endl;
						break;
					}
					if (s_in % 4 == 1) {
						cout << "Pair " << s->index << ".";
						s->data[0]->print();
						cout << endl;
						break;
					}
				}


				else
				{
					cout << "Pair " << s->index << ".";
					s->data[0]->print();
					s->data[1]->print();
					cout << endl;
					s = s->next;
				}

			}



		}
		double students = s_in + 0.0;													
		double naughty = my_sum + 0.0;
		cout << naughty / students << endl;
		if (naughty / students < quiet) cout << "What a quiet class!" << endl;
		else if (naughty / students > mess) cout << "What a mess!!" << endl;
		else cout << "Please be quiet!" << endl;
		
	}
	void insert_pair(Student* s1, Student* s2, int index) {						// eisagei zeugari se dedomenh thesi ths akolouthias
		Pair* temp = new Pair(s1, s2);
		Pair* temp1 = start;
		if (index == 1) {
			temp->next = temp1;
			start = temp;
			temp->index = 1;
			while (temp->next != NULL) {
				temp->next->index++;
				temp = temp->next;
			}

		}
		else {
			while (temp1->index != index - 1)
				temp1 = temp1->next;
			temp->next = temp1->next;
			temp1->next = temp;
			temp->index = index;
			while (temp->next != NULL) {
				temp->next->index++;
				temp = temp->next;
			}
		}
		size++;

	}
	

	void delete_pair(int i) {                                                 // diagrafei zeugari se dedomenh thesi ths akolouthias
		Pair* temp = start;
		if (i == 1) {
			start = start->next;
			delete temp;
		}
		else {
			while (temp->index != i - 1)
				temp = temp->next;
			if (i == size) {
				Pair* temp2 = temp->next;
				temp->next = NULL;
				delete temp2;

			}
			else
			{
				Pair* temp2;
				temp2 = temp->next;
				temp->next = temp2->next;
				while (temp->next != NULL) {
					temp->next->index--;
					temp = temp->next;
				}
				delete temp2;
			}

		}
		size--;


	}



	bool check_continuous_pairs() {												// elegxos an uparxoun 3+ synexomena zeugaria epistrefei true an yparxoun h false an oxi
		Pair* temp1 = start;
		while (temp1 != NULL)
		{
			Pair* temp2 = temp1;
			if (temp2->next != NULL && temp2->data[0] != NULL && temp2->data[1] != NULL) {
				if (temp2->naughty_pair) {
					temp2 = temp2->next;
					if (temp2 != NULL) {
						if (temp2->next != NULL && temp2->data[0] != NULL && temp2->data[1] != NULL) {
							if (temp2->naughty_pair) {
								temp2 = temp2->next;
								if (temp2->data[0] != NULL && temp2->data[1] != NULL) {
									if (temp2->naughty_pair) {
										return true;
										break;
									}


								}
							}


						}

					}
				}

			}
			temp1 = temp1->next;
		}
		return false;
	}

	int check_amount_of_naughty_pairs() {										// elegxei posa zeugaria einai atakta kai epistrefei to sunolo autwn

		int counter = 0;														
		Pair* temp = start;
		while (temp != NULL) {

			if (temp->naughty_pair)
				counter++;


			temp = temp->next;
		}
		return counter;
	}

	void set_naughty_pair() {													// thetei an ena zeugari einai atakto an kai oi duo mathites einai ataktoi
		Pair* temp = start;
		while (temp != NULL) {
			if (temp->data[0] != NULL && temp->data[1] != NULL) {
				if (temp->data[0]->is_naughty == true && temp->data[1]->is_naughty == true)
					temp->naughty_pair = true;
				else
					temp->naughty_pair = false;
				
			}
			temp = temp->next;
		}
	}

	void swap_pairs() {															// allazei thesi se 2 zeugaria tis akolouthias	 (tha tin kalesei h akolouthia akolouthiwn)	
		Student* s1;															// ftiaxnoume 2 poiters se mathites gia na ginei h allagh	
		Student* s2;


		unsigned seed = time(0);
		srand(seed);
		Pair* temp1 = start;													// ksekinwntas apo to prwto zeugari
		while (temp1 != NULL) {													// oso o pointer den einai NULL (to proigoumeno zeugari den einai kai to teleutaio ths akolouthias)
			int count = 0;
			if (temp1->data[0] != NULL && temp1->data[1] != NULL) {				// an yparxoun mathites kai stis duo theseis 
				if (temp1->data[0]->is_naughty && temp1->data[1]->is_naughty) {	// an to zeugari einai atakto
					Pair* temp = start;
					int random = rand() % (s_in / 2);							// dhmiourgia random thesis sthn akolouthia pou an einai idia me thn the auth tou zeugariou pou theloume na allaksoume
					while (random == temp1->index - 1) {						
						random = rand() % (s_in / 2);
					}
					while (temp != NULL) {										// psaxoume tyxaio zeugari sthn akolouthia  	
						if (count == random) {
							if (temp1->data[0]->gender == temp->data[0]->gender) {  // an h diataksh einai h idia
								s1 = temp->data[0];
								s2 = temp->data[1];
								temp->data[0] = temp1->data[0];
								temp->data[1] = temp1->data[1];
								cout << "Pair ";
								temp->data[0]->print();
								temp->data[1]->print();								// analogws ginetai h allagh twn zeugariwn kai teleiwnei h ataksia tous
								cout << " was moved!" << endl;
								temp->data[0]->is_naughty = false;
								temp->data[1]->is_naughty = false;
								my_sum += 2;										// prosthetoume pontous ataksias sthn taksh tous	
								temp1->data[0] = s1;
								if (temp1->data[0]->is_naughty) {					// an oi mathites tou zeugariou me tous opoious antimetathesame htan ataktoi 	
									temp1->data[0]->is_naughty = false;				// teleiwnei h ataksia tous kai prosthetoun pontous ataksias
									my_sum += 1;
								}
								temp1->data[1] = s2;
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									my_sum += 1;
								}
								cout << "Pair ";
								temp1->data[0]->print();
								temp1->data[1]->print();
								cout << " was moved!" << endl;
								break;
							}
							else													// an h diataksh twn zeugariwn einai antistrofh ginontai oi analoges energeies
							{
								s1 = temp->data[0];
								s2 = temp->data[1];
								temp->data[0] = temp1->data[1];
								temp->data[1] = temp1->data[0];
								temp->data[0]->is_naughty = false;
								temp->data[1]->is_naughty = false;
								temp1->data[0] = s2;
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									my_sum++;
								}
								temp1->data[1] = s1;
								if (temp1->data[1]->is_naughty) {
									temp1->data[1]->is_naughty = false;
									my_sum++;
								}
								break;
							}
						}
						temp = temp->next;
						count++;
					}


				}


			}

			temp1 = temp1->next;
		}



	}


	Student** get_pair(int index) {													// pairnei orizma thn thesi pou zitame kai epistrefei ton pinaka mathitwn (pointer se mathites) pou exei
		Pair* temp = start;
		while (temp->index != index) {
			temp = temp->next;

		}

		Student** s = new Student * [2];
		s[0] = temp->data[0];
		s[1] = temp->data[1];
		return s;
	}

	void swap_student() {															// allagh enos ataktou mathiti (tha thn kalesei h akolouthia akolouthiwn)


		Pair* temp1 = start;														// ksekinwntas apo thn arxh ths akolouthias
		Student* p = NULL;

		int count = 0;
		unsigned seed = time(0);
		srand(seed);
		int count2 = 0;

		while (temp1 != NULL) {														// kai gia ola ta zeugaria
			if (temp1->data[0] != NULL) {											// an to zeugari exei mathiti sth thesi 0 tou pinaka	
				if (temp1->data[0]->is_naughty) {									// an o mathitis autos einai ataktos
					Pair* temp = start;

					if (temp1->data[0]->gender == "boy") {							// gia agori
						count = 0;
						int random = rand() % (s_in / 2);
						while (random == count2) {
							random = rand() % (s_in / 2);							// psaxnoume mathiti se tuxaia thesi diaforetiki apo auth pou einai 		
						}
						while (temp != NULL)
						{
							if (count == random && temp->data[0]->gender == "boy") { // molis vroume thn tyxaia thesi koitame analogws pou einai to agori kai kanoume thn allagh

								p = temp->data[0];
								temp->data[0] = temp1->data[0];
								temp1->data[0] = p;
								temp->data[0]->is_naughty = false;
								temp->data[0]->print();
								cout << "was moved " << endl;
								naughty_sum++;											// prosthetoume ponto ataksias sthn taksh kai teleiwnei h ataksia tou
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									temp1->data[0]->print();
									cout << "was moved " << endl;
									naughty_sum++;										// an kai to paidi pou irthe htan atakto prosthetei ponto sthn taksh kai teleiwnei h ataksia tou
								}
								break;

							}
							if (count == random && temp->data[1]->gender == "boy")		// edw antistoixa gia thn allh thesi tou pinaka
							{
								p = temp->data[1];
								temp->data[1] = temp1->data[0];
								temp1->data[0] = p;
								temp->data[1]->is_naughty = false;
								temp->data[1]->print();
								cout << "was moved " << endl;
								naughty_sum++;
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									temp1->data[0]->print();
									cout << "was moved " << endl;
									naughty_sum++;
								}
								break;


							}
							count++;
							temp = temp->next;
						}


					}
					if (temp1->data[0]->gender == "girl") {								// analogws gia koritsi
						count = 0;
						int random = rand() % (s_in / 2);
						while (random == count2) {
							random = rand() % (s_in / 2);
						}
						while (temp != NULL)
						{

							if (count == random && temp->data[0]->gender == "girl") {

								p = temp->data[0];
								temp->data[0] = temp1->data[0];
								temp1->data[0] = p;
								temp->data[0]->is_naughty = false;
								temp->data[0]->print();
								cout << "was moved " << endl;
								naughty_sum++;
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									temp1->data[0]->print();
									cout << "was moved " << endl;
									naughty_sum++;
								}
								break;

							}
							if (count == random && temp->data[1]->gender == "girl")
							{
								p = temp->data[1];
								temp->data[1] = temp1->data[0];
								temp1->data[0] = p;
								temp->data[1]->is_naughty = false;
								temp->data[1]->print();
								cout << "was moved " << endl;
								naughty_sum++;
								if (temp1->data[0]->is_naughty) {
									temp1->data[0]->is_naughty = false;
									temp1->data[0]->print();
									cout << "was moved " << endl;
									naughty_sum++;
								}
								break;


							}
							count++;
							temp = temp->next;
						}



					}

				}
			}
			if (temp1->data[1] != NULL) {													// antistoixa gia thn epomenh thesi tou pinaka 
				if (temp1->data[1]->is_naughty) {

					Pair* temp = start;
					if (temp1->data[1]->gender == "boy") {
						count = 0;
						int random = rand() % (s_in / 2);
						while (random == count2) {
							random = rand() % (s_in / 2);
						}
						while (temp != NULL)
						{
							if (count == random && temp->data[0]->gender == "boy") {

								p = temp->data[0];
								temp->data[0] = temp1->data[1];
								temp1->data[1] = p;
								temp->data[0]->is_naughty = false;
								temp->data[0]->print();
								cout << "was moved " << endl;
								my_sum++;
								if (temp1->data[1]->is_naughty) {
									temp1->data[1]->is_naughty = false;
									temp1->data[1]->print();
									cout << "was moved " << endl;
									my_sum++;
								}
								break;

							}
							if (count == random && temp->data[1]->gender == "boy")
							{
								p = temp->data[1];
								temp->data[1] = temp1->data[1];
								temp1->data[1] = p;
								temp->data[1]->is_naughty = false;
								temp->data[1]->print();
								cout << "was moved " << endl;
								my_sum++;
								if (temp1->data[1]->is_naughty) {
									temp1->data[1]->is_naughty = false;
									temp1->data[1]->print();
									cout << "was moved " << endl;
									my_sum++;
								}
								break;


							}
							count++;
							temp = temp->next;
						}

					}
					else {

						count = 0;
						int random = rand() % (s_in / 2);
						while (random == count2) {
							random = rand() % (s_in / 2);
						}
						while (temp != NULL)
						{
							if (count == random && temp->data[0]->gender == "girl") {


								p = temp->data[0];
								temp->data[0] = temp1->data[1];
								temp1->data[1] = p;
								temp->data[0]->is_naughty = false;
								temp->data[0]->print();
								cout << "was moved " << endl;
								my_sum++;
								if (temp1->data[1]->is_naughty) {
									temp1->data[1]->is_naughty = false;
									temp1->data[1]->print();
									cout << "was moved " << endl;
									my_sum++;
								}
								break;

							}

							if (count == random && temp->data[1]->gender == "girl")
							{
								p = temp->data[1];
								temp->data[1] = temp1->data[1];
								temp1->data[1] = p;
								temp->data[1]->is_naughty = false;
								temp->data[1]->print();
								cout << "  was moved" << endl;
								my_sum++;
								if (temp1->data[1]->is_naughty) {
									temp1->data[1]->is_naughty = false;
									temp1->data[1]->print();
									cout << "  was moved" << endl;
									my_sum++;
								}
								break;


							}
							count++;
							temp = temp->next;
						}


					}


				}
			}
			temp1 = temp1->next;
			count2++;
		}

	}





private:
	struct Pair {																	// i akolouthia exei mia struct Pair (zeugari) h opoia ousiastika einai to node ths listas
		Pair(Student* s1, Student* s2) : next(NULL), index(0) {						// pairnei orisma 2 deiktes se mathiti 
			data = new Student * [2];												// ftiaxnei pinaka deiktwn se mathites 2 thesewn afou einai zeugari
			data[0] = s1;															// thetei sthn thesi 0 ton prwto pointer mathiti
			data[1] = s2;															// sthn thesi 1 ton deutero

		}
		

		Pair* next;																	// exei ena deikth se zeugari pou tha deixnei ston epomeno komvo
		Student** data;																// exei ena deikth se pinaka mathitwn
		int index;																	// enan akeraio pou tha deixnei th thesh tou zeugariou
		bool naughty_pair = false;													// ena bool pou tha mporei na deiksei an to zeugari einai atakto	
	};
	int s_in;																		// enas akeraios pou deixnei posoi mathites exei h akolouthia
	
	Student** array_of_students;													// deikths se pinaka deiktwn mathitwn ton opoio tha parei apo th main

	
	Pair* start;																	// enas deikths ston prwto komvo-zeugari
	Pair* last;																		// enas deikths ston teleutaio komco-zeugari
	int naughty_sum = 0;															// o metrhths ataksias 
	int size;																		// to plithos komvwn ths akolouthias 	
	int& my_sum = naughty_sum;														// reference ston metrith ataksias			
	int cl_no;																		// o arithmos taksis ths akolouthias
	double mess;																	// to pososto Tmess
	double quiet;																	// to pososto Tquiet


};


// Class Sequence of Sequences ===============================================================

class bigSequence {

public:

	bigSequence() : head(NULL),last(NULL) , in_size(0) {							// contructor ths akolouthias akolouthiwn me intializer list
		cout << " A big sequence has been created " << endl;



	}
	~bigSequence() {																// destructor pou apodesmeuei ta nodes
		Sequence_node* t1 = head;
		while (t1 != NULL) {
			Sequence_node* t2 = t1;
			t1 = t1->next;
			delete t2;
		}
		cout << " A big sequence to be destoyed" << endl;

	}

	void insert_sequence(Sequence* s) {												// esagei  neo komvo-akolouthia sthn "lista" akolouthia akolouthiwn

		cout << " inserting sequence" << endl;
		Sequence_node* t1 = new Sequence_node(s);



		if (head == NULL) {
			head = t1;

			t1->index = 1;

		}
		else
		{
			t1->index = 2;
			Sequence_node* t2 = head;
			while (t2->next != NULL) {

				t2 = t2->next;
				t1->index++;
			}
			t2->next = t1;
			t1->previous = t2;

		}
		last = t1;
		in_size++;														
		if (t1 != head && head != NULL) {													// sthn periptwsh pou i akolouthia pou eisagoume den einai o prwtos komvos

			if (t1->data->s_in % 2 == 1 && t1->previous->data->s_in % 2 == 1) {				// an to sunolo mathitwn ths akolouthias einai peritos kai ths prohgoumenhs to idio
				if (t1->data->s_in % 4 == 1) {												// elegxos gia to se poia thesi tou zeugariou einai o mathitis			
					if (t1->previous == head) {															// elegxos an h prohgoumenh akolouthia einai o prwtos komvos 
						head->data->create_pairs(head->data->last->data[0], t1->data->last->data[0]);	// ftiaxnoume to zeugari me tous duo mathites pou perisevoun

						head->data->s_in++;												// auksanoume ton arithmo mathitwn kata 1 (giati o enas mathitis pou phrame htan ths prwths akolouthias)
						int i = head->data->last->index - 1;										

						head->data->delete_pair(i);										// diagrafoume to "zeugari" pou phge sthn prwth akolouthia omws epeidh einai o idios mathitis den allazei to plithos			
						int j = t1->data->last->index;

						t1->data->s_in--;
						t1->data->delete_pair(j);												// diagrafoume to zeugari ths akolouthias apo thn opoia efyge o mathitis

					}
					else                                                                // se allh periptwsh
					{
						if (head->data->s_in % 4 == 2) {
							cout << head->data->s_in << endl;								// elegxoume ton tropo pou prepei na mpoun oi mathites
							head->data->create_pairs(t1->data->last->data[0], t1->previous->data->last->data[0]); // prostetoume tous duo mathites sthn prwth akolouthia

							int i = t1->previous->data->last->index;

							t1->previous->data->s_in--;
							t1->previous->data->delete_pair(i);											// diagrafoume to komvo me ton mathiti apo thn prwth
							int j = t1->data->last->index;

							t1->data->s_in--;
							t1->data->delete_pair(j);													// diagrafoume kai ton komvo me ton mathiti apo thn 2h 
							head->data->s_in += 2;

						}
						else if (head->data->s_in % 4 == 0) {									// gia antistrofh topothetisi

							head->data->create_pairs(t1->previous->data->last->data[0], t1->data->last->data[0]);
							int i = t1->previous->data->last->index;

							t1->previous->data->s_in--;
							t1->previous->data->delete_pair(i);
							int j = t1->data->last->index;

							t1->data->s_in--;
							t1->data->delete_pair(j);
							head->data->s_in += 2;

						}
					}
				}
				else {															// antistoixes energeies sthn periptwsh pou tha prepei na paroume ton mathiti apo thn allh thesi tou komvou
					if (t1->previous == head) {
						head->data->create_pairs(t1->data->last->data[1], head->data->last->data[1]);

						head->data->s_in++;
						int i = head->data->last->index - 1;

						head->data->delete_pair(i);
						int j = t1->data->last->index;

						t1->data->s_in--;
						t1->data->delete_pair(j);

					}
					else
					{
						if (head->data->s_in % 4 == 2) {
							head->data->create_pairs(t1->data->last->data[1], t1->previous->data->last->data[1]);

							int i = t1->previous->data->last->index;

							t1->previous->data->s_in--;
							t1->previous->data->delete_pair(i);
							int j = t1->data->last->index;

							t1->data->s_in--;
							t1->data->delete_pair(j);
							head->data->s_in += 2;

						}
						else if (head->data->s_in % 4 == 0) {

							head->data->create_pairs(t1->previous->data->last->data[1], t1->data->last->data[1]);
							int i = t1->previous->data->last->index;

							t1->previous->data->s_in--;
							t1->previous->data->delete_pair(i);
							int j = t1->data->last->index;

							t1->data->s_in--;
							t1->data->delete_pair(j);
							head->data->s_in += 2;

						}
					}
				}
			}

		}

	}

	void swap_pairs() {														// h synarthsh pou tha kanei tis allages stis akolouthies gia ta atakta zeugaria kai paidia
		srand(time(NULL));
		Sequence_node* temp = head;											// ksekiname me thn prwth akolouthia
		while (temp != NULL) {												// gia olous tous komvous ths akolouthias akolouthiwn
			temp->data->set_naughty_pair();									// thetoume atakta zeugaria analoga me tous ataktous mathites
			int count = temp->data->check_amount_of_naughty_pairs();		// elegxos gia to posa attakta zeugaria yparxoun
			if (count >= 3) {												// gia tria kai panw	
				if (temp->data->check_continuous_pairs()) {					// elegxos an exoume synexomena zeugaria 
					for (int i = 1; i <= temp->data->size; i++) {			// gia olous tous komvous zeugariwn		
						int random = (rand() % in_size) + 1;				// tyxaios arithmos gia na vroume tyxaia akolouthia pou tha ginei i allagh
						while (random == temp->index) {						
							random = (rand() % in_size) + 1;
						}													// elegxos na mhn einai o idios me to index ths akolouthias pou koitame
						Student** s1 = temp->data->get_pair(i);				// koitame to zeugari na einai atakto
						if (s1[0] == NULL || s1[1] == NULL)					// an den einai kan zeugari pame sthn epomeno komvo (auto symfwna me thn ylopoihsh mou symvainei mono sthn 
							continue;										// teleutaia akolouthia an o arithmos tmhmatwn einai peritos kai o arithmos paidiwn einai perittos omws tha leitourgouse kai
																			// se alles ylopoihseis}
						if (s1[0]->is_naughty && s1[1]->is_naughty) {		// an kai oi duo mathites einai ataktoi
							Sequence_node* temp1 = head;					
							int count2 = 1;
							while (temp1 != NULL) {							// psaxnoume tyxaia akolouthia apo opou tha epileksoume tyxaio zeugari
								if (count2 == random) {
									int j;
									if (random == in_size)					// an einai h  teleutaia akolouthia 	
										 j = (rand() % (temp1->data->size - 1)) + 1;         // opoiodhpote zeugari ektos tou teleutaiou
									else
										 j = (rand() % temp1->data->size) + 1;				// alliws opoiodhpote zeugari				
									Student** s2 = temp1->data->get_pair(j);				// apothikeusi se pinaka deiktwn se mathites to tyxaio zeugari
									if (s1[0]->gender == s2[0]->gender) {					// an h diataksh einai idia 	
										temp->data->insert_pair(s2[0], s2[1], i);			// vazoume komvo zeugariou sth mia akolouthia to zeugari ths allhs
										temp1->data->insert_pair(s1[0], s1[1], j);			// antistoixa
										cout << "Pair ";
										s1[0]->print();											
										s1[1]->print();
										cout << "Pair ";
										cout << " was moved to sequence " << temp1->index << endl;	// ektypwsh twn zeugariwn pou metakinhthikan kai pou
										s2[0]->print();
										s2[1]->print();
										cout << " was moved to sequence " << temp->index << endl;


										s1[0]->is_naughty = false;
										s1[1]->is_naughty = false;									// teleiwnei h ataksia tou prwtou zeugariou		
										Sequence_node* t = head;
										while (t != NULL) {											// sthn taksh tou kathe mathiti dinoume 2 pontous ataksias gia ton kathena

											if (t->index == s1[0]->cl_no)
												t->data->my_sum += 2;
											if (t->index == s1[1]->cl_no)
												t->data->my_sum += 2;
											t = t->next;
										}
										if (s2[0]->is_naughty) {									// antistoixa mono an kai oi mathites pou tous antikatesthsan htan ataktoi
											Sequence_node* t = head;								// tha dwsoun pontous ataksias sthn taksh tous
											while (t != NULL) {

												if (t->index == s2[0]->cl_no)
													t->data->my_sum += 2;
												t = t->next;
											}
											s2[0]->is_naughty = false;
										}
										if (s2[1]->is_naughty) {
											Sequence_node* t = head;
											while (t != NULL) {

												if (t->index == s2[1]->cl_no)
													t->data->my_sum += 2;
												t = t->next;
											}
											s2[1]->is_naughty = false;
										}

										temp->data->delete_pair(i + 1);								// diagrafoume tous komvous zeugaria tous opoious antikatasthsame kai einai pleon sthn 			
										temp1->data->delete_pair(j + 1);							// allh akolouthia
										break;
									}
									else {															// antistoixes energeies an ta zeygaria einai se diaforetikh diataksh 
										temp->data->insert_pair(s2[1], s2[0], i);					// allazontas ton tropo (thesi sto zeugari) pou tha tous topothetisoume
										temp1->data->insert_pair(s1[1], s1[0], j);
										cout << "Pair ";
										s1[0]->print();
										s1[1]->print();
										cout << " was moved to sequence " << temp1->index << endl;
										cout << "Pair ";
										s2[0]->print();
										s2[1]->print();
										cout << " was moved to sequence " << temp->index << endl;
										s1[0]->is_naughty = false;
										s1[1]->is_naughty = false;
										Sequence_node* t = head;
										while (t != NULL) {
											if (t->index == s1[0]->cl_no)
												t->data->my_sum += 2;
											if (t->index == s1[1]->cl_no)
												t->data->my_sum += 2;
											t = t->next;
										}
										if (s2[0]->is_naughty) {
											Sequence_node* t = head;
											while (t != NULL) {
												if (t->index == s2[0]->cl_no)
													t->data->my_sum += 2;
												t = t->next;
											}
											s2[0]->is_naughty = false;
										}
										if (s2[1]->is_naughty) {
											Sequence_node* t = head;
											while (t != NULL) {
												if (t->index == s2[1]->cl_no)
													t->data->my_sum += 2;
												t = t->next;
											}
											s2[1]->is_naughty = false;
										}
										temp->data->delete_pair(i + 1);
										temp1->data->delete_pair(j + 1);
										break;
									}


								}
								count2++;
								temp1 = temp1->next;

							}


						}


					}

				}
				else																	// sthn periptwsh pou ta zeugaria einai diasparta
				{
					for (int i = 1; i <= temp->data->size; i++) {						// gia ola ta zeugaria ths akolouthias
						Student** s1 = temp->data->get_pair(i);							// koitame to kathe zeugari 	
						if (s1[0] == NULL || s1[1] == NULL)
							continue;
						Sequence_node* temp1;
						int j;
						if (temp == last) {												// edw an h akolouthia zeugariwn einai h teleutaia tha ginei allagh me thn prohgoumenh
							temp1 = temp->previous;
							j = (rand() % (temp1->data->size - 1)) + 1;					
						}
						else {															// alliws tha ginei allagh me thn epomenh akolouthia		
							temp1 = temp->next;
							if (temp1 == last) {										
								j = (rand() % (temp1->data->size - 1)) + 1;				// apofeugoume to teleutaio zeugari pou mporei na einai perittos gia thn teleutaia akolouthia
							}
							else 
								j = (rand() % temp1->data->size) + 1;
						}
						Student** s2 = temp1->data->get_pair(j);						// antistoixes energeies me prohgoumenws mono pou pleon to atakto zeugari paei sthn epomenh akolouthia
						if (s1[0]->gender == s2[0]->gender) {							// anti gia mia tyxaia	
							temp->data->insert_pair(s2[0], s2[1], i);
							temp1->data->insert_pair(s1[0], s1[1], j);
							cout << "Pair ";
							s1[0]->print();
							s1[1]->print();
							cout << " was moved to sequence " << temp1->index << endl;
							cout << "Pair ";
							s2[0]->print();
							s2[1]->print();
							cout << " was moved to sequence " << temp->index << endl;


							s1[0]->is_naughty = false;
							s1[1]->is_naughty = false;
							Sequence_node* t = head;
							while (t != NULL) {

								if (t->index == s1[0]->cl_no)
									t->data->my_sum += 2;
								if (t->index == s1[1]->cl_no)
									t->data->my_sum += 2;
								t = t->next;
							}
							if (s2[0]->is_naughty) {
								Sequence_node* t = head;
								while (t != NULL) {

									if (t->index == s2[0]->cl_no)
										t->data->my_sum += 2;
									t = t->next;
								}
								s2[0]->is_naughty = false;
							}
							if (s2[1]->is_naughty) {
								Sequence_node* t = head;
								while (t != NULL) {

									if (t->index == s2[1]->cl_no)
										t->data->my_sum += 2;
									t = t->next;
								}
								s2[1]->is_naughty = false;
							}

							temp->data->delete_pair(i + 1);
							temp1->data->delete_pair(j + 1);
							break;
						}
						else {
							temp->data->insert_pair(s2[1], s2[0], i);
							temp1->data->insert_pair(s1[1], s1[0], j);
							cout << "Pair ";
							s1[0]->print();
							s1[1]->print();
							cout << " was moved to sequence " << temp1->index << endl;
							cout << "Pair ";
							s2[0]->print();
							s2[1]->print();
							cout << " was moved to sequence " << temp->index << endl;
							s1[0]->is_naughty = false;
							s1[1]->is_naughty = false;
							Sequence_node* t = head;
							while (t != NULL) {
								if (t->index == s1[0]->cl_no)
									t->data->my_sum += 2;
								if (t->index == s1[1]->cl_no)
									t->data->my_sum += 2;
								t = t->next;
							}
							if (s2[0]->is_naughty) {
								Sequence_node* t = head;
								while (t != NULL) {
									if (t->index == s2[0]->cl_no)
										t->data->my_sum += 2;
									t = t->next;
								}
								s2[0]->is_naughty = false;
							}
							if (s2[1]->is_naughty) {
								Sequence_node* t = head;
								while (t != NULL) {
									if (t->index == s2[1]->cl_no)
										t->data->my_sum += 2;
									t = t->next;
								}
								s2[1]->is_naughty = false;
							}
							temp->data->delete_pair(i + 1);
							temp1->data->delete_pair(j + 1);
							break;
						}
						

					}
				}
			}
			else												// se periptwsh pou ta atakta zeugaria einai mexri 2 sthn akolouthia zeugariwn 
			{
				temp->data->swap_pairs();						// kaleitai h synarthsh gia allagh zeugariwn eswterika ths akolouthias	
				temp->data->swap_student();						// gia tous ataktous mathites kaleitai h synarthsh gia allagh ataktwn mathitwn
			}

			temp = temp->next;
		}
	}





	void print() {												// h synarthsh print ths akolouthias akolouthiwn kalei gia oles tis akolouthies thn print twn zeugariwn

		Sequence_node* temp;
		temp = head;
		while (temp != NULL)
		{
			
			temp->data->print_pairs();
			cout << endl;
			temp = temp->next;
		}

	}


private:

	struct Sequence_node															// o Komvos ths akolouthias akolouthiwn 
	{
		Sequence_node(Sequence* s) : data(s), next(NULL), previous(NULL) {}			// o constructor dinei orismata sto data meros tou ena pointer se akolouthia zeugariwn 
																					// ston pointer next NULL kai sto previous NULL

		Sequence* data;																// exei data typou pointer se antikeimeno typou akolouthia zeugariwn
		Sequence_node* next;														// exei pointer se antikeimeno typou komvos akolouthias akolouthiwn	pou deixnei ston epomeno komvo
		Sequence_node* previous;													// exei pointer se antikeimeno typou komvos akolouthias akolouthiwn	pou deixnei ston prohgoumeno komvo
		
		int index;																	// exei ena index typou akeraios gia na gnwrizoume th thesh ths akolouthias (h alliws kai ton arithmo ths takshs)
	};

	int in_size;											// h akolouthia akolouthiwn exei sto private meros giati den xreiazomaste prosvash se enan akeraio pou metraei poses
	Sequence_node* head;									// akolouthies exei mesa, ena pointer se antikeimeno typou akolouthia zeugariwn pou tha deixnei ton prwto komvo  	
	Sequence_node* last;									// kai ena pointer se antikeimeno typou akolouthia zeugariwn pou tha deixnei ton teleutaio komvo

};






// Main Function =============================================================================


int main(int argc,char* argv[]) {
    int K = atoi(argv[1]);
	int L = atoi(argv[2]);
    double Tquiet = atof(argv[3]);
	double Tmessy = atof(argv[4]);
	int s_of_K;
    cout << "Give the number of students of every class :"<< endl;
    cin>>s_of_K;
	
	
	int N = s_of_K * K;
	int X = s_of_K;											// metavliti pou arxikopoieitai ston arithmo mathitwn pou exei h kathe taksh	
	int j = 0;
	Student** kindergarden;									// to nhpiagwgio tha einai enas pinakas deiktwn se antikeimena typou student 
	Student** temp_array;									// ftiaxnoume ki ena voithitiko pinaka deiktwn se antikeimena typou student mesw tou opoiou tha 
															// arxikopoihsoume tis akolouthies mas 
	bigSequence sequence_list;								// exoume ena antikeimeno typou akolouthia akolouthiwn
	Sequence** array_of_sequences;							// exoume ena pinaka deiktwn se akolouthies zeugariwn		
	array_of_sequences = new Sequence * [K];				// desmeuoume dunamika xwro mnhmhs gia K deiktes se akolouthia zeugariwn
	kindergarden = new Student * [N];						// desmeuoume dunamika xwro mnhmhs gia N deiktes se mathites
	temp_array = new Student * [s_of_K];					// desmeoume dunamika xwro mnhmhs gia ton arithmo twn mathitwn ths kathe takshs to plithos, deiktes se mathites		





	for (int i = 0; i < K; i++) {							
		int ii = 0;
		while (j < X) {													// dynamikh desmeush mnhmhs gia deiktes se mathiti	
			if (j % 2 == 0) {									
				kindergarden[j] = new Student(i + 1, "boy");			// edw kathe mathitis tha parei san orisma ton arithmo takshs tous kai to fyllo tou			
			}
			else														// o tropos pou dialeksa (vlepe readme) einai pws tha kataskevastoun me thn seira enalax agori/koritsi
			{
				kindergarden[j] = new Student(i + 1, "girl");			
			}
			temp_array[ii] = kindergarden[j];							// ston voithitiko pinaka tha apothikeusoume tous mathites ths ekastote takshs



			kindergarden[j]->print();
			cout << endl;

			j++;
			ii++;
		}
		array_of_sequences[i] = new Sequence(temp_array, i + 1, s_of_K,Tmessy,Tquiet);      // edw desmeoume dynamika mnhmh gia mia akolouthia zeugariwn h opoia dexetai san orisma 
																							// ton voithiko pinaka mathitwn ths takshs, ton arithmo ths takshs, kai ta pososta Tmessy,Tquiet 
																							// pou tha xrhsimopoihsei eswterika


		j = X;
		X += s_of_K;




	}


	for (int i = 0; i < K; i++)
		sequence_list.insert_sequence(array_of_sequences[i]);                                // h akolouthia akolouthiwn pairnei san orisma tous deiktes se akolouthies zeygariwn

	cout << " printing sequences!!!!!!!!!!!!!!!!!" << endl;

	sequence_list.print();																	// mia prwth ektypwsh twn akolouthiwn opws exoun diamorfwthei arxikopoihmenes					
	srand(time(NULL));
	
	for (int i = 0; i < L; i++) {															// gia L fores
		
		int random2 = rand() % s_of_K;														// tyxaio plithos mathitwn	(edw mporoume na allaksoume ton tropo pou vgainei to random gia perissotera apotelesmata)

		for (int j = 0; j < random2; j++) {													// gia auto to plithos
			
		
			int random = rand() % N;														// tyxaioi mathites
	
			if (kindergarden[random]->is_naughty) {											// an einai hdh ataktos dialegoume allon 
				random2++;
				continue;

			}
				
			kindergarden[random]->is_naughty = true;										// tha kanoun ataksies
			kindergarden[random]->print();													// ektypwsh tou mathiti pou einai ataktos
			cout << " is naughty!!" <<endl;

		}
		sequence_list.print();									// ektypwsh me tis akolouthies me tous ataktous mathites (den to zhthse h ekfwnhsh alla tha voithisei pisteuw)
		sequence_list.swap_pairs();								// ginontai oi aparaiththes energeies 
		cout << endl;
		sequence_list.print();									// ektypwsh twn akolouthiwn opws exoun diamorfwthei meta tis allages	
	}
	
	

	cout << " 3rd print ===============" << endl << endl << endl << endl;


	sequence_list.print();										// mia teliki ektypwsh me tis theseis twn mathitwn 


	for (int i = 0; i < K; i++) {
		delete array_of_sequences[i];							// apodesmeysh mnhmhs twn deiktwn se akolouthies zeygariwn
	}


	delete[] array_of_sequences;								// apodemeysh mnhmhs tou pinaka deiktwn se akolouthies zeugariwn


	for (int i = 0; i < N; i++) {

		delete kindergarden[i];									// apodesmeysh mnhmhs twn deiktwn se mathites

	}

	delete[] kindergarden;										// apodemeysh mnhmhs tou pinaka deiktwn se mathites


	return 0;
}







