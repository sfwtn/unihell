// №9 Подсчитать число единиц в однобайтовом числе.

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

unsigned char countOnes(unsigned char n) {
    //"Базовый случай" при достижении которого рекурсия прекращается, чтобы n не перешел в отрицательные
    if (n == 0) {
        return 0;
    } else {
        //Битовая операция проверяющая последний бит числа, в данном случае явл. ли 1
        //Затем выполняется рекурсия с повышением бита
        return (n & 1) + countOnes(n >> 1);
    }
}

int main() {
    unsigned char number = userInput();
    unsigned char result = countOnes(number);

    //Отображение двоичной формы для наглядного подсчета
    std::bitset<8> binary(number);
    std::cout << "Двоичное представление: " << binary << std::endl;
    std::cout << "Количество единиц в числе: " << static_cast<int>(result) << std::endl;

    return 0;
}
