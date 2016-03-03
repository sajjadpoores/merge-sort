int a[100]; // array a must be defined globaly
void merge(int l,int mid, int h){
	
	int *temp = new int[h - l + 1];

	for (int i = 0, j = l; j <= h; i++, j++)
		temp[i] = a[j]; 

	int left = l-l;
	int right = mid + 1 - l;
	int k = l;
	while (k <= h && left <= mid-l && right <= h-l){
		if (temp[left] < temp[right])
			a[k++] = temp[left++];
		else
			a[k++] = temp[right++];
	}

	if (left > mid-l)
		while (right <= h-l)
			a[k++] = temp[right++];
	else
	while (left <= mid-l)
		a[k++] = temp[left++];
	
	
	delete[] temp;
}
void merge_sort(int low , int high){
	if (low < high){
		int mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid,high);
	}
}