#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	cout << "Content-Type: text/html\r\n\r\n";

	FILE* f = fopen("C:\\temp\\Termine.txt", "a+");
	char buffer[250] = "";
	char line[250] = "";

	char* Tocken;

	if (f == NULL)
	{
		cout << "Termine können nicht angezeigt werden";
		return 0;
	}

	printf("<!DOCTYPE html>");
	printf("<html lang = 'de'>");
	printf("<head>");
	printf("<link rel='stylesheet' type='text/css' href='http://localhost/style.css'>");
	printf("<link href='https://fonts.googleapis.com/css?family=IBM+Plex+Mono:400,700' rel='stylesheet'>");
	printf("<META HTTP-EQUIV ='content-type' CONTENT ='text/html; charset =utf-8'>");
	printf("<title> Termine list </title>");
	printf("</head>");
	printf("<body>");
	printf("<nav class ='navigation terakutta'>");
	printf("<ul class ='nav-ul'>");
	printf("<ul class ='nav-ul'>");
	printf("<li class='nav-ul-li'><a href = 'http://localhost/pages/login.html'>Login</a></li>");
	printf("<li class ='nav- ul-li'><a href = 'http://localhos/pages/menue.html'>Menue</a></li>");
	printf("<li class ='nav-ul-li'><a href = 'http://localhost/pages/termin-add.html'>Neuer Termin</a></li>");
	printf("<li class ='nav-ul-li'><a href = 'http://localhost/pages/termin-edit.html'>Termin Bearbeiten</a></li>");
	printf("</ul>");
	printf("</nav>");
	printf("<h1 class = 'title' align='center'>Terminverwaltung - Termin List </h1>");
	printf("<section class = main'>");
	printf("<div class ='container-termin-liste' id = 'main'>");
	printf("<table border='3' align='center' class='tg'>");
	printf("<tr>");
	printf("<th class='tg-29iv' width='90px'> Datum </th>");
	printf("<th class='tg-29iv'> Art </th>");
	printf("<th class='bearbeiten tg-29iv' width='370px'> Bearbeiten </th>");
	printf("</tr>");
	printf("<form name='login-form' class='login100-form validate-form' METHOD='POST'>");
	while (fgets(buffer, sizeof(buffer), f) != NULL)
	{
		strcpy(line, buffer);
		cout << endl;
		printf("<tr>");

		Tocken = strtok(line, "|");
		printf("<td class='tg-fr00'> %s ", Tocken);

		Tocken = strtok(NULL, "|");
		printf(" %s </td>", Tocken);

		Tocken = strtok(NULL, "|");

		printf("<td class='tg-fr00'>   %s </td>", Tocken);
		printf("<td class='list-edit'>");

		/*printf("<a href='#'><img src='../assets/edit_icon.svg'></a>");
		printf("<a href='#'><img src='../assets/delete_icon.svg'></a>");*/

		printf("<button title='bearbeiten' name='SUBMIT' formaction='file:///C:/temp/Apache/htdocs/pages/termin-aendern.html' style='height:25px; width:180px' type='submit' value='submit'>bearbeiten</button>");
		printf("<button title='entfernen' name='SUBMIT2' formaction='' style='height:25px; width:180px' type='submit' value='submit'>entfernen</button>");
		printf("</td>");
		printf("</tr>");
	}
	printf("</form>");
	printf("</table>");
	printf("</div>");
	printf("</section");
	printf("</body>");
	printf("</html>");
	return 0;
}
