#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n) {
	int i;
	int m = n / 2;
	
	if (n % 2 == 0) {
		return 0;
	}
	
	for (i = 3; i <= m; i+=2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int gcd(int num1, int num2) {

    int resto;
    float max = num1 / 2;

    do {
        resto = num1 % num2;
		num2++;
		if(num2 > max){
			return 1;
		}
    } while (resto != 1);

    return --num2;
}

int powMod(int a, int b, int n) {
	long long x = 1, y = a;

	while (b > 0) {
		if (b % 2 == 1)
			x = (x * y) % n;
		y = (y * y) % n;
		b /= 2;
	}

	return x % n;
}

int main(int argc, char* argv[]) {
	int p, q;
	int n, phin;

	int data, cipher, decrypt;

	while (1) {
		printf("Entre com dois numeros primos: ");
		scanf("%d %d", &p, &q);

		if (!(checkPrime(p) && checkPrime(q)))
			printf("Os numeros não são primos. Por favor digite números primos\n");
		else if (!checkPrime(p))
			printf("O primeiro numero não é primo. Por favor digite números primos\n");
		else if (!checkPrime(q))
			printf("O Segundo numero não é primo. Por favor digite números primos\n");
		else
			break;
	}
	
	n = p * q;
	printf("N: %d\n", n);

	phin = (p - 1) * (q - 1);
	printf("phi(N): %d\n", phin);
	
	int e = 3;
	e = gcd(phin, e);
	
	int d = 0;
	for (d = e + 1; d <= 100; d++) {
		if ( ((d * e) % phin) == 1)
			break;
	}

	printf("Valor para E: %d\n", e);
	printf("Valor para D: %d\n", d);

	printf("Digite o numero a ser criptografado: ");
	scanf("%d", &data);

	cipher = powMod(data, e, n);
	printf("O valor criptografado: %d\n", cipher);

	decrypt = powMod(cipher, d, n);
	printf("O valor decriptado: %d\n", decrypt);
	return 0;
}
