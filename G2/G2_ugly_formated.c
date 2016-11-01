#include < stdio.h > 
#include < conio.h >
int main() { float c, r; printf("C:"); scanf_s("%f", &c);
printf("r:"); scanf_s("%f", &r); int y = 0; do { c = c + c*(r / 100.0f);
y = y + 1; printf("\ny=%d: c=%.1f", y, c); } while (y<10); printf("\nGood bye!\n");
printf("Press any key to exit this program."); _getch(); }
