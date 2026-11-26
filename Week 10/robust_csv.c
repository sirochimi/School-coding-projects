/* Week 10 Activity 4: read name and three scores, skipping malformed records. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
static int parse_score(const char *s, int *out) {
    char *end; long value; errno = 0;
    value = strtol(s, &end, 10);
    if (end == s || errno == ERANGE || value < INT_MIN || value > INT_MAX) return 0;
    while (isspace((unsigned char)*end)) ++end;
    if (*end) return 0;
    *out = (int)value; return 1;
}
int main(void) {
    FILE *file = fopen("students.csv", "r");
    if (!file) { perror("students.csv"); return 1; }
    char line[1024]; puts("--- Processing Student Records ---");
    while (fgets(line, sizeof line, file)) {
        if (!strchr(line, '\n') && !feof(file)) {
            int ch; while ((ch = fgetc(file)) != '\n' && ch != EOF) {}
            puts("WARNING: Skipping overlong record."); continue;
        }
        line[strcspn(line,"\r\n")] = '\0'; if (!*line) continue;
        char *fields[4], *p = line; int ok = 1;
        for (int i=0; i<4; ++i) {
            fields[i] = p; char *comma = strchr(p, ',');
            if (i<3) { if (!comma) { ok=0; break; } *comma='\0'; p=comma+1; }
            else if (comma) ok=0;
        }
        int a,b,c;
        if (!ok || !*fields[0] || !parse_score(fields[1],&a) || !parse_score(fields[2],&b) || !parse_score(fields[3],&c)) {
            puts("WARNING: Skipping malformed record."); continue;
        }
        printf("%s -> Average: %.2f\n", fields[0], ((double)a+b+c)/3.0);
    }
    if (ferror(file)) { perror("Read error"); fclose(file); return 1; }
    fclose(file); puts("\n--- Processing Complete ---"); return 0;
}
