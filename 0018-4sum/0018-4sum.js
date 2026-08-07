var fourSum = function(nums, target) {
    nums.sort((a, b) => a - b);
    const ans = [];

    for (let i = 0; i < nums.length - 3; i++) {
        if (i && nums[i] === nums[i - 1]) continue;

        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;

            let l = j + 1, r = nums.length - 1;

            while (l < r) {
                const sum = nums[i] + nums[j] + nums[l] + nums[r];

                if (sum === target) {
                    ans.push([nums[i], nums[j], nums[l], nums[r]]);
                    while (l < r && nums[l] === nums[++l]);
                    while (l < r && nums[r] === nums[--r]);
                } else if (sum < target) l++;
                else r--;
            }
        }
    }
    return ans;
};