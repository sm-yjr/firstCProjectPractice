#include <stdio.h>
#include <ctype.h>

#define MAX 5
#define HXF(i) printf("%5d",i)
void swap(int v[], int i, int j);

void qsort(int v[], int left, int right);

int htoi(char []);

int main() {
    int a[MAX]= {4,5,4,2,1};
    qsort(a,0,4);
    for(int i=0;i<5;i++)
        HXF(a[i]);
    printf("%5d\n",*(a+2));
    return 0;
}

int htoi(char s[]) {
    int p = 0;//pointer to 0
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        p = 2;
    //main part7u777uuu
    int n = 0;
    for (int i = p; s[i] != '\0'; i++) {
        if (isdigit(s[i]))
            n = n * 16 + (s[i] - '0');
        if (s[i] >= 'A' && s[i] <= 'F')
            s[i] += 'a' - 'A';
        if (s[i] >= 'a' && s[i] <= 'f')
            n = n * 16 + (s[i] - 'a' + 10);
    }
    return n;
}


void swap(int v[], int i, int j) {
    if(i!=j) v[i]^=v[j]^=v[i]^=v[j];// two arguments should not be the same one (no i^=i^=i^=i)
//    int temp = v[i];
//    v[i]=v[j];
//    v[j]=temp;

}

void qsort(int v[], int left, int right) {
    int i, last, mid = (left + right) / 2;
    if (left >= right) return;
    swap(v, left, mid);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);

}
