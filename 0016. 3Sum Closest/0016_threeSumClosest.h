#pragma once
#include <vector>
using namespace std;

/*
16. ��ӽ�������֮��
����һ������Ϊ n ���������� nums �� һ��Ŀ��ֵ target������� nums ��ѡ������������ʹ���ǵĺ��� target ��ӽ���
�������������ĺ͡�
�ٶ�ÿ������ֻ����ǡ��һ���⡣

˼·������������ + ��ָ�룩
��������ѡ��3��Ԫ�أ�˼·��һ��������������ָ��ɨ�衣
ʹ��ָ�� i ���������ɨ�裻��ɨ��Ĺ����У��� i �Ҳ�����䣬ʹ�� left/right ָ����мбƣ�Ѱ�Ҹ����������Ľ⡣

�Ż��㣺����ָ�붼Ҫȥ�ء�
*/
class Solution_0016 {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int ans, sum;
        sort(nums.begin(), nums.end()); // ��������Ż�
        size_t n = nums.size();
        int offset = INT_MAX, new_offset;
        for (size_t i = 0; i <= n - 3; ++i) { // i��ൽn-3����ΪҪ��2��λ�ø�left/right��
            // �Ż���i ָ��ȥ��
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // �Ż���i ���ڵ���С���������ĺͣ��������target����ô������ϣ��Լ� i ֮�����ϣ��������
            sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (sum > target) {
                new_offset = sum - target;
                if (new_offset < offset) {
                    // ����forѭ�������Դ˴�����ˢ��offset��
                    ans = sum;
                }
                break; // i �� i ֮������ֻ�������target��Զ��
            }
            // �Ż���i ���ڵ���������֮�ͣ�����targetС���������ֻ���С��
            sum = nums[i] + nums[n - 2] + nums[n - 1];
            if (sum < target) {
                new_offset = target - sum;
                if (new_offset < offset) {
                    offset = new_offset;
                    ans = sum;
                }
                continue; // i ���ڵ��������ֻ���С����target��Զ��
            }
            // i���Ҳ�����ʹ��2��ָ����мб�
            // leftֻ�����ң�rightֻ������
            size_t left = i + 1, right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    new_offset = sum - target;
                    if (new_offset < offset) {
                        offset = new_offset;
                        ans = sum;
                    }
                    // sum̫����Ҫ��Сһ�㣻rightָ�����Ʋ�ȥ��
                    for (--right; left < right && nums[right] == nums[right + 1]; --right)
                        ;
                } else if (sum < target) {
                    new_offset = target - sum;
                    if (new_offset < offset) {
                        offset = new_offset;
                        ans = sum;
                    }
                    // sum̫С����Ҫ���һ�㣻leftָ�����Ʋ�ȥ��
                    for (++left; left < right && nums[left] == nums[left - 1]; ++left)
                        ;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};