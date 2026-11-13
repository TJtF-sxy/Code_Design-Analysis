#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int firstOccurrence(const vector<int>& arr, int target, int low, int high, int ans = -1)
{
    if(low > high) return ans;

    int mid = low + (high - low) / 2;
    if(arr[mid] == target)
    {
        ans = mid;
        return firstOccurrence(arr, target, low, mid - 1, ans);
    }
    else if(arr[mid] < target)
    {
        return firstOccurrence(arr,target, mid + 1, high, ans);
    }
    else
    {
        return firstOccurrence(arr, target, low, mid - 1, ans);
    }
}

int LastOccurrence(const vector<int>& arr, int target, int low, int high, int ans = -1)
{
    if(low > high) return ans;

    int mid = low + (high - low) / 2;
    if(arr[mid] == target)
    {
        ans = mid;
        return LastOccurrence(arr, target, mid + 1, high, ans);
    }
    else if(arr[mid] < target)
    {
        return LastOccurrence(arr,target, mid + 1, high, ans);
    }
    else
    {
        return LastOccurrence(arr, target, low, mid - 1, ans);
    }
}

int main()
{
    cout << "请输入有序正整数数组（空格分隔）：";
    string line;
    getline(cin, line);

    vector<int> arr;
    istringstream iss(line);
    int x;
    while (iss >> x) arr.push_back(x);

    int target;
    cout << "请输入目标值：";
    cin >> target;

    cout << "查找第一次出现请输入1，查找最后一次出现请输入2：";
    int choice;
    cin >> choice;

    int index;
    string label;
    if (choice == 1) {
        index = firstOccurrence(arr, target, 0, (int)arr.size() - 1);
        label = "第一次";
    } else {
        index = LastOccurrence(arr, target, 0, (int)arr.size() - 1);
        label = "最后一次";
    }

    if (index == -1) {
        cout << "-1" << endl;
    } else {
        cout << "目标数" << label << "出现的索引号为：" << index << endl;
    }

    return 0;
}