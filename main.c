#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct CString
{
	char* text;
	size_t size;
} CString;

CString* cstring_new(const char* str)
{
	size_t size = strlen(str);
	CString* q = (CString*)malloc(sizeof(CString));
	char* buffer = malloc(size+1);
	strcpy(buffer, str);
	q->text = buffer;
	q->size = size;
	return q;
}

size_t cstring_length(CString* str)
{
	return str->size;
}

char cstring_get(CString* str, int pos)
{
	if(pos>=0 && pos<str->size)
		return str->text[pos];
}

const char* cstring_text(CString* str)
{
	return str->text;
}

void cstring_set(CString* str, int pos, char a)
{
	if(pos>=0 && pos<str->size)
		str->text[pos] = a;
}

void cstring_free(CString* str)
{
	if(str!=NULL)
	{
		free(str->text);
		free(str);
	}
}

int main()
{
	CString* a;
	assert(a = cstring_new("kreda"));
	const char* t1 = cstring_text(a);
	printf("%s\n", t1);
	printf("%zu\n", cstring_length(a));
	printf("%c\n", cstring_get(a, 0));
	cstring_set(a, 3, 't');
	const char* t2 = cstring_text(a);
	printf("%s\n", t2);
	cstring_free(a);
	
	return 0;
}
