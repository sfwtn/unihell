#include <iostream>
#include <bitset>

unsigned short userInput() {
    unsigned int number;
    std::cout << "Введите двухбайтовое число (0-65535): " << std::endl;
    std::cin >> number;
    if (number >= 0 && number <= 65535) {
        return static_cast<unsigned short>(number);
    } else {
        return userInput();
    }
}

unsigned char calcSum(unsigned short firstNumber, unsigned short secondNumber) {
    unsigned char firstQ = (firstNumber & 0xF000);
    unsigned char thirdQ = (secondNumber & 0x00F0);

    // Сумма первой тетрады первого числа и третьей тетрады второго числа
    unsigned char sum = firstQ + thirdQ;

    return sum; // Возвращаем сумму без ограничения
}

int main() {
    std::cout << "Введите первое число:" << std::endl;
    unsigned short firstNumber = userInput();

    std::cout << "Введите второе число:" << std::endl;
    unsigned short secondNumber = userInput();

    unsigned char sum = calcSum(firstNumber, secondNumber);

    // Отображение двоичной формы результата

    std::bitset<16> firstBinary(firstNumber);
    std::bitset<16> secondBinary(secondNumber);
    std::cout << "Двоичное представление числла 1: " << firstBinary << std::endl;
    std::cout << "Двоичное представление числла 2: " << secondBinary << std::endl;
    std::cout << "Двоичное представление результата: " << sum << std::endl;

    return 0;
}
