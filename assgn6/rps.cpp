#include <iostream>

using namespace std;

class Tool {
  public:
	Tool(){}
	virtual bool fight(Tool &T)= 0;
	void set_strength(int s) {
		this->strength=s;
	}
	int get_strength(){
		return strength;
	}
	char get_type(){
		return type;	
	}
	virtual ~Tool(){}
  protected:
	int strength;
	char type;
};


class Scissors:public Tool{
  public:
	Scissors(int s){
		strength=s;
		type='s';
	}

	virtual bool fight(Tool &t){
		int temp_s=strength;
		if(t.get_type()=='p'){
			temp_s=2*strength;
		}else if(t.get_type()=='r'){
			temp_s=strength/2;
		}
		if(temp_s < t.get_strength()){
			return false; 	
		} else {
			return true;
		}
	}
	
};

class Paper:public Tool{
  public:
	Paper(int s){
		strength=s;
		type='p';
	}

	virtual bool fight(Tool & t){
		int temp_s=strength;
		if(t.get_type()=='r'){
			temp_s=2*strength;
		}else if(t.get_type()=='s'){
			temp_s=strength/2;
		}
		if(temp_s < t.get_strength()){
			return false; 	
		} else {
			return true;
		}
	}

};

class Rock:public Tool{
  public:
	Rock(int s){
		strength=s;
		type='r';
	}

	virtual bool fight(Tool& t){
		int temp_s=strength;
		if(t.get_type()=='s'){
			temp_s=2*strength;
		}else if(t.get_type()=='p'){
			temp_s=strength/2;
		}
		if(temp_s < t.get_strength()){
			return false; 	
		} else {
			return true;
		}
	}

};


int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

	return 0;
}
