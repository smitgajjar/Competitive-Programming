/* Author: Smit Gajjar
   © 2018
*/
#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base :: sync_with_stdio(0);cin.tie(0);

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if((x2-x1)==0||(y2-y1)==0)
        {
            if((x2-x1)==0)
            {
                if(y2-y1>0)
                    printf("up\n");
                else
                    printf("down\n");
            }
            else if((y2-y1)==0)
            {
                if(x2-x1>0)
                    printf("right\n");
                else
                    printf("left\n");
            }
        }
        else
            printf("sad\n");
    }
}
