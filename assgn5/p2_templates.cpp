#include <stdio.h>
/*
    Your templated List class definition goes here.
*/
template <class T>
class List{
  private:
	T *arr;
  public:
	int length;
	List(int l){
		this->length=l;
		this->arr=new T[l];
	}
	~List(){
		delete[] arr;
	}
	void set(int ind, T data){
		this->arr[ind] = data;
	} 
	
	T get(int ind){
		return this->arr[ind];
	}
};



/*
    You shouldn't change the code below, unless you want to _temporarily_ change the main function while testing.
    Change it back when you're done.    
*/
typedef struct Point_ {
    int x;
    int y;
} Point;

int main(){
    List<int> integers(10);
    for(int i = 0; i < integers.length; i++){
        integers.set(i, i * 100);
        printf("%d ", integers.get(i));
    }
    printf("\n"); // this loop should print: 0 100 200 300 400 500 600 700 800 900 
    
    List<Point *> points(5);
    for(int i = 0; i < points.length; i++){
        Point * p = new Point;
        p->x = i * 10;
        p->y = i * 100;
        points.set(i, p);
        printf("(%d, %d) ", points.get(i)->x, points.get(i)->y);
        delete p;
    }
    printf("\n"); // this loop should print: (0, 0) (10, 100) (20, 200) (30, 300) (40, 400) 
}






class IntList { 	
int * list; 
	 public: 
	int length; 
	 	IntList(int len)
 { 		list = new int[len]; 
		length = len; 	} 	 	~IntList() { 		delete[] list; 	} 	 	int get(int index) { 		return list[index]; 	} 	 	void set(int index, int val) { 		list[index] = val; 	} };

 
