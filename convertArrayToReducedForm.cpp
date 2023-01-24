class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    int temp[n];
	    for(int i=0;i<n;i++){
	        temp[i]=arr[i];
	    }
	    sort(temp,temp+n);
	    map<int,int> mp;
	    for(int i=0;i<n;i++){
	        mp.insert({temp[i],i});
	    }
	    for(int i=0;i<n;i++){
	        arr[i]=mp[arr[i]];
	    }
	    
	}

};
