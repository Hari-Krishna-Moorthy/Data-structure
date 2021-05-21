
def MaxActivities(Activity):
	Activity = sorted(Activity, key=lambda x:(x[1])) 
	selected = [Activity[0]]

	for ind in range(1, len(Activity)):
		endTime = selected[-1][-1]
		if Activity[ind][0] >= endTime:
			selected.append(Activity[ind])

	return selected


Activity = [[5, 9], [1, 2], [3, 4], [0, 6],[5, 7], [8, 9]]

selected = MaxActivities(Activity)
print("Following activities are selected :")
print(selected)


"""
Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities.

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. 


1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do the following for the remaining activities in the sorted array. 
	a) If the start time of this activity is greater than or equal to the finish time
	of the previously selected activity then select this activity and print it.

Time Complexity: 
	It takes O(n log n) for non-sorted activities
	It takes O(n) for sorted activities 
"""