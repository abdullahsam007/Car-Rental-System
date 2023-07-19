#include <iostream>
#include <fstream>
using namespace std;
char* deepCopy(const char* a)
{
	char* temp = nullptr;
	if (a)
	{
		int size = strlen(a) + 1;
		temp = new char[size];
		int i = 0;
		/*for(int i=0; i< size; i++)
		{
		temp[i] = a[i];
		}
		temp[i] = '\0';*/
		strcpy_s(temp, size, a);
	}
	return temp;
}


 class vehicle{
	char* companyName;
	char* color;
	int numberOfWheels;
	int powerCC;
	char*  typeOfVehicle;
public:
	vehicle(char* cn = nullptr, char* co = nullptr, int wh = 0, int po = 0, char* type = nullptr)
	{
		companyName = deepCopy(cn);
		color = deepCopy(co);
		numberOfWheels = wh;
		powerCC = po;
		typeOfVehicle = deepCopy(type);
	}
	vehicle(const vehicle& obj)
	{
		companyName = deepCopy(obj.companyName);
		color = deepCopy(obj.color);
		numberOfWheels = obj.numberOfWheels;
		powerCC = obj.powerCC;
		typeOfVehicle = deepCopy(obj.typeOfVehicle);
	}

	void setcompanyname(char * name)
	{
		companyName = deepCopy(name);
	}
	void setcolor(char * co)
	{
		color = deepCopy(co);
	}
	void setnoofwheels(int wheels)
	{
		numberOfWheels = wheels;
	}
	void setpower(int pow)
	{
		powerCC = pow;
	}
	void setvehicletype(char * type)
	{
		typeOfVehicle = deepCopy(type);
	}
	char *getcompanyname()
	{
		char *temp;
		temp = deepCopy(companyName);
		return temp;
	}
	char *getcolor()
	{
		char *temp;
		temp = deepCopy(color);
		return temp;
	}
	int getnoofwheels()
	{
		return numberOfWheels;
	}
	int getpower()
	{
		return powerCC;
	}
	char *getvehicletype()
	{
		char *temp;
		temp = deepCopy(typeOfVehicle);
		return temp;
	}

	vehicle& operator =(const vehicle& obj)
	{
		if (this != &obj)
		{
			this->companyName = deepCopy(obj.companyName);
			this->color = deepCopy(obj.color);
			this->typeOfVehicle = deepCopy(obj.typeOfVehicle);
			this->numberOfWheels = obj.numberOfWheels;
			this->powerCC = obj.powerCC;
		}
		return *this;
	}
	virtual void checkType() = 0;
	virtual void display()
	{
		cout << "companyName" <<"  "<< "typeof" << "  " << "color" << "  " << "powerCC" << "  " << "numberofwheels" << endl;
		cout << "---------------------------------------------------------------------------------------------------------" << endl;
		cout << companyName << "        " << typeOfVehicle << "    " << color << "    " << powerCC << "           " << numberOfWheels << endl << endl;
	}
	virtual void displayfile(ofstream& fout)const
	{
		/*fout.open("file.txt",ios::out);
		if (fout.is_open())
		{
			cout << "success " << endl;
		}*/
		fout << "companyName" << "                              " << "typeof" << "  " << "color" << "  " << "powerCC" << "  " << "numberofwheels" << endl;
		fout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
		fout << companyName << "                                " << typeOfVehicle << "  " << color << "  " << powerCC << "  " << numberOfWheels << endl;
		//fout.close();
	}
	virtual void setattributes()     //writing this so i can get all the attributes when i want to add a vehicle
	{
		char company[20];
		cout << "enter company name : ";
		cin >> company;
		companyName = deepCopy(company);
		char c[20];
		cout << "enter color : ";
		cin >> c;
		color = deepCopy(c);
		int wheels = 0;
		cout << "enter wheels : ";
		cin >> wheels;
		numberOfWheels = wheels;
		int power = 0;
		cout << "enter power : ";
		cin >> power;
		powerCC = power;
		char type[20];
		cout << "enter type : ";
		cin >> type;
		typeOfVehicle = deepCopy(type);
	}
	virtual void countvehicles() = 0;   // this function is to count all the vehicles that will be added.
	virtual~vehicle()
	{
		if (companyName)
		{
			delete[]companyName;
		}
		if (color)
		{
			delete[]color;
		}
		if (typeOfVehicle)
		{
			delete[]typeOfVehicle;
		}
	}
};



 class bike : public vehicle{
	 double height;
	 bool  selfStart;
	 bool discBrake;
	 static int  numberOfBikes;
 public:
	 bike(char* cn = nullptr, char* co = nullptr, int wh = 0, int po = 0, char* type = nullptr, double hei = 0, bool self = false, bool disc = false) :vehicle(cn,co,wh,po,type)
	 {
		 height = hei;
		 selfStart = self;
		 discBrake = disc;
		 numberOfBikes++;
	 }
	 bike(const bike&obj)
	 {
		 this->height = obj.height;
		 this->selfStart = obj.selfStart;
		 this->discBrake = obj.discBrake;
	 }
	 static int getnumberofbikes()
	 {
		 return numberOfBikes;
	 }
	 void setheight(double hei)
	 {
		 height = hei;
	 }
	 void setselfstart(bool self)
	 {
		 selfStart = self;
	 }
	 void setdiscbrake(bool disc)
	 {
		 discBrake = disc;
	 }
	 double getheight()
	 {
		 return height;
	 }
	 bool getselfstart()
	 {
		 return selfStart;
	 }
	 bool getdiscbrake()
	 {
		 return discBrake;
	 }
	 bike& operator =(const bike& obj)
	 {
		 if (this != &obj)
		 {
			 this->height = obj.height;
			 this->selfStart = obj.selfStart;
			 this->discBrake = obj.discBrake;
		 }
		 return *this;
	 }
	 void checkType()
	 {
		 if (vehicle::getnoofwheels() == 2)
		 {
			 vehicle::setvehicletype("BIKE");
			 cout << vehicle::getvehicletype() << endl;
		 }
		 else
		 {
			 cout << "wrong input type " << endl;
		 }
	 }
	 void display()
	 {
		 vehicle::display();
		 cout << "height" << "  " << "selfStart" << "  " << "discBrake" << "  " << endl;
		 cout << height << "         " << selfStart << "            " << discBrake << "  " << endl;
	 }
	 void displayfile(ofstream& fout)
	 {
		 /*fout.open("file.txt",ios::out);
		 if (fout.is_open())
		 {
			 cout << "success " << endl;
		 }*/
		 vehicle::displayfile(fout);
		 fout << "height" << "  " << "selfStart" << "  " << "discBrake" << "  " << endl;
		 fout << height << "  " << selfStart << "  " << discBrake << "  " << endl;
		// fout.close();
	 }
	 void setattributes()
	 {
		 vehicle::setattributes();
		 int h = 0;
		 cin >> h;
		 height = h;
		 bool self = 0;
		 cin >> self;
		 selfStart = self;
		 bool disc = 0;
		 cin >> disc;
		 discBrake = disc;
	 }
	 void countvehicles()
	 {
		 numberOfBikes++;
	 }
	 ~bike(){}
 };
 int bike::numberOfBikes = 0;



 class car : public vehicle
 {
	 int noOfDoors;
	 char* trasmission;
	 int  noOfSeats;
	 static int numberOfCars;
 public:
	 car(char* cn = nullptr, char* co = nullptr, int wh = 0, int po = 0, char* type = nullptr, int doors = 0, char* trans = nullptr, int seats = 0) : vehicle(cn,co,wh,po,type)
	 {
		 noOfDoors = doors;
		 trasmission = deepCopy(trans);
		 noOfSeats = seats;
		 numberOfCars++;
	 }
	 car(const car&obj)
	 {
		 noOfDoors = obj.noOfDoors;
		 trasmission = deepCopy(obj.trasmission);
		 noOfSeats = obj.noOfSeats;
	 }
	 static int getnumberofcars()
	 {
		 return numberOfCars;
	 }
	 void setdoors(int doors)
	 {
		 noOfDoors = doors;
	 }
	 void settrasmission(char * tras)
	 {
		 trasmission = deepCopy(tras);
	 }
	 void setseats(int seats)
	 {
		 noOfSeats = seats;
	 }
	 int getdoors()
	 {
		 return noOfDoors;
	 }
	 char *gettrasmission()
	 {
		 char *temp;
		 temp = deepCopy(trasmission);
		 return temp;
	 }
	 int getseats()
	 {
		 return noOfSeats;
	 }
	 car& operator =(const car& obj)
	 {
		 if (this != &obj)
		 {
			 this->noOfDoors = obj.noOfDoors;
			 this->trasmission = deepCopy(obj.trasmission);
			 this->noOfSeats = obj.noOfSeats;
		 }
		 return *this;
	 }
	 void checkType()
	 {
		 if (vehicle::getnoofwheels() == 4)
		 {
			 vehicle::setvehicletype("CAR");
			 cout << vehicle::getvehicletype() << endl;
		 }
		 else
		 {
			 cout << "wrong input type " << endl;
		 }
	 }
	 void display()
	 {
		 vehicle::display();
		 cout << "noofdoors" << "  " << "trasmission" << "  " << "noofseats" << "  " << endl;
		 cout << noOfDoors << "           " << trasmission << "        " << noOfSeats << "  " << endl;
	 }
	 void displayfile(ofstream& fout)
	 {
		 /*fout.open("file.txt");
		 if (fout.is_open())
		 {
			 cout << "success " << endl;
		 }*/
		 vehicle::displayfile(fout);
		 fout << "noofdoors" << "  " << "trasmission" << "  " << "noofseats" << "  " << endl;
		 fout << noOfDoors << "  " << trasmission << "  " << noOfSeats << "  " << endl;
		// fout.close();
	 }
	 void setattributes()
	 {
		 vehicle::setattributes();
		 int doors = 0;
		 cin >> doors;
		 noOfDoors = doors;
		 char tras[20];
		 cin >> tras;
		 trasmission = deepCopy(tras);
		 int seats = 0;
		 cin >> seats;
		 noOfSeats = seats;
	 }
	 void countvehicles()
	 {
		 numberOfCars++;
	 }
	 ~car()
	 {
		 if (trasmission)
		 {
			 delete[]trasmission;
		 }
	 }
 };
 int car::numberOfCars = 0;


 class truck : public vehicle{
	 double containerSize;
	 char*  category;
	 bool fourWheelDrive;
	 static int numberOfTrucks;
 public:
	 truck(char* cn = nullptr, char* co = nullptr, int wh = 0, int po = 0, char* type = nullptr, double container = 0.0, char* cat = nullptr, bool four = false) :vehicle(cn, co, wh, po, type)
	 {
		 containerSize = container;
		 category = deepCopy(cat);
		 fourWheelDrive = four;
		 numberOfTrucks++;
	 }
	 truck(const truck& obj)
	 {
		 containerSize = obj.containerSize;
		 category = deepCopy(obj.category);
		 fourWheelDrive = obj.fourWheelDrive;
	 }
	 void setcontainer(double con)
	 {
		 containerSize = con;
	 }
	 void setcategory(char *cat)
	 {
		 category = deepCopy(cat);
	 }
	 void setfourwheels(bool four)
	 {
		 fourWheelDrive = four;
	 }
	 double getcontainer()
	 {
		 return containerSize;
	 }
	 char *getcategory()
	 {
		 char *temp;
		 temp = deepCopy(category);
		 return temp;
	 }
	 static int getnumberoftrucks()
	 {
		 return numberOfTrucks;
	 }
	 truck& operator =(const truck& obj)
	 {
		 if (this != &obj)
		 {
			 this->containerSize = obj.containerSize;
			 this->category = deepCopy(obj.category);
			 this->fourWheelDrive = obj.fourWheelDrive;
		 }
		 return *this;
	 }
	 void checkType()
	 {
		 if (vehicle::getnoofwheels() == 6)
		 {
			 vehicle::setvehicletype("TRUCK");
			 cout << vehicle::getvehicletype() << endl;
		 }
		 else
		 {
			 cout << "wrong input type " << endl;
		 }
	 }
	 void display()
	 {
		 vehicle::display();
		 cout << "containersize" << "  " << "category" << "  " << "fourwheel drive" << "  " << endl;
		 cout << containerSize << "              " << category << "            " << fourWheelDrive << "  " << endl;
	 }
	 void displayfile(ofstream& fout)
	 {
		 /*fout.open("file.txt",ios::out);
		 if (fout.is_open())
		 {
			 cout << "success " << endl;
		 }*/
		 vehicle::displayfile(fout);
		 fout << "containersize" << "  " << "category" << "  " << "fourwheel drive" << "  " << endl;
		 fout << containerSize << "  " << category << "  " << fourWheelDrive << "  " << endl;
		 //fout.close();
	 }
	 void setattributes()
	 {
		 vehicle::setattributes();
		 double container = 0.0;
		 cout << "container size : ";
		 cin >> container;
		 containerSize = container;
		 char cat[30];
		 cout << "category : ";
		 cin >> cat;
		 category = deepCopy(cat);
		 bool four = 0;
		 cout << "is it a four wheel drive? ";
		 cin >> four;
		 fourWheelDrive = four;
	 }
	 void countvehicles()
	 {
		 numberOfTrucks++;
	 }
	 ~truck()
	 {
		 if (category)
		 {
			 delete []category;
		 }
	 }
	 
 };
 int truck::numberOfTrucks = 0;

 class bilalmotors{
	 vehicle **arr;
	 int count;
 public:
	 bilalmotors()
	 {
		 /*this->arr = new vehicle *[count];
		 for (int i = 0; i < count; i++)
		 {
			 arr[i] = nullptr;
		 }*/
		 arr = nullptr;
		this->count = 0;
	 }
	 void setcount(int c)
	 {
		 count = c;
	 }
	 int getcount()
	 {
		 return count;
	 }
	 void setarray(vehicle **a)
	 {
		 this->arr = new vehicle *[count];
		 for (int i = 0; i < count; i++)
		 {
			 arr[i] = a[i];
		 }
	 }
	 vehicle **getarray()
	 {
		 vehicle **temp = new vehicle*[count];
		 for (int i = 0; i < count; i++)
		 {
			 temp[i] = arr[i];
		 }
		 return temp;
	 }
	 vehicle*& operator [](int index)
	 {
		 return arr[index];
	 }
	 vehicle* operator [](int index)const
	 {
		 return arr[index];
	 }

	 void searchVehicle(char* a)
	 {
		 bool yas = false;
		 bool nope = true;
		 char *temp;
		 for (int i = 0; i < count; i++)
		 {
			 temp = arr[i]->getvehicletype();
			 if (strlen(a) == strlen(temp))
			 {
				 for (int j = 0; j < strlen(a); j++)
				 {
					 if (a[j] == temp[j])
					 {
						 yas = true;
					 }
					 else
					 {
						 yas = false;
						 break;
					 }
				 }
			 }
			 if (yas)
			 {
				 nope = false;
				 arr[i]->display();
			 }
			 /*if (nope)
			 {
				 cout << "Sorry, no vehicle matches this dispriction " << endl;
			 }*/
		 }
		 if (nope)
		 {
			 cout << "Sorry, no vehicle matches this dispriction " << endl;
		 }
	 }
	 void addvehicle(vehicle *v)
	 {
		 vehicle** temp = new vehicle *[count+1];
		 int i = 0;
		 for (i; i < count; i++)
		 {
			 temp[i] = arr[i];
		 }
		 temp[i] = v;
		 temp[i]->countvehicles();
		 temp[i]->setattributes();
		 delete[]arr;
		 count = count + 1;
		 arr = temp;
	 }
	 bool saveData(const char* bilalishfaqmotors) const
	 {
		 ofstream fout;
		 fout.open(bilalishfaqmotors, ios::out);
		 if (!fout.is_open())
		 {
			 cout << "failed " << endl;
			 return false;
		 }
		 if (count == 0)
		 {
			 fout << "We are sorry, there are no vehicles available at this moment" << endl;
			 return false;
		 }
		 fout << "vehicle information " << endl;
		 fout << "---------------------" << endl;
		 fout << "Number of bikes : " << bike::getnumberofbikes() << endl;
		 fout << "Number of cars : " << car::getnumberofcars() << endl;
		 fout << "Number of trucks : " << truck::getnumberoftrucks() << endl;
		 for (int i = 0; i < count; i++)
		 {
			  arr[i]->displayfile(fout);
		 }
		 fout.close();
		 return true;
	 }
	 ~bilalmotors()
	 {
		 for (int i = 0; i < count; i++)
		 {
			 delete arr[i];
		 }
		 if (arr)
		 {
			 delete[]arr;
		 }
	 }
 };
 bool showvehicles(bilalmotors& obj)
 {
	 if (obj.getcount() == 0)
	 {
		 cout << "no vehicles available " << endl;
		 return false;
	 }
	 cout << "total vehicles : " << obj.getcount() << endl;
	 for (int i = 0; i < obj.getcount(); i++)
	 {
		 obj[i]->display();
	 }
	 return true;
 }
 int main()
 {
	 ofstream fout;
	vehicle *ptr = new bike("honda", "red", 2, 50,"bike", 4, true, true);
	ptr->display();
	cout << endl;
	 delete ptr;
	 ptr = new car("honda", "white", 4, 80, "car", 4, "whatever", 5);
	 ptr->display();
	 cout << endl;
	 
	 delete ptr;
	 ptr = new truck("suzuki", "yello", 6, 100, "truck", 30, "double", false);
	 ptr->display();
	 cout << endl;
	 char *a = ptr->getvehicletype();
	 delete ptr;
	 bilalmotors bilal;
	 vehicle *ptr2;
	 char choice = '\0';
	 cout << " *** BILAL MOTORS ***" << endl;
	 cout << " S Show vehicles list(brief)" << endl;
	 cout << " E Create a data file(output file)" << endl;
	 cout << " A Add new vehicle" << endl;
	 cout << " B for Bike" << endl;
	 cout << " C for Car" << endl;
	 cout << " T for Truck" << endl;
	 cout << " F Find Vehicle by type" << endl;
	 cout << " Q Quit Program" << endl;
	 cout << endl;
	 while (choice != 'Q')
	 {
		 cout << "enter your choice : ";
		 cin >> choice;
		 char arr[20];
		 if (choice == 'Q')
		 {
			 cout << "thank you, hope you found what you wanted : " << endl;
			 break;
		 }
		 else if (choice == 'S')
		 {
			 bool show = showvehicles(bilal);
		 }
		 else if (choice == 'E')
		 {
			 bool file = false;
			 cout << "enter file name with txt extension : ";
			 cin >> arr;
			 file = bilal.saveData(arr);
			 if (file)
			 {
				 cout << "information has been written in the file : " << endl;
			 }
			 else
			 {
				 cout << "failed" << endl;
			 }
		 }
		 else if (choice == 'A')
		 {
			 char vehiclechoice = '\0';
			 cout << "Which vehicle do you want to add : ";
			 cin >> vehiclechoice;
			 if (vehiclechoice == 'V')
			 {
				 cout << "we don't this vehicle" << endl;
				
			 }
			 else if (vehiclechoice == 'B')
			 {
				 ptr2 = new bike;
				 bilal.addvehicle(ptr2);
				 //delete ptr2;
			 }
			 else if (vehiclechoice == 'C')
			 {
				 ptr2 = new car;
				 bilal.addvehicle(ptr2);
				// delete ptr2;
			 }
			 else if (vehiclechoice == 'T')
			 {
				 ptr2 = new truck;
				 bilal.addvehicle(ptr2);
				// delete ptr2;
			 }
		 }
		 else if (choice == 'F')
		 {
			 cout << "what kind of vehicle do you want to search? " << endl;
			 cin >> arr;
			 bilal.searchVehicle(arr);
		 }
	 }
	 return 0;
 }