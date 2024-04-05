#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char arr[255] = "I am in New-York";
    char res[255] = {};
    int indexx = 0;
    int sizee = strlen(arr);
    _asm {
        mov ebx, 0
        mov ecx, sizee
        mov edx, 0

    loop_start:
        cmp ebx, ecx
        jge loop_end

        cmp arr[ebx], ' '
        je skip_loop
        cmp arr[ebx], '.'
        je skip_loop
        cmp arr[ebx], ','
        je skip_loop

        cmp esi, 0
        je first
        jmp first

    skip_loop:
        inc ebx
        jmp loop_start

    big_letter_loop:
        cmp ebx, ecx
        je loop_end
        cmp arr[ebx], ' '
        je loop_start
        cmp arr[ebx], ','
        je loop_start
        cmp arr[ebx], '.'
        je loop_start
        inc ebx
        jmp big_letter_loop

    first:
        cmp ebx, ecx
        je loop_end

        cmp arr[ebx], 'a'
        jl big_letter_loop
        cmp arr[ebx], 'z'
        jg big_letter_loop

    write_loop:
        cmp ebx, ecx
        je loop_end
        cmp arr[ebx], ' '
        je continue_loop
        cmp arr[ebx], ','
        je continue_loop
        cmp arr[ebx], '.'
        je continue_loop

        mov al, arr[ebx]
        mov res[edx], al
        inc edx
        inc ebx
        jmp write_loop



    continue_loop:
        mov res[edx], ' '
        inc edx
        jmp loop_start
    

    loop_end:
    }

    cout << res;
    return 0;
}
