//SOURCE CODE:
#include<stdio.h>

int main()
{
//variable declaration and initialization
int frames_number, pages_number, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, miss = 0;
//code to input the frame number
printf("Enter number of frames: ");
scanf("%d", & frames_number);
//code to input number of pages
printf("Enter number of pages: ");
scanf("%d", &pages_number);
//code to define reference string, page numbers, and frame numbers
printf("Enter page reference string: ");
for(i = 0; i < pages_number; ++i){
scanf("%d", &pages[i]);
}
for(i = 0; i < frames_number; ++i){
frames[i] = -1;
}
for(i = 0; i < pages_number; ++i){
flag1 = flag2 = 0;
for(j = 0; j < frames_number; ++j){
if(frames[j] == pages[i]){
flag1 = flag2 = 1;
break;
}
}
//definition of the flag at the starting of the string
if(flag1 == 0){
for(j = 0; j < frames_number; ++j){
if(frames[j] == -1){
flag3++;
frames[j] = pages[i];
flag2 = 1;
break;
}
}
}
// definition of the flag at the mid position
if(flag2 == 0){
flag3 =0;
for(j = 0; j < frames_number; ++j){
temp[j] = -1;
for(k = i + 1; k < pages_number; ++k){
if(frames[j] == pages[k]){
temp[j] = k;
break;
}
}
}
for(j = 0; j < frames_number; ++j){
if(temp[j] == -1){
pos = j;
flag3 = 1;
break;
}
}
//definition of flag at the rear position
if(flag3 ==0){
max = temp[0];
pos = 0;
for(j = 1; j < frames_number; ++j){ if(temp[j] > max){
max = temp[j];
pos = j;
}
}
}
frames[pos] = pages[i];
miss++;
}
printf("\n");
for(j = 0; j < frames_number; ++j){
printf("%d\t", frames[j]);
}
}
printf("\n\nTotal Page miss = %d", miss);
return 0;
}

