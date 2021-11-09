digit [0-9]
digits {digit}*
letter [A-Za-z]
word {letter}+

%%

{word}		{printf("\n%s is a word\n",yytext);}
{digits}	{printf("\n%s is a number\n",yytext);}


%%

int yywrap(void){}//auto call when input stream return 1
 
int main()
{
	yylex();//read the input stream
	return 0;
}

//yytext----> print from input stream.
