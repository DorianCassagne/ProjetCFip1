int count_char(Data *tube){
    return strlen(tube->str)
}

int count_word(Data *tube){
    int count=0,i,len;
    char lastC;
    len=strlen(tube->str);
    if(len > 0)
    {
        lastC = tube->str[0];
    }
    for(i=0; i<=len; i++)
    {
        if((tube->str[i]==' ' || tube->str[i]=='\0') && lastC != ' ')
        {
            count++;
        }
        lastC = tube->str[i];
    }
    return count;
}

int operation(Date *tube){
    int result = 0 ;
    for (int i = 0; i < strlen(tube->str); i++){
        while(tube->str[i] != '-' || tube->str[i] != '+' || tube->str[i] != '*'){
            char *ptr = strtok(tube->str, tube->str[i]);
            while(ptr != NULL)
            {
                switch (tube->str[i])
                {
                    case "-":
                        result -= result;
                    case "+":
                        result += result;
                    case "*":
                        result *= result;
                    default:
                        break;
                }
                ptr = strtok(NULL, delim);
            }
            return result;
        }
    }
}