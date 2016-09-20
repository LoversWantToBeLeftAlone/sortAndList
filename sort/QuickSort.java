package sort;

public class QuickSort {
	public void quickSort(int[] a, int left, int right) {
		if (left < right) {
			int low = left;
			int high = right;
			int key = a[left];
			while(low<high){
				while(low<high&&a[high]>key)
					high--;
				a[low]=a[high];
				while(low<high&&a[low]<key)
					low++;
				a[high]=a[low];
			}
			a[low]=key;
			quickSort(a,left,low);
			quickSort(a,low+1,right);
		}
	}
	
	public void binaryInsertSort(int[] a,int n){
		int key,left,right,middle;
		for(int i=1;i<n;i++){
			key=a[i];
			left=0;
			right=i-1;
			while(left<=right){
				middle=(left+right)/2;
				if(a[middle]>key)
					right=middle-1;
				left=middle+1;
			}
			for(int j=i-1;j>=left;j--)
				a[j+1]=a[j];
			a[left]=key;
		}
	}
	
	public void insertSort(int []a,int first,int last){
		int i,j,temp;
		for(i=first+1;i<last;i++){
			temp=a[i];
			j=i-1;
			while(j>first&& a[j]>temp){
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=temp;
		}
	}

}
