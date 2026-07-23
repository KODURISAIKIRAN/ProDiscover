#include<stdio.h>
#include<string.h>

int main() {
    char data[10000], file[100], rule[100];
    int found = 0;
    size_t bytesRead;

    printf("Enter the File Name: ");
    scanf("%s", file);

    FILE *fp = fopen(file, "r");
    FILE *rp = fopen("rule.txt", "r");

    if (!fp || !rp) {
        printf("File Not Found");
        return -1;
    }

    bytesRead = fread(data, 1, sizeof(data) - 1, fp);
    data[bytesRead] = '\0';

    while (fgets(rule, sizeof(rule), rp)) {
        rule[strcspn(rule, "\n")] = '\0';

        if (strstr(data, rule)) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Malware Detected. Data is Corrupted!!");
    } else {
        printf("No Malware Detected.");
    }

    fclose(fp);
    fclose(rp);

    return 0;
}
