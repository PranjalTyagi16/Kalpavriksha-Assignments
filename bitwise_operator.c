#include <stdio.h>

struct tuple{
    int and;
    int or;
    int xor;
};

struct tuple ans;
void calculate_the_maximum(int n, int k) {
  for(int i=1;i<n;i++)
  {
      for(int j=i+1;j<=n;j++)
      {
          struct tuple cur;
          cur.and=i & j;
          cur.or=i | j;
          cur.xor= i ^ j;
          if(cur.and>ans.and&&cur.and<k)
          {
             ans.and=cur.and;
          }
          if(cur.or>ans.or&&cur.or<k)
          {
              ans.or=cur.or;
          }
          if(cur.xor>ans.xor&&cur.xor<k)
          {
              ans.xor=cur.xor;
          }
      }
  }
    printf("%d\n",ans.and);
    printf("%d\n",ans.or);
    printf("%d\n",ans.xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
