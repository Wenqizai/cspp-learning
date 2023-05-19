#include <stdio.h>
#include <string.h>

/*
	copy integer into buffer if space is available
	buggy method:
	sizeof ��������ص��� size_t ���͵�ֵ������һ���޷����������͡�
	�� maxbytes ��ֵ��С��С�� sizeof(val) ʱ��maxbytes - sizeof(val) �Ľ���ᱻǿ��ת��Ϊ�޷������������½����ȻΪ������
*/
void buggy_copy_int(int val, void* buf, int maxbytes) {
	if (maxbytes - sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
}

/*
	right method: �Ƚϴ�С, ������������
*/
void copy_int(int val, void* buf, int maxbytes) {
	if (maxbytes >= sizeof(val))
		memcpy(buf, (void *) &val, sizeof(val));
}