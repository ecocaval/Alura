const nums1 = ['1', '2', '3']
const nums2 = ['4', '5', '6']
const nums3 = ['7', '8', '9']
let numsUnidos = []

numsUnidos = (nums1.concat(nums2)).concat(nums3)

console.log(numsUnidos)

for(let i = 0; i < numsUnidos.length; i++) {
    console.log(numsUnidos[i])
}