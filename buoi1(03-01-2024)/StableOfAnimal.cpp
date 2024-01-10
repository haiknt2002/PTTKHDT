/*
- Một cô gái (Sury) có:
    + Một chuồng gồm nhiều ngăn để nuôi các con vật làm cảnh,
    mỗi ngăn chỉ chứa 1 con, mỗi con đều có tên
    + Có nhiều loại con vật khác nhau
- Do số lượng ngày càng nhiều, Sury cần:
    + Xây dựng 1 chương trình để quản lí các con vật trên
- Chương trình có nhiệm vụ gì?
    + Xác định danh tính con vật trong từng ngăn
    + Thêm con vật vào chuồng, lấy một con vật ra khỏi chuồng
    + Có thể sửa chữa, mở rộng chương trình một cách dễ dàng
*/
/*
    class Animal:
        id : int;
        name : string;
        local : int;     //index of Animal in Array

    class
    class Stable:
        array of Animal;

        RemoveAnimal();
        AddAnimal();        // add animal to index is null from begin
*/

#include <iostream>
#include <vector>
#include <string>

class Animal
{
private:
    std::string name;

public:
    Animal() : name("") {}
    Animal(std::string name) : name(name) {}
    virtual ~Animal(){};
    virtual void Sound() = 0;
    std::string getName()
    {
        return name;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal() {}
    Cat(std::string name) : Animal(name) {}
    ~Cat() override
    {
        std::cout << "Deleted Cat: " << getName() << std::endl;
    }
    void Sound() override
    {
        std::cout << "Cat: " << getName() << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal() {}
    Dog(std::string name) : Animal(name) {}
    ~Dog() override
    {
        std::cout << "Deleted Dog: " << getName() << std::endl;
    }
    void Sound() override
    {
        std::cout << "Dog: " << getName() << std::endl;
    }
};

class Stable
{
private:
    std::vector<Animal *> animals;
    int maxSize;

public:
    Stable() : maxSize(10) {}           // Default maximum size
    Stable(int size) : maxSize(size) {} // Custom maximum size
    ~Stable()
    {
        // std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Clear Stable:" << std::endl;
        for (auto &animal : animals)
        {
            delete animal;
        }
        animals.clear();
    }

    void AcceptAnimal(Animal *a)
    {
        if (animals.size() < maxSize)
        {
            animals.push_back(a);
        }
        else
        {
            std::cout << "Stable is full. Cannot accept more animals." << std::endl;
        }
    }

    void ReleaseAnimal(int index)
    {
        if (index >= 0 && index < animals.size())
        {
            delete animals[index];
            animals.erase(animals.begin() + index);
        }
    }

    void LoadStable()
    {
        std::cout << "---------------------------------------------------" << std::endl;

        for (auto &animal : animals)
        {
            animal->Sound();
        }
        std::cout << "---------------------------------------------------" << std::endl;
    }
};

int main()
{
    Stable stable(2); // Create a stable with a maximum size of 2
    Cat *cat = new Cat("Whiskers");
    Dog *dog = new Dog("Buddy");
    Dog *anotherDog = new Dog("Max");

    stable.AcceptAnimal(cat);
    stable.AcceptAnimal(dog);
    stable.AcceptAnimal(anotherDog); // This won't be accepted due to the size limit

    stable.LoadStable();

    stable.ReleaseAnimal(0);

    stable.LoadStable();

    return 0;
}
