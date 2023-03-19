//Copyright 2023 Andress-s

int binserach(int* arr, int len, int value) {
    int low = 0;
    int high = len - 1;
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid - 1;
            while (i >= low && arr[i] == value) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i <= high && arr[i] == value) {
                count++;
                i++;
            }
            return count;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else { 
            high = mid - 1;
        }
    }
    return count;
}
int Edge(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (value < arr[i]) {
            return i;
            break;
        }
    }
    return 0;
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (value == arr[i] + arr[j]) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    len = Edge(arr, len, value);
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum_arr = arr[i] + arr[j];
            if (value == sum_arr) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int num = value - arr[i];
        count += binserach(arr + 1 + i, len - 1 - i, num);
    }
    return count;
}
