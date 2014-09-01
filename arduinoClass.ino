
// This is a class declaration
class Button {
// Private variables cant be accessed by anything but the object
private:
  byte down_at;
  byte down;
  
// Public variables and functions (methods) can be accessed anywhere
public:
  // These are simply method declarations, they are defined later
  Button();           // This is a special method called the constructructor - called once when you initialise a member of the class
  byte downFor();     
  void resetDown();
  bool isDown();
  void turnOn();
  void turnOff();
};


// You define a method in this way - button means its a member of the button class, downFor() is the method name
Button::downFor(){
    // put what you want to happen when we call Button.downFor() here
}

// You define the constructor like this
Button::Button()
{
  this->down_at = 0;
  this->down = 0;
}
