#include "Header.h"

int main()
{
    setlocale(LC_ALL, "");

    wchar_t temp[256] = { L'\0' };


    FILE* input = fopen("input.txt", "r");

    if (!input)
    {
        wprintf("Ошибка чтения файла");
    }
    else
    {
        wchar_t space = L" ";
        wchar_t temp__ = L"-";

        fgetws(temp, 256, input);
        fclose(input);        
        int len = wcslen(temp);
        wprintf(L"\n%ls\n", temp);
        int size = (int)ceil(len / 6.0);

        int* key = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++)
        {
            key[i] = i;
        }

        printf("\n");

        int ROWS = size;

        encrypto(ROWS,temp);

        if (decrypto(ROWS) == true)
        {
            wprintf(L"\nКодирование - декодирование произошло успешно!\n");
        }
        else
        {
            wprintf(L"\nКодирование - декодирование произошло с ошибкой!\n");
        }
        free(key);
    }

    return 0;
}
