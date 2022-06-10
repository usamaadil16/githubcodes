#include <iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
#include <stdio.h>
using namespace std;

class Plant {
	char pname[20];
	int price;
	public:
	void setplant(char pname[], int price){
		strcpy(this -> pname,pname);
		this->price=price; 
	}
	char* getname(){
		return pname;
	}	
	int getprice(){
		return price;
	}
		friend ostream& operator << (ostream &out, const Plant &p);

};
	ostream& operator << (ostream &out, const Plant &p){
		out<< " name of plant: "<< setw(20)<<p.pname<< "\t|"<<"price: "<<setw(10)<<p.price<<"\t\t|";
		return out;
	}



class Nursery{
	char nname[20] = "Weed land" , type[20];
	int cap=50;
	int csize=0;
	Plant plant;

	public:
	void setnursery(char name[], int price, char type[]){
		plant.setplant(name, price);
		strcpy(this->type,type);
		}
	bool isimportant(){
		int x;
		x=plant.getprice();
		if(x>1000)return true;
		else return false;
	}	
	char* gettype(){
		return type;
	}
	int getprice(){
		return plant.getprice();
	}
	char* getname(){
		return plant.getname();
	}
	  
	  // ~Nursery(){}
	
	friend ostream& operator << (ostream &out, const Nursery &n);
};
ostream& operator << (ostream &out, const Nursery &n){
    out<<"name of nursery: "<< n.nname <<"\t  |" << " plant info: "<<n.plant<<" plant type: "<<n.type<< "\t\t|"<<endl;
//	if(n.isimportant()==true) out<< "important plant";
//	else out<<"not a very important plant"<<endl;
	return out;
	}


int main(){
	#define COUNT 5
	#define quit 0
	char plant_name[20],type[20], gg[2] ;
	Nursery n[COUNT], *newN , nursery;
	int choice,count,price,mod;
	char names[COUNT][20] ={"Fern","Aloe Vera","Lemon tree","Jasmine","Forsythia", };
    int prices[COUNT] ={500,700,800,500,500};
    char types[COUNT][20]={"bush","weed","tree","flower","flower"};
    for (int i=0;i<COUNT;i++){
    	n[i].setnursery(names[i], prices[i],types[i]);
	}
	fstream file("nursery.bin", ios::binary|ios::in|ios::out);
	if (file.fail()){//check if file successfully opened
		ofstream out("nursery.bin");//Otherwise create a new file
		out.close();				//close file
		file.open("nursery.bin", ios::binary |ios::in | ios::out);//Reopen in reading+writing mode
	}
	file.write((char*) n, sizeof(Nursery) * COUNT);
	
	
	do{
	cout<<"press 1 for adding plant\n";
	cout<<"press 2 for removing plant\n";
	cout<<"press 3 for modifing plant\n";
	cout<<"press 4 to show all records\n";
	cout<<"press 0 to terminate\n";

	cout<<"enter choice of operation:\n";
	cin>> choice;
	switch(choice){
		case 1:
                       cout<<"enter plant name: \n";
			cin.getline( gg, 2);
			cin.getline(plant_name,20);
			cout<<"enter plant price:\n";
			cin>>price;
			cout<<"enter plant type:\n";
			cin.getline( gg, 2);
			cin.getline(type, sizeof(type));
			nursery.setnursery(plant_name, price, type); 
			file.seekp(0, ios::end);
			file.write ( (char*) &nursery, sizeof(Nursery) );
			break;
		
		case 2:{
		
			int rec;
			cout<<"enter number of the record to be deleted:\n";
			cin>> rec;
			file.seekg(0, ios::end);
			count = file.tellg() / sizeof(Nursery);
			if (rec > count){	//Check file has n records?
					if (count == 0) cout << "Sorry no record in the file\n";
					else			cout << "Sorry, File has less than n records\n";
					break;
				}
				file.seekg(0);
				newN = new Nursery [count];
				file.read ( (char*) newN, sizeof(Nursery) * count );
				rec--;
			file.close();
			remove("nursery.bin");
			ofstream out ("nursery.bin",ios::binary);
			out.write((char*) &newN[0], sizeof(Nursery)*rec);
			out.write((char*) &newN[rec+1], sizeof(Nursery)*(count-rec-1));
			out.close();
			delete []newN;
			file.open("nursery.bin", ios::binary |ios::in | ios::out);
			break;
		}
		case 3:{
			
		    cout<< "enter rec no to be modified:\n";
			cin>> mod;
			mod=mod-1;
			file.seekp(sizeof (Nursery) * mod);
                       cout<<"enter plant name: \n";
			cin.getline( gg, 2);
			cin.getline(plant_name,20);
			
			cout<<"enter plant price:\n";
			cin>>price;
			cout<<"enter plant type:\n";
                       cin.getline( gg, 2);
			cin.getline(type, sizeof(type));
			nursery.setnursery(plant_name,price,type);
			file.write((char*) &nursery , sizeof(Nursery) );
			break;
		}
		case 4:
		    	file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Nursery);//Counting number of objects
				file.seekg(0);
				newN = new Nursery [count];	
				cout<<"number of records: "<<count<<endl;
				file.read ( (char*) newN, sizeof(Nursery) * count );
				for (int i=0;i<count;i++)
					cout << newN[i];
				delete []newN;
				break;
			
				 
	}
}while (choice!=quit);
	file.close();

		cout << "\n\n\t\tThanks for using this program\n";

//	cout <<nursery << "\n";
   // newN.~Nursery();
	//nursery.~Nursery() ;
		
	return 0;
}

