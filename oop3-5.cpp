// №5 В двухбайтовом числе все нули в старшей тетраде поменять на единицы, а в младшей тетраде поменять все единицы на нули.

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

unsigned short modifyTetra(unsigned short number) {
    unsigned short modifiedHighTetra = (number & 0x0F00) ^ 0x0F00;
    unsigned short modifiedLowTetra = (number & 0x00FF) ^ 0x00FF;

    //Объединяем измененные тетрады
    return modifiedHighTetra | modifiedLowTetra;
}

int main() {
    unsigned short number = userInput();
    unsigned short result = modifyTetra(number);

    // Отображение двоичной формы для наглядного подсчета
    std::bitset<16> binary(number);
    std::cout << "Двоичное представление исходного числа: " << binary << std::endl;

    // Отображение результата
    std::bitset<16> binaryResult(result);
    std::cout << "Двоичное представление результата: " << binaryResult << std::endl;
    std::cout << "Десятеричное представление результата: " << result << std::endl;

    return 0;
}
