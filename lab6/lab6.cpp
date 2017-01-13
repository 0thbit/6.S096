#include <stdio.h>  

class Shape {
 public: 
	virtual ~Shape();
 	virtual void draw();
}; 

class Circle : public Shape {
 public: 
	~Circle(); 
	virtual void draw();
};  

Shape::~Shape() { 	
	printf("shape destructor\n");
}  

 void Shape::draw(){ 
	printf("Shape::draw\n"); 
 }  

Circle::~Circle() { 
	printf("circle destructor\n"); 
}  

void Circle::draw() { 
	printf("Circle::draw\n");
}  

int main() { 
	Shape *shape = new Circle; 
	Shape o_shape;
	shape->draw();
 	o_shape.draw();
	delete shape;  	
	return 0;
} 
