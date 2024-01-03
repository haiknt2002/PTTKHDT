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
        style : string;
        local : int;     //index of Animal in List

    class Stable: 
        list of Animal;

        RemoveAnimal();
        AddAnimal();        // add animal to index is null from begin
*/
#include <iostream>
#include <string>
#include <list>

class Animal {
public:
    int id;
    std::string name;
    std::string style;
    int local; // index of Animal in Stable

    Animal(int id, const std::string& name, const std::string& style, int local) {
        this->id = id;
        this->name = name;
        this->style = style;
        this->local = local;
    }
};

class Stable {
private:
    std::list<Animal> animals;

public:
    void RemoveAnimal(int index) {
        if (index < 0 || index >= animals.size()) {
            std::cout << "Invalid index to remove animal." << std::endl;
            return;
        }

        auto it = animals.begin();
        std::advance(it, index);
        animals.erase(it);

        // Update local indices of animals after the removed one
        int i = 0;
        for (auto& animal : animals) {
            animal.local = i;
            ++i;
        }

        std::cout << "Animal removed from index " << index << std::endl;
    }

    void AddAnimal(int index, const Animal& newAnimal) {
        if (index < 0 || index > animals.size()) {
            std::cout << "Invalid index to add animal." << std::endl;
            return;
        }

        auto it = animals.begin();
        std::advance(it, index);
        animals.insert(it, newAnimal);

        // Update local indices of animals after the added one
        int i = 0;
        for (auto& animal : animals) {
            animal.local = i;
            ++i;
        }

        std::cout << "Animal added to the stable at index " << index << std::endl;
    }

    void DisplayStable() {
        std::cout << "Animals in the stable:" << std::endl;
        for (const auto& animal : animals) {
            std::cout << "Index: " << animal.local << ", Name: " << animal.name << std::endl;
        }
    }
};

int main() {
    Stable stable;

    // Example of adding animals to the stable
    Animal cat{1, "Fluffy", "Cat", 0};
    Animal dog{2, "Buddy", "Dog", 0};
    stable.AddAnimal(0, cat);
    stable.AddAnimal(1, dog);

    // Displaying animals in the stable
    stable.DisplayStable();

    // Removing an animal from the stable
    stable.RemoveAnimal(1);
    stable.DisplayStable();

    return 0;
}
