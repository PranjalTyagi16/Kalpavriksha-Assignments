#include <stdio.h>

struct tuple{
    int and;
    int or;
    int xor;
};

struct tuple array[1001];
void calculate_the_maximum(int n, int k) {
  for(int i=1;i<n;i++)
  {
      for(int j=i+1;j<=n;j++)
      {
          struct tuple cur;
          cur.and=i & j;
          cur.or=i | j;
          cur.xor= i ^ j;
          if(cur.and>array[0].and&&cur.and<k)
          {
             array[0].and=cur.and;
          }
          if(cur.or>array[0].or&&cur.or<k)
          {
              array[0].or=cur.or;
          }
          if(cur.xor>array[0].xor&&cur.xor<k)
          {
              array[0].xor=cur.xor;
          }
      }
  }
    printf("%d\n",array[0].and);
    printf("%d\n",array[0].or);
    printf("%d\n",array[0].xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
