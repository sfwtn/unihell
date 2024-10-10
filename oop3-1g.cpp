// №1g В значении целого типа (4 байта) поменять местами 2-й и 3-й байты, причём 2-й байт надо перенести в новое место с инверсией.

#include <iostream>
#include <bitset>

unsigned int userInput() {
    unsigned long number;
    std::cout << "Введите целое число (0-4294967295): " << std::endl;
    std::cin >> number;
    if (number >= 0 && number <= 4294967295) {
        return static_cast<unsigned int>(number);
    } else {
        return userInput();
    }
}

unsigned int swapAndInvertBytes(unsigned int number) {
    //Извлечение байтов
    unsigned char byte1 = (number & 0x000000FF);       //1-й байт
    unsigned char byte2 = (number & 0x0000FF00) >> 8;  //2-й байт
    unsigned char byte3 = (number & 0x00FF0000) >> 16; //3-й байт
    unsigned char byte4 = (number & 0xFF000000) >> 24; //4-й байт

    byte2 = ~byte2;
    return (byte1) | (byte3 << 8) | (byte2 << 16) | (byte4 << 24);
}

int main() {
    unsigned int number = userInput();
    unsigned int result = swapAndInvertBytes(number);

    // Отображение двоичной формы для наглядного подсчета
    std::bitset<32> binary(number);
    std::cout << "Двоичное представление исходного числа: " << binary << std::endl;

    // Отображение результата
    std::bitset<32> binaryResult(result);
    std::cout << "Двоичное представление результата: " << binaryResult << std::endl;
    std::cout << "Десятеричное представление результата: " << result << std::endl;

    return 0;
}
