///把程式碼全刪
#include <windows.h>
#include <stdio.h>
int main()
{
        PlaySound("C:/Do.wav",NULL,SND_SYNC);
        PlaySound("C:/mykbeat.wav",NULL,SND_ASYNC);///不等待
        printf("請輸入一個整數: ");
        int n;
        scanf("%d",&n);///卡住
}
