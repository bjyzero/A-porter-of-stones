//我们先回忆一个初中数学问题
// |x-1| + |x-2| + |x-6| + |x-13|
//此时 x 取中位数,可以获得最小值

//进阶-->带权中位数
//假设最终的位置为 x ，则答案为 ∑(i=1，n) wi|pi-x| 
//其中 wi 为重量，pi 为位置
//注意到这是一个标准的带权中位数问题
//在对 pi(位置) 排序后，答案一定在 ∑(i=1，n) wi/2 处对应的 pi

//换种理解方式，即把 wi 看成有 wi 个 |pi-x|
//这样又回到初中数学的经典中位数问题
//取 pi 的中位数为 x 即可

//时间复杂度 O(n log n)-->sort()
#include <bits/stdc++.h>
using namespace std;

//出现数值+位置组合使用 pair<T,T>
using Pair = pair<int, int>;
//int数据范围是 2*10^9
using LL = long long;     

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<Pair> a(n);
  LL sw = 0;

  // range-for-each + 结构体绑定
  //因为要对位置排序，所以位置为 first ,重量为 second
  for (auto &t : a)
  {
    cin >> t.second >> t.first;
    sw += t.second;  
  }

  //这个排序按照石头的 位置 来排列的
  sort(a.begin(), a.end());

  //nw-->取下标的中位数
  //sw-->下标之和
  // nw < sw / 2 <= nw + a.second
  LL nw = 0;
  int x = 0;
  for (const auto &t : a)
  {
    if (nw * 2 < sw && sw <= 2 * (nw + t.second))
    {
      x = t.first;
      break;
    }
    nw += t.second;
  }

  //x为确定的 位置
  LL ans = 0;
  for (const auto &t : a)
  {
    ans += (LL)t.second * abs(t.first - x);
  }

  cout << ans << '\n';
  return 0;
}