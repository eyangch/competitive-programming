class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        min_deg = minutes * 6
        hour_deg = hour % 12 * 30 + minutes / 2
        angle = abs(hour_deg - min_deg)
        return min(angle, 360 - angle) 