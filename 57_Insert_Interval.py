class Solution(object):
    def insert(self, intervals: list, newInterval: list) -> list:
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if len(intervals) == 0:
            intervals.append(newInterval)
            return intervals
        
        index = 0
        for interval in intervals:
            if index + 1 >= len(intervals):
                if newInterval[0] > interval[1]:
                    intervals.append(newInterval)
                else:
                    intervals[index][0] = min(intervals[index][0], newInterval[0])
                    intervals[index][1] = max(intervals[index][1], newInterval[1])
                break
            if newInterval[0] > interval[0] and newInterval[0] < intervals[index+1][0]:
                intervals[index][1] = newInterval[1]
                if intervals[index][1] > intervals[index+1][0]:
                    intervals.pop(index+1)
                if intervals[index][1] >= intervals[index+1][0]:
                    intervals[index][1] = intervals[index+1][1]
                    intervals.pop(index+1)
                break
            index += 1
        return intervals
    
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
