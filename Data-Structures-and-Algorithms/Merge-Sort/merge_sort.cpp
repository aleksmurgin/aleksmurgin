#include<iostream>
#include<algorithm>
#include<vector>

void merge_arrays(std::vector<size_t>& arr, size_t left, size_t mid, size_t right){
    size_t size1 = mid - left + 1;
    size_t size2 = right - mid;

    std::vector<size_t> temp1,temp2;
    temp1.reserve(size1);
    temp2.reserve(size2);

    for(size_t i = 0; i < size1; ++i){
        temp1.push_back(arr[left + i]);
    }

    for(size_t i = 0; i < size2; ++i){
        temp2.push_back(arr[mid + 1 + i]);
    }

    size_t i = 0,j = 0 ,k = left;

    while(i < size1 && j < size2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
            k++;
        }else{
            arr[k] = temp2[j];
            j++;
            k++;
        }
    }
    while(i < size1){
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while(j < size2){
        arr[k] = temp2[j];
        j++;
        k++;
    }
}
void merge_sort(size_t left, size_t right, std::vector<size_t>& arr){
    if(left >= right){
        return;
    }
    size_t mid=left + (right - left) / 2;
    merge_sort(left, mid, arr);
    merge_sort(mid+1, right, arr);
    merge_arrays(arr, left, mid, right);
}
void sortArray(std::vector<size_t>& arr){
        if(arr.size() == 0){
            return;
        }
        merge_sort(0, arr.size()-1, arr);
}
int main(){
    std::vector<size_t> arr  ={5, 2, 3, 1};
    sortArray(arr);
    for(size_t i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    return 0;
}

