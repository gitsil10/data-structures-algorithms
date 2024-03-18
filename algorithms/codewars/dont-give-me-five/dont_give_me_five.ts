export function dont_give_me_five(start: number, end: number): number {
    let count = 0;
    for (let i = start; i <= end; i++) {
        if (!String(i).match('5')) {
            count++;
        }
    }
    return count;
}
