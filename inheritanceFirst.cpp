#include <iostream>
 
using namespace std;

// Base class
 class Shape 
 {
    public:
	  Shape() {
		cout << "Shape constructor is called \n ";
	  }
          void setWidth(int w)
          {
              width = w;
          }
          void setHeight(int h)
          {
                height = h;
          }
	   unsigned int getArea() { return (width * height); }

     protected:
           int width;
           int height;
 };

 // Derived class
 class Rectangle: public Shape
  {
    public:
	Rectangle() { cout << "Recetangle constructor is called \n"; }
      virtual unsigned int getArea()
	{
  		return (width * height + 10);
	}
  }; 

class Square: public Shape
{
	public:
		Square(unsigned int side) { 
			width = height = side ;
			cout << "square constructor is called \n";
		 }
		Square() { 
			if (width != height) 
				{ cout << " this is not an square, killing this instance \n;" ;
				  delete(this);
			} 
		}

	virtual unsigned int getArea() { return width * height;}
};

class qube : public Square
{
	public :
		qube(unsigned int side) : Square(side) { depth = side ;}
		qube() { cout << "qube constrcutor is called \n"; }
		unsigned int getArea() { return Square::getArea() * depth; }

	private :

		unsigned int depth;
};

int main(void)
{
    Rectangle * rect = new Rectangle();
    rect->setWidth(5);
    rect->setHeight(7);
    Square * sqr = new Square(5);
    qube * qb =  new qube(10);
    Shape * sp = new Shape();
     cout << " before assigned drived pointer  " << sp->getArea() << "\n";

   rect = sp;
     cout << " after assigned drived pointer  " << sp->getArea() << "\n";

   sp = qb;
     cout << " after assigned grand children class  " << sp->getArea() << "\n";
   // Print the area of the object.
   //cout << "Total area: " << Rect.getArea() << endl;
   //cout << "Total sq area: " << sqr.getArea() << endl;

   return 0;
}
