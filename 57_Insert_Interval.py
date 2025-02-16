class Solution(object):   
    def insert(self, intervals: list, newInterval: list) -> list:
        result = []
        i = 0
        n = len(intervals)
        
        while i < n and intervals[i][1] < newInterval[0]:
            result.append(intervals[i])
            i += 1
            
        # Merge overlapping intervals
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
            
        result.append(newInterval)
        
        # Add all remaining intervals after the new interval
        while i < n:
            result.append(intervals[i])
            i += 1
        
        return result
    
if __name__ == "__main__":
    soln = Solution()
    
    intervals = [[1,5]]
    newInterval = [6,8]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
    
    intervals = [[1,5]]
    newInterval = [2,7]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
    
    intervals = [[1,5]]
    newInterval = [2,3]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
    
    intervals = [[1,3],[6,9]]
    newInterval = [2,5]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
    
    intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
    newInterval = [4,8]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
    
    intervals = []
    newInterval = [5,7]
    output = soln.insert(intervals, newInterval)
    print(f"list : {output}")
