#include "Header.h"

bool decrypto(int ROWS)
{
    FILE* check = fopen("output.txt", "r");

    FILE* input = fopen("input.txt", "r");

    int size = (COLS * ROWS);

    wchar_t* temp = (wchar_t*)malloc(sizeof(wchar_t*) * (size + 1));
    wchar_t* temp_input = (wchar_t*)malloc(sizeof(wchar_t*) * size);

    fgetws(temp, size + 1, check);
    fgetws(temp_input, size + 1, input);

    wchar_t* output_arr = (wchar_t*)malloc(sizeof(wchar_t*) * (size + 1));

    wchar_t** matrix = (wchar_t**)malloc(sizeof(wchar_t*) * COLS);

    for (int i = 0; i < COLS; i++)
    {
        matrix[i] = (wchar_t*)malloc(sizeof(wchar_t) * ROWS);
    }

    int k = 0;

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            matrix[i][j] = temp[k];
            wprintf(L"%lc ", matrix[i][j]);
            k++;
        }
        wprintf(L"\n");
    }
    k = 0;
    ;   for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            output_arr[k] = matrix[j][i];
            k++;
        }
    }
    wprintf("\n");

    for (int i = 0; i < size; i++)
    {
        if (output_arr[i] == L'_')
        {
            output_arr[i] = L' ';
        }
    }

    for (int i = 0; i < size; i++)
    {
        wprintf(L"%lc", output_arr[i]);

    }
    wprintf("\n");

    for (int i = 0; i < COLS; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    if (wcschr(output_arr, temp_input) == 0)
    {
        free(temp_input);
        free(output_arr);
        return true;
    }
    else
    {
        free(temp_input);
        free(output_arr);
        return false;
    }

}

int encrypto(int ROWS, wchar_t temp[])
{
    FILE* output = fopen("output.txt", "w");
    int k = 0;
    wchar_t** matrix = (wchar_t**)malloc(sizeof(wchar_t*) * ROWS);

    for (int i = 0; i < ROWS; i++)
    {
        matrix[i] = (wchar_t*)malloc(sizeof(wchar_t) * COLS);
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (k != wcslen(temp))
            {
                if (temp[k] == L' ')
                {
                    matrix[i][j] = L'_';
                    k++;
                }
                else
                {
                    matrix[i][j] = temp[k];
                    k++;
                }
            }
            else
            {
                matrix[i][j] = L'_';
            }
        }
    }


    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            wprintf(L" %c ", matrix[i][j]);
        }
        printf("\n");
    }

    wprintf(L"Зашифрованный текст: ");

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            wprintf(L"%c", matrix[j][i]);
            fwprintf(output, L"%c", matrix[j][i]);
        }
    }

    wprintf(L"\n");

    for (int i = 0; i < ROWS; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    fclose(output);

}