#include <stdio.h>
#include <limits.h>

/*
    floatתΪint:
    1. ��float�Ĵ洢������
    2. �������λsign, ָ��λE, С��λM
    3. С��λM����������1, �� M = 0110, ��������1֮��, M = 10110
    4. �ж�ָ��λ��ֵ�Ƿ�Ϊ 0 / 1, �����жϷǹ��ֵ+0/-0, �����, NaN�����
    5. С��M�ƶ���Ӧλ��k�õ�ת�����int��ֵ (23Ϊ�洢С��λ��λ��, 64Ϊ��Ӧ��Ϊ52)
        5.1 actualE >= 0 ,����, k = (23 - (E - 127), result = M >> k
        5.2 actualE < 0 , ����, k = (-(E - 127), result = M << k
*/
int floatToInt(float f) {
    // �������� f ��λ��ʾת��Ϊ�޷�������
    unsigned int u = *((unsigned int*)&f);

    // ��ȡ����λ
    int sign = (u >> 31) & 0x1;

    // ��ȡָ��λ
    int exponent = (u >> 23) & 0xFF;

    // ��ȡβ��λ
    int mantissa = u & 0x7FFFFF;

    // ������������ IEEE 754 ��׼���з�������
    if (exponent == 0xFF) {
        // ���������NaN������һ�����֣��������
        return 0;  // ����0�����������ʵ�ֵ�������������
    }
    else if (exponent == 0) {
        // ����������ǹ淶��������
        return 0;  // ����0�����������ʵ�ֵ�������������
    }
    else {
        // �淶����
        // ��β��λ����������1���γ� 1.x ����ʽ
        mantissa = mantissa | 0x800000;

        // ���㸡������ָ��ƫ������127���Ի��ʵ��ָ��
        int actualExponent = exponent - 127;

        // �ж�ʵ��ָ����������������ָ����С��β�����ƻ�����
        if (actualExponent >= 0) {
            // ʵ��ָ�����ڵ���0����Ҫ����β��λ
            mantissa = mantissa >> (23 - actualExponent);
        }
        else {
            // ʵ��ָ��С��0����Ҫ����β��λ
            mantissa = mantissa << (-actualExponent);
        }

        // �жϸ������ķ��ţ����������յ�����ֵ
        if (sign == 1) {
            // ����
            return -mantissa;
        }
        else {
            // �Ǹ���
            return mantissa;
        }
    }


}

int main() {
    // ��������1������
    float f1 = 3.14f;
    int result1 = floatToInt(f1);
    printf("Result 1: %d\n", result1);

    // ��������2������
    float f2 = -2.718f;
    int result2 = floatToInt(f2);
    printf("Result 2: %d\n", result2);

    // ��������3���ǹ淶��������
    float f3 = 0.0f;
    int result3 = floatToInt(f3);
    printf("Result 3: %d\n", result3);

    // ��������4��NaN������һ�����֣��������
    float f4 =  0xff800000;  // �����
    int result4 = floatToInt(f4);
    printf("Result 4: %d\n", result4);

    return 0;
}