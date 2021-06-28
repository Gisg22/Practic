
#include <iostream>

class Component { //базовый класс, от которого наследуются все классы. Имеет только одну виртуальную функцию.
public: 
    Component(std::string name); //конструктор.
    virtual void Print() = 0; //вывод.
protected:
    std::string name_; //имя.
};

Component::Component(std::string name) {
    name_ = name;
}


class Camera : public Component {
public:
    Camera(std::string name, int megaPx);
    void Print() override; //переопределение виртуальной функции
    void Photograph();  //сделать фотографию
private:
    int megaPx_; //количество пикселеј
};

Camera::Camera(std::string name, int megaPx) : Component(name) {
    megaPx_ = megaPx;
}

void Camera::Print() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Megapixel: " << megaPx_ << std::endl;
}

void Camera::Photograph() {
    std::cout << "You photographed!" << std::endl;
}

class Processor : public Component {
public:
    Processor(std::string name,  int quantity_cores);
    void Print() override;
private:
    int quantity_cores_; //количество ядер.
};

Processor::Processor(std::string name, int quantity_cores) : Component(name){
    quantity_cores_ = quantity_cores;
};

void Processor::Print() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Quantity in cores: " << quantity_cores_ << std::endl;
}

class Operator : public Component {
public:
    Operator(std::string name, int number);
    void Print() override;
    void Speak(); //возможность говорить.
private:
    int number_;
};

Operator::Operator(std::string name, int number) : Component(name) {
    number_ = number;
}

void Operator::Print() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Number: " << number_ << std::endl;
}

void Operator::Speak() {
    std::cout << "You speak!" << std::endl;
}

class Phone : public Component {
public:
    Phone(std::string name, int version, int memory_volume);
    void Print() override;
    void Print_Camera( Camera *Cam); //передаются аргументы в виде указателя на класс, чтобы вызвать методы того класса
    void Print_Processor(Processor *Proc);
    void Print_Operator(Operator *Op);
    void Photograph_Camera(Camera* Cam);
    void Speak_Operator(Operator* Op);
private:
    int version_; //версия
    int memory_volume_; //объем памяти
    
};

Phone::Phone(std::string name, int version, int memory_volume) :Component(name) {
    version_ = version;
    memory_volume_ = memory_volume;
}

void Phone::Print() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Version: " << version_ << std::endl;
    std::cout << "Memory volume: " << memory_volume_ << std::endl;
}

void Phone::Print_Camera( Camera* Cam) {
    (*Cam).Print(); //вызывается метод у указателя
}

void Phone::Print_Processor(Processor* Proc) {
    (*Proc).Print();
}

void Phone::Print_Operator(Operator* Op) {
    (*Op).Print();
}

void Phone::Photograph_Camera(Camera* Cam) {
    (*Cam).Photograph();
}

void Phone::Speak_Operator(Operator* Op) {
    (*Op).Speak();
}

int main()
{
    Phone Samsung("Samsung", 12, 64);
    Camera SamsungСam("SamsungСam", 1200);
    Samsung.Photograph_Camera(&SamsungСam); //камера теперь в телефоне.
   
    
}

