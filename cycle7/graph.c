#include<stdio.h>
int a[100][100],n;

void main(){
    printf("enter number of vertices\n");
    scanf("%d",&n);

    printf("Enter 1 if there is an edge present")

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter 1 if there is an edge present in %d and %d else 0",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }

    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d",a[i][j]);
        }
        
    }
    while(ch!=4){
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            BFS();
            break;
        case 2:
            DFS(n);
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }     

}

void DFS(int n){
    


}