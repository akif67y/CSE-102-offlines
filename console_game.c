
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int str_len(char s[]);
int str_cmp(char a[], char b[]);
void str_cpy(char keeper[], char passer[]);
void str_lwr(char s[]);
void show_menu();
void special_score(int flag, int u);
void score(int count, int flagy);
void select_an_array(char selected[], char x[], char y[], char z[]);
void scrumble(char selected[], char scrumbled[]);
void anagram();
void decrypt(char guess[], char decrypted[], int k);
void encrypt(char selected[], char encrypted[], int k);
void caser_cipher();
int write_answer(char selected[], int count, int count2);
void check_substring(char selected[]);
void check_length(char selected[]);
void word_guess();
void start();
void exi();
void show_menu();

char a1[] = "listen";
char a2[] = "earth";
char a3[] = "binary";

char c1[] = "There is a secret code";
char c2[] = "Attack at dawn";
char c3[] = "Meet me at park";

char b1[] = "program";
char b2[] = "network";
char b3[] = "science";
int scor = 0;
int flag = 0;

int str_len(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int str_cmp(char a[], char b[])
{
    int m = str_len(a);
    int n = str_len(b);
    int lim;
    if (n != m)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return 1;
        }
        return 0;
    }
}

void str_cpy(char keeper[], char passer[])
{
    for (int i = 0; i < str_len(passer); i++)
    {
        keeper[i] = passer[i];
    }
}
void str_lwr(char s[])
{
    for (int i = 0; i < str_len(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
}

void score(int count, int flagy)
{
    scor += (3 - count) * 10;
    if (flagy == 1)
        scor += 10;
}
void special_score(int flagyy, int u)
{
    if (flagyy == 3)
        scor += 5;
    scor -= (2 * u);
}

void select_an_array(char selected[], char x[], char y[], char z[])
{

    srand(time(NULL));

    int j = rand() % 3;
    if (j == 0)
    {
        str_cpy(selected, x);
    }
    else if (j == 1)
    {
        str_cpy(selected, y);
    }
    else
    {
        str_cpy(selected, z);
    }
}

void scrumble(char selected[], char scrumbled[])
{

    srand(time(NULL));
    int n = str_len(selected);
    str_cpy(scrumbled, selected);

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1 + rand() % (n - i - 1);
        int temp = scrumbled[j];
        scrumbled[j] = scrumbled[i];
        scrumbled[i] = temp;
    }
}

void anagram()
{
    printf("\n\nStarting Anagram Challenge...\n");
    printf("Scrambled word: ");
    char selected[1000] = "";
    select_an_array(selected, a1, a2, a3);

    char scrumbled[1000] = "";
    scrumble(selected, scrumbled);

    printf("%s\n", scrumbled);

    int count = 1;
    int flag1 = 0;
    while (count <= 3)
    {

        char guess[1000] = "";
        printf("Your guess: ");
        scanf("\n%s", guess);
        if (str_cmp(guess, selected) == 0)
        {
            printf("Correct! You solved it in %d attempt(s)\n\n", count);
            flag1 = 1;
            flag++;
            break;
        }
        else if (count < 3)
        {

            printf("Incorrect! Try again.\n");
        }
        count++;
    }

    if (count == 4)
    {
        printf("You have run out of attempt(s)\n Correct answer was %s\n\n", selected);
        score(count - 1, flag1);
    }
    else
        score(count, flag1);
}

void decrypt(char guess[], char decrypted[], int k)
{
    int n = str_len(guess);
    for (int i = 0; i < n; i++)
    {

        if (guess[i] >= 'A' && guess[i] <= 'Z')
        {
            decrypted[i] = ((guess[i] - 'A' - k + 26) % 26) + 'A';
        }
        else if (guess[i] >= 'a' && guess[i] <= 'z')
        {
            decrypted[i] = ((guess[i] - 'a' - k + 26) % 26) + 'a';
        }
        else
        {
            decrypted[i] = guess[i];
        }
    }
}

void encrypt(char selected[], char encrypted[], int k)
{
    int n = str_len(selected);
    for (int i = 0; i < n; i++)
    {

        if (selected[i] >= 'A' && selected[i] <= 'Z')
        {
            encrypted[i] = ((selected[i] - 'A' + k) % 26) + 'A';
        }
        else if (selected[i] >= 'a' && selected[i] <= 'z')
        {
            encrypted[i] = ((selected[i] - 'a' + k) % 26) + 'a';
        }
        else
        {
            encrypted[i] = selected[i];
        }
    }
}

void caser_cipher()
{
    srand(time(NULL));
    int new = (rand() % 25) + 1;
    printf("Starting Caesar Cipher Challenge(Shift: %d)...\n", new);
    printf("Encypted phrase: ");

    char selected[1000] = "";
    select_an_array(selected, c1, c2, c3);
    // str_lwr(selected);
    char decrypted[1000] = "";
    char encrypted[1000] = "";

    encrypt(selected, encrypted, new);
    printf("%s\n", encrypted);

    char guess[1000] = "";
    int count = 1, flag2 = 0;
    while (count <= 3)
    {
        printf("Your guess: ");
        scanf("\n%[^\n]s", guess);
        // str_lwr(guess);
        decrypt(encrypted, decrypted, new);

        if (str_cmp(guess, decrypted) == 0)
        {
            printf("Correct!You decrypted it in %d attempt(s)\n\n", count);
            flag2 = 1;
            flag++;
            break;
        }
        else
        {
            if (count < 3)
                printf("Incorrect! Try again.\n");
        }
        count++;
    }

    if (count == 4)
    {
        printf("You have run out of attempt(s)\n Correct answer was %s\n\n", selected);
        score(count - 1, flag2);
    }
    else
        score(count, flag2);
    // substr and str_cpy function banano uchit
}
int write_answer(char selected[], int count, int count2)
{
    int flag3 = 0;

    printf("Enter your guess work: ");
    char s[1000] = "";
    scanf("\n%s", s);
    if (str_cmp(s, selected) == 0)
    {
        printf("Correct!You guessed it in %d attempt(s) using %d utility function\n\n", count2, count);
        flag3 = 1;
        score(count2, flag3);
        flag++;
        special_score(flag, count);
        return 1;
    }
    else
    {
        if (count2 < 3)
        {
            printf("incorrect, try again\n");
            return 0;
        }
        return 0;
    }
}
void check_substring(char selected[])
{
    printf("Enter substring: ");
    char guess[1000] = "";
    scanf("\n%s", guess);
    int i;
    for (i = 0; i <= str_len(selected) - str_len(guess); i++)
    {
        int j;
        for (j = 0; j < str_len(guess); j++)
        {
            if (selected[i + j] != guess[j])
            {
                break;
            }
        }
        if (j == str_len(guess))
        {
            printf("YES\n");
            break;
        }
    }
    if (i == str_len(selected) - str_len(guess) + 1)
    {
        printf("No\n");
    }
}
void check_length(char selected[])
{
    printf("Enter length: ");
    int n;
    scanf("%d", &n);
    getchar();

    if (n == str_len(selected))
    {
        printf("YES\n");
    }
    else
    {
        printf("No\n");
    }
}

void word_guess()
{
    printf("Starting Word guessing Challenge...\n");
    printf("Hint: ");

    char selected[1000] = "";
    select_an_array(selected, b1, b2, b3);

    printf("%.3s______", selected);
    printf("\nSelect an option: 1. Write Answer 2. Check Substring 3. Check Length\n");
    int u1 = 0, u2 = 0, u3 = 0;
    int count2 = 0;
    while (1)
    {
        int n;
        scanf("%d", &n);
        getchar();

        if (n == 1)
        {
            count2++;
            int t = write_answer(selected, u2 + u3, count2);

            if (t == 1)
            {
                break;
            }

            if (count2 >= 3)
            {
                printf("You are not so smart. Correct word was %s\n\n", selected);
                break;
            }
        }

        else if (n == 2)
        {
            if (u2 >= 1)
                printf("Error: Utility function already used\n");
            else
            {
                check_substring(selected);
                u2++;
            }
        }
        else if (n == 3)
        {
            if (u3 >= 1)
                printf("Error: Utility function already used\n");
            else
            {
                check_length(selected);
                u3++;
            }
        }
    }
}
void start()
{
    anagram();
    caser_cipher();
    word_guess();
    exi();
}

void exi()
{
    printf("Game Over!\n");
    printf("Your score is : %d\n", scor);
}

void show_menu()
{
    printf("Welcome to the Game world!\n");
    printf("1.Start Game\n2.Exit\nEnter your choice: ");
    int n;
    scanf("%d", &n);
    if (n == 2)
        exi();
    else if (n == 1)
        start();
}

int main()
{
    show_menu();
}
