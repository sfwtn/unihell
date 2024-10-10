// №7g Обычно при циклическом сдвиге  “выдвигаемые“ (за границу числа) разряды “задвигаются” в сдвигаемое значение со стороны, противоположной направлению сдвига. Реализовать циклический сдвиг двухбайтового числа влево на 3 разряда.

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

unsigned short shiftLeft(unsigned short number, int shift) {
    return (number << shift) | (number >> (16 - shift));
}

int main() {
    unsigned short number = userInput();
    unsigned short result = shiftLeft(number, 3);

    // Отображение двоичной формы для наглядного подсчета
    std::bitset<16> binary(number);
    std::cout << "Двоичное представление исходного числа: " << binary << std::endl;

    // Отображение результата
    std::bitset<16> binaryResult(result);
    std::cout << "Двоичное представление результата: " << binaryResult << std::endl;
    std::cout << "Десятеричное представление результата: " << result << std::endl;

    return 0;
}
