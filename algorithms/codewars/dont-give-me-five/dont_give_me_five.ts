export function dont_give_me_five(start: number, end: number): number {
    let count = 0;
    for (let i = start; i <= end; i++) {
        if (i.toString().indexOf('5') === -1) {
            count++;
        }
    }
    return count;
}
