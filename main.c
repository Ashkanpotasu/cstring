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
	CString* o = malloc(sizeof(CString));
	char* buffer = malloc(size+1);
	strcpy(buffer, str);
	o->text = buffer;
	o->size = size;
	return o;
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

int main()
{
	CString* c;
	assert(c = cstring_new("kreda"));
	char* a = cstring_text(c);
	printf("%s\n", a);
	printf("%zu\n", cstring_length(c));
	printf("%c\n", cstring_get(c, 0));
	cstring_set(c, 3, 't');
	char* b = cstring_text(c);
	printf("%s\n", b);
	
	return 0;
}
