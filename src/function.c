//Andrew x and Tyler Evans
//here is a file with a uppercase functiona and an integration function that puts things together

char upper_case(char c){
    while(c = getchar()) {
        //sees if the value is less then z or a and puts it so that there is
        if (c <= 'z' && c >= 'a') return putchar(c - 32);
        else if (c >= 'A' && c <= 'Z') return putchar(c + 32);
        else return putchar(c);
    }
}
