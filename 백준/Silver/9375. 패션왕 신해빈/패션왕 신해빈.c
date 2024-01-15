#include <stdio.h>
#include <string.h>

int main() {
    int tc_num;
    scanf("%d", &tc_num);
    
    for(int i = 0; i < tc_num; i++){
        int days = 1, cloth_kind_num = 0, cloth_num, cloth_kinds_num_list[31];
        char cloth_kinds_list[31][21], cloth[21], cloth_kind[21];
        scanf("\n%d", &cloth_num);
        
        for(int j = 0; j < cloth_num; j++){
            scanf("\n%s %s", cloth, cloth_kind);
            int k;
            for(k = 0; k < cloth_kind_num; k++){
                if(strcmp(cloth_kinds_list[k], cloth_kind) == 0){
                    cloth_kinds_num_list[k]++;
                    break;
                }
            }

            if(k == cloth_kind_num){
                strcpy(cloth_kinds_list[cloth_kind_num], cloth_kind);
                cloth_kinds_num_list[cloth_kind_num++] = 1;
            }
        }
        
       
        for(int l = 0; l < cloth_kind_num; l++)
            days *= (cloth_kinds_num_list[l] + 1);

        printf("%d\n", days - 1);
    }
    return 0;
}