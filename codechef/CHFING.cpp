#include <iostream>
#include <stack>
#include <vector>
using namespace std; 
struct DataFrame {
  int sum;
  std::vector<int> coins;
  std::vector<int> avail_coins;
};
 
int main() {
int cnt=0;
for(int i=1; i<=500; i++)
{
	  std::stack<DataFrame> s;
	  s.push({ i, {}, {  31, 32, 33 } });
	  int ways = 0;
	  while (!s.empty()) {
	    DataFrame top = s.top();
	    s.pop();
	    if (top.sum < 0) continue;
	    if (top.sum == 0) {
	      ++ways;
	      continue;
	    }
	    if (top.avail_coins.empty()) continue;
	    DataFrame d = top;
	    d.sum -= top.avail_coins[0];
	    d.coins.push_back(top.avail_coins[0]);
	    s.push(d);
	    d = top;
	    d.avail_coins.erase(std::begin(d.avail_coins));
	    s.push(d);
	  }
	  if(ways==0)
	  {
	  	cout<<i<<endl;
	  	cnt++;
	  }
	  //std::cout << ways << std::endl;
}
cout<<"hey: "<<cnt<<endl;
	  return 0;
}