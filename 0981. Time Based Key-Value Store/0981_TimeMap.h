#pragma once
#include <string>
#include <unordered_map>
using namespace std;

/*
��ϣ�� + ���ֲ��ҷ�
����ؼ���
1�����ݽṹ����ƣ�ͬһ��key�����ڲ�ͬʱ������ж��ֵ��Ҳ����һ��key��Ӧ���Ƕ����Ԫ��pair(timestamp, value)��ɵ����飺
    unordered_map<string, vector<pair<int, string>>>
2����Ϊʱ������ص㣬��Ԫ��pair(timestamp, value)�ǰ���timestamp�ϸ�����ģ���˿���ʹ�ö��ֲ��ҿ��ٵĶ�λ����������timestamp�����Ӧ��value��

����������
���� set �����е�ʱ��������ϸ�����ģ���˶�Ԫ���б��б����ʱ���Ҳ���ϸ�����ġ���������еġ�ʱ�������������ǰ��������
��ͱ�֤�˲���������ǰ���timestamp�����ģ����Ի���timestampʹ�ö��ֲ��ҷ���
*/
class TimeMap {
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        // push_back��Ҫһ�����ж��󣨸��ƻ��ƶ�����emplace_backʹ���ṩ�Ĳ���ֱ���������й������
        // ��ֱ����vector������ڴ��й�����󣬱�push_back����Ч����Ϊ�������˲���Ҫ�ĸ��ƻ��ƶ�������
        // ���磺push_back(std::make_pair(2, "example2"));  // ����һ����ʱ pair ���ƶ��� vector ��
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        if (store.find(key) == store.end()) // c++�Ĺ�ϣ�������ж�һ��key�Ƿ����
            return "";

        const auto& values = store[key];
        string ans;

        // ��׼�Ķ��ֲ���ģ��
        int left = 0, right = values.size() - 1; // ��vector����ĵ�һ��Ԫ�غ����һ��Ԫ�ص��±��ʼ��(left, right)��
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                // ��Ҫ��ͼһ�ξ��ҵ����յ�ans�����ǰѵ�һ�����ܵĽ⸳ֵ��ans����ʹ�á��������������Ľ��ans����ˢ�£�
                ans = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    unordered_map<string, vector<pair<int, string>>> store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */