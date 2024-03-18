/*

*/

dont_give_me_five = (start, end) => {
    //count the number of integers that do not contain the digit 5
    let count = 0;
    for (let i = start; i <= end; i++) {
        if (!i.toString().includes('5')) {
            count++;
        }
    }
    return count;
}

dont_give_me_five_2 = (start, end) => {
    //count the number of integers that do not contain the digit 5
    let count = 0;
    for (let i = start; i <= end; i++) {
        if (!/5/.test(i)) {
            count++;
        }
    }
    return count;
}

dont_give_me_five_3 = (start, end) => {
    return Array.from(Array(end-start+1),(e,i)=>i+start)
          .filter((e)=>(''+e).indexOf('5')===-1)
          .length;
}