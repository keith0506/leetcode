void get_num(char *a, int *real, int *imagine) {
    char * temp = a;
    *real = atoi(temp);
    while(*temp != '+')
        temp++;
    temp++;
    *imagine = atoi(temp);
}
char* complexNumberMultiply(char* a, char* b) {
    int real1 = 0;
    int imagine1 = 0;
    int real2 = 0;
    int imagine2 = 0;
    get_num(a, &real1, &imagine1);
    get_num(b, &real2, &imagine2);
    
    int res_real = real1 * real2 - imagine1 * imagine2;
    int res_imagine = real1 * imagine2 + real2 * imagine1;
    char *ret = (char *)malloc(20);
    sprintf(ret, "%d+%di", res_real, res_imagine);
    return ret;
}