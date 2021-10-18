class MedianFinder {

public:

	vector<int> arr;

	void addNum(int num) {
		arr.insert(lower_bound(arr.begin(), arr.end(), num), num);
	}

	double findMedian() {
		if( arr.size() % 2 == 1) {
			return arr[arr.size()/2];
		} else {
			return ( (arr[arr.size()/2]) + (arr[arr.size()/2 - 1]) ) / 2.0;
		}
	}
};
