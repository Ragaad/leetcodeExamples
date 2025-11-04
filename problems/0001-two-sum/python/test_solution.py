from solution import Solution

def run_tests():
    sol = Solution()

    # Test Case 1
    nums = [2, 7, 11, 15]
    target = 9
    print("Test 1:", sol.twoSum(nums, target))  # Expected: [0, 1]

    # Test Case 2
    nums = [3, 2, 4]
    target = 6
    print("Test 2:", sol.twoSum(nums, target))  # Expected: [1, 2]

    # Test Case 3
    nums = [3, 3]
    target = 6
    print("Test 3:", sol.twoSum(nums, target))  # Expected: [0, 1]

    # Edge Case: Negative numbers
    nums = [-1, -2, -3, -4, -5]
    target = -8
    print("Test 4:", sol.twoSum(nums, target))  # Expected: [2, 4]

if __name__ == "__main__":
    run_tests()

