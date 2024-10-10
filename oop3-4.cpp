// №4 Переставьте в обратном порядке все биты в однобайтовом числе.

#include <iostream>
#include <bitset>

unsigned char userInput() {
    unsigned int number;
    std::cout << "Введите однобайтовое число (0-255): "<< std::endl;
    std::cin >> number;
    if (number >= 0 && number <= 255){
        return static_cast<unsigned char>(number);
    }
    else {
        return userInput();
    }
}

unsigned char reverseBits(unsigned char n) {
    unsigned char reversed = 0;
    for (int i = 0; i < 8; ++i) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed;
}

int main() {
    unsigned char number = userInput();
    unsigned char result = reverseBits(number);

    // Отображение двоичной формы для наглядности
    std::bitset<8> binary(number);
    std::bitset<8> reversedBinary(result);
    std::cout << "Двоичное представление: " << binary << std::endl;
    std::cout << "Перевернутое представление: " << reversedBinary << std::endl;

    return 0;
}
