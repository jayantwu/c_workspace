int numJewelsInStones(char * J, char * S){
    char hash[58] = {0};  // 'z' - 'A' + 1

    for (int i = 0; i < 50; i++) {
        if (J[i] == '\0')
            break;
        hash[J[i] - 'A'] = J[i];   //A-Za-z
    }
    int ret = 0;
    for (int i = 0; i < 50; i++) {
        if (S[i] == '\0') {
            break;
        }
        if (hash[S[i] - 'A'] == S[i]) {
            ret++;
        }
    }

    return ret;
	
//将j[]中的字符散列开，形成一个散列表，遍历s[],hash算法就是 key-基地址（‘A’）