#include<iostream>
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

char username[20];
char password[20];

bool valid_login()
{
	char Data[1000];
	char* Token;
	cin >> Data;

	if (Data != NULL)
	{
		Token = strtok(Data, "&");
		sscanf(Token, "username=%s", username);

		Token = strtok(NULL, "&");
		sscanf(Token, "password=%s", password);
	}
	else
	{
		printf("<p> connection faild! </p>");
	}



	FILE* f = fopen("C:\\temp\\test.txt", "r");
	char buffer[100] = " ";
	char line[100] = "";
	
if (f == NULL)
	{
		cout << "Fehler beim einlesen der Datei";
		return NULL;
	}

	strcat(line, username);
	strcat(line, " ");
	strcat(line, password);

	while (fgets(buffer, sizeof(buffer), f) != NULL)
	{
		Token = strtok(buffer, "\n");
		if (strstr(Token, line) == NULL)
			continue;
		else
		{
			fclose(f);
			return true;
		}
	}
}

/*-------------------------------------------------------------------------*/

int main()
{
	cout << "Content-Type: text/html\r\n\r\n";

	if (valid_login())
	{
		
		system("C:\\temp\\Apache\\htdocs\\pages\\menue.html");
	}
	else
	{
		printf("<html>");
		printf("<head>");
		printf("<META HTTP-EQUIV ='content-type' CONTENT ='text/html; charset =utf-8'>");
		printf("<link rel='stylesheet' type='text/css' href='http://localhost/style.css'>");
		printf("<link href='https://fonts.googleapis.com/css?family=IBM+Plex+Mono:400,700' rel='stylesheet'>");
		printf("<META HTTP-EQUIV ='content-type' CONTENT ='text/html; charset =utf-8'>");
		printf("<title>ungültige Daten</title>");
		printf("</head>");
		printf("<body align='center'>");
		printf("<center>");
		printf("<h1>");
		printf("<font color='red' size='16'>FEHLER</font><br></br>");
		printf("<font size='12'>");
		printf("<a style='color: #cc0000' href = 'http://localhost/pages/login.html'>versuchen Sie noch mal</a>");
		printf("</font>");
		printf("</h1>");
		printf("</center>");
		printf("</ul>");
		printf("</nav>");
		printf("</body>");
		printf("</html>");
		return 0;
	}
	return 0;
}





