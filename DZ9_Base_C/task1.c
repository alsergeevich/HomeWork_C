//F1-Сортировка по возрастанию


void sort_array(int size, int a[]){
    int flag;
    int temp = 0;
    for(int k = 0; k < size; ++k) {
        flag = 0;
        for(int i = 0; i < size-1; ++i) {
            if(a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                flag = 1;
            }
            
        }
        if(flag == 0) {
            return;
        }
    }
}