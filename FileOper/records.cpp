// �����й̶����ȼ�¼���ļ�

/*
����fread��fwrite�ʺϴ����й̶����ȼ�¼���ļ���
�ڴ�ģʽ�����еġ�+����ʾ����ģʽ������ζ�������ļ�������������Ȼ��������ͨ������fflush����һЩ�ļ���λ������fseek��rewind�����ָ�������������������
����fseek�Ѷ�/д��궨λ�ڴ��ļ���ͷ��ʼ���ĸ����������ֽ���(SEEK_SET)������ļ���β��ʼ���ĸ����������ֽ���(SEEK_END),��ӵ�ǰλ�ÿ�ʼ���ĸ����������ֽ���(SEEK_CUR).
����rewind�ȼ���fseek(f, 0L, SEEK_SET)��
���ݸ�fseek�������ֽڶ�λֻ���ڶ�����ģʽ�²������壬��Ϊ���ı�ģʽ�¿��ܴ���δ֪��Ƕ��ʽ�ַ���
����ftell������һ���ļ��й��ĵ�ǰλ�ã����ֵ���Ա����ݸ�fseek�Է��ص��Ǹ�λ�á�(����fseek��ftell��ͬ��Ӧ��Ҳ�������ı�ģʽ��ʹ��)��
����fseek��ftellΪ���ļ���λ������һ�������Ͳ��������Ǳ��Լ�����ȷ�����ļ��Ĵ�С�����ơ����ϵͳ֧�ָ�����ļ���λֵ������ͨ���⺯��fgetpos��fsetpos����ر�����Щ�ļ���
������fpos_t���͵�ֵ���н��ף�fpos_t���Ϳ���������ֵҲ���ܲ��ǡ�
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXRECS	10

struct record
{
	char last[16];
	char first[11];
	int age;
};

static char* get_field(char *, char *);

int main6()
{
	int nrecs;
	char s[81];
	struct record recs[MAXRECS], recbuf;
	FILE* f;

	// С�ĵر����¼
	for (nrecs = 0; nrecs < MAXRECS && get_field("Last", s); ++nrecs)
	{
		strncpy(recs[nrecs].last, s, 15)[15] = '\0';
		get_field("First", s);
		strncpy(recs[nrecs].first, s, 10)[10] = '\0';
		get_field("Age", s);
		recs[nrecs].age = atoi(s);
	}

	// ����¼д���ļ�
	if ((f = fopen("recs.dat", "w+b")) == NULL)
	{
		return EXIT_FAILURE;
	}
	if (fwrite(recs, sizeof(recs[0]), nrecs, f) != nrecs)
	{
		return EXIT_FAILURE;
	}

	// ��λ�����һ����¼
	fseek(f, (nrecs - 1) * sizeof(struct record), SEEK_SET);
	fread(&recbuf, 1, sizeof(struct record), f);
	printf("last: %s, first: %s, age: %d\n", recbuf.last, recbuf.first, recbuf.age);

	// ��λ�ڵ�һ����¼
	rewind(f);
	fread(&recbuf, 1, sizeof(struct record), f);
	printf("last: %s, first: %s, age: %d\n", recbuf.last, recbuf.first, recbuf.age);

	return EXIT_SUCCESS;
}

static char* get_field(char* prompt, char* buf)
{
	// Ϊ��������ʾ
	fprintf(stderr, "%s: ", prompt);
	return gets(buf);
}