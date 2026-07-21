class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        result = int(dividend / divisor)

        MAX = 2147483647
        MIN = -2147483648

        if result > MAX:
            return MAX

        if result < MIN:
            return MIN

        return result