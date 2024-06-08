#include <iostream>
#include <string>

using namespace std;

int main(){
	/*const char *s2="Mondo!";
	char s1[]="Ciao ";
	int s1Len=strlen(s1), s2Len=strlen(s2);

	cout<<s1<<endl;
	cout<<s2<<endl;

	/*for (int i = 0; i <= s2Len; i++) //non funziona con cmd
		s1[s1Len+i]=s2[i];*/
	/*strcat(s1,s2);

	cout<<s1<<endl;*/
	//string s1("Hello"), s2("World!");
	/*s1+=" "+s2;

	cout<<s1<<endl;*/

	/* sizeof di string */
	string *str;
	cout<<"Il size e': "<<sizeof(str)<<endl;

	return 0;
}
