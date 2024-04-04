#include <stdio.h>
#include <string.h>

int main() {
    char word1[101], word2[101]; //создаём два буфера для двух слов
    int freq1[26] = {0}, freq2[26] = {0}; //создаём два массива для хранения количества сколько каких символов в строках
    
    FILE *input = fopen("input.txt", "r"); //открываем файл на чтение
    fscanf(input, "%s %s", word1, word2); //считываем из файла два слова разделённых пробелом в массивы word1, word2
    fclose(input); //закрываем файл
    
    for (int i = 0; i < strlen(word1); i++) { //считаем символы в массиве и 
        freq1[word1[i] - 'a']++; //вычисляем индекс элемента который надо увеличить
    }
    
    for (int i = 0; i < strlen(word2); i++) { //делаем тоже, что и выше
        freq2[word2[i] - 'a']++;
    }

    FILE *output = fopen("output.txt", "w"); //открываем файл на запись
    for (int i = 0; i < 26; i++) {
        if (freq1[i] == 1 && freq2[i] == 1) { //проверяем на каких позициях 1 и прибавляя к индексу 'a' получаем символ 
            fprintf(output, "%c ", i + 'a'); //записываем его в файл
        }
    }
    fclose(output);

    return 0;
}