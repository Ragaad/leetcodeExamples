from typing import List
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        graph=[[] for _ in range(numCourses)]
        degree=[0 for _ in range(numCourses)]
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            degree[course]+=1

        queue=[i for i in range(numCourses) if degree[i]==0]

        taken=0

        while queue:
            current=queue.pop(0)
            taken+=1
            for course in graph[current]:
                degree[course]-=1
                if degree[course]==0:
                    queue.append(course)
            
        return taken==numCourses

def solve(*args, **kwargs):
    sol=Solution()
    prerequisites=[[0,1]]
    numCourses=2
    if sol.canFinish(numCourses,prerequisites):
        print(f"These {numCourses} courses with this prerequisites {prerequisites} can be finished")
    else:
        print(f"These {numCourses} courses with this prerequisites {prerequisites} can not be finished")

if __name__ == "__main__":
    solve()
