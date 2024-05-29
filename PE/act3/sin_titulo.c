/* Este codigo ha sido generado por el modulo psexport 20230904-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>

/* Para las variables que no se pudo determinar el tipo se utiliza la constante
   SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
   (usualmente int,float,bool, o char[]). */
#define SIN_TIPO float

int main() {
	SIN_TIPO num1;
	SIN_TIPO num2;
	SIN_TIPO num3;
	scanf("%f", num1);
	scanf("%f", num2);
	scanf("%f", num3);
	if (num1<=num2 && num1<=num3) {
		if (num2<=num3) {
			printf("%f%f%f\n", num1, num2, num3);
		} else {
			printf("%f%f%f\n", num1, num3, num2);
		}
	} else {
		if (num2<=num1 && num2<=num3) {
			if (num1<=num3) {
				printf("%f%f%f\n", num2, num1, num3);
			} else {
				printf("%f%f%f\n", num2, num3, num1);
			}
		} else {
			if (num1<=num2) {
				printf("%f%f%f\n", num3, num1, num2);
			} else {
				printf("%f%f%f\n", num3, num2, num1);
			}
		}
	}
	return 0;
}

