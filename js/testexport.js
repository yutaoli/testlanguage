function countDown(leftSecond, intervalMs) {

    let countDown = leftSecond * 1000 + new Date().getTime()// ms

    let x = setInterval(function () {
        let left = countDown - new Date().getTime();
        if (left <= 0) {
            clearInterval(x);
            console.log('CountDown Finished');
            return;
        }

        let second = Math.floor(left / 1000);
        console.log(`left ${second} second.`)
    }, intervalMs)
}

export {countDown};