// Java program for implementation of QuickSort
class QuickSort
{
	/* This function takes last element as pivot,
	places the pivot element at its correct
	position in sorted array, and places all
	smaller (smaller than pivot) to left of
	pivot and all greater elements to right
	of pivot */
	int partitionArray(int arr[], int lowIndex, int highIndex)
	{
		int pivot = arr[highIndex]; //10, 7, 8, 9, 1, 5 --pivot is 5
		int i = (lowIndex-1); // index of smaller element  --first index will be -1
		
		for (int j=lowIndex; j<highIndex; j++)//first lowIndex is 0
		{
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot)
			{
				
				//it will help for changing the Array elements 
				i++; //first it will be 0

				// swap arr[i] and arr[j]
				
				int temp = arr[i];
				arr[i] = arr[j];// keep the value actual position
				arr[j] = temp;
			}
		}

		// swap arr[i+1] and arr[high] (or put pivot)
		int temp = arr[i+1];
		arr[i+1] = arr[highIndex];
		arr[highIndex] = temp;

		return i+1;
	}


void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitionArray(arr, low, high);
 
        // If left part is smaller, then recur for left
        // part and handle right part iteratively
        if (pi - low < high - pi)
        {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        }
 
        // Else recur for right part
        else
        {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}
	/* A utility function to print array of size n */
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}

	// Driver program
	public static void main(String args[])
	{
		int arr[] = {10, 7, 8, 9, 1, 5};
		int n = arr.length;

		QuickSort ob = new QuickSort();
		ob.quickSort(arr, 0, n-1);

		System.out.println("sorted array");
		printArray(arr);
	}
}
/*This code is contributed by Rajat Mishra */