#include <iostream>

// Базовый класс Triad
class Triad {
protected:
    int x, y, z;
public:
    Triad(int a, int b, int c) : x(a), y(b), z(c) {}

    int getX() const { return x; } // Добавлены методы для получения значений x, y, z
    int getY() const { return y; }

    int getZ() const { return z; }

    Triad operator+(int num) {
        return Triad(x + num, y + num, z + num);
    }

    Triad operator*(int num) {
        return Triad(x * num, y * num, z * num);
    }

    bool operator==(const Triad &other) {
        return (x == other.x && y == other.y && z == other.z);
    }
};

// Производный класс Vector3D
class Vector3D : public Triad {
public:
    Vector3D(int a, int b, int c) : Triad(a, b, c) {}

    Vector3D operator+(const Vector3D &vec) {
        return Vector3D(x + vec.x, y + vec.y, z + vec.z);
    }

    int operator*(const Vector3D &vec) {
        return (x * vec.x + y * vec.y + z * vec.z);
    }

    void displayCoordinates() {
        std::cout << "Coordinates: (" << getX() << ", " << getY() << ", " << getZ() << ")" << std::endl;
    }
};

int main() {
    bool continueRunning;

    do {
        int choice;

        std::cout << "Выберите действие (1 - операции с Triad, 2 - операции с VectorD, 0 - выход): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int a, b, c;
                std::cout << "Введите три целых числа: ";
                std::cin >> a >> b >> c;
                Triad t1(a, b, c);

                int num;
                std::cout << "Введите целое число для операций сложения и умножения: ";
                std::cin >> num;

                Triad result_addition = t1 + num;
                Triad result_multiplication = t1 * num;

                std::cout << "Исходная Triad: (" << t1.getX() << ", " << t1.getY() << ", " << t1.getZ() << ")"
                          << std::endl;
                std::cout << "Результат сложения с числом " << num << ": (" << result_addition.getX() << ", "
                          << result_addition.getY() << ", " << result_addition.getZ() << ")" << std::endl;
                std::cout << "Результат умножения на число " << num << ": (" << result_multiplication.getX() << ", "
                          << result_multiplication.getY() << ", " << result_multiplication.getZ() << ")" << std::endl;
                break;
            }


            case 2: {
                int x1, y1, z1, x2, y2, z2;
                std::cout << "Введите первую тройку координат: ";
                std::cin >> x1 >> y1 >> z1;
                Vector3D v1(x1, y1, z1);

                std::cout << "Введите вторую тройку координат: ";
                std::cin >> x2 >> y2 >> z2;
                Vector3D v2(x2, y2, z2);

                Vector3D addition_result = v1 + v2;
                int scalar_product = v1 * v2;

                // Utilizing a member function to display the results
                std::cout << "Результат операции сложения: ";
                addition_result.displayCoordinates();
                std::cout << "Результат скалярного произведения: " << scalar_product << std::endl;
                break;
            }

            case 0: {
                break;
            }

            default: {
                std::cout << "Некорректный выбор действия." << std::endl;
                break;
            }
        }
    } while (continueRunning);


    std::cout << "Программа завершена." << std::endl;
    return 0;
}

