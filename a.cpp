//�����Ȼ���һ��������ѧ����
// |x-1| + |x-2| + |x-6| + |x-13|
//��ʱ x ȡ��λ��,���Ի����Сֵ

//����-->��Ȩ��λ��
//�������յ�λ��Ϊ x �����Ϊ ��(i=1��n) wi|pi-x| 
//���� wi Ϊ������pi Ϊλ��
//ע�⵽����һ����׼�Ĵ�Ȩ��λ������
//�ڶ� pi(λ��) ����󣬴�һ���� ��(i=1��n) wi/2 ����Ӧ�� pi

//������ⷽʽ������ wi ������ wi �� |pi-x|
//�����ֻص�������ѧ�ľ�����λ������
//ȡ pi ����λ��Ϊ x ����

//ʱ�临�Ӷ� O(n log n)-->sort()
#include <bits/stdc++.h>
using namespace std;

//������ֵ+λ�����ʹ�� pair<T,T>
using Pair = pair<int, int>;
//int���ݷ�Χ�� 2*10^9
using LL = long long;     

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<Pair> a(n);
  LL sw = 0;

  // range-for-each + �ṹ���
  //��ΪҪ��λ����������λ��Ϊ first ,����Ϊ second
  for (auto &t : a)
  {
    cin >> t.second >> t.first;
    sw += t.second;  
  }

  //���������ʯͷ�� λ�� �����е�
  sort(a.begin(), a.end());

  //nw-->ȡ�±����λ��
  //sw-->�±�֮��
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

  //xΪȷ���� λ��
  LL ans = 0;
  for (const auto &t : a)
  {
    ans += (LL)t.second * abs(t.first - x);
  }

  cout << ans << '\n';
  return 0;
}