// №8e В двухбайтовом числе в 3-ю тетраду записать код, равный разности значений  1-й и 2-й тетрад.

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

unsigned char calcDiff(unsigned short number) {
    //1-я тетра (биты 8-11)
    unsigned char firstTetra = (number & 0x0F00) >> 8;
    //2-я тетра (биты 4-7)
    unsigned char secondTetra = (number & 0x00F0) >> 4;

    unsigned char diff = firstTetra - secondTetra;

    //Запись разности в 3-ю тетраду (биты 0-3)
    //Сохраняем старшие тетрады и записываем разность в младшую
    number = (number & 0xFF00) | (diff & 0x0F);

    return diff;
}

int main() {
    unsigned short number = userInput();
    unsigned char diff = calcDiff(number);

    //Отображение двоичной формы для наглядного подсчета
    std::bitset<16> binary(number);
    std::cout << "Двоичное представление: " << binary << std::endl;


    std::bitset<4> binaryDiff(diff);
    std::cout << "Двоичное представление разности: " << binaryDiff << std::endl;


    unsigned short result = (number & 0xFF00) | (diff & 0x0F);
    std::bitset<16> binaryResult(result);
    std::cout << "Двоичное представление результата: " << binaryResult << std::endl;
    std::cout << "Десятеричное представление результата: " << result << std::endl;

    return 0;
}
