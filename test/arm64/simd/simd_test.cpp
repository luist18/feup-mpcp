#ifndef SIMD_TEST_H_
#define SIMD_TEST_H_

#include "../../../src/test/asserts.h"

extern "C" void sumv(float *P, float *Q, float *R, int n);

extern "C" void altv(float *P, int n, float k);

extern "C" long int prodintv(int *R, int *S, int n);

using namespace asserts;

class simd_test {
public:
	static void example() {
		float PFSIMDFEX1A[] = { 3.4, 5.3, -1.0, -2.1, 3.4, 5.3, -1.0, -2.1, 3.4,
				5.3, -1.0, -2.1, 3.4, 5.3, -1.0, -2.1 };
		float QFSIMDFEX1A[] = { 1.4, 1.3, 1.0, 1.1, 1.4, 1.3, 1.0, 1.1, 1.4,
				1.3, 1.0, 1.1, 1.4, 1.3, 1.0, 40.0 };
		float RFSIMDFEX1A[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
				0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
		int NFSIMDFEX1A = 16;
		sumv(PFSIMDFEX1A, QFSIMDFEX1A, RFSIMDFEX1A, NFSIMDFEX1A);
		for (int i = 0; i < 16; i++) {
			printf("R[%d]= %f\n", i, RFSIMDFEX1A[i]);
		}
	}

	static void simd1b() {
		printf("EX1 B)\n");
		float PFSIMDFEX1B[] = { 3.4, 5.3, -1.0, -2.1, 3.4, 5.3, -1.0, -2.1, 3.4,
				5.3, -1.0, -2.1, 3.4, 5.3, -1.0, -2.1 };
		int NFSIMDFEX1B = 16;
		float KFSIMDFEX1B = 2.0;
		altv(PFSIMDFEX1B, NFSIMDFEX1B, KFSIMDFEX1B);
		for (int i = 0; i < 16; i++) {
			printf("R[%d]= %f\n", i, PFSIMDFEX1B[i]);
		}
	}

	static void simd2() {
		int RFSIMDFEX2[] = { 3, 5, 1, 1, 3, 5, 1, 1, 3, 5, 1, 1, 3, 5, 1, 1 };
		int SFSIMDFEX2[] = { 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1 };
		int NFSIMDFEX2 = 16;
		long int pro = 0;
		pro = prodintv(RFSIMDFEX2, SFSIMDFEX2, NFSIMDFEX2);
		printf("Produto interno = %ld\n", pro);
	}

	static void simd3() {
		printf("EX3\n");
		char VFSIMDFEX3[] = "frasedeteste21sd";
		long int NFSIMDFEX3 = 16;
		char VALFSIMDFEX3 = 'd';
		long int RESFSIMDFEX3 = 0;
		//RESFSIMDFEX3 = conta_ocorrVFSIMDFEX3(VFSIMDFEX3, NFSIMDFEX3,VALFSIMDFEX3);
		//printf("Elementos encontrados = %d\n", RESFSIMDFEX3);
	}
};

#endif
